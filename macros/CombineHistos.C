#include "TH1.h"
#include "TF1.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TMath.h"
#include "TGraphErrors.h"
#include "TLatex.h"
#include "TFile.h"
#include "TH2.h"
#include "TGraph.h"
#include <iostream>

TCanvas* DrawWithRatio(TH1* h1, TH1* h2, TCanvas* c1, std::string CanvasTitle, std::string RatioTitle, std::string OptionDraw, bool logy) {
    if (!h1 || !h2) {
        std::cerr << "DrawWithRatio: h1 or h2 is null! Returning nullptr.\n";
        return nullptr;
    }

    TCanvas* c_new = new TCanvas(CanvasTitle.c_str(), CanvasTitle.c_str(), 800, 800);

    // Define pads
    TPad* pad1 = new TPad("pad1", "pad1", 0.0, 0.3, 1.0, 1.0);
    pad1->SetBottomMargin(0.03);
    pad1->Draw();
    if (logy) pad1->SetLogy();

    TPad* pad2 = new TPad("pad2", "pad2", 0.0, 0.0, 1.0, 0.3);
    pad2->SetTopMargin(0.02);
    pad2->SetBottomMargin(0.3);
    pad2->Draw();

    // Draw upper plot: draw h1 then h2 (use OptionDraw for h1, and "E1 same" for h2)
    pad1->cd();
    // Make clones so que l'originale reste inchangée
    TH1* h1c = (TH1*)h1->Clone(TString(h1->GetName()) + "_" + CanvasTitle.c_str());
    TH1* h2c = (TH1*)h2->Clone(TString(h2->GetName()) + "_" + CanvasTitle.c_str());
    if (!h1c || !h2c) {
        std::cerr << "DrawWithRatio: clone failed.\n";
        delete c_new;
        return nullptr;
    }
    h1c->SetTitle(CanvasTitle.c_str());
    h1c->Draw(OptionDraw.c_str());
    h2c->Draw("E1 same");

    // save the legend and draw it on the new canvas
    TLegend* leg = nullptr;
    if (c1) {
        TList* primitives = c1->GetListOfPrimitives();
        TIter next(primitives);
        TObject* obj;
        while ((obj = next())) {
            if (obj->InheritsFrom("TLegend")) {
                leg = (TLegend*)obj->Clone(TString("leg_") + CanvasTitle.c_str());
                break;
            }
        }
    }
    if (leg) {
        pad1->cd();
        leg->Draw();
    }

    // Remove x labels on upper pad
    if (h1c->InheritsFrom("TH1")) ((TH1*)h1c)->GetXaxis()->SetLabelSize(0);
    if (h2c->InheritsFrom("TH1")) ((TH1*)h2c)->GetXaxis()->SetLabelSize(0);

    // Draw ratio
    pad2->cd();
    TH1* h_ratio = (TH1*)h2c->Clone(TString("h_ratio_") + CanvasTitle.c_str());
    if (!h_ratio) {
        std::cerr << "DrawWithRatio: ratio clone failed.\n";
        return c_new;
    }
    h_ratio_DATA->Sumw2();
    h1c_DATA->Sumw2();
    h_ratio->Divide(h1c);

    h_ratio->SetTitle("");
    h_ratio->GetYaxis()->SetTitle(RatioTitle.c_str());
    h_ratio->GetYaxis()->SetRangeUser(0, 2);
    h_ratio->SetMarkerStyle(8);
    h_ratio->GetYaxis()->SetNdivisions(505);
    h_ratio->GetYaxis()->SetTitleSize(0.08);
    h_ratio->GetYaxis()->SetTitleOffset(0.5);
    h_ratio->GetXaxis()->SetTitleSize(0.08);
    h_ratio->GetXaxis()->SetTitleOffset(1);
    h_ratio->GetYaxis()->SetLabelSize(0.06);
    h_ratio->GetXaxis()->SetLabelSize(0.06);
    h_ratio->GetXaxis()->SetTitle(h1c->GetXaxis()->GetTitle());
    h_ratio->SetLineColor(kBlack);
    h_ratio->SetMarkerColor(kBlack);
    gPad->SetTickx(0);
    h_ratio->LabelsOption("v", "X");
    h_ratio->Draw("E0");

    TLine* line = new TLine(h_ratio->GetXaxis()->GetXmin(), 1,
                            h_ratio->GetXaxis()->GetXmax(), 1);
    line->SetLineColor(kBlack);
    line->SetLineStyle(2);
    line->Draw("same");

    c_new->Update();
    return c_new;
}


void MET_trg_eff(const char *ifileName, bool isAOD = false) {

    TFile *ofile;
    if (isAOD) ofile = new TFile("PlayWithHistos/MET_trg_eff_AOD_v2.root", "RECREATE");
    else ofile = new TFile("PlayWithHistos/MET_trg_eff_miniAOD_v2.root", "RECREATE");

    TFile *ifile = new TFile(Form("%s", ifileName), "READ");

    // input histos
    TH1F *PseudoCaloMET = (TH1F*)ifile->Get("OnlyMET_PseudoCaloMET");
    TH1F *RecoPFMET = (TH1F*)ifile->Get("OnlyMET_RecoPFMET");
    TH1F *RecoPFMET__PseudoCaloMETCut = (TH1F*)ifile->Get("OnlyMET_RecoPFMET__PseudoCaloMETCut");

    TH1F *if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET = (TH1F*)ifile->Get("OnlyMET_if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET");
    TH1F *if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET = (TH1F*)ifile->Get("OnlyMET_if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET");            
    
    TH1F *if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET = (TH1F*)ifile->Get("OnlyMET_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET");
    TH1F *if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET = (TH1F*)ifile->Get("OnlyMET_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET");
    
    TH1F *if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET = (TH1F*)ifile->Get("OnlyMET_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET");
    TH1F *if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET = (TH1F*)ifile->Get("OnlyMET_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET");
    
    TH1F *if___HLT_MET105_IsoTrk50___PseudoCaloMET = (TH1F*)ifile->Get("OnlyMET_if___HLT_MET105_IsoTrk50___PseudoCaloMET");
    TH1F *if___HLT_MET105_IsoTrk50___RecoPFMET = (TH1F*)ifile->Get("OnlyMET_if___HLT_MET105_IsoTrk50___RecoPFMET");

    TH1F *if___orMETtrg___PseudoCaloMET = (TH1F*)ifile->Get("OnlyMET_if___orMETtrg___PseudoCaloMET");
    TH1F *if___orMETtrg___RecoPFMET = (TH1F*)ifile->Get("OnlyMET_if___orMETtrg___RecoPFMET");
    TH1F *if___orMETtrg___RecoPFMET__PseudoCaloMETCut;
    if (!isAOD) if___orMETtrg___RecoPFMET__PseudoCaloMETCut = (TH1F*)ifile->Get("OnlyMET_if___orMETtrg___RecoPFMET__PseudoCaloMETCut");

    TH1F *RecoCaloMET;
    TH1F *if___HLT_PFMET120_PFMHT120_IDTight___RecoCaloMET;
    TH1F *if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoCaloMET;
    TH1F *if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoCaloMET;
    TH1F *if___HLT_MET105_IsoTrk50___RecoCaloMET;
    TH1F *if___orMETtrg___RecoCaloMET;

    if (isAOD) {
        RecoCaloMET = (TH1F*)ifile->Get("OnlyMET_RecoCaloMET");

        if___HLT_PFMET120_PFMHT120_IDTight___RecoCaloMET = (TH1F*)ifile->Get("OnlyMET_if___HLT_PFMET120_PFMHT120_IDTight___RecoCaloMET");
        if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoCaloMET = (TH1F*)ifile->Get("OnlyMET_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoCaloMET");
        if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoCaloMET = (TH1F*)ifile->Get("OnlyMET_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoCaloMET");
        if___HLT_MET105_IsoTrk50___RecoCaloMET = (TH1F*)ifile->Get("OnlyMET_if___HLT_MET105_IsoTrk50___RecoCaloMET");
        if___orMETtrg___RecoCaloMET = (TH1F*)ifile->Get("OnlyMET_if___orMETtrg___RecoCaloMET");
    }

    // setup 
    if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET->Sumw2();
    TH1F *eff_HLT_PFMET120_PseudoCaloMET = (TH1F*)if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET->Clone("eff_HLT_PFMET120_PseudoCaloMET");
    if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET->Sumw2();
    TH1F *eff_HLT_PFMET120_RecoPFMET = (TH1F*)if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET->Clone("eff_HLT_PFMET120_RecoPFMET");
    if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET->Sumw2();
    TH1F *eff_HLT_PFHT500_PseudoCaloMET = (TH1F*)if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET->Clone("eff_HLT_PFHT500_PseudoCaloMET");
    if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET->Sumw2();
    TH1F *eff_HLT_PFHT500_RecoPFMET = (TH1F*)if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET->Clone("eff_HLT_PFHT500_RecoPFMET");
    if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET->Sumw2();
    TH1F *eff_HLT_PFMETNoMu120_PseudoCaloMET = (TH1F*)if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET->Clone("eff_HLT_PFMETNoMu120_PseudoCaloMET");
    if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET->Sumw2();
    TH1F *eff_HLT_PFMETNoMu120_RecoPFMET = (TH1F*)if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET->Clone("eff_HLT_PFMETNoMu120_RecoPFMET");
    if___HLT_MET105_IsoTrk50___PseudoCaloMET->Sumw2();
    TH1F *eff_HLT_MET105_PseudoCaloMET = (TH1F*)if___HLT_MET105_IsoTrk50___PseudoCaloMET->Clone("eff_HLT_MET105_PseudoCaloMET");
    if___HLT_MET105_IsoTrk50___RecoPFMET->Sumw2();
    TH1F *eff_HLT_MET105_RecoPFMET = (TH1F*)if___HLT_MET105_IsoTrk50___RecoPFMET->Clone("eff_HLT_MET105_RecoPFMET");
    if___orMETtrg___PseudoCaloMET->Sumw2();
    TH1F *eff_orMETtrg_PseudoCaloMET = (TH1F*)if___orMETtrg___PseudoCaloMET->Clone("eff_orMETtrg_PseudoCaloMET");
    if___orMETtrg___RecoPFMET->Sumw2();
    TH1F *eff_orMETtrg_RecoPFMET = (TH1F*)if___orMETtrg___RecoPFMET->Clone("eff_orMETtrg_RecoPFMET");
    TH1F *eff_orMETtrg_RecoPFMET__PseudoCaloMETCut;
    if (!isAOD) {
        if___orMETtrg___RecoPFMET__PseudoCaloMETCut->Sumw2();    
        eff_orMETtrg_RecoPFMET__PseudoCaloMETCut = (TH1F*)if___orMETtrg___RecoPFMET__PseudoCaloMETCut->Clone("eff_orMETtrg_RecoPFMET__PseudoCaloMETCut");
    }

    TH1F *eff_HLT_PFMET120_RecoCaloMET;
    TH1F *eff_HLT_PFHT500_RecoCaloMET;
    TH1F *eff_HLT_PFMETNoMu120_RecoCaloMET;
    TH1F *eff_HLT_MET105_RecoCaloMET;
    TH1F *eff_orMETtrg_RecoCaloMET;
    if (isAOD) {
        if___HLT_PFMET120_PFMHT120_IDTight___RecoCaloMET->Sumw2();
        eff_HLT_PFMET120_RecoCaloMET = (TH1F*)if___HLT_PFMET120_PFMHT120_IDTight___RecoCaloMET->Clone("eff_HLT_PFMET120_RecoCaloMET");
        if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoCaloMET->Sumw2();
        eff_HLT_PFHT500_RecoCaloMET = (TH1F*)if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoCaloMET->Clone("eff_HLT_PFHT500_RecoCaloMET");
        if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoCaloMET->Sumw2();
        eff_HLT_PFMETNoMu120_RecoCaloMET = (TH1F*)if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoCaloMET->Clone("eff_HLT_PFMETNoMu120_RecoCaloMET");
        if___HLT_MET105_IsoTrk50___RecoCaloMET->Sumw2();
        eff_HLT_MET105_RecoCaloMET = (TH1F*)if___HLT_MET105_IsoTrk50___RecoCaloMET->Clone("eff_HLT_MET105_RecoCaloMET");
        if___orMETtrg___RecoCaloMET->Sumw2();
        eff_orMETtrg_RecoCaloMET = (TH1F*)if___orMETtrg___RecoCaloMET->Clone("eff_orMETtrg_RecoCaloMET");
    }

    // efficiency calculation
    eff_HLT_PFMET120_PseudoCaloMET->Divide(PseudoCaloMET);
    eff_HLT_PFMET120_RecoPFMET->Divide(RecoPFMET);
    eff_HLT_PFHT500_PseudoCaloMET->Divide(PseudoCaloMET);
    eff_HLT_PFHT500_RecoPFMET->Divide(RecoPFMET);
    eff_HLT_PFMETNoMu120_PseudoCaloMET->Divide(PseudoCaloMET);
    eff_HLT_PFMETNoMu120_RecoPFMET->Divide(RecoPFMET);
    eff_HLT_MET105_PseudoCaloMET->Divide(PseudoCaloMET);
    eff_HLT_MET105_RecoPFMET->Divide(RecoPFMET);
    eff_orMETtrg_PseudoCaloMET->Divide(PseudoCaloMET);
    eff_orMETtrg_RecoPFMET->Divide(RecoPFMET);
    if (!isAOD) eff_orMETtrg_RecoPFMET__PseudoCaloMETCut->Divide(RecoPFMET__PseudoCaloMETCut);

    if (isAOD) {
        eff_HLT_PFMET120_RecoCaloMET->Divide(RecoCaloMET);
        eff_HLT_PFHT500_RecoCaloMET->Divide(RecoCaloMET);
        eff_HLT_PFMETNoMu120_RecoCaloMET->Divide(RecoCaloMET);
        eff_HLT_MET105_RecoCaloMET->Divide(RecoCaloMET);
        eff_orMETtrg_RecoCaloMET->Divide(RecoCaloMET);
    }

    // setting style
    PseudoCaloMET->Scale(0.7 * 8.0 / PseudoCaloMET->Integral());
    RecoPFMET->Scale(1.8 * 9.0 / RecoPFMET->Integral());
    PseudoCaloMET->SetLineColor(kGreen+3);
    RecoPFMET->SetLineColor(kGreen+3);
    PseudoCaloMET->SetMarkerColor(kGreen+3);
    RecoPFMET->SetMarkerColor(kGreen+3);
    PseudoCaloMET->SetMarkerStyle(22);
    RecoPFMET->SetMarkerStyle(22);

    eff_HLT_PFMET120_PseudoCaloMET->SetLineColor(kRed);
    eff_HLT_PFMET120_PseudoCaloMET->SetMarkerColor(kRed);
    eff_HLT_PFMET120_PseudoCaloMET->SetMarkerStyle(21);
    eff_HLT_PFMET120_PseudoCaloMET->GetXaxis()->SetTitle("PseudoCaloMET [GeV]");
    eff_HLT_PFMET120_PseudoCaloMET->GetYaxis()->SetTitle("eff. HLT_PFMET120_PFMHT120_IDTight");
    eff_HLT_PFMET120_PseudoCaloMET->GetXaxis()->SetRangeUser(0, 1500);
    eff_HLT_PFMET120_PseudoCaloMET->GetYaxis()->SetRangeUser(0, 1);

    eff_HLT_PFMET120_RecoPFMET->SetLineColor(kRed);
    eff_HLT_PFMET120_RecoPFMET->SetMarkerColor(kRed);
    eff_HLT_PFMET120_RecoPFMET->SetMarkerStyle(21);
    eff_HLT_PFMET120_RecoPFMET->GetXaxis()->SetTitle("RecoPFMET [GeV]");
    eff_HLT_PFMET120_RecoPFMET->GetYaxis()->SetTitle("eff. HLT_PFMET120_PFMHT120_IDTight");
    eff_HLT_PFMET120_RecoPFMET->GetXaxis()->SetRangeUser(0, 1500);
    eff_HLT_PFMET120_RecoPFMET->GetYaxis()->SetRangeUser(0, 1);

    eff_HLT_PFHT500_PseudoCaloMET->SetLineColor(kRed);
    eff_HLT_PFHT500_PseudoCaloMET->SetMarkerColor(kRed);
    eff_HLT_PFHT500_PseudoCaloMET->SetMarkerStyle(21);
    eff_HLT_PFHT500_PseudoCaloMET->GetXaxis()->SetTitle("PseudoCaloMET [GeV]");
    eff_HLT_PFHT500_PseudoCaloMET->GetYaxis()->SetTitle("eff. HLT_PFHT500_PFMET100_PFMHT100_IDTight");
    eff_HLT_PFHT500_PseudoCaloMET->GetXaxis()->SetRangeUser(0, 1500);
    eff_HLT_PFHT500_PseudoCaloMET->GetYaxis()->SetRangeUser(0, 1);

    eff_HLT_PFHT500_RecoPFMET->SetLineColor(kRed);
    eff_HLT_PFHT500_RecoPFMET->SetMarkerColor(kRed);
    eff_HLT_PFHT500_RecoPFMET->SetMarkerStyle(21);
    eff_HLT_PFHT500_RecoPFMET->GetXaxis()->SetTitle("RecoPFMET [GeV]");
    eff_HLT_PFHT500_RecoPFMET->GetYaxis()->SetTitle("eff. HLT_PFHT500_PFMET100_PFMHT100_IDTight");
    eff_HLT_PFHT500_RecoPFMET->GetXaxis()->SetRangeUser(0, 1500);
    eff_HLT_PFHT500_RecoPFMET->GetYaxis()->SetRangeUser(0, 1);

    eff_HLT_PFMETNoMu120_PseudoCaloMET->SetLineColor(kRed);
    eff_HLT_PFMETNoMu120_PseudoCaloMET->SetMarkerColor(kRed);
    eff_HLT_PFMETNoMu120_PseudoCaloMET->SetMarkerStyle(21);
    eff_HLT_PFMETNoMu120_PseudoCaloMET->GetXaxis()->SetTitle("PseudoCaloMET [GeV]");
    eff_HLT_PFMETNoMu120_PseudoCaloMET->GetYaxis()->SetTitle("eff. HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60");
    eff_HLT_PFMETNoMu120_PseudoCaloMET->GetXaxis()->SetRangeUser(0, 1500);
    eff_HLT_PFMETNoMu120_PseudoCaloMET->GetYaxis()->SetRangeUser(0, 1);

    eff_HLT_PFMETNoMu120_RecoPFMET->SetLineColor(kRed);
    eff_HLT_PFMETNoMu120_RecoPFMET->SetMarkerColor(kRed);
    eff_HLT_PFMETNoMu120_RecoPFMET->SetMarkerStyle(21);
    eff_HLT_PFMETNoMu120_RecoPFMET->GetXaxis()->SetTitle("RecoPFMET [GeV]");
    eff_HLT_PFMETNoMu120_RecoPFMET->GetYaxis()->SetTitle("eff. HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60");
    eff_HLT_PFMETNoMu120_RecoPFMET->GetXaxis()->SetRangeUser(0, 1500);
    eff_HLT_PFMETNoMu120_RecoPFMET->GetYaxis()->SetRangeUser(0, 1);

    eff_HLT_MET105_PseudoCaloMET->SetLineColor(kRed);
    eff_HLT_MET105_PseudoCaloMET->SetMarkerColor(kRed);
    eff_HLT_MET105_PseudoCaloMET->SetMarkerStyle(21);
    eff_HLT_MET105_PseudoCaloMET->GetXaxis()->SetTitle("PseudoCaloMET [GeV]");
    eff_HLT_MET105_PseudoCaloMET->GetYaxis()->SetTitle("eff. HLT_MET105_IsoTrk50");
    eff_HLT_MET105_PseudoCaloMET->GetXaxis()->SetRangeUser(0, 1500);
    eff_HLT_MET105_PseudoCaloMET->GetYaxis()->SetRangeUser(0, 1);

    eff_HLT_MET105_RecoPFMET->SetLineColor(kRed);
    eff_HLT_MET105_RecoPFMET->SetMarkerColor(kRed);
    eff_HLT_MET105_RecoPFMET->SetMarkerStyle(21);
    eff_HLT_MET105_RecoPFMET->GetXaxis()->SetTitle("RecoPFMET [GeV]");
    eff_HLT_MET105_RecoPFMET->GetYaxis()->SetTitle("eff. HLT_MET105_IsoTrk50");
    eff_HLT_MET105_RecoPFMET->GetXaxis()->SetRangeUser(0, 1500);
    eff_HLT_MET105_RecoPFMET->GetYaxis()->SetRangeUser(0, 1);

    eff_orMETtrg_PseudoCaloMET->SetLineColor(kRed);
    eff_orMETtrg_PseudoCaloMET->SetMarkerColor(kRed);
    eff_orMETtrg_PseudoCaloMET->SetMarkerStyle(21);
    eff_orMETtrg_PseudoCaloMET->GetXaxis()->SetTitle("PseudoCaloMET [GeV]");
    eff_orMETtrg_PseudoCaloMET->GetYaxis()->SetTitle("eff. orMETtrg");
    eff_orMETtrg_PseudoCaloMET->GetXaxis()->SetRangeUser(0, 1500);
    eff_orMETtrg_PseudoCaloMET->GetYaxis()->SetRangeUser(0, 1);

    eff_orMETtrg_RecoPFMET->SetLineColor(kRed);
    eff_orMETtrg_RecoPFMET->SetMarkerColor(kRed);
    eff_orMETtrg_RecoPFMET->SetMarkerStyle(21);
    eff_orMETtrg_RecoPFMET->GetXaxis()->SetTitle("RecoPFMET [GeV]");
    eff_orMETtrg_RecoPFMET->GetYaxis()->SetTitle("eff. orMETtrg");
    eff_orMETtrg_RecoPFMET->GetXaxis()->SetRangeUser(0, 1500);
    eff_orMETtrg_RecoPFMET->GetYaxis()->SetRangeUser(0, 1);

    if (!isAOD) {
        eff_orMETtrg_RecoPFMET__PseudoCaloMETCut->SetLineColor(kRed);
        eff_orMETtrg_RecoPFMET__PseudoCaloMETCut->SetMarkerColor(kRed);
        eff_orMETtrg_RecoPFMET__PseudoCaloMETCut->SetMarkerStyle(21);
        eff_orMETtrg_RecoPFMET__PseudoCaloMETCut->GetXaxis()->SetTitle("RecoPFMET [GeV]");
        eff_orMETtrg_RecoPFMET__PseudoCaloMETCut->GetYaxis()->SetTitle("eff. orMETtrg w/PseudoMET>170GeV");
        eff_orMETtrg_RecoPFMET__PseudoCaloMETCut->GetXaxis()->SetRangeUser(0, 1500);
        eff_orMETtrg_RecoPFMET__PseudoCaloMETCut->GetYaxis()->SetRangeUser(0, 1);
    }

    if (isAOD) {
        eff_HLT_PFMET120_RecoCaloMET->SetLineColor(kBlue);
        eff_HLT_PFMET120_RecoCaloMET->SetMarkerColor(kBlue);
        eff_HLT_PFMET120_RecoCaloMET->SetMarkerStyle(20);
        eff_HLT_PFMET120_RecoCaloMET->GetXaxis()->SetTitle("RecoCaloMET [GeV]");
        eff_HLT_PFMET120_RecoCaloMET->GetYaxis()->SetTitle("eff. HLT_PFMET120_PFMHT120_IDTight");
        eff_HLT_PFMET120_RecoCaloMET->GetXaxis()->SetRangeUser(0, 1500);
        eff_HLT_PFMET120_RecoCaloMET->GetYaxis()->SetRangeUser(0, 1);

        eff_HLT_PFHT500_RecoCaloMET->SetLineColor(kBlue);
        eff_HLT_PFHT500_RecoCaloMET->SetMarkerColor(kBlue);
        eff_HLT_PFHT500_RecoCaloMET->SetMarkerStyle(20);
        eff_HLT_PFHT500_RecoCaloMET->GetXaxis()->SetTitle("RecoCaloMET [GeV]");
        eff_HLT_PFHT500_RecoCaloMET->GetYaxis()->SetTitle("eff. HLT_PFHT500_PFMET100_PFMHT100_IDTight");
        eff_HLT_PFHT500_RecoCaloMET->GetXaxis()->SetRangeUser(0, 1500);
        eff_HLT_PFHT500_RecoCaloMET->GetYaxis()->SetRangeUser(0, 1);

        eff_HLT_PFMETNoMu120_RecoCaloMET->SetLineColor(kBlue);
        eff_HLT_PFMETNoMu120_RecoCaloMET->SetMarkerColor(kBlue);
        eff_HLT_PFMETNoMu120_RecoCaloMET->SetMarkerStyle(20);
        eff_HLT_PFMETNoMu120_RecoCaloMET->GetXaxis()->SetTitle("RecoCaloMET [GeV]");
        eff_HLT_PFMETNoMu120_RecoCaloMET->GetYaxis()->SetTitle("eff. HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60");
        eff_HLT_PFMETNoMu120_RecoCaloMET->GetXaxis()->SetRangeUser(0, 1500);
        eff_HLT_PFMETNoMu120_RecoCaloMET->GetYaxis()->SetRangeUser(0, 1);

        eff_HLT_MET105_RecoCaloMET->SetLineColor(kBlue);
        eff_HLT_MET105_RecoCaloMET->SetMarkerColor(kBlue);
        eff_HLT_MET105_RecoCaloMET->SetMarkerStyle(20);
        eff_HLT_MET105_RecoCaloMET->GetXaxis()->SetTitle("RecoCaloMET [GeV]");
        eff_HLT_MET105_RecoCaloMET->GetYaxis()->SetTitle("eff. HLT_MET105_IsoTrk50");
        eff_HLT_MET105_RecoCaloMET->GetXaxis()->SetRangeUser(0, 1500);
        eff_HLT_MET105_RecoCaloMET->GetYaxis()->SetRangeUser(0, 1);

        eff_orMETtrg_RecoCaloMET->SetLineColor(kBlue);
        eff_orMETtrg_RecoCaloMET->SetMarkerColor(kBlue);
        eff_orMETtrg_RecoCaloMET->SetMarkerStyle(20);
        eff_orMETtrg_RecoCaloMET->GetXaxis()->SetTitle("RecoCaloMET [GeV]");
        eff_orMETtrg_RecoCaloMET->GetYaxis()->SetTitle("eff. orMETtrg");
        eff_orMETtrg_RecoCaloMET->GetXaxis()->SetRangeUser(0, 1500);
        eff_orMETtrg_RecoCaloMET->GetYaxis()->SetRangeUser(0, 1);
    }



    // drawing
    TCanvas *c_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET = new TCanvas("c_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET","c_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET",800,800);
    c_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET->cd();
    eff_HLT_PFMET120_PseudoCaloMET->Draw("E1");
    
    TCanvas *c_HLT_PFMET120_PFMHT120_IDTight___RecoPFMET = new TCanvas("c_HLT_PFMET120_PFMHT120_IDTight___RecoPFMET","c_HLT_PFMET120_PFMHT120_IDTight___RecoPFMET",800,800);
    c_HLT_PFMET120_PFMHT120_IDTight___RecoPFMET->cd();
    eff_HLT_PFMET120_RecoPFMET->Draw("E1");

    TCanvas *c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET = new TCanvas("c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET","c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET",800,800);
    c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET->cd();
    eff_HLT_PFHT500_PseudoCaloMET->Draw("E1");

    TCanvas *c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET = new TCanvas("c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET","c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET",800,800);
    c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET->cd();
    eff_HLT_PFHT500_RecoPFMET->Draw("E1");

    TCanvas *c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET = new TCanvas("c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET","c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET",800,800);
    c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET->cd();
    eff_HLT_PFMETNoMu120_PseudoCaloMET->Draw("E1");

    TCanvas *c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET = new TCanvas("c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET","c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET",800,800);
    c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET->cd();
    eff_HLT_PFMETNoMu120_RecoPFMET->Draw("E1");

    TCanvas *c_HLT_MET105_IsoTrk50___PseudoCaloMET = new TCanvas("c_HLT_MET105_IsoTrk50___PseudoCaloMET","c_HLT_MET105_IsoTrk50___PseudoCaloMET",800,800);
    c_HLT_MET105_IsoTrk50___PseudoCaloMET->cd();
    eff_HLT_MET105_PseudoCaloMET->Draw("E1");

    TCanvas *c_HLT_MET105_IsoTrk50___RecoPFMET = new TCanvas("c_HLT_MET105_IsoTrk50___RecoPFMET","c_HLT_MET105_IsoTrk50___RecoPFMET",800,800);
    c_HLT_MET105_IsoTrk50___RecoPFMET->cd();
    eff_HLT_MET105_RecoPFMET->Draw("E1");

    TCanvas *c_orMETtrg___PseudoCaloMET = new TCanvas("c_orMETtrg___PseudoCaloMET","c_orMETtrg___PseudoCaloMET",800,800);
    c_orMETtrg___PseudoCaloMET->cd();
    eff_orMETtrg_PseudoCaloMET->Draw("E1");
    //PseudoCaloMET->Draw("hist same");

    TCanvas *c_orMETtrg___RecoPFMET = new TCanvas("c_orMETtrg___RecoPFMET","c_orMETtrg___RecoPFMET",800,800);
    c_orMETtrg___RecoPFMET->cd();
    eff_orMETtrg_RecoPFMET->Draw("E1");
    //RecoPFMET->Draw("hist same");

    TCanvas *c_orMETtrg___RecoPFMET__PseudoCaloMETCut;
    if (!isAOD) {
        c_orMETtrg___RecoPFMET__PseudoCaloMETCut = new TCanvas("c_orMETtrg___RecoPFMET__PseudoCaloMETCut","c_orMETtrg___RecoPFMET__PseudoCaloMETCut",800,800);
        c_orMETtrg___RecoPFMET__PseudoCaloMETCut->cd();
        eff_orMETtrg_RecoPFMET__PseudoCaloMETCut->Draw("E1");
        //RecoPFMET->Draw("hist same");
    }

    TCanvas *c_HLT_PFMET120_PFMHT120_IDTight___RecoCaloMET;
    TCanvas *c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoCaloMET;
    TCanvas *c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoCaloMET;
    TCanvas *c_HLT_MET105_IsoTrk50___RecoCaloMET;
    TCanvas *c_orMETtrg___RecoCaloMET;

    TCanvas *c_orMETtrg_RecoCaloMET_PseudoCaloMET;
    TCanvas *c_HLT_MET105_IsoTrk50_RecoCaloMET_PseudoCaloMET;
    TCanvas *c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60_RecoCaloMET_PseudoCaloMET;
    TCanvas *c_HLT_PFHT500_PFMET100_PFMHT100_IDTight_RecoCaloMET_PseudoCaloMET;
    TCanvas *c_HLT_PFMET120_PFMHT120_IDTight_RecoCaloMET_PseudoCaloMET;
    if (isAOD) {
        c_HLT_PFMET120_PFMHT120_IDTight___RecoCaloMET = new TCanvas("c_HLT_PFMET120_PFMHT120_IDTight___RecoCaloMET","c_HLT_PFMET120_PFMHT120_IDTight___RecoCaloMET",800,800);
        c_HLT_PFMET120_PFMHT120_IDTight___RecoCaloMET->cd();
        eff_HLT_PFMET120_RecoCaloMET->Draw("E1");

        c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoCaloMET = new TCanvas("c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoCaloMET","c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoCaloMET",800,800);
        c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoCaloMET->cd();
        eff_HLT_PFHT500_RecoCaloMET->Draw("E1");

        c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoCaloMET = new TCanvas("c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoCaloMET","c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoCaloMET",800,800);
        c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoCaloMET->cd();
        eff_HLT_PFMETNoMu120_RecoCaloMET->Draw("E1");

        c_HLT_MET105_IsoTrk50___RecoCaloMET = new TCanvas("c_HLT_MET105_IsoTrk50___RecoCaloMET","c_HLT_MET105_IsoTrk50___RecoCaloMET",800,800);
        c_HLT_MET105_IsoTrk50___RecoCaloMET->cd();
        eff_HLT_MET105_RecoCaloMET->Draw("E1");

        c_orMETtrg___RecoCaloMET = new TCanvas("c_orMETtrg___RecoCaloMET","c_orMETtrg___RecoCaloMET",800,800);
        c_orMETtrg___RecoCaloMET->cd();
        eff_orMETtrg_RecoCaloMET->Draw("E1");

        c_orMETtrg_RecoCaloMET_PseudoCaloMET = DrawWithRatio(eff_orMETtrg_RecoCaloMET, eff_orMETtrg_PseudoCaloMET, c_orMETtrg___RecoCaloMET, "orMETtrg RecoCaloMET vs PseudoCaloMET",
                        "RecoCaloMET/PseudoCaloMET", "E1 same", false);

        c_HLT_MET105_IsoTrk50_RecoCaloMET_PseudoCaloMET = DrawWithRatio(eff_HLT_MET105_RecoCaloMET, eff_HLT_MET105_PseudoCaloMET, c_HLT_MET105_IsoTrk50___RecoCaloMET, "HLT_MET105 RecoCaloMET vs PseudoCaloMET",
                        "RecoCaloMET/PseudoCaloMET", "E1 same", false);
        
        c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60_RecoCaloMET_PseudoCaloMET = DrawWithRatio(eff_HLT_PFMETNoMu120_RecoCaloMET, eff_HLT_PFMETNoMu120_PseudoCaloMET, c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoCaloMET, "HLT_PFMETNoMu120 RecoCaloMET vs PseudoCaloMET",
                        "RecoCaloMET/PseudoCaloMET", "E1 same", false);

        c_HLT_PFHT500_PFMET100_PFMHT100_IDTight_RecoCaloMET_PseudoCaloMET = DrawWithRatio(eff_HLT_PFHT500_RecoCaloMET, eff_HLT_PFHT500_PseudoCaloMET, c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoCaloMET, "HLT_PFHT500 RecoCaloMET vs PseudoCaloMET",
                        "RecoCaloMET/PseudoCaloMET", "E1 same", false);

        c_HLT_PFMET120_PFMHT120_IDTight_RecoCaloMET_PseudoCaloMET = DrawWithRatio(eff_HLT_PFMET120_RecoCaloMET, eff_HLT_PFMET120_PseudoCaloMET, c_HLT_PFMET120_PFMHT120_IDTight___RecoCaloMET, "HLT_PFMET120 RecoCaloMET vs PseudoCaloMET",
                        "RecoCaloMET/PseudoCaloMET", "E1 same", false);
    }


    // saving
    ofile->cd();
    c_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET->Write();
    c_HLT_PFMET120_PFMHT120_IDTight___RecoPFMET->Write();
    c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET->Write();
    c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET->Write();
    c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET->Write();
    c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET->Write();
    c_HLT_MET105_IsoTrk50___PseudoCaloMET->Write();
    c_HLT_MET105_IsoTrk50___RecoPFMET->Write();
    c_orMETtrg___PseudoCaloMET->Write();
    c_orMETtrg___RecoPFMET->Write();
    if (!isAOD) c_orMETtrg___RecoPFMET__PseudoCaloMETCut->Write();
    if (isAOD) {
        c_HLT_PFMET120_PFMHT120_IDTight___RecoCaloMET->Write();
        c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoCaloMET->Write();
        c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoCaloMET->Write();
        c_HLT_MET105_IsoTrk50___RecoCaloMET->Write();
        c_orMETtrg___RecoCaloMET->Write();

        c_orMETtrg_RecoCaloMET_PseudoCaloMET->Write();
        c_HLT_MET105_IsoTrk50_RecoCaloMET_PseudoCaloMET->Write();
        c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60_RecoCaloMET_PseudoCaloMET->Write();
        c_HLT_PFHT500_PFMET100_PFMHT100_IDTight_RecoCaloMET_PseudoCaloMET->Write();
        c_HLT_PFMET120_PFMHT120_IDTight_RecoCaloMET_PseudoCaloMET->Write();
    }
    ofile->Close();


    return;
}


void PFMET_Cut(bool isAOD=false) {

    TFile *ofile = new TFile("PlayWithHistos/PFMET_Cut_v2.root", "RECREATE");

    TFile *ifile_AOD;
    if (isAOD) ifile_AOD = new TFile("../output/Gluino2000_Run2_METtrgEff_AOD_V11p15_Eta2p4.root", "READ");
    TFile *ifile_miniAOD = new TFile("../output/Gluino2000_miniAOD_FULL_MET_V11p12_Eta2p4.root", "READ");

    // input histos
    TH1F *RecoPFMET_AOD; TH1F *RecoPFMET_cutPseudoCaloMET_AOD; TH1F *RecoPFMET_cutRecoCaloMET_AOD;
    if (isAOD) {
        RecoPFMET_AOD = (TH1F*)ifile_AOD->Get("RecoPFMET");
        RecoPFMET_cutPseudoCaloMET_AOD = (TH1F*)ifile_AOD->Get("RecoPFMET___wPseudoCaloMETCut");
        RecoPFMET_cutRecoCaloMET_AOD = (TH1F*)ifile_AOD->Get("RecoPFMET___wCaloMETCut");
    }
    

    TH1F *RecoPFMET_miniAOD = (TH1F*)ifile_miniAOD->Get("RecoPFMET");
    TH1F *RecoPFMET_cutPseudoCaloMET_miniAOD = (TH1F*)ifile_miniAOD->Get("RecoPFMET___wPseudoCaloMETCut");

    // setup
    RecoPFMET_miniAOD->SetLineColor(kViolet);
    RecoPFMET_miniAOD->SetMarkerColor(kViolet);
    RecoPFMET_miniAOD->SetMarkerStyle(23);
    RecoPFMET_miniAOD->Rebin(4);
    RecoPFMET_miniAOD->GetXaxis()->SetTitle("RecoPFMET [GeV]");
    RecoPFMET_miniAOD->GetYaxis()->SetTitle("Events");

    if (isAOD) {
        RecoPFMET_cutPseudoCaloMET_AOD->SetLineColor(kRed);
        RecoPFMET_cutPseudoCaloMET_AOD->SetMarkerColor(kRed);
        RecoPFMET_cutPseudoCaloMET_AOD->SetMarkerStyle(20);
        RecoPFMET_cutPseudoCaloMET_AOD->GetXaxis()->SetTitle("RecoPFMET [GeV]");
        RecoPFMET_cutPseudoCaloMET_AOD->GetYaxis()->SetTitle("Events");
        RecoPFMET_cutPseudoCaloMET_AOD->Rebin(4);

        RecoPFMET_AOD->SetLineColor(kBlack);
        RecoPFMET_AOD->SetMarkerColor(kBlack);
        RecoPFMET_AOD->SetMarkerStyle(43);
        RecoPFMET_AOD->Rebin(4);
        RecoPFMET_AOD->GetXaxis()->SetTitle("RecoPFMET [GeV]");
        RecoPFMET_AOD->GetYaxis()->SetTitle("Events");

        RecoPFMET_cutRecoCaloMET_AOD->SetLineColor(kGreen+2);
        RecoPFMET_cutRecoCaloMET_AOD->SetMarkerColor(kGreen+2);
        RecoPFMET_cutRecoCaloMET_AOD->SetMarkerStyle(22);
        RecoPFMET_cutRecoCaloMET_AOD->Rebin(4);
    }

    RecoPFMET_cutPseudoCaloMET_miniAOD->SetLineColor(kBlue);
    RecoPFMET_cutPseudoCaloMET_miniAOD->SetMarkerColor(kBlue);
    RecoPFMET_cutPseudoCaloMET_miniAOD->SetMarkerStyle(21);
    RecoPFMET_cutPseudoCaloMET_miniAOD->Rebin(4);

    


    // drawing
    TCanvas *c_PFMET_AODcut_ratio; TCanvas *c_PFMET_nocut_ratio;
    if (isAOD) {
        cout << "c_PFMET_nocut" << endl;
        TCanvas *c_PFMET_nocut = new TCanvas("c_PFMET_nocut","c_PFMET_nocut",800,800);
        c_PFMET_nocut->cd();
        RecoPFMET_AOD->Draw("E1");
        RecoPFMET_miniAOD->Draw("E1 same");
        TLegend *leg_PFMET_nocut = new TLegend(0.6,0.7,0.88,0.88);
        leg_PFMET_nocut->AddEntry(RecoPFMET_AOD, "AOD", "ep");
        leg_PFMET_nocut->AddEntry(RecoPFMET_miniAOD, "miniAOD", "ep");
        leg_PFMET_nocut->Draw("same");
        leg_PFMET_nocut->SetBorderSize(0);
        leg_PFMET_nocut->SetFillStyle(0);
        c_PFMET_nocut_ratio = DrawWithRatio(RecoPFMET_AOD, RecoPFMET_miniAOD, c_PFMET_nocut, "RecoPFMET AOD vs miniAOD", "AOD/miniAOD", "E1 same", false);

        cout << "c_PFMET_AODcut" << endl;
        TCanvas *c_PFMET_AODcut = new TCanvas("c_PFMET_AODcut","c_PFMET_AODcut",800,800);
        c_PFMET_AODcut->cd();
        RecoPFMET_AOD->Draw("E1");
        RecoPFMET_cutPseudoCaloMET_AOD->Draw("E1 same");
        TLegend *leg_PFMET_AODcut = new TLegend(0.6,0.7,0.88,0.88);
        leg_PFMET_AODcut->AddEntry(RecoPFMET_AOD, "AOD wo PseudoCaloMET cut", "ep");
        leg_PFMET_AODcut->AddEntry(RecoPFMET_cutPseudoCaloMET_AOD, "AOD with PseudoCaloMET cut", "ep");
        leg_PFMET_AODcut->Draw("same");
        leg_PFMET_AODcut->SetBorderSize(0);
        leg_PFMET_AODcut->SetFillStyle(0);
        c_PFMET_AODcut_ratio = DrawWithRatio(RecoPFMET_AOD, RecoPFMET_cutPseudoCaloMET_AOD, c_PFMET_AODcut, "RecoPFMET AOD cut", "wo cut/cut", "E1 same", false);
    }

    cout << "c_PFMET_miniAODcut" << endl;
    TCanvas *c_PFMET_miniAODcut = new TCanvas("c_PFMET_miniAODcut","c_PFMET_miniAODcut",800,800);
    c_PFMET_miniAODcut->cd();
    RecoPFMET_miniAOD->Draw("E1");
    RecoPFMET_cutPseudoCaloMET_miniAOD->Draw("E1 same");
    TLegend *leg_PFMET_miniAODcut = new TLegend(0.6,0.7,0.88,0.88);
    leg_PFMET_miniAODcut->AddEntry(RecoPFMET_miniAOD, "miniAOD wo PseudoCaloMET cut", "ep");
    leg_PFMET_miniAODcut->AddEntry(RecoPFMET_cutPseudoCaloMET_miniAOD, "miniAOD with PseudoCaloMET cut", "ep");
    leg_PFMET_miniAODcut->Draw("same");
    leg_PFMET_miniAODcut->SetBorderSize(0);
    leg_PFMET_miniAODcut->SetFillStyle(0);
    TCanvas *c_PFMET_miniAODcut_ratio = DrawWithRatio(RecoPFMET_miniAOD, RecoPFMET_cutPseudoCaloMET_miniAOD, c_PFMET_miniAODcut, "RecoPFMET miniAOD cut", "wo cut/cut", "E1 same", false);


    TCanvas *c_PFMET_CaloMETcut_ratio; TCanvas *c_PFMET_ratio;
    if (isAOD) {
        cout << "c_PFMET_CaloMETcut" << endl;
        TCanvas *c_PFMET_CaloMETcut = new TCanvas("c_PFMET_CaloMETcut","c_PFMET_CaloMETcut",800,800);
        c_PFMET_CaloMETcut->cd();
        RecoPFMET_cutPseudoCaloMET_AOD->Draw("E1");
        RecoPFMET_cutRecoCaloMET_AOD->Draw("E1 same");
        TLegend *leg_PFMET_CaloMETcut = new TLegend(0.6,0.7,0.88,0.88);
        leg_PFMET_CaloMETcut->AddEntry(RecoPFMET_cutPseudoCaloMET_AOD, "AOD w PseudoCaloMET cut", "ep");
        leg_PFMET_CaloMETcut->AddEntry(RecoPFMET_cutRecoCaloMET_AOD, "AOD w RecoCaloMET cut", "ep");
        leg_PFMET_CaloMETcut->Draw("same");
        leg_PFMET_CaloMETcut->SetBorderSize(0);
        leg_PFMET_CaloMETcut->SetFillStyle(0);
        c_PFMET_CaloMETcut_ratio = DrawWithRatio(RecoPFMET_cutPseudoCaloMET_AOD, RecoPFMET_cutRecoCaloMET_AOD, c_PFMET_CaloMETcut, "RecoPFMET AOD", "PseudoCaloMET cut/RecoCaloMET cut", "E1 same", false);
    
            cout << "c_PFMET_onlycut" << endl;
        TCanvas *c_PFMET_onlycut = new TCanvas("c_PFMET_onlycut","c_PFMET_onlycut",800,800);
        c_PFMET_onlycut->cd();
        RecoPFMET_cutPseudoCaloMET_AOD->Draw("E1");
        RecoPFMET_cutPseudoCaloMET_miniAOD->Draw("E1 same");
        TLegend *leg_PFMET = new TLegend(0.6,0.7,0.88,0.88);
        leg_PFMET->AddEntry(RecoPFMET_cutPseudoCaloMET_AOD, "AOD", "ep");
        leg_PFMET->AddEntry(RecoPFMET_cutPseudoCaloMET_miniAOD, "miniAOD", "ep");
        leg_PFMET->Draw("same");
        leg_PFMET->SetBorderSize(0);
        leg_PFMET->SetFillStyle(0);
        c_PFMET_ratio = DrawWithRatio(RecoPFMET_cutPseudoCaloMET_AOD, RecoPFMET_cutPseudoCaloMET_miniAOD, c_PFMET_onlycut, "RecoPFMET with PseudoCaloMET cut", "AOD/miniAOD", "E1 same", false);
    }
    // saving
    cout << "saving histos..." << endl;
    ofile->cd();
    c_PFMET_miniAODcut_ratio->Write();
    if (isAOD) {
        c_PFMET_CaloMETcut_ratio->Write();
        c_PFMET_AODcut_ratio->Write();
        c_PFMET_ratio->Write();
        c_PFMET_nocut_ratio->Write();
    }
    ofile->Close();

    return;

}


void TrigEff_AODvsMiniAOD() {

    TFile *ofile = new TFile("PlayWithHistos/TrigEff_AODvsMiniAOD.root", "RECREATE");

    TFile *ifile_AOD = new TFile("../output/Gluino2000_Run2_METtrgEff_AOD_V11p15_Eta2p4.root", "READ");
    TFile *ifile_miniAOD = new TFile("../output/Gluino2000_Run2_METtrgEff_V11p15_Eta2p4.root", "READ");


    // input histos
    TH1F *RecoPFMET_AOD = (TH1F*)ifile_AOD->Get("OnlyMET_RecoPFMET");
    TH1F *RecoPFMET_miniAOD = (TH1F*)ifile_miniAOD->Get("OnlyMET_RecoPFMET");
    TH1F *if___orMETtrg___RecoPFMET_AOD = (TH1F*)ifile_AOD->Get("OnlyMET_if___orMETtrg___RecoPFMET");
    TH1F *if___orMETtrg___RecoPFMET_miniAOD = (TH1F*)ifile_miniAOD->Get("OnlyMET_if___orMETtrg___RecoPFMET");

    TH1F *PseudoCaloMET_AOD = (TH1F*)ifile_AOD->Get("OnlyMET_PseudoCaloMET");
    TH1F *PseudoCaloMET_miniAOD = (TH1F*)ifile_miniAOD->Get("OnlyMET_PseudoCaloMET");
    TH1F *if___orMETtrg___PseudoCaloMET_AOD = (TH1F*)ifile_AOD->Get("OnlyMET_if___orMETtrg___PseudoCaloMET");
    TH1F *if___orMETtrg___PseudoCaloMET_miniAOD = (TH1F*)ifile_miniAOD->Get("OnlyMET_if___orMETtrg___PseudoCaloMET");

    
    // setup
    if___orMETtrg___RecoPFMET_AOD->Sumw2();
    TH1F *eff_orMETtrg_RecoPFMET_AOD = (TH1F*)if___orMETtrg___RecoPFMET_AOD->Clone("eff_orMETtrg_RecoPFMET_AOD");
    if___orMETtrg___RecoPFMET_miniAOD->Sumw2();
    TH1F *eff_orMETtrg_RecoPFMET_miniAOD = (TH1F*)if___orMETtrg___RecoPFMET_miniAOD->Clone("eff_orMETtrg_RecoPFMET_miniAOD");
    
    if___orMETtrg___PseudoCaloMET_AOD->Sumw2();
    TH1F *eff_orMETtrg_PseudoCaloMET_AOD = (TH1F*)if___orMETtrg___PseudoCaloMET_AOD->Clone("eff_orMETtrg_PseudoCaloMET_AOD");
    if___orMETtrg___PseudoCaloMET_miniAOD->Sumw2();
    TH1F *eff_orMETtrg_PseudoCaloMET_miniAOD = (TH1F*)if___orMETtrg___PseudoCaloMET_miniAOD->Clone("eff_orMETtrg_PseudoCaloMET_miniAOD");

    eff_orMETtrg_RecoPFMET_AOD->Divide(RecoPFMET_AOD);
    eff_orMETtrg_RecoPFMET_miniAOD->Divide(RecoPFMET_miniAOD);
    eff_orMETtrg_PseudoCaloMET_AOD->Divide(PseudoCaloMET_AOD);
    eff_orMETtrg_PseudoCaloMET_miniAOD->Divide(PseudoCaloMET_miniAOD);


    // styling
    eff_orMETtrg_RecoPFMET_AOD->SetLineColor(kRed);
    eff_orMETtrg_RecoPFMET_AOD->SetMarkerColor(kRed);
    eff_orMETtrg_RecoPFMET_AOD->SetMarkerStyle(21);
    eff_orMETtrg_RecoPFMET_AOD->GetXaxis()->SetTitle("RecoPFMET [GeV]");
    eff_orMETtrg_RecoPFMET_AOD->GetYaxis()->SetTitle("eff. orMETtrg");
    eff_orMETtrg_RecoPFMET_AOD->GetXaxis()->SetRangeUser(0, 1500);
    eff_orMETtrg_RecoPFMET_AOD->GetYaxis()->SetRangeUser(0, 1);

    eff_orMETtrg_RecoPFMET_miniAOD->SetLineColor(kBlue);
    eff_orMETtrg_RecoPFMET_miniAOD->SetMarkerColor(kBlue);
    eff_orMETtrg_RecoPFMET_miniAOD->SetMarkerStyle(22);
    eff_orMETtrg_RecoPFMET_miniAOD->GetXaxis()->SetTitle("RecoPFMET [GeV]");
    eff_orMETtrg_RecoPFMET_miniAOD->GetYaxis()->SetTitle("eff. orMETtrg");
    eff_orMETtrg_RecoPFMET_miniAOD->GetXaxis()->SetRangeUser(0, 1500);
    eff_orMETtrg_RecoPFMET_miniAOD->GetYaxis()->SetRangeUser(0, 1);

    eff_orMETtrg_PseudoCaloMET_AOD->SetLineColor(kRed);
    eff_orMETtrg_PseudoCaloMET_AOD->SetMarkerColor(kRed);
    eff_orMETtrg_PseudoCaloMET_AOD->SetMarkerStyle(21);
    eff_orMETtrg_PseudoCaloMET_AOD->GetXaxis()->SetTitle("PseudoMET [GeV]");
    eff_orMETtrg_PseudoCaloMET_AOD->GetYaxis()->SetTitle("eff. orMETtrg");
    eff_orMETtrg_PseudoCaloMET_AOD->GetXaxis()->SetRangeUser(0, 1500);
    eff_orMETtrg_PseudoCaloMET_AOD->GetYaxis()->SetRangeUser(0, 1);

    eff_orMETtrg_PseudoCaloMET_miniAOD->SetLineColor(kBlue);
    eff_orMETtrg_PseudoCaloMET_miniAOD->SetMarkerColor(kBlue);
    eff_orMETtrg_PseudoCaloMET_miniAOD->SetMarkerStyle(22);
    eff_orMETtrg_PseudoCaloMET_miniAOD->GetXaxis()->SetTitle("PseudoMET [GeV]");
    eff_orMETtrg_PseudoCaloMET_miniAOD->GetYaxis()->SetTitle("eff. orMETtrg");
    eff_orMETtrg_PseudoCaloMET_miniAOD->GetXaxis()->SetRangeUser(0, 1500);
    eff_orMETtrg_PseudoCaloMET_miniAOD->GetYaxis()->SetRangeUser(0, 1);


    // drawing
    TCanvas *c_PFMET = new TCanvas("c_PFMET","c_PFMET",800,800);
    c_PFMET->cd();
    eff_orMETtrg_RecoPFMET_miniAOD->Draw("E1");
    eff_orMETtrg_RecoPFMET_AOD->Draw("E1 same");
    TLegend *leg_PFMET = new TLegend(0.6,0.7,0.88,0.88);
    leg_PFMET->AddEntry(eff_orMETtrg_RecoPFMET_AOD, "AOD", "ep");
    leg_PFMET->AddEntry(eff_orMETtrg_RecoPFMET_miniAOD, "miniAOD", "ep");
    leg_PFMET->Draw("same");
    leg_PFMET->SetBorderSize(0);
    leg_PFMET->SetFillStyle(0);
    TCanvas *c_PFMET_ratio = DrawWithRatio(eff_orMETtrg_RecoPFMET_miniAOD, eff_orMETtrg_RecoPFMET_AOD, c_PFMET, "RecoPFMET", "miniAOD/AOD", "E1 same", false);

    TCanvas *c_PseudoCaloMET = new TCanvas("c_PseudoCaloMET","c_PseudoCaloMET",800,800);
    c_PseudoCaloMET->cd();
    eff_orMETtrg_PseudoCaloMET_miniAOD->Draw("E1");
    eff_orMETtrg_PseudoCaloMET_AOD->Draw("E1 same");
    TLegend *leg_PseudoCaloMET = new TLegend(0.6,0.7,0.88,0.88);
    leg_PseudoCaloMET->AddEntry(eff_orMETtrg_PseudoCaloMET_AOD, "AOD", "ep");
    leg_PseudoCaloMET->AddEntry(eff_orMETtrg_PseudoCaloMET_miniAOD, "miniAOD", "ep");
    leg_PseudoCaloMET->Draw("same");
    leg_PseudoCaloMET->SetBorderSize(0);
    leg_PseudoCaloMET->SetFillStyle(0);
    TCanvas *c_PseudoCaloMET_ratio = DrawWithRatio(eff_orMETtrg_PseudoCaloMET_miniAOD, eff_orMETtrg_PseudoCaloMET_AOD, c_PseudoCaloMET, "PseudoCaloMET", "miniAOD/AOD", "E1 same", false);


    // saving
    ofile->cd();
    c_PFMET->Write();
    c_PFMET_ratio->Write();
    c_PseudoCaloMET->Write();
    c_PseudoCaloMET_ratio->Write();
    ofile->Close();

    return;
}


void Cutflows(std::string ifileAOD, std::string ifileminiAOD, bool HLTMu = true, bool normToOne = false, std::string PseudoMETon="") {
    
    std::string ofile = std::string("PlayWithHistos/EventCutflow");

    TFile *ifile_AOD_ = new TFile(ifileAOD.c_str(), "READ");
    TFile *ifile_miniAOD_ = new TFile(ifileminiAOD.c_str(), "READ");

    TH1F *hAOD_NotrackCut = (TH1F*)ifile_AOD_->Get("EventCutflow_NotrackCut");
    TH1F *hminiAOD_NotrackCut = (TH1F*)ifile_miniAOD_->Get("EventCutflow_NotrackCut");
    TH1F *hAOD = (TH1F*)ifile_AOD_->Get("EventCutflow");
    TH1F *hminiAOD = (TH1F*)ifile_miniAOD_->Get("EventCutflow");


    //     
    int color1 = kBlue-7;
    int color2 = kRed+1;
    int color3 = kGreen+3;
    int color4 = kSpring;
    TString labelCMS = "CMS Internal";

    // --- Clones
    TH1* hAOD_NotrackCut_draw = (TH1*)hAOD_NotrackCut->Clone(hAOD_NotrackCut->GetName() + TString("_draw"));
    TH1* hminiAOD_NotrackCut_draw = (TH1*)hminiAOD_NotrackCut->Clone(hminiAOD_NotrackCut->GetName() + TString("_draw"));
    TH1* hAOD_NotrackCut_r = (TH1*)hAOD_NotrackCut->Clone(hAOD_NotrackCut->GetName() + TString("_r"));
    TH1* hminiAOD_NotrackCut_r = (TH1*)hminiAOD_NotrackCut->Clone(hminiAOD_NotrackCut->GetName() + TString("_r"));
    TH1* hAOD_draw = (TH1*)hAOD->Clone(hAOD->GetName() + TString("_draw"));
    TH1* hminiAOD_draw = (TH1*)hminiAOD->Clone(hminiAOD->GetName() + TString("_draw"));
    TH1* hAOD_r = (TH1*)hAOD->Clone(hAOD->GetName() + TString("_r"));
    TH1* hminiAOD_r = (TH1*)hminiAOD->Clone(hminiAOD->GetName() + TString("_r"));

    gStyle->SetOptStat(0);

    hAOD_NotrackCut_draw->Sumw2();
    hminiAOD_NotrackCut->Sumw2();
    hAOD_draw->Sumw2();
    hminiAOD_draw->Sumw2();

    if (normToOne) {
        hAOD_NotrackCut_draw->Scale(1. / hAOD_NotrackCut_draw->GetBinContent(1));
        hminiAOD_NotrackCut_draw->Scale(1. / hminiAOD_NotrackCut_draw->GetBinContent(1));
        hAOD_draw->Scale(1. / hAOD_draw->GetBinContent(1));
        hminiAOD_draw->Scale(1. / hminiAOD_draw->GetBinContent(1));
    }

    // --- Style
    hAOD_NotrackCut_draw->SetLineWidth(2);
    hminiAOD_NotrackCut_draw->SetLineWidth(2);
    hAOD_NotrackCut_draw->SetMarkerStyle(0);
    hminiAOD_NotrackCut_draw->SetMarkerStyle(0);
    hAOD_draw->SetLineWidth(2);
    hminiAOD_draw->SetLineWidth(2);
    hAOD_draw->SetMarkerStyle(0);
    hminiAOD_draw->SetMarkerStyle(0);

    hAOD_NotrackCut_draw->SetLineColor(color3);
    hminiAOD_NotrackCut_draw->SetLineColor(color4);
    hAOD_NotrackCut_draw->SetFillStyle(1001);
    hAOD_NotrackCut_draw->SetFillColorAlpha(color3, 0.5);
    hAOD_draw->SetLineColor(color1);
    hminiAOD_draw->SetLineColor(color2);
    hAOD_draw->SetFillStyle(1001);
    hAOD_draw->SetFillColorAlpha(color1, 0.5);

    // --- Canvas + pads
    TCanvas* c = new TCanvas(hAOD_NotrackCut_draw->GetName() + TString("_canvas"), "", 700, 700);
    c->Divide(1, 2);

    // ----------------- PAD TOP -----------------
    TPad* padTop = (TPad*)c->cd(1);
    padTop->SetPad(0.0, 0.35, 1.0, 1.0);
    padTop->SetTopMargin(0.08);
    padTop->SetBottomMargin(0.02);
    padTop->SetLeftMargin(0.16);
    padTop->SetRightMargin(0.05);
    padTop->SetLogy();

    double ymax = std::max(hAOD_NotrackCut_draw->GetMaximum(), hminiAOD_NotrackCut_draw->GetMaximum());
    double ymin = std::min(hAOD_NotrackCut_draw->GetMinimum(), hminiAOD_NotrackCut_draw->GetMinimum());
    hAOD_NotrackCut_draw->SetMaximum(ymax * 3);
    hAOD_NotrackCut_draw->SetMinimum(std::max(0.1, ymin / 2.));
    hAOD_NotrackCut_draw->GetXaxis()->SetLabelSize(0);
    hAOD_NotrackCut_draw->GetXaxis()->SetRangeUser(0, 18);
    hAOD_NotrackCut_draw->GetYaxis()->SetTitle("Entries");
    hAOD_NotrackCut_draw->GetYaxis()->SetTitleSize(0.10);
    hAOD_NotrackCut_draw->GetYaxis()->SetTitleOffset(1.4);

    hAOD_draw->SetMaximum(std::max(hAOD_draw->GetMaximum(), hAOD_draw->GetMaximum()) * 3);
    hAOD_draw->SetMinimum(std::min(hAOD_draw->GetMinimum(), hAOD_draw->GetMinimum())/2);    
    if (normToOne) hAOD_draw->SetMinimum(0.01);
    hAOD_draw->GetXaxis()->SetLabelSize(0);
    hAOD_draw->GetXaxis()->SetRangeUser(0, 18);
    hAOD_draw->GetYaxis()->SetTitle("Events");
    if (normToOne) hAOD_draw->GetYaxis()->SetTitle("Events (normalized to 1 in bin 1)");
    hAOD_draw->GetYaxis()->SetTitleSize(0.05);
    hAOD_draw->GetYaxis()->SetTitleOffset(0.8);
    //hAOD_NotrackCut_draw->Draw("HIST");         // green
    hAOD_draw->Draw("HIST");               // blue
    hminiAOD_draw->Draw("HIST SAME");           // red
    //hminiAOD_NotrackCut_draw->Draw("HIST SAME");// magenta

    // --- Légende
    TLegend* leg = new TLegend(0.60, 0.73, 0.90, 0.88);
    leg->SetNColumns(2);
    leg->SetBorderSize(0);
    leg->AddEntry(hAOD_draw, "AOD", "f");
    //leg->AddEntry(hAOD_NotrackCut_draw, "AOD no track cut", "f");
    leg->AddEntry(hminiAOD_draw, "miniAOD", "l");
    //leg->AddEntry(hminiAOD_NotrackCut_draw, "miniAOD no track cut", "l");
    leg->Draw();

    // --- Label CMS
    TLatex latex;
    latex.SetNDC();
    latex.SetTextSize(0.045);
    latex.SetTextFont(42);
    latex.DrawLatex(0.18, 0.88, labelCMS);

    // ----------------- PAD BOTTOM -----------------
    TPad* padBot = (TPad*)c->cd(2);
    padBot->SetPad(0.0, 0.015, 1.0, 0.35);
    padBot->SetTopMargin(0.02);
    padBot->SetBottomMargin(0.55);
    padBot->SetLeftMargin(0.16);
    padBot->SetRightMargin(0.05);
    padBot->SetGridy();

    TH1* ratio = (TH1*)hminiAOD_r->Clone(hminiAOD->GetName() + TString("_ratio"));
    ratio->Divide(hAOD_r);
    ratio->SetTitle("");

    ratio->GetYaxis()->SetTitle("miniAOD / AOD");
    ratio->GetYaxis()->SetNdivisions(505);
    ratio->GetYaxis()->SetTitleSize(0.08);
    ratio->GetYaxis()->SetTitleOffset(0.6);
    ratio->GetYaxis()->SetLabelSize(0.09);

    ratio->GetXaxis()->SetTitle("");
    ratio->GetXaxis()->SetTitleSize(0.11);
    ratio->GetXaxis()->SetLabelSize(0.10);
    ratio->GetXaxis()->SetLabelOffset(0.02);

    ratio->SetLineColor(color2);
    ratio->SetMarkerColor(color2);
    ratio->SetMarkerStyle(20);
    ratio->SetMarkerSize(0.7);
    ratio->SetMinimum(0.0);
    ratio->SetMaximum(2.0);


    TH1* ratio_Cut = (TH1*)hminiAOD_NotrackCut_r->Clone(hminiAOD_NotrackCut->GetName() + TString("_ratio_Cut"));
    ratio_Cut->Divide(hAOD_NotrackCut_r);
    ratio_Cut->SetTitle("");

    ratio_Cut->GetYaxis()->SetNdivisions(505);
    ratio_Cut->GetYaxis()->SetTitleSize(0.10);
    ratio_Cut->GetYaxis()->SetTitleOffset(0.6);
    ratio_Cut->GetYaxis()->SetLabelSize(0.09);

    ratio_Cut->GetXaxis()->SetTitleSize(0.11);
    ratio_Cut->GetXaxis()->SetLabelSize(0.10);
    ratio_Cut->GetXaxis()->SetLabelOffset(0.02);

    ratio_Cut->SetLineColor(color4);
    ratio_Cut->SetMarkerColor(color4);
    ratio_Cut->SetMarkerStyle(22);
    ratio_Cut->SetMarkerSize(0.7);
    ratio_Cut->SetMinimum(0.0);
    ratio_Cut->SetMaximum(2.0);

    // --- Labels X
    std::vector<TString> xlabel;
    if (HLTMu) xlabel = {"All","HLT_Mu50","METfilters (true)", "CaloMET > 170 (true)", "p_{T}>55","|#eta|<2.4","N_{no-L1 pixel hits}#geq2","f_{valid hits}>0.8",
                "N_{dEdx hits}#geq10","HighPurity","#chi^{2}/N_{dof}<5","|d_{z}|<0.1","|d_{xy}|<0.02","I^{rel}_{PF iso}<0.02","I^{trk}_{dr03}<15",
                "E/p<0.3","#sigma_{p_{T}}/p_{T}^{2}<0.0008","F_{i}>0.3","#sigma_{p_{T}}/p_{T}<1","I_{h}>C"};
    else xlabel = {"All","HLT MET","METfilters", "PseudoMET > 170", "p_{T}>55","|#eta|<2.4","N_{no-L1 pixel hits}#geq2","f_{valid hits}>0.8",
                "N_{dEdx hits}#geq10","HighPurity","#chi^{2}/N_{dof}<5","|d_{z}|<0.1","|d_{xy}|<0.02","I^{rel}_{PF iso}<0.02","I^{trk}_{dr03}<15",
                "E/p<0.3","#sigma_{p_{T}}/p_{T}^{2}<0.0008","F_{i}>0.3","#sigma_{p_{T}}/p_{T}<1","I_{h}>C"};

    for (int i = 1; i <= ratio->GetNbinsX(); i++) {
        if (i-1 < xlabel.size())
            ratio->GetXaxis()->SetBinLabel(i, xlabel[i-1]);
    }

    gPad->SetTickx(0);
    ratio->LabelsOption("v", "X");
    ratio->SetLabelSize(0.08, "X");
    ratio->GetXaxis()->SetRangeUser(0, 18);
    ratio->Draw("E1");
    //ratio_Cut->Draw("E1 SAME");

    // --- ratio values
    for (int i = 1; i <= ratio->GetNbinsX(); i++) {
        double x = ratio->GetBinCenter(i);
        double y = ratio->GetBinContent(i);
        double err = ratio->GetBinError(i);
        if (y == 0) continue;

        TLatex txt;
        txt.SetTextAlign(22);
        txt.SetTextSize(0.06);
        txt.SetTextFont(42);
        //txt.SetTextColor(color2);
        //if (i==18) txt.DrawLatex(x, y + err + 0.15, Form("%.2f", y));
        txt.SetTextColor(kBlack);
        txt.DrawLatex(x, y + err + 0.15, Form("%.2f", y));
    }

    for (int i = 1; i <= ratio->GetNbinsX(); i++) {
        double x = ratio_Cut->GetBinCenter(i);
        double y = ratio_Cut->GetBinContent(i);
        double err = ratio_Cut->GetBinError(i);
        if (y == 0) continue;

        TLatex txt;
        txt.SetTextAlign(22);
        txt.SetTextSize(0.07);
        txt.SetTextFont(42);
        txt.SetTextColor(color4);
        //if (i==18) txt.DrawLatex(x, y - err - 0.25, Form("%.2f", y));
    }

    // --- Saving
    ofile += HLTMu ? "_HLTMu" : "_HLTMET";
    if (normToOne) ofile += "_normToOne";
    std::string outname = ofile + PseudoMETon + ".pdf";

    c->SaveAs(outname.c_str());

    if (normToOne) {
        cout << "AOD normalized to 1:" << endl;
        for (int i = 1; i <= hAOD_draw->GetNbinsX(); i++) {
            cout << "Bin " << i << " AOD : " << hAOD_draw->GetBinContent(i) << " +/- " << hAOD_draw->GetBinError(i) << endl;
            cout << "  miniAOD : " << hminiAOD_draw->GetBinContent(i) << " +/- " << hminiAOD_draw->GetBinError(i) << endl;
        }
    }
}


void MET_trg_eff(const char *inputfileDATA, const char *inputfileMC) {

    TFile *ofile = new TFile("PlayWithHistos/MET_trg_eff_MC_vs_data.root", "RECREATE");

    TFile *ifileDATA = new TFile(Form("%s", inputfileDATA), "READ");
    TFile *ifileMC = new TFile(Form("%s", inputfileMC), "READ");


    // input histos
    TH1F *PseudoCaloMET_MC = (TH1F*)ifileMC->Get("CalibPseudoMET_PseudoCaloMET");
    TH1F *RecoPFMET_MC = (TH1F*)ifileMC->Get("CalibPseudoMET_RecoPFMET");
    TH1F *if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET_MC = (TH1F*)ifileMC->Get("CalibPseudoMET_if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET");
    TH1F *if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET_MC = (TH1F*)ifileMC->Get("CalibPseudoMET_if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET");            
    TH1F *if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET_MC = (TH1F*)ifileMC->Get("CalibPseudoMET_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET");
    TH1F *if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET_MC = (TH1F*)ifileMC->Get("CalibPseudoMET_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET");
    TH1F *if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET_MC = (TH1F*)ifileMC->Get("CalibPseudoMET_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET");
    TH1F *if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET_MC = (TH1F*)ifileMC->Get("CalibPseudoMET_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET");
    TH1F *if___HLT_MET105_IsoTrk50___PseudoCaloMET_MC = (TH1F*)ifileMC->Get("CalibPseudoMET_if___HLT_MET105_IsoTrk50___PseudoCaloMET");
    TH1F *if___HLT_MET105_IsoTrk50___RecoPFMET_MC = (TH1F*)ifileMC->Get("CalibPseudoMET_if___HLT_MET105_IsoTrk50___RecoPFMET");
    TH1F *if___orMETtrg___PseudoCaloMET_MC = (TH1F*)ifileMC->Get("CalibPseudoMET_if___orMETtrg___PseudoCaloMET");
    TH1F *if___orMETtrg___RecoPFMET_MC = (TH1F*)ifileMC->Get("CalibPseudoMET_if___orMETtrg___RecoPFMET");
    TH1F *if___orMETtrg___RecoPFMET__PseudoCaloMETCut_MC = (TH1F*)ifileMC->Get("OnlyMET_if___orMETtrg___RecoPFMET__PseudoCaloMETCut");

    TH1F *PseudoCaloMET_DATA = (TH1F*)ifileDATA->Get("CalibPseudoMET_PseudoCaloMET");
    TH1F *RecoPFMET_DATA = (TH1F*)ifileDATA->Get("CalibPseudoMET_RecoPFMET");
    TH1F *if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET_DATA = (TH1F*)ifileDATA->Get("CalibPseudoMET_if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET");
    TH1F *if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET_DATA = (TH1F*)ifileDATA->Get("CalibPseudoMET_if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET");            
    TH1F *if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET_DATA = (TH1F*)ifileDATA->Get("CalibPseudoMET_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET");
    TH1F *if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET_DATA = (TH1F*)ifileDATA->Get("CalibPseudoMET_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET");
    TH1F *if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET_DATA = (TH1F*)ifileDATA->Get("CalibPseudoMET_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET");
    TH1F *if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET_DATA = (TH1F*)ifileDATA->Get("CalibPseudoMET_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET");
    TH1F *if___HLT_MET105_IsoTrk50___PseudoCaloMET_DATA = (TH1F*)ifileDATA->Get("CalibPseudoMET_if___HLT_MET105_IsoTrk50___PseudoCaloMET");
    TH1F *if___HLT_MET105_IsoTrk50___RecoPFMET_DATA = (TH1F*)ifileDATA->Get("CalibPseudoMET_if___HLT_MET105_IsoTrk50___RecoPFMET");
    TH1F *if___orMETtrg___PseudoCaloMET_DATA = (TH1F*)ifileDATA->Get("CalibPseudoMET_if___orMETtrg___PseudoCaloMET");
    TH1F *if___orMETtrg___RecoPFMET_DATA = (TH1F*)ifileDATA->Get("CalibPseudoMET_if___orMETtrg___RecoPFMET");
    TH1F *if___orMETtrg___RecoPFMET__PseudoCaloMETCut_DATA = (TH1F*)ifileDATA->Get("OnlyMET_if___orMETtrg___RecoPFMET__PseudoCaloMETCut");
    

    // setup 
    if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET_MC->Sumw2();
    TH1F *eff_HLT_PFMET120_PseudoCaloMET_MC = (TH1F*)if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET_MC->Clone("eff_HLT_PFMET120_PseudoCaloMET_MC");
    if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET_MC->Sumw2();
    TH1F *eff_HLT_PFMET120_RecoPFMET_MC = (TH1F*)if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET_MC->Clone("eff_HLT_PFMET120_RecoPFMET_MC");
    if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET_MC->Sumw2();
    TH1F *eff_HLT_PFHT500_PseudoCaloMET_MC = (TH1F*)if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET_MC->Clone("eff_HLT_PFHT500_PseudoCaloMET_MC");
    if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET_MC->Sumw2();
    TH1F *eff_HLT_PFHT500_RecoPFMET_MC = (TH1F*)if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET_MC->Clone("eff_HLT_PFHT500_RecoPFMET_MC");
    if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET_MC->Sumw2();
    TH1F *eff_HLT_PFMETNoMu120_PseudoCaloMET_MC = (TH1F*)if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET_MC->Clone("eff_HLT_PFMETNoMu120_PseudoCaloMET_MC");
    if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET_MC->Sumw2();
    TH1F *eff_HLT_PFMETNoMu120_RecoPFMET_MC = (TH1F*)if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET_MC->Clone("eff_HLT_PFMETNoMu120_RecoPFMET_MC");
    if___HLT_MET105_IsoTrk50___PseudoCaloMET_MC->Sumw2();
    TH1F *eff_HLT_MET105_PseudoCaloMET_MC = (TH1F*)if___HLT_MET105_IsoTrk50___PseudoCaloMET_MC->Clone("eff_HLT_MET105_PseudoCaloMET_MC");
    if___HLT_MET105_IsoTrk50___RecoPFMET_MC->Sumw2();
    TH1F *eff_HLT_MET105_RecoPFMET_MC = (TH1F*)if___HLT_MET105_IsoTrk50___RecoPFMET_MC->Clone("eff_HLT_MET105_RecoPFMET_MC");
    if___orMETtrg___PseudoCaloMET_MC->Sumw2();
    TH1F *eff_orMETtrg_PseudoCaloMET_MC = (TH1F*)if___orMETtrg___PseudoCaloMET_MC->Clone("eff_orMETtrg_PseudoCaloMET_MC");
    if___orMETtrg___RecoPFMET_MC->Sumw2();
    TH1F *eff_orMETtrg_RecoPFMET_MC = (TH1F*)if___orMETtrg___RecoPFMET_MC->Clone("eff_orMETtrg_RecoPFMET_MC");
    if___orMETtrg___RecoPFMET__PseudoCaloMETCut_MC->Sumw2();    
    TH1F *eff_orMETtrg_RecoPFMET__PseudoCaloMETCut_MC = (TH1F*)if___orMETtrg___RecoPFMET__PseudoCaloMETCut_MC->Clone("eff_orMETtrg_RecoPFMET__PseudoCaloMETCut_MC");

    if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET_DATA->Sumw2();
    TH1F *eff_HLT_PFMET120_PseudoCaloMET_DATA = (TH1F*)if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET_DATA->Clone("eff_HLT_PFMET120_PseudoCaloMET_DATA");
    if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET_DATA->Sumw2();
    TH1F *eff_HLT_PFMET120_RecoPFMET_DATA = (TH1F*)if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET_DATA->Clone("eff_HLT_PFMET120_RecoPFMET_DATA");
    if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET_DATA->Sumw2();
    TH1F *eff_HLT_PFHT500_PseudoCaloMET_DATA = (TH1F*)if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET_DATA->Clone("eff_HLT_PFHT500_PseudoCaloMET_DATA");
    if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET_DATA->Sumw2();
    TH1F *eff_HLT_PFHT500_RecoPFMET_DATA = (TH1F*)if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET_DATA->Clone("eff_HLT_PFHT500_RecoPFMET_DATA");
    if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET_DATA->Sumw2();
    TH1F *eff_HLT_PFMETNoMu120_PseudoCaloMET_DATA = (TH1F*)if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET_DATA->Clone("eff_HLT_PFMETNoMu120_PseudoCaloMET_DATA");
    if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET_DATA->Sumw2();
    TH1F *eff_HLT_PFMETNoMu120_RecoPFMET_DATA = (TH1F*)if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET_DATA->Clone("eff_HLT_PFMETNoMu120_RecoPFMET_DATA");
    if___HLT_MET105_IsoTrk50___PseudoCaloMET_DATA->Sumw2();
    TH1F *eff_HLT_MET105_PseudoCaloMET_DATA = (TH1F*)if___HLT_MET105_IsoTrk50___PseudoCaloMET_DATA->Clone("eff_HLT_MET105_PseudoCaloMET_DATA");
    if___HLT_MET105_IsoTrk50___RecoPFMET_DATA->Sumw2();
    TH1F *eff_HLT_MET105_RecoPFMET_DATA = (TH1F*)if___HLT_MET105_IsoTrk50___RecoPFMET_DATA->Clone("eff_HLT_MET105_RecoPFMET_DATA");
    if___orMETtrg___PseudoCaloMET_DATA->Sumw2();
    TH1F *eff_orMETtrg_PseudoCaloMET_DATA = (TH1F*)if___orMETtrg___PseudoCaloMET_DATA->Clone("eff_orMETtrg_PseudoCaloMET_DATA");
    if___orMETtrg___RecoPFMET_DATA->Sumw2();
    TH1F *eff_orMETtrg_RecoPFMET_DATA = (TH1F*)if___orMETtrg___RecoPFMET_DATA->Clone("eff_orMETtrg_RecoPFMET_DATA");
    if___orMETtrg___RecoPFMET__PseudoCaloMETCut_DATA->Sumw2();    
    TH1F *eff_orMETtrg_RecoPFMET__PseudoCaloMETCut_DATA = (TH1F*)if___orMETtrg___RecoPFMET__PseudoCaloMETCut_DATA->Clone("eff_orMETtrg_RecoPFMET__PseudoCaloMETCut_DATA");

    // efficiency calculation
    eff_HLT_PFMET120_PseudoCaloMET_MC->Divide(PseudoCaloMET_MC);
    eff_HLT_PFMET120_RecoPFMET_MC->Divide(RecoPFMET_MC);
    eff_HLT_PFHT500_PseudoCaloMET_MC->Divide(PseudoCaloMET_MC);
    eff_HLT_PFHT500_RecoPFMET_MC->Divide(RecoPFMET_MC);
    eff_HLT_PFMETNoMu120_PseudoCaloMET_MC->Divide(PseudoCaloMET_MC);
    eff_HLT_PFMETNoMu120_RecoPFMET_MC->Divide(RecoPFMET_MC);
    eff_HLT_MET105_PseudoCaloMET_MC->Divide(PseudoCaloMET_MC);
    eff_HLT_MET105_RecoPFMET_MC->Divide(RecoPFMET_MC);
    eff_orMETtrg_PseudoCaloMET_MC->Divide(PseudoCaloMET_MC);
    eff_orMETtrg_RecoPFMET_MC->Divide(RecoPFMET_MC);
    eff_orMETtrg_RecoPFMET__PseudoCaloMETCut_MC->Divide(RecoPFMET__PseudoCaloMETCut_MC);

    eff_HLT_PFMET120_PseudoCaloMET_DATA->Divide(PseudoCaloMET_DATA);
    eff_HLT_PFMET120_RecoPFMET_DATA->Divide(RecoPFMET_DATA);
    eff_HLT_PFHT500_PseudoCaloMET_DATA->Divide(PseudoCaloMET_DATA);
    eff_HLT_PFHT500_RecoPFMET_DATA->Divide(RecoPFMET_DATA);
    eff_HLT_PFMETNoMu120_PseudoCaloMET_DATA->Divide(PseudoCaloMET_DATA);
    eff_HLT_PFMETNoMu120_RecoPFMET_DATA->Divide(RecoPFMET_DATA);
    eff_HLT_MET105_PseudoCaloMET_DATA->Divide(PseudoCaloMET_DATA);
    eff_HLT_MET105_RecoPFMET_DATA->Divide(RecoPFMET_DATA);
    eff_orMETtrg_PseudoCaloMET_DATA->Divide(PseudoCaloMET_DATA);
    eff_orMETtrg_RecoPFMET_DATA->Divide(RecoPFMET_DATA);
    eff_orMETtrg_RecoPFMET__PseudoCaloMETCut_DATA->Divide(RecoPFMET__PseudoCaloMETCut_DATA);


    // setting style
    eff_HLT_PFMET120_PseudoCaloMET_DATA->SetLineColor(kRed);
    eff_HLT_PFMET120_PseudoCaloMET_DATA->SetMarkerColor(kRed);
    eff_HLT_PFMET120_PseudoCaloMET_DATA->SetMarkerStyle(21);
    eff_HLT_PFMET120_PseudoCaloMET_DATA->GetXaxis()->SetTitle("PseudoCaloMET [GeV]");
    eff_HLT_PFMET120_PseudoCaloMET_DATA->GetYaxis()->SetTitle("eff. HLT_PFMET120_PFMHT120_IDTight");
    eff_HLT_PFMET120_PseudoCaloMET_DATA->GetXaxis()->SetRangeUser(0, 1500);
    eff_HLT_PFMET120_PseudoCaloMET_DATA->GetYaxis()->SetRangeUser(0, 1);

    eff_HLT_PFMET120_RecoPFMET_DATA->SetLineColor(kRed);
    eff_HLT_PFMET120_RecoPFMET_DATA->SetMarkerColor(kRed);
    eff_HLT_PFMET120_RecoPFMET_DATA->SetMarkerStyle(21);
    eff_HLT_PFMET120_RecoPFMET_DATA->GetXaxis()->SetTitle("RecoPFMET [GeV]");
    eff_HLT_PFMET120_RecoPFMET_DATA->GetYaxis()->SetTitle("eff. HLT_PFMET120_PFMHT120_IDTight");
    eff_HLT_PFMET120_RecoPFMET_DATA->GetXaxis()->SetRangeUser(0, 1500);
    eff_HLT_PFMET120_RecoPFMET_DATA->GetYaxis()->SetRangeUser(0, 1);

    eff_HLT_PFHT500_PseudoCaloMET_DATA->SetLineColor(kRed);
    eff_HLT_PFHT500_PseudoCaloMET_DATA->SetMarkerColor(kRed);
    eff_HLT_PFHT500_PseudoCaloMET_DATA->SetMarkerStyle(21);
    eff_HLT_PFHT500_PseudoCaloMET_DATA->GetXaxis()->SetTitle("PseudoCaloMET [GeV]");
    eff_HLT_PFHT500_PseudoCaloMET_DATA->GetYaxis()->SetTitle("eff. HLT_PFHT500_PFMET100_PFMHT100_IDTight");
    eff_HLT_PFHT500_PseudoCaloMET_DATA->GetXaxis()->SetRangeUser(0, 1500);
    eff_HLT_PFHT500_PseudoCaloMET_DATA->GetYaxis()->SetRangeUser(0, 1);

    eff_HLT_PFHT500_RecoPFMET_DATA->SetLineColor(kRed);
    eff_HLT_PFHT500_RecoPFMET_DATA->SetMarkerColor(kRed);
    eff_HLT_PFHT500_RecoPFMET_DATA->SetMarkerStyle(21);
    eff_HLT_PFHT500_RecoPFMET_DATA->GetXaxis()->SetTitle("RecoPFMET [GeV]");
    eff_HLT_PFHT500_RecoPFMET_DATA->GetYaxis()->SetTitle("eff. HLT_PFHT500_PFMET100_PFMHT100_IDTight");
    eff_HLT_PFHT500_RecoPFMET_DATA->GetXaxis()->SetRangeUser(0, 1500);
    eff_HLT_PFHT500_RecoPFMET_DATA->GetYaxis()->SetRangeUser(0, 1);

    eff_HLT_PFMETNoMu120_PseudoCaloMET_DATA->SetLineColor(kRed);
    eff_HLT_PFMETNoMu120_PseudoCaloMET_DATA->SetMarkerColor(kRed);
    eff_HLT_PFMETNoMu120_PseudoCaloMET_DATA->SetMarkerStyle(21);
    eff_HLT_PFMETNoMu120_PseudoCaloMET_DATA->GetXaxis()->SetTitle("PseudoCaloMET [GeV]");
    eff_HLT_PFMETNoMu120_PseudoCaloMET_DATA->GetYaxis()->SetTitle("eff. HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60");
    eff_HLT_PFMETNoMu120_PseudoCaloMET_DATA->GetXaxis()->SetRangeUser(0, 1500);
    eff_HLT_PFMETNoMu120_PseudoCaloMET_DATA->GetYaxis()->SetRangeUser(0, 1);

    eff_HLT_PFMETNoMu120_RecoPFMET_DATA->SetLineColor(kRed);
    eff_HLT_PFMETNoMu120_RecoPFMET_DATA->SetMarkerColor(kRed);
    eff_HLT_PFMETNoMu120_RecoPFMET_DATA->SetMarkerStyle(21);
    eff_HLT_PFMETNoMu120_RecoPFMET_DATA->GetXaxis()->SetTitle("RecoPFMET [GeV]");
    eff_HLT_PFMETNoMu120_RecoPFMET_DATA->GetYaxis()->SetTitle("eff. HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60");
    eff_HLT_PFMETNoMu120_RecoPFMET_DATA->GetXaxis()->SetRangeUser(0, 1500);
    eff_HLT_PFMETNoMu120_RecoPFMET_DATA->GetYaxis()->SetRangeUser(0, 1);

    eff_HLT_MET105_PseudoCaloMET_DATA->SetLineColor(kRed);
    eff_HLT_MET105_PseudoCaloMET_DATA->SetMarkerColor(kRed);
    eff_HLT_MET105_PseudoCaloMET_DATA->SetMarkerStyle(21);
    eff_HLT_MET105_PseudoCaloMET_DATA->GetXaxis()->SetTitle("PseudoCaloMET [GeV]");
    eff_HLT_MET105_PseudoCaloMET_DATA->GetYaxis()->SetTitle("eff. HLT_MET105_IsoTrk50");
    eff_HLT_MET105_PseudoCaloMET_DATA->GetXaxis()->SetRangeUser(0, 1500);
    eff_HLT_MET105_PseudoCaloMET_DATA->GetYaxis()->SetRangeUser(0, 1);

    eff_HLT_MET105_RecoPFMET_DATA->SetLineColor(kRed);
    eff_HLT_MET105_RecoPFMET_DATA->SetMarkerColor(kRed);
    eff_HLT_MET105_RecoPFMET_DATA->SetMarkerStyle(21);
    eff_HLT_MET105_RecoPFMET_DATA->GetXaxis()->SetTitle("RecoPFMET [GeV]");
    eff_HLT_MET105_RecoPFMET_DATA->GetYaxis()->SetTitle("eff. HLT_MET105_IsoTrk50");
    eff_HLT_MET105_RecoPFMET_DATA->GetXaxis()->SetRangeUser(0, 1500);
    eff_HLT_MET105_RecoPFMET_DATA->GetYaxis()->SetRangeUser(0, 1);

    eff_orMETtrg_PseudoCaloMET_DATA->SetLineColor(kRed);
    eff_orMETtrg_PseudoCaloMET_DATA->SetMarkerColor(kRed);
    eff_orMETtrg_PseudoCaloMET_DATA->SetMarkerStyle(21);
    eff_orMETtrg_PseudoCaloMET_DATA->GetXaxis()->SetTitle("PseudoCaloMET [GeV]");
    eff_orMETtrg_PseudoCaloMET_DATA->GetYaxis()->SetTitle("eff. orMETtrg");
    eff_orMETtrg_PseudoCaloMET_DATA->GetXaxis()->SetRangeUser(0, 1500);
    eff_orMETtrg_PseudoCaloMET_DATA->GetYaxis()->SetRangeUser(0, 1);

    eff_orMETtrg_RecoPFMET_DATA->SetLineColor(kRed);
    eff_orMETtrg_RecoPFMET_DATA->SetMarkerColor(kRed);
    eff_orMETtrg_RecoPFMET_DATA->SetMarkerStyle(21);
    eff_orMETtrg_RecoPFMET_DATA->GetXaxis()->SetTitle("RecoPFMET [GeV]");
    eff_orMETtrg_RecoPFMET_DATA->GetYaxis()->SetTitle("eff. orMETtrg");
    eff_orMETtrg_RecoPFMET_DATA->GetXaxis()->SetRangeUser(0, 1500);
    eff_orMETtrg_RecoPFMET_DATA->GetYaxis()->SetRangeUser(0, 1);

    eff_orMETtrg_RecoPFMET__PseudoCaloMETCut_DATA->SetLineColor(kRed);
    eff_orMETtrg_RecoPFMET__PseudoCaloMETCut_DATA->SetMarkerColor(kRed);
    eff_orMETtrg_RecoPFMET__PseudoCaloMETCut_DATA->SetMarkerStyle(21);
    eff_orMETtrg_RecoPFMET__PseudoCaloMETCut_DATA->GetXaxis()->SetTitle("RecoPFMET [GeV]");
    eff_orMETtrg_RecoPFMET__PseudoCaloMETCut_DATA->GetYaxis()->SetTitle("eff. orMETtrg w/PseudoMET>170GeV");
    eff_orMETtrg_RecoPFMET__PseudoCaloMETCut_DATA->GetXaxis()->SetRangeUser(0, 1500);
    eff_orMETtrg_RecoPFMET__PseudoCaloMETCut_DATA->GetYaxis()->SetRangeUser(0, 1);

    eff_HLT_PFMET120_PseudoCaloMET_MC->SetLineColor(kBlue);
    eff_HLT_PFMET120_PseudoCaloMET_MC->SetMarkerColor(kBlue);
    eff_HLT_PFMET120_PseudoCaloMET_MC->SetMarkerStyle(22);
    eff_HLT_PFMET120_PseudoCaloMET_MC->GetXaxis()->SetTitle("PseudoCaloMET [GeV]");
    eff_HLT_PFMET120_PseudoCaloMET_MC->GetYaxis()->SetTitle("eff. HLT_PFMET120_PFMHT120_IDTight");
    eff_HLT_PFMET120_PseudoCaloMET_MC->GetXaxis()->SetRangeUser(0, 1500);
    eff_HLT_PFMET120_PseudoCaloMET_MC->GetYaxis()->SetRangeUser(0, 1);

    eff_HLT_PFMET120_RecoPFMET_MC->SetLineColor(kBlue);
    eff_HLT_PFMET120_RecoPFMET_MC->SetMarkerColor(kBlue);
    eff_HLT_PFMET120_RecoPFMET_MC->SetMarkerStyle(22);
    eff_HLT_PFMET120_RecoPFMET_MC->GetXaxis()->SetTitle("RecoPFMET [GeV]");
    eff_HLT_PFMET120_RecoPFMET_MC->GetYaxis()->SetTitle("eff. HLT_PFMET120_PFMHT120_IDTight");
    eff_HLT_PFMET120_RecoPFMET_MC->GetXaxis()->SetRangeUser(0, 1500);
    eff_HLT_PFMET120_RecoPFMET_MC->GetYaxis()->SetRangeUser(0, 1);

    eff_HLT_PFHT500_PseudoCaloMET_MC->SetLineColor(kBlue);
    eff_HLT_PFHT500_PseudoCaloMET_MC->SetMarkerColor(kBlue);
    eff_HLT_PFHT500_PseudoCaloMET_MC->SetMarkerStyle(22);
    eff_HLT_PFHT500_PseudoCaloMET_MC->GetXaxis()->SetTitle("PseudoCaloMET [GeV]");
    eff_HLT_PFHT500_PseudoCaloMET_MC->GetYaxis()->SetTitle("eff. HLT_PFHT500_PFMET100_PFMHT100_IDTight");
    eff_HLT_PFHT500_PseudoCaloMET_MC->GetXaxis()->SetRangeUser(0, 1500);
    eff_HLT_PFHT500_PseudoCaloMET_MC->GetYaxis()->SetRangeUser(0, 1);

    eff_HLT_PFHT500_RecoPFMET_MC->SetLineColor(kBlue);
    eff_HLT_PFHT500_RecoPFMET_MC->SetMarkerColor(kBlue);
    eff_HLT_PFHT500_RecoPFMET_MC->SetMarkerStyle(22);
    eff_HLT_PFHT500_RecoPFMET_MC->GetXaxis()->SetTitle("RecoPFMET [GeV]");
    eff_HLT_PFHT500_RecoPFMET_MC->GetYaxis()->SetTitle("eff. HLT_PFHT500_PFMET100_PFMHT100_IDTight");
    eff_HLT_PFHT500_RecoPFMET_MC->GetXaxis()->SetRangeUser(0, 1500);
    eff_HLT_PFHT500_RecoPFMET_MC->GetYaxis()->SetRangeUser(0, 1);

    eff_HLT_PFMETNoMu120_PseudoCaloMET_MC->SetLineColor(kBlue);
    eff_HLT_PFMETNoMu120_PseudoCaloMET_MC->SetMarkerColor(kBlue);
    eff_HLT_PFMETNoMu120_PseudoCaloMET_MC->SetMarkerStyle(22);
    eff_HLT_PFMETNoMu120_PseudoCaloMET_MC->GetXaxis()->SetTitle("PseudoCaloMET [GeV]");
    eff_HLT_PFMETNoMu120_PseudoCaloMET_MC->GetYaxis()->SetTitle("eff. HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60");
    eff_HLT_PFMETNoMu120_PseudoCaloMET_MC->GetXaxis()->SetRangeUser(0, 1500);
    eff_HLT_PFMETNoMu120_PseudoCaloMET_MC->GetYaxis()->SetRangeUser(0, 1);

    eff_HLT_PFMETNoMu120_RecoPFMET_MC->SetLineColor(kBlue);
    eff_HLT_PFMETNoMu120_RecoPFMET_MC->SetMarkerColor(kBlue);
    eff_HLT_PFMETNoMu120_RecoPFMET_MC->SetMarkerStyle(22);
    eff_HLT_PFMETNoMu120_RecoPFMET_MC->GetXaxis()->SetTitle("RecoPFMET [GeV]");
    eff_HLT_PFMETNoMu120_RecoPFMET_MC->GetYaxis()->SetTitle("eff. HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60");
    eff_HLT_PFMETNoMu120_RecoPFMET_MC->GetXaxis()->SetRangeUser(0, 1500);
    eff_HLT_PFMETNoMu120_RecoPFMET_MC->GetYaxis()->SetRangeUser(0, 1);

    eff_HLT_MET105_PseudoCaloMET_MC->SetLineColor(kBlue);
    eff_HLT_MET105_PseudoCaloMET_MC->SetMarkerColor(kBlue);
    eff_HLT_MET105_PseudoCaloMET_MC->SetMarkerStyle(22);
    eff_HLT_MET105_PseudoCaloMET_MC->GetXaxis()->SetTitle("PseudoCaloMET [GeV]");
    eff_HLT_MET105_PseudoCaloMET_MC->GetYaxis()->SetTitle("eff. HLT_MET105_IsoTrk50");
    eff_HLT_MET105_PseudoCaloMET_MC->GetXaxis()->SetRangeUser(0, 1500);
    eff_HLT_MET105_PseudoCaloMET_MC->GetYaxis()->SetRangeUser(0, 1);

    eff_HLT_MET105_RecoPFMET_MC->SetLineColor(kBlue);
    eff_HLT_MET105_RecoPFMET_MC->SetMarkerColor(kBlue);
    eff_HLT_MET105_RecoPFMET_MC->SetMarkerStyle(22);
    eff_HLT_MET105_RecoPFMET_MC->GetXaxis()->SetTitle("RecoPFMET [GeV]");
    eff_HLT_MET105_RecoPFMET_MC->GetYaxis()->SetTitle("eff. HLT_MET105_IsoTrk50");
    eff_HLT_MET105_RecoPFMET_MC->GetXaxis()->SetRangeUser(0, 1500);
    eff_HLT_MET105_RecoPFMET_MC->GetYaxis()->SetRangeUser(0, 1);

    eff_orMETtrg_PseudoCaloMET_MC->SetLineColor(kBlue);
    eff_orMETtrg_PseudoCaloMET_MC->SetMarkerColor(kBlue);
    eff_orMETtrg_PseudoCaloMET_MC->SetMarkerStyle(22);
    eff_orMETtrg_PseudoCaloMET_MC->GetXaxis()->SetTitle("PseudoCaloMET [GeV]");
    eff_orMETtrg_PseudoCaloMET_MC->GetYaxis()->SetTitle("eff. orMETtrg");
    eff_orMETtrg_PseudoCaloMET_MC->GetXaxis()->SetRangeUser(0, 1500);
    eff_orMETtrg_PseudoCaloMET_MC->GetYaxis()->SetRangeUser(0, 1);

    eff_orMETtrg_RecoPFMET_MC->SetLineColor(kBlue);
    eff_orMETtrg_RecoPFMET_MC->SetMarkerColor(kBlue);
    eff_orMETtrg_RecoPFMET_MC->SetMarkerStyle(22);
    eff_orMETtrg_RecoPFMET_MC->GetXaxis()->SetTitle("RecoPFMET [GeV]");
    eff_orMETtrg_RecoPFMET_MC->GetYaxis()->SetTitle("eff. orMETtrg");
    eff_orMETtrg_RecoPFMET_MC->GetXaxis()->SetRangeUser(0, 1500);
    eff_orMETtrg_RecoPFMET_MC->GetYaxis()->SetRangeUser(0, 1);

    eff_orMETtrg_RecoPFMET__PseudoCaloMETCut_MC->SetLineColor(kBlue);
    eff_orMETtrg_RecoPFMET__PseudoCaloMETCut_MC->SetMarkerColor(kBlue);
    eff_orMETtrg_RecoPFMET__PseudoCaloMETCut_MC->SetMarkerStyle(22);
    eff_orMETtrg_RecoPFMET__PseudoCaloMETCut_MC->GetXaxis()->SetTitle("RecoPFMET [GeV]");
    eff_orMETtrg_RecoPFMET__PseudoCaloMETCut_MC->GetYaxis()->SetTitle("eff. orMETtrg w/PseudoMET>170GeV");
    eff_orMETtrg_RecoPFMET__PseudoCaloMETCut_MC->GetXaxis()->SetRangeUser(0, 1500);
    eff_orMETtrg_RecoPFMET__PseudoCaloMETCut_MC->GetYaxis()->SetRangeUser(0, 1);

    // legend
    Tlegend *leg = new TLegend(0.75,0.75,0.85,0.85);
    leg->AddEntry(eff_HLT_PFMET120_PseudoCaloMET_DATA,"DATA","lep");
    leg->AddEntry(eff_HLT_PFMET120_PseudoCaloMET_MC,"MC","lep");
    leg->SetBorderSize(0);
    leg->SetFillStyle(0);


    // drawing
    TCanvas *c_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET = new TCanvas("c_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET","c_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET",800,800);
    c_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET->cd();
    eff_HLT_PFMET120_PseudoCaloMET_DATA->Draw("E1");
    eff_HLT_PFMET120_PseudoCaloMET_MC->Draw("E1 same");
    leg->Draw("same");
    
    TCanvas *c_HLT_PFMET120_PFMHT120_IDTight___RecoPFMET = new TCanvas("c_HLT_PFMET120_PFMHT120_IDTight___RecoPFMET","c_HLT_PFMET120_PFMHT120_IDTight___RecoPFMET",800,800);
    c_HLT_PFMET120_PFMHT120_IDTight___RecoPFMET->cd();
    eff_HLT_PFMET120_RecoPFMET_DATA->Draw("E1");
    eff_HLT_PFMET120_RecoPFMET_MC->Draw("E1 same");
    leg->Draw("same");

    TCanvas *c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET = new TCanvas("c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET","c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET",800,800);
    c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET->cd();
    eff_HLT_PFHT500_PseudoCaloMET_DATA->Draw("E1");
    eff_HLT_PFHT500_PseudoCaloMET_MC->Draw("E1 same");
    leg->Draw("same");

    TCanvas *c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET = new TCanvas("c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET","c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET",800,800);
    c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET->cd();
    eff_HLT_PFHT500_RecoPFMET_DATA->Draw("E1");
    eff_HLT_PFHT500_RecoPFMET_MC->Draw("E1 same");
    leg->Draw("same");

    TCanvas *c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET = new TCanvas("c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET","c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET",800,800);
    c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET->cd();
    eff_HLT_PFMETNoMu120_PseudoCaloMET_DATA->Draw("E1");
    eff_HLT_PFMETNoMu120_PseudoCaloMET_MC->Draw("E1 same");
    leg->Draw("same");

    TCanvas *c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET = new TCanvas("c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET","c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET",800,800);
    c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET->cd();
    eff_HLT_PFMETNoMu120_RecoPFMET_DATA->Draw("E1");
    eff_HLT_PFMETNoMu120_RecoPFMET_MC->Draw("E1 same");
    leg->Draw("same");

    TCanvas *c_HLT_MET105_IsoTrk50___PseudoCaloMET = new TCanvas("c_HLT_MET105_IsoTrk50___PseudoCaloMET","c_HLT_MET105_IsoTrk50___PseudoCaloMET",800,800);
    c_HLT_MET105_IsoTrk50___PseudoCaloMET->cd();
    eff_HLT_MET105_PseudoCaloMET_DATA->Draw("E1");
    eff_HLT_MET105_PseudoCaloMET_MC->Draw("E1 same");
    leg->Draw("same");

    TCanvas *c_HLT_MET105_IsoTrk50___RecoPFMET = new TCanvas("c_HLT_MET105_IsoTrk50___RecoPFMET","c_HLT_MET105_IsoTrk50___RecoPFMET",800,800);
    c_HLT_MET105_IsoTrk50___RecoPFMET->cd();
    eff_HLT_MET105_RecoPFMET_DATA->Draw("E1");
    eff_HLT_MET105_RecoPFMET_MC->Draw("E1 same");
    leg->Draw("same");

    TCanvas *c_orMETtrg___PseudoCaloMET = new TCanvas("c_orMETtrg___PseudoCaloMET","c_orMETtrg___PseudoCaloMET",800,800);
    c_orMETtrg___PseudoCaloMET->cd();
    eff_orMETtrg_PseudoCaloMET_DATA->Draw("E1");
    eff_orMETtrg_PseudoCaloMET_MC->Draw("E1 same");
    leg->Draw("same");

    TCanvas *c_orMETtrg___RecoPFMET = new TCanvas("c_orMETtrg___RecoPFMET","c_orMETtrg___RecoPFMET",800,800);
    c_orMETtrg___RecoPFMET->cd();
    eff_orMETtrg_RecoPFMET_DATA->Draw("E1");
    eff_orMETtrg_RecoPFMET_MC->Draw("E1 same");
    leg->Draw("same");

    TCanvas *c_orMETtrg___RecoPFMET__PseudoCaloMETCut = new TCanvas("c_orMETtrg___RecoPFMET__PseudoCaloMETCut","c_orMETtrg___RecoPFMET__PseudoCaloMETCut",800,800);
    c_orMETtrg___RecoPFMET__PseudoCaloMETCut->cd();
    eff_orMETtrg_RecoPFMET__PseudoCaloMETCut_DATA->Draw("E1");
    eff_orMETtrg_RecoPFMET__PseudoCaloMETCut_MC->Draw("E1 same");
    leg->Draw("same");
        
    // saving
    ofile->cd();
    c_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET->Write();
    c_HLT_PFMET120_PFMHT120_IDTight___RecoPFMET->Write();
    c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET->Write();
    c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET->Write();
    c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET->Write();
    c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET->Write();
    c_HLT_MET105_IsoTrk50___PseudoCaloMET->Write();
    c_HLT_MET105_IsoTrk50___RecoPFMET->Write();
    c_orMETtrg___PseudoCaloMET->Write();
    c_orMETtrg___RecoPFMET->Write();
    c_orMETtrg___RecoPFMET__PseudoCaloMETCut->Write();
    ofile->Close();


    return;
}

void Comp_ttbar_muonEG(const char *inputfileDATA, const char *inputfileMC) {

    TFile *ofile = new TFile("PlayWithHistos/Comp_ttbar_muonEG.root", "RECREATE");

    TFile *ifileDATA = new TFile(Form("%s", inputfileDATA), "READ");
    TFile *ifileMC = new TFile(Form("%s", inputfileMC), "READ");

    // histograms
    TH1F *electron_pt_DATA = (TH1F*)ifileDATA->Get("CalibPseudoMET_electron_pt");
    TH1F *electron_eta_DATA = (TH1F*)ifileDATA->Get("CalibPseudoMET_electron_eta");
    TH1F *electron_phi_DATA = (TH1F*)ifileDATA->Get("CalibPseudoMET_electron_phi");
    TH1F *electron_pt_MC = (TH1F*)ifileMC->Get("CalibPseudoMET_electron_pt");
    TH1F *electron_eta_MC = (TH1F*)ifileMC->Get("CalibPseudoMET_electron_eta");
    TH1F *electron_phi_MC = (TH1F*)ifileMC->Get("CalibPseudoMET_electron_phi");

    TH1F *muon_pt_DATA = (TH1F*)ifileDATA->Get("CalibPseudoMET_muon_pt");
    TH1F *muon_eta_DATA = (TH1F*)ifileDATA->Get("CalibPseudoMET_muon_eta");
    TH1F *muon_phi_DATA = (TH1F*)ifileDATA->Get("CalibPseudoMET_muon_phi");
    TH1F *muon_pt_MC = (TH1F*)ifileMC->Get("CalibPseudoMET_muon_pt");
    TH1F *muon_eta_MC = (TH1F*)ifileMC->Get("CalibPseudoMET_muon_eta");
    TH1F *muon_phi_MC = (TH1F*)ifileMC->Get("CalibPseudoMET_muon_phi");

    // setup
    electron_pt_DATA->SetLineColor(kBlack);
    electron_pt_DATA->SetMarkerColor(kBlack);
    electron_eta_DATA->SetLineColor(kBlack);
    electron_eta_DATA->SetMarkerColor(kBlack);
    electron_phi_DATA->SetLineColor(kBlack);
    electron_phi_DATA->SetMarkerColor(kBlack);

    muon_pt_DATA->SetLineColor(kBlack);
    muon_pt_DATA->SetMarkerColor(kBlack);
    muon_eta_DATA->SetLineColor(kBlack);
    muon_eta_DATA->SetMarkerColor(kBlack);
    muon_phi_DATA->SetLineColor(kBlack);
    muon_phi_DATA->SetMarkerColor(kBlack);

    electron_pt_MC->SetLineColor(kAzure+7);
    electron_pt_MC->SetFillColor(kAzure+7);
    electron_pt_MC->SetFillStyle(4050);
    electron_eta_MC->SetLineColor(kAzure+7);
    electron_eta_MC->SetFillColor(kAzure+7);
    electron_eta_MC->SetFillStyle(4050);
    electron_phi_MC->SetLineColor(kAzure+7);
    electron_phi_MC->SetFillColor(kAzure+7);
    electron_phi_MC->SetFillStyle(4050);

    muon_pt_MC->SetLineColor(kAzure+7);
    muon_pt_MC->SetFillColor(kAzure+7);
    muon_pt_MC->SetFillStyle(4050);
    muon_eta_MC->SetLineColor(kAzure+7);
    muon_eta_MC->SetFillColor(kAzure+7);
    muon_eta_MC->SetFillStyle(4050);
    muon_phi_MC->SetLineColor(kAzure+7);
    muon_phi_MC->SetFillColor(kAzure+7);
    muon_phi_MC->SetFillStyle(4050);

    // scale
    electron_pt_DATA->Scale(1./electron_pt_DATA->Integral());
    electron_eta_DATA->Scale(1./electron_eta_DATA->Integral());
    electron_phi_DATA->Scale(1./electron_phi_DATA->Integral());
    muon_pt_DATA->Scale(1./muon_pt_DATA->Integral());
    muon_eta_DATA->Scale(1./muon_eta_DATA->Integral());
    muon_phi_DATA->Scale(1./muon_phi_DATA->Integral());
    electron_pt_MC->Scale(1./electron_pt_MC->Integral());
    electron_eta_MC->Scale(1./electron_eta_MC->Integral());
    electron_phi_MC->Scale(1./electron_phi_MC->Integral());
    muon_pt_MC->Scale(1./muon_pt_MC->Integral());
    muon_eta_MC->Scale(1./muon_eta_MC->Integral());
    muon_phi_MC->Scale(1./muon_phi_MC->Integral());

    // leg
    TLegend *leg = new TLegend(0.65,0.75,0.85,0.85);
    leg->AddEntry(electron_pt_DATA, "DATA", "lep");
    leg->AddEntry(electron_pt_MC, "MC", "f");
    leg->SetBorderSize(0);
    leg->SetFillStyle(0);

    // canvas 
    TCanvas *c_electron_pt = new TCanvas("c_electron_pt", "c_electron_pt", 800, 800);
    c_electron_pt->cd();
    electron_pt_DATA->Draw("E1");
    electron_pt_MC->Draw("HIST same");
    leg->Draw("same");

    TCanvas *c_electron_eta = new TCanvas("c_electron_eta", "c_electron_eta", 800, 800);
    c_electron_eta->cd();
    electron_eta_DATA->Draw("E1");
    electron_eta_MC->Draw("HIST same");
    leg->Draw("same");

    TCanvas *c_electron_phi = new TCanvas("c_electron_phi", "c_electron_phi", 800, 800);
    c_electron_phi->cd();
    electron_phi_DATA->Draw("E1");
    electron_phi_MC->Draw("HIST same");
    leg->Draw("same");

    TCanvas *c_muon_pt = new TCanvas("c_muon_pt", "c_muon_pt", 800, 800);
    c_muon_pt->cd();
    muon_pt_DATA->Draw("E1");
    muon_pt_MC->Draw("HIST same");
    leg->Draw("same");

    TCanvas *c_muon_eta = new TCanvas("c_muon_eta", "c_muon_eta", 800, 800);
    c_muon_eta->cd();
    muon_eta_DATA->Draw("E1");
    muon_eta_MC->Draw("HIST same");
    leg->Draw("same");

    TCanvas *c_muon_phi = new TCanvas("c_muon_phi", "c_muon_phi", 800, 800);
    c_muon_phi->cd();
    muon_phi_DATA->Draw("E1");
    muon_phi_MC->Draw("HIST same");
    leg->Draw("same");


    //draw with ratio
    TCanvas *c_RATIO_electron_pt = DrawWithRatio(electron_pt_DATA, electron_pt_MC, c_electron_pt, "Electron p_{T}", "DATA/MC", "E1 same", false);
    TCanvas *c_RATIO_electron_eta = DrawWithRatio(electron_eta_DATA, electron_eta_MC, c_electron_eta, "Electron #eta", "DATA/MC", "E1 same", false);
    TCanvas *c_RATIO_electron_phi = DrawWithRatio(electron_phi_DATA, electron_phi_MC, c_electron_phi, "Electron #phi", "DATA/MC", "E1 same", false);

    TCanvas *c_RATIO_muon_pt = DrawWithRatio(muon_pt_DATA, muon_pt_MC, c_muon_pt, "Muon p_{T}", "DATA/MC", "E1 same", false);
    TCanvas *c_RATIO_muon_eta = DrawWithRatio(muon_eta_DATA, muon_eta_MC, c_muon_eta, "Muon #eta", "DATA/MC", "E1 same", false);
    TCanvas *c_RATIO_muon_phi = DrawWithRatio(muon_phi_DATA, muon_phi_MC, c_muon_phi, "Muon #phi", "DATA/MC", "E1 same", false);



    // saving
    ofile->cd();
    c_RATIO_electron_pt->Write();
    c_RATIO_electron_eta->Write();
    c_RATIO_electron_phi->Write();

    c_RATIO_muon_pt->Write();
    c_RATIO_muon_eta->Write();
    c_RATIO_muon_phi->Write();
    ofile->close();

    return;
}



void CombineHistos()
{
    //MET_trg_eff("../output/Gluino2000_Run2_METtrgEff_V11p15_Eta2p4.root", false);
    //MET_trg_eff("../output/Gluino2000_Run2_METtrgEff_AOD_V11p15_Eta2p4.root", true);
    //PFMET_Cut(false);
    //TrigEff_AODvsMiniAOD();

    //Cutflows("../output/Gluino2000_AOD_FULL_Mu50_V11p11_Eta2p4.root", "../output/Gluino2000_miniAOD_FULL_Mu50_V11p11_Eta2p4.root", true, false);
    //Cutflows("../output/Gluino2000_AOD_FULL_Mu50_V11p11_Eta2p4.root", "../output/Gluino2000_miniAOD_FULL_Mu50_V11p11_Eta2p4.root", true, true);
    
    //Cutflows("../output/Gluino2000_Run2_METtrgEff_AOD_V11p15_Eta2p4.root", "../output/Gluino2000_Run2_METtrgEff_V11p15_Eta2p4.root", false, false);
    //Cutflows("../output/Gluino2000_Run2_METtrgEff_AOD_V11p15_Eta2p4.root", "../output/Gluino2000_Run2_METtrgEff_V11p15_Eta2p4.root", false, true);

    //Cutflows("../output/Gluino2000_Run2_MET_AOD_V11p16_Eta2p4.root", "../output/Gluino2000_Run2_MET_V11p16_Eta2p4.root", false, false, "_PseudoMETon");
    //Cutflows("../output/Gluino2000_Run2_MET_AOD_V11p16_Eta2p4.root", "../output/Gluino2000_Run2_MET_V11p16_Eta2p4.root", false, true, "_PseudoMETon");

    //MET_trg_eff("../output/MuonEG_V17/MuonEG2024_V17p0_Eta2p4.root", "../output/TTbar2024_V15/TTbar2024_V15p2_Eta2p4.root")
    Comp_ttbar_muonEG("../output/MuonEG_V17/MuonEG2024_V17p0_Eta2p4.root", "../output/TTbar2024_V15/TTbar2024_V15p2_Eta2p4.root")

    return;
}