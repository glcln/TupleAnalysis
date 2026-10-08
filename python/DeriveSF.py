#!/usr/bin/env python3
"""
Trigger scale factors (DATA/MC) applied to the simulation by the selector.

The script produces the three tables read by HSCPSelector::Begin, in inc/:

  SF_PseudoMET.txt, SF_PUppiMET.txt
      one-dimensional scale factors, in bins of pseudo MET and of PUppi MET
  SF_<trigger>_PUppiMET_VS_PseudoMET__<OFILENAME>_table_plain.txt
      two-dimensional scale factors on a *non-grid* custom binning

and, in outputDisplay/TriggEff/, their LaTeX versions and the maps of the
two-dimensional scale factors.

One-dimensional tables: the fine bins above SF1D_LAST_EDGE are merged into one,
then SF = eff_data / eff_MC per bin, the errors being propagated as TH1::Divide
does (numerator and denominator treated as uncorrelated).

Two-dimensional table: the PUppiMET vs PseudoMET efficiency map cannot be stored
in a ROOT TH2, because each PseudoMET (y) slice uses its own PUppiMET (x)
binning. We read the fine-binned TH2s with uproot, aggregate raw counts into the
custom "super-bins", compute eff_data, eff_MC and SF = eff_data / eff_MC per
super-bin (binomial errors), then write the tables and a text-annotated 2D map
(matplotlib) per trigger.

The geometry is fully irregular: it starts from per-Y-slice X edges, then any
single cell can be replaced by an arbitrary set of sub-rectangles via
REPLACE_CELLS (so one cell can be split in Y/X without touching its neighbours).

All paths are relative to the repository, so the script can be started from
anywhere:   python3 python/DeriveSF.py
"""

import math
import os
import sys

import numpy as np
import uproot
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from matplotlib.patches import Rectangle

# ----------------------------------------------------------------------
# ROOT-like fonts (Helvetica/Arial sans-serif)
# ----------------------------------------------------------------------
plt.rcParams.update({
    "text.usetex": False,
    "font.family": "sans-serif",
    "font.sans-serif": ["Helvetica", "Arial", "Nimbus Sans", "DejaVu Sans"],
    "mathtext.fontset": "custom",
    "mathtext.rm": "sans",
    "mathtext.it": "sans:italic",
    "mathtext.bf": "sans:bold",
    "axes.formatter.use_mathtext": True,
    "axes.unicode_minus": False,
    "font.size": 12,
})

# ======================================================================
# CONFIG
# ======================================================================
REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

INPUT_DATA = os.path.join(REPO, "output/Mu2024_V18/Mu2024_V18p1.root")
INPUT_MC   = os.path.join(REPO, "output/Wjets2024_V14/WjetMuNu2024_V14p12.root")

LABEL_DATA = "TriggerEffCalib"
LABEL_MC   = "TriggerEffCalib"

OFILENAME  = "TriggerEffCalib"
TABLEDIR   = os.path.join(REPO, "inc")                       # tables read by the selector
OUTDIR     = os.path.join(REPO, "outputDisplay/TriggEff")    # LaTeX tables and plots

OBS = "PUppiMET_VS_PseudoMET"
TRIGGERS = ["orMETtrg"]

# ----------------------------------------------------------------------
# one-dimensional scale factors
# each entry: (observable in the histogram names, name of the table)
# ----------------------------------------------------------------------
SF1D_TRIGGER = "orMETtrg"
SF1D_TABLES = [
    ("PseudoCaloMET", "SF_PseudoMET"),
    ("PUppiMET",      "SF_PUppiMET"),
]
SF1D_LAST_EDGE = 400.0      # the bins above this value are merged into a single one

# ----------------------------------------------------------------------
# base custom binning  (rows: one X binning per Y slice)
# ----------------------------------------------------------------------
Y_EDGES = [0, 250, 300, 400, 500, 700, 1200]

X_EDGES_PER_SLICE = [
    [0, 150, 300, 1200],            # 0   - 250
    [0, 50, 100, 150, 300, 1200],   # 250 - 300
    [0, 150, 300, 400, 1200],       # 300 - 400
    [0, 150, 300, 450, 1200],       # 400 - 500
    [0, 150, 300, 1200],            # 500 - 700
    [0, 1200],                      # 700 - 1200
]

# ----------------------------------------------------------------------
# manual cell replacements (irregular subdivisions)
# each entry: (cell_to_replace, [list of sub-cells])
# a cell is (xlo, xhi, ylo, yhi)  with  x = PUppi MET, y = Pseudo MET
# ----------------------------------------------------------------------
REPLACE_CELLS = [
    # PUppi[150,300] x Pseudo[0,250]  -> split in Pseudo[0,150] and Pseudo[150,250],
    # and the Pseudo[150,250] part is further split in PUppi[150,225] / PUppi[225,300]
    ((150, 300, 0, 250), [
        (150, 300,   0, 150),   # bottom strip, full PUppi [150,300]
        (150, 200, 150, 250),   # top strip, PUppi [150,200]
        (200, 250, 150, 250),   # top strip, PUppi [200,250]
        (250, 300, 150, 250),   # top strip, PUppi [250,300]
    ]),
]

# axis display range
XRANGE = (0, 1200)
YRANGE = (0, 1200)
# ======================================================================


# ----------------------------------------------------------------------
# One-dimensional scale factors
# ----------------------------------------------------------------------
def load_th1(fname, label, suffix):
    """Contents, squared errors and bin edges of a TH1, without under/overflow."""
    key = f"{label}_{suffix}"
    with uproot.open(fname) as f:
        avail = [k.split(";")[0] for k in f.keys()]
        if key not in avail:
            raise KeyError(f"'{key}' not found in {fname}")
        h = f[key]
        return (np.asarray(h.values(), dtype=np.float64),
                np.asarray(h.variances(), dtype=np.float64),
                np.asarray(h.axis().edges(), dtype=np.float64))


def as_th1f(x):
    """Round to single precision, as the content of a TH1F is stored."""
    return np.asarray(x, dtype=np.float32).astype(np.float64)


def merge_tail(values, variances, edges, last_edge):
    """Merge all the bins above last_edge into one (TH1::Rebin with variable bins)."""
    n = int(np.searchsorted(edges, last_edge))
    if n >= len(edges) - 1 or not math.isclose(edges[n], last_edge):
        raise ValueError(f"{last_edge:g} is not an inner bin edge of the histogram")
    new_values = as_th1f(np.append(values[:n], values[n:].sum()))
    new_variances = np.append(variances[:n], variances[n:].sum())
    new_edges = np.append(edges[:n + 1], edges[-1])
    return new_values, new_variances, new_edges


def divide(num, var_num, den, var_den):
    """num / den with the error propagation of TH1::Divide; empty denominator -> 0."""
    ok = den != 0
    safe = np.where(ok, den, 1.0)
    ratio = as_th1f(np.where(ok, num / safe, 0.0))
    variance = np.where(ok, (var_num * safe**2 + var_den * num**2) / safe**4, 0.0)
    return ratio, variance


def process_sf1d(obs):
    """Scale factor and its error per bin of obs. Returns (low edges, up edges, sf, error)."""
    num_suffix = f"if___{SF1D_TRIGGER}___{obs}"
    hists = {}
    for tag, fname, label in (("d", INPUT_DATA, LABEL_DATA), ("m", INPUT_MC, LABEL_MC)):
        for kind, suffix in (("num", num_suffix), ("den", obs)):
            hists[kind + "_" + tag] = merge_tail(*load_th1(fname, label, suffix), SF1D_LAST_EDGE)

    edges = hists["num_d"][2]
    eff_d, var_d = divide(*hists["num_d"][:2], *hists["den_d"][:2])
    eff_m, var_m = divide(*hists["num_m"][:2], *hists["den_m"][:2])
    sf, var_sf = divide(eff_d, var_d, eff_m, var_m)
    return edges[:-1], edges[1:], sf, np.sqrt(var_sf)


def write_tables_1d(lows, ups, sf, err, plain_path, tex_path):
    # table read by the selector: low edge of the bin, SF - error, SF, SF + error
    with open(plain_path, "w") as t:
        for lo, s, e in zip(lows, sf, err):
            t.write("{:g} {:g} {:g} {:g}\n".format(lo, s - e, s, s + e))

    with open(tex_path, "w") as t:
        t.write("\\begin{table}[htbp]\n  \\centering\n")
        t.write("  \\caption{Trigger scale factors (data/MC) for \\texttt{"
                + SF1D_TRIGGER.replace("_", "\\_") + "} on the custom binning.}\n")
        t.write("  \\begin{tabular}{cc}\n    \\hline\n")
        t.write("    MET bin [GeV] & SF \\\\\n    \\hline\n")
        for lo, up, s, e in zip(lows, ups, sf, err):
            t.write("    $\\left[{:g}, {:g}\\right]$ & {:.4f} $\\pm$ {:.4f} \\\\\n".format(lo, up, s, e))
        t.write("    \\hline\n  \\end{tabular}\n\\end{table}\n")


# ----------------------------------------------------------------------
# Two-dimensional scale factors
# ----------------------------------------------------------------------
def build_cells():
    """Expand the per-slice binning into rectangles, then apply REPLACE_CELLS."""
    cells = []
    for iy in range(len(Y_EDGES) - 1):
        ylo, yhi = Y_EDGES[iy], Y_EDGES[iy + 1]
        xs = X_EDGES_PER_SLICE[iy]
        for ix in range(len(xs) - 1):
            cells.append((xs[ix], xs[ix + 1], ylo, yhi))

    for target, subs in REPLACE_CELLS:
        if target in cells:
            i = cells.index(target)
            cells[i:i + 1] = subs
        else:
            print(f"[warn] replace target {target} not found among base cells",
                  file=sys.stderr)

    # sort for a tidy table / drawing order: bottom-to-top, left-to-right
    cells.sort(key=lambda c: (c[2], c[0]))
    return cells


def load_th2(fname, label, suffix):
    key = f"{label}_{suffix}"
    with uproot.open(fname) as f:
        avail = [k.split(";")[0] for k in f.keys()]
        if key not in avail:
            raise KeyError(f"'{key}' not found in {fname}")
        h = f[key]
        values, xedges, yedges = h.to_numpy()      # values[x, y]
    return values.T, np.asarray(xedges), np.asarray(yedges)   # -> [y, x]


def integrate_region(counts, xedges, yedges, xlo, xhi, ylo, yhi):
    xc = 0.5 * (xedges[:-1] + xedges[1:])
    yc = 0.5 * (yedges[:-1] + yedges[1:])
    xmask = (xc >= xlo) & (xc < xhi)
    ymask = (yc >= ylo) & (yc < yhi)
    return counts[np.ix_(ymask, xmask)].sum()


def eff_and_err(k, n):
    if n > 0:
        eff = k / n
        var = eff * (1.0 - eff) / n
        return eff, math.sqrt(var) if var > 0 else 0.0
    return 0.0, 0.0


def sf_and_err(effd, errd, effm, errm):
    if effm > 0:
        sf = effd / effm
        rel = (errm / effm) ** 2
        if effd > 0:
            rel += (errd / effd) ** 2
        return sf, sf * math.sqrt(rel)
    return 0.0, 0.0


def cms_header(fig, private):
    artists = []
    if not private:
        artists.append(fig.text(0.125, 0.91, r"$\mathbf{CMS}$", fontsize=17))
        artists.append(fig.text(0.2, 0.91, r"$\mathit{Work\ in\ progress}$", fontsize=13))
    else:
        artists.append(fig.text(0.125, 0.91,
                                r"$\mathit{Private\ work\ (CMS\ simulation/data)}$", fontsize=13))
    return artists


def process_trigger(trigger, fine, cells_geom):
    num_d, xe, ye = fine["num_d"]
    den_d, _, _ = fine["den_d"]
    num_m, _, _ = fine["num_m"]
    den_m, _, _ = fine["den_m"]

    rows, cells = [], []
    for (xlo, xhi, ylo, yhi) in cells_geom:
        kd = integrate_region(num_d, xe, ye, xlo, xhi, ylo, yhi)
        nd = integrate_region(den_d, xe, ye, xlo, xhi, ylo, yhi)
        km = integrate_region(num_m, xe, ye, xlo, xhi, ylo, yhi)
        nm = integrate_region(den_m, xe, ye, xlo, xhi, ylo, yhi)

        effd, errd = eff_and_err(kd, nd)
        effm, errm = eff_and_err(km, nm)
        sf, sferr = sf_and_err(effd, errd, effm, errm)

        rows.append(dict(ylo=ylo, yhi=yhi, xlo=xlo, xhi=xhi,
                         effd=effd, errd=errd, effm=effm, errm=errm,
                         sf=sf, sferr=sferr, nd=nd, nm=nm))
        cells.append((xlo, xhi, ylo, yhi, sf, sferr))
    return rows, cells


def write_tables(trigger, rows, plain_path, tex_path):
    with open(tex_path, "w") as t:
        t.write("% Trigger scale factors (DATA/MC), custom non-grid binning\n")
        t.write(f"% trigger: {trigger}\n")
        t.write("\\begin{table}[htbp]\n  \\centering\n")
        t.write("  \\caption{Trigger scale factors (data/MC) for \\texttt{"
                + trigger.replace("_", "\\_") + "} on the custom binning.}\n")
        t.write("  \\begin{tabular}{ccc}\n    \\hline\n")
        t.write("    PseudoMET [GeV] & PUppiMET [GeV] & SF \\\\\n    \\hline\n")
        last_y = None
        for r in rows:
            yrange = f"$\\left[{r['ylo']:g}, {r['yhi']:g}\\right]$"
            xrange = f"$\\left[{r['xlo']:g}, {r['xhi']:g}\\right]$"
            ycell = yrange if yrange != last_y else ""
            last_y = yrange
            t.write("    {} & {} & {:.4f} $\\pm$ {:.4f} \\\\\n"
                    .format(ycell, xrange, r["sf"], r["sferr"]))
        t.write("    \\hline\n  \\end{tabular}\n\\end{table}\n")

    # table read by the selector: PseudoMET low/up, PUppiMET low/up, SF - error, SF, SF + error
    with open(plain_path, "w") as t:
        for r in rows:
            t.write("{:>8g} {:>8g} {:>8g} {:>8g} {:<8.4f} {:<8.4f} {:<8.4f}\n".format(
                r['ylo'], r['yhi'], r['xlo'], r['xhi'],
                r["sf"] - r["sferr"], r["sf"], r["sf"] + r["sferr"]))


def draw_map(trigger, cells, base):
    fig, ax = plt.subplots(figsize=(8, 6))
    fig.subplots_adjust(top=0.9, right=0.9)
    sf_vals = [c[4] for c in cells if c[4] > 0]
    vmin, vmax = (min(sf_vals), max(sf_vals)) if sf_vals else (0, 1)
    if vmin == vmax:
        vmin, vmax = vmin - 0.01, vmax + 0.01
    cmap = plt.cm.viridis
    norm = matplotlib.colors.Normalize(vmin=vmin, vmax=vmax)

    for (xlo, xhi, ylo, yhi, sf, sferr) in cells:
        color = cmap(norm(sf)) if sf > 0 else (0.9, 0.9, 0.9, 1.0)
        ax.add_patch(Rectangle((xlo, ylo), xhi - xlo, yhi - ylo,
                               facecolor=color, edgecolor="black", linewidth=0.8))
        cx, cy = 0.5 * (xlo + xhi), 0.5 * (ylo + yhi)
        lum = 0.299 * color[0] + 0.587 * color[1] + 0.114 * color[2] if sf > 0 else 1.0
        ax.text(cx, cy, f"{sf:.2f}", ha="center", va="center",
                fontsize=9, color="white" if lum < 0.5 else "black")

    ax.set_xlim(*XRANGE)
    ax.set_ylim(*YRANGE)
    ax.set_xlabel("PUppi MET [GeV]", fontsize=18)
    ax.set_ylabel("Pseudo MET [GeV]", fontsize=18)

    sm = plt.cm.ScalarMappable(cmap=cmap, norm=norm); sm.set_array([])
    fig.colorbar(sm, ax=ax, pad=0.02, fraction=0.046).set_label(
        "SF (DATA/MC)  " + trigger.replace("_", " "), fontsize=18)

    header = cms_header(fig, False)
    fig.savefig(base + "_map.pdf")
    for a in header:
        a.remove()
    cms_header(fig, True)
    fig.savefig(base + "_map_bis.pdf")
    plt.close(fig)


def draw_overlay(trigger, fine, cells_geom, base):
    num_d, xe, ye = fine["num_d"]
    den_d, _, _ = fine["den_d"]
    num_m, _, _ = fine["num_m"]
    den_m, _, _ = fine["den_m"]

    with np.errstate(divide="ignore", invalid="ignore"):
        eff_d = np.where(den_d > 0, num_d / den_d, np.nan)
        eff_m = np.where(den_m > 0, num_m / den_m, np.nan)
        sf_fine = np.where((eff_m > 0) & np.isfinite(eff_d), eff_d / eff_m, np.nan)

    fig, ax = plt.subplots(figsize=(8, 6))
    fig.subplots_adjust(top=0.9, right=0.9)

    finite = sf_fine[np.isfinite(sf_fine)]
    if finite.size:
        vmin, vmax = np.percentile(finite, 2), np.percentile(finite, 98)
        if vmin == vmax:
            vmin, vmax = vmin - 0.01, vmax + 0.01
    else:
        vmin, vmax = 0.0, 2.0

    X, Y = np.meshgrid(xe, ye)
    pcm = ax.pcolormesh(X, Y, sf_fine, cmap="viridis", vmin=vmin, vmax=vmax,
                        shading="flat")

    for (xlo, xhi, ylo, yhi) in cells_geom:
        ax.add_patch(Rectangle((xlo, ylo), xhi - xlo, yhi - ylo,
                               facecolor="none", edgecolor="red", linewidth=1.2))

    ax.set_xlim(*XRANGE)
    ax.set_ylim(*YRANGE)
    ax.set_xlabel("PUppi MET [GeV]", fontsize=18)
    ax.set_ylabel("Pseudo MET [GeV]", fontsize=18)

    fig.colorbar(pcm, ax=ax, pad=0.02, fraction=0.046).set_label(
        "SF (DATA/MC)  " + trigger.replace("_", " "), fontsize=18)

    header = cms_header(fig, False)
    fig.savefig(base + "_overlay.pdf", bbox_inches="tight")
    for a in header:
        a.remove()
    cms_header(fig, True)
    fig.savefig(base + "_overlay_bis.pdf", bbox_inches="tight")
    plt.close(fig)


def main():
    os.makedirs(OUTDIR, exist_ok=True)
    os.makedirs(TABLEDIR, exist_ok=True)

    # ---- one-dimensional tables ----
    for obs, name in SF1D_TABLES:
        try:
            lows, ups, sf, err = process_sf1d(obs)
        except (KeyError, ValueError, FileNotFoundError, OSError) as e:
            print(f"[skip] {name}: {e}", file=sys.stderr)
            continue
        plain = os.path.join(TABLEDIR, name + ".txt")
        tex = os.path.join(OUTDIR, name + "_tex.txt")
        write_tables_1d(lows, ups, sf, err, plain, tex)
        print(f"[done] {SF1D_TRIGGER} vs {obs} -> {plain}")

    # ---- two-dimensional table ----
    den_suffix = OBS
    cells_geom = build_cells()

    for trigger in TRIGGERS:
        num_suffix = f"if___{trigger}___{OBS}"
        try:
            fine = {
                "num_d": load_th2(INPUT_DATA, LABEL_DATA, num_suffix),
                "den_d": load_th2(INPUT_DATA, LABEL_DATA, den_suffix),
                "num_m": load_th2(INPUT_MC,   LABEL_MC,   num_suffix),
                "den_m": load_th2(INPUT_MC,   LABEL_MC,   den_suffix),
            }
        except (KeyError, FileNotFoundError, OSError) as e:
            print(f"[skip] {trigger}: {e}", file=sys.stderr)
            continue

        rows, cells = process_trigger(trigger, fine, cells_geom)
        name = f"SF_{trigger}_{OBS}__{OFILENAME}"
        base = os.path.join(OUTDIR, name)
        plain = os.path.join(TABLEDIR, name + "_table_plain.txt")
        write_tables(trigger, rows, plain, base + "_table.txt")
        draw_map(trigger, cells, base)
        draw_overlay(trigger, fine, cells_geom, base)
        print(f"[done] {trigger} -> {plain}")
        print(f"       plots and LaTeX table: {base}_*")


if __name__ == "__main__":
    main()
