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

// Same but for matching D -> reweighting = B*C/A
void etaReweighingP(TH2F* nabla_eta_C, const TH1F* eta_B_, const TH1F* eta_A_)
{
    TH1F* eta_B = (TH1F*) eta_B_->Clone();
    TH1F* eta_A = (TH1F*) eta_A_->Clone();
    eta_B->Scale(1./eta_B->Integral(0,eta_B->GetNbinsX()+1));
    eta_A->Scale(1./eta_A->Integral(0,eta_A->GetNbinsX()+1));
    eta_B->Divide(eta_A);

    for(int i=0; i<nabla_eta_C->GetNbinsY()+2; i++)  // nabla bins 
    {
        for(int j=0; j<nabla_eta_C->GetNbinsX()+2; j++)  // eta bins
        {
            nabla_eta_C->SetBinContent(j, i, nabla_eta_C->GetBinContent(j,i)*eta_B->GetBinContent(j));
            nabla_eta_C->SetBinError(j, i, nabla_eta_C->GetBinError(j,i)*eta_B->GetBinContent(j));
        }
    }
}

// Switch X and Y axis
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

// Switch TH2(pT,eta) to TH2(p,eta)
TH2F* Transform_pT_eta_to_p_eta_fixed_pT_binning(const TH2F* h_pT_eta, const char* new_name = "h_p_eta") {
    const int n_pT = h_pT_eta->GetNbinsX();
    const int n_eta = h_pT_eta->GetNbinsY();

    const TAxis* ax_pT  = h_pT_eta->GetXaxis(); // pT axis
    const TAxis* ax_eta = h_pT_eta->GetYaxis(); // eta axis


    std::vector<double> xbins;
    double xmin = ax_pT->GetXmin();
    double xmax = ax_pT->GetXmax();
    for (int i = 0; i <= n_pT; ++i) xbins.push_back(xmin + i * (xmax - xmin) / n_pT);
    std::vector<double> ybins;
    double ymin = ax_eta->GetXmin();
    double ymax = ax_eta->GetXmax();
    for (int i = 0; i <= n_eta; ++i) ybins.push_back(ymin + i * (ymax - ymin) / n_eta);


    TH2F* h_p_eta = new TH2F(
        new_name,
        Form("%s mapped to p = pT * cosh(eta)", h_pT_eta->GetName()),
        n_pT, xbins.data(),
        n_eta, ybins.data()
    );

    for (int i = 1; i <= n_pT; ++i) {
        double pT = ax_pT->GetBinCenter(i);
        for (int j = 1; j <= n_eta; ++j) {
            double eta = ax_eta->GetBinCenter(j);
            double p = pT * std::cosh(eta);

            double content = h_pT_eta->GetBinContent(i, j);
            double error = h_pT_eta->GetBinError(i, j);

            int binx = h_p_eta->GetXaxis()->FindBin(p);
            int biny = h_p_eta->GetYaxis()->FindBin(eta);

            // Somme et erreur quadratique
            double prev = h_p_eta->GetBinContent(binx, biny);
            double prev_err = h_p_eta->GetBinError(binx, biny);

            h_p_eta->SetBinContent(binx, biny, prev + content);
            h_p_eta->SetBinError(binx, biny, std::sqrt(prev_err*prev_err + error*error));
        }
    }

    return h_p_eta;
}


void CompareDist_CandD(std::string ext)
{
    TFile *ofile = new TFile(Form("PlayWithHistos/CompareDist_CandD_%s.root", ext.c_str()),"RECREATE");
    
    TFile *ifile = new TFile("MET_2017_2018_massCut_0_pT70_V3p3_Fpix_Eta2p4.root");
    TH2F *C_fpix_eta = (TH2F*)ifile->Get(Form("fpix_eta_regionC_3fp8_%s", ext.c_str()));
    TH2F *C_1oP_eta = (TH2F*)ifile->Get(Form("eta_p_regionC_3fp8_%s", ext.c_str()));
    TH2F *C_pT_eta = (TH2F*)ifile->Get(Form("eta_pt_regionC_3fp8_%s", ext.c_str()));
    TH2F *C_eta_ih = (TH2F*)ifile->Get(Form("ih_eta_regionC_3fp8_%s", ext.c_str()));
    TH2F *D_fpix_eta = (TH2F*)ifile->Get(Form("fpix_eta_regionD_8fp9_%s", ext.c_str()));
    TH2F *D_1oP_eta = (TH2F*)ifile->Get(Form("eta_p_regionD_8fp9_%s", ext.c_str()));
    TH2F *D_pT_eta = (TH2F*)ifile->Get(Form("eta_pt_regionD_8fp9_%s", ext.c_str()));
    TH2F *D_eta_ih = (TH2F*)ifile->Get(Form("ih_eta_regionD_8fp9_%s", ext.c_str()));

    TH2F *A_eta_ih = (TH2F*)ifile->Get(Form("ih_eta_regionA_3fp8_%s", ext.c_str()));
    TH2F *B_eta_ih = (TH2F*)ifile->Get(Form("ih_eta_regionB_3fp8_%s", ext.c_str()));
    TH1F *a_eta = (TH1F*)A_eta_ih->ProjectionX();
    TH1F *b_eta = (TH1F*)B_eta_ih->ProjectionX();


    // Reweighting en eta
    etaReweighingP(C_eta_ih, b_eta, a_eta);

    TH2F* C_eta_1oP = TransposeTH2(C_1oP_eta);
    etaReweighingP(C_eta_1oP, b_eta, a_eta);

    TH2F* C_eta_fpix = TransposeTH2(C_fpix_eta);
    etaReweighingP(C_eta_fpix, b_eta, a_eta);

    TH2F* C_p_eta = Transform_pT_eta_to_p_eta_fixed_pT_binning(C_pT_eta, "h_p_eta_C");
    TH2F* C_eta_p = TransposeTH2(C_p_eta);
    etaReweighingP(C_eta_p, b_eta, a_eta);

    TH2F* D_p_eta = Transform_pT_eta_to_p_eta_fixed_pT_binning(D_pT_eta, "h_p_eta_D");

    // Save
    ofile->cd();
    C_eta_ih->ProjectionY()->Write("C_ih");
    C_eta_1oP->ProjectionY()->Write("C_1oP");
    C_eta_fpix->ProjectionY()->Write("C_fpix");
    C_eta_p->ProjectionY()->Write("C_p");
    D_eta_ih->ProjectionY()->Write("D_ih");
    D_1oP_eta->ProjectionX()->Write("D_1oP");
    D_fpix_eta->ProjectionX()->Write("D_fpix");
    D_p_eta->ProjectionX()->Write("D_p");
    ofile->Close();

    return;
}


TGraph* ConvertToGraph(TH1* histo)
{
    int nbins = histo->GetNbinsX();
    TGraph* graph = new TGraph(nbins);

    for (int i = 1; i <= nbins; ++i) {
        double x = histo->GetBinCenter(i);
        double y = histo->GetBinContent(i);
        graph->SetPoint(i - 1, x, y);
    }

    return graph;
}

TH1F* pullOfHisto(const TH1F* data, const TH1F* pred)
{
    TH1F* res = (TH1F*)pred->Clone();
    int nBins = pred->GetNbinsX();
    
    for (int i = 1; i <= nBins; ++i)
    {
        double Perr = 0;
        double P = pred->GetBinContent(i);
        double D = data->GetBinContent(i);

        Perr = pred->GetBinError(i);

        // Calcul du pull
        double pull = 0.0;
        if (P + Perr * Perr > 0) pull = (D - P) / sqrt(P + Perr * Perr);
        if (D == 0) pull = 0;

        res->SetBinContent(i, pull);
    }

    double xbins[] = {0,20,40,60,80,100,120,140,160,180,200,220,240,260,280,300,320,340,360,380,410,440,480,530,590,660,760,880,1030,1210,1440,1730,2000,2500,3200,4000};
    int nb = 35;

    res->Rebin(nb, "pull", xbins);

    return res;
}

TCanvas* DrawCanvas(TH1F* h1, TH1F* h2, TH1F* h3, TH1F* h4, TH1F *obs, const char *name)
{
    TCanvas *c1 = new TCanvas("c1","c1",800,800);
    c1->cd();

    //First pad: drawing the histos
    TPad *pad1 = new TPad("pad1","pad1",0,0.3,1,1);
    pad1->SetBottomMargin(0);
    pad1->Draw();
    pad1->cd();

    TGraph *graph1 = ConvertToGraph(h1);
    graph1->SetLineColor(kOrange+7);
    graph1->SetLineWidth(2);
    graph1->SetLineStyle(10);
    TGraph *graph2 = ConvertToGraph(h2);
    graph2->SetLineColor(kAzure+7);
    graph2->SetLineWidth(2);
    graph2->SetLineStyle(10);
    TGraph *graph3 = ConvertToGraph(h3);
    graph3->SetLineColor(kGreen+2);
    TGraph *graph4 = ConvertToGraph(h4);
    graph4->SetLineColor(kMagenta+1);

    obs->SetLineColor(kBlack);
    obs->SetMarkerColor(kBlack);
    obs->SetMarkerStyle(20);
    obs->GetXaxis()->SetRangeUser(0, 4000);
    obs->GetYaxis()->SetRangeUser(1e-4, 5e6);

    obs->Draw("E1");
    graph1->Draw("same L");
    graph2->Draw("same L");
    graph3->Draw("same L");
    graph4->Draw("same L");
    obs->Draw("same E1");
    gStyle->SetOptStat(0);

    TLegend *leg = new TLegend(0.5,0.55,0.7,0.75);
    leg->SetHeader(name,"C");
    leg->SetTextSize(0.03);
    leg->AddEntry(obs,"Observed","lep");
    leg->AddEntry(graph1,"No I_{h} Fit","l");
    leg->AddEntry(graph2,"No 1/p Fit","l");
    leg->AddEntry(graph3,"No I_{h} and no 1/p Fit","l");
    leg->AddEntry(graph4,"I_{h} and 1/p Fit","l");
    leg->SetBorderSize(0);
    leg->Draw();

    pad1->SetLogy();
    pad1->SetTickx(1);
    pad1->SetTicky(1);


    //Second pad: drawing the pull
    c1->cd();
    TPad *pad2 = new TPad("pad2","pad2",0,0,1,0.3);
    pad2->SetTopMargin(0);
    pad2->SetBottomMargin(0.3);
    pad2->Draw();
    pad2->cd();

    TH1F* pull1 = pullOfHisto(obs, h1);
    TH1F* pull2 = pullOfHisto(obs, h2);
    TH1F* pull3 = pullOfHisto(obs, h3);
    TH1F* pull4 = pullOfHisto(obs, h4);
    pull1->SetFillColor(kOrange+7);
    pull2->SetFillColor(kAzure+7);
    pull1->SetFillStyle(4050);
    pull2->SetFillStyle(4050);
    pull1->SetMarkerColor(kOrange+7);
    pull1->SetLineColor(kOrange+7);
    pull1->SetMarkerStyle(5);
    pull2->SetMarkerColor(kAzure+7);
    pull2->SetLineColor(kAzure+7);
    pull2->SetMarkerStyle(5);
    pull3->SetMarkerColor(kGreen+2);
    pull3->SetLineColor(kGreen+2);
    pull3->SetMarkerStyle(4);
    pull4->SetMarkerColor(kMagenta+1);
    pull4->SetLineColor(kMagenta+1);
    pull4->SetMarkerStyle(4);
    pull2->Draw("hist ");
    pull1->Draw("same hist ");
    pull3->Draw("same hist ");
    pull4->Draw("same hist ");
    pull2->GetYaxis()->SetRangeUser(-3, 3);
    pull2->GetXaxis()->SetTitleSize(0.1);
    pull2->GetXaxis()->SetLabelSize(0.05);
    pull2->GetYaxis()->SetLabelSize(0.05);
    
    TLine *line0 = new TLine(0, 0, 4000, 0);
    line0->SetLineStyle(1);
    line0->Draw("same");
    TLine *line1 = new TLine(0, 1.0, 4000, 1.0);
    line1->SetLineStyle(2);
    line1->Draw("same");
    TLine *linem1 = new TLine(0, -1.0, 4000, -1.0);
    linem1->SetLineStyle(2);
    linem1->Draw("same");
    TLine *line2 = new TLine(0, 2.0, 4000, 2.0);
    line2->SetLineStyle(2);
    line2->Draw("same");
    TLine *linem2 = new TLine(0, -2.0, 4000, -2.0);
    linem2->SetLineStyle(2);
    linem2->Draw("same");

    TLatex *text = new TLatex();
    text->SetTextSize(0.08);
    text->SetTextAngle(90);
    text->SetTextAlign(22);
    text->DrawLatex(-200, 0.5, "#frac{Data-pred}{#sigma}");

    c1->Update();

    return c1;
}

TCanvas* DrawCanvas(TH1F* h1, TH1F* h2, TH1F* h3, TH1F* h4, TH1F* hC, TH1F *obs, const char *name)
{
    TCanvas *c1 = new TCanvas("c1","c1",800,800);
    c1->cd();

    //First pad: drawing the histos
    TPad *pad1 = new TPad("pad1","pad1",0,0.3,1,1);
    pad1->SetBottomMargin(0);
    pad1->Draw();
    pad1->cd();

    TGraph *graph1 = ConvertToGraph(h1);
    graph1->SetLineColor(kOrange+7);
    graph1->SetLineWidth(2);
    graph1->SetLineStyle(10);
    TGraph *graph2 = ConvertToGraph(h2);
    graph2->SetLineColor(kAzure+7);
    graph2->SetLineWidth(2);
    graph2->SetLineStyle(10);
    TGraph *graph3 = ConvertToGraph(h3);
    graph3->SetLineColor(kGreen+2);
    TGraph *graph4 = ConvertToGraph(h4);
    graph4->SetLineColor(kMagenta+1);

    obs->SetLineColor(kBlack);
    obs->SetMarkerColor(kBlack);
    obs->SetMarkerStyle(20);
    obs->GetXaxis()->SetRangeUser(0, 4000);
    obs->GetYaxis()->SetRangeUser(1e-4, 5e6);

    hC->SetLineColor(8);
    hC->SetMarkerColor(8);
    hC->SetMarkerStyle(23);

    obs->Draw("E1");
    hC->Draw("same E1");
    graph1->Draw("same L");
    graph2->Draw("same L");
    graph3->Draw("same L");
    graph4->Draw("same L");
    obs->Draw("same E1");
    gStyle->SetOptStat(0);

    TLegend *leg = new TLegend(0.5,0.55,0.7,0.75);
    leg->SetHeader(name,"C");
    leg->SetTextSize(0.03);
    leg->AddEntry(obs,"Observed","lep");
    leg->AddEntry(hC,"Observed in C","lep");
    leg->AddEntry(graph1,"No I_{h} Fit","l");
    leg->AddEntry(graph2,"No 1/p Fit","l");
    leg->AddEntry(graph3,"No I_{h} and 1/p Fit","l");
    leg->AddEntry(graph4,"I_{h} and 1/p Fit","l");
    leg->SetBorderSize(0);
    leg->Draw();

    pad1->SetLogy();
    pad1->SetTickx(1);
    pad1->SetTicky(1);


    //Second pad: drawing the pull
    c1->cd();
    TPad *pad2 = new TPad("pad2","pad2",0,0,1,0.3);
    pad2->SetTopMargin(0);
    pad2->SetBottomMargin(0.3);
    pad2->Draw();
    pad2->cd();

    TH1F* pull1 = pullOfHisto(obs, h1);
    TH1F* pull2 = pullOfHisto(obs, h2);
    TH1F* pull3 = pullOfHisto(obs, h3);
    TH1F* pull4 = pullOfHisto(obs, h4);
    pull1->SetFillColor(kOrange+7);
    pull2->SetFillColor(kAzure+7);
    pull1->SetFillStyle(4050);
    pull2->SetFillStyle(4050);
    pull1->SetMarkerColor(kOrange+7);
    pull1->SetLineColor(kOrange+7);
    pull1->SetMarkerStyle(5);
    pull2->SetMarkerColor(kAzure+7);
    pull2->SetLineColor(kAzure+7);
    pull2->SetMarkerStyle(5);
    pull3->SetMarkerColor(kGreen+2);
    pull3->SetLineColor(kGreen+2);
    pull3->SetMarkerStyle(4);
    pull4->SetMarkerColor(kMagenta+1);
    pull4->SetLineColor(kMagenta+1);
    pull4->SetMarkerStyle(4);
    pull2->Draw("hist ");
    pull1->Draw("same hist ");
    pull3->Draw("same hist ");
    pull4->Draw("same hist ");
    pull2->GetYaxis()->SetRangeUser(-3, 3);
    pull2->GetXaxis()->SetTitleSize(0.1);
    pull2->GetXaxis()->SetLabelSize(0.05);
    pull2->GetYaxis()->SetLabelSize(0.05);
    
    TLine *line0 = new TLine(0, 0, 4000, 0);
    line0->SetLineStyle(1);
    line0->Draw("same");
    TLine *line1 = new TLine(0, 1.0, 4000, 1.0);
    line1->SetLineStyle(2);
    line1->Draw("same");
    TLine *linem1 = new TLine(0, -1.0, 4000, -1.0);
    linem1->SetLineStyle(2);
    linem1->Draw("same");
    TLine *line2 = new TLine(0, 2.0, 4000, 2.0);
    line2->SetLineStyle(2);
    line2->Draw("same");
    TLine *linem2 = new TLine(0, -2.0, 4000, -2.0);
    linem2->SetLineStyle(2);
    linem2->Draw("same");

    TLatex *text = new TLatex();
    text->SetTextSize(0.08);
    text->SetTextAngle(90);
    text->SetTextAlign(22);
    text->DrawLatex(-200, 0.5, "#frac{Data-pred}{#sigma}");

    c1->Update();

    return c1;
}

TCanvas* DrawCanvas(TH1F* h3, TH1F* h4, TH1F* h5, TH1F* hC, TH1F *obs, const char *name, bool blouki)
{
    TCanvas *c1 = new TCanvas("c1","c1",800,800);
    c1->cd();

    //First pad: drawing the histos
    TPad *pad1 = new TPad("pad1","pad1",0,0.3,1,1);
    pad1->SetBottomMargin(0);
    pad1->Draw();
    pad1->cd();

    TGraph *graph3 = ConvertToGraph(h3);
    graph3->SetLineColor(kGreen+2);
    TGraph *graph4 = ConvertToGraph(h4);
    graph4->SetLineColor(kMagenta+1);
    TGraph *graph5 = ConvertToGraph(h5);
    graph5->SetLineColor(kRed);
    graph5->SetLineStyle(7);

    obs->SetLineColor(kBlack);
    obs->SetMarkerColor(kBlack);
    obs->SetMarkerStyle(20);
    obs->GetXaxis()->SetRangeUser(0, 4000);
    obs->GetYaxis()->SetRangeUser(1e-4, 5e6);

    hC->SetLineColor(8);
    hC->SetMarkerColor(8);
    hC->SetMarkerStyle(23);

    obs->Draw("E1");
    hC->Draw("same E1");
    graph3->Draw("same L");
    graph4->Draw("same L");
    graph5->Draw("same L");
    obs->Draw("same E1");
    gStyle->SetOptStat(0);

    TLegend *leg = new TLegend(0.5,0.55,0.7,0.75);
    leg->SetHeader(name,"C");
    leg->SetTextSize(0.03);
    leg->AddEntry(obs,"Observed","lep");
    leg->AddEntry(hC,"Observed in C","lep");
    leg->AddEntry(graph3,"No I_{h} and 1/p Fit","l");
    leg->AddEntry(graph4,"Old I_{h} and old 1/p Fit","l");
    leg->AddEntry(graph5,"New I_{h} and new 1/p Fit","l");
    leg->SetBorderSize(0);
    leg->Draw();

    pad1->SetLogy();
    pad1->SetTickx(1);
    pad1->SetTicky(1);


    //Second pad: drawing the pull
    c1->cd();
    TPad *pad2 = new TPad("pad2","pad2",0,0,1,0.3);
    pad2->SetTopMargin(0);
    pad2->SetBottomMargin(0.3);
    pad2->Draw();
    pad2->cd();

    TH1F* pull3 = pullOfHisto(obs, h3);
    TH1F* pull4 = pullOfHisto(obs, h4);
    TH1F* pull5 = pullOfHisto(obs, h5);
    pull3->SetLineColor(kGreen+2);
    pull4->SetLineColor(kMagenta+1);
    pull5->SetLineColor(kRed);
    pull5->SetFillStyle(4050);
    pull5->SetFillColor(kRed);
    pull3->Draw("hist");
    pull4->Draw("same hist");
    pull5->Draw("same hist");
    pull3->GetYaxis()->SetRangeUser(-3, 3);
    pull3->GetXaxis()->SetTitleSize(0.1);
    pull3->GetXaxis()->SetLabelSize(0.05);
    pull3->GetYaxis()->SetLabelSize(0.05);
    
    TLine *line0 = new TLine(0, 0, 4000, 0);
    line0->SetLineStyle(1);
    line0->Draw("same");
    TLine *line1 = new TLine(0, 1.0, 4000, 1.0);
    line1->SetLineStyle(2);
    line1->Draw("same");
    TLine *linem1 = new TLine(0, -1.0, 4000, -1.0);
    linem1->SetLineStyle(2);
    linem1->Draw("same");
    TLine *line2 = new TLine(0, 2.0, 4000, 2.0);
    line2->SetLineStyle(2);
    line2->Draw("same");
    TLine *linem2 = new TLine(0, -2.0, 4000, -2.0);
    linem2->SetLineStyle(2);
    linem2->Draw("same");

    TLatex *text = new TLatex();
    text->SetTextSize(0.08);
    text->SetTextAngle(90);
    text->SetTextAlign(22);
    text->DrawLatex(-200, 0.5, "#frac{Data-pred}{#sigma}");

    c1->Update();

    return c1;
}

TCanvas* DrawCanvas(TH1F* h3, TH1F* h4, TH1F* h5, TH1F *obs, const char *name)
{
    TCanvas *c1 = new TCanvas("c1","c1",800,800);
    c1->cd();

    //First pad: drawing the histos
    TPad *pad1 = new TPad("pad1","pad1",0,0.3,1,1);
    pad1->SetBottomMargin(0);
    pad1->Draw();
    pad1->cd();

    TGraph *graph3 = ConvertToGraph(h3);
    graph3->SetLineColor(kGreen+2);
    TGraph *graph4 = ConvertToGraph(h4);
    graph4->SetLineColor(kMagenta+1);
    TGraph *graph5 = ConvertToGraph(h5);
    graph5->SetLineColor(kRed);
    graph5->SetLineStyle(7);

    obs->SetLineColor(kBlack);
    obs->SetMarkerColor(kBlack);
    obs->SetMarkerStyle(20);
    obs->GetXaxis()->SetRangeUser(0, 4000);
    obs->GetYaxis()->SetRangeUser(1e-4, 5e6);

    obs->Draw("E1");
    graph3->Draw("same L");
    graph4->Draw("same L");
    graph5->Draw("same L");
    obs->Draw("same E1");
    gStyle->SetOptStat(0);

    TLegend *leg = new TLegend(0.5,0.55,0.7,0.75);
    leg->SetHeader(name,"C");
    leg->SetTextSize(0.03);
    leg->AddEntry(obs,"Observed","lep");
    leg->AddEntry(graph3,"No I_{h} and 1/p Fit","l");
    leg->AddEntry(graph4,"Old I_{h} and old 1/p Fit","l");
    leg->AddEntry(graph5,"New I_{h} and new 1/p Fit","l");
    leg->SetBorderSize(0);
    leg->Draw();

    pad1->SetLogy();
    pad1->SetTickx(1);
    pad1->SetTicky(1);


    //Second pad: drawing the pull
    c1->cd();
    TPad *pad2 = new TPad("pad2","pad2",0,0,1,0.3);
    pad2->SetTopMargin(0);
    pad2->SetBottomMargin(0.3);
    pad2->Draw();
    pad2->cd();

    TH1F* pull3 = pullOfHisto(obs, h3);
    TH1F* pull4 = pullOfHisto(obs, h4);
    TH1F* pull5 = pullOfHisto(obs, h5);
    pull3->SetLineColor(kGreen+2);
    pull4->SetLineColor(kMagenta+1);
    pull5->SetLineColor(kRed);
    pull5->SetFillStyle(4050);
    pull5->SetFillColor(kRed);
    pull3->Draw("hist");
    pull4->Draw("same hist");
    pull5->Draw("same hist");
    pull3->GetYaxis()->SetRangeUser(-3, 3);
    pull3->GetXaxis()->SetTitleSize(0.1);
    pull3->GetXaxis()->SetLabelSize(0.05);
    pull3->GetYaxis()->SetLabelSize(0.05);
    
    TLine *line0 = new TLine(0, 0, 4000, 0);
    line0->SetLineStyle(1);
    line0->Draw("same");
    TLine *line1 = new TLine(0, 1.0, 4000, 1.0);
    line1->SetLineStyle(2);
    line1->Draw("same");
    TLine *linem1 = new TLine(0, -1.0, 4000, -1.0);
    linem1->SetLineStyle(2);
    linem1->Draw("same");
    TLine *line2 = new TLine(0, 2.0, 4000, 2.0);
    line2->SetLineStyle(2);
    line2->Draw("same");
    TLine *linem2 = new TLine(0, -2.0, 4000, -2.0);
    linem2->SetLineStyle(2);
    linem2->Draw("same");

    TLatex *text = new TLatex();
    text->SetTextSize(0.08);
    text->SetTextAngle(90);
    text->SetTextAlign(22);
    text->DrawLatex(-200, 0.5, "#frac{Data-pred}{#sigma}");

    c1->Update();

    return c1;
}

void PlotPredFits()
{
    double xbins[] = {0,20,40,60,80,100,120,140,160,180,200,220,240,260,280,300,320,340,360,380,410,440,480,530,590,660,760,880,1030,1210,1440,1730,2000,2500,3200,4000};
    int nBins = 35;
    
    // Fpix D_8fp9 mass prediction
    TFile *Fpix_noIhFit_Eta1 = new TFile("Fpix_noIhFit_V2p12/Plots_Fpix_Eta1/pred.root");
    TH1F *Fpred_noIhFit_Eta1 = (TH1F*)Fpix_noIhFit_Eta1->Get("pred_new");
    TFile *F0pix_noIhFit_Eta1 = new TFile("Fpix_noIhFit_V2p12/Plots_Fpix_Eta1/obs.root");
    TH1F *Fobs_noIhFit_Eta1 = (TH1F*)F0pix_noIhFit_Eta1->Get("obs_new");
    TFile *Fpix_noIhFit_Eta1_2p4 = new TFile("Fpix_noIhFit_V2p12/Plots_Fpix_Eta1_2p4/pred.root");
    TH1F *Fpred_noIhFit_Eta1_2p4 = (TH1F*)Fpix_noIhFit_Eta1_2p4->Get("pred_new");
    TFile *F0pix_noIhFit_Eta1_2p4 = new TFile("Fpix_noIhFit_V2p12/Plots_Fpix_Eta1_2p4/obs.root");
    TH1F *Fobs_noIhFit_Eta1_2p4 = (TH1F*)F0pix_noIhFit_Eta1_2p4->Get("obs_new");
    TFile *Fpix_noIhFit_Eta2p4 = new TFile("Fpix_noIhFit_V2p12/Plots_Fpix_Eta2p4/pred.root");
    TH1F *Fpred_noIhFit_Eta2p4 = (TH1F*)Fpix_noIhFit_Eta2p4->Get("pred_new");
    TFile *F0pix_noIhFit_Eta2p4 = new TFile("Fpix_noIhFit_V2p12/Plots_Fpix_Eta2p4/obs.root");
    TH1F *Fobs_noIhFit_Eta2p4 = (TH1F*)F0pix_noIhFit_Eta2p4->Get("obs_new");
    
    TFile *Fpix_noPFit_Eta1 = new TFile("Fpix_noPFit_V2p12/Plots_Fpix_Eta1/pred.root");
    TH1F *Fpred_noPFit_Eta1 = (TH1F*)Fpix_noPFit_Eta1->Get("pred_new");
    TFile *F0pix_noPFit_Eta1 = new TFile("Fpix_noPFit_V2p12/Plots_Fpix_Eta1/obs.root");
    TH1F *Fobs_noPFit_Eta1 = (TH1F*)F0pix_noPFit_Eta1->Get("obs_new");
    TFile *Fpix_noPFit_Eta1_2p4 = new TFile("Fpix_noPFit_V2p12/Plots_Fpix_Eta1_2p4/pred.root");
    TH1F *Fpred_noPFit_Eta1_2p4 = (TH1F*)Fpix_noPFit_Eta1_2p4->Get("pred_new");
    TFile *F0pix_noPFit_Eta1_2p4 = new TFile("Fpix_noPFit_V2p12/Plots_Fpix_Eta1_2p4/obs.root");
    TH1F *Fobs_noPFit_Eta1_2p4 = (TH1F*)F0pix_noPFit_Eta1_2p4->Get("obs_new");
    TFile *Fpix_noPFit_Eta2p4 = new TFile("Fpix_noPFit_V2p12/Plots_Fpix_Eta2p4/pred.root");
    TH1F *Fpred_noPFit_Eta2p4 = (TH1F*)Fpix_noPFit_Eta2p4->Get("pred_new");
    TFile *F0pix_noPFit_Eta2p4 = new TFile("Fpix_noPFit_V2p12/Plots_Fpix_Eta2p4/obs.root");
    TH1F *Fobs_noPFit_Eta2p4 = (TH1F*)F0pix_noPFit_Eta2p4->Get("obs_new");
    
    TFile *Fpix_noIhFit_noPFit_Eta1 = new TFile("Fpix_noIhFit_noPFit_V2p12/Plots_Fpix_Eta1/pred.root");
    TH1F *Fpred_noIhFit_noPFit_Eta1 = (TH1F*)Fpix_noIhFit_noPFit_Eta1->Get("pred_new");
    TFile *F0pix_noIhFit_noPFit_Eta1 = new TFile("Fpix_noIhFit_noPFit_V2p12/Plots_Fpix_Eta1/obs.root");
    TH1F *Fobs_noIhFit_noPFit_Eta1 = (TH1F*)F0pix_noIhFit_noPFit_Eta1->Get("obs_new");
    TFile *Fpix_noIhFit_noPFit_Eta1_2p4 = new TFile("Fpix_noIhFit_noPFit_V2p12/Plots_Fpix_Eta1_2p4/pred.root");
    TH1F *Fpred_noIhFit_noPFit_Eta1_2p4 = (TH1F*)Fpix_noIhFit_noPFit_Eta1_2p4->Get("pred_new");
    TFile *F0pix_noIhFit_noPFit_Eta1_2p4 = new TFile("Fpix_noIhFit_noPFit_V2p12/Plots_Fpix_Eta1_2p4/obs.root");
    TH1F *Fobs_noIhFit_noPFit_Eta1_2p4 = (TH1F*)F0pix_noIhFit_noPFit_Eta1_2p4->Get("obs_new");
    TFile *Fpix_noIhFit_noPFit_Eta2p4 = new TFile("Fpix_noIhFit_noPFit_V2p12/Plots_Fpix_Eta2p4/pred.root");
    TH1F *Fpred_noIhFit_noPFit_Eta2p4 = (TH1F*)Fpix_noIhFit_noPFit_Eta2p4->Get("pred_new");
    TFile *F0pix_noIhFit_noPFit_Eta2p4 = new TFile("Fpix_noIhFit_noPFit_V2p12/Plots_Fpix_Eta2p4/obs.root");
    TH1F *Fobs_noIhFit_noPFit_Eta2p4 = (TH1F*)F0pix_noIhFit_noPFit_Eta2p4->Get("obs_new");
    
    TFile *Fpix_Eta1 = new TFile("Fpix_V2p12/Plots_Fpix_Eta1/pred.root");
    TH1F *Fpred_Eta1 = (TH1F*)Fpix_Eta1->Get("pred_new");
    TFile *FOpix_Eta1 = new TFile("Fpix_V2p12/Plots_Fpix_Eta1/obs.root");
    TH1F *Fobs_Eta1 = (TH1F*)FOpix_Eta1->Get("obs_new");
    TFile *FCpix_Eta1 = new TFile("Fpix_V2p12/Mu2018_massCut_0_pT70_V2p12_Fpix_Eta1_cutIndex3_rebinEta4_rebinIh4_rebinP2_rebinMass1.root");
    TH1F *FC_Eta1 = (TH1F*)FCpix_Eta1->Get("mass_regionC_3fp8_ReRunRaph");
    TH1F* FC_Eta1_new = (TH1F*)FC_Eta1->Rebin(nBins, "FC_Eta1_new", xbins);
    TFile *Fpix_Eta1_2p4 = new TFile("Fpix_V2p12/Plots_Fpix_Eta1_2p4/pred.root");
    TH1F *Fpred_Eta1_2p4 = (TH1F*)Fpix_Eta1_2p4->Get("pred_new");
    TFile *FOpix_Eta1_2p4 = new TFile("Fpix_V2p12/Plots_Fpix_Eta1_2p4/obs.root");
    TH1F *Fobs_Eta1_2p4 = (TH1F*)FOpix_Eta1_2p4->Get("obs_new");
    TFile *FCpix_Eta1_2p4 = new TFile("Fpix_V2p12/Mu2018_massCut_0_pT70_V2p12_Fpix_Eta1_2p4_cutIndex3_rebinEta4_rebinIh4_rebinP2_rebinMass1.root");
    TH1F *FC_Eta1_2p4 = (TH1F*)FCpix_Eta1_2p4->Get("mass_regionC_3fp8_ReRunRaph");
    TH1F* FC_Eta1_2p4_new = (TH1F*)FC_Eta1_2p4->Rebin(nBins, "FC_Eta1_2p4_new", xbins);
    TFile *Fpix_Eta2p4 = new TFile("Fpix_V2p12/Plots_Fpix_Eta2p4/pred.root");
    TH1F *Fpred_Eta2p4 = (TH1F*)Fpix_Eta2p4->Get("pred_new");
    TFile *FOpix_Eta2p4 = new TFile("Fpix_V2p12/Plots_Fpix_Eta2p4/obs.root");
    TH1F *Fobs_Eta2p4 = (TH1F*)FOpix_Eta2p4->Get("obs_new");
    TFile *FCpix_Eta2p4 = new TFile("Fpix_V2p12/Mu2018_massCut_0_pT70_V2p12_Fpix_Eta2p4_cutIndex3_rebinEta4_rebinIh4_rebinP2_rebinMass1.root");
    TH1F *FC_Eta2p4 = (TH1F*)FCpix_Eta2p4->Get("mass_regionC_3fp8_ReRunRaph");
    TH1F* FC_Eta2p4_new = (TH1F*)FC_Eta2p4->Rebin(nBins, "FC_Eta2p4_new", xbins);
    TFile *Fpix_Eta2p4_newfit = new TFile("Fpix_V2p14/Plots_Fpix_Eta2p4_coshFit_expFit/pred.root");
    TH1F *F_Eta2p4_newfit = (TH1F*)Fpix_Eta2p4_newfit->Get("pred_new");
    


    // ----------------------------------------------------------------------------------------------


    // Gstrip D_80ias90 mass prediction
    TFile *Gstrip_noIhFit_Eta1 = new TFile("Gstrip_noIhFit_V2p12/Plots_Gstrip_Eta1/pred.root");
    TH1F *Gpred_noIhFit_Eta1 = (TH1F*)Gstrip_noIhFit_Eta1->Get("pred_new");
    TFile *GOstrip_noIhFit_Eta1 = new TFile("Gstrip_noIhFit_V2p12/Plots_Gstrip_Eta1/obs.root");
    TH1F *Gobs_noIhFit_Eta1 = (TH1F*)GOstrip_noIhFit_Eta1->Get("obs_new");
    TFile *Gstrip_noIhFit_Eta1_2p4 = new TFile("Gstrip_noIhFit_V2p12/Plots_Gstrip_Eta1_2p4/pred.root");
    TH1F *Gpred_noIhFit_Eta1_2p4 = (TH1F*)Gstrip_noIhFit_Eta1_2p4->Get("pred_new");
    TFile *GOstrip_noIhFit_Eta1_2p4 = new TFile("Gstrip_noIhFit_V2p12/Plots_Gstrip_Eta1_2p4/obs.root");
    TH1F *Gobs_noIhFit_Eta1_2p4 = (TH1F*)GOstrip_noIhFit_Eta1_2p4->Get("obs_new");
    TFile *Gstrip_noIhFit_Eta2p4 = new TFile("Gstrip_noIhFit_V2p12/Plots_Gstrip_Eta2p4/pred.root");
    TH1F *Gpred_noIhFit_Eta2p4 = (TH1F*)Gstrip_noIhFit_Eta2p4->Get("pred_new");
    TFile *GOstrip_noIhFit_Eta2p4 = new TFile("Gstrip_noIhFit_V2p12/Plots_Gstrip_Eta2p4/obs.root");
    TH1F *Gobs_noIhFit_Eta2p4 = (TH1F*)GOstrip_noIhFit_Eta2p4->Get("obs_new");

    TFile *Gstrip_noPFit_Eta1 = new TFile("Gstrip_noPFit_V2p12/Plots_Gstrip_Eta1/pred.root");
    TH1F *Gpred_noPFit_Eta1 = (TH1F*)Gstrip_noPFit_Eta1->Get("pred_new");
    TFile *GOstrip_noPFit_Eta1 = new TFile("Gstrip_noPFit_V2p12/Plots_Gstrip_Eta1/obs.root");
    TH1F *Gobs_noPFit_Eta1 = (TH1F*)GOstrip_noPFit_Eta1->Get("obs_new");
    TFile *Gstrip_noPFit_Eta1_2p4 = new TFile("Gstrip_noPFit_V2p12/Plots_Gstrip_Eta1_2p4/pred.root");
    TH1F *Gpred_noPFit_Eta1_2p4 = (TH1F*)Gstrip_noPFit_Eta1_2p4->Get("pred_new");
    TFile *GOstrip_noPFit_Eta1_2p4 = new TFile("Gstrip_noPFit_V2p12/Plots_Gstrip_Eta1_2p4/obs.root");
    TH1F *Gobs_noPFit_Eta1_2p4 = (TH1F*)GOstrip_noPFit_Eta1_2p4->Get("obs_new");
    TFile *Gstrip_noPFit_Eta2p4 = new TFile("Gstrip_noPFit_V2p12/Plots_Gstrip_Eta2p4/pred.root");
    TH1F *Gpred_noPFit_Eta2p4 = (TH1F*)Gstrip_noPFit_Eta2p4->Get("pred_new");
    TFile *GOstrip_noPFit_Eta2p4 = new TFile("Gstrip_noPFit_V2p12/Plots_Gstrip_Eta2p4/obs.root");
    TH1F *Gobs_noPFit_Eta2p4 = (TH1F*)GOstrip_noPFit_Eta2p4->Get("obs_new");

    TFile *Gstrip_noIhFit_noPFit_Eta1 = new TFile("Gstrip_noIhFit_noPFit_V2p12/Plots_Gstrip_Eta1/pred.root");
    TH1F *Gpred_noIhFit_noPFit_Eta1 = (TH1F*)Gstrip_noIhFit_noPFit_Eta1->Get("pred_new");
    TFile *GOstrip_noIhFit_noPFit_Eta1 = new TFile("Gstrip_noIhFit_noPFit_V2p12/Plots_Gstrip_Eta1/obs.root");
    TH1F *Gobs_noIhFit_noPFit_Eta1 = (TH1F*)GOstrip_noIhFit_noPFit_Eta1->Get("obs_new");
    TFile *Gstrip_noIhFit_noPFit_Eta1_2p4 = new TFile("Gstrip_noIhFit_noPFit_V2p12/Plots_Gstrip_Eta1_2p4/pred.root");
    TH1F *Gpred_noIhFit_noPFit_Eta1_2p4 = (TH1F*)Gstrip_noIhFit_noPFit_Eta1_2p4->Get("pred_new");
    TFile *GOstrip_noIhFit_noPFit_Eta1_2p4 = new TFile("Gstrip_noIhFit_noPFit_V2p12/Plots_Gstrip_Eta1_2p4/obs.root");
    TH1F *Gobs_noIhFit_noPFit_Eta1_2p4 = (TH1F*)GOstrip_noIhFit_noPFit_Eta1_2p4->Get("obs_new");
    TFile *Gstrip_noIhFit_noPFit_Eta2p4 = new TFile("Gstrip_noIhFit_noPFit_V2p12/Plots_Gstrip_Eta2p4/pred.root");
    TH1F *Gpred_noIhFit_noPFit_Eta2p4 = (TH1F*)Gstrip_noIhFit_noPFit_Eta2p4->Get("pred_new");
    TFile *GOstrip_noIhFit_noPFit_Eta2p4 = new TFile("Gstrip_noIhFit_noPFit_V2p12/Plots_Gstrip_Eta2p4/obs.root");
    TH1F *Gobs_noIhFit_noPFit_Eta2p4 = (TH1F*)GOstrip_noIhFit_noPFit_Eta2p4->Get("obs_new");

    TFile *Gstrip_Eta1 = new TFile("Gstrip_V2p12/Plots_Gstrip_Eta1/pred.root");
    TH1F *Gpred_Eta1 = (TH1F*)Gstrip_Eta1->Get("pred_new");
    TFile *GOstrip_Eta1 = new TFile("Gstrip_V2p12/Plots_Gstrip_Eta1/obs.root");
    TH1F *Gobs_Eta1 = (TH1F*)GOstrip_Eta1->Get("obs_new");
    TFile *Gstrip_Eta1_2p4 = new TFile("Gstrip_V2p12/Plots_Gstrip_Eta1_2p4/pred.root");
    TH1F *Gpred_Eta1_2p4 = (TH1F*)Gstrip_Eta1_2p4->Get("pred_new");
    TFile *GOstrip_Eta1_2p4 = new TFile("Gstrip_V2p12/Plots_Gstrip_Eta1_2p4/obs.root");
    TH1F *Gobs_Eta1_2p4 = (TH1F*)GOstrip_Eta1_2p4->Get("obs_new");
    TFile *Gstrip_Eta2p4 = new TFile("Gstrip_V2p12/Plots_Gstrip_Eta2p4/pred.root");
    TH1F *Gpred_Eta2p4 = (TH1F*)Gstrip_Eta2p4->Get("pred_new");
    TFile *GOstrip_Eta2p4 = new TFile("Gstrip_V2p12/Plots_Gstrip_Eta2p4/obs.root");
    TH1F *Gobs_Eta2p4 = (TH1F*)GOstrip_Eta2p4->Get("obs_new");
    TFile *Gstrip_Eta2p4_newfit = new TFile("Gstrip_V2p14/Plots_Gstrip_Eta2p4_coshFit_gaussFit/pred.root");
    TH1F *G_Eta2p4_newfit = (TH1F*)Gstrip_Eta2p4_newfit->Get("pred_new");


    // Drawing and saving part
    TFile *ofile = new TFile("PlayWithHistos/PlotPredFits.root","RECREATE");
    
    ofile->cd();

    TCanvas *Fc_Eta1 = DrawCanvas(Fpred_noIhFit_Eta1, Fpred_noPFit_Eta1, Fpred_noIhFit_noPFit_Eta1, Fpred_Eta1, FC_Eta1_new, Fobs_Eta1, "|#eta| < 1");
    Fc_Eta1->Write("Fpred_Eta1");
    cout << "Fpix Eta1 done" << endl;
    TCanvas *Fc_Eta1_2p4 = DrawCanvas(Fpred_noIhFit_Eta1_2p4, Fpred_noPFit_Eta1_2p4, Fpred_noIhFit_noPFit_Eta1_2p4, Fpred_Eta1_2p4, FC_Eta1_2p4_new, Fobs_Eta1_2p4, "1 < |#eta| < 2.4");
    Fc_Eta1_2p4->Write("Fpred_Eta1_2p4");
    cout << "Fpix Eta1_2p4 done" << endl;
    TCanvas *Fc_Eta2p4 = DrawCanvas(Fpred_noIhFit_Eta2p4, Fpred_noPFit_Eta2p4, Fpred_noIhFit_noPFit_Eta2p4, Fpred_Eta2p4, FC_Eta2p4_new, Fobs_Eta2p4, "|#eta| < 2.4");
    Fc_Eta2p4->Write("Fpred_Eta2p4");
    cout << "Fpix Eta2p4 done" << endl;
    TCanvas *Fc_Eta2p4New = DrawCanvas(Fpred_noIhFit_noPFit_Eta2p4, Fpred_Eta2p4, F_Eta2p4_newfit, FC_Eta2p4_new, Fobs_Eta2p4, "|#eta| < 2.4", false);
    Fc_Eta2p4New->Write("Fpred_Eta2p4New");
    cout << "Fpix Eta2p4New done" << endl;

    TCanvas *Gc_Eta1 = DrawCanvas(Gpred_noIhFit_Eta1, Gpred_noPFit_Eta1, Gpred_noIhFit_noPFit_Eta1, Gpred_Eta1, Gobs_Eta1, "|#eta| < 1");
    Gc_Eta1->Write("Gpred_Eta1");
    cout << "Gstrip Eta1 done" << endl;
    TCanvas *Gc_Eta1_2p4 = DrawCanvas(Gpred_noIhFit_Eta1_2p4, Gpred_noPFit_Eta1_2p4, Gpred_noIhFit_noPFit_Eta1_2p4, Gpred_Eta1_2p4, Gobs_Eta1_2p4, "1 < |#eta| < 2.4");
    Gc_Eta1_2p4->Write("Gpred_Eta1_2p4");
    cout << "Gstrip Eta1_2p4 done" << endl;
    TCanvas *Gc_Eta2p4 = DrawCanvas(Gpred_noIhFit_Eta2p4, Gpred_noPFit_Eta2p4, Gpred_noIhFit_noPFit_Eta2p4, Gpred_Eta2p4, Gobs_Eta2p4, "|#eta| < 2.4");
    Gc_Eta2p4->Write("Gpred_Eta2p4");
    cout << "Gstrip Eta2p4 done" << endl;
    TCanvas *Gc_Eta2p4New = DrawCanvas(Gpred_noIhFit_noPFit_Eta2p4, Gpred_Eta2p4, G_Eta2p4_newfit, Gobs_Eta2p4, "|#eta| < 2.4");
    Gc_Eta2p4New->Write("Gpred_Eta2p4New");
    cout << "Gstrip Eta2p4New done" << endl;

    ofile->Close();

    return;
}

TCanvas* RatioPlots(TH1F* h1_eta1, TH1F* h2_eta1, TH1F* h1_eta1_2p4, TH1F* h2_eta1_2p4, bool rebin, const char *name, const char *nameX)
{
    TH1F* hClone_eta1 = (TH1F*)h1_eta1->Clone();
    hClone_eta1->Scale(1./hClone_eta1->Integral());
    h2_eta1->Scale(1./h2_eta1->Integral());
    hClone_eta1->Divide(h2_eta1);
    TH1F* hClone_eta1_2p4 = (TH1F*)h1_eta1_2p4->Clone();
    hClone_eta1_2p4->Scale(1./hClone_eta1_2p4->Integral());
    h2_eta1_2p4->Scale(1./h2_eta1_2p4->Integral());
    hClone_eta1_2p4->Divide(h2_eta1_2p4);

    if (rebin)
    {
        hClone_eta1->Rebin(4);
        hClone_eta1_2p4->Rebin(4);
        hClone_eta1->Scale(1./4);
        hClone_eta1_2p4->Scale(1./4);
    }

    TCanvas *c1 = new TCanvas(name, name, 800, 800);
    c1->cd();
    hClone_eta1->SetLineColor(kRed);
    hClone_eta1->SetMarkerColor(kRed);
    hClone_eta1->SetMarkerStyle(21);
    hClone_eta1_2p4->SetLineColor(kBlue);
    hClone_eta1_2p4->SetMarkerColor(kBlue);
    hClone_eta1_2p4->SetMarkerStyle(20);
    hClone_eta1_2p4->Draw("E1");
    hClone_eta1->Draw("E1 same");
    hClone_eta1_2p4->GetXaxis()->SetTitle(nameX);
    hClone_eta1_2p4->GetYaxis()->SetTitle("C / D");
    hClone_eta1_2p4->GetYaxis()->SetRangeUser(0, 2.5);

    TLegend *leg = new TLegend(0.6, 0.7, 0.9, 0.9);
    leg->AddEntry(hClone_eta1, "|#eta| < 1", "lp");
    leg->AddEntry(hClone_eta1_2p4, "1 < |#eta| < 2.4", "lp");
    leg->SetFillStyle(0);
    leg->SetBorderSize(0);
    leg->Draw();

    TLine *line = new TLine(hClone_eta1_2p4->GetXaxis()->GetXmin(), 1, hClone_eta1_2p4->GetXaxis()->GetXmax(), 1);
    line->SetLineStyle(2);
    line->Draw("same");

    return c1;
}

void CompareTemplates()
{
    // Setup
    TFile *ofile = new TFile("PlayWithHistos/TemplatesCompare.root","RECREATE");

    TFile *File_Fpix_Eta1 = new TFile("Fpix_V2p12/Mu2018_massCut_0_pT70_V2p12_Fpix_Eta1_cutIndex3_rebinEta4_rebinIh4_rebinP2_rebinMass1.root");
    TH1F *FpixC_Ih_Eta1 = (TH1F*)File_Fpix_Eta1->Get("ih_eta_regionC_3fp8_ReRunRaph_py");
    TH1F *FpixD_Ih_Eta1 = (TH1F*)File_Fpix_Eta1->Get("ih_eta_regionD_8fp9_ReRunRaph_py");
    TH1F *FpixC_1op_Eta1 = (TH1F*)File_Fpix_Eta1->Get("eta_p_regionC_3fp8_ReRunRaph_px");
    TH1F *FpixD_1op_Eta1 = (TH1F*)File_Fpix_Eta1->Get("eta_p_regionD_8fp9_ReRunRaph_px");
    TH1F *FpixC_eta_Eta1 = (TH1F*)File_Fpix_Eta1->Get("ih_eta_regionC_3fp8_ReRunRaph_px");
    TH1F *FpixD_eta_Eta1 = (TH1F*)File_Fpix_Eta1->Get("ih_eta_regionD_8fp9_ReRunRaph_px");
    TFile *File_Fpix_Eta1_2p4 = new TFile("Fpix_V2p12/Mu2018_massCut_0_pT70_V2p12_Fpix_Eta1_2p4_cutIndex3_rebinEta4_rebinIh4_rebinP2_rebinMass1.root");
    TH1F *FpixC_Ih_Eta1_2p4 = (TH1F*)File_Fpix_Eta1_2p4->Get("ih_eta_regionC_3fp8_ReRunRaph_py");
    TH1F *FpixD_Ih_Eta1_2p4 = (TH1F*)File_Fpix_Eta1_2p4->Get("ih_eta_regionD_8fp9_ReRunRaph_py");
    TH1F *FpixC_1op_Eta1_2p4 = (TH1F*)File_Fpix_Eta1_2p4->Get("eta_p_regionC_3fp8_ReRunRaph_px");
    TH1F *FpixD_1op_Eta1_2p4 = (TH1F*)File_Fpix_Eta1_2p4->Get("eta_p_regionD_8fp9_ReRunRaph_px");
    TH1F *FpixC_eta_Eta1_2p4 = (TH1F*)File_Fpix_Eta1_2p4->Get("ih_eta_regionC_3fp8_ReRunRaph_px");
    TH1F *FpixD_eta_Eta1_2p4 = (TH1F*)File_Fpix_Eta1_2p4->Get("ih_eta_regionD_8fp9_ReRunRaph_px");

    // Ratio plots
    TCanvas *cIh = RatioPlots(FpixC_Ih_Eta1, FpixD_Ih_Eta1, FpixC_Ih_Eta1_2p4, FpixD_Ih_Eta1_2p4, true, "Fpix_Ih", "I_{h}");
    TCanvas *c1op = RatioPlots(FpixC_1op_Eta1, FpixD_1op_Eta1, FpixC_1op_Eta1_2p4, FpixD_1op_Eta1_2p4, true, "Fpix_1op", "1/p");
    TCanvas *cEta = RatioPlots(FpixC_eta_Eta1, FpixD_eta_Eta1, FpixC_eta_Eta1_2p4, FpixD_eta_Eta1_2p4, false, "Fpix_eta", "#eta");
    
    // Saving
    ofile->cd();
    cIh->Write();
    c1op->Write();
    cEta->Write();
    ofile->Close();

    return;
}

TCanvas* EtaPlots(TH2F* h2A, TH2F* h2B, TH2F* h2C, TH2F* h2D, const char *nameEta, const char *nameCanvas)
{
    TH1D *hA = h2A->ProjectionY(Form("%s_A", nameCanvas));
    TH1D *hB = h2B->ProjectionY(Form("%s_B", nameCanvas));
    TH1D *hC = h2C->ProjectionY(Form("%s_C", nameCanvas));
    TH1D *hD = h2D->ProjectionY(Form("%s_D", nameCanvas));

    hA->Scale(1./hA->Integral());
    hB->Scale(1./hB->Integral());
    hC->Scale(1./hC->Integral());
    hD->Scale(1./hD->Integral());

    hA->SetLineColor(kRed);
    hA->SetMarkerColor(kRed);
    hA->SetMarkerStyle(21);
    hB->SetLineColor(kBlue);
    hB->SetMarkerColor(kBlue);
    hB->SetMarkerStyle(20);
    hC->SetLineColor(kGreen+1);
    hC->SetMarkerColor(kGreen+1);
    hC->SetMarkerStyle(22);
    hD->SetLineColor(kMagenta);
    hD->SetMarkerColor(kMagenta);
    hD->SetMarkerStyle(23);
    
    TCanvas *c1 = new TCanvas(nameCanvas, nameCanvas, 800, 800);
    c1->cd();
    hA->Draw("E1");
    hB->Draw("E1 same");
    hC->Draw("E1 same");
    hD->Draw("E1 same");
    hA->GetXaxis()->SetTitle("#eta");
    hA->GetXaxis()->SetRangeUser(-2.6, 2.6);
    hA->GetYaxis()->SetRangeUser(0, hA->GetMaximum()*1.2);

    TLegend *leg = new TLegend(0.6, 0.7, 0.9, 0.9);
    leg->SetFillStyle(0);
    leg->SetBorderSize(0);
    leg->SetHeader(nameEta,"C");
    leg->AddEntry(hA, "Region A", "p");
    leg->AddEntry(hB, "Region B", "p");
    leg->AddEntry(hC, "Region C", "p");
    leg->AddEntry(hD, "Region D", "p");
    leg->Draw();

    return c1;
}

TCanvas* RatioEta(TH2F* h2A, TH2F* h2B, TH2F* h2C, TH2F* h2D, const char *nameEta, const char *nameCanvas)
{
    TH1D *hA = h2A->ProjectionY(Form("%s_A", nameCanvas));
    TH1D *hB = h2B->ProjectionY(Form("%s_B", nameCanvas));
    TH1D *hC = h2C->ProjectionY(Form("%s_C", nameCanvas));
    TH1D *hD = h2D->ProjectionY(Form("%s_D", nameCanvas));

    hA->Scale(1./hA->Integral());
    hB->Scale(1./hB->Integral());
    hC->Scale(1./hC->Integral());
    hD->Scale(1./hD->Integral());
    
    hA->Divide(hD);
    hB->Divide(hD);
    hC->Divide(hD);

    hA->SetLineColor(kRed);
    hA->SetMarkerColor(kRed);
    hA->SetMarkerStyle(21);
    hB->SetLineColor(kBlue);
    hB->SetMarkerColor(kBlue);
    hB->SetMarkerStyle(20);
    hC->SetLineColor(kGreen+1);
    hC->SetMarkerColor(kGreen+1);
    hC->SetMarkerStyle(22);

    TCanvas *c1 = new TCanvas(nameCanvas, nameCanvas, 800, 800);
    c1->cd();
    hA->Draw("E1");
    hB->Draw("E1 same");
    hC->Draw("E1 same");
    hA->GetXaxis()->SetTitle("#eta");
    hA->GetXaxis()->SetRangeUser(-2.6, 2.6);
    hA->GetYaxis()->SetRangeUser(0, 2.5);

    TLegend *leg = new TLegend(0.6, 0.7, 0.9, 0.9);
    leg->SetFillStyle(0);
    leg->SetBorderSize(0);
    leg->SetHeader(nameEta,"C");
    leg->AddEntry(hA, "A/D", "p");
    leg->AddEntry(hB, "B/D", "p");
    leg->AddEntry(hC, "C/D", "p");
    leg->Draw();

    TLine *line = new TLine(hA->GetXaxis()->GetXmin(), 1, hA->GetXaxis()->GetXmax(), 1);
    line->SetLineStyle(2);
    line->Draw("same");

    return c1;

}

void WriteSF(TH2F* h2A, TH2F* h2D, const char *nameFile)
{
    // Setup
    TH1D *hA = h2A->ProjectionY("blouki_A");
    TH1D *hD = h2D->ProjectionY("blouki_D");

    hA->Scale(1./hA->Integral());
    hD->Scale(1./hD->Integral());
    hA->Divide(hD);

    // SF saved
    ofstream file;
    file.open(nameFile);
    for (int i = 1; i <= hA->GetNbinsX(); i++) file << hA->GetBinContent(i) << endl;
    file.close();

    return;
}

TCanvas* SF_Eta(TH2F* h2A, TH2F* h2B, TH2F* h2C, TH2F* h2D, const char *nameEta, const char *nameCanvas)
{
    TH1D *hA = h2A->ProjectionY(Form("%s_SFA", nameCanvas));
    TH1D *hB = h2B->ProjectionY(Form("%s_SFB", nameCanvas));
    TH1D *hC = h2C->ProjectionY(Form("%s_SFC", nameCanvas));
    TH1D *hD = h2D->ProjectionY(Form("%s_SFD", nameCanvas));

    hA->Scale(1./hA->Integral());
    hB->Scale(1./hB->Integral());
    hC->Scale(1./hC->Integral());
    hD->Scale(1./hD->Integral());

    hA->SetLineColor(kRed);
    hA->SetMarkerColor(kRed);
    hA->SetMarkerStyle(21);
    hD->SetLineColor(kBlack);
    hD->SetMarkerColor(kBlack);
    hD->SetMarkerStyle(22);

    for (int i = 1; i <= hA->GetNbinsX(); i++) hA->SetBinContent(i, hB->GetBinContent(i)*hC->GetBinContent(i)/hA->GetBinContent(i));

    TCanvas *c1 = new TCanvas(nameCanvas, nameCanvas, 800, 800);
    c1->cd();
    hA->Draw("E1");
    hD->Draw("hist same");
    hA->GetXaxis()->SetTitle("#eta");
    hA->GetXaxis()->SetRangeUser(-2.6, 2.6);
    hA->GetYaxis()->SetRangeUser(0, 0.02);

    TLegend *leg = new TLegend(0.6, 0.7, 0.9, 0.9);
    leg->SetFillStyle(0);
    leg->SetBorderSize(0);
    leg->SetHeader(nameEta,"C");
    leg->AddEntry(hA, "B*C/A", "p");
    leg->AddEntry(hD, "D", "p");
    leg->Draw();

    return c1;
}

TCanvas* SF_EtaRatio(TH2F* h2A, TH2F* h2B, TH2F* h2C, TH2F* h2D, const char *nameEta, const char *nameCanvas)
{
    TH1D *hA = h2A->ProjectionY(Form("%s_SFA", nameCanvas));
    TH1D *hB = h2B->ProjectionY(Form("%s_SFB", nameCanvas));
    TH1D *hC = h2C->ProjectionY(Form("%s_SFC", nameCanvas));
    TH1D *hD = h2D->ProjectionY(Form("%s_SFD", nameCanvas));

    hA->Scale(1./hA->Integral());
    hB->Scale(1./hB->Integral());
    hC->Scale(1./hC->Integral());
    hD->Scale(1./hD->Integral());

    hA->SetLineColor(kRed);
    hA->SetMarkerColor(kRed);
    hA->SetMarkerStyle(21);

    for (int i = 1; i <= hA->GetNbinsX(); i++) hA->SetBinContent(i, hB->GetBinContent(i)*hC->GetBinContent(i)/hA->GetBinContent(i));
    hA->Divide(hD);

    TCanvas *c1 = new TCanvas(nameCanvas, nameCanvas, 800, 800);
    c1->cd();
    hA->Draw("E1");
    hA->GetXaxis()->SetTitle("#eta");
    hA->GetXaxis()->SetRangeUser(-2.6, 2.6);
    hA->GetYaxis()->SetRangeUser(0.8, 1.2);

    TLegend *leg = new TLegend(0.6, 0.7, 0.9, 0.9);
    leg->SetFillStyle(0);
    leg->SetBorderSize(0);
    leg->SetHeader(nameEta,"C");
    leg->AddEntry(hA, "B*C/A / D", "p");
    leg->Draw();

    TLine *line = new TLine(hA->GetXaxis()->GetXmin(), 1, hA->GetXaxis()->GetXmax(), 1);
    line->SetLineStyle(2);
    line->Draw("same");

    return c1;
}

void EtaInRegions()
{
    // Setup
    TFile *ofile = new TFile("PlayWithHistos/EtaInRegions.root", "RECREATE");

    TFile *File_Fpix_Eta1 = new TFile("Mu2018_massCut_0_pT70_V2p14_Fpix_Eta1.root");
    TH2F *A_Eta1 = (TH2F*)File_Fpix_Eta1->Get("eta_p_regionA_3fp8_ReRunRaph");
    TH2F *B_Eta1 = (TH2F*)File_Fpix_Eta1->Get("eta_p_regionB_8fp9_ReRunRaph");
    TH2F *C_Eta1 = (TH2F*)File_Fpix_Eta1->Get("eta_p_regionC_3fp8_ReRunRaph");
    TH2F *D_Eta1 = (TH2F*)File_Fpix_Eta1->Get("eta_p_regionD_8fp9_ReRunRaph");
    TFile *File_Fpix_Eta1_2p4 = new TFile("Mu2018_massCut_0_pT70_V2p14_Fpix_Eta1_2p4.root");
    TH2F *A_Eta1_2p4 = (TH2F*)File_Fpix_Eta1_2p4->Get("eta_p_regionA_3fp8_ReRunRaph");
    TH2F *B_Eta1_2p4 = (TH2F*)File_Fpix_Eta1_2p4->Get("eta_p_regionB_8fp9_ReRunRaph");
    TH2F *C_Eta1_2p4 = (TH2F*)File_Fpix_Eta1_2p4->Get("eta_p_regionC_3fp8_ReRunRaph");
    TH2F *D_Eta1_2p4 = (TH2F*)File_Fpix_Eta1_2p4->Get("eta_p_regionD_8fp9_ReRunRaph");
    TFile *File_Fpix_Eta2p4 = new TFile("Mu2018_massCut_0_pT70_V2p17_Fpix_Eta2p4.root");
    TH2F *A_Eta2p4 = (TH2F*)File_Fpix_Eta2p4->Get("eta_p_regionA_3fp8_ReRunRaph");
    TH2F *B_Eta2p4 = (TH2F*)File_Fpix_Eta2p4->Get("eta_p_regionB_8fp9_ReRunRaph");
    TH2F *C_Eta2p4 = (TH2F*)File_Fpix_Eta2p4->Get("eta_p_regionC_3fp8_ReRunRaph");
    TH2F *D_Eta2p4 = (TH2F*)File_Fpix_Eta2p4->Get("eta_p_regionD_8fp9_ReRunRaph");


    // Eta plots in all regions
    TCanvas *cEta1 = EtaPlots(A_Eta1, B_Eta1, C_Eta1, D_Eta1, "|#eta| < 1", "Eta1");
    TCanvas *cEta1_2p4 = EtaPlots(A_Eta1_2p4, B_Eta1_2p4, C_Eta1_2p4, D_Eta1_2p4, "1 < |#eta| < 2.4", "Eta1_2p4");
    TCanvas *cEta2p4 = EtaPlots(A_Eta2p4, B_Eta2p4, C_Eta2p4, D_Eta2p4, "|#eta| < 2.4", "Eta2p4");
    TCanvas *cEta2p4Ratio = RatioEta(A_Eta2p4, B_Eta2p4, C_Eta2p4, D_Eta2p4, "|#eta| < 2.4", "Eta2p4_RatioToD");
    TCanvas *cEta2p4_SF = SF_Eta(A_Eta2p4, B_Eta2p4, C_Eta2p4, D_Eta2p4, "|#eta| < 2.4", "SF_Eta");
    TCanvas *cEta2p4_SFratio = SF_EtaRatio(A_Eta2p4, B_Eta2p4, C_Eta2p4, D_Eta2p4, "|#eta| < 2.4", "SF_EtaRatio");
    

    WriteSF(A_Eta2p4, D_Eta2p4, "PlayWithHistos/SF_AoD.txt");

    // Saving
    ofile->cd();
    cEta1->Write();
    cEta1_2p4->Write();
    cEta2p4->Write();
    cEta2p4Ratio->Write();
    cEta2p4_SF->Write();
    cEta2p4_SFratio->Write();
    ofile->Close();

    return;
}

void FpixVSEta()
{   
    // Setup
    TFile *ofile = new TFile("PlayWithHistos/FpixVSEta.root","RECREATE");
    

    TFile *File_Fpix_Eta2p4 = new TFile("Mu2018_massCut_0_pT70_V2p17_Gstrip_Fpix_Eta2p4.root");
    TH2F *A_Eta2p4 = (TH2F*)File_Fpix_Eta2p4->Get("fpix_eta_regionA_3fp8_ReRunRaph");
    TH2F *B_Eta2p4 = (TH2F*)File_Fpix_Eta2p4->Get("fpix_eta_regionB_8fp9_ReRunRaph");
    TH2F *C_Eta2p4 = (TH2F*)File_Fpix_Eta2p4->Get("fpix_eta_regionC_3fp8_ReRunRaph");
    TH2F *D_Eta2p4 = (TH2F*)File_Fpix_Eta2p4->Get("fpix_eta_regionD_8fp9_ReRunRaph");

    // Eta projection for each Fpix bin
    std::vector <TH1D*> hA_vec;
    std::vector <TH1D*> hB_vec;
    std::vector <TH1D*> hC_vec;
    std::vector <TH1D*> hD_vec;
    for (int i=1; i<A_Eta2p4->GetNbinsX(); i++)
    {
        TH1D *hA = A_Eta2p4->ProjectionY(Form("Aeta_%d", i), i, i);
        TH1D *hB = B_Eta2p4->ProjectionY(Form("Beta_%d", i), i, i);
        TH1D *hC = C_Eta2p4->ProjectionY(Form("Ceta_%d", i), i, i);
        TH1D *hD = D_Eta2p4->ProjectionY(Form("Deta_%d", i), i, i);

        if (hA->Integral() != 0) { hA->Scale(1./hA->Integral()); hA_vec.push_back(hA); }
        if (hB->Integral() != 0) { hB->Scale(1./hB->Integral()); hB_vec.push_back(hB); }
        if (hC->Integral() != 0) { hC->Scale(1./hC->Integral()); hC_vec.push_back(hC); }
        if (hD->Integral() != 0) { hD->Scale(1./hD->Integral()); hD_vec.push_back(hD); }
    }

    // Eta plots in all regions
    TCanvas *cA = new TCanvas("cA", "cA", 800, 800);
    cA->cd();
    hA_vec[0]->Draw("hist");
    hA_vec[0]->SetLineColor(kOrange);
    for (int i=1; i<hA_vec.size(); i++){ hA_vec[i]->Draw("hist same"); hA_vec[i]->SetLineColor(kOrange+i); }
    hA_vec[0]->GetXaxis()->SetTitle("#eta");
    hA_vec[0]->GetXaxis()->SetRangeUser(-2.6, 2.6);
    TLegend *legA = new TLegend(0.6, 0.7, 0.9, 0.9);
    legA->SetFillStyle(0);
    legA->SetBorderSize(0);
    for (int i=0; i<hA_vec.size(); i++) legA->AddEntry(hA_vec[i], Form("F_{pixel} [%3.2f;%3.2f]", 0.3+0.05*i, 0.35+0.05*i), "l");
    legA->Draw();


    TCanvas *cB = new TCanvas("cB", "cB", 800, 800);
    cB->cd();
    hB_vec[0]->Draw("hist");
    hB_vec[0]->SetLineColor(kOrange);
    for (int i=1; i<hB_vec.size(); i++){ hB_vec[i]->Draw("hist same"); hB_vec[i]->SetLineColor(kOrange+i); }
    hB_vec[0]->GetXaxis()->SetTitle("#eta");
    hB_vec[0]->GetXaxis()->SetRangeUser(-2.6, 2.6);
    TLegend *legB = new TLegend(0.6, 0.7, 0.9, 0.9);
    legB->SetFillStyle(0);
    legB->SetBorderSize(0);
    for (int i=0; i<hB_vec.size(); i++) legB->AddEntry(hB_vec[i], Form("F_{pixel} [%3.2f;%3.2f]", 0.8+0.05*i, 0.85+0.05*i), "l");
    legB->Draw();

    TCanvas *cC = new TCanvas("cC", "cC", 800, 800);
    cC->cd();
    hC_vec[0]->Draw("hist");
    hC_vec[0]->SetLineColor(kOrange);
    for (int i=1; i<hC_vec.size(); i++){ hC_vec[i]->Draw("hist same"); hC_vec[i]->SetLineColor(kOrange+i); }
    hC_vec[0]->GetXaxis()->SetTitle("#eta");
    hC_vec[0]->GetXaxis()->SetRangeUser(-2.6, 2.6);
    TLegend *legC = new TLegend(0.6, 0.7, 0.9, 0.9);
    legC->SetFillStyle(0);
    legC->SetBorderSize(0);
    for (int i=0; i<hC_vec.size(); i++) legC->AddEntry(hC_vec[i], Form("F_{pixel} [%3.2f;%3.2f]", 0.3+0.05*i, 0.35+0.05*i), "l");
    legC->Draw();

    TCanvas *cD = new TCanvas("cD", "cD", 800, 800);
    cD->cd();
    hD_vec[0]->Draw("hist");
    hD_vec[0]->SetLineColor(kOrange);
    for (int i=1; i<hD_vec.size(); i++){ hD_vec[i]->Draw("hist same"); hD_vec[i]->SetLineColor(kOrange+i); }
    hD_vec[0]->GetXaxis()->SetTitle("#eta");
    hD_vec[0]->GetXaxis()->SetRangeUser(-2.6, 2.6);
    TLegend *legD = new TLegend(0.6, 0.7, 0.9, 0.9);
    legD->SetFillStyle(0);
    legD->SetBorderSize(0);
    for (int i=0; i<hD_vec.size(); i++) legD->AddEntry(hD_vec[i], Form("F_{pixel} [%3.2f;%3.2f]", 0.8+0.05*i, 0.85+0.05*i), "l");
    legD->Draw();

    // Saving
    ofile->cd();
    cA->Write();
    cB->Write();
    cC->Write();
    cD->Write();
    A_Eta2p4->Write();
    B_Eta2p4->Write();
    C_Eta2p4->Write();
    D_Eta2p4->Write();
    ofile->Close();

    return;
}

void CompareDistwMET()
{
    TFile *ofile = new TFile("PlayWithHistos/CompareDistwMET.root", "RECREATE");

    TFile *MET = new TFile("../output/Fpix_V3p1/MET_2017_2018_massCut_0_pT70_V3p1_Fpix_Eta2p4_cutIndex3_rebinEta4_rebinIh4_rebinP2_rebinMass1_EtaReweighting_NewFit.root");
    TH1F *eta_MET = (TH1F*)MET->Get("ih_eta_regionD_8fp9_MET_px");
    TH1F *Ih_MET = (TH1F*)MET->Get("ih_eta_regionD_8fp9_MET_py");
    TFile *METbis = new TFile("../output/MET_2017_2018_massCut_0_pT70_V3p1_Fpix_Eta2p4.root");
    TH1F *p_MET = (TH1F*)METbis->Get("MET_p");
    TH2F *FpixGstripMET = (TH2F*)METbis->Get("MET_Fpix_vs_Gstrip");
    TH1F *FpixMET = (TH1F*)FpixGstripMET->ProjectionX("Fpix");
    
    TFile *Mu = new TFile("../output/Fpix_V2p18/Mu2018_massCut_0_pT70_V2p18_Fpix_Eta2p4_cutIndex3_rebinEta4_rebinIh4_rebinP2_rebinMass1_EtaReweighting.root");
    TH1F *eta_Mu = (TH1F*)Mu->Get("ih_eta_regionD_8fp9_ReRunRaph_px");
    TH1F *Ih_Mu = (TH1F*)Mu->Get("ih_eta_regionD_8fp9_ReRunRaph_py");
    TFile *Mubis = new TFile("../output/Mu2018_massCut_0_pT70_V2p18_Fpix_Eta2p4.root");
    TH1F *p_Mu = (TH1F*)Mubis->Get("ReRunRaph_p");
    TH2F *FpixGstripMu = (TH2F*)Mubis->Get("ReRunRaph_Fpix_vs_Gstrip");
    TH1F *FpixMu = (TH1F*)FpixGstripMu->ProjectionX("Fpix");


    eta_MET->Scale(1./eta_MET->Integral());
    eta_Mu->Scale(1./eta_Mu->Integral());
    p_MET->Scale(1./p_MET->Integral());
    p_Mu->Scale(1./p_Mu->Integral());
    Ih_MET->Scale(1./Ih_MET->Integral());
    Ih_Mu->Scale(1./Ih_Mu->Integral());
    FpixMET->Scale(1./FpixMET->Integral());
    FpixMu->Scale(1./FpixMu->Integral());

    for (int i = 1; i <= FpixMET->GetNbinsX(); i++)
    {
        if (FpixMET->GetBinCenter(i) > 0.9) FpixMET->SetBinContent(i, 0);
        if (FpixMu->GetBinCenter(i) > 0.9) FpixMu->SetBinContent(i, 0);
    }
    

    eta_MET->SetLineColor(kRed);
    eta_MET->SetMarkerColor(kRed);
    eta_MET->SetMarkerStyle(21);
    eta_Mu->SetLineColor(kBlue);
    eta_Mu->SetMarkerColor(kBlue);
    eta_Mu->SetMarkerStyle(20);

    p_MET->SetLineColor(kRed);
    p_MET->SetMarkerColor(kRed);
    p_MET->SetMarkerStyle(21);
    p_Mu->SetLineColor(kBlue);
    p_Mu->SetMarkerColor(kBlue);
    p_Mu->SetMarkerStyle(20);

    Ih_MET->SetLineColor(kRed);
    Ih_MET->SetMarkerColor(kRed);
    Ih_MET->SetMarkerStyle(21);
    Ih_Mu->SetLineColor(kBlue);
    Ih_Mu->SetMarkerColor(kBlue);
    Ih_Mu->SetMarkerStyle(20);

    FpixMET->SetLineColor(kRed);
    FpixMET->SetMarkerColor(kRed);
    FpixMET->SetMarkerStyle(21);
    FpixMu->SetLineColor(kBlue);
    FpixMu->SetMarkerColor(kBlue);
    FpixMu->SetMarkerStyle(20);

    TCanvas *c1 = new TCanvas("ceta", "c1", 800, 800);
    c1->cd();
    eta_MET->Draw("E1");
    eta_Mu->Draw("E1 same");
    eta_MET->GetXaxis()->SetTitle("#eta");
    TLegend *leg = new TLegend(0.6, 0.7, 0.9, 0.9);
    leg->SetFillStyle(0);
    leg->SetBorderSize(0);
    leg->AddEntry(eta_MET, "MET", "lp");
    leg->AddEntry(eta_Mu, "Mu", "lp");
    leg->Draw();

    TCanvas *c2 = new TCanvas("cp", "c1", 800, 800);
    c2->cd();
    p_MET->Draw("E1");
    p_Mu->Draw("E1 same");
    p_MET->GetXaxis()->SetTitle("p [GeV]");
    p_MET->GetYaxis()->SetTitle("");
    c2->SetLogy();
    leg->Draw();

    TCanvas *c3 = new TCanvas("cih", "c1", 800, 800);
    c3->cd();
    Ih_MET->Draw("E1");
    Ih_Mu->Draw("E1 same");
    Ih_MET->GetXaxis()->SetTitle("I_{h}");
    c3->SetLogy();
    leg->Draw();

    TCanvas *c4 = new TCanvas("cfpix", "c1", 800, 800);
    c4->cd();
    FpixMET->Draw("E1");
    FpixMu->Draw("E1 same");
    FpixMET->GetXaxis()->SetTitle("F_{pixel}");
    leg->Draw();


    ofile->cd();
    c1->Write();
    c2->Write();
    c3->Write();
    c4->Write();
    ofile->Close();

    return;
}

void MyCutFlow()
{
    TFile *ofile = new TFile("PlayWithHistos/MyCutFlow.root", "RECREATE");

    TFile *ifile = new TFile("MET_2017_2018_massCut_0_pT70_V3p3_Fpix_Eta2p4.root");
    TH1F *CutFlow_MET = (TH1F*)ifile->Get("METContainingMu_Cutflow");
    TH1F *CutFlow_OnlyMET = (TH1F*)ifile->Get("OnlyMET_Cutflow");

    CutFlow_MET->GetXaxis()->SetBinLabel(1, "All events");
    CutFlow_MET->GetXaxis()->SetBinLabel(2, "MET triggers");
    CutFlow_MET->GetXaxis()->SetBinLabel(3, "CaloMET > 170 GeV");
    CutFlow_MET->GetXaxis()->SetBinLabel(4, "MET filters");
    CutFlow_MET->GetXaxis()->SetBinLabel(5, "p_{T} > 55 GeV");
    CutFlow_MET->GetXaxis()->SetBinLabel(6, "#eta < 2.4");
    CutFlow_MET->GetXaxis()->SetBinLabel(7, "NOPH #geq 2");
    CutFlow_MET->GetXaxis()->SetBinLabel(8, "FOVH > 0.8");
    CutFlow_MET->GetXaxis()->SetBinLabel(9, "NOM #geq 10");
    CutFlow_MET->GetXaxis()->SetBinLabel(10, "isHighPurity");
    CutFlow_MET->GetXaxis()->SetBinLabel(11, "#chi^{2}/ndof < 5.0");
    CutFlow_MET->GetXaxis()->SetBinLabel(12, "d_{z} < 0.1");
    CutFlow_MET->GetXaxis()->SetBinLabel(13, "d_{xy} < 0.02");
    CutFlow_MET->GetXaxis()->SetBinLabel(14, "I_{PF}^{rel} < 0.02");
    CutFlow_MET->GetXaxis()->SetBinLabel(15, "I_{trk} < 15 GeV");
    CutFlow_MET->GetXaxis()->SetBinLabel(16, "E/p < 0.3");
    CutFlow_MET->GetXaxis()->SetBinLabel(17, "p_{T}^{err}/p_{T}^2 < 0.0008");
    CutFlow_MET->GetXaxis()->SetBinLabel(18, "F_{pixel} > 0.3");
    CutFlow_MET->GetXaxis()->SetBinLabel(19, "p_{T}^{err}/p_{T} < 1");
    CutFlow_MET->GetXaxis()->SetBinLabel(20, "I_{h} > C");

    // scale par rapport au premier bin
    CutFlow_MET->Scale(1./CutFlow_MET->GetBinContent(1));
    CutFlow_OnlyMET->Scale(1./CutFlow_OnlyMET->GetBinContent(1));
    CutFlow_MET->SetLineColor(kRed);
    CutFlow_OnlyMET->SetLineColor(kBlue);

    TCanvas *c1 = new TCanvas("CutFlow", "CutFlow", 800, 800);
    c1->cd();
    CutFlow_MET->Draw("hist");
    CutFlow_OnlyMET->Draw("hist same");
    gPad->SetTickx(0);
    CutFlow_MET->LabelsOption("v", "X");
    CutFlow_MET->GetXaxis()->SetTitle("");
    CutFlow_MET->GetYaxis()->SetTitle("Events");
    CutFlow_MET->GetYaxis()->SetRangeUser(CutFlow_OnlyMET->GetMinimum()/5, CutFlow_MET->GetMaximum()*5);
    TLegend *leg = new TLegend(0.6, 0.7, 0.9, 0.9);
    leg->SetFillStyle(0);
    leg->SetBorderSize(0);
    leg->AddEntry(CutFlow_MET, "MET", "l");
    leg->AddEntry(CutFlow_OnlyMET, "Only MET", "l");
    leg->Draw();
    c1->SetLogy();


    ofile->cd();
    c1->Write();
    ofile->Close();

    return;
}

void Nm1CutFlow()
{
    TFile *ofile = new TFile("PlayWithHistos/Nm1CutFlow.root", "RECREATE");

    TFile *ifile = new TFile("MET_2017_2018_massCut_0_pT70_V3p3_Fpix_Eta2p4.root");
    TH1F *OnlyMET_Nm1_trigger = (TH1F*)ifile->Get("OnlyMET_Nm1_trigger");
    TH1F *OnlyMET_Nm1_METfilters = (TH1F*)ifile->Get("OnlyMET_Nm1_METfilters");
    TH1F *OnlyMET_Nm1_CaloMET = (TH1F*)ifile->Get("OnlyMET_Nm1_CaloMET");
    TH1F *OnlyMET_Nm1_Pt = (TH1F*)ifile->Get("OnlyMET_Nm1_Pt");
    TH1F *OnlyMET_Nm1_eta = (TH1F*)ifile->Get("OnlyMET_Nm1_eta");
    TH1F *OnlyMET_Nm1_NOPH = (TH1F*)ifile->Get("OnlyMET_Nm1_NOPH");
    TH1F *OnlyMET_Nm1_FOVH = (TH1F*)ifile->Get("OnlyMET_Nm1_FOVH");
    TH1F *OnlyMET_Nm1_NOM = (TH1F*)ifile->Get("OnlyMET_Nm1_NOM");
    TH1F *OnlyMET_Nm1_HighPurity = (TH1F*)ifile->Get("OnlyMET_Nm1_HighPurity");
    TH1F *OnlyMET_Nm1_Chi2 = (TH1F*)ifile->Get("OnlyMET_Nm1_Chi2");
    TH1F *OnlyMET_Nm1_dZ = (TH1F*)ifile->Get("OnlyMET_Nm1_dZ");
    TH1F *OnlyMET_Nm1_dXY = (TH1F*)ifile->Get("OnlyMET_Nm1_dXY");
    TH1F *OnlyMET_Nm1_PFMiniIso = (TH1F*)ifile->Get("OnlyMET_Nm1_PFMiniIso");
    TH1F *OnlyMET_Nm1_TrkIso = (TH1F*)ifile->Get("OnlyMET_Nm1_TrkIso");
    TH1F *OnlyMET_Nm1_EoverP = (TH1F*)ifile->Get("OnlyMET_Nm1_EoverP");
    TH1F *OnlyMET_Nm1_PtErr_over_PtPt = (TH1F*)ifile->Get("OnlyMET_Nm1_PtErr_over_PtPt");
    TH1F *OnlyMET_Nm1_Fpix = (TH1F*)ifile->Get("OnlyMET_Nm1_Fpix");
    TH1F *OnlyMET_Nm1_PtErr_over_Pt = (TH1F*)ifile->Get("OnlyMET_Nm1_PtErr_over_Pt");
    TH1F *OnlyMET_Nm1_Ih_StripOnly = (TH1F*)ifile->Get("OnlyMET_Nm1_Ih_StripOnly");

    std::vector<std::function<bool(double)>> cuts;
    cuts.push_back([&](int trigger){ return trigger; });
    cuts.push_back([&](int Flag_allMETFilters){ return Flag_allMETFilters; });
    cuts.push_back([&](float RecoCaloMET){ return RecoCaloMET > 170; });
    cuts.push_back([&](float Pt){ return Pt > 55.0; });
    cuts.push_back([&](float eta){ return fabs(eta) < 2.4; });
    cuts.push_back([&](float NOPH){ return NOPH >= 2; });
    cuts.push_back([&](float FOVH){ return FOVH > 0.8; });
    cuts.push_back([&](float NOM){ return NOM >= 10; });
    cuts.push_back([&](int isHighPurity){ return isHighPurity; });
    cuts.push_back([&](float Chi2_over_ndof){ return Chi2_over_ndof < 5.0; });
    cuts.push_back([&](float dZ){ return fabs(dZ) < 0.1; });
    cuts.push_back([&](float dXY){ return fabs(dXY) < 0.02; });
    cuts.push_back([&](float PFMiniIso_relative){ return PFMiniIso_relative < 0.02; });
    cuts.push_back([&](float track_genTrackIsoSumPt_dr03){ return track_genTrackIsoSumPt_dr03 < 15; });
    cuts.push_back([&](float EoverP){ return EoverP < 0.3; });
    cuts.push_back([&](float PtErr_over_PtPt){ return (PtErr_over_PtPt > 0 && PtErr_over_PtPt < 0.0008); });
    cuts.push_back([&](float Fpix){ return Fpix > 0.3; });
    cuts.push_back([&](float PtErr_over_Pt){ return PtErr_over_Pt < 1; });
    cuts.push_back([&](float Ih_StripOnly){ return Ih_StripOnly > 3.14; });

    std::vector<TH1F*> originalHistos = {
    OnlyMET_Nm1_trigger,
    OnlyMET_Nm1_METfilters,
    OnlyMET_Nm1_CaloMET,
    OnlyMET_Nm1_Pt,
    OnlyMET_Nm1_eta,
    OnlyMET_Nm1_NOPH,
    OnlyMET_Nm1_FOVH,
    OnlyMET_Nm1_NOM,
    OnlyMET_Nm1_HighPurity,
    OnlyMET_Nm1_Chi2,
    OnlyMET_Nm1_dZ,
    OnlyMET_Nm1_dXY,
    OnlyMET_Nm1_PFMiniIso,
    OnlyMET_Nm1_TrkIso,
    OnlyMET_Nm1_EoverP,
    OnlyMET_Nm1_PtErr_over_PtPt,
    OnlyMET_Nm1_Fpix,
    OnlyMET_Nm1_PtErr_over_Pt,
    OnlyMET_Nm1_Ih_StripOnly
    };

    std::vector<std::string> Xlabels = {
    "Trigger",
    "MET filters",
    "CaloMET",
    "p_{T}",
    "#eta",
    "NOPH",
    "FOVH",
    "NOM",
    "isHighPurity",
    "#chi^{2}/ndof",
    "|d_{z}|",
    "|d_{xy}|",
    "I_{PF}^{rel}",
    "I_{trk}",
    "E/p",
    "p_{T}^{err}/p_{T}^2",
    "F_{pixel}",
    "p_{T}^{err}/p_{T}",
    "I_{h}"
    };

    std::vector<TH1F*> cutHistos;
    for (size_t i = 0; i < originalHistos.size(); ++i) {
        TH1F* h_clone = (TH1F*)originalHistos[i]->Clone((std::string(originalHistos[i]->GetName()) + "_cut").c_str());
        h_clone->Reset();
        cutHistos.push_back(h_clone);
    }

    for (size_t j = 0; j < cuts.size(); ++j) {
        for (int i=1; i<cutHistos[j]->GetNbinsX(); i++) {
            double binCenter = originalHistos[j]->GetXaxis()->GetBinCenter(i);
            double binContent = originalHistos[j]->GetBinContent(i);

            if (cuts[j](binCenter)) cutHistos[j]->SetBinContent(i, binContent);
        }
    }

    for (size_t i = 0; i < cutHistos.size(); ++i) {
        cutHistos[i]->SetLineColor(kRed);
        originalHistos[i]->SetLineColor(kBlue);
        cutHistos[i]->GetXaxis()->SetTitle(Xlabels[i].c_str());
        cutHistos[i]->GetYaxis()->SetTitle("Events");
    }

    ofile->cd();
    for (size_t i = 0; i < cutHistos.size(); ++i) {
        TCanvas *c = new TCanvas(Form("Nm1CutFlow_%zu", i), Form("Nm1CutFlow_%zu", i), 800, 800);
        c->cd();
        cutHistos[i]->Draw("hist");
        originalHistos[i]->Draw("hist same");
        cutHistos[i]->Draw("hist same");
        cutHistos[i]->GetYaxis()->SetRangeUser(0, cutHistos[i]->GetMaximum()*5);
        TLegend *leg = new TLegend(0.6, 0.7, 0.9, 0.9);
        leg->SetFillStyle(0);
        leg->SetBorderSize(0);
        leg->AddEntry(cutHistos[i], "cut", "l");
        leg->AddEntry(originalHistos[i], "original", "l");
        leg->Draw();

        c->Write();
    }
    ofile->Close();



    return;
}


void CombineHistos()
{
    //PlotPredFits();
    //CompareTemplates();
    //EtaInRegions();
    //FpixVSEta();
    //CompareDistwMET();
    //MyCutFlow();
    //Nm1CutFlow();

    CompareDist_CandD("METContainingMu");
    CompareDist_CandD("OnlyMET");

    return;
}