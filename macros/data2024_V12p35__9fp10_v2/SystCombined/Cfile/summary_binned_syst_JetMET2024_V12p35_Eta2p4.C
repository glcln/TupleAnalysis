#ifdef __CLING__
#pragma cling optimize(0)
#endif
void summary_binned_syst_JetMET2024_V12p35_Eta2p4()
{
//=========Macro generated from canvas: c2_283/c2
//=========  (Tue Sep 29 15:02:15 2026) by ROOT version 6.32.13
   TCanvas *c2_283 = new TCanvas("c2_283", "c2",0,0,800,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c2_283->SetHighLightColor(2);
   c2_283->Range(-470.5883,-1.690817,4235.294,4.065992);
   c2_283->SetFillColor(0);
   c2_283->SetBorderMode(0);
   c2_283->SetBorderSize(2);
   c2_283->SetLogy();
   c2_283->SetGridx();
   c2_283->SetGridy();
   c2_283->SetRightMargin(0.05);
   c2_283->SetTopMargin(0.05);
   c2_283->SetBottomMargin(0.12);
   c2_283->SetFrameLineWidth(2);
   c2_283->SetFrameBorderMode(0);
   c2_283->SetFrameLineWidth(2);
   c2_283->SetFrameBorderMode(0);
   
   TH1D *frameSummary_284__3 = new TH1D("frameSummary_284__3","",1,0,4000);
   frameSummary_284__3->SetMinimum(0.1);
   frameSummary_284__3->SetMaximum(6000);
   frameSummary_284__3->SetDirectory(nullptr);
   frameSummary_284__3->SetStats(0);
   frameSummary_284__3->SetLineWidth(2);
   frameSummary_284__3->SetMarkerStyle(20);
   frameSummary_284__3->SetMarkerSize(0.9);
   frameSummary_284__3->GetXaxis()->SetTitle("Mass (GeV)");
   frameSummary_284__3->GetXaxis()->SetLabelFont(43);
   frameSummary_284__3->GetXaxis()->SetLabelOffset(0.015);
   frameSummary_284__3->GetXaxis()->SetLabelSize(24);
   frameSummary_284__3->GetXaxis()->SetTitleSize(0.05);
   frameSummary_284__3->GetXaxis()->SetTitleOffset(1);
   frameSummary_284__3->GetXaxis()->SetTitleFont(42);
   frameSummary_284__3->GetYaxis()->SetTitle("Systematic Uncertainty [%]");
   frameSummary_284__3->GetYaxis()->SetLabelFont(43);
   frameSummary_284__3->GetYaxis()->SetLabelOffset(0.015);
   frameSummary_284__3->GetYaxis()->SetLabelSize(24);
   frameSummary_284__3->GetYaxis()->SetTitleSize(0.05);
   frameSummary_284__3->GetYaxis()->SetTickLength(0.02);
   frameSummary_284__3->GetYaxis()->SetTitleOffset(1);
   frameSummary_284__3->GetYaxis()->SetTitleFont(42);
   frameSummary_284__3->GetZaxis()->SetLabelFont(42);
   frameSummary_284__3->GetZaxis()->SetLabelOffset(0.015);
   frameSummary_284__3->GetZaxis()->SetLabelSize(0.05);
   frameSummary_284__3->GetZaxis()->SetTitleSize(0.065);
   frameSummary_284__3->GetZaxis()->SetTitleOffset(1.1);
   frameSummary_284__3->GetZaxis()->SetTitleFont(42);
   frameSummary_284__3->Draw("AXIS");
   
   TH1D *frameSummary_284__4 = new TH1D("frameSummary_284__4","",1,0,4000);
   frameSummary_284__4->SetMinimum(0.1);
   frameSummary_284__4->SetMaximum(6000);
   frameSummary_284__4->SetDirectory(nullptr);
   frameSummary_284__4->SetStats(0);
   frameSummary_284__4->SetLineWidth(2);
   frameSummary_284__4->SetMarkerStyle(20);
   frameSummary_284__4->SetMarkerSize(0.9);
   frameSummary_284__4->GetXaxis()->SetTitle("Mass (GeV)");
   frameSummary_284__4->GetXaxis()->SetLabelFont(43);
   frameSummary_284__4->GetXaxis()->SetLabelOffset(0.015);
   frameSummary_284__4->GetXaxis()->SetLabelSize(24);
   frameSummary_284__4->GetXaxis()->SetTitleSize(0.05);
   frameSummary_284__4->GetXaxis()->SetTitleOffset(1);
   frameSummary_284__4->GetXaxis()->SetTitleFont(42);
   frameSummary_284__4->GetYaxis()->SetTitle("Systematic Uncertainty [%]");
   frameSummary_284__4->GetYaxis()->SetLabelFont(43);
   frameSummary_284__4->GetYaxis()->SetLabelOffset(0.015);
   frameSummary_284__4->GetYaxis()->SetLabelSize(24);
   frameSummary_284__4->GetYaxis()->SetTitleSize(0.05);
   frameSummary_284__4->GetYaxis()->SetTickLength(0.02);
   frameSummary_284__4->GetYaxis()->SetTitleOffset(1);
   frameSummary_284__4->GetYaxis()->SetTitleFont(42);
   frameSummary_284__4->GetZaxis()->SetLabelFont(42);
   frameSummary_284__4->GetZaxis()->SetLabelOffset(0.015);
   frameSummary_284__4->GetZaxis()->SetLabelSize(0.05);
   frameSummary_284__4->GetZaxis()->SetTitleSize(0.065);
   frameSummary_284__4->GetZaxis()->SetTitleOffset(1.1);
   frameSummary_284__4->GetZaxis()->SetTitleFont(42);
   frameSummary_284__4->Draw("SAME AXIG");
   
   Double_t Graph_fx10[35] = { 10, 30, 50, 70, 90, 110, 130, 150, 170, 190, 210, 230, 250, 270, 290, 310, 330,
   350, 370, 395, 425, 460, 505, 560, 625, 710, 820, 955, 1120, 1325, 1585, 1865, 2250,
   2850, 3600 };
   Double_t Graph_fy10[35] = { 1.255668, 0.9302778, 0.8252275, 0.7562697, 0.7689364, 0.8220322, 0.8804396, 0.9102363, 0.9720313, 1.010979, 1.13044, 1.175266, 1.234815, 1.336481, 1.379503, 1.449295, 1.773322,
   1.537611, 1.729964, 1.665454, 1.853156, 1.558037, 1.869165, 1.834945, 2.167578, 2.569335, 3.352608, 4.663485, 6.907327, 13.09244, 16.19254, 21.99653, 12.97546,
   19.26816, 60.13647 };
   TGraph *graph = new TGraph(35,Graph_fx10,Graph_fy10);
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillColor(1);
   graph->SetFillStyle(1000);
   graph->SetMarkerStyle(20);
   graph->SetMarkerSize(1.2);
   
   TH1F *Graph_Graph10 = new TH1F("Graph_Graph10","",100,0,3959);
   Graph_Graph10->SetMinimum(0.6806427);
   Graph_Graph10->SetMaximum(66.07449);
   Graph_Graph10->SetDirectory(nullptr);
   Graph_Graph10->SetStats(0);
   Graph_Graph10->SetLineWidth(2);
   Graph_Graph10->SetMarkerStyle(20);
   Graph_Graph10->SetMarkerSize(0.9);
   Graph_Graph10->GetXaxis()->SetLabelFont(42);
   Graph_Graph10->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph10->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph10->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph10->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph10->GetXaxis()->SetTitleFont(42);
   Graph_Graph10->GetYaxis()->SetLabelFont(42);
   Graph_Graph10->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph10->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph10->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph10->GetYaxis()->SetTickLength(0.02);
   Graph_Graph10->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph10->GetYaxis()->SetTitleFont(42);
   Graph_Graph10->GetZaxis()->SetLabelFont(42);
   Graph_Graph10->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph10->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph10->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph10->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph10->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph10);
   
   graph->Draw("p");
   
   Double_t Graph_fx11[35] = { 10, 30, 50, 70, 90, 110, 130, 150, 170, 190, 210, 230, 250, 270, 290, 310, 330,
   350, 370, 395, 425, 460, 505, 560, 625, 710, 820, 955, 1120, 1325, 1585, 1865, 2250,
   2850, 3600 };
   Double_t Graph_fy11[35] = { 0.3183241, 0.299915, 0.1357089, 0.07722393, 0.7418822, 0.6298646, 0.1462883, 0.3400114, 0.4833164, 1.011475, 1.173251, 1.559138, 1.084572, 2.170487, 1.093466, 2.085891, 2.479519,
   0.9140586, 2.227316, 2.984515, 4.130277, 2.450266, 3.415518, 2.397381, 4.521868, 5.255982, 4.901584, 9.805532, 17.42073, 39.63724, 38.62994, 72.77024, 56.52165,
   119.9264, 7.334965 };
   graph = new TGraph(35,Graph_fx11,Graph_fy11);
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
   
   TH1F *Graph_Graph11 = new TH1F("Graph_Graph11","",100,0,3959);
   Graph_Graph11->SetMinimum(0.06950154);
   Graph_Graph11->SetMaximum(131.9113);
   Graph_Graph11->SetDirectory(nullptr);
   Graph_Graph11->SetStats(0);
   Graph_Graph11->SetLineWidth(2);
   Graph_Graph11->SetMarkerStyle(20);
   Graph_Graph11->SetMarkerSize(0.9);
   Graph_Graph11->GetXaxis()->SetLabelFont(42);
   Graph_Graph11->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph11->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph11->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph11->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph11->GetXaxis()->SetTitleFont(42);
   Graph_Graph11->GetYaxis()->SetLabelFont(42);
   Graph_Graph11->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph11->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph11->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph11->GetYaxis()->SetTickLength(0.02);
   Graph_Graph11->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph11->GetYaxis()->SetTitleFont(42);
   Graph_Graph11->GetZaxis()->SetLabelFont(42);
   Graph_Graph11->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph11->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph11->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph11->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph11->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph11);
   
   graph->Draw("p");
   
   Double_t Graph_fx12[35] = { 10, 30, 50, 70, 90, 110, 130, 150, 170, 190, 210, 230, 250, 270, 290, 310, 330,
   350, 370, 395, 425, 460, 505, 560, 625, 710, 820, 955, 1120, 1325, 1585, 1865, 2250,
   2850, 3600 };
   Double_t Graph_fy12[35] = { 5.088418, 0.582132, 0.9563427, 2.745993, 3.316036, 2.055334, 2.713101, 7.799607, 17.18659, 12.79988, 8.114247, 7.909593, 11.72737, 29.24277, 2.021733, 29.38037, 21.06017,
   28.28191, 46.37371, 46.49742, 10.72091, 18.71499, 8.32131, 19.08981, 2.931476, 19.02097, 8.011612, 15.55107, 8.662682, 14.06721, 20.05237, 14.07458, 11.96205,
   16.2827, 5.667207 };
   graph = new TGraph(35,Graph_fx12,Graph_fy12);
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
   
   TH1F *Graph_Graph12 = new TH1F("Graph_Graph12","",100,0,3959);
   Graph_Graph12->SetMinimum(0.5239188);
   Graph_Graph12->SetMaximum(51.08895);
   Graph_Graph12->SetDirectory(nullptr);
   Graph_Graph12->SetStats(0);
   Graph_Graph12->SetLineWidth(2);
   Graph_Graph12->SetMarkerStyle(20);
   Graph_Graph12->SetMarkerSize(0.9);
   Graph_Graph12->GetXaxis()->SetLabelFont(42);
   Graph_Graph12->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph12->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph12->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph12->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph12->GetXaxis()->SetTitleFont(42);
   Graph_Graph12->GetYaxis()->SetLabelFont(42);
   Graph_Graph12->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph12->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph12->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph12->GetYaxis()->SetTickLength(0.02);
   Graph_Graph12->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph12->GetYaxis()->SetTitleFont(42);
   Graph_Graph12->GetZaxis()->SetLabelFont(42);
   Graph_Graph12->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph12->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph12->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph12->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph12->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph12);
   
   graph->Draw("p");
   
   Double_t Graph_fx13[35] = { 10, 30, 50, 70, 90, 110, 130, 150, 170, 190, 210, 230, 250, 270, 290, 310, 330,
   350, 370, 395, 425, 460, 505, 560, 625, 710, 820, 955, 1120, 1325, 1585, 1865, 2250,
   2850, 3600 };
   Double_t Graph_fy13[35] = { 0.3960798, 0.5204199, 0.5489741, 1.061896, 3.864781, 3.884807, 2.888103, 5.451009, 2.717238, 6.599399, 6.924764, 3.61451, 17.54111, 25.12501, 6.013513, 3.041899, 18.82835,
   29.05318, 16.13919, 4.904872, 9.182567, 18.74927, 8.581589, 6.973862, 27.83513, 4.605958, 23.03268, 49.4453, 30.01917, 63.84516, 49.26408, 47.36595, 45.28066,
   53.01263, 128.4215 };
   graph = new TGraph(35,Graph_fx13,Graph_fy13);
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
   
   TH1F *Graph_Graph13 = new TH1F("Graph_Graph13","",100,0,3959);
   Graph_Graph13->SetMinimum(0.3564718);
   Graph_Graph13->SetMaximum(141.224);
   Graph_Graph13->SetDirectory(nullptr);
   Graph_Graph13->SetStats(0);
   Graph_Graph13->SetLineWidth(2);
   Graph_Graph13->SetMarkerStyle(20);
   Graph_Graph13->SetMarkerSize(0.9);
   Graph_Graph13->GetXaxis()->SetLabelFont(42);
   Graph_Graph13->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph13->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph13->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph13->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph13->GetXaxis()->SetTitleFont(42);
   Graph_Graph13->GetYaxis()->SetLabelFont(42);
   Graph_Graph13->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph13->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph13->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph13->GetYaxis()->SetTickLength(0.02);
   Graph_Graph13->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph13->GetYaxis()->SetTitleFont(42);
   Graph_Graph13->GetZaxis()->SetLabelFont(42);
   Graph_Graph13->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph13->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph13->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph13->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph13->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph13);
   
   graph->Draw("p");
   
   Double_t Graph_fx14[35] = { 10, 30, 50, 70, 90, 110, 130, 150, 170, 190, 210, 230, 250, 270, 290, 310, 330,
   350, 370, 395, 425, 460, 505, 560, 625, 710, 820, 955, 1120, 1325, 1585, 1865, 2250,
   2850, 3600 };
   Double_t Graph_fy14[35] = { 0.2483094, 0.2482657, 0.2076969, 0.09060091, 0.02122206, 0.02408513, 0.04533246, 0.1163981, 0.2754121, 0.3656031, 0.6147533, 0.6855915, 0.9013601, 1.180427, 1.242073, 1.209351, 1.801549,
   1.20438, 1.753692, 1.951536, 2.207662, 1.833738, 2.596009, 2.419735, 2.820827, 2.705345, 2.559413, 2.921529, 2.782384, 3.112125, 4.482638, 3.814335, 9.481095,
   4.896978, 3.013971 };
   graph = new TGraph(35,Graph_fx14,Graph_fy14);
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
   
   TH1F *Graph_Graph14 = new TH1F("Graph_Graph14","",100,0,3959);
   Graph_Graph14->SetMinimum(0.01909985);
   Graph_Graph14->SetMaximum(10.42708);
   Graph_Graph14->SetDirectory(nullptr);
   Graph_Graph14->SetStats(0);
   Graph_Graph14->SetLineWidth(2);
   Graph_Graph14->SetMarkerStyle(20);
   Graph_Graph14->SetMarkerSize(0.9);
   Graph_Graph14->GetXaxis()->SetLabelFont(42);
   Graph_Graph14->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph14->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph14->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph14->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph14->GetXaxis()->SetTitleFont(42);
   Graph_Graph14->GetYaxis()->SetLabelFont(42);
   Graph_Graph14->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph14->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph14->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph14->GetYaxis()->SetTickLength(0.02);
   Graph_Graph14->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph14->GetYaxis()->SetTitleFont(42);
   Graph_Graph14->GetZaxis()->SetLabelFont(42);
   Graph_Graph14->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph14->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph14->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph14->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph14->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph14);
   
   graph->Draw("p");
   
   Double_t Graph_fx15[35] = { 10, 30, 50, 70, 90, 110, 130, 150, 170, 190, 210, 230, 250, 270, 290, 310, 330,
   350, 370, 395, 425, 460, 505, 560, 625, 710, 820, 955, 1120, 1325, 1585, 1865, 2250,
   2850, 3600 };
   Double_t Graph_fy15[35] = { 0.03381576, 0.03381604, 0.03327501, 0.03131453, 0.02999263, 0.0285215, 0.02442917, 0.01880221, 0.00806656, 0.003246999, 0.03031675, 0.04342127, 0.0700811, 0.1267064, 0.156359, 0.2062995, 0.2773667,
   0.2922004, 0.4076577, 0.5092058, 0.6295036, 0.7249166, 1.219516, 1.694493, 2.49775, 3.964609, 6.595951, 8.632912, 11.26687, 12.81665, 15.98965, 16.43974, 23.53707,
   23.95614, 5.619629 };
   graph = new TGraph(35,Graph_fx15,Graph_fy15);
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
   
   TH1F *Graph_Graph15 = new TH1F("Graph_Graph15","",100,0,3959);
   Graph_Graph15->SetMinimum(0.002922299);
   Graph_Graph15->SetMaximum(26.35143);
   Graph_Graph15->SetDirectory(nullptr);
   Graph_Graph15->SetStats(0);
   Graph_Graph15->SetLineWidth(2);
   Graph_Graph15->SetMarkerStyle(20);
   Graph_Graph15->SetMarkerSize(0.9);
   Graph_Graph15->GetXaxis()->SetLabelFont(42);
   Graph_Graph15->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph15->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph15->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph15->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph15->GetXaxis()->SetTitleFont(42);
   Graph_Graph15->GetYaxis()->SetLabelFont(42);
   Graph_Graph15->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph15->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph15->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph15->GetYaxis()->SetTickLength(0.02);
   Graph_Graph15->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph15->GetYaxis()->SetTitleFont(42);
   Graph_Graph15->GetZaxis()->SetLabelFont(42);
   Graph_Graph15->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph15->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph15->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph15->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph15->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph15);
   
   graph->Draw("p");
   
   Double_t Graph_fx16[35] = { 10, 30, 50, 70, 90, 110, 130, 150, 170, 190, 210, 230, 250, 270, 290, 310, 330,
   350, 370, 395, 425, 460, 505, 560, 625, 710, 820, 955, 1120, 1325, 1585, 1865, 2250,
   2850, 3600 };
   Double_t Graph_fy16[35] = { 0.4460838, 0.2386984, 0.05414756, 0.01124193, 0.06900419, 0.1158486, 0.1846834, 0.2276046, 0.264921, 0.2655481, 0.3063592, 0.2812592, 0.2944437, 0.3158767, 0.3370735, 0.3110573, 0.4347743,
   0.3422721, 0.4903597, 0.3920525, 0.5067139, 0.4618186, 0.4591646, 0.4290175, 0.4865141, 0.5902824, 0.7257854, 0.8804329, 1.113408, 2.497131, 3.1098, 4.350552, 3.932711,
   4.564555, 2.306224 };
   graph = new TGraph(35,Graph_fx16,Graph_fy16);
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
   
   TH1F *Graph_Graph16 = new TH1F("Graph_Graph16","",100,0,3959);
   Graph_Graph16->SetMinimum(0.01011774);
   Graph_Graph16->SetMaximum(5.019887);
   Graph_Graph16->SetDirectory(nullptr);
   Graph_Graph16->SetStats(0);
   Graph_Graph16->SetLineWidth(2);
   Graph_Graph16->SetMarkerStyle(20);
   Graph_Graph16->SetMarkerSize(0.9);
   Graph_Graph16->GetXaxis()->SetLabelFont(42);
   Graph_Graph16->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph16->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph16->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph16->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph16->GetXaxis()->SetTitleFont(42);
   Graph_Graph16->GetYaxis()->SetLabelFont(42);
   Graph_Graph16->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph16->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph16->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph16->GetYaxis()->SetTickLength(0.02);
   Graph_Graph16->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph16->GetYaxis()->SetTitleFont(42);
   Graph_Graph16->GetZaxis()->SetLabelFont(42);
   Graph_Graph16->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph16->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph16->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph16->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph16->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph16);
   
   graph->Draw("p");
   
   Double_t Graph_fx17[35] = { 10, 30, 50, 70, 90, 110, 130, 150, 170, 190, 210, 230, 250, 270, 290, 310, 330,
   350, 370, 395, 425, 460, 505, 560, 625, 710, 820, 955, 1120, 1325, 1585, 1865, 2250,
   2850, 3600 };
   Double_t Graph_fy17[35] = { 3.647908, 3.108851, 0.8475208, 0.9460592, 1.368984, 1.584489, 1.728877, 1.995501, 2.185194, 2.414745, 2.533853, 2.814137, 3.03252, 3.239132, 3.223288, 3.625235, 3.417344,
   3.8491, 3.903764, 4.048979, 4.193295, 4.30929, 4.489863, 4.607132, 4.570622, 5.087358, 5.145301, 5.638293, 7.116694, 14.40256, 17.53572, 25.16864, 22.39586,
   27.58367, 18.06775 };
   graph = new TGraph(35,Graph_fx17,Graph_fy17);
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
   
   TH1F *Graph_Graph17 = new TH1F("Graph_Graph17","",100,0,3959);
   Graph_Graph17->SetMinimum(0.7627687);
   Graph_Graph17->SetMaximum(30.25729);
   Graph_Graph17->SetDirectory(nullptr);
   Graph_Graph17->SetStats(0);
   Graph_Graph17->SetLineWidth(2);
   Graph_Graph17->SetMarkerStyle(20);
   Graph_Graph17->SetMarkerSize(0.9);
   Graph_Graph17->GetXaxis()->SetLabelFont(42);
   Graph_Graph17->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph17->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph17->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph17->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph17->GetXaxis()->SetTitleFont(42);
   Graph_Graph17->GetYaxis()->SetLabelFont(42);
   Graph_Graph17->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph17->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph17->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph17->GetYaxis()->SetTickLength(0.02);
   Graph_Graph17->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph17->GetYaxis()->SetTitleFont(42);
   Graph_Graph17->GetZaxis()->SetLabelFont(42);
   Graph_Graph17->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph17->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph17->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph17->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph17->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph17);
   
   graph->Draw("p");
   
   Double_t Graph_fx18[35] = { 10, 30, 50, 70, 90, 110, 130, 150, 170, 190, 210, 230, 250, 270, 290, 310, 330,
   350, 370, 395, 425, 460, 505, 560, 625, 710, 820, 955, 1120, 1325, 1585, 1865, 2250,
   2850, 3600 };
   Double_t Graph_fy18[35] = { 6.426192, 3.368945, 1.63733, 3.185961, 5.380939, 4.786858, 4.418643, 9.774417, 17.57446, 14.67888, 11.10589, 9.375975, 21.40148, 38.79309, 7.444383, 29.89406, 28.67961,
   40.78753, 49.37276, 47.09952, 15.58401, 27.07192, 13.66176, 21.26749, 29.04921, 21.59874, 26.58973, 54.03886, 38.9096, 80.02647, 71.94757, 95.6984, 81.95983,
   138.5952, 143.4114 };
   graph = new TGraph(35,Graph_fx18,Graph_fy18);
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
   
   TH1F *Graph_Graph18 = new TH1F("Graph_Graph18","",100,0,3959);
   Graph_Graph18->SetMinimum(1.473597);
   Graph_Graph18->SetMaximum(157.5888);
   Graph_Graph18->SetDirectory(nullptr);
   Graph_Graph18->SetStats(0);
   Graph_Graph18->SetLineWidth(2);
   Graph_Graph18->SetMarkerStyle(20);
   Graph_Graph18->SetMarkerSize(0.9);
   Graph_Graph18->GetXaxis()->SetLabelFont(42);
   Graph_Graph18->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph18->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph18->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph18->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph18->GetXaxis()->SetTitleFont(42);
   Graph_Graph18->GetYaxis()->SetLabelFont(42);
   Graph_Graph18->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph18->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph18->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph18->GetYaxis()->SetTickLength(0.02);
   Graph_Graph18->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph18->GetYaxis()->SetTitleFont(42);
   Graph_Graph18->GetZaxis()->SetLabelFont(42);
   Graph_Graph18->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph18->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph18->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph18->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph18->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph18);
   
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
      tex = new TLatex(0.8,0.88,"#bf{|#eta|<2.4}");
   tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.07);
   tex->SetLineWidth(2);
   tex->Draw();
   c2_283->Modified();
   c2_283->SetSelected(c2_283);
}
