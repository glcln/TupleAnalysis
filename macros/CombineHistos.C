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

TH2F* TransposeTH2(const TH2F* h_in)
{
    int nx = h_in->GetNbinsX();
    int ny = h_in->GetNbinsY();

    const TAxis* ax = h_in->GetXaxis();
    const TAxis* ay = h_in->GetYaxis();

    std::vector<double> new_xbins, new_ybins;

    for (int j = 1; j <= ny+1; ++j) new_xbins.push_back(ay->GetBinLowEdge(j));
    for (int i = 1; i <= nx+1; ++i) new_ybins.push_back(ax->GetBinLowEdge(i));

    TH2F* h_out = new TH2F(
        Form("%s_transposed", h_in->GetName()),
        Form("%s transposed", h_in->GetTitle()),
        ny, new_xbins.data(),
        nx, new_ybins.data()
    );

    for (int ix = 1; ix <= nx; ++ix) {
        for (int iy = 1; iy <= ny; ++iy) {
            double content = h_in->GetBinContent(ix, iy);
            double error = h_in->GetBinError(ix, iy);
            h_out->SetBinContent(iy, ix, content);  // swap X <-> Y
            h_out->SetBinError(iy, ix, error);
        }
    }

    return h_out;
}


double GetMinNonZero(const TH1* h) {
    double min = std::numeric_limits<double>::max();

    for (int i = 1; i <= h->GetNbinsX(); ++i) {
        double c = h->GetBinContent(i);
        if (c > 0 && c < min) min = c;
    }

    if (min == std::numeric_limits<double>::max()) return 0.;

    return min;
}

TCanvas* DrawWithRatio(TH1* h1,
                       TH1* h2,
                       TCanvas* c1,
                       std::string CanvasTitle,
                       std::string RatioTitle,  // h1/h2
                       std::string XaxisTitle,
                       float Xmin,
                       float Xmax) {
    TCanvas* c_new = new TCanvas(CanvasTitle.c_str(), CanvasTitle.c_str(), 800, 800);

    // Define pads
    TPad* pad1 = new TPad("pad1", "pad1", 0.0, 0.3, 1.0, 1.0);
    pad1->SetBottomMargin(0.03);
    pad1->Draw();

    TPad* pad2 = new TPad("pad2", "pad2", 0.0, 0.0, 1.0, 0.3);
    pad2->SetTopMargin(0.02);
    pad2->SetBottomMargin(0.3);
    pad2->Draw();

    // Draw upper plot: draw h1 then h2 (use OptionDraw for h1, and "E1 same" for h2)
    pad1->cd();
    c1->DrawClonePad();

    // Draw ratio
    TH1F *h1c = (TH1F*)h1->Clone(TString(h1->GetName()) + "_" + CanvasTitle.c_str() + "_h1");
    TH1F *h2c = (TH1F*)h2->Clone(TString(h2->GetName()) + "_" + CanvasTitle.c_str() + "_h2");
    pad2->cd();
    TH1* h_ratio = (TH1*)h1c->Clone(TString("h_ratio_") + CanvasTitle.c_str());
    h_ratio->Divide(h2c);

    h_ratio->SetTitle("");
    h_ratio->GetYaxis()->SetTitle(RatioTitle.c_str());
    h_ratio->GetXaxis()->SetTitle(XaxisTitle.c_str());
    h_ratio->GetYaxis()->SetRangeUser(0, 2);
    h_ratio->SetMarkerStyle(8);
    h_ratio->GetYaxis()->SetNdivisions(505);
    h_ratio->GetYaxis()->SetTitleSize(0.08);
    h_ratio->GetYaxis()->SetTitleOffset(0.3);
    h_ratio->GetXaxis()->SetTitleSize(0.08);
    h_ratio->GetXaxis()->SetTitleOffset(1);
    h_ratio->GetYaxis()->SetLabelSize(0.06);
    h_ratio->GetXaxis()->SetLabelSize(0.06);
    h_ratio->SetLineColor(kBlack);
    h_ratio->SetMarkerColor(kBlack);
    gPad->SetTickx(0);
    h_ratio->LabelsOption("v", "X");
    h_ratio->Draw("E0");
    h_ratio->GetXaxis()->SetRangeUser(Xmin, Xmax);

    TLine* line = new TLine(Xmin, 1, Xmax, 1);
    line->SetLineColor(kBlack);
    line->SetLineStyle(2);
    line->Draw("same");

    c_new->Update();
    cout << "Canvas " << CanvasTitle << " drawn with ratio of h1: " << h1->GetName() << " to h2: " << h2->GetName() << endl;
    return c_new;
}


TCanvas *DrawCanvas(TH1* h,
                    std::string CanvasTitle,
                    std::string XaxisTitle,
                    std::string YaxisTitle,
                    std::string OptionDraw,
                    float Xmin,
                    float Xmax, 
                    float Ymin = 0, 
                    float Ymax = -1, 
                    bool isLOGy = false) {

    TCanvas* c_new = new TCanvas(CanvasTitle.c_str(), CanvasTitle.c_str(), 800, 600);
    

    TH1* hc = (TH1*)h->Clone(TString(h->GetName()) + "_" + CanvasTitle.c_str());
    hc->SetTitle(CanvasTitle.c_str());
    hc->GetXaxis()->SetTitle(XaxisTitle.c_str());
    hc->GetYaxis()->SetTitle(YaxisTitle.c_str());
    hc->SetLineColor(kBlack);
    hc->SetMarkerColor(kBlack);
    hc->Draw(OptionDraw.c_str());
    hc->GetXaxis()->SetRangeUser(Xmin, Xmax);
    if (Ymax == -1) Ymax = 1.2*hc->GetMaximum();
    if (isLOGy) Ymin = hc->GetMinimum()*0.8;
    hc->GetYaxis()->SetRangeUser(Ymin, Ymax);
    if (isLOGy) c_new->SetLogy();

    c_new->Update();
    cout << "Canvas " << CanvasTitle << " drawn with h: " << h->GetName() << endl;
    return c_new;
}

TCanvas *DrawCanvas(TH1* h1,
                    TH1* h2,
                    std::string CanvasTitle,
                    std::string XaxisTitle,
                    std::string YaxisTitle,
                    std::string OptionDraw_h1,
                    std::string OptionDraw_h2,
                    bool isLegend,
                    std::string legtitle_h1,
                    std::string legtitle_h2,
                    std::string legdraw_h1,
                    std::string legdraw_h2,
                    float Xmin,
                    float Xmax, 
                    float Ymin = 0, 
                    float Ymax = -1, 
                    bool isLOGy = false,
                    bool isMCfill_h2 = false) {

    TCanvas* c_new = new TCanvas(CanvasTitle.c_str(), CanvasTitle.c_str(), 800, 600);

    TH1* h1c = (TH1*)h1->Clone(TString(h1->GetName()) + "_" + CanvasTitle.c_str());
    TH1* h2c = (TH1*)h2->Clone(TString(h2->GetName()) + "_" + CanvasTitle.c_str());

    h1c->SetTitle(CanvasTitle.c_str());
    h1c->GetXaxis()->SetTitle(XaxisTitle.c_str());
    h1c->GetYaxis()->SetTitle(YaxisTitle.c_str());

    h1c->SetLineColor(kRed);
    h1c->SetMarkerColor(kRed);
    h2c->SetLineColor(kBlue);
    h2c->SetMarkerColor(kBlue);

    if (isMCfill_h2) {
        h1c->SetLineColor(kBlack);
        h1c->SetMarkerColor(kBlack);
        h1c->SetMarkerStyle(20);
        h2c->SetLineColor(kBlue-7);
        h2c->SetMarkerColor(kBlue-7);
        h2c->SetFillStyle(1001);
        h2c->SetFillColor(kBlue-7);
    }

    if (isMCfill_h2) {
        h1c->Draw(OptionDraw_h1.c_str());
        std::string OptionDraw_h1_filled = OptionDraw_h1 + " same";
        h2c->Draw(OptionDraw_h2.c_str());
        h1c->Draw(OptionDraw_h1_filled.c_str());
    }
    else {
        h1c->Draw(OptionDraw_h1.c_str());
        h2c->Draw(OptionDraw_h2.c_str());
    }

    h1c->GetXaxis()->SetRangeUser(Xmin, Xmax);
    if (Ymax == -1) Ymax = 1.2*std::max(h1->GetMaximum(), h2->GetMaximum());
    if (isLOGy) Ymin = 0.8*std::min(GetMinNonZero(h1c), GetMinNonZero(h2c));
    h1c->GetYaxis()->SetRangeUser(Ymin, Ymax);

    TLegend* leg = new TLegend(0.7, 0.7, 0.9, 0.9);
    leg->AddEntry(h1c, legtitle_h1.c_str(), legdraw_h1.c_str());
    leg->AddEntry(h2c, legtitle_h2.c_str(), legdraw_h2.c_str());
    leg->SetBorderSize(0);
    leg->SetFillStyle(0);
    if (isLegend) leg->Draw();

    if (isLOGy) c_new->SetLogy();

    c_new->Update();
    cout << "Canvas " << CanvasTitle << " drawn with h1: " << h1->GetName() << " and h2: " << h2->GetName() << endl;
    return c_new;
}

TCanvas *DrawCanvas(TH1* h1,
                    TH1* h2,
                    TH1* h3,
                    std::string CanvasTitle,
                    std::string XaxisTitle,
                    std::string YaxisTitle,
                    std::string OptionDraw_h1,
                    std::string OptionDraw_h2,
                    std::string OptionDraw_h3,
                    bool isLegend,
                    std::string legtitle_h1,
                    std::string legtitle_h2,
                    std::string legtitle_h3,
                    std::string legdraw_h1,
                    std::string legdraw_h2,
                    std::string legdraw_h3,
                    float Xmin,
                    float Xmax, 
                    float Ymin = 0, 
                    float Ymax = -1, 
                    bool isLOGy = false,
                    bool isMCfill_h2 = false) {

    TCanvas* c_new = new TCanvas(CanvasTitle.c_str(), CanvasTitle.c_str(), 800, 600);

    TH1* h1c = (TH1*)h1->Clone(TString(h1->GetName()) + "_" + CanvasTitle.c_str());
    TH1* h2c = (TH1*)h2->Clone(TString(h2->GetName()) + "_" + CanvasTitle.c_str());
    TH1* h3c = (TH1*)h3->Clone(TString(h3->GetName()) + "_" + CanvasTitle.c_str());

    h1c->SetTitle(CanvasTitle.c_str());
    h1c->GetXaxis()->SetTitle(XaxisTitle.c_str());
    h1c->GetYaxis()->SetTitle(YaxisTitle.c_str());

    h1c->SetLineColor(kRed);
    h1c->SetMarkerColor(kRed);
    h2c->SetLineColor(kBlue);
    h2c->SetMarkerColor(kBlue);
    h3c->SetLineColor(kGreen+2);
    h3c->SetMarkerColor(kGreen+2);
        
    if (isMCfill_h2) {
        h1c->SetLineColor(kBlack);
        h1c->SetMarkerColor(kBlack);
        h1c->SetMarkerStyle(20);
        h2c->SetLineColor(kBlue-7);
        h2c->SetMarkerColor(kBlue-7);
        h2c->SetFillStyle(1001);
        h2c->SetFillColor(kBlue-7);
        h3c->SetLineColor(kRed);
        h3c->SetMarkerColor(kRed);
    }

    if (isMCfill_h2) {
        h1c->Draw(OptionDraw_h1.c_str());
        std::string OptionDraw_h1_filled = OptionDraw_h1 + " same";
        h2c->Draw(OptionDraw_h2.c_str());
        h1c->Draw(OptionDraw_h1_filled.c_str());
        h3c->Draw(OptionDraw_h3.c_str());
    }
    else {
        h1c->Draw(OptionDraw_h1.c_str());
        h2c->Draw(OptionDraw_h2.c_str());
        h3c->Draw(OptionDraw_h3.c_str());
    }

    h1c->GetXaxis()->SetRangeUser(Xmin, Xmax);
    if (Ymax == -1) Ymax = 1.2*std::max(h1->GetMaximum(), h2->GetMaximum());
    if (isLOGy) Ymin = 0.8*std::min(GetMinNonZero(h1c), GetMinNonZero(h2c));
    h1c->GetYaxis()->SetRangeUser(Ymin, Ymax);

    TLegend* leg = new TLegend(0.7, 0.7, 0.9, 0.9);
    leg->AddEntry(h1c, legtitle_h1.c_str(), legdraw_h1.c_str());
    leg->AddEntry(h2c, legtitle_h2.c_str(), legdraw_h2.c_str());
    leg->AddEntry(h3c, legtitle_h3.c_str(), legdraw_h3.c_str());
    leg->SetBorderSize(0);
    leg->SetFillStyle(0);
    if (isLegend) leg->Draw();

    if (isLOGy) c_new->SetLogy();

    c_new->Update();
    cout << "Canvas " << CanvasTitle << " drawn with h1: " << h1->GetName() << " and h2: " << h2->GetName() << " and h3: " << h3->GetName() << endl;
    return c_new;
}


// main
void MET_trg_eff(const char* label, const char *ifileName, bool isAOD = false) {

    TFile *ofile;
    if (isAOD) ofile = new TFile("PlayWithHistos/MET_trg_eff_AOD.root", "RECREATE");
    else ofile = new TFile("PlayWithHistos/MET_trg_eff_miniAOD.root", "RECREATE");

    TFile *ifile = new TFile(Form("%s", ifileName), "READ");

    // input histos
    TH1F *PseudoCaloMET = (TH1F*)ifile->Get(Form("%s_PseudoCaloMET", label));
    TH1F *if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET = (TH1F*)ifile->Get(Form("%s_if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET", label));
    TH1F *if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET = (TH1F*)ifile->Get(Form("%s_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET", label));
    TH1F *if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET = (TH1F*)ifile->Get(Form("%s_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET", label));
    TH1F *if___HLT_MET105_IsoTrk50___PseudoCaloMET = (TH1F*)ifile->Get(Form("%s_if___HLT_MET105_IsoTrk50___PseudoCaloMET", label));
    TH1F *if___orMETtrg___PseudoCaloMET = (TH1F*)ifile->Get(Form("%s_if___orMETtrg___PseudoCaloMET", label));

    TH1F *RecoPFMET = (TH1F*)ifile->Get(Form("%s_RecoPFMET", label));
    TH1F *if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET = (TH1F*)ifile->Get(Form("%s_if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET", label));            
    TH1F *if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET = (TH1F*)ifile->Get(Form("%s_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET", label));
    TH1F *if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET = (TH1F*)ifile->Get(Form("%s_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET", label));
    TH1F *if___HLT_MET105_IsoTrk50___RecoPFMET = (TH1F*)ifile->Get(Form("%s_if___HLT_MET105_IsoTrk50___RecoPFMET", label));
    TH1F *if___orMETtrg___RecoPFMET = (TH1F*)ifile->Get(Form("%s_if___orMETtrg___RecoPFMET", label));
    
    TH1F *PseudoCaloMET__RecoPFMETCut = (TH1F*)ifile->Get(Form("%s_PseudoCaloMET__RecoPFMETCut", label));
    TH1F *if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET__RecoPFMETCut = (TH1F*)ifile->Get(Form("%s_if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET__RecoPFMETCut", label));       
    TH1F *if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET__RecoPFMETCut = (TH1F*)ifile->Get(Form("%s_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET__RecoPFMETCut", label));
    TH1F *if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET__RecoPFMETCut = (TH1F*)ifile->Get(Form("%s_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET__RecoPFMETCut", label));
    TH1F *if___HLT_MET105_IsoTrk50___PseudoCaloMET__RecoPFMETCut = (TH1F*)ifile->Get(Form("%s_if___HLT_MET105_IsoTrk50___PseudoCaloMET__RecoPFMETCut", label));
    TH1F *if___orMETtrg___PseudoCaloMET__RecoPFMETCut = (TH1F*)ifile->Get(Form("%s_if___orMETtrg___PseudoCaloMET__RecoPFMETCut", label));
    
    TH1F *RecoPFMET__PseudoCaloMETCut = (TH1F*)ifile->Get(Form("%s_RecoPFMET__PseudoCaloMETCut", label));
    TH1F *if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET__PseudoCaloMETCut = (TH1F*)ifile->Get(Form("%s_if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET__PseudoCaloMETCut", label));      
    TH1F *if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET__PseudoCaloMETCut = (TH1F*)ifile->Get(Form("%s_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET__PseudoCaloMETCut", label));
    TH1F *if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET__PseudoCaloMETCut = (TH1F*)ifile->Get(Form("%s_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET__PseudoCaloMETCut", label));
    TH1F *if___HLT_MET105_IsoTrk50___RecoPFMET__PseudoCaloMETCut = (TH1F*)ifile->Get(Form("%s_if___HLT_MET105_IsoTrk50___RecoPFMET__PseudoCaloMETCut", label));
    TH1F *if___orMETtrg___RecoPFMET__PseudoCaloMETCut = (TH1F*)ifile->Get(Form("%s_if___orMETtrg___RecoPFMET__PseudoCaloMETCut", label));
        
    TH1F *L1MET = (TH1F*)ifile->Get(Form("%s_L1MET", label));
    TH1F *HLTCaloMET = (TH1F*)ifile->Get(Form("%s_HLTCaloMET", label));
    TH1F *HLTCaloMHT = (TH1F*)ifile->Get(Form("%s_HLTCaloMHT", label));
    TH1F *HLTPFMHT = (TH1F*)ifile->Get(Form("%s_HLTPFMHT", label));
    TH1F *HLTPFMET = (TH1F*)ifile->Get(Form("%s_HLTPFMET", label));


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
    TH1F *eff_HLT_PFMET120_PseudoCaloMET = (TH1F*)if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET->Clone("eff_HLT_PFMET120_PseudoCaloMET");
    TH1F *eff_HLT_PFHT500_PseudoCaloMET = (TH1F*)if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET->Clone("eff_HLT_PFHT500_PseudoCaloMET");
    TH1F *eff_HLT_PFMETNoMu120_PseudoCaloMET = (TH1F*)if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET->Clone("eff_HLT_PFMETNoMu120_PseudoCaloMET");
    TH1F *eff_HLT_MET105_PseudoCaloMET = (TH1F*)if___HLT_MET105_IsoTrk50___PseudoCaloMET->Clone("eff_HLT_MET105_PseudoCaloMET");
    TH1F *eff_orMETtrg_PseudoCaloMET = (TH1F*)if___orMETtrg___PseudoCaloMET->Clone("eff_orMETtrg_PseudoCaloMET");
    
    TH1F *eff_HLT_PFMET120_RecoPFMET = (TH1F*)if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET->Clone("eff_HLT_PFMET120_RecoPFMET");
    TH1F *eff_HLT_PFHT500_RecoPFMET = (TH1F*)if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET->Clone("eff_HLT_PFHT500_RecoPFMET");
    TH1F *eff_HLT_PFMETNoMu120_RecoPFMET = (TH1F*)if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET->Clone("eff_HLT_PFMETNoMu120_RecoPFMET");
    TH1F *eff_HLT_MET105_RecoPFMET = (TH1F*)if___HLT_MET105_IsoTrk50___RecoPFMET->Clone("eff_HLT_MET105_RecoPFMET");
    TH1F *eff_orMETtrg_RecoPFMET = (TH1F*)if___orMETtrg___RecoPFMET->Clone("eff_orMETtrg_RecoPFMET");
    
    TH1F *eff_HLT_PFMET120_PseudoCaloMET__RecoPFMETCut = (TH1F*)if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET__RecoPFMETCut->Clone("eff_HLT_PFMET120_PseudoCaloMET__RecoPFMETCut");
    TH1F *eff_HLT_PFHT500_PseudoCaloMET__RecoPFMETCut = (TH1F*)if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET__RecoPFMETCut->Clone("eff_HLT_PFHT500_PseudoCaloMET__RecoPFMETCut");
    TH1F *eff_HLT_PFMETNoMu120_PseudoCaloMET__RecoPFMETCut = (TH1F*)if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET__RecoPFMETCut->Clone("eff_HLT_PFMETNoMu120_PseudoCaloMET__RecoPFMETCut");
    TH1F *eff_HLT_MET105_PseudoCaloMET__RecoPFMETCut = (TH1F*)if___HLT_MET105_IsoTrk50___PseudoCaloMET__RecoPFMETCut->Clone("eff_HLT_MET105_PseudoCaloMET__RecoPFMETCut");
    TH1F *eff_orMETtrg_PseudoCaloMET__RecoPFMETCut = (TH1F*)if___orMETtrg___PseudoCaloMET__RecoPFMETCut->Clone("eff_orMETtrg_PseudoCaloMET__RecoPFMETCut");

    TH1F *eff_HLT_PFMET120_RecoPFMET__PseudoCaloMETCut = (TH1F*)if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET__PseudoCaloMETCut->Clone("eff_HLT_PFMET120_RecoPFMET__PseudoCaloMETCut");
    TH1F *eff_HLT_PFHT500_RecoPFMET__PseudoCaloMETCut = (TH1F*)if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET__PseudoCaloMETCut->Clone("eff_HLT_PFHT500_RecoPFMET__PseudoCaloMETCut");
    TH1F *eff_HLT_PFMETNoMu120_RecoPFMET__PseudoCaloMETCut = (TH1F*)if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET__PseudoCaloMETCut->Clone("eff_HLT_PFMETNoMu120_RecoPFMET__PseudoCaloMETCut");
    TH1F *eff_HLT_MET105_RecoPFMET__PseudoCaloMETCut = (TH1F*)if___HLT_MET105_IsoTrk50___RecoPFMET__PseudoCaloMETCut->Clone("eff_HLT_MET105_RecoPFMET__PseudoCaloMETCut");
    TH1F *eff_orMETtrg_RecoPFMET__PseudoCaloMETCut = (TH1F*)if___orMETtrg___RecoPFMET__PseudoCaloMETCut->Clone("eff_orMETtrg_RecoPFMET__PseudoCaloMETCut");

    TH1F *eff_HLT_PFMET120_RecoCaloMET;
    TH1F *eff_HLT_PFHT500_RecoCaloMET;
    TH1F *eff_HLT_PFMETNoMu120_RecoCaloMET;
    TH1F *eff_HLT_MET105_RecoCaloMET;
    TH1F *eff_orMETtrg_RecoCaloMET;
    if (isAOD) {
        eff_HLT_PFMET120_RecoCaloMET = (TH1F*)if___HLT_PFMET120_PFMHT120_IDTight___RecoCaloMET->Clone("eff_HLT_PFMET120_RecoCaloMET");
        eff_HLT_PFHT500_RecoCaloMET = (TH1F*)if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoCaloMET->Clone("eff_HLT_PFHT500_RecoCaloMET");
        eff_HLT_PFMETNoMu120_RecoCaloMET = (TH1F*)if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoCaloMET->Clone("eff_HLT_PFMETNoMu120_RecoCaloMET");
        eff_HLT_MET105_RecoCaloMET = (TH1F*)if___HLT_MET105_IsoTrk50___RecoCaloMET->Clone("eff_HLT_MET105_RecoCaloMET");
        eff_orMETtrg_RecoCaloMET = (TH1F*)if___orMETtrg___RecoCaloMET->Clone("eff_orMETtrg_RecoCaloMET");
    }

    // efficiency calculation
    eff_HLT_PFMET120_PseudoCaloMET->Divide(PseudoCaloMET);
    eff_HLT_PFHT500_PseudoCaloMET->Divide(PseudoCaloMET);
    eff_HLT_PFMETNoMu120_PseudoCaloMET->Divide(PseudoCaloMET);
    eff_HLT_MET105_PseudoCaloMET->Divide(PseudoCaloMET);
    eff_orMETtrg_PseudoCaloMET->Divide(PseudoCaloMET);
    
    eff_HLT_PFMET120_RecoPFMET->Divide(RecoPFMET);
    eff_HLT_PFHT500_RecoPFMET->Divide(RecoPFMET);
    eff_HLT_PFMETNoMu120_RecoPFMET->Divide(RecoPFMET);
    eff_HLT_MET105_RecoPFMET->Divide(RecoPFMET);
    eff_orMETtrg_RecoPFMET->Divide(RecoPFMET);

    eff_HLT_PFMET120_PseudoCaloMET__RecoPFMETCut->Divide(PseudoCaloMET__RecoPFMETCut);
    eff_HLT_PFHT500_PseudoCaloMET__RecoPFMETCut->Divide(PseudoCaloMET__RecoPFMETCut);
    eff_HLT_PFMETNoMu120_PseudoCaloMET__RecoPFMETCut->Divide(PseudoCaloMET__RecoPFMETCut);
    eff_HLT_MET105_PseudoCaloMET__RecoPFMETCut->Divide(PseudoCaloMET__RecoPFMETCut);
    eff_orMETtrg_PseudoCaloMET__RecoPFMETCut->Divide(PseudoCaloMET__RecoPFMETCut);
    
    eff_HLT_PFMET120_RecoPFMET__PseudoCaloMETCut->Divide(RecoPFMET__PseudoCaloMETCut);
    eff_HLT_PFHT500_RecoPFMET__PseudoCaloMETCut->Divide(RecoPFMET__PseudoCaloMETCut);
    eff_HLT_PFMETNoMu120_RecoPFMET__PseudoCaloMETCut->Divide(RecoPFMET__PseudoCaloMETCut);
    eff_HLT_MET105_RecoPFMET__PseudoCaloMETCut->Divide(RecoPFMET__PseudoCaloMETCut);
    eff_orMETtrg_RecoPFMET__PseudoCaloMETCut->Divide(RecoPFMET__PseudoCaloMETCut);


    if (isAOD) {
        eff_HLT_PFMET120_RecoCaloMET->Divide(RecoCaloMET);
        eff_HLT_PFHT500_RecoCaloMET->Divide(RecoCaloMET);
        eff_HLT_PFMETNoMu120_RecoCaloMET->Divide(RecoCaloMET);
        eff_HLT_MET105_RecoCaloMET->Divide(RecoCaloMET);
        eff_orMETtrg_RecoCaloMET->Divide(RecoCaloMET);
    }


    // drawing

    TCanvas *c_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET = DrawCanvas(eff_HLT_PFMET120_PseudoCaloMET, "HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET", "PseudoCaloMET [GeV]", "eff. HLT_PFMET120_PFMHT120_IDTight", "E1", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET = DrawCanvas(eff_HLT_PFHT500_PseudoCaloMET, "HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET", "PseudoCaloMET [GeV]", "eff. HLT_PFHT500_PFMET100_PFMHT100_IDTight", "E1", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET = DrawCanvas(eff_HLT_PFMETNoMu120_PseudoCaloMET, "HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET", "PseudoCaloMET [GeV]", "eff. HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60", "E1", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_MET105_IsoTrk50___PseudoCaloMET = DrawCanvas(eff_HLT_MET105_PseudoCaloMET, "HLT_MET105_IsoTrk50___PseudoCaloMET", "PseudoCaloMET [GeV]", "eff. HLT_MET105_IsoTrk50", "E1", 0, 1200, 0, 1, false);    
    TCanvas *c_orMETtrg___PseudoCaloMET = DrawCanvas(eff_orMETtrg_PseudoCaloMET, "orMETtrg___PseudoCaloMET", "PseudoCaloMET [GeV]", "eff. orMETtrg", "E1", 0, 1200, 0, 1, false);

    TCanvas *c_HLT_PFMET120_PFMHT120_IDTight___RecoPFMET = DrawCanvas(eff_HLT_PFMET120_RecoPFMET, "HLT_PFMET120_PFMHT120_IDTight___RecoPFMET", "RecoPFMET [GeV]", "eff. HLT_PFMET120_PFMHT120_IDTight", "E1", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET = DrawCanvas(eff_HLT_PFHT500_RecoPFMET, "HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET", "RecoPFMET [GeV]", "eff. HLT_PFHT500_PFMET100_PFMHT100_IDTight", "E1", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET = DrawCanvas(eff_HLT_PFMETNoMu120_RecoPFMET, "HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET", "RecoPFMET [GeV]", "eff. HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60", "E1", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_MET105_IsoTrk50___RecoPFMET = DrawCanvas(eff_HLT_MET105_RecoPFMET, "HLT_MET105_IsoTrk50___RecoPFMET", "RecoPFMET [GeV]", "eff. HLT_MET105_IsoTrk50", "E1", 0, 1200, 0, 1, false);
    TCanvas *c_orMETtrg___RecoPFMET = DrawCanvas(eff_orMETtrg_RecoPFMET, "orMETtrg___RecoPFMET", "RecoPFMET [GeV]", "eff. orMETtrg", "E1", 0, 1200, 0, 1, false);

    TCanvas *c_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET__RecoPFMETCut = DrawCanvas(eff_HLT_PFMET120_PseudoCaloMET__RecoPFMETCut, "HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET__RecoPFMETCut", "PseudoCaloMET [GeV]", "eff. HLT_PFMET120_PFMHT120_IDTight w/RecoPFMET>170 GeV", "E1", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET__RecoPFMETCut = DrawCanvas(eff_HLT_PFHT500_PseudoCaloMET__RecoPFMETCut, "HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET__RecoPFMETCut", "PseudoCaloMET [GeV]", "eff. HLT_PFHT500_PFMET100_PFMHT100_IDTight w/RecoPFMET>170 GeV", "E1", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET__RecoPFMETCut = DrawCanvas(eff_HLT_PFMETNoMu120_PseudoCaloMET__RecoPFMETCut, "HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET__RecoPFMETCut", "PseudoCaloMET [GeV]", "eff. HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 w/RecoPFMET>170 GeV", "E1", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_MET105_IsoTrk50___PseudoCaloMET__RecoPFMETCut = DrawCanvas(eff_HLT_MET105_PseudoCaloMET__RecoPFMETCut, "HLT_MET105_IsoTrk50___PseudoCaloMET__RecoPFMETCut", "PseudoCaloMET [GeV]", "eff. HLT_MET105_IsoTrk50 w/RecoPFMET>170 GeV", "E1", 0, 1200, 0, 1, false);
    TCanvas *c_orMETtrg___PseudoCaloMET__RecoPFMETCut = DrawCanvas(eff_orMETtrg_PseudoCaloMET__RecoPFMETCut, "orMETtrg___PseudoCaloMET__RecoPFMETCut", "PseudoCaloMET [GeV]", "eff. orMETtrgw/RecoPFMET>170 GeV", "E1", 0, 1200, 0, 1, false);

    TCanvas *c_HLT_PFMET120_PFMHT120_IDTight_RecoPFMET__PseudoCaloMETCut = DrawCanvas(eff_HLT_PFMET120_RecoPFMET__PseudoCaloMETCut, "HLT_PFMET120_PFMHT120_IDTight___RecoPFMET__PseudoCaloMETCut", "RecoPFMET [GeV]", "eff. HLT_PFMET120_PFMHT120_IDTight w/PseudoCaloMET>170 GeV", "E1", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_PFHT500_PFMET100_PFMHT100_IDTight__PseudoCaloMETCut = DrawCanvas(eff_HLT_PFHT500_RecoPFMET__PseudoCaloMETCut, "HLT_PFHT500_PFMET100_PFMHT100_IDTight__PseudoCaloMETCut", "RecoPFMET [GeV]", "eff. HLT_PFHT500_PFMET100_PFMHT100_IDTight w/PseudoCaloMET>170 GeV", "E1", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60__PseudoCaloMETCut = DrawCanvas(eff_HLT_PFMETNoMu120_RecoPFMET__PseudoCaloMETCut, "HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET__PseudoCaloMETCut", "RecoPFMET [GeV]", "eff. HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 w/PseudoCaloMET>170 GeV", "E1", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_MET105_IsoTrk50_RecoPFMET__PseudoCaloMETCut = DrawCanvas(eff_HLT_MET105_RecoPFMET__PseudoCaloMETCut, "HLT_MET105_IsoTrk50___RecoPFMET__PseudoCaloMETCut", "RecoPFMET [GeV]", "eff. HLT_MET105_IsoTrk50 w/PseudoCaloMET>170 GeV", "E1", 0, 1200, 0, 1, false);
    TCanvas *c_orMETtrg_RecoPFMET__PseudoCaloMETCut = DrawCanvas(eff_orMETtrg_RecoPFMET__PseudoCaloMETCut, "orMETtrg_RecoPFMET__PseudoCaloMETCut", "RecoPFMET [GeV]", "eff. orMETtrg w/PseudoCaloMET>170 GeV", "E1", 0, 1200, 0, 1, false);

    TCanvas *c_PseudoCaloMET = DrawCanvas(PseudoCaloMET, "PseudoCaloMET", "PseudoCaloMET [GeV]", "Events / 25 GeV", "HIST", 0, 1000, 0, PseudoCaloMET->GetMaximum()*1.2, true);
    TCanvas *c_RecoPFMET = DrawCanvas(RecoPFMET, "RecoPFMET", "RecoPFMET [GeV]", "Events / 25 GeV", "HIST", 0, 1000, 0, RecoPFMET->GetMaximum()*1.2, true);
    TCanvas *c_L1MET = DrawCanvas(L1MET, "L1MET", "L1MET [GeV]", "Events / 25 GeV", "HIST", 0, 1000, 0, L1MET->GetMaximum()*1.2, true);
    TCanvas *c_HLTCaloMET = DrawCanvas(HLTCaloMET, "HLTCaloMET", "HLTCaloMET [GeV]", "Events / 25 GeV", "HIST", 0, 1000, 0, HLTCaloMET->GetMaximum()*1.2, true);
    TCanvas *c_HLTCaloMHT = DrawCanvas(HLTCaloMHT, "HLTCaloMHT", "HLTCaloMHT [GeV]", "Events / 25 GeV", "HIST", 0, 1000, 0, HLTCaloMHT->GetMaximum()*1.2, true);
    TCanvas *c_HLTPFMHT = DrawCanvas(HLTPFMHT, "HLTPFMHT", "HLTPFMHT [GeV]", "Events / 25 GeV", "HIST", 0, 1000, 0, HLTPFMHT->GetMaximum()*1.2, true);
    TCanvas *c_HLTPFMET = DrawCanvas(HLTPFMET, "HLTPFMET", "HLTPFMET [GeV]", "Events / 25 GeV", "HIST", 0, 1000, 0, HLTPFMET->GetMaximum()*1.2, true);



    // saving
    ofile->cd();
    c_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET->Write();
    c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET->Write();
    c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET->Write();
    c_HLT_MET105_IsoTrk50___PseudoCaloMET->Write();
    c_orMETtrg___PseudoCaloMET->Write();

    c_HLT_PFMET120_PFMHT120_IDTight___RecoPFMET->Write();
    c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET->Write();
    c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET->Write();
    c_HLT_MET105_IsoTrk50___RecoPFMET->Write();
    c_orMETtrg___RecoPFMET->Write();

    c_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET__RecoPFMETCut->Write();
    c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET__RecoPFMETCut->Write();
    c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET__RecoPFMETCut->Write();
    c_HLT_MET105_IsoTrk50___PseudoCaloMET__RecoPFMETCut->Write();
    c_orMETtrg___PseudoCaloMET__RecoPFMETCut->Write();

    c_HLT_PFMET120_PFMHT120_IDTight_RecoPFMET__PseudoCaloMETCut->Write();
    c_HLT_PFHT500_PFMET100_PFMHT100_IDTight__PseudoCaloMETCut->Write();
    c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60__PseudoCaloMETCut->Write();
    c_HLT_MET105_IsoTrk50_RecoPFMET__PseudoCaloMETCut->Write();
    c_orMETtrg_RecoPFMET__PseudoCaloMETCut->Write();

    c_PseudoCaloMET->Write();
    c_RecoPFMET->Write();
    c_L1MET->Write();
    c_HLTCaloMET->Write();
    c_HLTCaloMHT->Write();
    c_HLTPFMHT->Write();
    c_HLTPFMET->Write();
    
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
        //c_PFMET_nocut_ratio = DrawWithRatio(RecoPFMET_AOD, RecoPFMET_miniAOD, c_PFMET_nocut, "RecoPFMET AOD vs miniAOD", "AOD/miniAOD", "E1 same", "E1 same", 0, 2000);

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
        //c_PFMET_AODcut_ratio = DrawWithRatio(RecoPFMET_AOD, RecoPFMET_cutPseudoCaloMET_AOD, c_PFMET_AODcut, "RecoPFMET AOD cut", "wo cut/cut", "E1 same", "E1 same", 0, 2000);
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
    //TCanvas *c_PFMET_miniAODcut_ratio = DrawWithRatio(RecoPFMET_miniAOD, RecoPFMET_cutPseudoCaloMET_miniAOD, c_PFMET_miniAODcut, "RecoPFMET miniAOD cut", "wo cut/cut", "E1 same", "E1 same", 0, 2000);


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
        //c_PFMET_CaloMETcut_ratio = DrawWithRatio(RecoPFMET_cutPseudoCaloMET_AOD, RecoPFMET_cutRecoCaloMET_AOD, c_PFMET_CaloMETcut, "RecoPFMET AOD", "PseudoCaloMET cut/RecoCaloMET cut", "E1 same", "E1 same", 0, 2000);
    
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
        //c_PFMET_ratio = DrawWithRatio(RecoPFMET_cutPseudoCaloMET_AOD, RecoPFMET_cutPseudoCaloMET_miniAOD, c_PFMET_onlycut, "RecoPFMET with PseudoCaloMET cut", "AOD/miniAOD", "E1 same", "E1 same", 0, 2000);
    }
    // saving
    cout << "saving histos..." << endl;
    ofile->cd();
    //c_PFMET_miniAODcut_ratio->Write();
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
    TH1F *eff_orMETtrg_RecoPFMET_AOD = (TH1F*)if___orMETtrg___RecoPFMET_AOD->Clone("eff_orMETtrg_RecoPFMET_AOD");
    TH1F *eff_orMETtrg_RecoPFMET_miniAOD = (TH1F*)if___orMETtrg___RecoPFMET_miniAOD->Clone("eff_orMETtrg_RecoPFMET_miniAOD");
    
    TH1F *eff_orMETtrg_PseudoCaloMET_AOD = (TH1F*)if___orMETtrg___PseudoCaloMET_AOD->Clone("eff_orMETtrg_PseudoCaloMET_AOD");
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
    //TCanvas *c_PFMET_ratio = DrawWithRatio(eff_orMETtrg_RecoPFMET_miniAOD, eff_orMETtrg_RecoPFMET_AOD, c_PFMET, "RecoPFMET", "miniAOD/AOD", "E1 same", "E1 same", 0, 1200, 0, 1, false);

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
    //TCanvas *c_PseudoCaloMET_ratio = DrawWithRatio(eff_orMETtrg_PseudoCaloMET_miniAOD, eff_orMETtrg_PseudoCaloMET_AOD, c_PseudoCaloMET, "PseudoCaloMET", "miniAOD/AOD", "E1 same", "E1 same", 0, 1200, 0, 1, false);


    // saving
    ofile->cd();
    c_PFMET->Write();
    //c_PFMET_ratio->Write();
    c_PseudoCaloMET->Write();
    //c_PseudoCaloMET_ratio->Write();
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


void MET_trg_eff(const char *label, const char *ofilename, const char *inputfileDATA, const char *inputfileMC) {

    TFile *ofile = new TFile(Form("PlayWithHistos/%s.root", ofilename), "RECREATE");

    TFile *ifileDATA = new TFile(Form("%s", inputfileDATA), "READ");
    TFile *ifileMC = new TFile(Form("%s", inputfileMC), "READ");


    // MC 
    TH1F *PseudoCaloMET_MC = (TH1F*)ifileMC->Get(Form("%s_PseudoCaloMET", label));
    TH1F *if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET_MC = (TH1F*)ifileMC->Get(Form("%s_if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET", label));
    TH1F *if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET_MC = (TH1F*)ifileMC->Get(Form("%s_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET", label));
    TH1F *if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET_MC = (TH1F*)ifileMC->Get(Form("%s_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET", label));
    TH1F *if___HLT_MET105_IsoTrk50___PseudoCaloMET_MC = (TH1F*)ifileMC->Get(Form("%s_if___HLT_MET105_IsoTrk50___PseudoCaloMET", label));
    TH1F *if___orMETtrg___PseudoCaloMET_MC = (TH1F*)ifileMC->Get(Form("%s_if___orMETtrg___PseudoCaloMET", label));

    TH1F *RecoPFMET_MC = (TH1F*)ifileMC->Get(Form("%s_RecoPFMET", label));
    TH1F *if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET_MC = (TH1F*)ifileMC->Get(Form("%s_if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET", label));            
    TH1F *if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET_MC = (TH1F*)ifileMC->Get(Form("%s_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET", label));
    TH1F *if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET_MC = (TH1F*)ifileMC->Get(Form("%s_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET", label));
    TH1F *if___HLT_MET105_IsoTrk50___RecoPFMET_MC = (TH1F*)ifileMC->Get(Form("%s_if___HLT_MET105_IsoTrk50___RecoPFMET", label));
    TH1F *if___orMETtrg___RecoPFMET_MC = (TH1F*)ifileMC->Get(Form("%s_if___orMETtrg___RecoPFMET", label));
    
    TH1F *PseudoCaloMET__RecoPFMETCut_MC = (TH1F*)ifileMC->Get(Form("%s_PseudoCaloMET__RecoPFMETCut", label));
    TH1F *if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET__RecoPFMETCut_MC = (TH1F*)ifileMC->Get(Form("%s_if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET__RecoPFMETCut", label));       
    TH1F *if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET__RecoPFMETCut_MC = (TH1F*)ifileMC->Get(Form("%s_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET__RecoPFMETCut", label));
    TH1F *if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET__RecoPFMETCut_MC = (TH1F*)ifileMC->Get(Form("%s_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET__RecoPFMETCut", label));
    TH1F *if___HLT_MET105_IsoTrk50___PseudoCaloMET__RecoPFMETCut_MC = (TH1F*)ifileMC->Get(Form("%s_if___HLT_MET105_IsoTrk50___PseudoCaloMET__RecoPFMETCut", label));
    TH1F *if___orMETtrg___PseudoCaloMET__RecoPFMETCut_MC = (TH1F*)ifileMC->Get(Form("%s_if___orMETtrg___PseudoCaloMET__RecoPFMETCut", label));
    
    TH1F *RecoPFMET__PseudoCaloMETCut_MC = (TH1F*)ifileMC->Get(Form("%s_RecoPFMET__PseudoCaloMETCut", label));
    TH1F *if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET__PseudoCaloMETCut_MC = (TH1F*)ifileMC->Get(Form("%s_if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET__PseudoCaloMETCut", label));      
    TH1F *if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET__PseudoCaloMETCut_MC = (TH1F*)ifileMC->Get(Form("%s_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET__PseudoCaloMETCut", label));
    TH1F *if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET__PseudoCaloMETCut_MC = (TH1F*)ifileMC->Get(Form("%s_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET__PseudoCaloMETCut", label));
    TH1F *if___HLT_MET105_IsoTrk50___RecoPFMET__PseudoCaloMETCut_MC = (TH1F*)ifileMC->Get(Form("%s_if___HLT_MET105_IsoTrk50___RecoPFMET__PseudoCaloMETCut", label));
    TH1F *if___orMETtrg___RecoPFMET__PseudoCaloMETCut_MC = (TH1F*)ifileMC->Get(Form("%s_if___orMETtrg___RecoPFMET__PseudoCaloMETCut", label));


    // DATA
    TH1F *PseudoCaloMET_DATA = (TH1F*)ifileDATA->Get(Form("%s_PseudoCaloMET", label));
    TH1F *if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET", label));
    TH1F *if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET", label));
    TH1F *if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET", label));
    TH1F *if___HLT_MET105_IsoTrk50___PseudoCaloMET_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___HLT_MET105_IsoTrk50___PseudoCaloMET", label));
    TH1F *if___orMETtrg___PseudoCaloMET_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___orMETtrg___PseudoCaloMET", label));

    TH1F *RecoPFMET_DATA = (TH1F*)ifileDATA->Get(Form("%s_RecoPFMET", label));
    TH1F *if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET", label));            
    TH1F *if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET", label));
    TH1F *if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET", label));
    TH1F *if___HLT_MET105_IsoTrk50___RecoPFMET_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___HLT_MET105_IsoTrk50___RecoPFMET", label));
    TH1F *if___orMETtrg___RecoPFMET_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___orMETtrg___RecoPFMET", label));
    
    TH1F *PseudoCaloMET__RecoPFMETCut_DATA = (TH1F*)ifileDATA->Get(Form("%s_PseudoCaloMET__RecoPFMETCut", label));
    TH1F *if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET__RecoPFMETCut_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET__RecoPFMETCut", label));       
    TH1F *if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET__RecoPFMETCut_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET__RecoPFMETCut", label));
    TH1F *if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET__RecoPFMETCut_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET__RecoPFMETCut", label));
    TH1F *if___HLT_MET105_IsoTrk50___PseudoCaloMET__RecoPFMETCut_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___HLT_MET105_IsoTrk50___PseudoCaloMET__RecoPFMETCut", label));
    TH1F *if___orMETtrg___PseudoCaloMET__RecoPFMETCut_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___orMETtrg___PseudoCaloMET__RecoPFMETCut", label));
    
    TH1F *RecoPFMET__PseudoCaloMETCut_DATA = (TH1F*)ifileDATA->Get(Form("%s_RecoPFMET__PseudoCaloMETCut", label));
    TH1F *if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET__PseudoCaloMETCut_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET__PseudoCaloMETCut", label));      
    TH1F *if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET__PseudoCaloMETCut_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET__PseudoCaloMETCut", label));
    TH1F *if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET__PseudoCaloMETCut_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET__PseudoCaloMETCut", label));
    TH1F *if___HLT_MET105_IsoTrk50___RecoPFMET__PseudoCaloMETCut_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___HLT_MET105_IsoTrk50___RecoPFMET__PseudoCaloMETCut", label));
    TH1F *if___orMETtrg___RecoPFMET__PseudoCaloMETCut_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___orMETtrg___RecoPFMET__PseudoCaloMETCut", label));


    // setup 
    TH1F *eff_HLT_PFMET120_PseudoCaloMET_MC = (TH1F*)if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET_MC->Clone("eff_HLT_PFMET120_PseudoCaloMET_MC");
    TH1F *eff_HLT_PFHT500_PseudoCaloMET_MC = (TH1F*)if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET_MC->Clone("eff_HLT_PFHT500_PseudoCaloMET_MC");
    TH1F *eff_HLT_PFMETNoMu120_PseudoCaloMET_MC = (TH1F*)if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET_MC->Clone("eff_HLT_PFMETNoMu120_PseudoCaloMET_MC");
    TH1F *eff_HLT_MET105_PseudoCaloMET_MC = (TH1F*)if___HLT_MET105_IsoTrk50___PseudoCaloMET_MC->Clone("eff_HLT_MET105_PseudoCaloMET_MC");
    TH1F *eff_orMETtrg_PseudoCaloMET_MC = (TH1F*)if___orMETtrg___PseudoCaloMET_MC->Clone("eff_orMETtrg_PseudoCaloMET_MC");
    
    TH1F *eff_HLT_PFMET120_RecoPFMET_MC = (TH1F*)if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET_MC->Clone("eff_HLT_PFMET120_RecoPFMET_MC");
    TH1F *eff_HLT_PFHT500_RecoPFMET_MC = (TH1F*)if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET_MC->Clone("eff_HLT_PFHT500_RecoPFMET_MC");
    TH1F *eff_HLT_PFMETNoMu120_RecoPFMET_MC = (TH1F*)if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET_MC->Clone("eff_HLT_PFMETNoMu120_RecoPFMET_MC");
    TH1F *eff_HLT_MET105_RecoPFMET_MC = (TH1F*)if___HLT_MET105_IsoTrk50___RecoPFMET_MC->Clone("eff_HLT_MET105_RecoPFMET_MC");
    TH1F *eff_orMETtrg_RecoPFMET_MC = (TH1F*)if___orMETtrg___RecoPFMET_MC->Clone("eff_orMETtrg_RecoPFMET_MC");
    
    TH1F *eff_HLT_PFMET120_PseudoCaloMET__RecoPFMETCut_MC = (TH1F*)if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET__RecoPFMETCut_MC->Clone("eff_HLT_PFMET120_PseudoCaloMET__RecoPFMETCut_MC");
    TH1F *eff_HLT_PFHT500_PseudoCaloMET__RecoPFMETCut_MC = (TH1F*)if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET__RecoPFMETCut_MC->Clone("eff_HLT_PFHT500_PseudoCaloMET__RecoPFMETCut_MC");
    TH1F *eff_HLT_PFMETNoMu120_PseudoCaloMET__RecoPFMETCut_MC = (TH1F*)if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET__RecoPFMETCut_MC->Clone("eff_HLT_PFMETNoMu120_PseudoCaloMET__RecoPFMETCut_MC");
    TH1F *eff_HLT_MET105_PseudoCaloMET__RecoPFMETCut_MC = (TH1F*)if___HLT_MET105_IsoTrk50___PseudoCaloMET__RecoPFMETCut_MC->Clone("eff_HLT_MET105_PseudoCaloMET__RecoPFMETCut_MC");
    TH1F *eff_orMETtrg_PseudoCaloMET__RecoPFMETCut_MC = (TH1F*)if___orMETtrg___PseudoCaloMET__RecoPFMETCut_MC->Clone("eff_orMETtrg_PseudoCaloMET__RecoPFMETCut_MC");

    TH1F *eff_HLT_PFMET120_RecoPFMET__PseudoCaloMETCut_MC = (TH1F*)if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET__PseudoCaloMETCut_MC->Clone("eff_HLT_PFMET120_RecoPFMET__PseudoCaloMETCut_MC");
    TH1F *eff_HLT_PFHT500_RecoPFMET__PseudoCaloMETCut_MC = (TH1F*)if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET__PseudoCaloMETCut_MC->Clone("eff_HLT_PFHT500_RecoPFMET__PseudoCaloMETCut_MC");
    TH1F *eff_HLT_PFMETNoMu120_RecoPFMET__PseudoCaloMETCut_MC = (TH1F*)if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET__PseudoCaloMETCut_MC->Clone("eff_HLT_PFMETNoMu120_RecoPFMET__PseudoCaloMETCut_MC");
    TH1F *eff_HLT_MET105_RecoPFMET__PseudoCaloMETCut_MC = (TH1F*)if___HLT_MET105_IsoTrk50___RecoPFMET__PseudoCaloMETCut_MC->Clone("eff_HLT_MET105_RecoPFMET__PseudoCaloMETCut_MC");
    TH1F *eff_orMETtrg_RecoPFMET__PseudoCaloMETCut_MC = (TH1F*)if___orMETtrg___RecoPFMET__PseudoCaloMETCut_MC->Clone("eff_orMETtrg_RecoPFMET__PseudoCaloMETCut_MC");


    TH1F *eff_HLT_PFMET120_PseudoCaloMET_DATA = (TH1F*)if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET_DATA->Clone("eff_HLT_PFMET120_PseudoCaloMET_DATA");
    TH1F *eff_HLT_PFHT500_PseudoCaloMET_DATA = (TH1F*)if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET_DATA->Clone("eff_HLT_PFHT500_PseudoCaloMET_DATA");
    TH1F *eff_HLT_PFMETNoMu120_PseudoCaloMET_DATA = (TH1F*)if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET_DATA->Clone("eff_HLT_PFMETNoMu120_PseudoCaloMET_DATA");
    TH1F *eff_HLT_MET105_PseudoCaloMET_DATA = (TH1F*)if___HLT_MET105_IsoTrk50___PseudoCaloMET_DATA->Clone("eff_HLT_MET105_PseudoCaloMET_DATA");
    TH1F *eff_orMETtrg_PseudoCaloMET_DATA = (TH1F*)if___orMETtrg___PseudoCaloMET_DATA->Clone("eff_orMETtrg_PseudoCaloMET_DATA");
    
    TH1F *eff_HLT_PFMET120_RecoPFMET_DATA = (TH1F*)if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET_DATA->Clone("eff_HLT_PFMET120_RecoPFMET_DATA");
    TH1F *eff_HLT_PFHT500_RecoPFMET_DATA = (TH1F*)if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET_DATA->Clone("eff_HLT_PFHT500_RecoPFMET_DATA");
    TH1F *eff_HLT_PFMETNoMu120_RecoPFMET_DATA = (TH1F*)if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET_DATA->Clone("eff_HLT_PFMETNoMu120_RecoPFMET_DATA");
    TH1F *eff_HLT_MET105_RecoPFMET_DATA = (TH1F*)if___HLT_MET105_IsoTrk50___RecoPFMET_DATA->Clone("eff_HLT_MET105_RecoPFMET_DATA");
    TH1F *eff_orMETtrg_RecoPFMET_DATA = (TH1F*)if___orMETtrg___RecoPFMET_DATA->Clone("eff_orMETtrg_RecoPFMET_DATA");
    
    TH1F *eff_HLT_PFMET120_PseudoCaloMET__RecoPFMETCut_DATA = (TH1F*)if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET__RecoPFMETCut_DATA->Clone("eff_HLT_PFMET120_PseudoCaloMET__RecoPFMETCut_DATA");
    TH1F *eff_HLT_PFHT500_PseudoCaloMET__RecoPFMETCut_DATA = (TH1F*)if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET__RecoPFMETCut_DATA->Clone("eff_HLT_PFHT500_PseudoCaloMET__RecoPFMETCut_DATA");
    TH1F *eff_HLT_PFMETNoMu120_PseudoCaloMET__RecoPFMETCut_DATA = (TH1F*)if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET__RecoPFMETCut_DATA->Clone("eff_HLT_PFMETNoMu120_PseudoCaloMET__RecoPFMETCut_DATA");
    TH1F *eff_HLT_MET105_PseudoCaloMET__RecoPFMETCut_DATA = (TH1F*)if___HLT_MET105_IsoTrk50___PseudoCaloMET__RecoPFMETCut_DATA->Clone("eff_HLT_MET105_PseudoCaloMET__RecoPFMETCut_DATA");
    TH1F *eff_orMETtrg_PseudoCaloMET__RecoPFMETCut_DATA = (TH1F*)if___orMETtrg___PseudoCaloMET__RecoPFMETCut_DATA->Clone("eff_orMETtrg_PseudoCaloMET__RecoPFMETCut_DATA");

    TH1F *eff_HLT_PFMET120_RecoPFMET__PseudoCaloMETCut_DATA = (TH1F*)if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET__PseudoCaloMETCut_DATA->Clone("eff_HLT_PFMET120_RecoPFMET__PseudoCaloMETCut_DATA");
    TH1F *eff_HLT_PFHT500_RecoPFMET__PseudoCaloMETCut_DATA = (TH1F*)if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET__PseudoCaloMETCut_DATA->Clone("eff_HLT_PFHT500_RecoPFMET__PseudoCaloMETCut_DATA");
    TH1F *eff_HLT_PFMETNoMu120_RecoPFMET__PseudoCaloMETCut_DATA = (TH1F*)if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET__PseudoCaloMETCut_DATA->Clone("eff_HLT_PFMETNoMu120_RecoPFMET__PseudoCaloMETCut_DATA");
    TH1F *eff_HLT_MET105_RecoPFMET__PseudoCaloMETCut_DATA = (TH1F*)if___HLT_MET105_IsoTrk50___RecoPFMET__PseudoCaloMETCut_DATA->Clone("eff_HLT_MET105_RecoPFMET__PseudoCaloMETCut_DATA");
    TH1F *eff_orMETtrg_RecoPFMET__PseudoCaloMETCut_DATA = (TH1F*)if___orMETtrg___RecoPFMET__PseudoCaloMETCut_DATA->Clone("eff_orMETtrg_RecoPFMET__PseudoCaloMETCut_DATA");



    // efficiency calculation
    eff_HLT_PFMET120_PseudoCaloMET_MC->Divide(PseudoCaloMET_MC);
    eff_HLT_PFHT500_PseudoCaloMET_MC->Divide(PseudoCaloMET_MC);
    eff_HLT_PFMETNoMu120_PseudoCaloMET_MC->Divide(PseudoCaloMET_MC);
    eff_HLT_MET105_PseudoCaloMET_MC->Divide(PseudoCaloMET_MC);
    eff_orMETtrg_PseudoCaloMET_MC->Divide(PseudoCaloMET_MC);
    
    eff_HLT_PFMET120_RecoPFMET_MC->Divide(RecoPFMET_MC);
    eff_HLT_PFHT500_RecoPFMET_MC->Divide(RecoPFMET_MC);
    eff_HLT_PFMETNoMu120_RecoPFMET_MC->Divide(RecoPFMET_MC);
    eff_HLT_MET105_RecoPFMET_MC->Divide(RecoPFMET_MC);
    eff_orMETtrg_RecoPFMET_MC->Divide(RecoPFMET_MC);

    eff_HLT_PFMET120_PseudoCaloMET__RecoPFMETCut_MC->Divide(PseudoCaloMET__RecoPFMETCut_MC);
    eff_HLT_PFHT500_PseudoCaloMET__RecoPFMETCut_MC->Divide(PseudoCaloMET__RecoPFMETCut_MC);
    eff_HLT_PFMETNoMu120_PseudoCaloMET__RecoPFMETCut_MC->Divide(PseudoCaloMET__RecoPFMETCut_MC);
    eff_HLT_MET105_PseudoCaloMET__RecoPFMETCut_MC->Divide(PseudoCaloMET__RecoPFMETCut_MC);
    eff_orMETtrg_PseudoCaloMET__RecoPFMETCut_MC->Divide(PseudoCaloMET__RecoPFMETCut_MC);
    
    eff_HLT_PFMET120_RecoPFMET__PseudoCaloMETCut_MC->Divide(RecoPFMET__PseudoCaloMETCut_MC);
    eff_HLT_PFHT500_RecoPFMET__PseudoCaloMETCut_MC->Divide(RecoPFMET__PseudoCaloMETCut_MC);
    eff_HLT_PFMETNoMu120_RecoPFMET__PseudoCaloMETCut_MC->Divide(RecoPFMET__PseudoCaloMETCut_MC);
    eff_HLT_MET105_RecoPFMET__PseudoCaloMETCut_MC->Divide(RecoPFMET__PseudoCaloMETCut_MC);
    eff_orMETtrg_RecoPFMET__PseudoCaloMETCut_MC->Divide(RecoPFMET__PseudoCaloMETCut_MC);


    eff_HLT_PFMET120_PseudoCaloMET_DATA->Divide(PseudoCaloMET_DATA);
    eff_HLT_PFHT500_PseudoCaloMET_DATA->Divide(PseudoCaloMET_DATA);
    eff_HLT_PFMETNoMu120_PseudoCaloMET_DATA->Divide(PseudoCaloMET_DATA);
    eff_HLT_MET105_PseudoCaloMET_DATA->Divide(PseudoCaloMET_DATA);
    eff_orMETtrg_PseudoCaloMET_DATA->Divide(PseudoCaloMET_DATA);
    
    eff_HLT_PFMET120_RecoPFMET_DATA->Divide(RecoPFMET_DATA);
    eff_HLT_PFHT500_RecoPFMET_DATA->Divide(RecoPFMET_DATA);
    eff_HLT_PFMETNoMu120_RecoPFMET_DATA->Divide(RecoPFMET_DATA);
    eff_HLT_MET105_RecoPFMET_DATA->Divide(RecoPFMET_DATA);
    eff_orMETtrg_RecoPFMET_DATA->Divide(RecoPFMET_DATA);

    eff_HLT_PFMET120_PseudoCaloMET__RecoPFMETCut_DATA->Divide(PseudoCaloMET__RecoPFMETCut_DATA);
    eff_HLT_PFHT500_PseudoCaloMET__RecoPFMETCut_DATA->Divide(PseudoCaloMET__RecoPFMETCut_DATA);
    eff_HLT_PFMETNoMu120_PseudoCaloMET__RecoPFMETCut_DATA->Divide(PseudoCaloMET__RecoPFMETCut_DATA);
    eff_HLT_MET105_PseudoCaloMET__RecoPFMETCut_DATA->Divide(PseudoCaloMET__RecoPFMETCut_DATA);
    eff_orMETtrg_PseudoCaloMET__RecoPFMETCut_DATA->Divide(PseudoCaloMET__RecoPFMETCut_DATA);
    
    eff_HLT_PFMET120_RecoPFMET__PseudoCaloMETCut_DATA->Divide(RecoPFMET__PseudoCaloMETCut_DATA);
    eff_HLT_PFHT500_RecoPFMET__PseudoCaloMETCut_DATA->Divide(RecoPFMET__PseudoCaloMETCut_DATA);
    eff_HLT_PFMETNoMu120_RecoPFMET__PseudoCaloMETCut_DATA->Divide(RecoPFMET__PseudoCaloMETCut_DATA);
    eff_HLT_MET105_RecoPFMET__PseudoCaloMETCut_DATA->Divide(RecoPFMET__PseudoCaloMETCut_DATA);
    eff_orMETtrg_RecoPFMET__PseudoCaloMETCut_DATA->Divide(RecoPFMET__PseudoCaloMETCut_DATA);



    // drawing    
    TCanvas *c_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET = DrawCanvas(eff_HLT_PFMET120_PseudoCaloMET_DATA, eff_HLT_PFMET120_PseudoCaloMET_MC, "c_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET", "PseudoCaloMET [GeV]", "eff. HLT_PFMET120_PFMHT120_IDTight",
    "E1", "E1 same", true, "DATA", "MC", "lep", "lep", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET = DrawCanvas(eff_HLT_PFHT500_PseudoCaloMET_DATA, eff_HLT_PFHT500_PseudoCaloMET_MC, "c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET", "PseudoCaloMET [GeV]", "eff. HLT_PFHT500_PFMET100_PFMHT100_IDTight",
    "E1", "E1 same", true, "DATA", "MC", "lep", "lep", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET = DrawCanvas(eff_HLT_PFMETNoMu120_PseudoCaloMET_DATA, eff_HLT_PFMETNoMu120_PseudoCaloMET_MC, "c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET", "PseudoCaloMET [GeV]", "eff. HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60",
    "E1", "E1 same", true, "DATA", "MC", "lep", "lep", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_MET105_IsoTrk50___PseudoCaloMET = DrawCanvas(eff_HLT_MET105_PseudoCaloMET_DATA, eff_HLT_MET105_PseudoCaloMET_MC, "c_HLT_MET105_IsoTrk50___PseudoCaloMET", "PseudoCaloMET [GeV]", "eff. HLT_MET105_IsoTrk50",
    "E1", "E1 same", true, "DATA", "MC", "lep", "lep", 0, 1200, 0, 1, false);
    TCanvas *c_orMETtrg___PseudoCaloMET = DrawCanvas(eff_orMETtrg_PseudoCaloMET_DATA, eff_orMETtrg_PseudoCaloMET_MC, "c_orMETtrg___PseudoCaloMET", "PseudoCaloMET [GeV]", "eff orMETtrg",
    "E1", "E1 same", true, "DATA", "MC", "lep", "lep", 0, 1200, 0, 1, false);

    TCanvas *c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET = DrawCanvas(eff_HLT_PFHT500_RecoPFMET_DATA, eff_HLT_PFHT500_RecoPFMET_MC, "c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET", "RecoPFMET [GeV]", "eff. HLT_PFHT500_PFMET100_PFMHT100_IDTight",
    "E1", "E1 same", true, "DATA", "MC", "lep", "lep", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_PFMET120_PFMHT120_IDTight___RecoPFMET = DrawCanvas(eff_HLT_PFMET120_RecoPFMET_DATA, eff_HLT_PFMET120_RecoPFMET_MC, "c_HLT_PFMET120_PFMHT120_IDTight___RecoPFMET", "RecoPFMET [GeV]", "eff. HLT_PFMET120_PFMHT120_IDTight",
    "E1", "E1 same", true, "DATA", "MC", "lep", "lep", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET = DrawCanvas(eff_HLT_PFMETNoMu120_RecoPFMET_DATA, eff_HLT_PFMETNoMu120_RecoPFMET_MC, "c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET", "RecoPFMET [GeV]", "eff. HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60",
    "E1", "E1 same", true, "DATA", "MC", "lep", "lep", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_MET105_IsoTrk50___RecoPFMET = DrawCanvas(eff_HLT_MET105_RecoPFMET_DATA, eff_HLT_MET105_RecoPFMET_MC, "c_HLT_MET105_IsoTrk50___RecoPFMET", "RecoPFMET [GeV]", "eff. HLT_MET105_IsoTrk50",
    "E1", "E1 same", true, "DATA", "MC", "lep", "lep", 0, 1200, 0, 1, false);
    TCanvas *c_orMETtrg___RecoPFMET = DrawCanvas(eff_orMETtrg_RecoPFMET_DATA, eff_orMETtrg_RecoPFMET_MC, "c_orMETtrg___RecoPFMET", "RecoPFMET [GeV]", "eff orMETtrg",
    "E1", "E1 same", true, "DATA", "MC", "lep", "lep", 0, 1200, 0, 1, false);

    TCanvas *c_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET__RecoPFMETCut = DrawCanvas(eff_HLT_PFMET120_PseudoCaloMET__RecoPFMETCut_DATA, eff_HLT_PFMET120_PseudoCaloMET__RecoPFMETCut_MC, "c_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET__RecoPFMETCut", "PseudoCaloMET [GeV]", "eff. HLT_PFMET120_PFMHT120_IDTight w/RecoPFMET>170GeV",
    "E1", "E1 same", true, "DATA", "MC", "lep", "lep", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET__RecoPFMETCut = DrawCanvas(eff_HLT_PFHT500_PseudoCaloMET__RecoPFMETCut_DATA, eff_HLT_PFHT500_PseudoCaloMET__RecoPFMETCut_MC, "c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET__RecoPFMETCut", "PseudoCaloMET [GeV]", "eff. HLT_PFHT500_PFMET100_PFMHT100_IDTight w/RecoPFMET>170GeV",
    "E1", "E1 same", true, "DATA", "MC", "lep", "lep", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET__RecoPFMETCut = DrawCanvas(eff_HLT_PFMETNoMu120_PseudoCaloMET__RecoPFMETCut_DATA, eff_HLT_PFMETNoMu120_PseudoCaloMET__RecoPFMETCut_MC, "c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET__RecoPFMETCut", "PseudoCaloMET [GeV]", "eff. HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 w/RecoPFMET>170GeV",
    "E1", "E1 same", true, "DATA", "MC", "lep", "lep", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_MET105_IsoTrk50___PseudoCaloMET__RecoPFMETCut = DrawCanvas(eff_HLT_MET105_PseudoCaloMET__RecoPFMETCut_DATA, eff_HLT_MET105_PseudoCaloMET__RecoPFMETCut_MC, "c_HLT_MET105_IsoTrk50___PseudoCaloMET__RecoPFMETCut", "PseudoCaloMET [GeV]", "eff. HLT_MET105_IsoTrk50 w/RecoPFMET>170GeV",
    "E1", "E1 same", true, "DATA", "MC", "lep", "lep", 0, 1200, 0, 1, false);
    TCanvas *c_orMETtrg___PseudoCaloMET__RecoPFMETCut = DrawCanvas(eff_orMETtrg_PseudoCaloMET__RecoPFMETCut_DATA, eff_orMETtrg_PseudoCaloMET__RecoPFMETCut_MC, "c_orMETtrg___PseudoCaloMET__RecoPFMETCut", "PseudoCaloMET [GeV]", "eff orMETtrg w/RecoPFMET>170GeV",
    "E1", "E1 same", true, "DATA", "MC", "lep", "lep", 0, 1200, 0, 1, false);

    TCanvas *c_HLT_PFMET120_PFMHT120_IDTight___RecoPFMET__PseudoCaloMETCut = DrawCanvas(eff_HLT_PFMET120_RecoPFMET__PseudoCaloMETCut_DATA, eff_HLT_PFMET120_RecoPFMET__PseudoCaloMETCut_MC, "c_HLT_PFMET120_PFMHT120_IDTight___RecoPFMET__PseudoCaloMETCut", "RecoPFMET [GeV]", "eff. HLT_PFMET120_PFMHT120_IDTight w/PseudoCaloMET>170GeV",
    "E1", "E1 same", true, "DATA", "MC", "lep", "lep", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET__PseudoCaloMETCut = DrawCanvas(eff_HLT_PFHT500_RecoPFMET__PseudoCaloMETCut_DATA, eff_HLT_PFHT500_RecoPFMET__PseudoCaloMETCut_MC, "c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET__PseudoCaloMETCut", "RecoPFMET [GeV]", "eff. HLT_PFHT500_PFMET100_PFMHT100_IDTight w/PseudoCaloMET>170GeV",
    "E1", "E1 same", true, "DATA", "MC", "lep", "lep", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET__PseudoCaloMETCut = DrawCanvas(eff_HLT_PFMETNoMu120_RecoPFMET__PseudoCaloMETCut_DATA, eff_HLT_PFMETNoMu120_RecoPFMET__PseudoCaloMETCut_MC, "c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET__PseudoCaloMETCut", "RecoPFMET [GeV]", "eff. HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 w/PseudoCaloMET>170GeV",
    "E1", "E1 same", true, "DATA", "MC", "lep", "lep", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_MET105_IsoTrk50___RecoPFMET__PseudoCaloMETCut = DrawCanvas(eff_HLT_MET105_RecoPFMET__PseudoCaloMETCut_DATA, eff_HLT_MET105_RecoPFMET__PseudoCaloMETCut_MC, "c_HLT_MET105_IsoTrk50___RecoPFMET__PseudoCaloMETCut", "RecoPFMET [GeV]", "eff. HLT_MET105_IsoTrk50 w/PseudoCaloMET>170GeV",
    "E1", "E1 same", true, "DATA", "MC", "lep", "lep", 0, 1200, 0, 1, false);
    TCanvas *c_orMETtrg___RecoPFMET__PseudoCaloMETCut = DrawCanvas(eff_orMETtrg_RecoPFMET__PseudoCaloMETCut_DATA, eff_orMETtrg_RecoPFMET__PseudoCaloMETCut_MC, "c_orMETtrg___RecoPFMET__PseudoCaloMETCut", "RecoPFMET [GeV]", "eff. orMETtrg w/PseudoCaloMET>170GeV",
    "E1", "E1 same", true, "DATA", "MC", "lep", "lep", 0, 1200, 0, 1, false);

    TCanvas *cRatio_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET = DrawWithRatio(eff_HLT_PFMET120_PseudoCaloMET_DATA, eff_HLT_PFMET120_PseudoCaloMET_MC, c_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET, "HLT_PFMET120_PFMHT120_IDTight_pseudoCaloMET", "DATA/MC", "PseudoCaloMET [GeV]", 0, 1200);
    TCanvas *cRatio_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET = DrawWithRatio(eff_HLT_PFHT500_PseudoCaloMET_DATA, eff_HLT_PFHT500_PseudoCaloMET_MC, c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET, "HLT_PFHT500_PFMET100_PFMHT100_IDTight_pseudoCaloMET", "DATA/MC", "PseudoCaloMET [GeV]", 0, 1200);
    TCanvas *cRatio_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET = DrawWithRatio(eff_HLT_PFMETNoMu120_PseudoCaloMET_DATA, eff_HLT_PFMETNoMu120_PseudoCaloMET_MC, c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET, "HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60_pseudoCaloMET", "DATA/MC", "PseudoCaloMET [GeV]", 0, 1200);
    TCanvas *cRatio_HLT_MET105_IsoTrk50___PseudoCaloMET = DrawWithRatio(eff_HLT_MET105_PseudoCaloMET_DATA, eff_HLT_MET105_PseudoCaloMET_MC, c_HLT_MET105_IsoTrk50___PseudoCaloMET, "HLT_MET105_IsoTrk50_pseudoCaloMET", "DATA/MC", "PseudoCaloMET [GeV]", 0, 1200);
    TCanvas *cRatio_orMETtrg___PseudoCaloMET = DrawWithRatio(eff_orMETtrg_PseudoCaloMET_DATA, eff_orMETtrg_PseudoCaloMET_MC, c_orMETtrg___PseudoCaloMET, "orMETtrg_pseudoCaloMET", "DATA/MC", "PseudoCaloMET [GeV]", 0, 1200);
    
    TCanvas *cRatio_HLT_PFMET120_PFMHT120_IDTight___RecoPFMET = DrawWithRatio(eff_HLT_PFMET120_RecoPFMET_DATA, eff_HLT_PFMET120_RecoPFMET_MC, c_HLT_PFMET120_PFMHT120_IDTight___RecoPFMET, "HLT_PFMET120_PFMHT120_IDTight_pfMET", "DATA/MC", "RecoPFMET [GeV]", 0, 1200);
    TCanvas *cRatio_HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET = DrawWithRatio(eff_HLT_PFHT500_RecoPFMET_DATA, eff_HLT_PFHT500_RecoPFMET_MC, c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET, "HLT_PFHT500_PFMET100_PFMHT100_IDTight_pfMET", "DATA/MC", "RecoPFMET [GeV]", 0, 1200);
    TCanvas *cRatio_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET = DrawWithRatio(eff_HLT_PFMETNoMu120_RecoPFMET_DATA, eff_HLT_PFMETNoMu120_RecoPFMET_MC, c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET, "HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60_pfMET", "DATA/MC", "RecoPFMET [GeV]", 0, 1200);
    TCanvas *cRatio_HLT_MET105_IsoTrk50___RecoPFMET = DrawWithRatio(eff_HLT_MET105_RecoPFMET_DATA, eff_HLT_MET105_RecoPFMET_MC, c_HLT_MET105_IsoTrk50___RecoPFMET, "HLT_MET105_IsoTrk_pfMET", "DATA/MC", "RecoPFMET [GeV]", 0, 1200);
    TCanvas *cRatio_orMETtrg___RecoPFMET = DrawWithRatio(eff_orMETtrg_RecoPFMET_DATA, eff_orMETtrg_RecoPFMET_MC, c_orMETtrg___RecoPFMET, "orMETtrg_pfMET", "DATA/MC", "RecoPFMET [GeV]", 0, 1200);
    
    TCanvas *cRatio_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET__RecoPFMETCut = DrawWithRatio(eff_HLT_PFMET120_PseudoCaloMET__RecoPFMETCut_DATA, eff_HLT_PFMET120_PseudoCaloMET__RecoPFMETCut_MC, c_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET__RecoPFMETCut, "HLT_PFMET120_PFMHT120_IDTight_w/RecoPFMET>170GeV", "DATA/MC", "PseudoCaloMET [GeV]", 0, 1200);
    TCanvas *cRatio_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET__RecoPFMETCut = DrawWithRatio(eff_HLT_PFHT500_PseudoCaloMET__RecoPFMETCut_DATA, eff_HLT_PFHT500_PseudoCaloMET__RecoPFMETCut_MC, c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET__RecoPFMETCut, "HLT_PFHT500_PFMET100_PFMHT100_IDTight_w/RecoPFMET>170GeV", "DATA/MC", "PseudoCaloMET [GeV]", 0, 1200);
    TCanvas *cRatio_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET__RecoPFMETCut = DrawWithRatio(eff_HLT_PFMETNoMu120_PseudoCaloMET__RecoPFMETCut_DATA, eff_HLT_PFMETNoMu120_PseudoCaloMET__RecoPFMETCut_MC, c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET__RecoPFMETCut, "HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60_w/RecoPFMET>170GeV", "DATA/MC", "PseudoCaloMET [GeV]", 0, 1200);
    TCanvas *cRatio_HLT_MET105_IsoTrk50___PseudoCaloMET__RecoPFMETCut = DrawWithRatio(eff_HLT_MET105_PseudoCaloMET__RecoPFMETCut_DATA, eff_HLT_MET105_PseudoCaloMET__RecoPFMETCut_MC, c_HLT_MET105_IsoTrk50___PseudoCaloMET__RecoPFMETCut, "HLT_MET105_IsoTrk50_w/RecoPFMET>170GeV", "DATA/MC", "PseudoCaloMET [GeV]", 0, 1200);
    TCanvas *cRatio_orMETtrg___PseudoCaloMET__RecoPFMETCut = DrawWithRatio(eff_orMETtrg_PseudoCaloMET__RecoPFMETCut_DATA, eff_orMETtrg_PseudoCaloMET__RecoPFMETCut_MC, c_orMETtrg___PseudoCaloMET__RecoPFMETCut, "orMETtrg_w/RecoPFMET>170GeV", "DATA/MC", "PseudoCaloMET [GeV]", 0, 1200);

    TCanvas *cRatio_HLT_PFMET120_PFMHT120_IDTight___RecoPFMET__PseudoCaloMETCut = DrawWithRatio(eff_HLT_PFMET120_RecoPFMET__PseudoCaloMETCut_DATA, eff_HLT_PFMET120_RecoPFMET__PseudoCaloMETCut_MC, c_HLT_PFMET120_PFMHT120_IDTight___RecoPFMET__PseudoCaloMETCut, "HLT_PFMET120_PFMHT120_IDTight_w/PseudoCaloMET>170GeV", "DATA/MC", "RecoPFMET [GeV]", 0, 1200);
    TCanvas *cRatio_HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET__PseudoCaloMETCut = DrawWithRatio(eff_HLT_PFHT500_RecoPFMET__PseudoCaloMETCut_DATA, eff_HLT_PFHT500_RecoPFMET__PseudoCaloMETCut_MC, c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET__PseudoCaloMETCut, "HLT_PFHT500_PFMET100_PFMHT100_IDTight_w/PseudoCaloMET>170GeV", "DATA/MC", "RecoPFMET [GeV]", 0, 1200);
    TCanvas *cRatio_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET__PseudoCaloMETCut = DrawWithRatio(eff_HLT_PFMETNoMu120_RecoPFMET__PseudoCaloMETCut_DATA, eff_HLT_PFMETNoMu120_RecoPFMET__PseudoCaloMETCut_MC, c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET__PseudoCaloMETCut, "HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60_w/PseudoCaloMET>170GeV", "DATA/MC", "RecoPFMET [GeV]", 0, 1200);
    TCanvas *cRatio_HLT_MET105_IsoTrk50___RecoPFMET__PseudoCaloMETCut = DrawWithRatio(eff_HLT_MET105_RecoPFMET__PseudoCaloMETCut_DATA, eff_HLT_MET105_RecoPFMET__PseudoCaloMETCut_MC, c_HLT_MET105_IsoTrk50___RecoPFMET__PseudoCaloMETCut, "HLT_MET105_IsoTrk50_w/PseudoCaloMET>170GeV", "DATA/MC", "RecoPFMET [GeV]", 0, 1200);
    TCanvas *cRatio_orMETtrg___RecoPFMET__PseudoCaloMETCut = DrawWithRatio(eff_orMETtrg_RecoPFMET__PseudoCaloMETCut_DATA, eff_orMETtrg_RecoPFMET__PseudoCaloMETCut_MC, c_orMETtrg___RecoPFMET__PseudoCaloMETCut, "orMETtrg_w/PseudoCaloMET>170GeV", "DATA/MC", "RecoPFMET [GeV]", 0, 1200);


    // saving
    ofile->cd();
    cRatio_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET->Write();
    cRatio_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET->Write();
    cRatio_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET->Write();
    cRatio_HLT_MET105_IsoTrk50___PseudoCaloMET->Write();
    cRatio_orMETtrg___PseudoCaloMET->Write();
    
    cRatio_HLT_PFMET120_PFMHT120_IDTight___RecoPFMET->Write();
    cRatio_HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET->Write();
    cRatio_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET->Write();
    cRatio_HLT_MET105_IsoTrk50___RecoPFMET->Write();
    cRatio_orMETtrg___RecoPFMET->Write();
    
    cRatio_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET__RecoPFMETCut->Write();
    cRatio_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET__RecoPFMETCut->Write();
    cRatio_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET__RecoPFMETCut->Write();
    cRatio_HLT_MET105_IsoTrk50___PseudoCaloMET__RecoPFMETCut->Write();
    cRatio_orMETtrg___PseudoCaloMET__RecoPFMETCut->Write();

    cRatio_HLT_PFMET120_PFMHT120_IDTight___RecoPFMET__PseudoCaloMETCut->Write();
    cRatio_HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET__PseudoCaloMETCut->Write();
    cRatio_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET__PseudoCaloMETCut->Write();
    cRatio_HLT_MET105_IsoTrk50___RecoPFMET__PseudoCaloMETCut->Write();
    cRatio_orMETtrg___RecoPFMET__PseudoCaloMETCut->Write();
    ofile->Close();


    return;
}


void Comp_muonEG(const char *inputfileDATA, const char *inputfileMC) {

    TFile *ofile = new TFile("PlayWithHistos/Comp_muonEG.root", "RECREATE");

    TFile *ifileDATA = new TFile(Form("%s", inputfileDATA), "READ");
    TFile *ifileMC = new TFile(Form("%s", inputfileMC), "READ");
    // histograms
    TH1F *electron_pt_DATA = (TH1F*)ifileDATA->Get("CalibPseudoMET_electron_pt");
    TH1F *electron_eta_DATA = (TH1F*)ifileDATA->Get("CalibPseudoMET_electron_eta");
    TH1F *electron_phi_DATA = (TH1F*)ifileDATA->Get("CalibPseudoMET_electron_phi");
    TH1F *muon_pt_DATA = (TH1F*)ifileDATA->Get("CalibPseudoMET_muon_pt");
    TH1F *muon_eta_DATA = (TH1F*)ifileDATA->Get("CalibPseudoMET_muon_eta");
    TH1F *muon_phi_DATA = (TH1F*)ifileDATA->Get("CalibPseudoMET_muon_phi");    
    TH1F *PseudoCaloMET_DATA = (TH1F*)ifileDATA->Get("CalibPseudoMET_PseudoCaloMET");
    TH1F *RecoPFMET_DATA = (TH1F*)ifileDATA->Get("CalibPseudoMET_RecoPFMET");
    TH1F *L1MET_DATA = (TH1F*)ifileDATA->Get("CalibPseudoMET_L1MET");
    TH1F *HLTCaloMET_DATA = (TH1F*)ifileDATA->Get("CalibPseudoMET_HLTCaloMET");
    TH1F *HLTCaloMHT_DATA = (TH1F*)ifileDATA->Get("CalibPseudoMET_HLTCaloMHT");
    TH1F *HLTPFMHT_DATA = (TH1F*)ifileDATA->Get("CalibPseudoMET_HLTPFMHT");
    TH1F *HLTPFMET_DATA = (TH1F*)ifileDATA->Get("CalibPseudoMET_HLTPFMET");

    TH1F *electron_pt_MC = (TH1F*)ifileMC->Get("CalibPseudoMET_electron_pt");
    TH1F *electron_eta_MC = (TH1F*)ifileMC->Get("CalibPseudoMET_electron_eta");
    TH1F *electron_phi_MC = (TH1F*)ifileMC->Get("CalibPseudoMET_electron_phi");
    TH1F *muon_pt_MC = (TH1F*)ifileMC->Get("CalibPseudoMET_muon_pt");
    TH1F *muon_eta_MC = (TH1F*)ifileMC->Get("CalibPseudoMET_muon_eta");
    TH1F *muon_phi_MC = (TH1F*)ifileMC->Get("CalibPseudoMET_muon_phi");
    TH1F *PseudoCaloMET_MC = (TH1F*)ifileMC->Get("CalibPseudoMET_PseudoCaloMET");
    TH1F *RecoPFMET_MC = (TH1F*)ifileMC->Get("CalibPseudoMET_RecoPFMET");
    TH1F *L1MET_MC = (TH1F*)ifileMC->Get("CalibPseudoMET_L1MET");
    TH1F *HLTCaloMET_MC = (TH1F*)ifileMC->Get("CalibPseudoMET_HLTCaloMET");
    TH1F *HLTCaloMHT_MC = (TH1F*)ifileMC->Get("CalibPseudoMET_HLTCaloMHT");
    TH1F *HLTPFMHT_MC = (TH1F*)ifileMC->Get("CalibPseudoMET_HLTPFMHT");
    TH1F *HLTPFMET_MC = (TH1F*)ifileMC->Get("CalibPseudoMET_HLTPFMET");


    // scale
    electron_pt_DATA->Scale(1./electron_pt_DATA->Integral());
    electron_eta_DATA->Scale(1./electron_eta_DATA->Integral());
    electron_phi_DATA->Scale(1./electron_phi_DATA->Integral());
    muon_pt_DATA->Scale(1./muon_pt_DATA->Integral());
    muon_eta_DATA->Scale(1./muon_eta_DATA->Integral());
    muon_phi_DATA->Scale(1./muon_phi_DATA->Integral());
    PseudoCaloMET_DATA->Scale(1./PseudoCaloMET_DATA->Integral());
    RecoPFMET_DATA->Scale(1./RecoPFMET_DATA->Integral());
    L1MET_DATA->Scale(1./L1MET_DATA->Integral());
    HLTCaloMET_DATA->Scale(1./HLTCaloMET_DATA->Integral());
    HLTCaloMHT_DATA->Scale(1./HLTCaloMHT_DATA->Integral());
    HLTPFMHT_DATA->Scale(1./HLTPFMHT_DATA->Integral());
    HLTPFMET_DATA->Scale(1./HLTPFMET_DATA->Integral());

    electron_pt_MC->Scale(1./electron_pt_MC->Integral());
    electron_eta_MC->Scale(1./electron_eta_MC->Integral());
    electron_phi_MC->Scale(1./electron_phi_MC->Integral());
    muon_pt_MC->Scale(1./muon_pt_MC->Integral());
    muon_eta_MC->Scale(1./muon_eta_MC->Integral());
    muon_phi_MC->Scale(1./muon_phi_MC->Integral());
    PseudoCaloMET_MC->Scale(1./PseudoCaloMET_MC->Integral());
    RecoPFMET_MC->Scale(1./RecoPFMET_MC->Integral());
    L1MET_MC->Scale(1./L1MET_MC->Integral());
    HLTCaloMET_MC->Scale(1./HLTCaloMET_MC->Integral());
    HLTCaloMHT_MC->Scale(1./HLTCaloMHT_MC->Integral());
    HLTPFMHT_MC->Scale(1./HLTPFMHT_MC->Integral());
    HLTPFMET_MC->Scale(1./HLTPFMET_MC->Integral());


    // rebin
    muon_pt_DATA->Rebin(4);
    muon_pt_MC->Rebin(4);
    electron_pt_DATA->Rebin(4);
    electron_pt_MC->Rebin(4);

    // canvas 
    TCanvas *c_electron_pt = DrawCanvas(electron_pt_DATA, electron_pt_MC, "c_electron_pt", "Electron p_{T} [GeV]", "Number of tracks (normalized)",
    "E1", "HIST same", true, "DATA", "MC", "lep", "f", 0, 600, 0, -1, true, true);
    TCanvas *c_electron_eta = DrawCanvas(electron_eta_DATA, electron_eta_MC, "c_electron_eta", "Electron #eta", "Number of tracks (normalized)",
    "E1", "HIST same", true, "DATA", "MC", "lep", "f", -3.2, 3.2, 0, -1, false, true);
    TCanvas *c_electron_phi = DrawCanvas(electron_phi_DATA, electron_phi_MC, "c_electron_phi", "Electron #phi", "Number of tracks (normalized)",
    "E1", "HIST same", true, "DATA", "MC", "lep", "f", -3.2, 3.2, 0, -1, false, true);

    TCanvas *c_muon_pt = DrawCanvas(muon_pt_DATA, muon_pt_MC, "c_muon_pt", "Muon p_{T} [GeV]", "Number of tracks (normalized)",
    "E1", "HIST same", true, "DATA", "MC", "lep", "f", 0, 600, 0, -1, true, true);
    TCanvas *c_muon_eta = DrawCanvas(muon_eta_DATA, muon_eta_MC, "c_muon_eta", "Muon #eta", "Number of tracks (normalized)",
    "E1", "HIST same", true, "DATA", "MC", "lep", "f", -3.2, 3.2, 0, -1, false, true);
    TCanvas *c_muon_phi = DrawCanvas(muon_phi_DATA, muon_phi_MC, "c_muon_phi", "Muon #phi", "Number of tracks (normalized)",
    "E1", "HIST same", true, "DATA", "MC", "lep", "f", -3.2, 3.2, 0, -1, false, true);

    TCanvas *c_PseudoCaloMET = DrawCanvas(PseudoCaloMET_DATA, PseudoCaloMET_MC, "c_PseudoCaloMET", "PseudoCaloMET [GeV]", "Number of events (normalized)",
    "E1", "HIST same", true, "DATA", "MC", "lep", "f", 0, 1000, 0, -1, true, true);
    TCanvas *c_RecoPFMET = DrawCanvas(RecoPFMET_DATA, RecoPFMET_MC, "c_RecoPFMET", "RecoPFMET [GeV]", "Number of events (normalized)",
    "E1", "HIST same", true, "DATA", "MC", "lep", "f", 0, 1000, 0, -1, true, true);
    TCanvas *c_L1MET = DrawCanvas(L1MET_DATA, L1MET_MC, "c_L1MET", "L1MET [GeV]", "Number of events (normalized)",
    "E1", "HIST same", true, "DATA", "MC", "lep", "f", 0, 1000, 0, -1, true, true);
    TCanvas *c_HLTCaloMET = DrawCanvas(HLTCaloMET_DATA, HLTCaloMET_MC, "c_HLTCaloMET", "HLTCaloMET [GeV]", "Number of events (normalized)",
    "E1", "HIST same", true, "DATA", "MC", "lep", "f", 0, 1000, 0, -1, true, true);
    TCanvas *c_HLTCaloMHT = DrawCanvas(HLTCaloMHT_DATA, HLTCaloMHT_MC, "c_HLTCaloMHT", "HLTCaloMHT [GeV]", "Number of events (normalized)",
    "E1", "HIST same", true, "DATA", "MC", "lep", "f", 0, 1000, 0, -1, true, true);
    TCanvas *c_HLTPFMHT = DrawCanvas(HLTPFMHT_DATA, HLTPFMHT_MC, "c_HLTPFMHT", "HLTPFMHT [GeV]", "Number of events (normalized)",
    "E1", "HIST same", true, "DATA", "MC", "lep", "f", 0, 1000, 0, -1, true, true);
    TCanvas *c_HLTPFMET = DrawCanvas(HLTPFMET_DATA, HLTPFMET_MC, "c_HLTPFMET", "HLTPFMET [GeV]", "Number of events (normalized)",
    "E1", "HIST same", true, "DATA", "MC", "lep", "f", 0, 1000, 0, -1, true, true);


    //draw with ratio
    TCanvas *c_RATIO_electron_pt = DrawWithRatio(electron_pt_DATA, electron_pt_MC, c_electron_pt, "Electron_pT", "DATA/MC", "Electron p_{T}", 0, 600);
    TCanvas *c_RATIO_electron_eta = DrawWithRatio(electron_eta_DATA, electron_eta_MC, c_electron_eta, "Electron_Eta", "DATA/MC", "Electron #eta", -3.2, 3.2);
    TCanvas *c_RATIO_electron_phi = DrawWithRatio(electron_phi_DATA, electron_phi_MC, c_electron_phi, "Electron_Phi", "DATA/MC", "Electron #phi", -3.2, 3.2);

    TCanvas *c_RATIO_muon_pt = DrawWithRatio(muon_pt_DATA, muon_pt_MC, c_muon_pt, "Muon_pT", "DATA/MC", "Muon p_{T}", 0, 600);
    TCanvas *c_RATIO_muon_eta = DrawWithRatio(muon_eta_DATA, muon_eta_MC, c_muon_eta, "Muon_Eta", "DATA/MC", "Muon #eta", -3.2, 3.2);
    TCanvas *c_RATIO_muon_phi = DrawWithRatio(muon_phi_DATA, muon_phi_MC, c_muon_phi, "Muon_Phi", "DATA/MC", "Muon #phi", -3.2, 3.2);

    TCanvas *c_RATIO_PseudoCaloMET = DrawWithRatio(PseudoCaloMET_DATA, PseudoCaloMET_MC, c_PseudoCaloMET, "PseudoCaloMET", "DATA/MC", "PseudoCaloMET [GeV]", 0, 1000);
    TCanvas *c_RATIO_RecoPFMET = DrawWithRatio(RecoPFMET_DATA, RecoPFMET_MC, c_RecoPFMET, "RecoPFMET", "DATA/MC", "RecoPFMET [GeV]", 0, 1000);
    TCanvas *c_RATIO_L1MET = DrawWithRatio(L1MET_DATA, L1MET_MC, c_L1MET, "L1MET", "DATA/MC", "L1MET [GeV]", 0, 1000);
    TCanvas *c_RATIO_HLTCaloMET = DrawWithRatio(HLTCaloMET_DATA, HLTCaloMET_MC, c_HLTCaloMET, "HLTCaloMET", "DATA/MC", "HLTCaloMET [GeV]", 0, 1000);
    TCanvas *c_RATIO_HLTCaloMHT = DrawWithRatio(HLTCaloMHT_DATA, HLTCaloMHT_MC, c_HLTCaloMHT, "HLTCaloMHT", "DATA/MC", "HLTCaloMHT [GeV]", 0, 1000);
    TCanvas *c_RATIO_HLTPFMHT = DrawWithRatio(HLTPFMHT_DATA, HLTPFMHT_MC, c_HLTPFMHT, "HLTPFMHT", "DATA/MC", "HLTPFMHT [GeV]", 0, 1000);
    TCanvas *c_RATIO_HLTPFMET = DrawWithRatio(HLTPFMET_DATA, HLTPFMET_MC, c_HLTPFMET, "HLTPFMET", "DATA/MC", "HLTPFMET [GeV]", 0, 1000);


    // saving
    ofile->cd();
    c_RATIO_electron_pt->Write();
    c_RATIO_electron_eta->Write();
    c_RATIO_electron_phi->Write();

    c_RATIO_muon_pt->Write();
    c_RATIO_muon_eta->Write();
    c_RATIO_muon_phi->Write();

    c_RATIO_PseudoCaloMET->Write();
    c_RATIO_RecoPFMET->Write();
    c_RATIO_L1MET->Write();
    c_RATIO_HLTCaloMET->Write();
    c_RATIO_HLTCaloMHT->Write();
    c_RATIO_HLTPFMHT->Write();
    c_RATIO_HLTPFMET->Write();
    ofile->Close();

    return;
}


void Old_vs_New_fits(const char *inputfile) {

    TFile *ofile = new TFile("PlayWithHistos/Old_vs_New_fits.root", "RECREATE");
    TFile *ifile = new TFile(Form("%s", inputfile), "READ");

    // histograms
    TH1F* Ih = (TH1F*)ifile->Get("METanalysis_Eta2p4_Ih");
    TH1F* oP = (TH1F*)ifile->Get("METanalysis_Eta2p4_10000oP");

    TH1F* Ih_new = (TH1F*)Ih->Clone("Ih_new");
    TH1F* oP_new = (TH1F*)oP->Clone("oP_new");


    // 1oP fit
    float rangemax_p = 30;
    if (oP->GetBinCenter(oP->GetMaximumBin()) < rangemax_p) rangemax_p = 0.8 * oP->GetBinCenter(oP->GetMaximumBin());
    TF1 f_p_old("f_p_old","[0]*([1]+erf((log(x)-[2])/[3]))",0,rangemax_p);
    f_p_old.SetParameter(0,560);
    f_p_old.FixParameter(1,1.0);
    f_p_old.SetParameter(2,3.50116e+00);
    f_p_old.SetParameter(3,0.60152e+00);
    oP->Fit(&f_p_old,"RL","",0,rangemax_p);

    TF1 f_p_new("f_p_new", "0.5*(exp([0]*x*x+[1]*x)+exp(-[0]*x*x-[1]*x))-1", 0, rangemax_p);
    float end1oPFit = 0.4 * oP->GetBinCenter(oP->GetMaximumBin());
    if (end1oPFit > 25) end1oPFit = 25;
    oP_new->Fit(&f_p_new, "R", "", 0, end1oPFit);

    // Ih fit
    float max_ih = Ih_new->GetBinCenter(Ih_new->GetMaximumBin());
    TF1 f_ih_old("f_ih_old", "gaus", 3, 8);
    f_ih_old.SetParameter(0, 0.5*Ih->Integral());
    f_ih_old.SetParameter(1, max_ih);
    f_ih_old.SetParameter(2, Ih->GetStdDev());
    Ih->Fit(&f_ih_old, "RL", "", 3, 8);

    float start_fit = 1.2*max_ih;
    int lastBinContent = Ih->GetNbinsX();
    while(Ih->GetBinContent(lastBinContent)==0) lastBinContent--;
    if(start_fit > Ih->GetBinCenter(lastBinContent)) start_fit = max_ih;
    TF1 f_ih_new("f_ih_new", "gaus", start_fit, 6);
    f_ih_new.SetParameter(0, 0.5*Ih->Integral());
    f_ih_new.SetParameter(1, max_ih);
    f_ih_new.SetParameter(2, Ih->GetStdDev());
    Ih_new->Fit(&f_ih_new, "RL", "", start_fit, 6);


    TCanvas *cIhold = DrawCanvas(Ih, "Ih old fit", "Ih [MeV/cm]", "Number of tracks", "E1", 0, 10, 0, -1, false);
    TCanvas *coPold = DrawCanvas(oP, "oP old fit", "10^{4}/p [GeV^{-1}]", "Number of tracks", "E1", 0, 200, 0, -1, false);
    TCanvas *cIhnew = DrawCanvas(Ih_new, "Ih new fit", "Ih [MeV/cm]", "Number of tracks", "E1", 0, 10, 0, -1, false);
    TCanvas *coPnew = DrawCanvas(oP_new, "oP new fit", "10^{4}/p [GeV^{-1}]", "Number of tracks", "E1", 0, 200, 0, -1, false);

    ofile->cd();
    cIhold->Write();
    coPold->Write();
    cIhnew->Write();
    coPnew->Write();
    ofile->Close();


    return;
}


void BKGdependency(const char *inputname, const char *ofilename) {

    TFile *ofile = new TFile(Form("PlayWithHistos/BKGdependency_%s.root", ofilename), "RECREATE");
    TFile *ifile = new TFile(Form("%s", inputname), "READ");

    TH2F *pT_vs_fpix = (TH2F*)ifile->Get("METanalysis_Eta2p4_pT_vs_Fpixel");

    TH2F *ih_vs_eta_A3fp9 = (TH2F*)ifile->Get("ih_eta_regionA_3fp9_METanalysis_Eta2p4");
    TH2F *ih_vs_eta_A9fp10 = (TH2F*)ifile->Get("ih_eta_regionA_9fp10_METanalysis_Eta2p4");
    TH2F *ih_vs_eta_D3fp8 = (TH2F*)ifile->Get("ih_eta_regionD_3fp8_METanalysis_Eta2p4");
    TH2F *ih_vs_eta_D8fp9 = (TH2F*)ifile->Get("ih_eta_regionD_8fp9_METanalysis_Eta2p4");
    TH2F *ih_vs_eta_D9fp10 = (TH2F*)ifile->Get("ih_eta_regionD_9fp10_METanalysis_Eta2p4");

    TH2F *fpix_vs_ih_A3fp9 = (TH2F*)ifile->Get("fpix_ih_regionA_3fp9_METanalysis_Eta2p4");
    TH2F *fpix_vs_ih_A9fp10 = (TH2F*)ifile->Get("fpix_ih_regionA_9fp10_METanalysis_Eta2p4");
    TH2F *fpix_vs_ih_D3fp8 = (TH2F*)ifile->Get("fpix_ih_regionD_3fp8_METanalysis_Eta2p4");
    TH2F *fpix_vs_ih_D8fp9 = (TH2F*)ifile->Get("fpix_ih_regionD_8fp9_METanalysis_Eta2p4");
    TH2F *fpix_vs_ih_D9fp10 = (TH2F*)ifile->Get("fpix_ih_regionD_9fp10_METanalysis_Eta2p4");

    TH2F *oP_vs_fpix_A3fp9 = (TH2F*)ifile->Get("oP_fpix_regionA_3fp9_METanalysis_Eta2p4");
    TH2F *oP_vs_fpix_A9fp10 = (TH2F*)ifile->Get("oP_fpix_regionA_9fp10_METanalysis_Eta2p4");
    TH2F *oP_vs_fpix_D3fp8 = (TH2F*)ifile->Get("oP_fpix_regionD_3fp8_METanalysis_Eta2p4");
    TH2F *oP_vs_fpix_D8fp9 = (TH2F*)ifile->Get("oP_fpix_regionD_8fp9_METanalysis_Eta2p4");
    TH2F *oP_vs_fpix_D9fp10 = (TH2F*)ifile->Get("oP_fpix_regionD_9fp10_METanalysis_Eta2p4");

    // add the histograms together
    TH2F *ih_vs_eta = (TH2F*)ih_vs_eta_A3fp9->Clone("ih_vs_eta");
    ih_vs_eta->Add(ih_vs_eta_A9fp10);
    ih_vs_eta->Add(ih_vs_eta_D3fp8);
    ih_vs_eta->Add(ih_vs_eta_D8fp9);
    if (strstr(inputname, "TTbar") != nullptr || strstr(inputname, "Wjets") != nullptr || || strstr(inputname, "QCD") != nullptr) ih_vs_eta->Add(ih_vs_eta_D9fp10);
    ih_vs_eta->RebinX(4);

    TH2F *fpix_vs_ih = (TH2F*)fpix_vs_ih_A3fp9->Clone("fpix_vs_ih");
    fpix_vs_ih->Add(fpix_vs_ih_A9fp10);
    fpix_vs_ih->Add(fpix_vs_ih_D3fp8);
    fpix_vs_ih->Add(fpix_vs_ih_D8fp9);
    if (strstr(inputname, "TTbar") != nullptr || strstr(inputname, "Wjets") != nullptr || || strstr(inputname, "QCD") != nullptr) fpix_vs_ih->Add(fpix_vs_ih_D9fp10);

    TH2F *oP_vs_fpix = (TH2F*)oP_vs_fpix_A3fp9->Clone("oP_vs_fpix");
    oP_vs_fpix->Add(oP_vs_fpix_A9fp10);
    oP_vs_fpix->Add(oP_vs_fpix_D3fp8);
    oP_vs_fpix->Add(oP_vs_fpix_D8fp9);
    if (strstr(inputname, "TTbar") != nullptr || strstr(inputname, "Wjets") != nullptr || || strstr(inputname, "QCD") != nullptr) oP_vs_fpix->Add(oP_vs_fpix_D9fp10);
    TH2F *fpix_vs_oP = TransposeTH2(oP_vs_fpix);

    // plot the profile
    TProfile *profile_ih_vs_eta = ih_vs_eta->ProfileX("profile_ih_vs_eta");
    TProfile *profile_fpix_vs_ih = fpix_vs_ih->ProfileX("profile_fpix_vs_ih");
    TProfile *profile_fpix_vs_oP = fpix_vs_oP->ProfileX("profile_fpix_vs_oP");
    TProfile *profile_pT_vs_fpix = pT_vs_fpix->ProfileX("profile_pT_vs_fpix");

    TCanvas *c_ih_vs_eta = new TCanvas("c_ih_vs_eta", "c_ih_vs_eta", 800, 600);
    ih_vs_eta->GetXaxis()->SetTitle("#eta");
    ih_vs_eta->GetYaxis()->SetTitle("I_{h} [MeV/cm]");
    ih_vs_eta->Draw("COLZ");
    profile_ih_vs_eta->SetMarkerStyle(20);
    profile_ih_vs_eta->SetMarkerColor(kRed);
    profile_ih_vs_eta->SetLineColor(kRed);
    profile_ih_vs_eta->Draw("sameP");

    TCanvas *c_fpix_vs_ih = new TCanvas("c_fpix_vs_ih", "c_fpix_vs_ih", 800, 600);
    fpix_vs_ih->GetXaxis()->SetTitle("F_{pixel}");
    fpix_vs_ih->GetYaxis()->SetTitle("I_{h} [MeV/cm]");
    fpix_vs_ih->Draw("COLZ");
    profile_fpix_vs_ih->SetMarkerStyle(20);
    profile_fpix_vs_ih->SetMarkerColor(kRed);
    profile_fpix_vs_ih->SetLineColor(kRed);
    profile_fpix_vs_ih->Draw("sameP");

    TCanvas *c_oP_vs_fpix = new TCanvas("c_oP_vs_fpix", "c_oP_vs_fpix", 800, 600);
    fpix_vs_oP->GetXaxis()->SetTitle("F_{pixel}");
    fpix_vs_oP->GetYaxis()->SetTitle("10^{4}/p [GeV^{-1}]");
    fpix_vs_oP->Draw("COLZ");
    profile_fpix_vs_oP->SetMarkerStyle(20);
    profile_fpix_vs_oP->SetMarkerColor(kRed);
    profile_fpix_vs_oP->SetLineColor(kRed);
    profile_fpix_vs_oP->Draw("sameP");

    TCanvas *c_pT_vs_fpix = new TCanvas("c_pT_vs_fpix", "c_pT_vs_fpix", 800, 600);
    pT_vs_fpix->GetXaxis()->SetTitle("F_{pixel}");
    pT_vs_fpix->GetYaxis()->SetTitle("p_{T} [GeV]");
    pT_vs_fpix->Draw("COLZ");
    profile_pT_vs_fpix->SetMarkerStyle(20);
    profile_pT_vs_fpix->SetMarkerColor(kRed);
    profile_pT_vs_fpix->SetLineColor(kRed);
    profile_pT_vs_fpix->Draw("sameP");




    ofile->cd();
    c_ih_vs_eta->Write();
    c_fpix_vs_ih->Write();
    c_oP_vs_fpix->Write();
    c_pT_vs_fpix->Write();
    ofile->Close();

    return;
}

void GluinoP_mass(bool isPythia) {

    TFile *ofile = new TFile(Form("PlayWithHistos/GluinoP_mass_%s.root", isPythia ? "pythia" : "madgraph"), "RECREATE");

    // create a std::vector of ifile where to retrieve the pT vs Fpixel histograms in each:
    std::vector<TFile*> ifiles;
    std::vector<TString> labels;
    if (isPythia) labels = {"1000", "1200", "1400", "1600", "1800", "2000", "2200", "2400", "2600"};
    else labels = {"1100", "1200", "1300", "1400", "1600", "1800", "2000", "2200", "2400", "2600"};

    for (unsigned int i=0; i<labels.size(); i++) ifiles.push_back(new TFile(Form("../output/Gluino_V19/Gluino_Run3_MET_%s%s_V19p%s.root", isPythia ? "" : "madgraph_", labels[i].Data(), isPythia ? "0" : "1"), "READ"));

    // retrieve the p histogram and plot on the same canvas with different color (+legend)
    TCanvas *c_p = new TCanvas("c_p", "c_p", 800, 600);
    TLegend *legend = new TLegend(0.7, 0.5, 0.85, 0.9);
    for (size_t i = 0; i < ifiles.size(); i++) {
        TH1F *p = (TH1F*)ifiles[i]->Get("METanalysis_Eta2p4_P");
        p->SetLineColor(kOrange+i);
        p->SetLineWidth(2);
        if (i == 0) p->Draw("HIST");
        else p->Draw("HIST same");
        legend->AddEntry(p, Form("#tilde{g} m=%s",labels[i].Data()), "l");
    }
    legend->Draw();
    legend->SetBorderSize(0);
    legend->SetFillStyle(0);
    c_p->SetLogy();

    // retrieve the pT vs Fpixel histograms, sum all the TH2 together and plot it
    TH2F *pT_vs_Fpixel_sum = nullptr;
    float fpix_cut = 0.7;
    std::vector <TH1D*> pT_distributions;
    std::vector <TH1D*> pT_distributions_Fpix_cut;
    std::vector <TH1D*> Fpixel_distributions;
    for (size_t i = 0; i < ifiles.size(); i++) {
        TH2F *pT_vs_Fpixel = (TH2F*)ifiles[i]->Get("METanalysis_Eta2p4_pT_vs_Fpixel");

        int nEntries_CR = 0;
        for (int xbin = 1; xbin <= pT_vs_Fpixel->GetNbinsX(); xbin++) {
            for (int ybin = 1; ybin <= pT_vs_Fpixel->GetNbinsY(); ybin++) {
                if (pT_vs_Fpixel->GetXaxis()->GetBinCenter(xbin) <= fpix_cut || pT_vs_Fpixel->GetYaxis()->GetBinCenter(ybin) <= 70) {
                    nEntries_CR += pT_vs_Fpixel->GetBinContent(xbin, ybin);
                }
            }
        }
        cout << "Number of entries in the CR (pT<=70 and Fpix<=" << fpix_cut << ") for m=" << labels[i].Data() << ": " << nEntries_CR << " / " << pT_vs_Fpixel->GetEntries() << " (" << 100.0*nEntries_CR/pT_vs_Fpixel->GetEntries() << "%)" << endl;

        TH1D *proj_pT = pT_vs_Fpixel->ProjectionY(Form("pT_%s", labels[i].Data()));
        TH1D *proj_Fpixel = pT_vs_Fpixel->ProjectionX(Form("Fpixel_%s", labels[i].Data()));
        pT_distributions.push_back(proj_pT);
        Fpixel_distributions.push_back(proj_Fpixel);

        // do the proj of pT but with a Fpix cut on the TH2 before
        TH1D *proj_pT_Fpix_cut = new TH1D(Form("pT_%s_Fpix_cut", labels[i].Data()), Form("pT_%s_Fpix_cut", labels[i].Data()), pT_vs_Fpixel->GetYaxis()->GetNbins(), pT_vs_Fpixel->GetYaxis()->GetXmin(), pT_vs_Fpixel->GetYaxis()->GetXmax());
        for (int xbin = 1; xbin <= pT_vs_Fpixel->GetNbinsX(); xbin++) {
            for (int ybin = 1; ybin <= pT_vs_Fpixel->GetNbinsY(); ybin++) {
                if (pT_vs_Fpixel->GetXaxis()->GetBinCenter(xbin) <= fpix_cut) {
                    proj_pT_Fpix_cut->Fill(pT_vs_Fpixel->GetYaxis()->GetBinCenter(ybin), pT_vs_Fpixel->GetBinContent(xbin, ybin));
                }
            }
        }
        pT_distributions_Fpix_cut.push_back(proj_pT_Fpix_cut);


        if (pT_vs_Fpixel_sum == nullptr) pT_vs_Fpixel_sum = (TH2F*)pT_vs_Fpixel->Clone("pT_vs_Fpixel_sum");
        else pT_vs_Fpixel_sum->Add(pT_vs_Fpixel);
    }
    TCanvas *c_pT_vs_Fpixel = new TCanvas("c_pT_vs_Fpixel", "c_pT_vs_Fpixel", 800, 600);
    pT_vs_Fpixel_sum->GetXaxis()->SetTitle("F_{pixel}");
    pT_vs_Fpixel_sum->GetYaxis()->SetTitle("p_{T} [GeV]");
    pT_vs_Fpixel_sum->Draw("COLZ");
    c_pT_vs_Fpixel->SetLogz();

    int nEntries_CR = 0;
    for (int xbin = 1; xbin <= pT_vs_Fpixel_sum->GetNbinsX(); xbin++) {
        for (int ybin = 1; ybin <= pT_vs_Fpixel_sum->GetNbinsY(); ybin++) {
            if (pT_vs_Fpixel_sum->GetXaxis()->GetBinCenter(xbin) <= fpix_cut || pT_vs_Fpixel_sum->GetYaxis()->GetBinCenter(ybin) <= 70) {
                nEntries_CR += pT_vs_Fpixel_sum->GetBinContent(xbin, ybin);
            }
        }
    }
    cout << "Number of entries in the CR (pT<=70 and Fpix<=" << fpix_cut << ") (TOTAL): " << nEntries_CR << " / " << pT_vs_Fpixel_sum->GetEntries() << " (" << 100.0*nEntries_CR/pT_vs_Fpixel_sum->GetEntries() << "%)" << endl;

    // plot pT_distributions on the same canvas with different color (+legend)
    TCanvas *c_pT = new TCanvas("c_pT", "c_pT", 800, 600);
    TLegend *legend_pT = new TLegend(0.7, 0.5, 0.85, 0.9);
    for (size_t i = 0; i < pT_distributions.size(); i++) {
        pT_distributions[i]->SetLineColor(kOrange+i);
        pT_distributions[i]->SetLineWidth(2);
        if (i == 0) pT_distributions[i]->Draw("HIST");
        else pT_distributions[i]->Draw("HIST same");
        legend_pT->AddEntry(pT_distributions[i], Form("#tilde{g} m=%s",labels[i].Data()), "l");
    }
    legend_pT->Draw();
    legend_pT->SetBorderSize(0);
    legend_pT->SetFillStyle(0);

    // plot Fpixel_distributions on the same canvas with different color (+legend)
    TCanvas *c_Fpixel = new TCanvas("c_Fpixel", "c_Fpixel", 800, 600);
    TLegend *legend_Fpixel = new TLegend(0.7, 0.5, 0.85, 0.9);
    for (size_t i = 0; i < Fpixel_distributions.size(); i++) {
        Fpixel_distributions[i]->SetLineColor(kOrange+i);
        Fpixel_distributions[i]->SetLineWidth(2);
        if (i == 0) Fpixel_distributions[i]->Draw("HIST");
        else Fpixel_distributions[i]->Draw("HIST same");
        legend_Fpixel->AddEntry(Fpixel_distributions[i], Form("#tilde{g} m=%s",labels[i].Data()), "l");
    }
    legend_Fpixel->Draw();
    legend_Fpixel->SetBorderSize(0);
    legend_Fpixel->SetFillStyle(0);

    TCanvas *c_pT2 = new TCanvas("c_pT2", "c_pT2", 800, 600);
    for (size_t i = 0; i < pT_distributions_Fpix_cut.size(); i++) {
        pT_distributions_Fpix_cut[i]->SetLineColor(kOrange+i);
        pT_distributions_Fpix_cut[i]->SetLineWidth(2);
        if (i == 0) pT_distributions_Fpix_cut[i]->Draw("HIST");
        else pT_distributions_Fpix_cut[i]->Draw("HIST same");
    }
    legend_pT->Draw();



    ofile->cd();
    c_p->Write();
    pT_vs_Fpixel_sum->Write();
    c_pT->Write();
    c_Fpixel->Write();
    c_pT2->Write();
    ofile->Close();

}


void CompareMaping() {

    TFile *ofile = new TFile("PlayWithHistos/CompareMapping.root", "RECREATE");

    TFile *ifileTTbar2024 = new TFile("../output/TTbar2024_V15/TTbar2024_V15p5_weighted.root", "READ");
    TFile *ifileWjets2024 = new TFile("../output/Wjets2024_V14/Wjets2024_V14p6_weighted.root", "READ");
    TFile *ifileQCD2024 = new TFile("../output/QCD2024_V16/QCD2024_mu_V16p1_weighted.root", "READ");
    TFile *GluinoRun3madgraph = new TFile("PlayWithHistos/GluinoP_mass_madgraph.root", "READ");


    // load histograms
    TH2F *pT_vs_fpix_ttbar = (TH2F*)ifileTTbar2024->Get("METanalysis_Eta2p4_pT_vs_Fpixel");
    TH2F *pT_vs_fpix_wjets = (TH2F*)ifileWjets2024->Get("METanalysis_Eta2p4_pT_vs_Fpixel");
    TH2F *pT_vs_fpix_qcd = (TH2F*)ifileQCD2024->Get("METanalysis_Eta2p4_pT_vs_Fpixel");
    TH2F *pT_vs_fpix_gluino = (TH2F*)GluinoRun3madgraph->Get("pT_vs_Fpixel_sum");

    // sum the MC backgrounds together
    TH2F *pT_vs_fpix_bkg = (TH2F*)pT_vs_fpix_ttbar->Clone("pT_vs_fpix_bkg");
    pT_vs_fpix_bkg->Add(pT_vs_fpix_wjets);
    pT_vs_fpix_bkg->Add(pT_vs_fpix_qcd);

    // divide the gluino histogram by the bkg histogram to see where the signal is enhanced
    TH2F *pT_vs_fpix_ratio = (TH2F*)pT_vs_fpix_gluino->Clone("pT_vs_fpix_ratio");
    pT_vs_fpix_ratio->Divide(pT_vs_fpix_bkg);

    // canvas of the ratio
    TCanvas *c_ratio = new TCanvas("c_ratio", "c_ratio", 800, 600);
    pT_vs_fpix_ratio->GetXaxis()->SetTitle("F_{pixel}");
    pT_vs_fpix_ratio->GetYaxis()->SetTitle("p_{T} [GeV]");
    pT_vs_fpix_ratio->Draw("COLZ");

    Tcanvas *c_bkg_gluino = new TCanvas("c_bkg_gluino", "c_bkg_gluino", 800, 600);
    pT_vs_fpix_bkg->GetXaxis()->SetTitle("F_{pixel}");
    pT_vs_fpix_bkg->GetYaxis()->SetTitle("p_{T} [GeV]");
    pT_vs_fpix_bkg->Draw("COLZ");
    pT_vs_fpix_gluino->SetLineColor(kRed);
    pT_vs_fpix_gluino->Draw("COLZ same");

    ofile->cd();
    c_ratio->Write();
    c_bkg_gluino->Write();
    ofile->Close();

    return;
}


void CombineHistos()
{
    //MET_trg_eff("../output/Gluino2000_Run2_METtrgEff_V11p15_Eta2p4.root", false);
    //MET_trg_eff("../output/Gluino2000_Run2_METtrgEff_AOD_V11p15_Eta2p4.root", true);
    MET_trg_eff("../output/Gluino_V19/Gluino_Run3_MET_2000_V19p0.root", false);
    //PFMET_Cut(false);
    //TrigEff_AODvsMiniAOD();

    //Cutflows("../output/Gluino2000_AOD_FULL_Mu50_V11p11_Eta2p4.root", "../output/Gluino2000_miniAOD_FULL_Mu50_V11p11_Eta2p4.root", true, false);
    //Cutflows("../output/Gluino2000_AOD_FULL_Mu50_V11p11_Eta2p4.root", "../output/Gluino2000_miniAOD_FULL_Mu50_V11p11_Eta2p4.root", true, true);
    
    //Cutflows("../output/Gluino2000_Run2_MET_AOD_V11p16_Eta2p4.root", "../output/Gluino2000_Run2_MET_V11p16_Eta2p4.root", false, false, "_PseudoMETon");
    //Cutflows("../output/Gluino2000_Run2_MET_AOD_V11p16_Eta2p4.root", "../output/Gluino2000_Run2_MET_V11p16_Eta2p4.root", false, true, "_PseudoMETon");

    //MET_trg_eff("CalibPseudoMET", "MET_trg_eff_MC_vs_data", "../output/MuonEG_V17/MuonEG2024_V17p3.root", "../output/TTbar2024_V15/TTbar2024_V15p5.root");
    //MET_trg_eff("METanalysis_Eta2p4_EffTrg", "../output/Gluino_V13/Gluino2000_Run2_MET_V13p1.root", false);
    //Comp_muonEG("../output/MuonEG_V17/MuonEG2024_V17p3.root", "../output/TTbar2024_V15/TTbar2024_V15p5.root");
    //MET_trg_eff("CalibPseudoMET_MuWay", "MET_trg_eff_MCwjet_vs_data", "../output/Mu2024_V18/Mu2024_V18.root", "../output/Wjets2024_V14/Wjets2024_V14p6_weighted.root");
    //MET_trg_eff("CalibPseudoMET_MuWaynocutPt", "MET_trg_eff_MCwjetNoptcut_vs_data", "../output/Mu2024_V18/Mu2024_V18.root", "../output/Wjets2024_V14/Wjets2024_V14p6_weighted.root");
    

    //Old_vs_New_fits("../output/JetMET2024_V12/JetMET2024_V12p24.root");
    BKGdependency("../output/TTbar2024_V15/TTbar2024_V15p5_weighted.root", "TTbar");
    BKGdependency("../output/Wjets2024_V14/Wjets2024_V14p6_weighted.root", "Wjets");
    BKGdependency("../output/QCD2024_V16/QCD2024_mu_V16p1_weighted.root", "QCD");

    CompareMaping();

    //GluinoP_mass(true);
    //GluinoP_mass(false);

    return;
}