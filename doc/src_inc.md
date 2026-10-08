i# `src/` and `inc/` — the `libTools` helper library

Reference for the seven source files in `src/` and `inc/`, after the October 2026 cleanup. What the cleanup removed is listed at the end.

`inc/` also holds the three trigger scale-factor tables read by the selector (`SF_*.txt`), written by `python/DeriveSF.py`; their format is given in the `MassTools` section.

## Overview

| File | Content | In `libTools.so` |
|---|---|---|
| `inc/CPlots.h`, `src/CPlots.cc` | `CPlots`: named 1D/2D histograms booked and filled by string key | yes |
| `inc/RegionMassPlot.h`, `src/RegionMassPlot.cc` | `RegionMassPlot`: fixed set of control histograms for one ABCD region | yes |
| `inc/MassTools.h`, `src/MassTools.cc` | Mass from (p, Ih) with the K & C formula; scale-factor table readers | yes |
| `inc/ComputeATLASmass.h` | Mass from (p, Ih) with the ATLAS dE/dx parametrisation | no (header-only) |

### How the pieces are used

```
compile.sh ──► libTools.so  (CPlots, RegionMassPlot, MassTools)

macros/macro.cc
  ├─ gSystem->Load("../libTools.so")
  └─ chain->Process("HSCPSelector.C+")          # compiled on the fly by ACLiC
         └─ HSCPSelector.h
              ├─ #include "../inc/RegionMassPlot.h"   ─► MassTools.h
              ├─ #include "../inc/CPlots.h"
              └─ #include "../inc/ComputeATLASmass.h"
```

`HSCPSelector.{h,C}` are generated from `HSCPTemplate.{h,C}` by `python/CreateSelector.py`. The selector is the only consumer of the library. It does not include `MassTools.h` directly: `GetMass`, `loadSF1D` and `loadSF2D` reach it through `RegionMassPlot.h`, which is why that include must stay.

### Build

```
./compile.sh        # needs root-config in the PATH; writes libTools.so at the repository root
```

Any change in `src/` or `inc/` requires re-running `compile.sh`. `ComputeATLASmass.h` is recompiled with the selector, so it does not.

### Units and conventions

- Momenta in GeV, `Ih` in MeV/cm, masses in GeV.
- In `RegionMassPlot`, the argument and axes called `p` hold **10⁴/p** in GeV⁻¹, not the momentum.
- Histograms are detached from any `TDirectory` (`SetDirectory(nullptr)`) and booked with `Sumw2()`.
- Neither class owns its histograms: they are never deleted, and copying an object copies the pointers only. The selector hands them to `fOutput` at the end of the job.

---

## `CPlots` — `inc/CPlots.h`, `src/CPlots.cc`

A container of histograms addressed by name. One `CPlots` object holds three maps (name → `TH1D*`, `TH1F*`, `TH2F*`). The selector keeps one object per selection (`vcp`) plus one for the plots made before any selection (`vcp_nosel`).

Typical sequence: book with `AddHisto*` in `SlaveBegin`, fill with `FillHisto*` in `Process`, export with `AddToList(fOutput)` in `SlaveTerminate`.

| Method | Behaviour |
|---|---|
| `AddHisto1F(name, nbins, xmin, xmax, title="")` | Books a `TH1F`. Does nothing if `name` is already booked. If `name` contains `_SignalMass`, sets the `kPoisson` bin-error option and prints a message. |
| `AddHisto1D(name, nbins, xmin, xmax, title="")` | Same for `TH1D`, without the `_SignalMass` case. |
| `AddHisto2F(name, nbinsx, xmin, xmax, nbinsy, ymin, ymax, title="")` | Books a `TH2F`. |
| `FillHisto1F(name, value, weight=1)`, `FillHisto1D(name, value, weight=1)`, `FillHisto2F(name, x, y, weight=1)` | Fills the histogram if it exists and returns `true`; returns `false` otherwise. |
| `AddToList(TList*)` | Adds every histogram to the list, skipping names already present in it. Returns `false` if the list is null. |

Things to know:

- **Axis titles.** The Y title of 1D histograms is `Normalized tracks / <bin width>`. No other axis title is set.
- **A misspelt name is silent.** `FillHisto*` returns `false` for an unknown name and the selector never checks the return value.
- **`kPoisson` and weights.** ROOT ignores the `kPoisson` option on a histogram whose sum of weights differs from its sum of squared weights. The `_SignalMass` histograms are filled with `weightPU × SF`, so they keep the usual `sqrt(sumw2)` errors; the option only acts on a histogram filled with unit weights.
- **Float interface.** All values go through `float` arguments, including the `double` branches of the tree.

---

## `RegionMassPlot` — `inc/RegionMassPlot.h`, `src/RegionMassPlot.cc`

A fixed set of 26 control histograms for one region of the background estimate. The selector builds 49 of them per selection, one for each of the regions A, B, C, D in each of their Fpix slices.

All data members are public. All histogram names end with the `suffix` given to the constructor, which the selector builds as `_region<A|B|C|D>_<lo>fp<hi>_<selection label>`, for example `ih_eta_regionD_8fp9_METanalysis_TestPUppiMETCut_Eta2p4`.

### Interface

| Method | Behaviour |
|---|---|
| `RegionMassPlot(suffix, etabins, ihbins, pbins, massbins, fpixbins, C_parameter)` | Stores the suffix and calls `initHisto`. |
| `initHisto(etabins, ihbins, pbins, massbins, fpixbins, C_parameter)` | Sets the binning and books every histogram. Calls `TH1::AddDirectory(false)`, which is a process-wide setting. |
| `fill(eta, nhits, p, pt, pterr, ih, ias, m, npv, fpix, w)` | Fills the 26 histograms with weight `w`. |
| `addToList(TList*)` | Adds the 26 histograms and 5 projections/profiles to the list. Objects whose name contains `CalibPseudoMET`, or already in the list, are skipped. |
| `~RegionMassPlot()` | Empty on purpose, see below. |

**Destructor.** It must not delete the histograms. The selector copies these objects by value (`push_back`, `for(auto obj : ...)`), and the copies share the histogram pointers, which also end up in `fOutput`. Deleting them here would destroy histograms that are still in use.

### Arguments of `fill`

| Argument | Meaning | What the selector passes |
|---|---|---|
| `eta` | track η | `IsoTrack_eta` |
| `nhits` | number of dE/dx measurements | `DeDx_NoL1NOM` |
| `p` | **10⁴/p** [GeV⁻¹] | `10000 / (pT·cosh η)` |
| `pt`, `pterr` | pT and its uncertainty [GeV] | `IsoTrack_PseudoTrack_pt`, `IsoTrack_ptError` |
| `ih` | Ih [MeV/cm] | `DeDx_IhStrip` |
| `ias` | discriminator filled in the `ias` histograms | `DeDx_GiStrip` |
| `m` | reconstructed mass [GeV] | `GetMass(p, Ih, K, C)` |
| `npv` | number of good primary vertices | `PV_npvsGood` |
| `fpix` | pixel discriminator | `DeDx_FiPixelNoL1` |
| `w` | event weight | |

### Binning

| Axis | Bins | Range |
|---|---|---|
| 10⁴/p | `pbins` | 0 – 200 GeV⁻¹ |
| pT (also used for p in `eta_p`) | `pbins` | 0 – 10000 GeV |
| Ih | `ihbins` | `C_parameter` – `C_parameter + 5` MeV/cm |
| Ias | `ihbins` | 0 – 1 |
| η | `etabins` | −2.4 – 2.4 |
| mass | `massbins` | 0 – 4000 GeV |
| Fpix | `fpixbins` | 0 – 1 |
| nhits | 20 | 0 – 20 |
| npv | 100 | 0 – 100 |
| σ(pT)/pT | `pbins` in `eta_pterrOpt`, 100 in `pt_pterroverpt` | 0 – 1 |

The bin counts come from `cfg/configFile.txt` (currently η 96, Ih 400, p 1000, mass 400, Fpix 20). With these values one `RegionMassPlot` takes about 36 MB.

### Histograms

The object name is `<name><suffix>`. Three members have a name that differs from the object name.

| Member | Object name | X | Y |
|---|---|---|---|
| `ih_pt` | `ih_pt` | pT | Ih |
| `ias_pt` | `ias_pt` | pT | Ias |
| `ih_ias` | **`ias_ih`** | Ias | Ih |
| `ih_fpix` | **`fpix_ih`** | Fpix | Ih |
| `eta_fpix` | **`fpix_eta`** | Fpix | η |
| `oP_fpix` | `oP_fpix` | 10⁴/p | Fpix |
| `ih_nhits` | `ih_nhits` | nhits | Ih |
| `ias_nhits` | `ias_nhits` | nhits | Ias |
| `eta_pt` | `eta_pt` | pT | η |
| `eta_1oP` | `eta_1oP` | 10⁴/p | η |
| `eta_p` | `eta_p` | p = pT·cosh η | η |
| `eta_pterrOpt` | `eta_pterrOpt` | η | σ(pT)/pT |
| `nhits_pt` | `nhits_pt` | pT | nhits |
| `eta_nhits` | `eta_nhits` | nhits | η |
| `ih_eta` | `ih_eta` | η | Ih |
| `ih_p` | `ih_p` | 10⁴/p | Ih |
| `ias_p` | `ias_p` | 10⁴/p | Ias |
| `pt_pterroverpt` | `pt_pterroverpt` | pT | σ(pT)/pT |
| `ias_eta` | `ias_eta` | η | Ias |
| `mass_eta` | `mass_eta` | η | mass |
| `eta_npv` | `eta_npv` | npv | η |
| `p_npv` | `p_npv` | npv | 10⁴/p |
| `ih_npv` | `ih_npv` | npv | Ih |
| `mass` | `mass` (TH1F, `kPoisson`) | mass | |
| `mass_p` | `mass_p` | 10⁴/p | mass |
| `mass_ih` | `mass_ih` | Ih | mass |

`addToList` also exports, computed at the time of the call: `ih_pt<suffix>_py` (Ih projection), and the X profiles `ih_p<suffix>_pfx`, `ias_p<suffix>_pfx`, `ih_pt<suffix>_pfx`, `ias_pt<suffix>_pfx`.

Axis titles that do not match the content: `mass_p` and `mass_ih` carry `Mass [GeV]` on X while the mass is on Y; `p_npv` is labelled `p [GeV]` but holds 10⁴/p; `oP_fpix` gives 10⁴/p in GeV instead of GeV⁻¹.

---

## `MassTools` — `inc/MassTools.h`, `src/MassTools.cc`

Free functions.

| Function | Behaviour |
|---|---|
| `float GetMass(p, ih, k, c)` | K & C mass: `m = p · sqrt((Ih − C) / K)`. Returns −1 if `Ih < C`. |
| `loadSF1D(filepath, SF_MET, SF_Down, SF, SF_Up)` | Reads a 4-column scale-factor table. |
| `loadSF2D(filepath, PseudoMETlo, PseudoMEThi, PUppiMETlo, PUppiMEThi, SF_Down, SF, SF_Up)` | Reads a 7-column scale-factor table. |

The two readers clear their output vectors, read whitespace-separated numbers until the first value that does not parse, print the file name, and throw `std::runtime_error` if the file cannot be opened.

File formats:

- 4 columns: `MET  SF_down  SF  SF_up`. `MET` is the lower edge of the bin; the selector takes the next row as the upper edge.
- 7 columns: `PseudoMET_lo  PseudoMET_hi  PUppiMET_lo  PUppiMET_hi  SF_down  SF  SF_up`.

Files read by the selector in `Begin`:

| File | Reader |
|---|---|
| `inc/SF_PseudoMET.txt` | `loadSF1D` |
| `inc/SF_PUppiMET.txt` | `loadSF1D` |
| `inc/SF_orMETtrg_PUppiMET_VS_PseudoMET__TriggerEffCalib_table_plain.txt` | `loadSF2D` |

The K and C values themselves are not in the library: they are globals of `HSCPTemplate.C`, set from the dataset name in `SlaveBegin`.

---

## `ComputeATLASmass.h` — `inc/ComputeATLASmass.h`

Mass reconstruction from (p, Ih) with an ATLAS-style parametrisation of dE/dx against βγ. It is used for the alternative `*_SignalMass_ATLAS*` histograms, filled for simulation only.

The file is header-only and not part of `libTools.so`. It has no include guard, defines non-inline functions and global arrays, defines the macros `TOLERANCE`, `MIN` and `MAX`, and contains `using namespace std;`. It can therefore be included in one translation unit only, which today is the selector.

### Model

```
dEdx(βγ) = p1 · X^(p2/2) · ln(1 + (p3·βγ)^p4) − p5      with  X = ( sqrt(βγ⁴ + 4βγ²) − βγ² ) / 2
```

`AtlasFunction` returns `dEdx(βγ) − Ih`. The mass is `p / βγ`, where βγ is the root of that function between `MIN` = 0.3 and the position of the minimum of the curve, i.e. on the slow-particle branch. If the minimum lies above `Ih` there is no solution.

### Parameter sets

| Key passed to `findMass` | Arrays | Fit |
|---|---|---|
| `"2024data"` | `ATLASfit_data2024`, `covMatrixATLASfit_data2024` | 2024 data |
| `"2024bkg"` | `ATLASfit_bckg2024`, `covMatrixATLASfit_bckg2024` | 2024 background simulation |
| `"2024glupion"` | `ATLASfit_glupion2024`, `covMatrixATLASfit_glupion2024` | `glupion` variant |

Each set has the five parameters p1…p5 and their 5×5 covariance matrix.

### Functions

| Function | Behaviour |
|---|---|
| `double findMass(p, Ih, year, up=false, down=false)` | Entry point. Returns the mass, or −1 if the key is unknown, or if the nominal curve or one of the `−` shifted curves has no solution. With `up` or `down`, returns the mass obtained with the corresponding varied parameters. The selector only uses the nominal form. |
| `findBetaGammaWithCovariance(Ih, FitParam, Cov)` | Diagonalises the covariance matrix. For each of the five eigen-directions, shifts the parameters by ±√λ along the eigenvector and recomputes the position of the minimum. Returns, in a `BetaGammaMinResult`, the nominal position with the nominal parameters, the largest position among the `+` shifts (`up`) and the smallest among the `−` shifts (`down`), each with the parameters that produced it. |
| `findMinimumX(par)` | Position of the minimum of `AtlasFunction` on [0.3, 10⁴], or −1 if the function is positive at that minimum. |
| `ZeroBrentMethod(a, b, t, params)` | Root of `AtlasFunction` in [a, b] with Brent's method and tolerance `t`. |
| `AtlasFunction(x, par)` | The function above, with `par[0] = Ih` and `par[1..5] = p1..p5`. |
| `InitializeCovMatrix(covMatrix)` | Copies a `double[5][5]` into a `TMatrixDSym`. |

Notes:

- `up` and `down` refer to the position of the minimum in βγ, not to the mass. The `up` mass can be below the nominal one, depending on `Ih`. In the scan quoted at the end of this document, the nominal mass lies between the two at every point.
- The error message for an unknown key says `Use '2024' or '2018'`; the valid keys are those of the table above.

---

## What the October 2026 cleanup changed

Removed, because nothing in the repository used it:

- `PlotTools.h` / `PlotTools.cc` entirely (`scale`, `invScale`, `ratioIntegral`, `chi2test`, `overflowLastBin`).
- `CPlots`: `SetLabels` and its four labels, `Write(TFile*)`, `GetHisto1D`, `AddHisto2D`, `FillHisto2D`, the `TObject` base class, and the axis titles derived from `_h` in the histogram name (no name matched, so every title was `idk`).
- `RegionMassPlot`: `write()`, `OneOverPreweighting()`, `plotMass()`, two declarations without implementation, the members `nbins`, `xbins`, `xp`, `c`, `eta_p_rebinned`, and ten histograms that were booked but never filled (`cross1Dtemplates`, `mapM800`, `Mass_errMass`, `massFrom1DTemplates`, `massFrom1DTemplatesEtaBinning`, `pred_mass`, `errMass`, `ih_used`, `momentumDistribM1000`, `dedxDistribM1000`). The duplicate `K` / `C` globals of `RegionMassPlot.cc`.
- `MassTools`: `deltaR(float, …)` (the selector uses the `double` version of `HSCPTemplate.h`) and `loadSF`, together with its four calls and the vectors it filled in `HSCPTemplate.{h,C}`.
- `ComputeATLASmass.h`: `ZeroBisectionMethod`, `MAX_ITER`, and the `nomsup` option of `findMass`.

Fixed:

- `findBetaGammaWithCovariance` kept its `up` and `down` parameters in pointers to the nominal array, so the three parameter sets it returned were always identical and the nominal mass was computed with shifted parameters. They are now independent copies. On a scan of p from 200 to 3000 GeV and Ih from 3 to 12 MeV/cm, the nominal mass moves by at most 1.6% for `2024data` (median 0.08%) and by less than 0.1% for the other two sets.

Visible in the output files:

- The empty `cross1Dtemplates_ih_p_<suffix>` histogram is no longer written.
- `CPlots` histograms have an empty X title (and Y title for 2D) instead of `idk`.
- The `*_SignalMass_ATLAS*` histograms change slightly because of the fix above.
- All other histograms are identical bin by bin.

