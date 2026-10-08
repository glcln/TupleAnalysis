#ifdef __CLING__
#pragma cling optimize(0)
#endif
void summary_binned_syst_JetMET2024_V12p35_Eta1()
{
//=========Macro generated from canvas: c2_141/c2
//=========  (Tue Sep 29 15:02:15 2026) by ROOT version 6.32.13
   TCanvas *c2_141 = new TCanvas("c2_141", "c2",0,0,800,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c2_141->SetHighLightColor(2);
   c2_141->Range(-470.5883,-1.690817,4235.294,4.065992);
   c2_141->SetFillColor(0);
   c2_141->SetBorderMode(0);
   c2_141->SetBorderSize(2);
   c2_141->SetLogy();
   c2_141->SetGridx();
   c2_141->SetGridy();
   c2_141->SetRightMargin(0.05);
   c2_141->SetTopMargin(0.05);
   c2_141->SetBottomMargin(0.12);
   c2_141->SetFrameLineWidth(2);
   c2_141->SetFrameBorderMode(0);
   c2_141->SetFrameLineWidth(2);
   c2_141->SetFrameBorderMode(0);
   
   TH1D *frameSummary_142__1 = new TH1D("frameSummary_142__1","",1,0,4000);
   frameSummary_142__1->SetMinimum(0.1);
   frameSummary_142__1->SetMaximum(6000);
   frameSummary_142__1->SetDirectory(nullptr);
   frameSummary_142__1->SetStats(0);
   frameSummary_142__1->SetLineWidth(2);
   frameSummary_142__1->SetMarkerStyle(20);
   frameSummary_142__1->SetMarkerSize(0.9);
   frameSummary_142__1->GetXaxis()->SetTitle("Mass (GeV)");
   frameSummary_142__1->GetXaxis()->SetLabelFont(43);
   frameSummary_142__1->GetXaxis()->SetLabelOffset(0.015);
   frameSummary_142__1->GetXaxis()->SetLabelSize(24);
   frameSummary_142__1->GetXaxis()->SetTitleSize(0.05);
   frameSummary_142__1->GetXaxis()->SetTitleOffset(1);
   frameSummary_142__1->GetXaxis()->SetTitleFont(42);
   frameSummary_142__1->GetYaxis()->SetTitle("Systematic Uncertainty [%]");
   frameSummary_142__1->GetYaxis()->SetLabelFont(43);
   frameSummary_142__1->GetYaxis()->SetLabelOffset(0.015);
   frameSummary_142__1->GetYaxis()->SetLabelSize(24);
   frameSummary_142__1->GetYaxis()->SetTitleSize(0.05);
   frameSummary_142__1->GetYaxis()->SetTickLength(0.02);
   frameSummary_142__1->GetYaxis()->SetTitleOffset(1);
   frameSummary_142__1->GetYaxis()->SetTitleFont(42);
   frameSummary_142__1->GetZaxis()->SetLabelFont(42);
   frameSummary_142__1->GetZaxis()->SetLabelOffset(0.015);
   frameSummary_142__1->GetZaxis()->SetLabelSize(0.05);
   frameSummary_142__1->GetZaxis()->SetTitleSize(0.065);
   frameSummary_142__1->GetZaxis()->SetTitleOffset(1.1);
   frameSummary_142__1->GetZaxis()->SetTitleFont(42);
   frameSummary_142__1->Draw("AXIS");
   
   TH1D *frameSummary_142__2 = new TH1D("frameSummary_142__2","",1,0,4000);
   frameSummary_142__2->SetMinimum(0.1);
   frameSummary_142__2->SetMaximum(6000);
   frameSummary_142__2->SetDirectory(nullptr);
   frameSummary_142__2->SetStats(0);
   frameSummary_142__2->SetLineWidth(2);
   frameSummary_142__2->SetMarkerStyle(20);
   frameSummary_142__2->SetMarkerSize(0.9);
   frameSummary_142__2->GetXaxis()->SetTitle("Mass (GeV)");
   frameSummary_142__2->GetXaxis()->SetLabelFont(43);
   frameSummary_142__2->GetXaxis()->SetLabelOffset(0.015);
   frameSummary_142__2->GetXaxis()->SetLabelSize(24);
   frameSummary_142__2->GetXaxis()->SetTitleSize(0.05);
   frameSummary_142__2->GetXaxis()->SetTitleOffset(1);
   frameSummary_142__2->GetXaxis()->SetTitleFont(42);
   frameSummary_142__2->GetYaxis()->SetTitle("Systematic Uncertainty [%]");
   frameSummary_142__2->GetYaxis()->SetLabelFont(43);
   frameSummary_142__2->GetYaxis()->SetLabelOffset(0.015);
   frameSummary_142__2->GetYaxis()->SetLabelSize(24);
   frameSummary_142__2->GetYaxis()->SetTitleSize(0.05);
   frameSummary_142__2->GetYaxis()->SetTickLength(0.02);
   frameSummary_142__2->GetYaxis()->SetTitleOffset(1);
   frameSummary_142__2->GetYaxis()->SetTitleFont(42);
   frameSummary_142__2->GetZaxis()->SetLabelFont(42);
   frameSummary_142__2->GetZaxis()->SetLabelOffset(0.015);
   frameSummary_142__2->GetZaxis()->SetLabelSize(0.05);
   frameSummary_142__2->GetZaxis()->SetTitleSize(0.065);
   frameSummary_142__2->GetZaxis()->SetTitleOffset(1.1);
   frameSummary_142__2->GetZaxis()->SetTitleFont(42);
   frameSummary_142__2->Draw("SAME AXIG");
   
   Double_t Graph_fx1[35] = { 10, 30, 50, 70, 90, 110, 130, 150, 170, 190, 210, 230, 250, 270, 290, 310, 330,
   350, 370, 395, 425, 460, 505, 560, 625, 710, 820, 955, 1120, 1325, 1585, 1865, 2250,
   2850, 3600 };
   Double_t Graph_fy1[35] = { 1.23721, 1.004298, 0.9610371, 0.9726334, 1.003506, 1.044649, 1.084399, 1.154261, 1.296514, 1.432063, 1.783235, 1.911399, 2.186331, 2.584338, 2.549521, 2.827125, 3.438846,
   3.562358, 3.717253, 3.322426, 3.538356, 3.393096, 3.280664, 3.458597, 3.586574, 3.744398, 4.61542, 4.73689, 5.494118, 6.434983, 8.010533, 9.797618, 11.70566,
   13.99291, 24.2522 };
   TGraph *graph = new TGraph(35,Graph_fx1,Graph_fy1);
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillColor(1);
   graph->SetFillStyle(1000);
   graph->SetMarkerStyle(20);
   graph->SetMarkerSize(1.2);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","",100,0,3959);
   Graph_Graph1->SetMinimum(0.8649334);
   Graph_Graph1->SetMaximum(26.58132);
   Graph_Graph1->SetDirectory(nullptr);
   Graph_Graph1->SetStats(0);
   Graph_Graph1->SetLineWidth(2);
   Graph_Graph1->SetMarkerStyle(20);
   Graph_Graph1->SetMarkerSize(0.9);
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   Graph_Graph1->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph1->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph1->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph1->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph1->GetXaxis()->SetTitleFont(42);
   Graph_Graph1->GetYaxis()->SetLabelFont(42);
   Graph_Graph1->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph1->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph1->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph1->GetYaxis()->SetTickLength(0.02);
   Graph_Graph1->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph1->GetYaxis()->SetTitleFont(42);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph1->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph1->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph1->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph1);
   
   graph->Draw("p");
   
   Double_t Graph_fx2[35] = { 10, 30, 50, 70, 90, 110, 130, 150, 170, 190, 210, 230, 250, 270, 290, 310, 330,
   350, 370, 395, 425, 460, 505, 560, 625, 710, 820, 955, 1120, 1325, 1585, 1865, 2250,
   2850, 3600 };
   Double_t Graph_fy2[35] = { 0.2123244, 0.2299215, 0.1486656, 0.2301411, 0.2967399, 0.3339287, 0.4395324, 0.6078133, 0.5131796, 0.7360211, 0.7929932, 1.046829, 1.205877, 1.316036, 1.541818, 2.437197, 2.710931,
   3.680685, 3.862813, 4.611793, 5.771897, 5.735746, 6.234623, 6.284938, 7.718498, 7.752992, 8.189846, 9.262228, 8.592614, 9.507101, 7.43647, 7.928367, 6.151882,
   1.674394, 2.3916 };
   graph = new TGraph(35,Graph_fx2,Graph_fy2);
   graph->SetName("");
   graph->SetTitle("");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff99ff");
   graph->SetFillColor(ci);
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#ff99ff");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#ff99ff");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(21);
   graph->SetMarkerSize(1.2);
   
   TH1F *Graph_Graph2 = new TH1F("Graph_Graph2","",100,0,3959);
   Graph_Graph2->SetMinimum(0.1337991);
   Graph_Graph2->SetMaximum(10.44294);
   Graph_Graph2->SetDirectory(nullptr);
   Graph_Graph2->SetStats(0);
   Graph_Graph2->SetLineWidth(2);
   Graph_Graph2->SetMarkerStyle(20);
   Graph_Graph2->SetMarkerSize(0.9);
   Graph_Graph2->GetXaxis()->SetLabelFont(42);
   Graph_Graph2->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph2->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph2->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph2->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph2->GetXaxis()->SetTitleFont(42);
   Graph_Graph2->GetYaxis()->SetLabelFont(42);
   Graph_Graph2->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph2->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph2->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph2->GetYaxis()->SetTickLength(0.02);
   Graph_Graph2->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph2->GetYaxis()->SetTitleFont(42);
   Graph_Graph2->GetZaxis()->SetLabelFont(42);
   Graph_Graph2->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph2->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph2->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph2->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph2->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph2);
   
   graph->Draw("p");
   
   Double_t Graph_fx3[35] = { 10, 30, 50, 70, 90, 110, 130, 150, 170, 190, 210, 230, 250, 270, 290, 310, 330,
   350, 370, 395, 425, 460, 505, 560, 625, 710, 820, 955, 1120, 1325, 1585, 1865, 2250,
   2850, 3600 };
   Double_t Graph_fy3[35] = { 1.55839, 0.527219, 0.2554984, 1.775975, 2.801475, 0.8610873, 2.368458, 6.328436, 15.59548, 12.36496, 4.060525, 6.584293, 8.307661, 31.93686, 6.133362, 22.86595, 5.411086,
   8.846137, 7.595142, 10.46666, 3.96613, 9.056915, 5.80211, 5.476159, 0.9163867, 7.27411, 10.05219, 14.927, 6.869346, 5.501774, 9.167536, 21.02325, 7.50364,
   13.06414, 22.12906 };
   graph = new TGraph(35,Graph_fx3,Graph_fy3);
   graph->SetName("");
   graph->SetTitle("");

   ci = TColor::GetColor("#9933ff");
   graph->SetFillColor(ci);
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#9933ff");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#9933ff");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(22);
   graph->SetMarkerSize(1.2);
   
   TH1F *Graph_Graph3 = new TH1F("Graph_Graph3","",100,0,3959);
   Graph_Graph3->SetMinimum(0.2299486);
   Graph_Graph3->SetMaximum(35.10499);
   Graph_Graph3->SetDirectory(nullptr);
   Graph_Graph3->SetStats(0);
   Graph_Graph3->SetLineWidth(2);
   Graph_Graph3->SetMarkerStyle(20);
   Graph_Graph3->SetMarkerSize(0.9);
   Graph_Graph3->GetXaxis()->SetLabelFont(42);
   Graph_Graph3->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph3->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph3->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph3->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph3->GetXaxis()->SetTitleFont(42);
   Graph_Graph3->GetYaxis()->SetLabelFont(42);
   Graph_Graph3->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph3->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph3->GetYaxis()->SetTickLength(0.02);
   Graph_Graph3->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph3->GetYaxis()->SetTitleFont(42);
   Graph_Graph3->GetZaxis()->SetLabelFont(42);
   Graph_Graph3->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph3->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph3->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph3->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph3);
   
   graph->Draw("p");
   
   Double_t Graph_fx4[35] = { 10, 30, 50, 70, 90, 110, 130, 150, 170, 190, 210, 230, 250, 270, 290, 310, 330,
   350, 370, 395, 425, 460, 505, 560, 625, 710, 820, 955, 1120, 1325, 1585, 1865, 2250,
   2850, 3600 };
   Double_t Graph_fy4[35] = { 0.154704, 0.3712215, 0.2165747, 0.2363188, 2.942382, 4.30189, 1.306155, 3.418031, 1.834004, 6.872419, 7.2622, 4.551312, 18.64007, 14.57497, 20.28148, 17.45971, 20.04004,
   34.63034, 35.67547, 34.47636, 41.84712, 37.99666, 36.50835, 40.98039, 58.52999, 34.05886, 42.67309, 66.85471, 43.60253, 74.58412, 71.98315, 91.16208, 46.15633,
   44.53156, 29.40237 };
   graph = new TGraph(35,Graph_fx4,Graph_fy4);
   graph->SetName("");
   graph->SetTitle("");

   ci = TColor::GetColor("#0000cc");
   graph->SetFillColor(ci);
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#0000cc");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#0000cc");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(23);
   graph->SetMarkerSize(1.2);
   
   TH1F *Graph_Graph4 = new TH1F("Graph_Graph4","",100,0,3959);
   Graph_Graph4->SetMinimum(0.1392336);
   Graph_Graph4->SetMaximum(100.2628);
   Graph_Graph4->SetDirectory(nullptr);
   Graph_Graph4->SetStats(0);
   Graph_Graph4->SetLineWidth(2);
   Graph_Graph4->SetMarkerStyle(20);
   Graph_Graph4->SetMarkerSize(0.9);
   Graph_Graph4->GetXaxis()->SetLabelFont(42);
   Graph_Graph4->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph4->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph4->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph4->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph4->GetXaxis()->SetTitleFont(42);
   Graph_Graph4->GetYaxis()->SetLabelFont(42);
   Graph_Graph4->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph4->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph4->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph4->GetYaxis()->SetTickLength(0.02);
   Graph_Graph4->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph4->GetYaxis()->SetTitleFont(42);
   Graph_Graph4->GetZaxis()->SetLabelFont(42);
   Graph_Graph4->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph4->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph4->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph4->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph4->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph4);
   
   graph->Draw("p");
   
   Double_t Graph_fx5[35] = { 10, 30, 50, 70, 90, 110, 130, 150, 170, 190, 210, 230, 250, 270, 290, 310, 330,
   350, 370, 395, 425, 460, 505, 560, 625, 710, 820, 955, 1120, 1325, 1585, 1865, 2250,
   2850, 3600 };
   Double_t Graph_fy5[35] = { 0.09486052, 0.09487366, 0.05091159, 0.09148769, 0.1846592, 0.2559573, 0.298585, 0.3246989, 0.3755565, 0.3766524, 0.4555398, 0.413771, 0.4671995, 0.5511483, 0.5370663, 0.5822406, 0.6556233,
   0.5779006, 0.6467308, 0.6899563, 0.7192448, 0.7366047, 0.9529088, 0.9596278, 1.142497, 1.252328, 1.303987, 1.68485, 1.616056, 2.656781, 2.581131, 3.149378, 3.322234,
   4.124581, 6.494597 };
   graph = new TGraph(35,Graph_fx5,Graph_fy5);
   graph->SetName("");
   graph->SetTitle("");

   ci = TColor::GetColor("#ff9933");
   graph->SetFillColor(ci);
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#ff9933");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#ff9933");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(33);
   graph->SetMarkerSize(1.2);
   
   TH1F *Graph_Graph5 = new TH1F("Graph_Graph5","",100,0,3959);
   Graph_Graph5->SetMinimum(0.04582043);
   Graph_Graph5->SetMaximum(7.138965);
   Graph_Graph5->SetDirectory(nullptr);
   Graph_Graph5->SetStats(0);
   Graph_Graph5->SetLineWidth(2);
   Graph_Graph5->SetMarkerStyle(20);
   Graph_Graph5->SetMarkerSize(0.9);
   Graph_Graph5->GetXaxis()->SetLabelFont(42);
   Graph_Graph5->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph5->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph5->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph5->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph5->GetXaxis()->SetTitleFont(42);
   Graph_Graph5->GetYaxis()->SetLabelFont(42);
   Graph_Graph5->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph5->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph5->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph5->GetYaxis()->SetTickLength(0.02);
   Graph_Graph5->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph5->GetYaxis()->SetTitleFont(42);
   Graph_Graph5->GetZaxis()->SetLabelFont(42);
   Graph_Graph5->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph5->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph5->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph5->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph5->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph5);
   
   graph->Draw("p");
   
   Double_t Graph_fx6[35] = { 10, 30, 50, 70, 90, 110, 130, 150, 170, 190, 210, 230, 250, 270, 290, 310, 330,
   350, 370, 395, 425, 460, 505, 560, 625, 710, 820, 955, 1120, 1325, 1585, 1865, 2250,
   2850, 3600 };
   Double_t Graph_fy6[35] = { 0.03029178, 0.03029088, 0.02960853, 0.02589552, 0.02104488, 0.01248229, 0.01194847, 0.06472295, 0.152692, 0.2859853, 0.5954221, 0.8129702, 1.318574, 2.101677, 2.659723, 3.575337, 4.303042,
   5.66618, 6.53325, 8.292549, 9.5576, 11.57183, 13.94455, 16.63276, 19.11249, 22.64296, 26.85092, 31.00132, 36.24706, 42.57337, 49.87431, 57.19687, 65.3869,
   76.04135, 87.67339 };
   graph = new TGraph(35,Graph_fx6,Graph_fy6);
   graph->SetName("");
   graph->SetTitle("");

   ci = TColor::GetColor("#00ffff");
   graph->SetFillColor(ci);
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#00ffff");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#00ffff");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(29);
   graph->SetMarkerSize(1.2);
   
   TH1F *Graph_Graph6 = new TH1F("Graph_Graph6","",100,0,3959);
   Graph_Graph6->SetMinimum(0.01075362);
   Graph_Graph6->SetMaximum(96.43953);
   Graph_Graph6->SetDirectory(nullptr);
   Graph_Graph6->SetStats(0);
   Graph_Graph6->SetLineWidth(2);
   Graph_Graph6->SetMarkerStyle(20);
   Graph_Graph6->SetMarkerSize(0.9);
   Graph_Graph6->GetXaxis()->SetLabelFont(42);
   Graph_Graph6->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph6->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph6->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph6->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph6->GetXaxis()->SetTitleFont(42);
   Graph_Graph6->GetYaxis()->SetLabelFont(42);
   Graph_Graph6->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph6->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph6->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph6->GetYaxis()->SetTickLength(0.02);
   Graph_Graph6->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph6->GetYaxis()->SetTitleFont(42);
   Graph_Graph6->GetZaxis()->SetLabelFont(42);
   Graph_Graph6->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph6->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph6->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph6->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph6->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph6);
   
   graph->Draw("p");
   
   Double_t Graph_fx7[35] = { 10, 30, 50, 70, 90, 110, 130, 150, 170, 190, 210, 230, 250, 270, 290, 310, 330,
   350, 370, 395, 425, 460, 505, 560, 625, 710, 820, 955, 1120, 1325, 1585, 1865, 2250,
   2850, 3600 };
   Double_t Graph_fy7[35] = { 1.410225, 0.5269774, 0.2631174, 0.5904216, 0.7495232, 0.8338187, 0.9589354, 0.9845635, 1.080526, 1.140972, 1.280919, 1.204427, 1.235783, 1.26849, 1.223035, 1.341219, 1.526007,
   1.041654, 1.612961, 1.520963, 1.657558, 1.498637, 1.771469, 1.767009, 2.088489, 2.038021, 2.055419, 2.330047, 2.193926, 2.317181, 1.949842, 1.8322, 1.198937,
   0.06640189, 1.869342 };
   graph = new TGraph(35,Graph_fx7,Graph_fy7);
   graph->SetName("");
   graph->SetTitle("");

   ci = TColor::GetColor("#ffcc00");
   graph->SetFillColor(ci);
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#ffcc00");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#ffcc00");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(39);
   graph->SetMarkerSize(1.2);
   
   TH1F *Graph_Graph7 = new TH1F("Graph_Graph7","",100,0,3959);
   Graph_Graph7->SetMinimum(0.0597617);
   Graph_Graph7->SetMaximum(2.556411);
   Graph_Graph7->SetDirectory(nullptr);
   Graph_Graph7->SetStats(0);
   Graph_Graph7->SetLineWidth(2);
   Graph_Graph7->SetMarkerStyle(20);
   Graph_Graph7->SetMarkerSize(0.9);
   Graph_Graph7->GetXaxis()->SetLabelFont(42);
   Graph_Graph7->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph7->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph7->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph7->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph7->GetXaxis()->SetTitleFont(42);
   Graph_Graph7->GetYaxis()->SetLabelFont(42);
   Graph_Graph7->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph7->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph7->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph7->GetYaxis()->SetTickLength(0.02);
   Graph_Graph7->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph7->GetYaxis()->SetTitleFont(42);
   Graph_Graph7->GetZaxis()->SetLabelFont(42);
   Graph_Graph7->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph7->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph7->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph7->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph7->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph7);
   
   graph->Draw("p");
   
   Double_t Graph_fx8[35] = { 10, 30, 50, 70, 90, 110, 130, 150, 170, 190, 210, 230, 250, 270, 290, 310, 330,
   350, 370, 395, 425, 460, 505, 560, 625, 710, 820, 955, 1120, 1325, 1585, 1865, 2250,
   2850, 3600 };
   Double_t Graph_fy8[35] = { 1.244608, 1.091636, 0.1593844, 0.9791206, 1.775769, 2.353145, 2.766075, 3.070478, 3.285179, 3.434351, 3.435473, 3.674735, 3.71623, 3.771401, 3.719621, 3.969103, 3.62052,
   4.526436, 3.870269, 3.659377, 3.744753, 3.873503, 3.497617, 3.484072, 3.350957, 3.133989, 2.849883, 2.560213, 2.209679, 1.77658, 1.35102, 0.8888526, 0.52819,
   0.01966929, 0.6997445 };
   graph = new TGraph(35,Graph_fx8,Graph_fy8);
   graph->SetName("");
   graph->SetTitle("");

   ci = TColor::GetColor("#009900");
   graph->SetFillColor(ci);
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#009900");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#009900");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(30);
   graph->SetMarkerSize(1.2);
   
   TH1F *Graph_Graph8 = new TH1F("Graph_Graph8","",100,0,3959);
   Graph_Graph8->SetMinimum(0.01770236);
   Graph_Graph8->SetMaximum(4.977113);
   Graph_Graph8->SetDirectory(nullptr);
   Graph_Graph8->SetStats(0);
   Graph_Graph8->SetLineWidth(2);
   Graph_Graph8->SetMarkerStyle(20);
   Graph_Graph8->SetMarkerSize(0.9);
   Graph_Graph8->GetXaxis()->SetLabelFont(42);
   Graph_Graph8->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph8->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph8->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph8->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph8->GetXaxis()->SetTitleFont(42);
   Graph_Graph8->GetYaxis()->SetLabelFont(42);
   Graph_Graph8->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph8->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph8->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph8->GetYaxis()->SetTickLength(0.02);
   Graph_Graph8->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph8->GetYaxis()->SetTitleFont(42);
   Graph_Graph8->GetZaxis()->SetLabelFont(42);
   Graph_Graph8->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph8->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph8->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph8->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph8->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph8);
   
   graph->Draw("p");
   
   Double_t Graph_fx9[35] = { 10, 30, 50, 70, 90, 110, 130, 150, 170, 190, 210, 230, 250, 270, 290, 310, 330,
   350, 370, 395, 425, 460, 505, 560, 625, 710, 820, 955, 1120, 1325, 1585, 1865, 2250,
   2850, 3600 };
   Double_t Graph_fy9[35] = { 2.75245, 1.719458, 1.075165, 2.35058, 4.620675, 5.171919, 4.164705, 7.996287, 16.1447, 14.69814, 9.329601, 9.197995, 20.97613, 35.51558, 21.92094, 29.53473, 22.01001,
   36.84787, 37.68085, 37.62213, 43.83357, 41.49561, 40.33469, 45.31747, 62.29944, 42.60628, 52.39689, 76.00329, 58.12524, 86.9076, 88.79653, 110.4396, 81.54618,
   90.28644, 98.39142 };
   graph = new TGraph(35,Graph_fx9,Graph_fy9);
   graph->SetName("");
   graph->SetTitle("");

   ci = TColor::GetColor("#ff0000");
   graph->SetFillColor(ci);
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#ff0000");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#ff0000");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(34);
   graph->SetMarkerSize(1.2);
   
   TH1F *Graph_Graph9 = new TH1F("Graph_Graph9","",100,0,3959);
   Graph_Graph9->SetMinimum(0.9676489);
   Graph_Graph9->SetMaximum(121.376);
   Graph_Graph9->SetDirectory(nullptr);
   Graph_Graph9->SetStats(0);
   Graph_Graph9->SetLineWidth(2);
   Graph_Graph9->SetMarkerStyle(20);
   Graph_Graph9->SetMarkerSize(0.9);
   Graph_Graph9->GetXaxis()->SetLabelFont(42);
   Graph_Graph9->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph9->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph9->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph9->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph9->GetXaxis()->SetTitleFont(42);
   Graph_Graph9->GetYaxis()->SetLabelFont(42);
   Graph_Graph9->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph9->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph9->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph9->GetYaxis()->SetTickLength(0.02);
   Graph_Graph9->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph9->GetYaxis()->SetTitleFont(42);
   Graph_Graph9->GetZaxis()->SetLabelFont(42);
   Graph_Graph9->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph9->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph9->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph9->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph9->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph9);
   
   graph->Draw("p");
   
   TLegend *leg = new TLegend(0.12,0.7,0.55,0.93,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextFont(62);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("","Total","PE1");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#ff0000");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(34);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(62);
   entry=leg->AddEntry("","Stat.","PE1");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(62);
   entry=leg->AddEntry("","#eta binning","PE1");

   ci = TColor::GetColor("#ff99ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#ff99ff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(62);
   entry=leg->AddEntry("","I_{h} binning","PE1");

   ci = TColor::GetColor("#9933ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#9933ff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(22);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(62);
   entry=leg->AddEntry("","p binning","PE1");

   ci = TColor::GetColor("#0000cc");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#0000cc");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(23);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(62);
   entry=leg->AddEntry("","I_{h} fit","PE1");

   ci = TColor::GetColor("#ff9933");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#ff9933");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(33);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(62);
   entry=leg->AddEntry("","p fit","PE1");

   ci = TColor::GetColor("#00ffff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#00ffff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(29);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(62);
   entry=leg->AddEntry("","corr template I_{h}","PE1");

   ci = TColor::GetColor("#ffcc00");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#ffcc00");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(39);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(62);
   entry=leg->AddEntry("","corr template 1/p","PE1");

   ci = TColor::GetColor("#009900");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#009900");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(30);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(62);
   leg->Draw();
   TLatex *   tex = new TLatex(0.1,0.96,"#scale[1.3]{#it{Private work (CMS data)}}");
   tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.735,0.96,"109 fb^{-1} (13.6 TeV)");
   tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.8,0.88,"#bf{|#eta|<1}");
   tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.07);
   tex->SetLineWidth(2);
   tex->Draw();
   c2_141->Modified();
   c2_141->SetSelected(c2_141);
}
