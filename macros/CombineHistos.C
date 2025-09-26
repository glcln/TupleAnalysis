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

TCanvas* DrawWithRatio(TH1* h1, TH1* h2, TCanvas* c1, std::string CanvasTitle,
                       std::string RatioTitle, std::string OptionDraw, bool logy)
{
    if (!h1 || !h2) {
        std::cerr << "DrawWithRatio: h1 or h2 is null! Returning nullptr.\n";
        return nullptr;
    }

    TCanvas* c_new = new TCanvas(CanvasTitle.c_str(), CanvasTitle.c_str(), 800, 800);

    // Define pads
    TPad* pad1 = new TPad("pad1", "pad1", 0.0, 0.45, 1.0, 1.0);
    pad1->SetBottomMargin(0.03);
    pad1->Draw();
    if (logy) pad1->SetLogy();

    TPad* pad2 = new TPad("pad2", "pad2", 0.0, 0.0, 1.0, 0.45);
    pad2->SetTopMargin(0.02);
    pad2->SetBottomMargin(0.45);
    pad2->Draw();

    // Draw upper plot: draw h1 then h2 (use OptionDraw for h1, and "E1 same" for h2)
    pad1->cd();
    // Make clones so que l'originale reste inchangée
    TH1* h1c = (TH1*)h1->Clone(TString(h1->GetName()) + "_" + CanvasTitle);
    TH1* h2c = (TH1*)h2->Clone(TString(h2->GetName()) + "_" + CanvasTitle);
    if (!h1c || !h2c) {
        std::cerr << "DrawWithRatio: clone failed.\n";
        delete c_new;
        return nullptr;
    }
    h1c->Draw(OptionDraw.c_str());
    h2c->Draw("E1 same");

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
    h_ratio->Sumw2();
    h1c->Sumw2();
    h_ratio->Divide(h1c);

    h_ratio->SetTitle("");
    h_ratio->GetYaxis()->SetTitle(RatioTitle.c_str());
    h_ratio->GetYaxis()->SetRangeUser(0, 2);
    h_ratio->SetMarkerStyle(8);
    h_ratio->GetYaxis()->SetNdivisions(505);
    h_ratio->GetYaxis()->SetTitleSize(0.06);
    h_ratio->GetYaxis()->SetTitleOffset(0.5);
    h_ratio->GetXaxis()->SetTitleSize(0.06);
    h_ratio->GetXaxis()->SetTitleOffset(1);
    h_ratio->GetYaxis()->SetLabelSize(0.06);
    h_ratio->GetXaxis()->SetLabelSize(0.06);
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






    // ------ MAIN -------

void CombineHistos()
{

    return;
}