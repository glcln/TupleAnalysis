// plot_histos.C
// Reproduit les histogrammes AOD et miniAOD à partir de coordonnées (x,y)
// avec erreurs symétriques construites à partir de l'err down.
// Largeur de bin : 25, plage : [0, 1500]

#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

struct Point { double x, y; };

// Lit un CSV "x, y" et retourne les points
std::vector<Point> ReadCSV(const std::string& filename) {
    std::vector<Point> pts;
    std::ifstream f(filename);
    if (!f.is_open()) {
        std::cerr << "Cannot open " << filename << std::endl;
        return pts;
    }
    std::string line;
    std::getline(f, line); // skip header
    while (std::getline(f, line)) {
        if (line.empty()) continue;
        std::replace(line.begin(), line.end(), ',', ' ');
        std::istringstream ss(line);
        Point p;
        if (ss >> p.x >> p.y) pts.push_back(p);
    }
    return pts;
}

// Retourne l'indice de bin ROOT (1-based) pour une valeur x
// bins : [0,25), [25,50), ..., [1475,1500)  => 60 bins
int GetBin(TH1* h, double x) {
    int b = h->FindBin(x);
    int n = h->GetNbinsX();
    if (b < 1) b = 1;
    if (b > n) b = n;
    return b;
}

void plotAODvsminiAOD() {

    // ---- Paramètres ----
    const int    NBINS   = 60;
    const double XMIN    = 0.0;
    const double XMAX    = 1500.0;
    const double BINW    = 25.0;

    // ---- Lecture des CSV ----
    auto aod_nom  = ReadCSV("AOD_nom.csv");
    auto aod_dn   = ReadCSV("AOD_errDOWN.csv");
    auto mini_nom = ReadCSV("miniAOD_nom.csv");
    auto mini_dn  = ReadCSV("miniAOD_errDOWN.csv");

    // ---- Création des TGraphAsymmErrors ----
    // On remplit d'abord des tableaux indexés par bin
    std::vector<double> aod_y (NBINS, -1.0), aod_ey (NBINS, 0.0);
    std::vector<double> mini_y(NBINS, -1.0), mini_ey(NBINS, 0.0);

    // TH1 temporaire pour la correspondance bin<->x
    TH1D* htmp = new TH1D("htmp","",NBINS,XMIN,XMAX);

    // Remplissage nominaux
    for (auto& p : aod_nom) {
        int b = GetBin(htmp, p.x) - 1; // 0-based
        aod_y[b] = p.y;
    }
    for (auto& p : mini_nom) {
        int b = GetBin(htmp, p.x) - 1;
        mini_y[b] = p.y;
    }

    // Calcul des erreurs : err = nominal - errDOWN (symétrique)
    for (auto& p : aod_dn) {
        int b = GetBin(htmp, p.x) - 1;
        if (aod_y[b] > 0) aod_ey[b] = std::fabs(aod_y[b] - p.y);
    }
    for (auto& p : mini_dn) {
        int b = GetBin(htmp, p.x) - 1;
        if (mini_y[b] > 0) mini_ey[b] = std::fabs(mini_y[b] - p.y);
    }

    // ---- Construction des TH1D ----
    TH1D* hAOD  = new TH1D("hAOD",  "", NBINS, XMIN, XMAX);
    TH1D* hMini = new TH1D("hMini", "", NBINS, XMIN, XMAX);

    for (int i = 0; i < NBINS; ++i) {
        int b = i + 1; // ROOT : bins 1-based
        if (aod_y[i] >= 0) {
            hAOD->SetBinContent(b, aod_y[i]);
            hAOD->SetBinError  (b, aod_ey[i]);
        }
        if (mini_y[i] >= 0) {
            hMini->SetBinContent(b, mini_y[i]);
            hMini->SetBinError  (b, mini_ey[i]);
        }
    }

    // ---- Style ----
    hAOD->SetStats(0);
    hAOD->SetMarkerStyle(20);
    hAOD->SetMarkerColor(kBlue);
    hAOD->SetLineColor(kBlue);

    hMini->SetStats(0);
    hMini->SetMarkerStyle(21);
    hMini->SetMarkerColor(kRed);
    hMini->SetLineColor(kRed);

    // ---- Canvas & dessin ----
    TCanvas* c = new TCanvas("c","AOD vs miniAOD",800,600);
    TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1);
    pad1->SetBottomMargin(0.16); pad1->SetLeftMargin(0.16);
    pad1->Draw();
    pad1->cd();

    TLatex *latex1 = new TLatex(0.16, 0.91, "#scale[1.3]{#bf{CMS}}#it{Simulation Work in progress}");
    latex1->SetNDC();
    latex1->SetTextFont(42);
    latex1->SetTextSize(0.04);

    hAOD->GetYaxis()->SetTitleSize(0.06);
    hAOD->GetXaxis()->SetTitleSize(0.06);
    hAOD->GetXaxis()->SetTitleOffset(0.9);
    hAOD->GetYaxis()->SetTitleOffset(1);
    hAOD->GetXaxis()->SetLabelSize(0.05);
    hAOD->GetYaxis()->SetLabelSize(0.05);
    hAOD->GetXaxis()->SetTitle("Calo MET or Pseudo MET (GeV)");
    hAOD->GetYaxis()->SetTitle("Eff. orMETtrig");
    hAOD->GetYaxis()->SetRangeUser(0.0, 1);

    hAOD ->Draw("E1");        // points + barres d'erreur
    hMini->Draw("E1 SAME");
    latex1->Draw();

    // Légende
    TLegend* leg = new TLegend(0.4, 0.20, 0.80, 0.45);
    leg->SetBorderSize(0);
    leg->SetFillStyle(0);
    leg->SetTextSize(0.04);
    leg->AddEntry(hAOD,  "AOD (RecoCalo MET)",     "lpe");
    leg->AddEntry(hMini, "MiniAOD (Pseudo MET)", "lpe");
    leg->SetTextFont(42);
    leg->Draw();


    c->cd();
    TPad *pad2 = new TPad("pad2", "pad2", 0, 0, 1, 0.3);
    pad2->SetTopMargin(0); pad2->SetLeftMargin(0.16);
    pad2->SetBottomMargin(0.3);
    pad2->Draw();
    pad2->cd();

    TH1D *hRatio = (TH1D*)hAOD->Clone("C_over_D");
    hRatio->Divide(hMini);
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
    TLine *line = new TLine(hRatio->GetXaxis()->GetXmin(), 1, 1500, 1);
    line->SetLineStyle(2);
    gStyle->SetOptStat(0);
    line->Draw("same");
    hRatio->GetYaxis()->SetTitle("AOD/MiniAOD");
    hRatio->GetXaxis()->SetTitle("Calo MET or Pseudo MET (GeV)");
    hRatio->SetMinimum(0.9);
    hRatio->SetMaximum(1.1);

    c->SaveAs("AOD_vs_miniAOD.pdf");
    latex1->SetTitle("#it{Private work (CMS simulation)}");
    c->Modified();
    c->Update();
    c->SaveAs("AOD_vs_miniAOD_bis.pdf");


    return;
}