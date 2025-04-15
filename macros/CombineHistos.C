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



void CombineHistos()
{
    //PlotPredFits();
    //CompareTemplates();
    EtaInRegions();
    //FpixVSEta();

    return;
}