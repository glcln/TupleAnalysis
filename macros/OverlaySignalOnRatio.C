#include "TROOT.h"
#include "TSystem.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TH1.h"
#include "TLegend.h"
#include "TList.h"
#include "TString.h"
#include <iostream>

// ---------------------------------------------------------------------------
// Run a ROOT-generated .C macro (whose function name == the file stem) and
// return the LAST canvas created. This avoids hard-coding the internal canvas
// name, which differs between PseudoCaloMET / PUppiMET / ... files.
// ---------------------------------------------------------------------------
static TCanvas* RunAndGetLastCanvas(const char *macroPath) {
    int nBefore = gROOT->GetListOfCanvases()->GetSize();
    gROOT->ProcessLine(Form(".x %s", macroPath));
    TList *cList = (TList*)gROOT->GetListOfCanvases();
    if (cList->GetSize() <= nBefore) {
        std::cerr << "Error: no new canvas created by " << macroPath << std::endl;
        return nullptr;
    }
    return (TCanvas*)cList->Last();
}

// Find the first TH1 in a pad whose name contains 'needle'.
static TH1* FindHistInPad(TPad *pad, const char *needle) {
    if (!pad) return nullptr;
    TIter next(pad->GetListOfPrimitives());
    TObject *obj;
    while ((obj = next())) {
        if (obj->InheritsFrom(TH1::Class()) &&
            TString(obj->GetName()).Contains(needle))
            return (TH1*)obj;
    }
    return nullptr;
}

// Find the first TH1 in a canvas (single-pad signal file), scanning sub-pads too.
static TH1* FindHistInCanvas(TCanvas *c, const char *needle) {
    if (!c) return nullptr;
    TH1 *h = FindHistInPad((TPad*)c, needle);
    if (h) return h;
    TIter next(c->GetListOfPrimitives());
    TObject *obj;
    while ((obj = next())) {
        if (obj->InheritsFrom(TPad::Class())) {
            h = FindHistInPad((TPad*)obj, needle);
            if (h) return h;
        }
    }
    return nullptr;
}

// Find the top pad: the TPad named "pad1", else the first TPad found.
static TPad* FindTopPad(TCanvas *c) {
    if (!c) return nullptr;
    TPad *p = (TPad*)c->GetListOfPrimitives()->FindObject("pad1");
    if (p) return p;
    TIter next(c->GetListOfPrimitives());
    TObject *obj;
    while ((obj = next()))
        if (obj->InheritsFrom(TPad::Class())) return (TPad*)obj;
    return nullptr;
}

// Output stem from the ratio macro path (strip dir + ".C").
static TString OutStem(const char *ratioMacro) {
    TString s(ratioMacro);
    Ssiz_t slash = s.Last('/');
    if (slash != kNPOS) s.Remove(0, slash + 1);
    if (s.EndsWith(".C")) s.Remove(s.Length() - 2);
    return s;
}

// ---------------------------------------------------------------------------
// Main
// ---------------------------------------------------------------------------
void OverlaySignalOnRatio(const char *signalMacro,
                          const char *ratioMacro,
                          const char *signalLabel = "Signal",
                          const char *outDir      = "TriggEff") {

    gErrorIgnoreLevel = kWarning;

    // 1) SIGNAL macro -> histogram whose name contains "SIGNAL"
    TCanvas *cSig = RunAndGetLastCanvas(signalMacro);
    if (!cSig) return;
    TH1 *hSig = FindHistInCanvas(cSig, "SIGNAL");
    if (!hSig) {
        std::cerr << "Error: no 'SIGNAL' histogram in " << signalMacro << std::endl;
        return;
    }
    TH1 *hSigClone = (TH1*)hSig->Clone("hSig_overlay");
    hSigClone->SetDirectory(0);

    // 2) RATIO macro -> canvas + top pad
    TCanvas *cRatio = RunAndGetLastCanvas(ratioMacro);
    if (!cRatio) return;
    TPad *pad1 = FindTopPad(cRatio);
    if (!pad1) {
        std::cerr << "Error: top pad not found in ratio canvas." << std::endl;
        return;
    }

    // sanity: warn if axes differ (PUppi vs PseudoCalo)
    TH1 *hData = FindHistInPad(pad1, "DATA");
    if (hData) {
        TString sx = hSigClone->GetXaxis()->GetTitle();
        TString dx = hData->GetXaxis()->GetTitle();
        if (sx != dx)
            std::cerr << "Note: signal x-axis '" << sx << "' != data x-axis '"
                      << dx << "'. Overlaying anyway." << std::endl;
    }

    // 3) style + draw signal on top pad
    hSigClone->SetLineColor(kGreen + 2);
    hSigClone->SetMarkerColor(kGreen + 2);
    hSigClone->SetMarkerStyle(21);
    hSigClone->SetMarkerSize(0.6);
    pad1->cd();
    hSigClone->Draw("E1 same");

    // 4) legend
    TLegend *leg = nullptr;
    {
        TIter next(pad1->GetListOfPrimitives());
        TObject *obj;
        while ((obj = next()))
            if (obj->InheritsFrom(TLegend::Class())) { leg = (TLegend*)obj; break; }
    }
    if (!leg) {
        leg = new TLegend(0.4, 0.2, 0.6, 0.4, NULL, "brNDC");
        leg->SetBorderSize(0);
        leg->SetFillStyle(0);
        leg->Draw();
    }
    leg->AddEntry(hSigClone, signalLabel, "lep");

    pad1->Modified();
    cRatio->cd();
    cRatio->Modified();
    cRatio->Update();

    // 5) save
    gSystem->mkdir(outDir, kTRUE);
    TString stem = OutStem(ratioMacro);
    cRatio->SaveAs(Form("%s/%s__withSignal.pdf", outDir, stem.Data()));
    cRatio->SaveAs(Form("%s/%s__withSignal.C",   outDir, stem.Data()));

    std::cout << "Done: " << signalLabel << " overlaid on " << stem << std::endl;
}