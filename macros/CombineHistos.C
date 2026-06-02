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

TH2F* TransposeTH2(const TH2F* h_in) {
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
    TCanvas* c_new = new TCanvas(CanvasTitle.c_str(), CanvasTitle.c_str(), 800, 600);

    // Define pads
    TPad* pad1 = new TPad("pad1", "pad1", 0.0, 0.3, 1.0, 1.0);
    pad1->SetLeftMargin(0.16);
    pad1->SetBottomMargin(0.02);
    pad1->Draw();

    TPad* pad2 = new TPad("pad2", "pad2", 0.0, 0.0, 1.0, 0.315);
    pad2->SetLeftMargin(0.16);pad2->SetBottomMargin(0.33);
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
    h_ratio->GetYaxis()->SetRangeUser(0.5, 1.5);
    h_ratio->SetMarkerStyle(8);
    h_ratio->GetYaxis()->SetNdivisions(505);
    h_ratio->GetYaxis()->SetTitleSize(0.08);
    h_ratio->GetYaxis()->SetTitleFont(43);
    h_ratio->GetXaxis()->SetTitleFont(43);
    h_ratio->GetYaxis()->SetLabelFont(43);
    h_ratio->GetXaxis()->SetLabelFont(43);
    h_ratio->GetYaxis()->SetTitleSize(24);  // px
    h_ratio->GetXaxis()->SetTitleSize(24);
    h_ratio->GetYaxis()->SetLabelSize(20);
    h_ratio->GetXaxis()->SetLabelSize(20);
    h_ratio->GetYaxis()->SetTitleOffset(1.1);   // en font pixel, ~1.0 est correct
    h_ratio->SetLineColor(kBlack);
    h_ratio->SetMarkerColor(kBlack);
    gPad->SetTickx(0);
    gStyle->SetOptStat(0);
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

TCanvas* DrawWithRatio(TH1* h1,
                       TH1* h2,
                       TH1* h3,
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
    TH1F *h3c = (TH1F*)h3->Clone(TString(h3->GetName()) + "_" + CanvasTitle.c_str() + "_h3");
    pad2->cd();
    TH1* h_ratio = (TH1*)h1c->Clone(TString("h_ratio_") + CanvasTitle.c_str());
    TH1* h_ratiobis = (TH1*)h1c->Clone(TString("h_ratio_") + CanvasTitle.c_str());
    h_ratio->Divide(h2c);
    h_ratiobis->Divide(h3c);

    h_ratio->SetTitle("");
    h_ratio->GetYaxis()->SetTitle(RatioTitle.c_str());
    h_ratio->GetXaxis()->SetTitle(XaxisTitle.c_str());
    h_ratio->GetYaxis()->SetRangeUser(0, 2);
    h_ratio->SetMarkerStyle(8);
    h_ratiobis->SetMarkerStyle(22);
    h_ratio->GetYaxis()->SetNdivisions(505);
    h_ratio->GetYaxis()->SetTitleSize(0.08);
    h_ratio->GetYaxis()->SetTitleOffset(0.3);
    h_ratio->GetXaxis()->SetTitleSize(0.08);
    h_ratio->GetXaxis()->SetTitleOffset(1);
    h_ratio->GetYaxis()->SetLabelSize(0.06);
    h_ratio->GetXaxis()->SetLabelSize(0.06);
    h_ratio->SetLineColor(kBlack);
    h_ratio->SetMarkerColor(kBlack);
    h_ratiobis->SetLineColor(kRed);
    h_ratiobis->SetMarkerColor(kRed);
    gPad->SetTickx(0);
    gStyle->SetOptStat(0);
    h_ratio->LabelsOption("v", "X");
    h_ratio->Draw("E0");
    h_ratiobis->Draw("E0 same");
    h_ratio->GetXaxis()->SetRangeUser(Xmin, Xmax);

    // add legend
    TLegend* leg = new TLegend(0.7, 0.7, 0.9, 0.9);
    leg->AddEntry(h_ratio, "rescaled", "pe");
    leg->AddEntry(h_ratiobis, "no rescaled", "pe");
    leg->SetBorderSize(0);
    leg->SetFillStyle(0);
    leg->Draw();

    TLine* line = new TLine(Xmin, 1, Xmax, 1);
    line->SetLineColor(kBlack);
    line->SetLineStyle(2);
    line->Draw("same");

    c_new->Update();
    cout << "Canvas " << CanvasTitle << " drawn with ratio of h1: " << h1->GetName() << " to h2: " << h2->GetName() << " and h3: " << h3->GetName() << endl;
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
    c_new->SetLeftMargin(0.16);
    c_new->SetBottomMargin(0.16);
    
    TH1* hc = (TH1*)h->Clone(TString(h->GetName()) + "_" + CanvasTitle.c_str());
    hc->GetYaxis()->SetTitleOffset(1.2);
    hc->SetTitle("");
    hc->GetYaxis()->SetTitleSize(0.06);
    hc->GetXaxis()->SetTitleSize(0.06);
    hc->GetXaxis()->SetTitleOffset(0.9);
    hc->GetYaxis()->SetTitleOffset(1);
    hc->GetXaxis()->SetLabelSize(0.05);
    hc->GetYaxis()->SetLabelSize(0.05);

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
                    float sizetitleY,
                    float Xmin,
                    float Xmax, 
                    float Ymin = 0, 
                    float Ymax = -1, 
                    bool isLOGy = false,
                    bool isMCfill_h2 = false) {

    TCanvas* c_new = new TCanvas(CanvasTitle.c_str(), CanvasTitle.c_str(), 800, 600);
    c_new->SetLeftMargin(0.16);
    c_new->SetBottomMargin(0.16);
    

    TH1* h1c = (TH1*)h1->Clone(TString(h1->GetName()) + "_" + CanvasTitle.c_str());
    TH1* h2c = (TH1*)h2->Clone(TString(h2->GetName()) + "_" + CanvasTitle.c_str());

    h1c->GetYaxis()->SetTitleOffset(1.0);
    h1c->SetTitle("");
    h1c->GetYaxis()->SetTitleSize(sizetitleY);
    h1c->GetXaxis()->SetTitleSize(0.06);
    h1c->GetXaxis()->SetTitleOffset(0.9);
    h1c->GetYaxis()->SetTitleOffset(1);
    h1c->GetXaxis()->SetLabelSize(0.05);
    h1c->GetYaxis()->SetLabelSize(0.05);
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

    gStyle->SetOptStat(0);

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

    TLegend* leg = new TLegend(0.4, 0.2, 0.6, 0.4);
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

void ExtractSF (const char *ofiletxt, const char *labelData, const char *labelMC, const char *inputfileDATA, const char *inputfileMC) {

    TFile *ifileDATA = new TFile(Form("%s", inputfileDATA), "READ");
    TFile *ifileMC   = new TFile(Form("%s", inputfileMC), "READ");

    TH1F *htemp_pseudoCaloMET_data = (TH1F*)ifileDATA->Get(Form("%s_PseudoCaloMET", labelData));
    TH1F *htemp_orMETtrigger_data = (TH1F*)ifileDATA->Get(Form("%s_if___orMETtrg___PseudoCaloMET", labelData));
    TH1F *htemp_pseudoCaloMET_MC   = (TH1F*)ifileMC->Get(Form("%s_PseudoCaloMET", labelMC));
    TH1F *htemp_orMETtrigger_MC   = (TH1F*)ifileMC->Get(Form("%s_if___orMETtrg___PseudoCaloMET", labelMC));

    ofstream outfile(Form("PlayWithHistos/SF_%s.txt", ofiletxt), ios::out);

    // Construction des edges
    const TAxis* ax = htemp_orMETtrigger_data->GetXaxis();
    const int nBins = ax->GetNbins();

    int nNewBins = 0;
    for (int i = 1; i <= nBins; i++) {
        if (ax->GetBinLowEdge(i) < 400) nNewBins++;
    }
    nNewBins++; // bin [400, +inf]

    double* new_bins = new double[nNewBins + 1];
    int idx = 0;
    for (int i = 1; i <= nBins; i++) {
        if (ax->GetBinLowEdge(i) < 400)
            new_bins[idx++] = ax->GetBinLowEdge(i);
    }
    new_bins[idx++] = 400.0;
    new_bins[idx]   = ax->GetBinUpEdge(nBins);

    // Rebin
    htemp_orMETtrigger_data  = (TH1F*) htemp_orMETtrigger_data ->Rebin(nNewBins, "htemp_orMETtrigger_data",  new_bins);
    htemp_pseudoCaloMET_data = (TH1F*) htemp_pseudoCaloMET_data->Rebin(nNewBins, "htemp_pseudoCaloMET_data", new_bins);
    htemp_orMETtrigger_MC   = (TH1F*) htemp_orMETtrigger_MC   ->Rebin(nNewBins, "htemp_orMETtrigger_MC",    new_bins);
    htemp_pseudoCaloMET_MC  = (TH1F*) htemp_pseudoCaloMET_MC  ->Rebin(nNewBins, "htemp_pseudoCaloMET_MC",   new_bins);
    delete[] new_bins;

    htemp_orMETtrigger_data->Divide(htemp_pseudoCaloMET_data);
    htemp_orMETtrigger_MC->Divide(htemp_pseudoCaloMET_MC);

    htemp_orMETtrigger_data->Divide(htemp_orMETtrigger_MC);
    cout << "Extracted SF for " << ofiletxt << ":\n";
    for (int i = 1; i <= htemp_orMETtrigger_data->GetNbinsX(); i++) {
        double sf, sf_down, sf_up;

        sf      = htemp_orMETtrigger_data->GetBinContent(i);
        sf_down = sf - htemp_orMETtrigger_data->GetBinError(i);
        sf_up   = sf + htemp_orMETtrigger_data->GetBinError(i);

        cout << htemp_orMETtrigger_data->GetBinLowEdge(i) << " " << sf_down << " " << sf << " " << sf_up << "\n";

        outfile << htemp_orMETtrigger_data->GetBinLowEdge(i) << " " << sf_down << " " << sf << " " << sf_up << "\n";
    }
    cout << "\n";
    outfile.close();


    return;
}

double langaufun(double *x, double *par)
{
 
   //Fit parameters:
   //par[0]=Width (scale) parameter of Landau density
   //par[1]=Most Probable (MP, location) parameter of Landau density
   //par[2]=Total area (integral -inf to inf, normalization constant)
   //par[3]=Width (sigma) of convoluted Gaussian function
   //
   //In the Landau distribution (represented by the CERNLIB approximation),
   //the maximum is located at x=-0.22278298 with the location parameter=0.
   //This shift is corrected within this function, so that the actual
   //maximum is identical to the MP parameter.
 
      // Numeric constants
      double invsq2pi = 0.3989422804014;   // (2 pi)^(-1/2)
      double mpshift  = -0.22278298;       // Landau maximum location
 
      // Control constants
      double np = 100.0;      // number of convolution steps
      double sc =   5.0;      // convolution extends to +-sc Gaussian sigmas
 
      // Variables
      double xx;
      double mpc;
      double fland;
      double sum = 0.0;
      double xlow,xupp;
      double step;
      double i;
 
 
      // MP shift correction
      mpc = par[1] - mpshift * par[0];
 
      // Range of convolution integral
      xlow = x[0] - sc * par[3];
      xupp = x[0] + sc * par[3];
 
      step = (xupp-xlow) / np;
 
      // Convolution integral of Landau and Gaussian by sum
      for(i=1.0; i<=np/2; i++) {
         xx = xlow + (i-.5) * step;
         fland = TMath::Landau(xx,mpc,par[0]) / par[0];
         sum += fland * TMath::Gaus(x[0],xx,par[3]);
 
         xx = xupp - (i-.5) * step;
         fland = TMath::Landau(xx,mpc,par[0]) / par[0];
         sum += fland * TMath::Gaus(x[0],xx,par[3]);
      }
 
      return (par[2] * step * sum * invsq2pi / par[3]);
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

    TCanvas *c_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET = DrawCanvas(eff_HLT_PFMET120_PseudoCaloMET, "HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET", "Pseudo MET [GeV]", "eff. HLT_PFMET120_PFMHT120_IDTight", "E1", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET = DrawCanvas(eff_HLT_PFHT500_PseudoCaloMET, "HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET", "Pseudo MET [GeV]", "eff. HLT_PFHT500_PFMET100_PFMHT100_IDTight", "E1", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET = DrawCanvas(eff_HLT_PFMETNoMu120_PseudoCaloMET, "HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET", "Pseudo MET [GeV]", "eff. HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60", "E1", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_MET105_IsoTrk50___PseudoCaloMET = DrawCanvas(eff_HLT_MET105_PseudoCaloMET, "HLT_MET105_IsoTrk50___PseudoCaloMET", "Pseudo MET [GeV]", "eff. HLT_MET105_IsoTrk50", "E1", 0, 1200, 0, 1, false);    
    TCanvas *c_orMETtrg___PseudoCaloMET = DrawCanvas(eff_orMETtrg_PseudoCaloMET, "orMETtrg___PseudoCaloMET", "Pseudo MET [GeV]", "eff. orMETtrg", "E1", 0, 1200, 0, 1, false);

    /*TCanvas *c_HLT_PFMET120_PFMHT120_IDTight___RecoPFMET = DrawCanvas(eff_HLT_PFMET120_RecoPFMET, "HLT_PFMET120_PFMHT120_IDTight___RecoPFMET", "RecoPFMET [GeV]", "eff. HLT_PFMET120_PFMHT120_IDTight", "E1", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET = DrawCanvas(eff_HLT_PFHT500_RecoPFMET, "HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET", "RecoPFMET [GeV]", "eff. HLT_PFHT500_PFMET100_PFMHT100_IDTight", "E1", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET = DrawCanvas(eff_HLT_PFMETNoMu120_RecoPFMET, "HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET", "RecoPFMET [GeV]", "eff. HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60", "E1", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_MET105_IsoTrk50___RecoPFMET = DrawCanvas(eff_HLT_MET105_RecoPFMET, "HLT_MET105_IsoTrk50___RecoPFMET", "RecoPFMET [GeV]", "eff. HLT_MET105_IsoTrk50", "E1", 0, 1200, 0, 1, false);
    TCanvas *c_orMETtrg___RecoPFMET = DrawCanvas(eff_orMETtrg_RecoPFMET, "orMETtrg___RecoPFMET", "RecoPFMET [GeV]", "eff. orMETtrg", "E1", 0, 1200, 0, 1, false);

    TCanvas *c_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET__RecoPFMETCut = DrawCanvas(eff_HLT_PFMET120_PseudoCaloMET__RecoPFMETCut, "HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET__RecoPFMETCut", "Pseudo MET [GeV]", "eff. HLT_PFMET120_PFMHT120_IDTight w/RecoPFMET>170 GeV", "E1", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET__RecoPFMETCut = DrawCanvas(eff_HLT_PFHT500_PseudoCaloMET__RecoPFMETCut, "HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET__RecoPFMETCut", "Pseudo MET [GeV]", "eff. HLT_PFHT500_PFMET100_PFMHT100_IDTight w/RecoPFMET>170 GeV", "E1", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET__RecoPFMETCut = DrawCanvas(eff_HLT_PFMETNoMu120_PseudoCaloMET__RecoPFMETCut, "HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET__RecoPFMETCut", "Pseudo MET [GeV]", "eff. HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 w/RecoPFMET>170 GeV", "E1", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_MET105_IsoTrk50___PseudoCaloMET__RecoPFMETCut = DrawCanvas(eff_HLT_MET105_PseudoCaloMET__RecoPFMETCut, "HLT_MET105_IsoTrk50___PseudoCaloMET__RecoPFMETCut", "Pseudo MET [GeV]", "eff. HLT_MET105_IsoTrk50 w/RecoPFMET>170 GeV", "E1", 0, 1200, 0, 1, false);
    TCanvas *c_orMETtrg___PseudoCaloMET__RecoPFMETCut = DrawCanvas(eff_orMETtrg_PseudoCaloMET__RecoPFMETCut, "orMETtrg___PseudoCaloMET__RecoPFMETCut", "Pseudo MET [GeV]", "eff. orMETtrgw/RecoPFMET>170 GeV", "E1", 0, 1200, 0, 1, false);

    TCanvas *c_HLT_PFMET120_PFMHT120_IDTight_RecoPFMET__PseudoCaloMETCut = DrawCanvas(eff_HLT_PFMET120_RecoPFMET__PseudoCaloMETCut, "HLT_PFMET120_PFMHT120_IDTight___RecoPFMET__PseudoCaloMETCut", "RecoPFMET [GeV]", "eff. HLT_PFMET120_PFMHT120_IDTight w/Pseudo MET>170 GeV", "E1", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_PFHT500_PFMET100_PFMHT100_IDTight__PseudoCaloMETCut = DrawCanvas(eff_HLT_PFHT500_RecoPFMET__PseudoCaloMETCut, "HLT_PFHT500_PFMET100_PFMHT100_IDTight__PseudoCaloMETCut", "RecoPFMET [GeV]", "eff. HLT_PFHT500_PFMET100_PFMHT100_IDTight w/Pseudo MET>170 GeV", "E1", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60__PseudoCaloMETCut = DrawCanvas(eff_HLT_PFMETNoMu120_RecoPFMET__PseudoCaloMETCut, "HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET__PseudoCaloMETCut", "RecoPFMET [GeV]", "eff. HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 w/Pseudo MET>170 GeV", "E1", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_MET105_IsoTrk50_RecoPFMET__PseudoCaloMETCut = DrawCanvas(eff_HLT_MET105_RecoPFMET__PseudoCaloMETCut, "HLT_MET105_IsoTrk50___RecoPFMET__PseudoCaloMETCut", "RecoPFMET [GeV]", "eff. HLT_MET105_IsoTrk50 w/Pseudo MET>170 GeV", "E1", 0, 1200, 0, 1, false);
    TCanvas *c_orMETtrg_RecoPFMET__PseudoCaloMETCut = DrawCanvas(eff_orMETtrg_RecoPFMET__PseudoCaloMETCut, "orMETtrg_RecoPFMET__PseudoCaloMETCut", "RecoPFMET [GeV]", "eff. orMETtrg w/Pseudo MET>170 GeV", "E1", 0, 1200, 0, 1, false);

    TCanvas *c_PseudoCaloMET = DrawCanvas(PseudoCaloMET, "Pseudo MET", "Pseudo MET [GeV]", "Events / 25 GeV", "HIST", 0, 1000, 0, PseudoCaloMET->GetMaximum()*1.2, true);
    TCanvas *c_RecoPFMET = DrawCanvas(RecoPFMET, "RecoPFMET", "RecoPFMET [GeV]", "Events / 25 GeV", "HIST", 0, 1000, 0, RecoPFMET->GetMaximum()*1.2, true);
    TCanvas *c_L1MET = DrawCanvas(L1MET, "L1MET", "L1MET [GeV]", "Events / 25 GeV", "HIST", 0, 1000, 0, L1MET->GetMaximum()*1.2, true);
    TCanvas *c_HLTCaloMET = DrawCanvas(HLTCaloMET, "HLTCaloMET", "HLTCaloMET [GeV]", "Events / 25 GeV", "HIST", 0, 1000, 0, HLTCaloMET->GetMaximum()*1.2, true);
    TCanvas *c_HLTCaloMHT = DrawCanvas(HLTCaloMHT, "HLTCaloMHT", "HLTCaloMHT [GeV]", "Events / 25 GeV", "HIST", 0, 1000, 0, HLTCaloMHT->GetMaximum()*1.2, true);
    TCanvas *c_HLTPFMHT = DrawCanvas(HLTPFMHT, "HLTPFMHT", "HLTPFMHT [GeV]", "Events / 25 GeV", "HIST", 0, 1000, 0, HLTPFMHT->GetMaximum()*1.2, true);
    TCanvas *c_HLTPFMET = DrawCanvas(HLTPFMET, "HLTPFMET", "HLTPFMET [GeV]", "Events / 25 GeV", "HIST", 0, 1000, 0, HLTPFMET->GetMaximum()*1.2, true);
    */


    // saving
    ofile->cd();
    c_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET->Write();
    c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET->Write();
    c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET->Write();
    c_HLT_MET105_IsoTrk50___PseudoCaloMET->Write();
    c_orMETtrg___PseudoCaloMET->Write();

    /*c_HLT_PFMET120_PFMHT120_IDTight___RecoPFMET->Write();
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
    c_HLTPFMET->Write();*/
    
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

    //TFile *ifile_AOD = new TFile("../output/Gluino2000_Run2_METtrgEff_AOD_V11p15_Eta2p4.root", "READ");
    //TFile *ifile_miniAOD = new TFile("../output/Gluino2000_Run2_METtrgEff_V11p15_Eta2p4.root", "READ");

    TFile *ifile_AOD = new TFile("../output/Gluino2000_Run2_MET_AOD_V11p16_Eta2p4.root", "READ");
    TFile *ifile_miniAOD = new TFile("../output/Gluino2000_Run2_MET_V11p16_Eta2p4.root", "READ");


    // input histos
    TH1F *RecoPFMET_AOD = (TH1F*)ifile_AOD->Get("OnlyMET_RecoPFMET");
    TH1F *RecoPFMET_miniAOD = (TH1F*)ifile_miniAOD->Get("METanalysis_RecoPFMET");
    TH1F *if___orMETtrg___RecoPFMET_AOD = (TH1F*)ifile_AOD->Get("OnlyMET_if___orMETtrg___RecoPFMET");
    TH1F *if___orMETtrg___RecoPFMET_miniAOD = (TH1F*)ifile_miniAOD->Get("METanalysis_if___orMETtrg___RecoPFMET");

    TH1F *PseudoCaloMET_AOD = (TH1F*)ifile_AOD->Get("OnlyMET_CaloJets");
    TH1F *PseudoCaloMET_miniAOD = (TH1F*)ifile_miniAOD->Get("METanalysis_CaloJets");
    TH1F *if___orMETtrg___PseudoCaloMET_AOD = (TH1F*)ifile_AOD->Get("OnlyMET_if___orMETtrg___CaloJets");
    TH1F *if___orMETtrg___PseudoCaloMET_miniAOD = (TH1F*)ifile_miniAOD->Get("METanalysis_if___orMETtrg___CaloJets");

    
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


void Cutflows(std::string QCD, std::string TTbar, std::string Wjets, std::string JetMETdata, std::string Gluino2000) {

    TFile *ofile = new TFile("PlayWithHistos/EventCutflow.root", "RECREATE");

    TFile *ifile_QCD = new TFile(QCD.c_str(), "READ");
    TFile *ifile_TTbar = new TFile(TTbar.c_str(), "READ");
    TFile *ifile_Wjets = new TFile(Wjets.c_str(), "READ");
    TFile *ifile_JetMETdata = new TFile(JetMETdata.c_str(), "READ");
    TFile *ifile_Gluino2000 = new TFile(Gluino2000.c_str(), "READ");

    TH1D *Cutflow_QCD = (TH1D*)ifile_QCD->Get("EventCutflow");
    TH1D *Cutflow_TTbar = (TH1D*)ifile_TTbar->Get("EventCutflow");
    TH1D *Cutflow_Wjets = (TH1D*)ifile_Wjets->Get("EventCutflow");
    TH1D *Cutflow_JetMETdata = (TH1D*)ifile_JetMETdata->Get("EventCutflow");
    TH1D *Cutflow_Gluino2000 = (TH1D*)ifile_Gluino2000->Get("EventCutflow");

    THStack *hs = new THStack("hs", "");
    hs->Add(Cutflow_QCD);
    hs->Add(Cutflow_TTbar);
    hs->Add(Cutflow_Wjets);

    auto PrintCutflowPercent = [](TH1D* h, const std::string& name)
    {
        double N0 = h->GetBinContent(2);

        std::cout << "\n=== " << name << " ===\n";
        std::cout << "Cut\t\tEvents\t\tRemaining (%)\n";

        for (int i = 2; i <= h->GetNbinsX(); ++i) { // remove 'All' bin
            double Ni = h->GetBinContent(i);
            double eff = (N0 > 0) ? 100. * Ni / N0 : 0.;
            std::cout << i << "\t\t"
                    << Ni << "\t\t"
                    << std::fixed << std::setprecision(2)
                    << eff << " %\n";
        }
    };

    // --- Style   
    int colorWjets = kBlue-7;
    int colorTTbar = kRed;
    int colorQCD = kGreen-4;
    int colorSignal = kOrange+1;
    int colorJetMET = kBlack;
    gStyle->SetOptStat(0);

    Cutflow_Wjets->SetFillColorAlpha(colorWjets, 0.5);
    Cutflow_Wjets->SetLineColor(colorWjets);
    Cutflow_TTbar->SetFillColorAlpha(colorTTbar, 0.5);
    Cutflow_TTbar->SetLineColor(colorTTbar);
    Cutflow_QCD->SetFillColorAlpha(colorQCD, 0.5);
    Cutflow_QCD->SetLineColor(colorQCD);
    Cutflow_Gluino2000->SetLineColor(colorSignal);
    Cutflow_Gluino2000->SetMarkerColor(colorSignal);
    Cutflow_Gluino2000->SetMarkerStyle(22);
    Cutflow_JetMETdata->SetLineColor(colorJetMET);
    Cutflow_JetMETdata->SetMarkerColor(colorJetMET);
    Cutflow_JetMETdata->SetMarkerStyle(20);




    // --- Canvas + pads
    TCanvas* c = new TCanvas("Cutflow_BKG_data_signal", "", 800, 800);
    
    c->SetBottomMargin(0.25);
    c->SetLeftMargin(0.12);
    c->SetRightMargin(0.05);
    c->SetTopMargin(0.08);

    c->cd();
    hs->SetMaximum(std::max(hs->GetMaximum()*3, Cutflow_JetMETdata->GetMaximum())*3);
    hs->SetMinimum(std::min(hs->GetMinimum()/2, Cutflow_Gluino2000->GetMinimum())/2);
    Cutflow_Wjets->GetXaxis()->SetLabelSize(0.04);
    Cutflow_Wjets->GetXaxis()->SetRangeUser(1, 20);
    Cutflow_Wjets->GetXaxis()->SetTitle("");
    hs->Draw("HIST");
    hs->GetHistogram()->GetYaxis()->SetTitle("Events");
    Cutflow_Gluino2000->Draw("E1 same");
    Cutflow_JetMETdata->Draw("E1 same");
    c->SetLogy();

    // --- Légende
    TLegend* leg = new TLegend(0.60, 0.65, 0.92, 0.92);
    leg->SetBorderSize(0);
    leg->SetFillStyle(0);
    leg->AddEntry(Cutflow_JetMETdata, "2024 JetMET data", "ep");
    leg->AddEntry(Cutflow_Wjets, "W+jets", "f");
    leg->AddEntry(Cutflow_TTbar, "TTbar", "f");
    leg->AddEntry(Cutflow_QCD, "QCD muEnriched", "f");
    leg->AddEntry(Cutflow_Gluino2000, "#tilde{g}_{m=2000}", "ep");
    leg->Draw();

    // --- Label CMS
    TLatex latex;
    latex.SetNDC();
    latex.SetTextSize(0.035);
    latex.SetTextFont(42);
    latex.DrawLatex(0.12, 0.93, "#it{Work in progress}");

    // --- Labels X
    std::vector<TString> xlabel = {"All","HLT MET","METfilters", "PseudoMET > 170", "p_{T}>50","|#eta|<2.4","N_{no-L1 pixel hits}#geq2","f_{valid hits}>0.8",
                "N_{dEdx hits}#geq10","HighPurity","#chi^{2}/N_{dof}<5","|d_{z}|<0.1","|d_{xy}|<0.02","I^{rel}_{PF}<0.02","I^{trk}_{dr03}<15",
                "E/p<0.3","#sigma_{p_{T}}/p_{T}^{2}<0.0008","F_{pixel}>0.3","#sigma_{p_{T}}/p_{T}<1","I_{h}>C"};

    for (int i = 1; i <= Cutflow_Wjets->GetNbinsX(); i++) {
        if (i-1 < xlabel.size()) {
            Cutflow_Wjets->GetXaxis()->SetBinLabel(i, xlabel[i-1]);
            Cutflow_TTbar->GetXaxis()->SetBinLabel(i, xlabel[i-1]);
            Cutflow_QCD->GetXaxis()->SetBinLabel(i, xlabel[i-1]);
            hs->GetXaxis()->SetBinLabel(i, xlabel[i-1]);
        }
    }

    gPad->SetTickx(0);
    hs->GetXaxis()->LabelsOption("v");
    hs->GetXaxis()->SetRangeUser(1, 20);
    hs->GetXaxis()->SetLabelSize(0.04);
    c->Update();

    

    // Cout values:
    PrintCutflowPercent(Cutflow_JetMETdata, "JetMET data");
    TH1D* Cutflow_MC = (TH1D*)Cutflow_Wjets->Clone("Cutflow_MC");
    Cutflow_MC->Add(Cutflow_TTbar);
    Cutflow_MC->Add(Cutflow_QCD);
    PrintCutflowPercent(Cutflow_MC, "MC (Wjets + TTbar + QCD)");
    PrintCutflowPercent(Cutflow_Gluino2000, "Signal m=2000");



    // --- Saving
    ofile->cd();
    c->Write();
    c->SaveAs("PlayWithHistos/EventCutflow.pdf");
    ofile->Close();
}


void Cutflows_cutPseudoMET() {

    TFile *ofile = new TFile("PlayWithHistos/EventCutflow_GluinoPseudoMETcut.root", "RECREATE");

    TFile *ifile_Gluino2000_cut170 = new TFile("../output/Gluino_V19/Gluino_Run3_MET_madgraph_2000_V19p1_weighted.root", "READ");
    TFile *ifile_Gluino2000_cut300 = new TFile("../output/Gluino_V19/Gluino_Run3_MET_madgraph_2000_V19p1_cut300PseudoMET_weighted.root", "READ");

    TH1D *Cutflow_Gluino2000_cut170 = (TH1D*)ifile_Gluino2000_cut170->Get("EventCutflow");
    TH1D *Cutflow_Gluino2000_cut300 = (TH1D*)ifile_Gluino2000_cut300->Get("EventCutflow");

    auto PrintCutflowPercent = [](TH1D* h, const std::string& name)
    {
        double N0 = h->GetBinContent(1);

        std::cout << "\n=== " << name << " ===\n";
        std::cout << "Cut\t\tEvents\t\tRemaining (%)\n";

        for (int i = 1; i <= h->GetNbinsX(); ++i) {
            double Ni = h->GetBinContent(i);
            double eff = (N0 > 0) ? 100. * Ni / N0 : 0.;
            std::cout << i << "\t\t"
                    << Ni << "\t\t"
                    << std::fixed << std::setprecision(2)
                    << eff << " %\n";
        }
    };

    // --- Style    
    int colorSignal = kBlue-7;
    int colorSignal_bis = kRed+1;
    gStyle->SetOptStat(0);
    Cutflow_Gluino2000_cut170->SetLineColor(colorSignal);
    Cutflow_Gluino2000_cut170->SetMarkerColor(colorSignal);
    Cutflow_Gluino2000_cut170->SetMarkerStyle(22);
    Cutflow_Gluino2000_cut300->SetLineColor(colorSignal_bis);
    Cutflow_Gluino2000_cut300->SetMarkerColor(colorSignal_bis);
    Cutflow_Gluino2000_cut300->SetMarkerStyle(20);


    // --- Canvas + pads
    TCanvas* c = new TCanvas("Cutflow_BKG_data_signal", "", 800, 800);
    
    c->SetBottomMargin(0.25);
    c->SetLeftMargin(0.12);
    c->SetRightMargin(0.05);
    c->SetTopMargin(0.08);

    c->cd();
    Cutflow_Gluino2000_cut170->SetMaximum(std::max(Cutflow_Gluino2000_cut170->GetMaximum()*3, Cutflow_Gluino2000_cut300->GetMaximum())*3);
    Cutflow_Gluino2000_cut170->SetMinimum(std::min(Cutflow_Gluino2000_cut170->GetMinimum()/2, Cutflow_Gluino2000_cut300->GetMinimum())/2);
    Cutflow_Gluino2000_cut170->GetXaxis()->SetLabelSize(0.04);
    Cutflow_Gluino2000_cut170->GetXaxis()->SetRangeUser(0, 18);
    Cutflow_Gluino2000_cut170->GetYaxis()->SetTitle("Events");
    Cutflow_Gluino2000_cut170->GetYaxis()->SetTitleOffset(1.4);
    Cutflow_Gluino2000_cut170->GetXaxis()->SetTitle("");
    Cutflow_Gluino2000_cut170->Draw("E1");
    Cutflow_Gluino2000_cut300->Draw("E1 same");
    c->SetLogy();

    // --- Légende
    TLegend* leg = new TLegend(0.60, 0.73, 0.90, 0.88);
    leg->SetBorderSize(0);
    leg->SetFillStyle(0);
    leg->AddEntry(Cutflow_Gluino2000_cut170, "PseudoMET > 170 GeV", "ep");
    leg->AddEntry(Cutflow_Gluino2000_cut300, "PseudoMET > 300 GeV", "ep");
    leg->Draw();

    // --- Label CMS
    TLatex latex;
    latex.SetNDC();
    latex.SetTextSize(0.035);
    latex.SetTextFont(42);
    latex.DrawLatex(0.12, 0.93, "CMS Internal");

    // --- Labels X
    std::vector<TString> xlabel = {"All","HLT MET","METfilters", "PseudoMET cut", "p_{T}>50","|#eta|<2.4","N_{no-L1 pixel hits}#geq2","f_{valid hits}>0.8",
                "N_{dEdx hits}#geq10","HighPurity","#chi^{2}/N_{dof}<5","|d_{z}|<0.1","|d_{xy}|<0.02","I^{rel}_{PF iso}<0.02","I^{trk}_{dr03}<15",
                "E/p<0.3","#sigma_{p_{T}}/p_{T}^{2}<0.0008","F_{pixel}>0.3","#sigma_{p_{T}}/p_{T}<1","I_{h}>C"};

    for (int i = 1; i <= Cutflow_Gluino2000_cut170->GetNbinsX(); i++) {
        if (i-1 < xlabel.size())
            Cutflow_Gluino2000_cut170->GetXaxis()->SetBinLabel(i, xlabel[i-1]);
    }

    gPad->SetTickx(0);
    Cutflow_Gluino2000_cut170->LabelsOption("v", "X");
    c->Update();

    
    // Cout values:
    PrintCutflowPercent(Cutflow_Gluino2000_cut170, "PseudoMET > 170");
    PrintCutflowPercent(Cutflow_Gluino2000_cut300, "PseudoMET > 300");

    // --- Saving
    ofile->cd();
    c->Write();
    ofile->Close();
}


void MET_trg_eff(const char *labelData, 
                 const char *labelMC, 
                 const char *ofilename, 
                 const char *inputfileDATA, 
                 const char *inputfileMC) {

    cout << "dataset: " << inputfileDATA << " and " << inputfileMC << endl;

    gErrorIgnoreLevel = kError;

    TFile *ofile = new TFile(Form("PlayWithHistos/%s.root", ofilename), "RECREATE");

    TFile *ifileDATA = new TFile(Form("%s", inputfileDATA), "READ");
    TFile *ifileMC = new TFile(Form("%s", inputfileMC), "READ");


    // MC 
    TH1F *PseudoCaloMET_MC = (TH1F*)ifileMC->Get(Form("%s_PseudoCaloMET", labelMC));
    TH1F *if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET_MC = (TH1F*)ifileMC->Get(Form("%s_if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET", labelMC));
    TH1F *if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET_MC = (TH1F*)ifileMC->Get(Form("%s_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET", labelMC));
    TH1F *if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET_MC = (TH1F*)ifileMC->Get(Form("%s_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET", labelMC));
    TH1F *if___HLT_MET105_IsoTrk50___PseudoCaloMET_MC = (TH1F*)ifileMC->Get(Form("%s_if___HLT_MET105_IsoTrk50___PseudoCaloMET", labelMC));
    TH1F *if___orMETtrg___PseudoCaloMET_MC = (TH1F*)ifileMC->Get(Form("%s_if___orMETtrg___PseudoCaloMET", labelMC));

    TH1F *RecoPFMET_MC = (TH1F*)ifileMC->Get(Form("%s_RecoPFMET", labelMC));
    TH1F *if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET_MC = (TH1F*)ifileMC->Get(Form("%s_if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET", labelMC));            
    TH1F *if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET_MC = (TH1F*)ifileMC->Get(Form("%s_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET", labelMC));
    TH1F *if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET_MC = (TH1F*)ifileMC->Get(Form("%s_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET", labelMC));
    TH1F *if___HLT_MET105_IsoTrk50___RecoPFMET_MC = (TH1F*)ifileMC->Get(Form("%s_if___HLT_MET105_IsoTrk50___RecoPFMET", labelMC));
    TH1F *if___orMETtrg___RecoPFMET_MC = (TH1F*)ifileMC->Get(Form("%s_if___orMETtrg___RecoPFMET", labelMC));
    
    TH1F *PseudoCaloMET__RecoPFMETCut_MC = (TH1F*)ifileMC->Get(Form("%s_PseudoCaloMET__RecoPFMETCut", labelMC));
    TH1F *if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET__RecoPFMETCut_MC = (TH1F*)ifileMC->Get(Form("%s_if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET__RecoPFMETCut", labelMC));       
    TH1F *if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET__RecoPFMETCut_MC = (TH1F*)ifileMC->Get(Form("%s_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET__RecoPFMETCut", labelMC));
    TH1F *if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET__RecoPFMETCut_MC = (TH1F*)ifileMC->Get(Form("%s_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET__RecoPFMETCut", labelMC));
    TH1F *if___HLT_MET105_IsoTrk50___PseudoCaloMET__RecoPFMETCut_MC = (TH1F*)ifileMC->Get(Form("%s_if___HLT_MET105_IsoTrk50___PseudoCaloMET__RecoPFMETCut", labelMC));
    TH1F *if___orMETtrg___PseudoCaloMET__RecoPFMETCut_MC = (TH1F*)ifileMC->Get(Form("%s_if___orMETtrg___PseudoCaloMET__RecoPFMETCut", labelMC));
    
    TH1F *RecoPFMET__PseudoCaloMETCut_MC = (TH1F*)ifileMC->Get(Form("%s_RecoPFMET__PseudoCaloMETCut", labelMC));
    TH1F *if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET__PseudoCaloMETCut_MC = (TH1F*)ifileMC->Get(Form("%s_if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET__PseudoCaloMETCut", labelMC));      
    TH1F *if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET__PseudoCaloMETCut_MC = (TH1F*)ifileMC->Get(Form("%s_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET__PseudoCaloMETCut", labelMC));
    TH1F *if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET__PseudoCaloMETCut_MC = (TH1F*)ifileMC->Get(Form("%s_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET__PseudoCaloMETCut", labelMC));
    TH1F *if___HLT_MET105_IsoTrk50___RecoPFMET__PseudoCaloMETCut_MC = (TH1F*)ifileMC->Get(Form("%s_if___HLT_MET105_IsoTrk50___RecoPFMET__PseudoCaloMETCut", labelMC));
    TH1F *if___orMETtrg___RecoPFMET__PseudoCaloMETCut_MC = (TH1F*)ifileMC->Get(Form("%s_if___orMETtrg___RecoPFMET__PseudoCaloMETCut", labelMC));


    // DATA
    TH1F *PseudoCaloMET_DATA = (TH1F*)ifileDATA->Get(Form("%s_PseudoCaloMET", labelData));
    TH1F *if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET", labelData));
    TH1F *if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET", labelData));
    TH1F *if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET", labelData));
    TH1F *if___HLT_MET105_IsoTrk50___PseudoCaloMET_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___HLT_MET105_IsoTrk50___PseudoCaloMET", labelData));
    TH1F *if___orMETtrg___PseudoCaloMET_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___orMETtrg___PseudoCaloMET", labelData));

    TH1F *RecoPFMET_DATA = (TH1F*)ifileDATA->Get(Form("%s_RecoPFMET", labelData));
    TH1F *if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET", labelData));            
    TH1F *if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET", labelData));
    TH1F *if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET", labelData));
    TH1F *if___HLT_MET105_IsoTrk50___RecoPFMET_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___HLT_MET105_IsoTrk50___RecoPFMET", labelData));
    TH1F *if___orMETtrg___RecoPFMET_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___orMETtrg___RecoPFMET", labelData));
    
    TH1F *PseudoCaloMET__RecoPFMETCut_DATA = (TH1F*)ifileDATA->Get(Form("%s_PseudoCaloMET__RecoPFMETCut", labelData));
    TH1F *if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET__RecoPFMETCut_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET__RecoPFMETCut", labelData));       
    TH1F *if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET__RecoPFMETCut_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET__RecoPFMETCut", labelData));
    TH1F *if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET__RecoPFMETCut_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET__RecoPFMETCut", labelData));
    TH1F *if___HLT_MET105_IsoTrk50___PseudoCaloMET__RecoPFMETCut_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___HLT_MET105_IsoTrk50___PseudoCaloMET__RecoPFMETCut", labelData));
    TH1F *if___orMETtrg___PseudoCaloMET__RecoPFMETCut_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___orMETtrg___PseudoCaloMET__RecoPFMETCut", labelData));
    
    TH1F *RecoPFMET__PseudoCaloMETCut_DATA = (TH1F*)ifileDATA->Get(Form("%s_RecoPFMET__PseudoCaloMETCut", labelData));
    TH1F *if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET__PseudoCaloMETCut_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET__PseudoCaloMETCut", labelData));      
    TH1F *if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET__PseudoCaloMETCut_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET__PseudoCaloMETCut", labelData));
    TH1F *if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET__PseudoCaloMETCut_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET__PseudoCaloMETCut", labelData));
    TH1F *if___HLT_MET105_IsoTrk50___RecoPFMET__PseudoCaloMETCut_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___HLT_MET105_IsoTrk50___RecoPFMET__PseudoCaloMETCut", labelData));
    TH1F *if___orMETtrg___RecoPFMET__PseudoCaloMETCut_DATA = (TH1F*)ifileDATA->Get(Form("%s_if___orMETtrg___RecoPFMET__PseudoCaloMETCut", labelData));


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


    TLatex *latex1 = new TLatex(0.16, 0.91, "#scale[1.3]{#bf{CMS}}#it{Work in progress}");
    latex1->SetNDC();
    latex1->SetTextFont(42);
    latex1->SetTextSize(0.04);

    // drawing
    TCanvas *c_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET = DrawCanvas(eff_HLT_PFMET120_PseudoCaloMET_DATA, eff_HLT_PFMET120_PseudoCaloMET_MC, "c_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET", "Pseudo MET [GeV]", "eff. HLT_PFMET120_PFMHT120_IDTight",
    "E1", "E1 same", true, "DATA", "MC", "lep", "lep", 0.045, 0, 1200, 0, 1, false);
    c_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET->cd();
    latex1->Draw();
    TCanvas *c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET = DrawCanvas(eff_HLT_PFHT500_PseudoCaloMET_DATA, eff_HLT_PFHT500_PseudoCaloMET_MC, "c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET", "Pseudo MET [GeV]", "eff. HLT_PFHT500_PFMET100_PFMHT100_IDTight",
    "E1", "E1 same", true, "DATA", "MC", "lep", "lep", 0.04, 0, 1200, 0, 1, false);
    c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET->cd();
    latex1->Draw();
    TCanvas *c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET = DrawCanvas(eff_HLT_PFMETNoMu120_PseudoCaloMET_DATA, eff_HLT_PFMETNoMu120_PseudoCaloMET_MC, "c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET", "Pseudo MET [GeV]", "eff. HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60",
    "E1", "E1 same", true, "DATA", "MC", "lep", "lep", 0.032, 0, 1200, 0, 1, false);
    c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET->cd();
    latex1->Draw();
    TCanvas *c_HLT_MET105_IsoTrk50___PseudoCaloMET = DrawCanvas(eff_HLT_MET105_PseudoCaloMET_DATA, eff_HLT_MET105_PseudoCaloMET_MC, "c_HLT_MET105_IsoTrk50___PseudoCaloMET", "Pseudo MET [GeV]", "eff. HLT_MET105_IsoTrk50",
    "E1", "E1 same", true, "DATA", "MC", "lep", "lep", 0.05, 0, 1200, 0, 1, false);
    c_HLT_MET105_IsoTrk50___PseudoCaloMET->cd();
    latex1->Draw();
    TCanvas *c_orMETtrg___PseudoCaloMET = DrawCanvas(eff_orMETtrg_PseudoCaloMET_DATA, eff_orMETtrg_PseudoCaloMET_MC, "c_orMETtrg___PseudoCaloMET", "Pseudo MET [GeV]", "eff orMETtrg",
    "E1", "E1 same", true, "DATA", "MC", "lep", "lep", 0.06, 0, 1200, 0, 1, false);
    c_orMETtrg___PseudoCaloMET->cd();
    latex1->Draw();

    /*TCanvas *c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET = DrawCanvas(eff_HLT_PFHT500_RecoPFMET_DATA, eff_HLT_PFHT500_RecoPFMET_MC, "c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET", "RecoPFMET [GeV]", "eff. HLT_PFHT500_PFMET100_PFMHT100_IDTight",
    "E1", "E1 same", true, "DATA", "MC", "lep", "lep", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_PFMET120_PFMHT120_IDTight___RecoPFMET = DrawCanvas(eff_HLT_PFMET120_RecoPFMET_DATA, eff_HLT_PFMET120_RecoPFMET_MC, "c_HLT_PFMET120_PFMHT120_IDTight___RecoPFMET", "RecoPFMET [GeV]", "eff. HLT_PFMET120_PFMHT120_IDTight",
    "E1", "E1 same", true, "DATA", "MC", "lep", "lep", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET = DrawCanvas(eff_HLT_PFMETNoMu120_RecoPFMET_DATA, eff_HLT_PFMETNoMu120_RecoPFMET_MC, "c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET", "RecoPFMET [GeV]", "eff. HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60",
    "E1", "E1 same", true, "DATA", "MC", "lep", "lep", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_MET105_IsoTrk50___RecoPFMET = DrawCanvas(eff_HLT_MET105_RecoPFMET_DATA, eff_HLT_MET105_RecoPFMET_MC, "c_HLT_MET105_IsoTrk50___RecoPFMET", "RecoPFMET [GeV]", "eff. HLT_MET105_IsoTrk50",
    "E1", "E1 same", true, "DATA", "MC", "lep", "lep", 0, 1200, 0, 1, false);
    TCanvas *c_orMETtrg___RecoPFMET = DrawCanvas(eff_orMETtrg_RecoPFMET_DATA, eff_orMETtrg_RecoPFMET_MC, "c_orMETtrg___RecoPFMET", "RecoPFMET [GeV]", "eff orMETtrg",
    "E1", "E1 same", true, "DATA", "MC", "lep", "lep", 0, 1200, 0, 1, false);

    TCanvas *c_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET__RecoPFMETCut = DrawCanvas(eff_HLT_PFMET120_PseudoCaloMET__RecoPFMETCut_DATA, eff_HLT_PFMET120_PseudoCaloMET__RecoPFMETCut_MC, "c_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET__RecoPFMETCut", "Pseudo MET [GeV]", "eff. HLT_PFMET120_PFMHT120_IDTight w/RecoPFMET>170GeV",
    "E1", "E1 same", true, "DATA", "MC", "lep", "lep", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET__RecoPFMETCut = DrawCanvas(eff_HLT_PFHT500_PseudoCaloMET__RecoPFMETCut_DATA, eff_HLT_PFHT500_PseudoCaloMET__RecoPFMETCut_MC, "c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET__RecoPFMETCut", "Pseudo MET [GeV]", "eff. HLT_PFHT500_PFMET100_PFMHT100_IDTight w/RecoPFMET>170GeV",
    "E1", "E1 same", true, "DATA", "MC", "lep", "lep", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET__RecoPFMETCut = DrawCanvas(eff_HLT_PFMETNoMu120_PseudoCaloMET__RecoPFMETCut_DATA, eff_HLT_PFMETNoMu120_PseudoCaloMET__RecoPFMETCut_MC, "c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET__RecoPFMETCut", "Pseudo MET [GeV]", "eff. HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 w/RecoPFMET>170GeV",
    "E1", "E1 same", true, "DATA", "MC", "lep", "lep", 0, 1200, 0, 1, false);
    TCanvas *c_HLT_MET105_IsoTrk50___PseudoCaloMET__RecoPFMETCut = DrawCanvas(eff_HLT_MET105_PseudoCaloMET__RecoPFMETCut_DATA, eff_HLT_MET105_PseudoCaloMET__RecoPFMETCut_MC, "c_HLT_MET105_IsoTrk50___PseudoCaloMET__RecoPFMETCut", "Pseudo MET [GeV]", "eff. HLT_MET105_IsoTrk50 w/RecoPFMET>170GeV",
    "E1", "E1 same", true, "DATA", "MC", "lep", "lep", 0, 1200, 0, 1, false);
    TCanvas *c_orMETtrg___PseudoCaloMET__RecoPFMETCut = DrawCanvas(eff_orMETtrg_PseudoCaloMET__RecoPFMETCut_DATA, eff_orMETtrg_PseudoCaloMET__RecoPFMETCut_MC, "c_orMETtrg___PseudoCaloMET__RecoPFMETCut", "Pseudo MET [GeV]", "eff orMETtrg w/RecoPFMET>170GeV",
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
    "E1", "E1 same", true, "DATA", "MC", "lep", "lep", 0, 1200, 0, 1, false);*/

    TCanvas *cRatio_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET = DrawWithRatio(eff_HLT_PFMET120_PseudoCaloMET_DATA, eff_HLT_PFMET120_PseudoCaloMET_MC, c_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET, "HLT_PFMET120_PFMHT120_IDTight_pseudoCaloMET", "DATA/MC", "Pseudo MET [GeV]", 0, 1200);
    TCanvas *cRatio_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET = DrawWithRatio(eff_HLT_PFHT500_PseudoCaloMET_DATA, eff_HLT_PFHT500_PseudoCaloMET_MC, c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET, "HLT_PFHT500_PFMET100_PFMHT100_IDTight_pseudoCaloMET", "DATA/MC", "Pseudo MET [GeV]", 0, 1200);
    TCanvas *cRatio_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET = DrawWithRatio(eff_HLT_PFMETNoMu120_PseudoCaloMET_DATA, eff_HLT_PFMETNoMu120_PseudoCaloMET_MC, c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET, "HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60_pseudoCaloMET", "DATA/MC", "Pseudo MET [GeV]", 0, 1200);
    TCanvas *cRatio_HLT_MET105_IsoTrk50___PseudoCaloMET = DrawWithRatio(eff_HLT_MET105_PseudoCaloMET_DATA, eff_HLT_MET105_PseudoCaloMET_MC, c_HLT_MET105_IsoTrk50___PseudoCaloMET, "HLT_MET105_IsoTrk50_pseudoCaloMET", "DATA/MC", "Pseudo MET [GeV]", 0, 1200);
    TCanvas *cRatio_orMETtrg___PseudoCaloMET = DrawWithRatio(eff_orMETtrg_PseudoCaloMET_DATA, eff_orMETtrg_PseudoCaloMET_MC, c_orMETtrg___PseudoCaloMET, "orMETtrg_pseudoCaloMET", "DATA/MC", "Pseudo MET [GeV]", 0, 1200);
    
    latex1->SetTitle("#it{Private work (CMS simulation/data)}");

    cRatio_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET->SaveAs(Form("PlayWithHistos/cRatio_HLT_PFMET120_PFMHT120_IDTight_%s.pdf", ofilename));
    cRatio_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET->SaveAs(Form("PlayWithHistos/cRatio_HLT_PFHT500_PFMET100_PFMHT100_IDTight_%s.pdf", ofilename));
    cRatio_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET->SaveAs(Form("PlayWithHistos/cRatio_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60_%s.pdf", ofilename));
    cRatio_HLT_MET105_IsoTrk50___PseudoCaloMET->SaveAs(Form("PlayWithHistos/cRatio_HLT_MET105_IsoTrk50_%s.pdf", ofilename));
    cRatio_orMETtrg___PseudoCaloMET->SaveAs(Form("PlayWithHistos/cRatio_orMETtrg_%s.pdf", ofilename));


    cRatio_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET->Modified();
    cRatio_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET->Update();
    TCanvas *cRatio_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET_bis = DrawWithRatio(eff_HLT_PFMET120_PseudoCaloMET_DATA, eff_HLT_PFMET120_PseudoCaloMET_MC, c_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET, "HLT_PFMET120_PFMHT120_IDTight_pseudoCaloMET", "DATA/MC", "Pseudo MET [GeV]", 0, 1200);
    cRatio_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET_bis->SaveAs(Form("PlayWithHistos/cRatio_HLT_PFMET120_PFMHT120_IDTight_%s_bis.pdf", ofilename));
    cRatio_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET->Modified();
    cRatio_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET->Update();
    TCanvas *cRatio_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET_bis = DrawWithRatio(eff_HLT_PFHT500_PseudoCaloMET_DATA, eff_HLT_PFHT500_PseudoCaloMET_MC, c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET, "HLT_PFHT500_PFMET100_PFMHT100_IDTight_pseudoCaloMET", "DATA/MC", "Pseudo MET [GeV]", 0, 1200);
    cRatio_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET_bis->SaveAs(Form("PlayWithHistos/cRatio_HLT_PFHT500_PFMET100_PFMHT100_IDTight_%s_bis.pdf", ofilename));
    cRatio_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET->Modified();
    cRatio_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET->Update();
    TCanvas *cRatio_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET_bis = DrawWithRatio(eff_HLT_PFMETNoMu120_PseudoCaloMET_DATA, eff_HLT_PFMETNoMu120_PseudoCaloMET_MC, c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET, "HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60_pseudoCaloMET", "DATA/MC", "Pseudo MET [GeV]", 0, 1200);
    cRatio_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET_bis->SaveAs(Form("PlayWithHistos/cRatio_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60_%s_bis.pdf", ofilename));
    cRatio_HLT_MET105_IsoTrk50___PseudoCaloMET->Modified();
    cRatio_HLT_MET105_IsoTrk50___PseudoCaloMET->Update();
    TCanvas *cRatio_HLT_MET105_IsoTrk50___PseudoCaloMET_bis = DrawWithRatio(eff_HLT_MET105_PseudoCaloMET_DATA, eff_HLT_MET105_PseudoCaloMET_MC, c_HLT_MET105_IsoTrk50___PseudoCaloMET, "HLT_MET105_IsoTrk50_pseudoCaloMET", "DATA/MC", "Pseudo MET [GeV]", 0, 1200);
    cRatio_HLT_MET105_IsoTrk50___PseudoCaloMET_bis->SaveAs(Form("PlayWithHistos/cRatio_HLT_MET105_IsoTrk50_%s_bis.pdf", ofilename));
    cRatio_orMETtrg___PseudoCaloMET->Modified();
    cRatio_orMETtrg___PseudoCaloMET->Update();
    TCanvas *cRatio_orMETtrg___PseudoCaloMET_bis = DrawWithRatio(eff_orMETtrg_PseudoCaloMET_DATA, eff_orMETtrg_PseudoCaloMET_MC, c_orMETtrg___PseudoCaloMET, "orMETtrg_pseudoCaloMET", "DATA/MC", "Pseudo MET [GeV]", 0, 1200);
    cRatio_orMETtrg___PseudoCaloMET_bis->SaveAs(Form("PlayWithHistos/cRatio_orMETtrg_%s_bis.pdf", ofilename));



    /*TCanvas *cRatio_HLT_PFMET120_PFMHT120_IDTight___RecoPFMET = DrawWithRatio(eff_HLT_PFMET120_RecoPFMET_DATA, eff_HLT_PFMET120_RecoPFMET_MC, c_HLT_PFMET120_PFMHT120_IDTight___RecoPFMET, "HLT_PFMET120_PFMHT120_IDTight_pfMET", "DATA/MC", "RecoPFMET [GeV]", 0, 1200);
    TCanvas *cRatio_HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET = DrawWithRatio(eff_HLT_PFHT500_RecoPFMET_DATA, eff_HLT_PFHT500_RecoPFMET_MC, c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET, "HLT_PFHT500_PFMET100_PFMHT100_IDTight_pfMET", "DATA/MC", "RecoPFMET [GeV]", 0, 1200);
    TCanvas *cRatio_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET = DrawWithRatio(eff_HLT_PFMETNoMu120_RecoPFMET_DATA, eff_HLT_PFMETNoMu120_RecoPFMET_MC, c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET, "HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60_pfMET", "DATA/MC", "RecoPFMET [GeV]", 0, 1200);
    TCanvas *cRatio_HLT_MET105_IsoTrk50___RecoPFMET = DrawWithRatio(eff_HLT_MET105_RecoPFMET_DATA, eff_HLT_MET105_RecoPFMET_MC, c_HLT_MET105_IsoTrk50___RecoPFMET, "HLT_MET105_IsoTrk_pfMET", "DATA/MC", "RecoPFMET [GeV]", 0, 1200);
    TCanvas *cRatio_orMETtrg___RecoPFMET = DrawWithRatio(eff_orMETtrg_RecoPFMET_DATA, eff_orMETtrg_RecoPFMET_MC, c_orMETtrg___RecoPFMET, "orMETtrg_pfMET", "DATA/MC", "RecoPFMET [GeV]", 0, 1200);
    
    TCanvas *cRatio_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET__RecoPFMETCut = DrawWithRatio(eff_HLT_PFMET120_PseudoCaloMET__RecoPFMETCut_DATA, eff_HLT_PFMET120_PseudoCaloMET__RecoPFMETCut_MC, c_HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET__RecoPFMETCut, "HLT_PFMET120_PFMHT120_IDTight_w/RecoPFMET>170GeV", "DATA/MC", "Pseudo MET [GeV]", 0, 1200);
    TCanvas *cRatio_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET__RecoPFMETCut = DrawWithRatio(eff_HLT_PFHT500_PseudoCaloMET__RecoPFMETCut_DATA, eff_HLT_PFHT500_PseudoCaloMET__RecoPFMETCut_MC, c_HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET__RecoPFMETCut, "HLT_PFHT500_PFMET100_PFMHT100_IDTight_w/RecoPFMET>170GeV", "DATA/MC", "Pseudo MET [GeV]", 0, 1200);
    TCanvas *cRatio_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET__RecoPFMETCut = DrawWithRatio(eff_HLT_PFMETNoMu120_PseudoCaloMET__RecoPFMETCut_DATA, eff_HLT_PFMETNoMu120_PseudoCaloMET__RecoPFMETCut_MC, c_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET__RecoPFMETCut, "HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60_w/RecoPFMET>170GeV", "DATA/MC", "Pseudo MET [GeV]", 0, 1200);
    TCanvas *cRatio_HLT_MET105_IsoTrk50___PseudoCaloMET__RecoPFMETCut = DrawWithRatio(eff_HLT_MET105_PseudoCaloMET__RecoPFMETCut_DATA, eff_HLT_MET105_PseudoCaloMET__RecoPFMETCut_MC, c_HLT_MET105_IsoTrk50___PseudoCaloMET__RecoPFMETCut, "HLT_MET105_IsoTrk50_w/RecoPFMET>170GeV", "DATA/MC", "Pseudo MET [GeV]", 0, 1200);
    TCanvas *cRatio_orMETtrg___PseudoCaloMET__RecoPFMETCut = DrawWithRatio(eff_orMETtrg_PseudoCaloMET__RecoPFMETCut_DATA, eff_orMETtrg_PseudoCaloMET__RecoPFMETCut_MC, c_orMETtrg___PseudoCaloMET__RecoPFMETCut, "orMETtrg_w/RecoPFMET>170GeV", "DATA/MC", "Pseudo MET [GeV]", 0, 1200);

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
    ofile->Close();*/


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

    TCanvas *c_PseudoCaloMET = DrawCanvas(PseudoCaloMET_DATA, PseudoCaloMET_MC, "c_PseudoCaloMET", "Pseudo MET [GeV]", "Number of events (normalized)",
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

    TCanvas *c_RATIO_PseudoCaloMET = DrawWithRatio(PseudoCaloMET_DATA, PseudoCaloMET_MC, c_PseudoCaloMET, "PseudoCaloMET", "DATA/MC", "Pseudo MET [GeV]", 0, 1000);
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

void Ihand1oP_fits() {

    TFile *ifile = new TFile("../output/JetMET2024_V12/JetMET2024_V12p24.root", "READ");

    // histograms
    TH1F* Ih_new = (TH1F*)ifile->Get("METanalysis_Eta2p4_Ih");
    TH1F* oP_new = (TH1F*)ifile->Get("METanalysis_Eta2p4_10000oP");

    // 1oP fit
    float rangemax_p = 30;
    if (oP_new->GetBinCenter(oP_new->GetMaximumBin()) < rangemax_p) rangemax_p = 0.8 * oP_new->GetBinCenter(oP_new->GetMaximumBin());
    
    TF1 f_p_new("f_p_new", "0.5*(exp([0]*x*x+[1]*x)+exp(-[0]*x*x-[1]*x))-1", 0, rangemax_p);
    float end1oPFit = 0.4 * oP_new->GetBinCenter(oP_new->GetMaximumBin());
    if (end1oPFit > 25) end1oPFit = 25;
    oP_new->Fit(&f_p_new, "R", "", 0, end1oPFit);

    // Ih fit
    float max_ih = Ih_new->GetBinCenter(Ih_new->GetMaximumBin());
   
    float start_fit = 1.2*max_ih;
    int lastBinContent = Ih_new->GetNbinsX();
    while(Ih_new->GetBinContent(lastBinContent)==0) lastBinContent--;
    if(start_fit > Ih_new->GetBinCenter(lastBinContent)) start_fit = max_ih;
    TF1 f_ih_new("f_ih_new", "gaus", start_fit, 6);
    f_ih_new.SetParameter(0, 0.5*Ih_new->Integral());
    f_ih_new.SetParameter(1, max_ih);
    f_ih_new.SetParameter(2, Ih_new->GetStdDev());
    Ih_new->Fit(&f_ih_new, "RL", "", start_fit, 6);


    Ih_new->GetYaxis()->SetTitleSize(0.06);
    Ih_new->GetXaxis()->SetTitleSize(0.06);
    Ih_new->GetXaxis()->SetTitleOffset(0.9);
    Ih_new->GetYaxis()->SetTitleOffset(1);
    Ih_new->GetXaxis()->SetLabelSize(0.05);
    Ih_new->GetYaxis()->SetLabelSize(0.05);
    Ih_new->GetXaxis()->SetTitle("I_{h} [MeV/cm]");
    Ih_new->GetYaxis()->SetTitle("Number of tracks");
    Ih_new->SetLineColor(kBlack);
    Ih_new->SetMarkerStyle(20);
    Ih_new->SetMarkerColor(kBlack);
    Ih_new->GetXaxis()->SetRangeUser(0, 6);

    oP_new->GetYaxis()->SetTitleSize(0.06);
    oP_new->GetXaxis()->SetTitleSize(0.06);
    oP_new->GetXaxis()->SetTitleOffset(0.9);
    oP_new->GetYaxis()->SetTitleOffset(1);
    oP_new->GetXaxis()->SetLabelSize(0.05);
    oP_new->GetYaxis()->SetLabelSize(0.05);
    oP_new->GetXaxis()->SetTitle("10^{4}/p [GeV^{-1}]");
    oP_new->GetYaxis()->SetTitle("Number of tracks");
    oP_new->SetLineColor(kBlack);
    oP_new->SetMarkerStyle(20);
    oP_new->SetMarkerColor(kBlack);
    oP_new->GetXaxis()->SetRangeUser(0, 210);

    TLatex *latex1 = new TLatex(0.16, 0.91, "#scale[1.3]{#bf{CMS}}#it{Work in progress}");
    latex1->SetNDC();
    latex1->SetTextFont(42);
    latex1->SetTextSize(0.04);

    TCanvas *c1 = new TCanvas("c1","c1",800,600);
    c1->cd();
    c1->SetLeftMargin(0.16); c1->SetBottomMargin(0.16);
    gStyle->SetOptStat(0);
    Ih_new->Draw("EO");
    latex1->Draw();
    c1->SetLogy();
    gStyle->SetOptFit(1);
    f_ih_new.SetLineColor(kRed);
    f_ih_new.SetLineWidth(2);
    f_ih_new.Draw("same");
    
    TPaveStats *st = (TPaveStats*)Ih_new->FindObject("stats");
    if (st) {
        st->SetX1NDC(0.2); // new x start position
        st->SetX2NDC(0.6); // new x end position
        st->SetY1NDC(0.2);  // new y start position
        st->SetY2NDC(0.5);  // new y end position
    }
    st->SetTextSize(0.035);
    c1->SaveAs("PlayWithHistos/Ih_newfit.pdf");
    latex1->SetTitle("#it{Private work (CMS data)}");
    c1->Modified();
    c1->Update();
    c1->SaveAs("PlayWithHistos/Ih_newfit_bis.pdf");
    latex1->SetTitle("#scale[1.3]{#bf{CMS}}#it{Work in progress}");


    TCanvas *c2 = new TCanvas("c2","c2",800,600);
    c2->cd();
    c2->SetLeftMargin(0.16); c2->SetBottomMargin(0.16);
    gStyle->SetOptStat(0);
    oP_new->Draw("E0");
    latex1->Draw();
    c2->SetLogy();
    gStyle->SetOptFit(1);
    f_p_new.SetLineColor(kRed);
    f_p_new.SetLineWidth(2);
    f_p_new.SetRange(0, 11);
    f_p_new.Draw("same");
    
    TPaveStats *st2 = (TPaveStats*)oP_new->FindObject("stats");
    if (st2) {
        st2->SetX1NDC(0.3); // new x start position
        st2->SetX2NDC(0.6); // new x end position
        st2->SetY1NDC(0.2);  // new y start position
        st2->SetY2NDC(0.5);  // new y end position
    }
    st2->SetTextSize(0.035);
    c2->SaveAs("PlayWithHistos/oP_newfit.pdf");
    latex1->SetTitle("#it{Private work (CMS data)}");
    c2->Modified();
    c2->Update();
    c2->SaveAs("PlayWithHistos/oP_newfit_bis.pdf");


    return;
}

void BKGdependency_preliminary (const char *inputname, const char *ofilename) {

    TFile *ofile = new TFile(Form("PlayWithHistos/BKGdependency_preliminary_%s.root", ofilename), "RECREATE");
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

    TH2D *fpix_vs_ih_C3fp9 = (TH2D*)ifile->Get("fpix_ih_regionC_3fp9_METanalysis_Eta2p4");
    TH2D *fpix_vs_ih_D9fp10_bis = (TH2D*)ifile->Get("fpix_ih_regionD_9fp10_METanalysis_Eta2p4");

    // add the histograms together
    TH2F *ih_vs_eta = (TH2F*)ih_vs_eta_A3fp9->Clone("ih_vs_eta");
    ih_vs_eta->Add(ih_vs_eta_A9fp10);
    ih_vs_eta->Add(ih_vs_eta_D3fp8);
    ih_vs_eta->Add(ih_vs_eta_D8fp9);
    ih_vs_eta->Add(ih_vs_eta_D9fp10);
    ih_vs_eta->RebinX(4);

    TH2F *fpix_vs_ih = (TH2F*)fpix_vs_ih_A3fp9->Clone("fpix_vs_ih");
    fpix_vs_ih->Add(fpix_vs_ih_A9fp10);
    fpix_vs_ih->Add(fpix_vs_ih_D3fp8);
    fpix_vs_ih->Add(fpix_vs_ih_D8fp9);
    fpix_vs_ih->Add(fpix_vs_ih_D9fp10);

    TH2F *oP_vs_fpix = (TH2F*)oP_vs_fpix_A3fp9->Clone("fpix_vs_oP");
    oP_vs_fpix->Add(oP_vs_fpix_A9fp10);
    oP_vs_fpix->Add(oP_vs_fpix_D3fp8);
    oP_vs_fpix->Add(oP_vs_fpix_D8fp9);
    oP_vs_fpix->Add(oP_vs_fpix_D9fp10);
    TH2F *fpix_vs_oP = TransposeTH2(oP_vs_fpix);

    // projection of fpix_vs_ih_C3fp9
    TH1D *py_C3fp9  = fpix_vs_ih_C3fp9->ProjectionY("py_C3fp9");
    TH1D *py_D9fp10 = fpix_vs_ih_D9fp10_bis->ProjectionY("py_D9fp10");
    
    ofile->cd();
    ih_vs_eta->Write();
    fpix_vs_ih->Write();
    fpix_vs_oP->Write();
    pT_vs_fpix->Write();
    py_C3fp9->Write();
    py_D9fp10->Write();
    ofile->Close();

    return;
}

void BKGdependency () {

    TFile *ifile_TTbar = new TFile("PlayWithHistos/BKGdependency_preliminary_TTbar.root", "READ");
    TFile *ifile_QCD = new TFile("PlayWithHistos/BKGdependency_preliminary_QCD.root", "READ");
    TFile *ifile_Wjets = new TFile("PlayWithHistos/BKGdependency_preliminary_Wjets.root", "READ");

    TH2F *ih_vs_eta__TTbar = (TH2F*)ifile_TTbar->Get("ih_vs_eta");
    TH2F *fpix_vs_ih__TTbar = (TH2F*)ifile_TTbar->Get("fpix_vs_ih");
    TH2F *fpix_vs_oP__TTbar = (TH2F*)ifile_TTbar->Get("fpix_vs_oP_transposed");
    TH2F *pT_vs_fpix__TTbar = (TH2F*)ifile_TTbar->Get("METanalysis_Eta2p4_pT_vs_Fpixel");

    TH2F *ih_vs_eta__QCD = (TH2F*)ifile_QCD->Get("ih_vs_eta");
    TH2F *fpix_vs_oP__QCD = (TH2F*)ifile_QCD->Get("fpix_vs_oP_transposed");
    TH2F *fpix_vs_ih__QCD = (TH2F*)ifile_QCD->Get("fpix_vs_ih");
    TH2F *pT_vs_fpix__QCD = (TH2F*)ifile_QCD->Get("METanalysis_Eta2p4_pT_vs_Fpixel");

    TH2F *ih_vs_eta__Wjets = (TH2F*)ifile_Wjets->Get("ih_vs_eta");
    TH2F *fpix_vs_oP__Wjets = (TH2F*)ifile_Wjets->Get("fpix_vs_oP_transposed");
    TH2F *fpix_vs_ih__Wjets = (TH2F*)ifile_Wjets->Get("fpix_vs_ih");
    TH2F *pT_vs_fpix__Wjets = (TH2F*)ifile_Wjets->Get("METanalysis_Eta2p4_pT_vs_Fpixel");

    TH1F *py_C3fp9__TTbar = (TH1F*)ifile_TTbar->Get("py_C3fp9");
    TH1F *py_C3fp9__QCD = (TH1F*)ifile_QCD->Get("py_C3fp9");
    TH1F *py_C3fp9__Wjets = (TH1F*)ifile_Wjets->Get("py_C3fp9");

    TH1F *py_D9fp10__TTbar = (TH1F*)ifile_TTbar->Get("py_D9fp10");
    TH1F *py_D9fp10__QCD = (TH1F*)ifile_QCD->Get("py_D9fp10");
    TH1F *py_D9fp10__Wjets = (TH1F*)ifile_Wjets->Get("py_D9fp10");
    

    // sum the histograms together
    TH2F *ih_vs_eta = (TH2F*)ih_vs_eta__TTbar->Clone("ih_vs_eta_b");
    ih_vs_eta->Add(ih_vs_eta__QCD); ih_vs_eta->Add(ih_vs_eta__Wjets);
    TH2F *fpix_vs_ih = (TH2F*)fpix_vs_ih__TTbar->Clone("fpix_vs_ih_b");
    fpix_vs_ih->Add(fpix_vs_ih__QCD); fpix_vs_ih->Add(fpix_vs_ih__Wjets);
    TH2F *fpix_vs_oP = (TH2F*)fpix_vs_oP__TTbar->Clone("fpix_vs_oP_b");
    fpix_vs_oP->Add(fpix_vs_oP__QCD); fpix_vs_oP->Add(fpix_vs_oP__Wjets);
    TH2F *pT_vs_fpix = (TH2F*)pT_vs_fpix__TTbar->Clone("pT_vs_fpix_b");
    pT_vs_fpix->Add(pT_vs_fpix__QCD); pT_vs_fpix->Add(pT_vs_fpix__Wjets);
    TH1F *py_C3fp9 = (TH1F*)py_C3fp9__TTbar->Clone("py_C3fp9");
    py_C3fp9->Add(py_C3fp9__QCD); py_C3fp9->Add(py_C3fp9__Wjets);
    TH1F *py_D9fp10 = (TH1F*)py_D9fp10__TTbar->Clone("py_D9fp10");
    py_D9fp10->Add(py_D9fp10__QCD); py_D9fp10->Add(py_D9fp10__Wjets);

    // plot the profile
    TProfile *profile_ih_vs_eta = ih_vs_eta->ProfileX("profile_ih_vs_eta");
    TProfile *profile_fpix_vs_ih = fpix_vs_ih->ProfileX("profile_fpix_vs_ih");
    TProfile *profile_fpix_vs_oP = fpix_vs_oP->ProfileX("profile_fpix_vs_oP");
    TProfile *profile_pT_vs_fpix = pT_vs_fpix->ProfileX("profile_pT_vs_fpix");


    fpix_vs_ih->GetXaxis()->SetTitle("F_{pixel}");
    fpix_vs_ih->GetYaxis()->SetTitle("I_{h} [MeV/cm]");
    fpix_vs_ih->GetYaxis()->SetTitleOffset(1.2);
    fpix_vs_ih->GetZaxis()->SetTitle("Events");
    fpix_vs_ih->SetTitle("");
    fpix_vs_ih->GetYaxis()->SetTitleSize(0.06);
    fpix_vs_ih->GetXaxis()->SetTitleSize(0.06);
    fpix_vs_ih->GetXaxis()->SetTitleOffset(0.9);
    fpix_vs_ih->GetYaxis()->SetTitleOffset(1.1);
    fpix_vs_ih->GetXaxis()->SetLabelSize(0.05);
    fpix_vs_ih->GetYaxis()->SetLabelSize(0.05);
    fpix_vs_ih->GetZaxis()->SetTitleSize(0.06);
    fpix_vs_ih->GetZaxis()->SetTitleOffset(0.9);
    fpix_vs_ih->GetZaxis()->SetLabelSize(0.05);

    fpix_vs_oP->GetXaxis()->SetTitle("F_{pixel}");
    fpix_vs_oP->GetYaxis()->SetTitle("10^{4}/p [GeV^{-1}]");
    fpix_vs_oP->GetYaxis()->SetTitleOffset(1.2);
    fpix_vs_oP->GetZaxis()->SetTitle("Events");
    fpix_vs_oP->SetTitle("");
    fpix_vs_oP->GetYaxis()->SetTitleSize(0.06);
    fpix_vs_oP->GetXaxis()->SetTitleSize(0.06);
    fpix_vs_oP->GetXaxis()->SetTitleOffset(0.9);
    fpix_vs_oP->GetYaxis()->SetTitleOffset(1);
    fpix_vs_oP->GetXaxis()->SetLabelSize(0.05);
    fpix_vs_oP->GetYaxis()->SetLabelSize(0.05);
    fpix_vs_oP->GetZaxis()->SetTitleSize(0.06);
    fpix_vs_oP->GetZaxis()->SetTitleOffset(0.9);
    fpix_vs_oP->GetZaxis()->SetLabelSize(0.05);

    TLatex *latex1 = new TLatex(0.16, 0.91, "#scale[1.3]{#bf{CMS}}#it{Simulation Work in progress}");
    latex1->SetNDC();
    latex1->SetTextFont(42);
    latex1->SetTextSize(0.04);


    TCanvas *c_fpix_vs_ih = new TCanvas("c_fpix_vs_ih", "c_fpix_vs_ih", 800, 600);
    c_fpix_vs_ih->SetLeftMargin(0.16); c_fpix_vs_ih->SetBottomMargin(0.16); c_fpix_vs_ih->SetRightMargin(0.16);
    fpix_vs_ih->Draw("COLZ");
    profile_fpix_vs_ih->SetMarkerStyle(20);
    profile_fpix_vs_ih->SetMarkerColor(kRed);
    profile_fpix_vs_ih->SetLineColor(kRed);
    profile_fpix_vs_ih->Draw("sameP");
    c_fpix_vs_ih->SetLogz();
    gStyle->SetOptStat(0);
    latex1->Draw();
    c_fpix_vs_ih->SaveAs("PlayWithHistos/Correlation_fpix_ih.pdf");
    latex1->SetTitle("#it{Private work (CMS simulation)}");
    c_fpix_vs_ih->Modified();
    c_fpix_vs_ih->Update();
    c_fpix_vs_ih->SaveAs("PlayWithHistos/Correlation_fpix_ih_bis.pdf");
    latex1->SetTitle("#scale[1.3]{#bf{CMS}}#it{Simulation Work in progress}");
    fpix_vs_ih->GetYaxis()->SetRangeUser(3.29, 3.31);
    c_fpix_vs_ih->Update();
    c_fpix_vs_ih->SaveAs("PlayWithHistos/Correlation_fpix_ih__ZOOM.pdf");
    latex1->SetTitle("#it{Private work (CMS simulation)}");
    c_fpix_vs_ih->Modified();
    c_fpix_vs_ih->Update();
    c_fpix_vs_ih->SaveAs("PlayWithHistos/Correlation_fpix_ih__ZOOM_bis.pdf");
    latex1->SetTitle("#scale[1.3]{#bf{CMS}}#it{Simulation Work in progress}");

    TCanvas *c_fpix_vs_oP = new TCanvas("c_fpix_vs_oP", "c_fpix_vs_oP", 800, 600);
    c_fpix_vs_oP->SetLeftMargin(0.16); c_fpix_vs_oP->SetBottomMargin(0.16); c_fpix_vs_oP->SetRightMargin(0.16);
    fpix_vs_oP->Draw("COLZ");
    profile_fpix_vs_oP->SetMarkerStyle(20);
    profile_fpix_vs_oP->SetMarkerColor(kRed);
    profile_fpix_vs_oP->SetLineColor(kRed);
    profile_fpix_vs_oP->Draw("sameP");
    c_fpix_vs_oP->SetLogz();
    gStyle->SetOptStat(0);
    latex1->Draw();
    c_fpix_vs_oP->SaveAs("PlayWithHistos/Correlation_fpix_1oP.pdf");
    latex1->SetTitle("#it{Private work (CMS simulation)}");
    c_fpix_vs_oP->Modified();
    c_fpix_vs_oP->Update();
    c_fpix_vs_oP->SaveAs("PlayWithHistos/Correlation_fpix_1oP_bis.pdf");
    latex1->SetTitle("#scale[1.3]{#bf{CMS}}#it{Simulation Work in progress}");
    fpix_vs_oP->GetYaxis()->SetRangeUser(40, 60);
    c_fpix_vs_oP->Update();
    c_fpix_vs_oP->SaveAs("PlayWithHistos/Correlation_fpix_1oP__ZOOM.pdf");
    latex1->SetTitle("#it{Private work (CMS simulation)}");
    c_fpix_vs_oP->Modified();
    c_fpix_vs_oP->Update();
    c_fpix_vs_oP->SaveAs("PlayWithHistos/Correlation_fpix_1oP__ZOOM_bis.pdf");


    // Ih ratio in C and D
    py_C3fp9->Rebin(4); py_D9fp10->Rebin(4);
    py_C3fp9->Scale(1.0/py_C3fp9->Integral());
    py_D9fp10->Scale(1.0/py_D9fp10->Integral());
    
    py_C3fp9->GetYaxis()->SetTitle("Events (normalised)");
    py_C3fp9->GetXaxis()->SetTitle("I_{h} [MeV/cm]");
    py_C3fp9->SetTitle("");
    py_C3fp9->GetYaxis()->SetTitleSize(0.06);
    py_C3fp9->GetXaxis()->SetTitleSize(0.06);
    py_C3fp9->GetXaxis()->SetTitleOffset(0.9);
    py_C3fp9->GetYaxis()->SetTitleOffset(1);
    py_C3fp9->GetXaxis()->SetLabelSize(0.05);
    py_C3fp9->GetYaxis()->SetLabelSize(0.05);
    py_C3fp9->GetXaxis()->SetRangeUser(0, 8);
    py_C3fp9->SetLineColor(kBlue);
    py_C3fp9->SetLineWidth(2);

    py_D9fp10->SetLineColor(kRed);
    py_D9fp10->SetLineWidth(2);
    latex1->SetTitle("#scale[1.3]{#bf{CMS}}#it{Simulation Work in progress}");
    

    TCanvas *c1 = new TCanvas("c1", "c1", 800, 600);
    TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1);
    pad1->SetBottomMargin(0.16); pad1->SetLeftMargin(0.16);
    pad1->Draw();
    pad1->cd();

    py_C3fp9->Draw("hist");
    py_D9fp10->Draw("hist same");
    pad1->SetLogy();
    
    TLegend *legend = new TLegend(0.6, 0.6, 0.9, 0.9);
    legend->AddEntry(py_C3fp9, "F_{pixel} #leq 0.9", "l");
    legend->AddEntry(py_D9fp10, "F_{pixel} > 0.9", "l");
    legend->SetBorderSize(0);
    legend->SetFillStyle(0);
    legend->SetTextSize(0.045);
    legend->Draw();
    gStyle->SetOptStat(0);
    latex1->Draw();
    
    // Ratio plot
    c1->cd();
    TPad *pad2 = new TPad("pad2", "pad2", 0, 0, 1, 0.3);
    pad2->SetTopMargin(0); pad2->SetLeftMargin(0.16);
    pad2->SetBottomMargin(0.3);
    pad2->Draw();
    pad2->cd();

    TH1D *hRatio = (TH1D*)py_C3fp9->Clone("C_over_D");
    hRatio->Divide(py_D9fp10);
    hRatio->SetMarkerStyle(20);
    hRatio->SetMarkerColor(kBlack);
    hRatio->SetLineColor(kBlack);

    hRatio->GetYaxis()->SetNdivisions(505);
    hRatio->GetYaxis()->SetTitleSize(0.08);
    hRatio->GetYaxis()->SetTitleFont(43);
    hRatio->GetXaxis()->SetTitleFont(43);
    hRatio->GetYaxis()->SetLabelFont(43);
    hRatio->GetXaxis()->SetLabelFont(43);
    hRatio->GetYaxis()->SetTitleSize(24);  // px
    hRatio->GetXaxis()->SetTitleSize(24);
    hRatio->GetYaxis()->SetLabelSize(20);
    hRatio->GetXaxis()->SetLabelSize(20);
    hRatio->GetYaxis()->SetTitleOffset(1.4);   // en font pixel, ~1.0 est correct
    hRatio->GetXaxis()->SetTitleOffset(1.0);

    hRatio->Draw("E1");
    TLine *line = new TLine(hRatio->GetXaxis()->GetXmin(), 1, 8, 1);
    line->SetLineStyle(2);
    gStyle->SetOptStat(0);
    line->Draw("same");
    hRatio->GetYaxis()->SetTitle("I_{h}^{C}/I_{h}^{D}  ");
    hRatio->GetXaxis()->SetTitle("I_{h} [MeV/cm]");
    hRatio->SetMinimum(0.8);
    hRatio->SetMaximum(1.2);

    //fit hRatio with a linear function:
    hRatio->Fit("pol1", "R", "", 2.5, 5);

    c1->SaveAs("PlayWithHistos/IhRatio.pdf");
    latex1->SetTitle("#it{Private work (CMS simulation)}");
    c1->Modified();
    c1->Update();
    c1->SaveAs("PlayWithHistos/IhRatio_bis.pdf");

    return;
}

void GluinoP_mass(bool isPythia, bool isWeighted) {

    TFile *ofile = new TFile(Form("PlayWithHistos/GluinoP_mass_%s_%s.root", isPythia ? "pythia" : "madgraph", isWeighted ? "weighted" : ""), "RECREATE");

    // create a std::vector of ifile where to retrieve the pT vs Fpixel histograms in each:
    std::vector<TFile*> ifiles;
    std::vector<TString> labels;
    if (isPythia) labels = {"1000", "1200", "1400", "1600", "1800", "2000", "2200", "2400", "2600"};
    else labels = {"1100", "1200", "1300", "1400", "1600", "1800", "2000", "2200", "2400", "2600"};

    for (unsigned int i=0; i<labels.size(); i++) ifiles.push_back(new TFile(Form("../output/Gluino_V19/Gluino_Run3_MET_%s%s_V19p%s_%s.root", isPythia ? "" : "madgraph_", labels[i].Data(), isPythia ? "0" : "1", isWeighted ? "weighted" : ""), "READ"));

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

        float nEntries_CR = 0;
        for (int xbin = 1; xbin <= pT_vs_Fpixel->GetNbinsX(); xbin++) {
            for (int ybin = 1; ybin <= pT_vs_Fpixel->GetNbinsY(); ybin++) {
                if (pT_vs_Fpixel->GetXaxis()->GetBinCenter(xbin) <= fpix_cut || pT_vs_Fpixel->GetYaxis()->GetBinCenter(ybin) <= 70) {
                    nEntries_CR += pT_vs_Fpixel->GetBinContent(xbin, ybin);
                }
            }
        }
        cout << "Number of entries in the CR (pT<=70 and Fpix<=" << fpix_cut << ") for m=" << labels[i].Data() << ": " << nEntries_CR << " / " << pT_vs_Fpixel->Integral() << " (" << 100.0*nEntries_CR/pT_vs_Fpixel->Integral() << "%)" << endl;

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

    float nEntries_CR = 0;
    for (int xbin = 1; xbin <= pT_vs_Fpixel_sum->GetNbinsX(); xbin++) {
        for (int ybin = 1; ybin <= pT_vs_Fpixel_sum->GetNbinsY(); ybin++) {
            if (pT_vs_Fpixel_sum->GetXaxis()->GetBinCenter(xbin) <= fpix_cut || pT_vs_Fpixel_sum->GetYaxis()->GetBinCenter(ybin) <= 70) {
                nEntries_CR += pT_vs_Fpixel_sum->GetBinContent(xbin, ybin);
            }
        }
    }
    cout << "Number of entries in the CR (pT<=70 and Fpix<=" << fpix_cut << ") (TOTAL): " << nEntries_CR << " / " << pT_vs_Fpixel_sum->Integral() << " (" << 100.0*nEntries_CR/pT_vs_Fpixel_sum->Integral() << "%)" << endl;

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
    TFile *GluinoRun3madgraph = new TFile("PlayWithHistos/GluinoP_mass_madgraph_weighted.root", "READ");

    TLatex *latex1 = new TLatex(0.155, 0.91, "#scale[1.3]{#bf{CMS}}#it{Simulation Work in progress}");
    latex1->SetNDC();
    latex1->SetTextFont(42);
    latex1->SetTextSize(0.04);


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
    pT_vs_fpix_ratio->Rebin2D(5,5);

    // canvas of the ratio
    TCanvas *c_ratio = new TCanvas("c_ratio", "c_ratio", 800, 600);
    pT_vs_fpix_ratio->GetXaxis()->SetTitle("F_{pixel}");
    pT_vs_fpix_ratio->GetYaxis()->SetTitle("p_{T} [GeV]");
    pT_vs_fpix_ratio->Draw("TEXT");

    TCanvas *c_bkg_gluino = new TCanvas("c_bkg_gluino", "c_bkg_gluino", 800, 600);
    c_bkg_gluino->SetLeftMargin(0.16); c_bkg_gluino->SetRightMargin(0.16); c_bkg_gluino->SetBottomMargin(0.16);
    pT_vs_fpix_bkg->GetXaxis()->SetTitle("F_{pixel}");
    pT_vs_fpix_bkg->GetYaxis()->SetTitle("p_{T} [GeV]");
    pT_vs_fpix_bkg->Draw("COLZ");

    TProfile *profile_pT_vs_fpix_bkg = pT_vs_fpix_bkg->ProfileX("profile_pT_vs_fpix_bkg");
    profile_pT_vs_fpix_bkg->SetLineColor(kRed);
    profile_pT_vs_fpix_bkg->SetMarkerColor(kRed);
    profile_pT_vs_fpix_bkg->Draw("sameP");

    pT_vs_fpix_bkg->GetYaxis()->SetTitleSize(0.06);
    pT_vs_fpix_bkg->GetXaxis()->SetTitleSize(0.06);
    pT_vs_fpix_bkg->GetXaxis()->SetTitleOffset(0.9);
    pT_vs_fpix_bkg->GetYaxis()->SetTitleOffset(1.1);
    pT_vs_fpix_bkg->GetXaxis()->SetLabelSize(0.05);
    pT_vs_fpix_bkg->GetYaxis()->SetLabelSize(0.05);
    pT_vs_fpix_bkg->GetZaxis()->SetTitleSize(0.06);
    pT_vs_fpix_bkg->GetZaxis()->SetTitleOffset(0.9);
    pT_vs_fpix_bkg->GetZaxis()->SetLabelSize(0.05);

    pT_vs_fpix_gluino->GetYaxis()->SetTitleSize(0.06);
    pT_vs_fpix_gluino->GetXaxis()->SetTitleSize(0.06);
    pT_vs_fpix_gluino->GetXaxis()->SetTitleOffset(0.9);
    pT_vs_fpix_gluino->GetYaxis()->SetTitleOffset(1.1);
    pT_vs_fpix_gluino->GetXaxis()->SetLabelSize(0.05);
    pT_vs_fpix_gluino->GetYaxis()->SetLabelSize(0.05);
    pT_vs_fpix_gluino->GetZaxis()->SetTitleSize(0.06);
    pT_vs_fpix_gluino->GetZaxis()->SetTitleOffset(0.9);
    pT_vs_fpix_gluino->GetZaxis()->SetLabelSize(0.05);

    pT_vs_fpix_gluino->GetXaxis()->SetTitle("F_{pixel}");
    pT_vs_fpix_gluino->GetYaxis()->SetTitle("p_{T} [GeV]");

    //pT_vs_fpix_gluino->Draw("COLZ");
    latex1->Draw("same");
    c_bkg_gluino->SetLogz();


    // cout number of event bellow each .1 in Fpixel, for both hists.
    
    for (int i=1; i<=10; i++) {
        float fpix_cut = 0.1*i;
        int nEntries_bkg = 0;
        float nEntries_gluino = 0;
        for (int xbin = 1; xbin <= pT_vs_fpix_bkg->GetNbinsX(); xbin++) {
            for (int ybin = 1; ybin <= pT_vs_fpix_bkg->GetNbinsY(); ybin++) {
                if (pT_vs_fpix_bkg->GetXaxis()->GetBinCenter(xbin) <= fpix_cut) {
                    nEntries_bkg += pT_vs_fpix_bkg->GetBinContent(xbin, ybin);
                    nEntries_gluino += pT_vs_fpix_gluino->GetBinContent(xbin, ybin);
                }
            }
        }
        cout << "Number of entries with Fpixel <= " << fpix_cut << ": " << nEntries_bkg << " (bkg), " << nEntries_gluino << " (gluino)" << "    (" << 100.0*nEntries_gluino/nEntries_bkg << " %)" << endl;
    }
    gStyle->SetOptStat(0);
    c_bkg_gluino->SaveAs("PlayWithHistos/CompareMaping_mc.pdf");


    ofile->cd();
    c_ratio->Write();
    c_bkg_gluino->Write();
    ofile->Close();

    return;
}

void FpixelPlot() {

    TFile *ofile = new TFile("PlayWithHistos/Nm1_plots.root", "RECREATE");

    TFile *fileWjets = new TFile("../output/Wjets2024_V14/WjetMuNu2024_V14p11_weighted.root", "READ");
    TFile *ifile_JetMETdata = new TFile("../output/JetMET2024_V12/JetMET2024_V12p24.root", "READ");
    TFile *ifile_Gluino = new TFile("../output/Gluino_V19/Gluino_Run3_MET_madgraph_2000_V19p1.root", "READ");


    TH1F *fpix_JetMETdata = (TH1F*)ifile_JetMETdata->Get("Nosel_Fpix");
    TH1F *fpix_Gluino = (TH1F*)ifile_Gluino->Get("Nosel_Fpix");
    TH1F *fpix_Wjets = (TH1F*)fileWjets->Get("Nosel_Fpix");
    fpix_JetMETdata->Scale(1./fpix_JetMETdata->Integral());
    fpix_Gluino->Scale(1./fpix_Gluino->Integral());
    fpix_Wjets->Scale(1./fpix_Wjets->Integral());

    fpix_Wjets->SetBinContent(1,0);
    fpix_Wjets->SetBinContent(2,0);
    fpix_Wjets->SetBinContent(3,0);
    fpix_Wjets->SetBinContent(4,0);
    fpix_Wjets->SetBinContent(5,0);

    fpix_Gluino->SetBinContent(1,0);
    fpix_Gluino->SetBinContent(2,0);
    fpix_Gluino->SetBinContent(3,0);
    fpix_Gluino->SetBinContent(4,0);
    fpix_Gluino->SetBinContent(5,0);

    fpix_Wjets->SetLineWidth(2);

    //draw vertical dashed line black at fpix = 0.9
    TLine *line = new TLine(0.9, 0, 0.9, fpix_Gluino->GetMaximum()*1.05);
    line->SetLineStyle(2);
    line->SetLineColor(kBlack);
    line->SetLineWidth(2);
    


    fpix_Gluino->GetYaxis()->SetTitleSize(0.06);
    fpix_Gluino->GetXaxis()->SetTitleSize(0.06);
    fpix_Gluino->GetXaxis()->SetTitleOffset(0.9);
    fpix_Gluino->GetYaxis()->SetTitleOffset(1.1);
    fpix_Gluino->GetXaxis()->SetLabelSize(0.05);
    fpix_Gluino->GetYaxis()->SetLabelSize(0.05);

    TCanvas *c_fpix = new TCanvas("c_fpix", "c_fpix", 800, 600);
    c_fpix->SetLeftMargin(0.16); c_fpix->SetBottomMargin(0.16);
    fpix_JetMETdata->SetLineColor(kBlack);
    fpix_JetMETdata->SetMarkerColor(kBlack);
    fpix_JetMETdata->SetMarkerStyle(20);
    fpix_Gluino->GetXaxis()->SetTitle("F_{pixel}");
    fpix_Gluino->GetYaxis()->SetTitle("Events (normalised)");
    fpix_Gluino->SetFillColorAlpha(kRed, 0.5);
    fpix_Gluino->SetLineColor(kRed);
    fpix_Wjets->SetLineColor(kBlue);
    fpix_Gluino->Draw("HIST");
    fpix_Wjets->Draw("HIST same");
    line->Draw("same");
    //fpix_JetMETdata->Draw("E1 same");
    TLegend *legend_fpix = new TLegend(0.2, 0.5, 0.5, 0.7);
    //legend_fpix->AddEntry(fpix_JetMETdata, "JetMET 2024 data", "lep");
    legend_fpix->AddEntry(fpix_Wjets, "MC Wjet 2024", "lep");
    legend_fpix->AddEntry(fpix_Gluino, "#tilde{g}_{m=2000 GeV}", "f");
    legend_fpix->SetBorderSize(0);
    legend_fpix->SetFillStyle(0);
    legend_fpix->Draw();

    // remove stat using SetOptStat(0);
    gStyle->SetOptStat(0);
    
    TLatex *latex1 = new TLatex(0.155, 0.91, "#scale[1.3]{#bf{CMS}}#it{Simulation Work in progress}");
    latex1->SetNDC();
    latex1->SetTextFont(42);
    latex1->SetTextSize(0.04);
    latex1->Draw();
    //latex1->SetTitle("#it{Private work (CMS simulation)}");

    c_fpix->SaveAs("PlayWithHistos/Fpixel_plot.pdf");
}

void Nm1Eff (bool isRescaled, bool isOnlyWjets, std::string QCD, std::string TTbar, std::string Wjets, std::string JetMETdata, std::string Gluino) {

    gErrorIgnoreLevel = kWarning;

    TFile *ifile_QCD = new TFile(QCD.c_str(), "READ");
    TFile *ifile_TTbar = new TFile(TTbar.c_str(), "READ");
    TFile *ifile_Wjets = new TFile(Wjets.c_str(), "READ");
    TFile *ifile_JetMETdata = new TFile(JetMETdata.c_str(), "READ");
    TFile *ifile_Gluino = new TFile(Gluino.c_str(), "READ");

    std::vector<TH1F*> hNM1_QCD, hNM1_TTbar, hNM1_Wjets, hNM1_MC, hNM1_JetMETdata, hNM1_Gluino;
    
    std::vector<string> cutNames = {"trigger", "METfilters", "CaloMET", "CaloMET_rescaled", "Ptpseudo", "eta", "NOPH", "FOVH", "NOM", "HighPurity", 
    "Chi2", "dZ", "dXY", "PFMiniIso", "TrkIso", "EoverP", "PtErr_over_PtPt", "Fpix", "PtErr_over_Pt", "Ih_StripOnly", "Ih_StripOnly_rescaled"};

    std::vector<string> Xlabel = {"orMETtrigger", "METfilters", "PseudoMET", "PseudoMET rescaled", "p_{T} [GeV]", "eta", "Nb pixel hits", "frac. valid hits", "Nb dE/dx", "HighPurity", 
    "#chi^{2}/NDOF", "dz [cm]", "dxy [cm]", "I_{PF}^{rel}", "I_{dr03}^{trk}", "E/p", "#sigma_{p_{T}}/p_{T}^{2}", "F_{pixel}", "#sigma_{p_{T}}/p_{T}", "I_{h} [MeV/cm]", "I_{h} rescaled [MeV/cm]"};

    // Step 1: retrieve the Nm1 hists
    for (size_t i = 0; i < cutNames.size(); i++) {

        if (cutNames[i] == "Ih_StripOnly_rescaled") {
            hNM1_JetMETdata.push_back((TH1F*)ifile_JetMETdata->Get(Form("Nm1_event_%s", cutNames[i-1].c_str())));
            
            hNM1_QCD.push_back((TH1F*)ifile_QCD->Get(Form("Nm1_event_%s", cutNames[i-1].c_str())));
            hNM1_TTbar.push_back((TH1F*)ifile_TTbar->Get(Form("Nm1_event_%s", cutNames[i-1].c_str())));
            hNM1_Wjets.push_back((TH1F*)ifile_Wjets->Get(Form("Nm1_event_%s", cutNames[i].c_str())));
            hNM1_Gluino.push_back((TH1F*)ifile_Gluino->Get(Form("Nm1_event_%s", cutNames[i].c_str())));

            hNM1_MC.push_back((TH1F*)ifile_Wjets->Get(Form("Nm1_event_%s", cutNames[i-1].c_str())));
        }
        
        if (cutNames[i] == "CaloMET_rescaled") {
            hNM1_JetMETdata.push_back((TH1F*)ifile_JetMETdata->Get(Form("Nm1_event_%s", cutNames[i-1].c_str())));
            hNM1_QCD.push_back((TH1F*)ifile_QCD->Get("Nm1_event_CaloMET_weighted"));
            hNM1_TTbar.push_back((TH1F*)ifile_TTbar->Get("Nm1_event_CaloMET_weighted"));
        }
        else {
            hNM1_JetMETdata.push_back((TH1F*)ifile_JetMETdata->Get(Form("Nm1_event_%s", cutNames[i].c_str())));
            hNM1_QCD.push_back((TH1F*)ifile_QCD->Get(Form("Nm1_event_%s", cutNames[i].c_str())));
            hNM1_TTbar.push_back((TH1F*)ifile_TTbar->Get(Form("Nm1_event_%s", cutNames[i].c_str())));
        }

        hNM1_Wjets.push_back((TH1F*)ifile_Wjets->Get(Form("Nm1_event_%s", cutNames[i].c_str())));
        hNM1_Gluino.push_back((TH1F*)ifile_Gluino->Get(Form("Nm1_event_%s", cutNames[i].c_str())));

        hNM1_MC.push_back((TH1F*)ifile_Wjets->Get(Form("Nm1_event_%s", cutNames[i].c_str())));
    }

    // Step 2: change the style of the hists
    for (size_t i = 0; i < cutNames.size(); i++) {
        cout << "Cut: " << cutNames[i] << endl;
        hNM1_MC[i]->Add(hNM1_TTbar[i]);
        hNM1_MC[i]->Add(hNM1_QCD[i]);

        hNM1_QCD[i]->SetLineColor(kGreen-4);
        hNM1_QCD[i]->SetFillColorAlpha(kGreen-4, 0.5);
        hNM1_TTbar[i]->SetLineColor(kRed);
        hNM1_TTbar[i]->SetFillColorAlpha(kRed, 0.5);
        hNM1_Wjets[i]->SetLineColor(kBlue-7);
        hNM1_Wjets[i]->SetFillColorAlpha(kBlue-7, 0.5);
        hNM1_Gluino[i]->SetLineColor(kOrange+8);
        hNM1_Gluino[i]->SetMarkerStyle(22);
        hNM1_Gluino[i]->SetMarkerColor(kOrange+8);
        hNM1_JetMETdata[i]->SetLineColor(kBlack);
        hNM1_JetMETdata[i]->SetMarkerColor(kBlack);
        hNM1_JetMETdata[i]->SetMarkerStyle(20);
    }

    // Step 2 bis: if rescaled, scale all the hists to 1
    if (isRescaled && !isOnlyWjets) {
        for (size_t i = 0; i < cutNames.size(); i++) {
            float intTot = hNM1_QCD[i]->Integral() + hNM1_TTbar[i]->Integral() + hNM1_Wjets[i]->Integral();
            hNM1_QCD[i]->Scale(hNM1_JetMETdata[i]->Integral()/intTot);
            hNM1_TTbar[i]->Scale(hNM1_JetMETdata[i]->Integral()/intTot);
            hNM1_Wjets[i]->Scale(hNM1_JetMETdata[i]->Integral()/intTot);
            hNM1_Gluino[i]->Scale(hNM1_JetMETdata[i]->Integral()/hNM1_Gluino[i]->Integral());
        }
    }
    else if (isRescaled && isOnlyWjets) {
        for (size_t i = 0; i < cutNames.size(); i++) {
            hNM1_Wjets[i]->Scale(hNM1_JetMETdata[i]->Integral()/hNM1_Wjets[i]->Integral());
            hNM1_Gluino[i]->Scale(hNM1_JetMETdata[i]->Integral()/hNM1_Gluino[i]->Integral());
        }
    }

    // Step 3: Canvas for each hists
    std::vector<TCanvas*> canvases;
    // line at x=2.9784 (=C_2024)
    TLine *line = new TLine(2.9784, 0, 2.9784, 1);
    line->SetLineColor(kRed);
    line->SetLineStyle(2);
    for (size_t i = 0; i < cutNames.size(); i++) {

        TCanvas *c = new TCanvas(Form("c_Nm1_%s", cutNames[i].c_str()), Form("c_Nm1_%s", cutNames[i].c_str()), 800, 600);

        THStack *hs = new THStack(Form("hs_%s", cutNames[i].c_str()), "");
        if (!isOnlyWjets) {
            hs->Add(hNM1_QCD[i]);
            hs->Add(hNM1_TTbar[i]);
            hs->Add(hNM1_Wjets[i]);
        }
        else hs->Add(hNM1_Wjets[i]);
        hs->Draw("HIST");
        hs->SetMaximum(std::max(hs->GetMaximum()*1.5, hNM1_JetMETdata[i]->GetMaximum()*1.5));
        hs->SetMinimum(std::min(hs->GetMinimum() == 0 ? 1 : hs->GetMinimum()/2, hNM1_JetMETdata[i]->GetMinimum() == 0 ? 1 : hNM1_JetMETdata[i]->GetMinimum()/2));
        hs->GetXaxis()->SetTitle(Xlabel[i].c_str());
        hs->GetYaxis()->SetTitle("Number of events");

        hNM1_JetMETdata[i]->SetMarkerStyle(20);
        hNM1_JetMETdata[i]->SetMarkerColor(kBlack);
        hNM1_JetMETdata[i]->SetLineColor(kBlack);
        hNM1_JetMETdata[i]->Draw("E1 same");

        hNM1_Gluino[i]->Draw("E1 same");

        double ymin = std::min(hs->GetMinimum() == 0 ? 1 : hs->GetMinimum()/2, hNM1_JetMETdata[i]->GetMinimum() == 0 ? 1 : hNM1_JetMETdata[i]->GetMinimum()/2);
        double ymax = std::max(hs->GetMaximum()*1.5, hNM1_JetMETdata[i]->GetMaximum()*1.5);
        TLine *line = new TLine(2.9784, ymin, 2.9784, ymax);
        line->SetLineColor(kRed);
        line->SetLineStyle(2);
        if (cutNames[i] == "Ih_StripOnly_rescaled" || cutNames[i] == "Ih_StripOnly") line->Draw("same");

        TLegend *legend = new TLegend(0.7, 0.5, 0.85, 0.9);
        if (!isOnlyWjets) {
            legend->AddEntry(hNM1_QCD[i],       "QCD muEnriched",       "f");
            legend->AddEntry(hNM1_TTbar[i],     "TTbar",     "f");
        }
        legend->AddEntry(hNM1_Wjets[i],     "W+jets",    "f");
        legend->AddEntry(hNM1_JetMETdata[i],"JetMET data","lep");
        legend->AddEntry(hNM1_Gluino[i],     "#tilde{g} m=2000 GeV", "lep");
        legend->SetBorderSize(0);
        legend->SetFillStyle(0);
        legend->Draw();

        c->SetLogy();

        TH1F *htemp = (TH1F*)hNM1_Wjets[i]->Clone("htemp");
        if (!isOnlyWjets) {
            htemp->Add(hNM1_TTbar[i]);
            htemp->Add(hNM1_QCD[i]);
        }

        TCanvas *cRatio = DrawWithRatio(hNM1_JetMETdata[i], htemp, c, Form("N-1 plot -- %s",Xlabel[i].c_str()), "data/MC",  Xlabel[i], htemp->GetBinLowEdge(1), htemp->GetBinLowEdge(htemp->GetNbinsX()+1));

        canvases.push_back(cRatio);
        delete htemp;
    }

    // Step 4: compute the efficiency for each cut
    // For each cut: efficiency = integral on the signal side / total integral
    // "right" = cut is var > threshold (keep high values)
    // "left"  = cut is var < threshold (keep low values)

    struct CutInfo {
        double threshold;
        bool keepRight;
        bool isSymmetric; // pour les coupures sur |var|
    };

    std::vector<CutInfo> cutInfos = {
        {0,      true,  false},  // trigger
        {0,      true,  false},  // METfilters
        {170,    true,  false},  // CaloMET       > 170
        {170,    true,  false},  // CaloMET rescaled       > 170
        {50,     true,  false},  // Pt_pseudo     > 50
        {2.4,    false, true },  // |eta|         < 2.4  ← symétrique
        {2,      true,  false},  // NOPH          >= 2
        {0.8,    true,  false},  // FOVH          > 0.8
        {10,     true,  false},  // NOM           >= 10
        {0,      true,  false},  // HighPurity
        {5.0,    false, false},  // Chi2          < 5
        {0.1,    false, true },  // |dZ|          < 0.1  ← symétrique
        {0.02,   false, true },  // |dXY|         < 0.02 ← symétrique
        {0.02,   false, false},  // PFMiniIso     < 0.02
        {15,     false, false},  // TrkIso        < 15
        {0.3,    false, false},  // EoverP        < 0.3
        {0.0008, false, false},  // PtErr/PtPt    < 0.0008
        {0.3,    true,  false},  // Fpix          > 0.3
        {1,      false, false},  // PtErr/Pt      < 1
        {3.14,   true,  false},  // Ih_StripOnly  > 3.14
        {3.14,   true,  false},  // Ih_StripOnly rescaled > 3.14
    };

    // Helper lambda étendu: avec option symétrique pour |var| < threshold
    auto computeEff = [](TH1F* h, double threshold, bool keepRight, bool isSymmetric = false) -> double {
        if (!h) return -1.0;
        int totalBins = h->GetNbinsX();
        double total  = h->Integral(1, totalBins);
        if (total == 0) return 0.0;

        if (isSymmetric) {
            // |var| < threshold  =>  intégrer entre -threshold et +threshold
            int binLow  = h->FindBin(-threshold);
            int binHigh = h->FindBin(threshold);
            return h->Integral(binLow, binHigh) / total;
        }

        int cutBin = h->FindBin(threshold);
        double signal = keepRight ? h->Integral(cutBin, totalBins)
                                : h->Integral(1, cutBin - 1);
        return signal / total;
    };

    // Print efficiencies
    std::cout << std::left
            << std::setw(25) << "Cut"
            << std::setw(12) << "QCD"
            << std::setw(12) << "TTbar"
            << std::setw(12) << "W+jets"
            << std::setw(12) << "ALL MC"
            << std::setw(12) << "Data"
            << std::endl;
    std::cout << std::string(70, '-') << std::endl;

    for (size_t i = 0; i < cutNames.size(); i++) {
        double eff_QCD   = computeEff(hNM1_QCD[i],        cutInfos[i].threshold, cutInfos[i].keepRight);
        double eff_TTbar = computeEff(hNM1_TTbar[i],      cutInfos[i].threshold, cutInfos[i].keepRight);
        double eff_Wjets = computeEff(hNM1_Wjets[i],      cutInfos[i].threshold, cutInfos[i].keepRight);
        double eff_MC    = computeEff(hNM1_MC[i],         cutInfos[i].threshold, cutInfos[i].keepRight);

        double eff_Data  = computeEff(hNM1_JetMETdata[i], cutInfos[i].threshold, cutInfos[i].keepRight);

        std::cout << std::left  << std::setw(25) << cutNames[i]
                << std::fixed << std::setprecision(4)
                << std::setw(12) << eff_QCD
                << std::setw(12) << eff_TTbar
                << std::setw(12) << eff_Wjets
                << std::setw(12) << eff_MC
                << std::setw(12) << eff_Data
                << std::endl;
    }

    // Step 5: save
    TString pdfName = Form("PlayWithHistos/Nm1plots/Nm1Eff%s%s_ALL.pdf", isRescaled ? "_rescaled" : "", isOnlyWjets ? "_onlyWjets" : "");
    for (size_t i = 0; i < canvases.size(); i++) {
        if      (i == 0)                    canvases[i]->Print(pdfName + "("); // ouverture
        else if (i == canvases.size() - 1)  canvases[i]->Print(pdfName + ")"); // fermeture
        else                                canvases[i]->Print(pdfName);       // page normale
    }
    

    return;
}

void PseudoMET_vs_PFMET () {
    TFile *ifileData = new TFile("TestMET2024_V12p24.root", "READ");
    TFile *ifileGluino = new TFile("../output/Gluino_V19/Gluino_Run3_MET_madgraph_2000_V19p1.root", "READ");

    TH2F *CaloMET_vs_PFMET_data = (TH2F*)ifileData->Get("Nosel_PseudoMET_vs_PFMET");
    TH2F *CaloMET_vs_PFMET_gluino = (TH2F*)ifileGluino->Get("Nosel_PseudoMET_vs_PFMET");

    // draw two different TCanvas with the same range, one for data and one for gluino, with the same color scale
    TCanvas *c_data = new TCanvas("c_data", "c_data", 1200, 900);
    CaloMET_vs_PFMET_data->GetXaxis()->SetTitle("PFMET [GeV]");
    CaloMET_vs_PFMET_data->GetXaxis()->SetLabelSize(0.03);
    CaloMET_vs_PFMET_data->GetYaxis()->SetTitle("PseudoMET [GeV]");
    CaloMET_vs_PFMET_data->GetYaxis()->SetLabelSize(0.03);
    CaloMET_vs_PFMET_data->Draw("COLZ");
    c_data->SetLogz();
    gStyle->SetOptStat(0);
    TCanvas *c_gluino = new TCanvas("c_gluino", "c_gluino", 1200, 900);
    CaloMET_vs_PFMET_gluino->GetXaxis()->SetTitle("PFMET [GeV]");
    CaloMET_vs_PFMET_gluino->GetXaxis()->SetLabelSize(0.03);
    CaloMET_vs_PFMET_gluino->GetYaxis()->SetTitle("PseudoMET [GeV]");
    CaloMET_vs_PFMET_gluino->GetYaxis()->SetLabelSize(0.03);
    CaloMET_vs_PFMET_gluino->Draw("COLZ");
    c_gluino->SetLogz();
    gStyle->SetOptStat(0);

    c_data->SaveAs("PlayWithHistos/PseudoMET_vs_PFMET_data.pdf");
    c_gluino->SaveAs("PlayWithHistos/PseudoMET_vs_PFMET_gluino.pdf");

    return;
}

void DrawPseudoMET(bool OTHERrescale = false) {

    gErrorIgnoreLevel = kError;

    TFile *ifileWjetMuNu;
    if (OTHERrescale) ifileWjetMuNu = new TFile("../output/Wjets2024_V14/WjetMuNu2024_V14p10_weighted.root", "READ");
    else ifileWjetMuNu = new TFile("../output/Wjets2024_V14/WjetMuNu2024_V14p8_weighted.root", "READ");
    TFile *ifileMET = new TFile("../output/JetMET2024_V12/JetMET2024_V12p24.root", "READ");

    TH1F *Nosel_PseudoCaloMET_WjetMuNu = (TH1F*)ifileWjetMuNu->Get("Nosel_PseudoCaloMET");
    TH1F *Nosel_PseudoCaloMET_MET2024 = (TH1F*)ifileMET->Get("Nosel_PseudoCaloMET");

    TH1F *Nm1_event_PseudoMET_WjetMuNu = (TH1F*)ifileWjetMuNu->Get("Nm1_event_CaloMET");
    TH1F *Nm1_event_PseudoMET_MET2024 = (TH1F*)ifileMET->Get("Nm1_event_CaloMET");

    TH1F *Nm1Rescaled_event_PseudoMET_WjetMuNu = (TH1F*)ifileWjetMuNu->Get(Form("Nm1_event_CaloMET_%s", OTHERrescale ? "rescaled" : "weighted"));
    TH1F *Nm1Rescaled_event_PseudoMET_MET2024 = (TH1F*)ifileMET->Get("Nm1_event_CaloMET_weighted");


    Nm1_event_PseudoMET_WjetMuNu->Scale(1./Nm1_event_PseudoMET_WjetMuNu->Integral());
    Nm1_event_PseudoMET_MET2024->Scale(1./Nm1_event_PseudoMET_MET2024->Integral());
    Nosel_PseudoCaloMET_WjetMuNu->Scale(1./Nosel_PseudoCaloMET_WjetMuNu->Integral());
    Nosel_PseudoCaloMET_MET2024->Scale(1./Nosel_PseudoCaloMET_MET2024->Integral());
    Nm1Rescaled_event_PseudoMET_WjetMuNu->Scale(1./Nm1Rescaled_event_PseudoMET_WjetMuNu->Integral());
    Nm1Rescaled_event_PseudoMET_MET2024->Scale(1./Nm1Rescaled_event_PseudoMET_MET2024->Integral());

    Nosel_PseudoCaloMET_WjetMuNu->GetXaxis()->SetTitle("Pseudo MET [GeV]");
    Nosel_PseudoCaloMET_WjetMuNu->GetYaxis()->SetTitle("Number of events");
    Nosel_PseudoCaloMET_WjetMuNu->GetYaxis()->SetTitleOffset(1.2);
    Nosel_PseudoCaloMET_WjetMuNu->SetTitle("");
    Nosel_PseudoCaloMET_WjetMuNu->GetYaxis()->SetTitleSize(0.06);
    Nosel_PseudoCaloMET_WjetMuNu->GetXaxis()->SetTitleSize(0.06);
    Nosel_PseudoCaloMET_WjetMuNu->GetXaxis()->SetTitleOffset(0.9);
    Nosel_PseudoCaloMET_WjetMuNu->GetYaxis()->SetTitleOffset(1);
    Nosel_PseudoCaloMET_WjetMuNu->GetXaxis()->SetLabelSize(0.05);
    Nosel_PseudoCaloMET_WjetMuNu->GetYaxis()->SetLabelSize(0.05);

    Nm1_event_PseudoMET_WjetMuNu->GetXaxis()->SetTitle("Pseudo MET [GeV]");
    Nm1_event_PseudoMET_WjetMuNu->GetYaxis()->SetTitle("Number of events");
    Nm1_event_PseudoMET_WjetMuNu->GetYaxis()->SetTitleOffset(1.2);
    Nm1_event_PseudoMET_WjetMuNu->SetTitle("");
    Nm1_event_PseudoMET_WjetMuNu->GetYaxis()->SetTitleSize(0.06);
    Nm1_event_PseudoMET_WjetMuNu->GetXaxis()->SetTitleSize(0.06);
    Nm1_event_PseudoMET_WjetMuNu->GetXaxis()->SetTitleOffset(0.9);
    Nm1_event_PseudoMET_WjetMuNu->GetYaxis()->SetTitleOffset(1);
    Nm1_event_PseudoMET_WjetMuNu->GetXaxis()->SetLabelSize(0.05);
    Nm1_event_PseudoMET_WjetMuNu->GetYaxis()->SetLabelSize(0.05);

    Nm1Rescaled_event_PseudoMET_WjetMuNu->GetXaxis()->SetTitle("Pseudo MET [GeV]");
    Nm1Rescaled_event_PseudoMET_WjetMuNu->GetYaxis()->SetTitle("Number of events");
    Nm1Rescaled_event_PseudoMET_WjetMuNu->GetYaxis()->SetTitleOffset(1.2);
    Nm1Rescaled_event_PseudoMET_WjetMuNu->SetTitle("");
    Nm1Rescaled_event_PseudoMET_WjetMuNu->GetYaxis()->SetTitleSize(0.06);
    Nm1Rescaled_event_PseudoMET_WjetMuNu->GetXaxis()->SetTitleSize(0.06);
    Nm1Rescaled_event_PseudoMET_WjetMuNu->GetXaxis()->SetTitleOffset(0.9);
    Nm1Rescaled_event_PseudoMET_WjetMuNu->GetYaxis()->SetTitleOffset(1);
    Nm1Rescaled_event_PseudoMET_WjetMuNu->GetXaxis()->SetLabelSize(0.05);
    Nm1Rescaled_event_PseudoMET_WjetMuNu->GetYaxis()->SetLabelSize(0.05);

    TLatex *latex1 = new TLatex(0.16, 0.91, "#scale[1.3]{#bf{CMS}}#it{Work in progress}");
    latex1->SetNDC();
    latex1->SetTextFont(42);
    latex1->SetTextSize(0.04);

    // fit both hist with a gaussian at the peak
    TF1 *gaus_WjetMuNu = new TF1("gaus_WjetMuNu", "gaus", 20, 200);
    TF1 *gaus_MET2024 = new TF1("gaus_MET2024", "gaus", 20, 200);
    gaus_WjetMuNu->SetParameters(Nosel_PseudoCaloMET_WjetMuNu->GetMaximum(), Nosel_PseudoCaloMET_WjetMuNu->GetMean(), Nosel_PseudoCaloMET_WjetMuNu->GetRMS());
    gaus_MET2024->SetParameters(Nosel_PseudoCaloMET_MET2024->GetMaximum(), Nosel_PseudoCaloMET_MET2024->GetMean(), Nosel_PseudoCaloMET_MET2024->GetRMS());
    cout << "No sel" << endl;
    Nosel_PseudoCaloMET_WjetMuNu->Fit(gaus_WjetMuNu, "RQ");
    Nosel_PseudoCaloMET_MET2024->Fit(gaus_MET2024, "RQ");
    gaus_WjetMuNu->SetLineColor(kRed);
    gaus_MET2024->SetLineColor(kGreen);

    TF1 *gaus_Nm1_WjetMuNu = new TF1("gaus_Nm1_WjetMuNu", "gaus", 80, 220);
    TF1 *gaus_Nm1_MET2024 = new TF1("gaus_Nm1_MET2024", "gaus", 50, 230);
    gaus_Nm1_WjetMuNu->SetParameters(Nm1_event_PseudoMET_WjetMuNu->GetMaximum(), Nm1_event_PseudoMET_WjetMuNu->GetMean(), Nm1_event_PseudoMET_WjetMuNu->GetRMS());
    gaus_Nm1_MET2024->SetParameters(Nm1_event_PseudoMET_MET2024->GetMaximum(), Nm1_event_PseudoMET_MET2024->GetMean(), Nm1_event_PseudoMET_MET2024->GetRMS());
    cout << "N-1 sel" << endl;
    Nm1_event_PseudoMET_WjetMuNu->Fit(gaus_Nm1_WjetMuNu, "R");
    Nm1_event_PseudoMET_MET2024->Fit(gaus_Nm1_MET2024, "R");
    gaus_Nm1_WjetMuNu->SetLineColor(kRed);
    gaus_Nm1_MET2024->SetLineColor(kGreen);
    cout << "Mean data: " << gaus_Nm1_MET2024->GetParameter(1) << "   Mean WjetMuNu: " << gaus_Nm1_WjetMuNu->GetParameter(1) << endl;
    cout << "weight = " << gaus_Nm1_MET2024->GetParameter(1)/gaus_Nm1_WjetMuNu->GetParameter(1) << endl;

    TLegend *legend = new TLegend(0.7, 0.5, 0.85, 0.9);
    legend->AddEntry(Nosel_PseudoCaloMET_WjetMuNu, "WjetMuNu", "f");
    legend->AddEntry(Nosel_PseudoCaloMET_MET2024, "MET2024", "lep");
    legend->SetBorderSize(0);
    legend->SetFillStyle(0);


    TCanvas *c_PseudoCaloMET_nosel = new TCanvas("c_PseudoCaloMET_nosel", "c_PseudoCaloMET_nosel", 800, 600);
    c_PseudoCaloMET_nosel->cd();
    c_PseudoCaloMET_nosel->SetLeftMargin(0.16);
    c_PseudoCaloMET_nosel->SetBottomMargin(0.16);
    Nosel_PseudoCaloMET_WjetMuNu->SetLineColor(kBlue-7);
    Nosel_PseudoCaloMET_WjetMuNu->SetFillColorAlpha(kBlue-7, 0.5);
    Nosel_PseudoCaloMET_WjetMuNu->Draw("HIST");
    Nosel_PseudoCaloMET_WjetMuNu->GetXaxis()->SetRangeUser(10, 1000);
    Nosel_PseudoCaloMET_MET2024->SetLineColor(kBlack);
    Nosel_PseudoCaloMET_MET2024->SetMarkerColor(kBlack);
    Nosel_PseudoCaloMET_MET2024->SetMarkerStyle(20);
    Nosel_PseudoCaloMET_MET2024->Draw("E1 same");
    gaus_WjetMuNu->Draw("same");
    gaus_MET2024->Draw("same");
    latex1->Draw();
    legend->Draw();
    gPad->SetLogy();
    gStyle->SetOptStat(0);

    TCanvas *c_PseudoCaloMET = new TCanvas("c_PseudoCaloMET", "c_PseudoCaloMET", 800, 600);
    c_PseudoCaloMET->cd();
    c_PseudoCaloMET->SetLeftMargin(0.16);
    c_PseudoCaloMET->SetBottomMargin(0.16);
    Nm1_event_PseudoMET_WjetMuNu->SetLineColor(kBlue-7);
    Nm1_event_PseudoMET_WjetMuNu->SetFillColorAlpha(kBlue-7, 0.5);
    Nm1_event_PseudoMET_WjetMuNu->Draw("HIST");
    Nm1_event_PseudoMET_WjetMuNu->GetXaxis()->SetRangeUser(10, 1000);
    Nm1_event_PseudoMET_MET2024->SetLineColor(kBlack);
    Nm1_event_PseudoMET_MET2024->SetMarkerColor(kBlack);
    Nm1_event_PseudoMET_MET2024->SetMarkerStyle(20);
    Nm1_event_PseudoMET_MET2024->Draw("E1 same");
    gaus_Nm1_WjetMuNu->Draw("same");
    gaus_Nm1_MET2024->Draw("same");
    legend->Draw();
    latex1->Draw();
    gPad->SetLogy();
    gStyle->SetOptStat(0);

    TCanvas *cRescaled_PseudoCaloMET = new TCanvas("cRescaled_PseudoCaloMET", "cRescaled_PseudoCaloMET", 800, 600);
    cRescaled_PseudoCaloMET->cd();
    cRescaled_PseudoCaloMET->SetLeftMargin(0.16);
    cRescaled_PseudoCaloMET->SetBottomMargin(0.16);
    Nm1Rescaled_event_PseudoMET_WjetMuNu->SetLineColor(kBlue-7);
    Nm1Rescaled_event_PseudoMET_WjetMuNu->SetFillColorAlpha(kBlue-7, 0.5);
    Nm1Rescaled_event_PseudoMET_WjetMuNu->Draw("HIST");
    Nm1Rescaled_event_PseudoMET_WjetMuNu->GetXaxis()->SetRangeUser(10, 1000);
    Nm1Rescaled_event_PseudoMET_MET2024->SetLineColor(kBlack);
    Nm1Rescaled_event_PseudoMET_MET2024->SetMarkerColor(kBlack);
    Nm1Rescaled_event_PseudoMET_MET2024->SetMarkerStyle(20);
    Nm1Rescaled_event_PseudoMET_MET2024->Draw("E1 same");
    legend->Draw();
    latex1->Draw();
    gPad->SetLogy();
    gStyle->SetOptStat(0);

    TCanvas *cRatio_nosel = DrawWithRatio(Nosel_PseudoCaloMET_MET2024, Nosel_PseudoCaloMET_WjetMuNu,
                       c_PseudoCaloMET_nosel, "PseudoMET wo selections", "data/MC",  "Pseudo MET [GeV]", 10, 1000);

    TCanvas *cRatio_Nm1 = DrawWithRatio(Nm1_event_PseudoMET_MET2024, Nm1_event_PseudoMET_WjetMuNu,
                       c_PseudoCaloMET, "PseudoMET N-1 selections", "data/MC",  "Pseudo MET [GeV]", 10, 1000);

    TCanvas *cRatio_Rescaled = DrawWithRatio(Nm1Rescaled_event_PseudoMET_MET2024, Nm1Rescaled_event_PseudoMET_WjetMuNu,
                       cRescaled_PseudoCaloMET, "PseudoMET N-1 selections rescaled", "data/MC",  "Pseudo MET [GeV]", 10, 1000);

    cRatio_nosel->SaveAs("PlayWithHistos/PseudoCaloMET_nosel_FIT.pdf");
    cRatio_Nm1->SaveAs("PlayWithHistos/PseudoCaloMET_Nm1_FIT.pdf");
    cRatio_Rescaled->SaveAs(Form("PlayWithHistos/PseudoCaloMET_Nm1_%srescaled.pdf", OTHERrescale ? "OTHER" : ""));


    latex1->SetTitle("#it{Private work (CMS simulation/data)}");
    
    c_PseudoCaloMET_nosel->Modified();
    c_PseudoCaloMET_nosel->Update();
    TCanvas *cRatio_nosel_bis = DrawWithRatio(Nosel_PseudoCaloMET_MET2024, Nosel_PseudoCaloMET_WjetMuNu,
                       c_PseudoCaloMET_nosel, "PseudoMET wo selections", "data/MC",  "Pseudo MET [GeV]", 10, 1000);
    cRatio_nosel_bis->SaveAs("PlayWithHistos/IhRatio_bis.pdf");

    c_PseudoCaloMET->Modified();
    c_PseudoCaloMET->Update();
    TCanvas *cRatio_Nm1_bis = DrawWithRatio(Nm1_event_PseudoMET_MET2024, Nm1_event_PseudoMET_WjetMuNu,
                       c_PseudoCaloMET, "PseudoMET N-1 selections", "data/MC",  "Pseudo MET [GeV]", 10, 1000);
    cRatio_Nm1_bis->SaveAs("PlayWithHistos/PseudoCaloMET_Nm1_FIT_bis.pdf");

    cRescaled_PseudoCaloMET->Modified();
    cRescaled_PseudoCaloMET->Update();
    TCanvas *cRatio_Rescaled_bis = DrawWithRatio(Nm1Rescaled_event_PseudoMET_MET2024, Nm1Rescaled_event_PseudoMET_WjetMuNu,
                       cRescaled_PseudoCaloMET, "PseudoMET N-1 selections rescaled", "data/MC",  "Pseudo MET [GeV]", 10, 1000);
    cRatio_Rescaled_bis->SaveAs(Form("PlayWithHistos/PseudoCaloMET_Nm1_%srescaled_bis.pdf", OTHERrescale ? "OTHER" : ""));

    return;
}

void nHSCP() {

    gErrorIgnoreLevel = kError;

    TFile *ifileQCD = new TFile("../output/QCD2024_V16/QCD2024_mu_V16p1_weighted.root", "READ");
    TFile *ifileTTbar = new TFile("../output/TTbar2024_V15/TTbar2024_V15p6_weighted.root", "READ");
    TFile *ifileWjetMuNu = new TFile("../output/Wjets2024_V14/WjetMuNu2024_V14p8_weighted.root", "READ");
    TFile *ifileMET = new TFile("../output/JetMET2024_V12/JetMET2024_V12p24.root", "READ");

    TH1F *nHSCP_QCD = (TH1F*)ifileQCD->Get("nHSCP");
    TH1F *nHSCP_TTbar = (TH1F*)ifileTTbar->Get("nHSCP");
    TH1F *nHSCP_WjetMuNu = (TH1F*)ifileWjetMuNu->Get("nHSCP");
    TH1F *nHSCP_MET = (TH1F*)ifileMET->Get("nHSCP");

    TH1F *Sel_nHSCP_QCD = (TH1F*)ifileQCD->Get("METanalysis_Eta2p4_nHSCP");
    TH1F *Sel_nHSCP_TTbar = (TH1F*)ifileTTbar->Get("METanalysis_Eta2p4_nHSCP");
    TH1F *Sel_nHSCP_WjetMuNu = (TH1F*)ifileWjetMuNu->Get("METanalysis_Eta2p4_nHSCP");
    TH1F *Sel_nHSCP_MET = (TH1F*)ifileMET->Get("METanalysis_Eta2p4_nHSCP");

    // draw on the same canvas with a tstack for bkg
    TCanvas *c_nHSCP = new TCanvas("c_nHSCP", "c_nHSCP", 800, 600);
    THStack *hs_nHSCP = new THStack("hs_nHSCP", "");
    nHSCP_QCD->SetLineColor(kGreen-4);
    nHSCP_QCD->SetFillColorAlpha(kGreen-4, 0.5);
    nHSCP_TTbar->SetLineColor(kRed);
    nHSCP_TTbar->SetFillColorAlpha(kRed, 0.5);
    nHSCP_WjetMuNu->SetLineColor(kBlue-7);
    nHSCP_WjetMuNu->SetFillColorAlpha(kBlue-7, 0.5);
    nHSCP_MET->SetLineColor(kBlack);
    nHSCP_MET->SetMarkerColor(kBlack);
    nHSCP_MET->SetMarkerStyle(20);

    hs_nHSCP->Add(nHSCP_QCD);
    hs_nHSCP->Add(nHSCP_TTbar);
    hs_nHSCP->Add(nHSCP_WjetMuNu);
    hs_nHSCP->Draw("HIST");
    hs_nHSCP->SetMinimum(0.8);
    hs_nHSCP->GetXaxis()->SetTitle("N_{HSCP}");
    hs_nHSCP->GetYaxis()->SetTitle("Number of events");
    nHSCP_MET->Draw("E1 same");

    TLegend *legend = new TLegend(0.7, 0.5, 0.85, 0.9);
    legend->AddEntry(nHSCP_QCD, "QCD muEnriched", "f");
    legend->AddEntry(nHSCP_TTbar, "TTbar", "f");
    legend->AddEntry(nHSCP_WjetMuNu, "W+jets", "f");
    legend->AddEntry(nHSCP_MET, "JetMET data", "lep");
    legend->SetBorderSize(0);
    legend->SetFillStyle(0);
    legend->Draw();

    c_nHSCP->SetLogy();

    c_nHSCP->SaveAs("PlayWithHistos/nHSCP_nosel.pdf");

    // same for the selected events
    TCanvas *c_Sel_nHSCP = new TCanvas("c_Sel_nHSCP", "c_Sel_nHSCP", 800, 600);
    THStack *hs_Sel_nHSCP = new THStack("hs_Sel_nHSCP", "");
    Sel_nHSCP_QCD->SetLineColor(kGreen-4);
    Sel_nHSCP_QCD->SetFillColorAlpha(kGreen-4, 0.5);
    Sel_nHSCP_TTbar->SetLineColor(kRed);
    Sel_nHSCP_TTbar->SetFillColorAlpha(kRed, 0.5);
    Sel_nHSCP_WjetMuNu->SetLineColor(kBlue-7);
    Sel_nHSCP_WjetMuNu->SetFillColorAlpha(kBlue-7, 0.5);
    Sel_nHSCP_MET->SetLineColor(kBlack);
    Sel_nHSCP_MET->SetMarkerColor(kBlack);
    Sel_nHSCP_MET->SetMarkerStyle(20);

    hs_Sel_nHSCP->Add(Sel_nHSCP_QCD);
    hs_Sel_nHSCP->Add(Sel_nHSCP_TTbar);
    hs_Sel_nHSCP->Add(Sel_nHSCP_WjetMuNu);
    hs_Sel_nHSCP->Draw("HIST");
    hs_Sel_nHSCP->SetMinimum(0.8);
    hs_Sel_nHSCP->GetXaxis()->SetTitle("N_{HSCP}");
    hs_Sel_nHSCP->GetYaxis()->SetTitle("Number of events");
    Sel_nHSCP_MET->Draw("E1 same");

    legend->Draw();
    c_Sel_nHSCP->SetLogy();
    c_Sel_nHSCP->SaveAs("PlayWithHistos/nHSCP_sel.pdf");


    return;
}

void nPV() {

    gErrorIgnoreLevel = kError;

    TFile *ifileQCD = new TFile("../output/QCD2024_V16/QCD2024_mu_V16p1_weighted.root", "READ");
    TFile *ifileTTbar = new TFile("../output/TTbar2024_V15/TTbar2024_V15p6_weighted.root", "READ");
    TFile *ifileWjetMuNu = new TFile("../output/Wjets2024_V14/WjetMuNu2024_V14p8_weighted.root", "READ");
    TFile *ifileMET = new TFile("../output/JetMET2024_V12/JetMET2024_V12p24.root", "READ");

    TH1F *nPV_QCD = (TH1F*)ifileQCD->Get("nPVgood");
    TH1F *nPV_TTbar = (TH1F*)ifileTTbar->Get("nPVgood");
    TH1F *nPV_WjetMuNu = (TH1F*)ifileWjetMuNu->Get("nPVgood");
    TH1F *nPV_MET = (TH1F*)ifileMET->Get("nPVgood");

    TH1F *Sel_nPV_QCD = (TH1F*)ifileQCD->Get("METanalysis_Eta2p4_nPVgood");
    TH1F *Sel_nPV_TTbar = (TH1F*)ifileTTbar->Get("METanalysis_Eta2p4_nPVgood");
    TH1F *Sel_nPV_WjetMuNu = (TH1F*)ifileWjetMuNu->Get("METanalysis_Eta2p4_nPVgood");
    TH1F *Sel_nPV_MET = (TH1F*)ifileMET->Get("METanalysis_Eta2p4_nPVgood");

    // draw on the same canvas with a tstack for bkg
    TCanvas *c_nPV = new TCanvas("c_nPV", "c_nPV", 800, 600);
    THStack *hs_nPV = new THStack("hs_nPV", "");
    nPV_QCD->SetLineColor(kGreen-4);
    nPV_QCD->SetFillColorAlpha(kGreen-4, 0.5);
    nPV_TTbar->SetLineColor(kRed);
    nPV_TTbar->SetFillColorAlpha(kRed, 0.5);
    nPV_WjetMuNu->SetLineColor(kBlue-7);
    nPV_WjetMuNu->SetFillColorAlpha(kBlue-7, 0.5);
    nPV_MET->SetLineColor(kBlack);
    nPV_MET->SetMarkerColor(kBlack);
    nPV_MET->SetMarkerStyle(20);

    hs_nPV->Add(nPV_QCD);
    hs_nPV->Add(nPV_TTbar);
    hs_nPV->Add(nPV_WjetMuNu);
    hs_nPV->Draw("HIST");
    hs_nPV->SetMinimum(0.8);
    hs_nPV->GetXaxis()->SetTitle("N_{PV}");
    hs_nPV->GetYaxis()->SetTitle("Number of events");
    nPV_MET->Draw("E1 same");

    TLegend *legend = new TLegend(0.7, 0.5, 0.85, 0.9);
    legend->AddEntry(nPV_QCD, "QCD muEnriched", "f");
    legend->AddEntry(nPV_TTbar, "TTbar", "f");
    legend->AddEntry(nPV_WjetMuNu, "W+jets", "f");
    legend->AddEntry(nPV_MET, "JetMET data", "lep");
    legend->SetBorderSize(0);
    legend->SetFillStyle(0);
    legend->Draw();

    c_nPV->SetLogy();

    c_nPV->SaveAs("PlayWithHistos/nPV_nosel.pdf");

    // same for the selected events
    TCanvas *c_Sel_nPV = new TCanvas("c_Sel_nPV", "c_Sel_nPV", 800, 600);
    THStack *hs_Sel_nPV = new THStack("hs_Sel_nPV", "");
    Sel_nPV_QCD->SetLineColor(kGreen-4);
    Sel_nPV_QCD->SetFillColorAlpha(kGreen-4, 0.5);
    Sel_nPV_TTbar->SetLineColor(kRed);
    Sel_nPV_TTbar->SetFillColorAlpha(kRed, 0.5);
    Sel_nPV_WjetMuNu->SetLineColor(kBlue-7);
    Sel_nPV_WjetMuNu->SetFillColorAlpha(kBlue-7, 0.5);
    Sel_nPV_MET->SetLineColor(kBlack);
    Sel_nPV_MET->SetMarkerColor(kBlack);
    Sel_nPV_MET->SetMarkerStyle(20);

    hs_Sel_nPV->Add(Sel_nPV_QCD);
    hs_Sel_nPV->Add(Sel_nPV_TTbar);
    hs_Sel_nPV->Add(Sel_nPV_WjetMuNu);
    hs_Sel_nPV->Draw("HIST");
    hs_Sel_nPV->SetMinimum(0.8);
    hs_Sel_nPV->GetXaxis()->SetTitle("N_{PV}");
    hs_Sel_nPV->GetYaxis()->SetTitle("Number of events");
    Sel_nPV_MET->Draw("E1 same");

    legend->Draw();
    c_Sel_nPV->SetLogy();
    c_Sel_nPV->SaveAs("PlayWithHistos/nPV_sel.pdf");


    return;
}

void PostTriggerPseudoMET() {

    gErrorIgnoreLevel = kError;

    TFile *ifileWjetMuNu = new TFile("../output/Wjets2024_V14/WjetMuNu2024_V14p9_weighted.root", "READ");
    TFile *ifileMET = new TFile("../output/JetMET2024_V12/JetMET2024_V12p25.root", "READ");

    TH1F *PostTrigger_PseudoCaloMET_SF_rescaled_Wmunu = (TH1F*)ifileWjetMuNu->Get("PostTrigger_PseudoCaloMET_SF_rescaled");
    TH1F *PostTrigger_PseudoCaloMET_SF_NOTrescaled_Wmunu = (TH1F*)ifileWjetMuNu->Get("PostTrigger_PseudoCaloMET_SF_NOTrescaled");
    TH1F *PostTrigger_PseudoCaloMET_MET = (TH1F*)ifileMET->Get("PostTrigger_PseudoCaloMET_SF_NOTrescaled");

    PostTrigger_PseudoCaloMET_SF_rescaled_Wmunu->Scale(1./PostTrigger_PseudoCaloMET_SF_rescaled_Wmunu->Integral());
    PostTrigger_PseudoCaloMET_SF_NOTrescaled_Wmunu->Scale(1./PostTrigger_PseudoCaloMET_SF_NOTrescaled_Wmunu->Integral());
    PostTrigger_PseudoCaloMET_MET->Scale(1./PostTrigger_PseudoCaloMET_MET->Integral());

    PostTrigger_PseudoCaloMET_SF_rescaled_Wmunu->SetLineColor(kBlue-7);
    PostTrigger_PseudoCaloMET_SF_rescaled_Wmunu->SetFillColorAlpha(kBlue-7, 0.5);
    PostTrigger_PseudoCaloMET_SF_NOTrescaled_Wmunu->SetLineColor(kCyan);
    PostTrigger_PseudoCaloMET_SF_NOTrescaled_Wmunu->SetFillColorAlpha(kCyan, 0.5);
    PostTrigger_PseudoCaloMET_MET->SetLineColor(kBlack);
    PostTrigger_PseudoCaloMET_MET->SetMarkerColor(kBlack);
    PostTrigger_PseudoCaloMET_MET->SetMarkerStyle(20);

    TLegend *legend = new TLegend(0.7, 0.5, 0.85, 0.9);
    legend->AddEntry(PostTrigger_PseudoCaloMET_SF_rescaled_Wmunu, "WjetMuNu SFwRescaling", "f");
    legend->AddEntry(PostTrigger_PseudoCaloMET_SF_NOTrescaled_Wmunu, "WjetMuNu SFwo/Rescaling", "f");
    legend->AddEntry(PostTrigger_PseudoCaloMET_MET, "MET2024", "lep");
    legend->SetBorderSize(0);
    legend->SetFillStyle(0);

    TCanvas *c_PseudoCaloMET = new TCanvas("c_PseudoCaloMET", "c_PseudoCaloMET", 800, 600);
    c_PseudoCaloMET->cd();
    PostTrigger_PseudoCaloMET_SF_rescaled_Wmunu->GetXaxis()->SetTitle("PseudoMET (~ CaloMET) [GeV]");
    PostTrigger_PseudoCaloMET_SF_rescaled_Wmunu->GetYaxis()->SetTitle("Number of events");
    PostTrigger_PseudoCaloMET_SF_rescaled_Wmunu->GetXaxis()->SetRangeUser(20, 1000);
    PostTrigger_PseudoCaloMET_SF_rescaled_Wmunu->Draw("HIST");
    PostTrigger_PseudoCaloMET_SF_NOTrescaled_Wmunu->Draw("HIST same");
    PostTrigger_PseudoCaloMET_MET->Draw("E1 same");
    legend->Draw();
    gPad->SetLogy();
    gStyle->SetOptStat(0);


    TCanvas *cRatio_Nm1 = DrawWithRatio(PostTrigger_PseudoCaloMET_MET, 
                                        PostTrigger_PseudoCaloMET_SF_rescaled_Wmunu,
                                        PostTrigger_PseudoCaloMET_SF_NOTrescaled_Wmunu,
                                        c_PseudoCaloMET,
                                        "PseudoMET w and wo rescaling (SF applied)",
                                        "data/MC",
                                        "PseudoMET (~ CaloMET) [GeV]",
                                        20,
                                        1000);

    cRatio_Nm1->SaveAs("PlayWithHistos/PostTriggerLOG_PseudoCaloMET_SF_rescaled_vs_NOTrescaled.pdf");

    TCanvas *c_PseudoCaloMET_b = new TCanvas("c_PseudoCaloMET_b", "c_PseudoCaloMET_b", 800, 600);
    c_PseudoCaloMET_b->cd();
    PostTrigger_PseudoCaloMET_SF_rescaled_Wmunu->GetXaxis()->SetTitle("PseudoMET (~ CaloMET) [GeV]");
    PostTrigger_PseudoCaloMET_SF_rescaled_Wmunu->GetYaxis()->SetTitle("Number of events");
    PostTrigger_PseudoCaloMET_SF_rescaled_Wmunu->GetXaxis()->SetRangeUser(20, 1000);
    PostTrigger_PseudoCaloMET_SF_rescaled_Wmunu->SetMaximum(0.08);
    PostTrigger_PseudoCaloMET_SF_rescaled_Wmunu->Draw("HIST");
    PostTrigger_PseudoCaloMET_SF_NOTrescaled_Wmunu->Draw("HIST same");
    PostTrigger_PseudoCaloMET_MET->Draw("E1 same");
    legend->Draw();
    gStyle->SetOptStat(0);

    TCanvas *cRatio_Nm1_b = DrawWithRatio(PostTrigger_PseudoCaloMET_MET, 
                                        PostTrigger_PseudoCaloMET_SF_rescaled_Wmunu,
                                        PostTrigger_PseudoCaloMET_SF_NOTrescaled_Wmunu,
                                        c_PseudoCaloMET_b,
                                        "PseudoMET w and wo rescaling (SF applied)",
                                        "data/MC",
                                        "PseudoMET (~ CaloMET) [GeV]",
                                        20,
                                        1000);

    cRatio_Nm1_b->SaveAs("PlayWithHistos/PostTrigger_PseudoCaloMET_SF_rescaled_vs_NOTrescaled.pdf");

    return;
}

void MyClusters() {

    // build a histogram of 512 bins with x axis from 0 to 512, where two strip clusters are artificially built:
    TH1F *h_clusters = new TH1F("", "", 512, -0.5, 511.5);
    h_clusters->SetBinContent(103, 6);
    h_clusters->SetBinContent(104, 18);
    h_clusters->SetBinContent(105, 177);
    h_clusters->SetBinContent(106, 22);
    h_clusters->SetBinContent(107, 7);

    h_clusters->SetBinContent(436, 4);
    h_clusters->SetBinContent(437, 129);
    h_clusters->SetBinContent(438, 83);
    h_clusters->SetBinContent(439, 15);
    h_clusters->SetBinContent(440, 2);

    h_clusters->GetXaxis()->SetTitle("Strip index");
    h_clusters->GetYaxis()->SetTitle("ADC counts");
    h_clusters->GetYaxis()->SetTitleSize(0.06);
    h_clusters->GetXaxis()->SetTitleSize(0.06);
    h_clusters->GetXaxis()->SetTitleOffset(0.9);
    h_clusters->GetYaxis()->SetTitleOffset(1.3);
    h_clusters->GetXaxis()->SetLabelSize(0.05);
    h_clusters->GetYaxis()->SetLabelSize(0.05);
    h_clusters->SetLineColor(kBlue-7);
    h_clusters->SetLineWidth(2);
    h_clusters->SetFillColorAlpha(kBlue-7, 0.5);
    gStyle->SetOptStat(0);

    TLatex *latex1 = new TLatex(0.155, 0.91, "#scale[1.3]{#bf{CMS}}#it{Simulation Work in progress}");
    latex1->SetNDC();
    latex1->SetTextFont(42);
    latex1->SetTextSize(0.04);

    // clone of the histo
    TH1F *h_clusters_clone = (TH1F*)h_clusters->Clone("h_clusters_clone");

    h_clusters_clone->GetYaxis()->SetTitleSize(0.06);
    h_clusters_clone->GetXaxis()->SetTitleSize(0.06);
    h_clusters_clone->GetXaxis()->SetTitleOffset(0.9);
    h_clusters_clone->GetYaxis()->SetTitleOffset(1.3);
    h_clusters_clone->GetXaxis()->SetLabelSize(0.05);
    h_clusters_clone->GetYaxis()->SetLabelSize(0.05);

    TCanvas *c_clusters1 = new TCanvas("c_clusters1", "c_clusters1", 800, 800);
    c_clusters1->cd();
    c_clusters1->SetLeftMargin(0.16); c_clusters1->SetBottomMargin(0.16);
    h_clusters->GetXaxis()->SetRangeUser(101, 107);
    h_clusters->Draw("HIST");
    latex1->Draw("same");
    c_clusters1->SaveAs("PlayWithHistos/Cluster_centered.pdf");
    latex1->SetTitle("#it{Private work (CMS simulation)}");
    c_clusters1->Modified();
    c_clusters1->Update();
    c_clusters1->SaveAs("PlayWithHistos/Cluster_centered_bis.pdf");

    TCanvas *c_clusters2 = new TCanvas("c_clusters2", "c_clusters2", 800, 800);
    c_clusters2->cd();
    c_clusters2->SetLeftMargin(0.16); c_clusters2->SetBottomMargin(0.16);
    h_clusters_clone->GetXaxis()->SetRangeUser(434, 440);
    h_clusters_clone->Draw("HIST");
    latex1->SetTitle("#scale[1.3]{#bf{CMS}}#it{Simulation Work in progress}");
    latex1->Draw("same");
    c_clusters2->SaveAs("PlayWithHistos/Cluster_tilted.pdf");
    latex1->SetTitle("#it{Private work (CMS simulation)}");
    c_clusters2->Modified();
    c_clusters2->Update();
    c_clusters2->SaveAs("PlayWithHistos/Cluster_tilted_bis.pdf");


    TH1F *hsat = new TH1F("", "", 512, -0.5, 511.5);
    hsat->SetBinContent(211, 16);
    hsat->SetBinContent(212, 38);
    hsat->SetBinContent(213, 391);
    hsat->SetBinContent(214, 43);
    hsat->SetBinContent(215, 18);
    hsat->SetBinContent(216, 3);

    hsat->GetYaxis()->SetTitleSize(0.06);
    hsat->GetXaxis()->SetTitleSize(0.06);
    hsat->GetXaxis()->SetTitleOffset(0.9);
    hsat->GetYaxis()->SetTitleOffset(1.3);
    hsat->GetXaxis()->SetLabelSize(0.05);
    hsat->GetYaxis()->SetLabelSize(0.05);


    TH1F *hsatreco = new TH1F("", "", 512, -0.5, 511.5);
    hsatreco->SetBinContent(211, 14);
    hsatreco->SetBinContent(212, 40);
    hsatreco->SetBinContent(213, 254);
    hsatreco->SetBinContent(214, 41);
    hsatreco->SetBinContent(215, 18);

    hsat->GetXaxis()->SetTitle("Strip index");
    hsat->GetYaxis()->SetTitle("ADC counts");
    hsat->SetLineColor(kBlue-7);
    hsat->SetLineWidth(2);
    hsat->SetFillColorAlpha(kBlue-7, 0.5);
    hsatreco->SetLineColor(kGreen-4);
    hsatreco->SetLineWidth(3);
    hsatreco->SetMarkerColor(kGreen-4);
    hsatreco->SetMarkerStyle(22);
    hsatreco->SetMarkerSize(2);
    gStyle->SetOptStat(0);

    TCanvas *c_sat = new TCanvas("c_sat", "c_sat", 800, 800);
    c_sat->cd();
    c_sat->SetLeftMargin(0.16); c_sat->SetBottomMargin(0.16);
    hsat->GetXaxis()->SetRangeUser(209, 216);
    hsat->Draw("HIST");
    hsatreco->Draw("hist same");
    hsatreco->Draw("P same");
    TLegend *legend = new TLegend(0.55, 0.75, 0.95, 0.9);
    legend->AddEntry(hsat, "Simulated", "f");
    legend->AddEntry(hsatreco, "Reconstructed", "lp");
    legend->SetTextSize(0.04);
    legend->SetBorderSize(0);
    legend->SetFillStyle(0);
    legend->Draw();
    latex1->SetTitle("#scale[1.3]{#bf{CMS}}#it{Simulation Work in progress}");
    latex1->Draw("same");
    c_sat->SaveAs("PlayWithHistos/Cluster_saturation.pdf");
    latex1->SetTitle("#it{Private work (CMS simulation)}");
    c_sat->Modified();
    c_sat->Update();
    c_sat->SaveAs("PlayWithHistos/Cluster_saturation_bis.pdf");


    TH1F *h_LR1 = new TH1F("", "", 512, -0.5, 511.5);
    h_LR1->SetBinContent(213, 10);
    h_LR1->SetBinContent(214, 187);
    h_LR1->SetBinContent(215, 351);
    h_LR1->SetBinContent(216, 221);
    h_LR1->SetBinContent(217, 11);
    h_LR1->SetBinContent(218, 2);

    TH1F *h_LR1reco = new TH1F("", "", 512, -0.5, 511.5);
    h_LR1reco->SetBinContent(213, 13);
    h_LR1reco->SetBinContent(214, 160);
    h_LR1reco->SetBinContent(215, 254);
    h_LR1reco->SetBinContent(216, 172);
    h_LR1reco->SetBinContent(217, 12);

    h_LR1->SetLineColor(kBlue-7);
    h_LR1->SetLineWidth(2);
    h_LR1->SetFillColorAlpha(kBlue-7, 0.5);
    h_LR1reco->SetLineColor(kGreen-4);
    h_LR1reco->SetLineWidth(3);
    h_LR1reco->SetMarkerColor(kGreen-4);
    h_LR1reco->SetMarkerStyle(22);
    h_LR1reco->SetMarkerSize(2);

    TH1F *h_LR2 = new TH1F("", "", 512, -0.5, 511.5);
    h_LR2->SetBinContent(85, 2);
    h_LR2->SetBinContent(86, 14);
    h_LR2->SetBinContent(87, 159);
    h_LR2->SetBinContent(88, 271);
    h_LR2->SetBinContent(89, 231);
    h_LR2->SetBinContent(90, 15);
    h_LR2->SetBinContent(91, 4);

    TH1F *h_LR2reco = new TH1F("", "", 512, -0.5, 511.5);
    h_LR2reco->SetBinContent(87, 148);
    h_LR2reco->SetBinContent(88, 254);
    h_LR2reco->SetBinContent(89, 225);
    h_LR2reco->SetBinContent(90, 17);

    h_LR2->SetLineColor(kBlue-7);
    h_LR2->SetLineWidth(2);
    h_LR2->SetFillColorAlpha(kBlue-7, 0.5);
    h_LR2reco->SetLineColor(kGreen-4);
    h_LR2reco->SetLineWidth(3);
    h_LR2reco->SetMarkerColor(kGreen-4);
    h_LR2reco->SetMarkerStyle(22);
    h_LR2reco->SetMarkerSize(2);

    TH1F *h_LR3 = new TH1F("", "", 512, -0.5, 511.5);
    h_LR3->SetBinContent(478, 2);
    h_LR3->SetBinContent(479, 14);
    h_LR3->SetBinContent(480, 174);
    h_LR3->SetBinContent(481, 241);
    h_LR3->SetBinContent(482, 289);
    h_LR3->SetBinContent(483, 222);
    h_LR3->SetBinContent(484, 15);
    h_LR3->SetBinContent(485, 3);

    TH1F *h_LR3reco = new TH1F("", "", 512, -0.5, 511.5);
    h_LR3reco->SetBinContent(480, 168);
    h_LR3reco->SetBinContent(481, 219);
    h_LR3reco->SetBinContent(482, 254);
    h_LR3reco->SetBinContent(483, 198);
    h_LR3reco->SetBinContent(484, 35);

    h_LR3->SetLineColor(kBlue-7);
    h_LR3->SetLineWidth(2);
    h_LR3->SetFillColorAlpha(kBlue-7, 0.5);
    h_LR3reco->SetLineColor(kGreen-4);
    h_LR3reco->SetLineWidth(3);
    h_LR3reco->SetMarkerColor(kGreen-4);
    h_LR3reco->SetMarkerStyle(22);
    h_LR3reco->SetMarkerSize(2);

    h_LR1->GetYaxis()->SetTitleSize(0.06);
    h_LR1->GetXaxis()->SetTitleSize(0.06);
    h_LR1->GetXaxis()->SetTitleOffset(0.9);
    h_LR1->GetYaxis()->SetTitleOffset(1.3);
    h_LR1->GetXaxis()->SetLabelSize(0.05);
    h_LR1->GetYaxis()->SetLabelSize(0.05);

    h_LR2->GetYaxis()->SetTitleSize(0.06);
    h_LR2->GetXaxis()->SetTitleSize(0.06);
    h_LR2->GetXaxis()->SetTitleOffset(0.9);
    h_LR2->GetYaxis()->SetTitleOffset(1.3);
    h_LR2->GetXaxis()->SetLabelSize(0.04);
    h_LR2->GetYaxis()->SetLabelSize(0.04);

    h_LR3->GetYaxis()->SetTitleSize(0.06);
    h_LR3->GetXaxis()->SetTitleSize(0.06);
    h_LR3->GetXaxis()->SetTitleOffset(0.9);
    h_LR3->GetYaxis()->SetTitleOffset(1.3);
    h_LR3->GetXaxis()->SetLabelSize(0.04);
    h_LR3->GetYaxis()->SetLabelSize(0.04);

    

    TCanvas *c_1 = new TCanvas("c_1", "c_1", 800, 800);
    c_1->cd();
    c_1->SetLeftMargin(0.16); c_1->SetBottomMargin(0.16);
    h_LR1->GetXaxis()->SetRangeUser(211, 218);
    h_LR1->Draw("HIST");
    h_LR1->GetXaxis()->SetTitle("Strip index");
    h_LR1->GetYaxis()->SetTitle("ADC counts");
    h_LR1reco->Draw("hist same");
    h_LR1reco->Draw("P same");
    TLegend *legend2 = new TLegend(0.18, 0.74, 0.4, 0.9);
    legend2->AddEntry(hsat, "Simulated", "f");
    legend2->AddEntry(hsatreco, "Reconstructed", "lp");
    legend2->SetTextSize(0.035);
    legend2->SetBorderSize(0);
    legend2->SetFillStyle(0);
    legend2->Draw();
    latex1->SetTitle("#scale[1.3]{#bf{CMS}}#it{Simulation Work in progress}");
    latex1->Draw("same");
    c_1->SaveAs("PlayWithHistos/LR_overcorrected_1.pdf");
    latex1->SetTitle("#it{Private work (CMS simulation)}");
    c_1->Modified();
    c_1->Update();
    c_1->SaveAs("PlayWithHistos/LR_overcorrected_1_bis.pdf");

    TCanvas *c_2 = new TCanvas("c_2", "c_2", 800, 800);
    c_2->cd();
    c_2->SetLeftMargin(0.16); c_2->SetBottomMargin(0.16);
    h_LR2->GetXaxis()->SetRangeUser(83, 91);
    h_LR2->Draw("HIST");
    h_LR2->GetXaxis()->SetTitle("Strip index");
    h_LR2->GetYaxis()->SetTitle("ADC counts");
    h_LR2reco->Draw("hist same");
    h_LR2reco->Draw("P same");
    legend2->Draw();
    latex1->SetTitle("#scale[1.3]{#bf{CMS}}#it{Simulation Work in progress}");
    latex1->Draw("same");
    c_2->SaveAs("PlayWithHistos/LR_overcorrected_2.pdf");
    latex1->SetTitle("#it{Private work (CMS simulation)}");
    c_2->Modified();
    c_2->Update();
    c_2->SaveAs("PlayWithHistos/LR_overcorrected_2_bis.pdf");

    TCanvas *c_3 = new TCanvas("c_3", "c_3", 800, 800);
    c_3->cd();
    c_3->SetLeftMargin(0.16); c_3->SetBottomMargin(0.16);
    h_LR3->GetXaxis()->SetRangeUser(476, 485);
    h_LR3->Draw("HIST");
    h_LR3->GetXaxis()->SetTitle("Strip index");
    h_LR3->GetYaxis()->SetTitle("ADC counts");
    h_LR3reco->Draw("hist same");
    h_LR3reco->Draw("P same");
    legend2->Draw();
    latex1->SetTitle("#scale[1.3]{#bf{CMS}}#it{Simulation Work in progress}");
    latex1->Draw("same");
    c_3->SaveAs("PlayWithHistos/LR_overcorrected_3.pdf");
    latex1->SetTitle("#it{Private work (CMS simulation)}");
    c_3->Modified();
    c_3->Update();
    c_3->SaveAs("PlayWithHistos/LR_overcorrected_3_bis.pdf");


    return;
}

void Run2_vs_Run3_gluino__TriggerEff() {

    TFile *ifileRun2 = new TFile("../output/Gluino_V19/Gluino_Run2_MET_madgraph_2000_V13p2.root", "READ");
    TFile *ifileRun3 = new TFile("../output/Gluino_V19/Gluino_Run3_MET_madgraph_2000_V19p1.root", "READ");

    TH1F *PseudoCaloMET_Run2 = (TH1F*)ifileRun2->Get("METanalysis_Eta2p4_EffTrg_PseudoCaloMET");
    TH1F *if___orMETtrg___PseudoCaloMET_Run2 = (TH1F*)ifileRun2->Get("METanalysis_Eta2p4_EffTrg_if___orMETtrg___PseudoCaloMET");
    TH1F *PseudoCaloMET_Run3 = (TH1F*)ifileRun3->Get("METanalysis_Eta2p4_EffTrg_PseudoCaloMET");
    TH1F *if___orMETtrg___PseudoCaloMET_Run3 = (TH1F*)ifileRun3->Get("METanalysis_Eta2p4_EffTrg_if___orMETtrg___PseudoCaloMET");
    
    TH1F *eff_orMETtrg_PseudoCaloMET_Run2 = (TH1F*)if___orMETtrg___PseudoCaloMET_Run2->Clone("eff_orMETtrg_PseudoCaloMET_Run2");
    TH1F *eff_orMETtrg_PseudoCaloMET_Run3 = (TH1F*)if___orMETtrg___PseudoCaloMET_Run3->Clone("eff_orMETtrg_PseudoCaloMET_Run3");

    eff_orMETtrg_PseudoCaloMET_Run2->Divide(PseudoCaloMET_Run2);
    eff_orMETtrg_PseudoCaloMET_Run3->Divide(PseudoCaloMET_Run3);

    TCanvas *c1 = new TCanvas("c1", "c1", 800, 600);
    gStyle->SetOptStat(0);
    eff_orMETtrg_PseudoCaloMET_Run2->GetXaxis()->SetTitle("PseudoMET (~ CaloMET) [GeV]");
    eff_orMETtrg_PseudoCaloMET_Run2->GetYaxis()->SetTitle("eff. OR all MET triggers");
    eff_orMETtrg_PseudoCaloMET_Run2->GetYaxis()->SetRangeUser(0, 1);
    eff_orMETtrg_PseudoCaloMET_Run2->GetXaxis()->SetRangeUser(0, 1200);


    eff_orMETtrg_PseudoCaloMET_Run2->SetLineColor(kRed);
    eff_orMETtrg_PseudoCaloMET_Run2->SetMarkerColor(kRed);
    eff_orMETtrg_PseudoCaloMET_Run2->SetMarkerStyle(20);
    eff_orMETtrg_PseudoCaloMET_Run2->Draw("E1");
    eff_orMETtrg_PseudoCaloMET_Run3->SetLineColor(kBlue-7);
    eff_orMETtrg_PseudoCaloMET_Run3->SetMarkerColor(kBlue-7);
    eff_orMETtrg_PseudoCaloMET_Run3->SetMarkerStyle(22);
    eff_orMETtrg_PseudoCaloMET_Run3->Draw("E1 same");

    TLegend *legend = new TLegend(0.6, 0.2, 0.85, 0.5);
    legend->AddEntry(eff_orMETtrg_PseudoCaloMET_Run2, "Run2", "lep");
    legend->AddEntry(eff_orMETtrg_PseudoCaloMET_Run3, "Run3", "lep");
    legend->SetBorderSize(0);
    legend->SetFillStyle(0);
    legend->Draw();

    c1->SaveAs("PlayWithHistos/Run2_vs_Run3_gluino__TriggerEff.pdf");

    return;
}

void ComparePseudoMET(bool isRescaled = true) {

    TFile *ifileWmunu = new TFile("../output/Wjets2024_V14/WjetMuNu2024_V14p9_weighted.root", "READ");
    TFile *ifileTTbar = new TFile("../output/TTbar2024_V15/TTbar2024_V15p8.root", "READ");
    TFile *ifileGluino = new TFile("../output/Gluino_V19/Gluino_Run3_MET_madgraph_2000_V19p1.root", "READ");

    TH1F *PseudoMET_Wmunu = (TH1F*)ifileWmunu->Get(Form("Nosel_PseudoCaloMET%s", isRescaled ? "_weighted" : ""));
    TH1F *PseudoMET_TTbar = (TH1F*)ifileTTbar->Get(Form("Nosel_PseudoCaloMET%s", isRescaled ? "_weighted" : ""));
    TH1F *PseudoMET_Gluino = (TH1F*)ifileGluino->Get(Form("Nosel_PseudoCaloMET%s", isRescaled ? "_rescaled" : ""));

    PseudoMET_Wmunu->Scale(1./PseudoMET_Wmunu->Integral());
    PseudoMET_TTbar->Scale(1./PseudoMET_TTbar->Integral());
    PseudoMET_Gluino->Scale(1./PseudoMET_Gluino->Integral());

    TCanvas *c1 = new TCanvas("c1", "c1", 800, 600);
    gStyle->SetOptStat(0);
    PseudoMET_Wmunu->GetXaxis()->SetTitle("PseudoMET (~ CaloMET) [GeV]");
    PseudoMET_Wmunu->GetYaxis()->SetTitle("Events (normalised)");

    PseudoMET_Wmunu->SetLineColor(kBlue-7);
    PseudoMET_Wmunu->SetFillColorAlpha(kBlue-7, 0.5);
    PseudoMET_Wmunu->Draw("HIST");
    PseudoMET_TTbar->SetLineColor(kRed);
    PseudoMET_TTbar->SetFillColorAlpha(kRed, 0.5);
    PseudoMET_TTbar->Draw("HIST same");
    PseudoMET_Gluino->SetLineColor(kBlack);
    PseudoMET_Gluino->Draw("HIST same");
    TLegend *legend = new TLegend(0.6, 0.7, 0.85, 0.9);
    legend->AddEntry(PseudoMET_Wmunu, "W+jets", "f");
    legend->AddEntry(PseudoMET_TTbar, "TTbar", "f");
    legend->AddEntry(PseudoMET_Gluino, "Gluino", "f");
    legend->SetBorderSize(0);
    legend->SetFillStyle(0);
    legend->Draw();
    c1->SetLogy();
    c1->SaveAs(Form("PlayWithHistos/Compare_PseudoMET%s.pdf", isRescaled ? "_rescaled" : "_NOTrescaled"));

    return;
}

void YieldAfterSF(bool isRescaled = true, bool isMuSelection = false, bool isMETSelection = false, bool isTTbarSelection = false) {

    TFile *ifileWmunu = new TFile("../output/Wjets2024_V14/WjetMuNu2024_V14p8_weighted.root", "READ");
    TFile *ifileTTbar = new TFile("../output/TTbar2024_V15/TTbar2024_V15p8_weighted.root", "READ");
    TFile *ifileDataMu = new TFile("../output/Mu2024_V18/Mu2024_V18.root", "READ");
    TFile *ifileDataMET = new TFile("../output/JetMET2024_V12/JetMET2024_V12p24.root", "READ");
    TFile *ifileDataMuonEG = new TFile("../output/MuonEG_V17/MuonEG2024_V17p4.root", "READ");
    TFile *ifileGluino = new TFile("../output/Gluino_V19/Gluino_Run3_MET_madgraph_2000_V19p1.root", "READ");

    TH1F *PostTrigger_PseudoCaloMET_SF_rescaled___MC, *PostTrigger_PseudoCaloMET_SF_NOTrescaled___DATA, *PostTrigger_PseudoCaloMET_SF_rescaled___Gluino;
    if (isMuSelection) {
        PostTrigger_PseudoCaloMET_SF_rescaled___MC = (TH1F*)ifileWmunu->Get(Form("CalibPseudoMET_MuWay%s_if___orMETtrg___PseudoCaloMET", isRescaled ? "_isRescaled" : ""));
        PostTrigger_PseudoCaloMET_SF_NOTrescaled___DATA = (TH1F*)ifileDataMu->Get("CalibPseudoMET_MuWay_if___orMETtrg___PseudoCaloMET"); // take the not rescaled one for data.
        PostTrigger_PseudoCaloMET_SF_rescaled___Gluino = (TH1F*)ifileGluino->Get(Form("METanalysis_Eta2p4_PseudoCaloMET%s", isRescaled ? "_rescaled" : ""));
    }
    else if (isMETSelection) {
        PostTrigger_PseudoCaloMET_SF_rescaled___MC = (TH1F*)ifileWmunu->Get(Form("Nm1_event_CaloMET%s", isRescaled ? "_weighted" : ""));
        PostTrigger_PseudoCaloMET_SF_NOTrescaled___DATA = (TH1F*)ifileDataMET->Get("Nm1_event_CaloMET"); // take the not rescaled one for data.
        PostTrigger_PseudoCaloMET_SF_rescaled___Gluino = (TH1F*)ifileGluino->Get(Form("Nm1_event_CaloMET%s", isRescaled ? "_rescaled" : ""));
    }
    else if (isTTbarSelection) {
        PostTrigger_PseudoCaloMET_SF_rescaled___MC = (TH1F*)ifileTTbar->Get(Form("CalibPseudoMET%s_if___orMETtrg___PseudoCaloMET", isRescaled ? "_isRescaled" : ""));
        PostTrigger_PseudoCaloMET_SF_NOTrescaled___DATA = (TH1F*)ifileDataMuonEG->Get("CalibPseudoMET_if___orMETtrg___PseudoCaloMET"); // take the not rescaled one for data.
        PostTrigger_PseudoCaloMET_SF_rescaled___Gluino = (TH1F*)ifileGluino->Get(Form("METanalysis_Eta2p4_PseudoCaloMET%s", isRescaled ? "_rescaled" : ""));
    }


    PostTrigger_PseudoCaloMET_SF_NOTrescaled___DATA->Scale(1./PostTrigger_PseudoCaloMET_SF_NOTrescaled___DATA->Integral());
    PostTrigger_PseudoCaloMET_SF_rescaled___MC->Scale(1./PostTrigger_PseudoCaloMET_SF_rescaled___MC->Integral());
    PostTrigger_PseudoCaloMET_SF_rescaled___Gluino->Scale(1./PostTrigger_PseudoCaloMET_SF_rescaled___Gluino->Integral());

    float yieldMC = 0;
    int binStart = PostTrigger_PseudoCaloMET_SF_rescaled___MC->FindBin(170.0);
    int binEnd = PostTrigger_PseudoCaloMET_SF_rescaled___MC->GetNbinsX() + 1; // +1 = overflow
    for (int i = binStart; i <= binEnd; i++) yieldMC += PostTrigger_PseudoCaloMET_SF_rescaled___MC->GetBinContent(i);
    
    float yieldData = 0;
    binStart = PostTrigger_PseudoCaloMET_SF_NOTrescaled___DATA->FindBin(170.0);
    binEnd = PostTrigger_PseudoCaloMET_SF_NOTrescaled___DATA->GetNbinsX() + 1; // +1 = overflow
    for (int i = binStart; i <= binEnd; i++) yieldData += PostTrigger_PseudoCaloMET_SF_NOTrescaled___DATA->GetBinContent(i);

    float yieldGluino = 0;
    binStart = PostTrigger_PseudoCaloMET_SF_rescaled___Gluino->FindBin(170.0);
    binEnd = PostTrigger_PseudoCaloMET_SF_rescaled___Gluino->GetNbinsX() + 1; // +1 = overflow
    for (int i = binStart; i <= binEnd; i++) yieldGluino += PostTrigger_PseudoCaloMET_SF_rescaled___Gluino->GetBinContent(i);

    cout << (isRescaled ? "With rescaling:" : "Without rescaling:") << endl;
    if (isMETSelection) cout << "HLT MET + HSCP selection:" << endl;
    else if (isMuSelection) cout << "HLT mu + HSCP selection:" << endl;
    else if (isTTbarSelection) cout << "HLT MuonEG + HSCP selection:" << endl;
    cout << "Yield in data (not rescaled) = " << yieldData << endl;
    cout << "Yield in MC (rescaled) = " << yieldMC << endl;
    if (isMETSelection) cout << "Yield in Gluino MC (rescaled) = " << yieldGluino << endl;
    cout << "ratio (Data/MC)= " << yieldData/yieldMC << endl;

    // clone PostTrigger_PseudoCaloMET_SF_NOTrescaled___DATA only for data from 170 up to N+1 and draw hit hashed:
    TH1F *PostTrigger_PseudoCaloMET_SF_NOTrescaled___DATA_clone = (TH1F*)PostTrigger_PseudoCaloMET_SF_NOTrescaled___DATA->Clone("PostTrigger_PseudoCaloMET_SF_NOTrescaled___DATA_clone");
    PostTrigger_PseudoCaloMET_SF_NOTrescaled___DATA_clone->Reset();
    for (int i = PostTrigger_PseudoCaloMET_SF_NOTrescaled___DATA->FindBin(170.0); i <= PostTrigger_PseudoCaloMET_SF_NOTrescaled___DATA->GetNbinsX() + 1; i++) 
        PostTrigger_PseudoCaloMET_SF_NOTrescaled___DATA_clone->SetBinContent(i, PostTrigger_PseudoCaloMET_SF_NOTrescaled___DATA->GetBinContent(i));
    TH1F *PostTrigger_PseudoCaloMET_SF_rescaled___MC_clone = (TH1F*)PostTrigger_PseudoCaloMET_SF_rescaled___MC->Clone("PostTrigger_PseudoCaloMET_SF_rescaled___MC_clone");
    PostTrigger_PseudoCaloMET_SF_rescaled___MC_clone->Reset();
    for (int i = PostTrigger_PseudoCaloMET_SF_rescaled___MC->FindBin(170.0); i <= PostTrigger_PseudoCaloMET_SF_rescaled___MC->GetNbinsX() + 1; i++) 
        PostTrigger_PseudoCaloMET_SF_rescaled___MC_clone->SetBinContent(i, PostTrigger_PseudoCaloMET_SF_rescaled___MC->GetBinContent(i));
    TH1F *PostTrigger_PseudoCaloMET_SF_rescaled___Gluino_clone = (TH1F*)PostTrigger_PseudoCaloMET_SF_rescaled___Gluino->Clone("PostTrigger_PseudoCaloMET_SF_rescaled___Gluino_clone");
    PostTrigger_PseudoCaloMET_SF_rescaled___Gluino_clone->Reset();
    for (int i = PostTrigger_PseudoCaloMET_SF_rescaled___Gluino->FindBin(170.0); i <= PostTrigger_PseudoCaloMET_SF_rescaled___Gluino->GetNbinsX() + 1; i++) 
        PostTrigger_PseudoCaloMET_SF_rescaled___Gluino_clone->SetBinContent(i, PostTrigger_PseudoCaloMET_SF_rescaled___Gluino->GetBinContent(i));

    TCanvas *c1 = new TCanvas("c1", "c1", 800, 600);
    gStyle->SetOptStat(0);
    PostTrigger_PseudoCaloMET_SF_NOTrescaled___DATA->SetLineColor(kBlack);
    PostTrigger_PseudoCaloMET_SF_NOTrescaled___DATA->SetMarkerColor(kBlack);
    PostTrigger_PseudoCaloMET_SF_NOTrescaled___DATA->SetMarkerStyle(20);
    PostTrigger_PseudoCaloMET_SF_NOTrescaled___DATA_clone->SetLineColor(kBlack);
    PostTrigger_PseudoCaloMET_SF_NOTrescaled___DATA_clone->SetFillColorAlpha(kBlack, 0.5);
    PostTrigger_PseudoCaloMET_SF_rescaled___MC->SetLineColor(kBlue-7);
    PostTrigger_PseudoCaloMET_SF_rescaled___MC->SetFillColorAlpha(kBlue-7, 0.5);
    PostTrigger_PseudoCaloMET_SF_rescaled___MC_clone->SetLineColor(kBlue-7);
    PostTrigger_PseudoCaloMET_SF_rescaled___MC_clone->SetFillColorAlpha(kBlue-7, 0.5);
    PostTrigger_PseudoCaloMET_SF_rescaled___Gluino_clone->SetLineColor(kRed);
    PostTrigger_PseudoCaloMET_SF_rescaled___Gluino_clone->SetFillColorAlpha(kRed, 0.5);
    PostTrigger_PseudoCaloMET_SF_rescaled___Gluino->SetLineColor(kRed);
    PostTrigger_PseudoCaloMET_SF_rescaled___Gluino->SetMarkerColor(kRed);
    PostTrigger_PseudoCaloMET_SF_rescaled___Gluino->SetMarkerStyle(22);

    PostTrigger_PseudoCaloMET_SF_rescaled___MC->GetXaxis()->SetTitle("PseudoMET (~ CaloMET) [GeV]");
    PostTrigger_PseudoCaloMET_SF_rescaled___MC->GetYaxis()->SetTitle("Events (normalised)");

    PostTrigger_PseudoCaloMET_SF_rescaled___MC->Draw("HIST");
    //PostTrigger_PseudoCaloMET_SF_rescaled___MC_clone->Draw("HIST same");
    //PostTrigger_PseudoCaloMET_SF_NOTrescaled___DATA_clone->Draw("HIST same");
    PostTrigger_PseudoCaloMET_SF_NOTrescaled___DATA->Draw("E1 same");
    if (isMETSelection) {
        //PostTrigger_PseudoCaloMET_SF_rescaled___Gluino_clone->Draw("HIST same");
        PostTrigger_PseudoCaloMET_SF_rescaled___Gluino->Draw("E1 same");
    }
    TLegend *legend = new TLegend(0.6, 0.7, 0.85, 0.9);
    legend->AddEntry(PostTrigger_PseudoCaloMET_SF_NOTrescaled___DATA, "Data", "lep");
    legend->AddEntry(PostTrigger_PseudoCaloMET_SF_rescaled___MC, Form("MC (%sSF)",(isRescaled) ? "rescaled + " : ""), "f");
    if (isMETSelection) legend->AddEntry(PostTrigger_PseudoCaloMET_SF_rescaled___Gluino, Form("Gluino2000 (%sSF)",(isRescaled) ? "rescaled + " : ""), "lep");
    legend->SetBorderSize(0);
    legend->SetFillStyle(0);
    legend->Draw();
    c1->SetLogy();
    if (isMETSelection) c1->SaveAs(Form("PlayWithHistos/YieldAfterSF_HLTmet_%s.pdf", isRescaled ? "_rescaled" : "_NOTrescaled"));
    else if (isMuSelection) c1->SaveAs(Form("PlayWithHistos/YieldAfterSF_HLTmu_%s.pdf", isRescaled ? "_rescaled" : "_NOTrescaled"));
    else if (isTTbarSelection) c1->SaveAs(Form("PlayWithHistos/YieldAfterSF_HLTMuonEG_%s.pdf", isRescaled ? "_rescaled" : "_NOTrescaled"));


    return;
}

void PlotSF(const std::string& fileWmunu = "PlayWithHistos/SF_TriggerEff_Mu2024_WMuNu_PseudoMETrescaled.txt",
           const std::string& fileTTbar  = "PlayWithHistos/SF_TriggerEff_MuonEG2024_TTbar_PseudoMETrescaled.txt") {

  auto parse = [&](const std::string& fname,
                    const std::string& name,
                    const std::string& title) -> TH1F* {
    std::ifstream f(fname);
    if (!f.is_open()) { std::cerr << "Cannot open: " << fname << "\n"; return nullptr; }

    std::vector<double> bins, vals, errs;
    double b, vd, v, vs;
    while (f >> b >> vd >> v >> vs) {
      bins.push_back(b); vals.push_back(v); errs.push_back((vs - vd) / 2.0);
    }

    int    n    = bins.size();
    double step = (n > 1) ? (bins[1] - bins[0]) : 25.0;
    std::vector<double> edges;
    for (int i = 0; i < n; i++) edges.push_back(bins[i] - step/2.0);
    edges.push_back(bins[n-1] + step/2.0);

    TH1F* h = new TH1F(name.c_str(), title.c_str(), n, edges.data());
    for (int i = 0; i < n; i++) { h->SetBinContent(i+1, vals[i]); h->SetBinError(i+1, errs[i]); }
    return h;
  };

  TH1F* hW = parse(fileWmunu, "hWmunu", "Scale Factors;PseudoMET (~ CaloMET) [GeV];SF");
  TH1F* hT = parse(fileTTbar,  "hTTbar", "Scale Factors;PseudoMET (~ CaloMET) [GeV];SF");
  if (!hW || !hT) return;

  hW->SetLineColor(kBlue+1);  hW->SetMarkerColor(kBlue+1);  hW->SetMarkerStyle(20);
  hT->SetLineColor(kRed+1);   hT->SetMarkerColor(kRed+1);   hT->SetMarkerStyle(21);

  TCanvas* c = new TCanvas("cSF", "Scale Factors", 800, 600);
  c->SetLeftMargin(0.12); c->SetBottomMargin(0.12);
  gStyle->SetOptStat(0);

  hW->GetYaxis()->SetRangeUser(0.65, 1.10);
  hW->Draw("E1"); hT->Draw("E1 SAME");

  TLine* line = new TLine(hW->GetXaxis()->GetXmin(), 1.0,
                            hW->GetXaxis()->GetXmax(), 1.0);
  line->SetLineStyle(2); line->SetLineColor(kGray+2); line->Draw();

  TLegend* leg = new TLegend(0.65, 0.15, 0.88, 0.32);
  leg->AddEntry(hW, "SF Muon/Wmunu", "lep");
  leg->AddEntry(hT, "SF MuonEG/TTbar", "lep");
  leg->SetBorderSize(0); leg->Draw();

  c->SaveAs("PlayWithHistos/Plot_SF___MuonWmunu_vs_MuonEGttbar.pdf");
}


void TableGluino(bool isRescaled) {

    TFile *ifileGluino = new TFile("Gluino_Run3_MET_madgraph_2000_V19p1.root", "READ"); // ../output/Gluino_V19/

    // Départ
    TH1F *Nosel_PseudoCaloMET = (TH1F*)ifileGluino->Get(Form("Nosel_PseudoCaloMET%s", isRescaled ? "_rescaled" : ""));

    // Trigger
    TH1F *PostTrigger_PseudoCaloMET_rescaled = (TH1F*)ifileGluino->Get(Form("PostTrigger_PseudoCaloMET_%srescaled", isRescaled ? "" : "NOT"));

    // Trigger + SF
    TH1F *PostTrigger_PseudoCaloMET_SF_rescaled___Gluino = (TH1F*)ifileGluino->Get(Form("PostTrigger_PseudoCaloMET_SF_%srescaled", isRescaled ? "" : "NOT"));

    // PseudoMET > 170
    TH1F *PostTrigger_PseudoCaloMET_SF_rescaled___Gluino_clone = (TH1F*)PostTrigger_PseudoCaloMET_SF_rescaled___Gluino->Clone("PostTrigger_PseudoCaloMET_SF_rescaled___Gluino_clone");
    PostTrigger_PseudoCaloMET_SF_rescaled___Gluino_clone->Reset();
    for (int i = PostTrigger_PseudoCaloMET_SF_rescaled___Gluino->FindBin(170.0); i <= PostTrigger_PseudoCaloMET_SF_rescaled___Gluino->GetNbinsX() + 1; i++) 
        PostTrigger_PseudoCaloMET_SF_rescaled___Gluino_clone->SetBinContent(i, PostTrigger_PseudoCaloMET_SF_rescaled___Gluino->GetBinContent(i));

    // HSCP sel
    TH1F *METanalysis_Eta2p4_PseudoCaloMET = (TH1F*)ifileGluino->Get(Form("METanalysis_PseudoMET%sescaled_Eta2p4_PseudoCaloMET_%srescaled", isRescaled ? "r" : "notR", isRescaled ? "" : "NOT"));


    cout << "# Gluino2000        " << (isRescaled ? "Rescaled" : "NOT Rescaled") << endl;
    cout << "Initial yield:       " << Nosel_PseudoCaloMET->Integral() << endl;
    cout << "After trigger:       " << PostTrigger_PseudoCaloMET_rescaled->Integral() << "    " << 1.0*PostTrigger_PseudoCaloMET_rescaled->Integral()/Nosel_PseudoCaloMET->Integral() << endl;
    cout << "After trigger + SF:  " << PostTrigger_PseudoCaloMET_SF_rescaled___Gluino->Integral() << "    " << 1.0*PostTrigger_PseudoCaloMET_SF_rescaled___Gluino->Integral()/Nosel_PseudoCaloMET->Integral() << endl;
    cout << "After PseudoMET>170: " << PostTrigger_PseudoCaloMET_SF_rescaled___Gluino_clone->Integral() << "    " << 1.0*PostTrigger_PseudoCaloMET_SF_rescaled___Gluino_clone->Integral()/Nosel_PseudoCaloMET->Integral() << endl;
    cout << "After HSCP sel:      " << METanalysis_Eta2p4_PseudoCaloMET->Integral() << "    " << 1.0*METanalysis_Eta2p4_PseudoCaloMET->Integral()/Nosel_PseudoCaloMET->Integral() << endl;


    return;
}


void CompareKinematics() {

    TFile *ifile = new TFile("../output/JetMET2024_V12/JetMET2024_V12p26.root", "READ");

    TH2F *trackPT_vs_trackPseudoTrackPT = (TH2F*)ifile->Get("trackPT_vs_trackPseudoTrackPT");
    TH2F *trackETA_vs_trackPseudoTrackETA = (TH2F*)ifile->Get("trackETA_vs_trackPseudoTrackETA");
    TH2F *trackPHI_vs_trackPseudoTrackPHI = (TH2F*)ifile->Get("trackPHI_vs_trackPseudoTrackPHI");

    trackPT_vs_trackPseudoTrackPT->GetXaxis()->SetTitle("PF p_{T} [GeV/c]");
    trackPT_vs_trackPseudoTrackPT->GetYaxis()->SetTitle("Track p_{T} [GeV/c]");
    trackPT_vs_trackPseudoTrackPT->GetYaxis()->SetTitleOffset(1.2);
    trackPT_vs_trackPseudoTrackPT->GetZaxis()->SetTitle("Events");
    trackPT_vs_trackPseudoTrackPT->SetTitle("");
    trackPT_vs_trackPseudoTrackPT->GetYaxis()->SetTitleSize(0.06);
    trackPT_vs_trackPseudoTrackPT->GetXaxis()->SetTitleSize(0.06);
    trackPT_vs_trackPseudoTrackPT->GetXaxis()->SetTitleOffset(0.9);
    trackPT_vs_trackPseudoTrackPT->GetYaxis()->SetTitleOffset(1);
    trackPT_vs_trackPseudoTrackPT->GetXaxis()->SetLabelSize(0.05);
    trackPT_vs_trackPseudoTrackPT->GetYaxis()->SetLabelSize(0.05);
    trackPT_vs_trackPseudoTrackPT->GetZaxis()->SetTitleSize(0.06);
    trackPT_vs_trackPseudoTrackPT->GetZaxis()->SetTitleOffset(0.9);
    trackPT_vs_trackPseudoTrackPT->GetZaxis()->SetLabelSize(0.05);

    trackETA_vs_trackPseudoTrackETA->GetXaxis()->SetTitle("PF #eta");
    trackETA_vs_trackPseudoTrackETA->GetYaxis()->SetTitle("Track #eta");
    trackETA_vs_trackPseudoTrackETA->GetZaxis()->SetTitle("Events");
    trackETA_vs_trackPseudoTrackETA->SetTitle("");
    trackETA_vs_trackPseudoTrackETA->GetYaxis()->SetTitleSize(0.06);
    trackETA_vs_trackPseudoTrackETA->GetXaxis()->SetTitleSize(0.06);
    trackETA_vs_trackPseudoTrackETA->GetXaxis()->SetTitleOffset(0.9);
    trackETA_vs_trackPseudoTrackETA->GetYaxis()->SetTitleOffset(0.7);
    trackETA_vs_trackPseudoTrackETA->GetXaxis()->SetLabelSize(0.05);
    trackETA_vs_trackPseudoTrackETA->GetYaxis()->SetLabelSize(0.05);
    trackETA_vs_trackPseudoTrackETA->GetZaxis()->SetTitleSize(0.06);
    trackETA_vs_trackPseudoTrackETA->GetZaxis()->SetTitleOffset(0.9);
    trackETA_vs_trackPseudoTrackETA->GetZaxis()->SetLabelSize(0.05);

    trackPHI_vs_trackPseudoTrackPHI->GetXaxis()->SetTitle("PF #phi");
    trackPHI_vs_trackPseudoTrackPHI->GetYaxis()->SetTitle("Track #phi ");
    trackPHI_vs_trackPseudoTrackPHI->GetZaxis()->SetTitle("Events");
    trackPHI_vs_trackPseudoTrackPHI->SetTitle("");
    trackPHI_vs_trackPseudoTrackPHI->GetYaxis()->SetTitleSize(0.06);
    trackPHI_vs_trackPseudoTrackPHI->GetXaxis()->SetTitleSize(0.06);
    trackPHI_vs_trackPseudoTrackPHI->GetXaxis()->SetTitleOffset(0.9);
    trackPHI_vs_trackPseudoTrackPHI->GetYaxis()->SetTitleOffset(0.7);
    trackPHI_vs_trackPseudoTrackPHI->GetXaxis()->SetLabelSize(0.05);
    trackPHI_vs_trackPseudoTrackPHI->GetYaxis()->SetLabelSize(0.05);
    trackPHI_vs_trackPseudoTrackPHI->GetZaxis()->SetTitleSize(0.06);
    trackPHI_vs_trackPseudoTrackPHI->GetZaxis()->SetTitleOffset(0.9);
    trackPHI_vs_trackPseudoTrackPHI->GetZaxis()->SetLabelSize(0.05);

    TLatex *tex = new TLatex(0.62, 0.91, "110 fb^{-1} (13.6 TeV)");
    tex->SetNDC();
    tex->SetTextFont(42);
    tex->SetTextSize(0.04);

    TLatex *latex1 = new TLatex(0.16, 0.91, "#scale[1.3]{#bf{CMS}}#it{Simulation Work in progress}");
    latex1->SetNDC();
    latex1->SetTextFont(42);
    latex1->SetTextSize(0.04);
    

    TCanvas *c1 = new TCanvas("c1", "c1", 800, 600);
    
    c1->SetLeftMargin(0.16); c1->SetBottomMargin(0.16);c1->SetRightMargin(0.16);
    gStyle->SetOptStat(0);
    gStyle->SetPalette(kViridis);
    trackPT_vs_trackPseudoTrackPT->Draw("COLZ");
    tex->Draw();
    c1->SetLogz();
    latex1->Draw();
    c1->SaveAs("PlayWithHistos/CompareKinematics_PT.pdf");
    latex1->SetTitle("#it{Private work (CMS data)}");
    c1->Modified();
    c1->Update();
    c1->SaveAs("PlayWithHistos/CompareKinematics_PT_bis.pdf");
    latex1->SetTitle("#scale[1.3]{#bf{CMS}}#it{Work in progress}");


    TCanvas *c2 = new TCanvas("c2", "c2", 800, 600);
    c2->SetRightMargin(0.16);
    c2->SetLeftMargin(0.16); c2->SetBottomMargin(0.16);
    gStyle->SetOptStat(0);
    gStyle->SetPalette(kViridis);
    trackETA_vs_trackPseudoTrackETA->Draw("COLZ");
    tex->Draw();
    c2->SetLogz();
    latex1->Draw();
    c2->SaveAs("PlayWithHistos/CompareKinematics_ETA.pdf");
    latex1->SetTitle("#it{Private work (CMS data)}");
    c2->Modified();
    c2->Update();
    c2->SaveAs("PlayWithHistos/CompareKinematics_ETA_bis.pdf");
    latex1->SetTitle("#scale[1.3]{#bf{CMS}}#it{Work in progress}");

    TCanvas *c3 = new TCanvas("c3", "c3", 800, 600);
    c3->SetRightMargin(0.16);
    c3->SetLeftMargin(0.16); c3->SetBottomMargin(0.16);
    gStyle->SetOptStat(0);
    gStyle->SetPalette(kViridis);
    trackPHI_vs_trackPseudoTrackPHI->Draw("COLZ");
    tex->Draw();
    c3->SetLogz();
    latex1->Draw();
    c3->SaveAs("PlayWithHistos/CompareKinematics_PHI.pdf");
    latex1->SetTitle("#it{Private work (CMS data)}");
    c3->Modified();
    c3->Update();
    c3->SaveAs("PlayWithHistos/CompareKinematics_PHI_bis.pdf");
    latex1->SetTitle("#scale[1.3]{#bf{CMS}}#it{Work in progress}");


    return;
}

void LangausFitOnIh() {

    TFile *ofile = new TFile("PlayWithHistos/LangausFitOnIh.root", "RECREATE");

    TFile *ifileWjets = new TFile("../output/Wjets2024_V14/WjetMuNu2024_V14p10_weighted.root", "READ");
    TFile *ifileJetMET = new TFile("../output/JetMET2024_V12/JetMET2024_V12p24.root", "READ");

    TH1F *Ih_wjet = (TH1F*)ifileWjets->Get("Nm1_event_Ih_StripOnly");
    TH1F *Ih_jetmet = (TH1F*)ifileJetMET->Get("Nm1_event_Ih_StripOnly");

    Ih_wjet->SetLineColor(kBlue-7);
    Ih_wjet->SetFillColorAlpha(kBlue-7, 0.5);
    Ih_jetmet->SetLineColor(kBlack);
    Ih_jetmet->SetMarkerColor(kBlack);
    Ih_jetmet->SetMarkerStyle(20);
    Ih_wjet->GetXaxis()->SetTitle("I_{h} (StripOnly)");
    Ih_wjet->GetYaxis()->SetTitle("Events");

    Ih_wjet->Scale(Ih_jetmet->Integral()/Ih_wjet->Integral());


    /////////////////////////////////////////////////////////

    // W+jets
    double peak_wjet  = Ih_wjet->GetBinCenter(Ih_wjet->GetMaximumBin());
    double xmin_wjet  = peak_wjet * 0.8;
    double xmax_wjet  = peak_wjet * 1.2;
    double area_wjet  = Ih_wjet->Integral() * Ih_wjet->GetBinWidth(1);

    TF1 *Langaus_wjet = new TF1("Langaus_wjet", langaufun, xmin_wjet, xmax_wjet, 4);
    Langaus_wjet->SetParNames("Width", "MPV", "Area", "GSigma");
    Langaus_wjet->SetParameters(0.05, peak_wjet, area_wjet, 0.05);
    Langaus_wjet->SetParLimits(0, 1e-4, 1.0);
    Langaus_wjet->SetParLimits(1, xmin_wjet, xmax_wjet);
    Langaus_wjet->SetParLimits(2, 0.0, 1e9);
    Langaus_wjet->SetParLimits(3, 1e-4, 1.0);
    Ih_wjet->Fit("Langaus_wjet", "RMQ");

    // JetMET
    double peak_jm   = Ih_jetmet->GetBinCenter(Ih_jetmet->GetMaximumBin());
    double xmin_jm   = peak_jm * 0.8;
    double xmax_jm   = peak_jm * 1.2;
    double area_jm   = Ih_jetmet->Integral() * Ih_jetmet->GetBinWidth(1);

    TF1 *Langaus_jetmet = new TF1("Langaus_jetmet", langaufun, xmin_jm, xmax_jm, 4);
    Langaus_jetmet->SetParNames("Width", "MPV", "Area", "GSigma");
    Langaus_jetmet->SetParameters(0.05, peak_jm, area_jm, 0.05);
    Langaus_jetmet->SetParLimits(0, 1e-4, 1.0);
    Langaus_jetmet->SetParLimits(1, xmin_jm, xmax_jm);
    Langaus_jetmet->SetParLimits(2, 0.0, 1e9);
    Langaus_jetmet->SetParLimits(3, 1e-4, 1.0);
    Ih_jetmet->Fit("Langaus_jetmet", "RMQ");

    Langaus_wjet->SetLineColor(kGreen);
    Langaus_jetmet->SetLineColor(kRed);


    // Drawing
    TCanvas *c1 = new TCanvas("c1", "c1", 800, 600);
    gStyle->SetOptStat(0);
    Ih_wjet->Draw("HIST");
    Ih_jetmet->Draw("E1 same");
    Langaus_jetmet->Draw("same");
    Langaus_wjet->Draw("same");
    TLegend *legend = new TLegend(0.6, 0.7, 0.85, 0.9);
    legend->AddEntry(Ih_wjet, "W+jets", "f");
    legend->AddEntry(Ih_jetmet, "JetMET", "lep");
    legend->SetBorderSize(0);
    legend->SetFillStyle(0);
    legend->Draw();
    c1->SetLogy();


    cout << "\t\t\t MPV" << endl;
    cout << "W+jets: " << Langaus_wjet->GetParameter("MPV") << " +/- " << Langaus_wjet->GetParError(Langaus_wjet->GetParNumber("MPV")) << endl;
    cout << "JetMET: " << Langaus_jetmet->GetParameter("MPV") << " +/- " << Langaus_jetmet->GetParError(Langaus_jetmet->GetParNumber("MPV")) << endl;

    // OUTPUT: data/MC = 3.2168/3.12692

    ofile->cd();
    c1->Write();
    ofile->Close();

    c1->SaveAs("PlayWithHistos/LangausFitOnIh.pdf");


    return;
}

void ShowSignalEfficiency() {

    TFile *ifileGluino1100 = new TFile("../output/Gluino_V19/Gluino_Run3_MET_madgraph_1100_V19p3_weighted.root", "READ");
    TFile *ifileGluino1200 = new TFile("../output/Gluino_V19/Gluino_Run3_MET_madgraph_1200_V19p3_weighted.root", "READ");
    TFile *ifileGluino1300 = new TFile("../output/Gluino_V19/Gluino_Run3_MET_madgraph_1300_V19p3_weighted.root", "READ");
    TFile *ifileGluino1400 = new TFile("../output/Gluino_V19/Gluino_Run3_MET_madgraph_1400_V19p3_weighted.root", "READ");
    TFile *ifileGluino1600 = new TFile("../output/Gluino_V19/Gluino_Run3_MET_madgraph_1600_V19p3_weighted.root", "READ");
    TFile *ifileGluino1800 = new TFile("../output/Gluino_V19/Gluino_Run3_MET_madgraph_1800_V19p3_weighted.root", "READ");
    TFile *ifileGluino2000 = new TFile("../output/Gluino_V19/Gluino_Run3_MET_madgraph_2000_V19p3_weighted.root", "READ");
    TFile *ifileGluino2200 = new TFile("../output/Gluino_V19/Gluino_Run3_MET_madgraph_2200_V19p3_weighted.root", "READ");
    TFile *ifileGluino2400 = new TFile("../output/Gluino_V19/Gluino_Run3_MET_madgraph_2400_V19p3_weighted.root", "READ");
    TFile *ifileGluino2600 = new TFile("../output/Gluino_V19/Gluino_Run3_MET_madgraph_2600_V19p3_weighted.root", "READ");

    std::vector <string> etaname = {"METanalysis_PseudoMETrescaled_Eta1",
                            "METanalysis_PseudoMETrescaled_Eta1_2p4",
                            "METanalysis_PseudoMETrescaled_Eta2p4"};

    TH1D* pEff_eta1 = new TH1D("eff_eta1", ";Gluino mass [GeV];Signal efficiency", 16, 1050, 2650);
    TH1D* pEff_eta1_2p4 = new TH1D("eff_eta1_2p4", ";Gluino mass [GeV];Signal efficiency", 16, 1050, 2650);
    TH1D* pEff_eta2p4 = new TH1D("eff_eta2p4", ";Gluino mass [GeV];Signal efficiency", 16, 1050, 2650);
    std::vector<TH1D*> pEffs = {pEff_eta1, pEff_eta1_2p4, pEff_eta2p4};
    for (int j = 0; j < etaname.size(); j++) {
        
        for (int i = 1100; i <= 2600; i += 100) {
            TFile *ifile = nullptr;
            if (i == 1100) ifile = ifileGluino1100;
            else if (i == 1200) ifile = ifileGluino1200;
            else if (i == 1300) ifile = ifileGluino1300;
            else if (i == 1400) ifile = ifileGluino1400;
            else if (i == 1600) ifile = ifileGluino1600;
            else if (i == 1800) ifile = ifileGluino1800;
            else if (i == 2000) ifile = ifileGluino2000;
            else if (i == 2200) ifile = ifileGluino2200;
            else if (i == 2400) ifile = ifileGluino2400;
            else if (i == 2600) ifile = ifileGluino2600;
            else continue;

            TH1D *WithSelection = (TH1D*)ifile->Get(Form("%s_nHSCP", etaname[j].c_str()));
            TH1D *WithoutSelection = (TH1D*)ifile->Get("nHSCP");

            int bin = (i - 1050) / 100 + 1;
            pEffs[j]->SetBinContent(bin, WithSelection->Integral()/WithoutSelection->Integral());
            pEffs[j]->SetBinError(bin, sqrt(WithSelection->Integral())/WithoutSelection->Integral());
        }

    }

    TCanvas *c1 = new TCanvas("c1", "c1", 800, 600);
    gStyle->SetOptStat(0);
    pEffs[0]->SetLineColor(kRed);
    pEffs[0]->SetMarkerColor(kRed);
    pEffs[0]->SetMarkerStyle(20);
    pEffs[0]->Draw("E1");

    pEffs[1]->SetLineColor(kGreen-3);
    pEffs[1]->SetMarkerColor(kGreen-3);
    pEffs[1]->SetMarkerStyle(21);
    pEffs[1]->Draw("E1 same");
    
    pEffs[2]->SetLineColor(kBlue-7);
    pEffs[2]->SetMarkerColor(kBlue-7);
    pEffs[2]->SetMarkerStyle(22);
    pEffs[2]->Draw("E1 same");
    

    pEffs[0]->SetTitle("");
    pEffs[0]->GetYaxis()->SetRangeUser(0.0, 1.0);
    TLegend *legend = new TLegend(0.6, 0.7, 0.85, 0.9);
    legend->AddEntry(pEffs[0], "|#eta| < 1.0", "lep");
    legend->AddEntry(pEffs[1], "1.0 < |#eta| < 2.4", "lep");
    legend->AddEntry(pEffs[2], "|#eta| < 2.4", "lep");
    legend->Draw();

    c1->SaveAs("PlayWithHistos/SignalEfficiency_vs_GluinoMass.pdf");


    return;
}


void FpixSlices() {

    TFile *fileWjets = new TFile("../output/Wjets2024_V14/WjetMuNu2024_V14p11_weighted.root", "READ");
    TFile *fileTTbar = new TFile("../output/TTbar2024_V15/TTbar2024_V15p5_weighted.root", "READ");
    TFile *fileQCD = new TFile("../output/QCD2024_V16/QCD2024_mu_V16p1_weighted.root", "READ");
    TFile *fileSignal = new TFile("../output/Gluino_V19/Gluino_Run3_MET_madgraph_2000_V19p3.root", "READ");
    
    TH1F *FpixGluino_Eta1 = (TH1F*)fileSignal->Get("METanalysis_PseudoMETrescaled_Eta1_Fpix");
    TH1F *FpixGluino_Eta1_2p4 = (TH1F*)fileSignal->Get("METanalysis_PseudoMETrescaled_Eta1_2p4_Fpix");
    TH1F *FpixGluino_Eta2p4 = (TH1F*)fileSignal->Get("METanalysis_PseudoMETrescaled_Eta2p4_Fpix");

    TH1F *FpixQCD_Eta1 = (TH1F*)fileQCD->Get("METanalysis_Eta1_Fpix");
    TH1F *FpixQCD_Eta1_2p4 = (TH1F*)fileQCD->Get("METanalysis_Eta1_2p4_Fpix");
    TH1F *FpixQCD_Eta2p4 = (TH1F*)fileQCD->Get("METanalysis_Eta2p4_Fpix");

    TH1F *FpixTTbar_Eta1 = (TH1F*)fileTTbar->Get("METanalysis_Eta1_Fpix");
    TH1F *FpixTTbar_Eta1_2p4 = (TH1F*)fileTTbar->Get("METanalysis_Eta1_2p4_Fpix");
    TH1F *FpixTTbar_Eta2p4 = (TH1F*)fileTTbar->Get("METanalysis_Eta2p4_Fpix");

    TH1F *FpixWjets_Eta1 = (TH1F*)fileWjets->Get("METanalysis_PseudoMETrescaled_Eta1_Fpix");
    TH1F *FpixWjets_Eta1_2p4 = (TH1F*)fileWjets->Get("METanalysis_PseudoMETrescaled_Eta1_2p4_Fpix");
    TH1F *FpixWjets_Eta2p4 = (TH1F*)fileWjets->Get("METanalysis_PseudoMETrescaled_Eta2p4_Fpix");

    FpixQCD_Eta1->Add(FpixTTbar_Eta1); FpixQCD_Eta1->Add(FpixWjets_Eta1);
    FpixQCD_Eta1_2p4->Add(FpixTTbar_Eta1_2p4); FpixQCD_Eta1_2p4->Add(FpixWjets_Eta1_2p4);
    FpixQCD_Eta2p4->Add(FpixTTbar_Eta2p4); FpixQCD_Eta2p4->Add(FpixWjets_Eta2p4); // QCD + TTbar + Wjets
    

    for (int i = 1; i <= 10; i++) {
        double prob = i * 0.1;
        double qGluino_Eta2p4, qGluino_Eta1, qGluino_Eta1_2p4, qMC_eta2p4, qMC_eta1, qMC_eta1_2p4;

        FpixGluino_Eta2p4->GetQuantiles(1, &qGluino_Eta2p4, &prob);
        FpixQCD_Eta2p4   ->GetQuantiles(1, &qMC_eta2p4,    &prob);
        FpixGluino_Eta1->GetQuantiles(1, &qGluino_Eta1, &prob);
        FpixQCD_Eta1   ->GetQuantiles(1, &qMC_eta1,    &prob);
        FpixGluino_Eta1_2p4->GetQuantiles(1, &qGluino_Eta1_2p4, &prob);
        FpixQCD_Eta1_2p4   ->GetQuantiles(1, &qMC_eta1_2p4,    &prob);

        cout << "      Quantile " << prob << ":\n";
        cout << "Gluino |#eta| < 2.4: " << qGluino_Eta2p4 << "\n";
        cout << "Gluino |#eta| < 1.0: " << qGluino_Eta1 << "\n";
        cout << "Gluino 1.0 < |#eta| < 2.4: " << qGluino_Eta1_2p4 << "\n";
        cout << "MC (QCD+TTbar+Wjets) |#eta| < 2.4: " << qMC_eta2p4 << "\n";
        cout << "MC (QCD+TTbar+Wjets) |#eta| < 1.0: " << qMC_eta1 << "\n";
        cout << "MC (QCD+TTbar+Wjets) 1.0 < |#eta| < 2.4: " << qMC_eta1_2p4 << "\n";
    }

    
    
    return;
}


void DefineIhCut() {

    TFile *ifileData = new TFile("../output/JetMET2024_V12/JetMET2024_V12p24.root", "READ");

    TH1F *Ih = (TH1F*)ifileData->Get("Nm1_Ih_StripOnly");

    double C_2024 = 2.9784;


    double totalIntegral = Ih->Integral(C_2024, Ih->GetNbinsX() + 1);
    double targetIntegral = totalIntegral * 0.01;
    double cumulativeIntegral = 0.0;
    double x_b = 0.0;
    for (int i = Ih->GetNbinsX(); i >= 1; i--) {
        cumulativeIntegral += Ih->GetBinContent(i);
        if (cumulativeIntegral >= targetIntegral) {
            x_b = Ih->GetBinLowEdge(i);
            break;
        }
    }

    Ih->SetLineColor(kBlue);
    
    TCanvas *c1 = new TCanvas("c1", "c1", 800, 600);
    gStyle->SetOptStat(0);
    Ih->Draw("HIST");
    TLine *line = new TLine(x_b, 0, x_b, Ih->GetMaximum());
    line->SetLineColor(kRed);
    TLine *line2 = new TLine(C_2024, 0, C_2024, Ih->GetMaximum());
    line2->SetLineColor(kBlack);
    line->Draw("same");
    line2->Draw("same");
    c1->SetLogy();

    c1->SaveAs("PlayWithHistos/DefineIhCut.pdf");

    // check


    cout << endl;
    cout << "   xb: " << x_b << endl; 
    cout << "Integral above C: " << totalIntegral << endl;
    cout << "cumulativeIntegral: " << cumulativeIntegral << endl;
    cout << "ratio: " << cumulativeIntegral / totalIntegral << endl;

    return;
}


void CombineHistos()
{
    //MET_trg_eff("../output/Gluino2000_Run2_METtrgEff_V11p15_Eta2p4.root", false);
    //MET_trg_eff("../output/Gluino2000_Run2_METtrgEff_AOD_V11p15_Eta2p4.root", true);
    //MET_trg_eff("METanalysis_Eta2p4_EffTrg", "../output/Gluino_V19/Gluino_Run3_MET_madgraph_2000_V19p1.root", false);
    //MET_trg_eff("METanalysis_Eta2p4_EffTrg", "../output/Gluino_V19/Gluino_Run3_MET_pythia_2000_V19p0.root", false);
    //PFMET_Cut(false);
    //TrigEff_AODvsMiniAOD();

    //MET_trg_eff("CalibPseudoMET", "MET_trg_eff_MC_vs_data", "../output/MuonEG_V17/MuonEG2024_V17p3.root", "../output/TTbar2024_V15/TTbar2024_V15p5.root");
    //MET_trg_eff("METanalysis_Eta2p4_EffTrg", "../output/Gluino_V13/Gluino2000_Run2_MET_V13p1.root", false);
    //Comp_muonEG("../output/MuonEG_V17/MuonEG2024_V17p3.root", "../output/TTbar2024_V15/TTbar2024_V15p5.root");
    MET_trg_eff("CalibPseudoMET_MuWay", "CalibPseudoMET_MuWay", "WMuNu_PseudoMET", "../output/Mu2024_V18/Mu2024_V18.root", "../output/Wjets2024_V14/WjetMuNu2024_V14p8_weighted.root");
    MET_trg_eff("CalibPseudoMET_MuWay", "CalibPseudoMET_MuWay_isRescaled", "WMuNu_PseudoMET_rescaled", "../output/Mu2024_V18/Mu2024_V18.root", "../output/Wjets2024_V14/WjetMuNu2024_V14p8_weighted.root");
    MET_trg_eff("CalibPseudoMET", "CalibPseudoMET_isRescaled", "TTbar_PseudoMET_rescaled", "../output/MuonEG_V17/MuonEG2024_V17p4.root", "../output/TTbar2024_V15/TTbar2024_V15p8_weighted.root");
    //MET_trg_eff("CalibPseudoMET_MuWay", "CalibPseudoMET_MuWay_OTHERisRescaled", "TriggerEff_Mu2024_Wjets_PseudoMET_OTHERrescaled", "../output/Mu2024_V18/Mu2024_V18.root", "../output/Wjets2024_V14/WjetMuNu2024_V14p10_weighted.root");
    

    //Old_vs_New_fits("../output/JetMET2024_V12/JetMET2024_V12p24.root");
    // BKGdependency_preliminary("../output/TTbar2024_V15/TTbar2024_V15p5_weighted.root", "TTbar");
    // BKGdependency_preliminary("../output/Wjets2024_V14/Wjets2024_V14p6_weighted.root", "Wjets");
    // BKGdependency_preliminary("../output/QCD2024_V16/QCD2024_mu_V16p1_weighted.root", "QCD");
    // BKGdependency();

    //GluinoP_mass(true, true);
    //GluinoP_mass(false, true);
    //CompareMaping();

    //Cutflows("../output/QCD2024_V16/QCD2024_mu_V16p1_weighted.root", "../output/TTbar2024_V15/TTbar2024_V15p6_weighted.root", "../output/Wjets2024_V14/WjetMuNu2024_V14p8_weighted.root", "../output/JetMET2024_V12/JetMET2024_V12p24.root", "../output/Gluino_V19/Gluino_Run3_MET_madgraph_2000_V19p1_weighted.root");
    //Cutflows_cutPseudoMET();
    //Nm1Eff(true, true, "../output/QCD2024_V16/QCD2024_mu_V16p1_weighted.root", "../output/TTbar2024_V15/TTbar2024_V15p8_weighted.root", "../output/Wjets2024_V14/WjetMuNu2024_V14p11_weighted.root", "../output/JetMET2024_V12/JetMET2024_V12p24.root", "../output/Gluino_V19/Gluino_Run3_MET_madgraph_2000_V19p3.root");
    //Nm1Eff(false, true, "../output/QCD2024_V16/QCD2024_mu_V16p1_weighted.root", "../output/TTbar2024_V15/TTbar2024_V15p5_weighted.root", "../output/Wjets2024_V14/WjetMuNu2024_V14p8_weighted.root", "../output/JetMET2024_V12/JetMET2024_V12p24.root", "../output/Gluino_V19/Gluino_Run3_MET_madgraph_2000_V19p1.root");
    //Nm1Eff(true, false, "../output/QCD2024_V16/QCD2024_mu_V16p1_weighted.root", "../output/TTbar2024_V15/TTbar2024_V15p8_weighted.root", "../output/Wjets2024_V14/WjetMuNu2024_V14p10_weighted.root", "../output/JetMET2024_V12/JetMET2024_V12p24.root", "../output/Gluino_V19/Gluino_Run3_MET_madgraph_2000_V19p1.root");
    //ShowSignalEfficiency();

    //FpixelPlot();
    //PseudoMET_vs_PFMET();
    //DrawPseudoMET(true); DrawPseudoMET(false);
    //nPV();
    //nHSCP();

    //ExtractSF ("TriggerEff_Mu2024_WMuNu_PseudoMETrescaled", "CalibPseudoMET_MuWay", "CalibPseudoMET_MuWay_isRescaled", "../output/Mu2024_V18/Mu2024_V18.root", "../output/Wjets2024_V14/WjetMuNu2024_V14p8_weighted.root");
    //ExtractSF ("TriggerEff_Mu2024_WMuNu_PseudoMET", "CalibPseudoMET_MuWay", "CalibPseudoMET_MuWay", "../output/Mu2024_V18/Mu2024_V18.root", "../output/Wjets2024_V14/WjetMuNu2024_V14p8_weighted.root");
    //ExtractSF ("TriggerEff_MuonEG2024_TTbar_PseudoMETrescaled", "CalibPseudoMET", "CalibPseudoMET_isRescaled", "../output/MuonEG_V17/MuonEG2024_V17p4.root", "../output/TTbar2024_V15/TTbar2024_V15p8.root");
    //PostTriggerPseudoMET();
    //PlotSF();

    //MyClusters();
    //CompareKinematics();


    // Run2_vs_Run3_gluino__TriggerEff();
    // ComparePseudoMET(true); ComparePseudoMET(false);
    // YieldAfterSF(true, true, false, false); YieldAfterSF(false, true, false, false); // HLT Mu + HSCP selections; rescaled and not rescaled
    // YieldAfterSF(true, false, true, false); YieldAfterSF(false, false, true, false); // HLT MET + HSCP selections; rescaled and not rescaled
    // YieldAfterSF(true, false, false, true); YieldAfterSF(false, false, false, true); // HLT MuonEG + HSCP selections; rescaled and not rescaled
    // TableGluino(true); TableGluino(false);

    //LangausFitOnIh();

    //FpixSlices();
    //Ihand1oP_fits();
    //DefineIhCut();


    return;
}