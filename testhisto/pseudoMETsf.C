// plot_pseudomet_sf.C
// Macro ROOT : Scale Factors en fonction du bin PseudoMET, sous forme d'histogramme
// avec bande d'incertitude (SF_down / SF_up).
// Usage : root -l 'plot_pseudomet_sf.C("pseudomet_sf.csv")'

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

void pseudoMETsf(const char* csvFile = "pseudomet_sf.csv")
{
    // ----------------------------------------------------------------
    // 1. Lecture du CSV
    // ----------------------------------------------------------------
    std::vector<double> bins, sf, sf_down, sf_up;

    std::ifstream fin(csvFile);
    if (!fin.is_open()) {
        std::cerr << "ERROR: cannot open " << csvFile << std::endl;
        return;
    }

    std::string line;
    std::getline(fin, line); // skip header

    while (std::getline(fin, line)) {
        if (line.empty()) continue;
        std::istringstream ss(line);
        std::string tok;
        std::vector<double> vals;
        while (std::getline(ss, tok, ','))
            vals.push_back(std::stod(tok));
        if (vals.size() < 4) continue;
        bins.push_back(vals[0]);
        sf_down.push_back(vals[1]);
        sf.push_back(vals[2]);
        sf_up.push_back(vals[3]);
    }
    fin.close();

    int N = (int)bins.size();

    // ----------------------------------------------------------------
    // 2. Construction des bin edges (largeur fixe 25 GeV)
    // ----------------------------------------------------------------
    const double binWidth = 25.0;
    std::vector<double> edges(N + 1);
    for (int i = 0; i < N; ++i)
        edges[i] = bins[i];
    edges[N] = bins[N-1] + binWidth;

    // ----------------------------------------------------------------
    // 3. Création des histogrammes
    // ----------------------------------------------------------------
    TH1D* hSF   = new TH1D("hSF",   ";PseudoMET bin [GeV];Scale Factor", N, edges.data());
    TH1D* hUp   = new TH1D("hUp",   ";PseudoMET bin [GeV];Scale Factor", N, edges.data());
    TH1D* hDown = new TH1D("hDown", ";PseudoMET bin [GeV];Scale Factor", N, edges.data());

    for (int i = 0; i < N; ++i) {
        hSF  ->SetBinContent(i+1, sf[i]);
        hUp  ->SetBinContent(i+1, sf_up[i]);
        hDown->SetBinContent(i+1, sf_down[i]);
        // Pas d'erreur stat (les erreurs sont encodées dans up/down)
        hSF  ->SetBinError(i+1, 0.);
        hUp  ->SetBinError(i+1, 0.);
        hDown->SetBinError(i+1, 0.);
    }

    // ----------------------------------------------------------------
    // 4. Histogramme de bande d'incertitude : hBand = hUp - hDown
    //    On utilisera "E2" pour remplir entre hDown et hUp via une astuce :
    //    on crée hBand avec contenu = (up+down)/2 et erreur = (up-down)/2
    // ----------------------------------------------------------------
    TH1D* hBand = (TH1D*)hSF->Clone("hBand");
    for (int i = 1; i <= N; ++i) {
        double up   = hUp  ->GetBinContent(i);
        double down = hDown->GetBinContent(i);
        hBand->SetBinContent(i, (up + down) / 2.0);
        hBand->SetBinError  (i, (up - down) / 2.0);
    }

    // ----------------------------------------------------------------
    // 5. Style
    // ----------------------------------------------------------------
    hBand->SetFillColor(kAzure - 9);
    hBand->SetFillStyle(1001);
    hBand->SetLineColor(kAzure - 9);
    hBand->SetMarkerSize(0);

    hUp->SetLineColor(kAzure + 1);
    hUp->SetLineStyle(2);
    hUp->SetLineWidth(2);

    hDown->SetLineColor(kAzure + 1);
    hDown->SetLineStyle(2);
    hDown->SetLineWidth(2);

    hSF->SetLineColor(kBlue + 1);
    hSF->SetLineWidth(2);
    hSF->SetMarkerStyle(20);
    hSF->SetMarkerSize(0.9);
    hSF->SetMarkerColor(kBlue + 1);

    // ----------------------------------------------------------------
    // 6. Canvas et dessin
    // ----------------------------------------------------------------
    TCanvas* c = new TCanvas("c_sf", "PseudoMET Scale Factors", 800, 600);
    c->SetLeftMargin(0.16);
    c->SetBottomMargin(0.16);
    c->SetGrid();

    hBand->SetTitle(";PseudoMET bin [GeV];Scale Factor");
    hBand->GetYaxis()->SetTitleSize(0.06);
    hBand->GetXaxis()->SetTitleSize(0.06);
    hBand->GetXaxis()->SetTitleOffset(0.9);
    hBand->GetYaxis()->SetTitleOffset(1);
    hBand->GetXaxis()->SetLabelSize(0.05);
    hBand->GetYaxis()->SetLabelSize(0.05);
    hBand->GetYaxis()->SetRangeUser(0.0, 2);

    hBand->Draw("E2");       // bande remplie
    hUp  ->Draw("HIST same");
    hDown->Draw("HIST same");
    hSF  ->Draw("HIST P same");

    gStyle->SetOptStat(0);

    TLatex *latex1 = new TLatex(0.16, 0.91, "#scale[1.3]{#bf{CMS}}#it{Simulation Work in progress}");
    latex1->SetNDC();
    latex1->SetTextFont(42);
    latex1->SetTextSize(0.04);
    latex1->Draw();

    // Ligne SF = 1
    TLine* line1 = new TLine(edges[0], 1.0, edges[N], 1.0);
    line1->SetLineColor(kBlack);
    line1->SetLineStyle(2);
    line1->SetLineWidth(2);
    line1->Draw();

    c->Update();
    c->SaveAs("pseudomet_sf.pdf");
    latex1->SetTitle("#it{Private work (CMS simulation)}");
    c->Modified();
    c->Update();
    c->SaveAs("pseudomet_sf_bis.pdf");

    return;
}