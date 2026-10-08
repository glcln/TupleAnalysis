#ifdef __CLING__
#pragma cling optimize(0)
#endif
void summary_binned_syst_JetMET2024_V12p35_Eta1_2p4()
{
//=========Macro generated from canvas: c2_425/c2
//=========  (Tue Sep 29 15:02:15 2026) by ROOT version 6.32.13
   TCanvas *c2_425 = new TCanvas("c2_425", "c2",0,0,800,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c2_425->SetHighLightColor(2);
   c2_425->Range(-470.5883,-1.690817,4235.294,4.065992);
   c2_425->SetFillColor(0);
   c2_425->SetBorderMode(0);
   c2_425->SetBorderSize(2);
   c2_425->SetLogy();
   c2_425->SetGridx();
   c2_425->SetGridy();
   c2_425->SetRightMargin(0.05);
   c2_425->SetTopMargin(0.05);
   c2_425->SetBottomMargin(0.12);
   c2_425->SetFrameLineWidth(2);
   c2_425->SetFrameBorderMode(0);
   c2_425->SetFrameLineWidth(2);
   c2_425->SetFrameBorderMode(0);
   
   TH1D *frameSummary_426__5 = new TH1D("frameSummary_426__5","",1,0,4000);
   frameSummary_426__5->SetMinimum(0.1);
   frameSummary_426__5->SetMaximum(6000);
   frameSummary_426__5->SetDirectory(nullptr);
   frameSummary_426__5->SetStats(0);
   frameSummary_426__5->SetLineWidth(2);
   frameSummary_426__5->SetMarkerStyle(20);
   frameSummary_426__5->SetMarkerSize(0.9);
   frameSummary_426__5->GetXaxis()->SetTitle("Mass (GeV)");
   frameSummary_426__5->GetXaxis()->SetLabelFont(43);
   frameSummary_426__5->GetXaxis()->SetLabelOffset(0.015);
   frameSummary_426__5->GetXaxis()->SetLabelSize(24);
   frameSummary_426__5->GetXaxis()->SetTitleSize(0.05);
   frameSummary_426__5->GetXaxis()->SetTitleOffset(1);
   frameSummary_426__5->GetXaxis()->SetTitleFont(42);
   frameSummary_426__5->GetYaxis()->SetTitle("Systematic Uncertainty [%]");
   frameSummary_426__5->GetYaxis()->SetLabelFont(43);
   frameSummary_426__5->GetYaxis()->SetLabelOffset(0.015);
   frameSummary_426__5->GetYaxis()->SetLabelSize(24);
   frameSummary_426__5->GetYaxis()->SetTitleSize(0.05);
   frameSummary_426__5->GetYaxis()->SetTickLength(0.02);
   frameSummary_426__5->GetYaxis()->SetTitleOffset(1);
   frameSummary_426__5->GetYaxis()->SetTitleFont(42);
   frameSummary_426__5->GetZaxis()->SetLabelFont(42);
   frameSummary_426__5->GetZaxis()->SetLabelOffset(0.015);
   frameSummary_426__5->GetZaxis()->SetLabelSize(0.05);
   frameSummary_426__5->GetZaxis()->SetTitleSize(0.065);
   frameSummary_426__5->GetZaxis()->SetTitleOffset(1.1);
   frameSummary_426__5->GetZaxis()->SetTitleFont(42);
   frameSummary_426__5->Draw("AXIS");
   
   TH1D *frameSummary_426__6 = new TH1D("frameSummary_426__6","",1,0,4000);
   frameSummary_426__6->SetMinimum(0.1);
   frameSummary_426__6->SetMaximum(6000);
   frameSummary_426__6->SetDirectory(nullptr);
   frameSummary_426__6->SetStats(0);
   frameSummary_426__6->SetLineWidth(2);
   frameSummary_426__6->SetMarkerStyle(20);
   frameSummary_426__6->SetMarkerSize(0.9);
   frameSummary_426__6->GetXaxis()->SetTitle("Mass (GeV)");
   frameSummary_426__6->GetXaxis()->SetLabelFont(43);
   frameSummary_426__6->GetXaxis()->SetLabelOffset(0.015);
   frameSummary_426__6->GetXaxis()->SetLabelSize(24);
   frameSummary_426__6->GetXaxis()->SetTitleSize(0.05);
   frameSummary_426__6->GetXaxis()->SetTitleOffset(1);
   frameSummary_426__6->GetXaxis()->SetTitleFont(42);
   frameSummary_426__6->GetYaxis()->SetTitle("Systematic Uncertainty [%]");
   frameSummary_426__6->GetYaxis()->SetLabelFont(43);
   frameSummary_426__6->GetYaxis()->SetLabelOffset(0.015);
   frameSummary_426__6->GetYaxis()->SetLabelSize(24);
   frameSummary_426__6->GetYaxis()->SetTitleSize(0.05);
   frameSummary_426__6->GetYaxis()->SetTickLength(0.02);
   frameSummary_426__6->GetYaxis()->SetTitleOffset(1);
   frameSummary_426__6->GetYaxis()->SetTitleFont(42);
   frameSummary_426__6->GetZaxis()->SetLabelFont(42);
   frameSummary_426__6->GetZaxis()->SetLabelOffset(0.015);
   frameSummary_426__6->GetZaxis()->SetLabelSize(0.05);
   frameSummary_426__6->GetZaxis()->SetTitleSize(0.065);
   frameSummary_426__6->GetZaxis()->SetTitleOffset(1.1);
   frameSummary_426__6->GetZaxis()->SetTitleFont(42);
   frameSummary_426__6->Draw("SAME AXIG");
   
   Double_t Graph_fx19[35] = { 10, 30, 50, 70, 90, 110, 130, 150, 170, 190, 210, 230, 250, 270, 290, 310, 330,
   350, 370, 395, 425, 460, 505, 560, 625, 710, 820, 955, 1120, 1325, 1585, 1865, 2250,
   2850, 3600 };
   Double_t Graph_fy19[35] = { 2.86062, 1.437542, 1.241155, 1.149111, 1.095993, 1.047209, 1.047743, 1.0511, 1.095752, 1.145044, 1.275981, 1.312776, 1.385659, 1.50048, 1.597488, 1.591019, 1.955083,
   1.714948, 1.934348, 1.873838, 2.014458, 1.733159, 2.057213, 2.128576, 2.506577, 2.722288, 3.580584, 4.970367, 7.628038, 14.46433, 17.94209, 23.51936, 15.39167,
   22.82215, 57.41285 };
   TGraph *graph = new TGraph(35,Graph_fx19,Graph_fy19);
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillColor(1);
   graph->SetFillStyle(1000);
   graph->SetMarkerStyle(20);
   graph->SetMarkerSize(1.2);
   
   TH1F *Graph_Graph19 = new TH1F("Graph_Graph19","",100,0,3959);
   Graph_Graph19->SetMinimum(0.9424883);
   Graph_Graph19->SetMaximum(63.04941);
   Graph_Graph19->SetDirectory(nullptr);
   Graph_Graph19->SetStats(0);
   Graph_Graph19->SetLineWidth(2);
   Graph_Graph19->SetMarkerStyle(20);
   Graph_Graph19->SetMarkerSize(0.9);
   Graph_Graph19->GetXaxis()->SetLabelFont(42);
   Graph_Graph19->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph19->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph19->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph19->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph19->GetXaxis()->SetTitleFont(42);
   Graph_Graph19->GetYaxis()->SetLabelFont(42);
   Graph_Graph19->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph19->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph19->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph19->GetYaxis()->SetTickLength(0.02);
   Graph_Graph19->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph19->GetYaxis()->SetTitleFont(42);
   Graph_Graph19->GetZaxis()->SetLabelFont(42);
   Graph_Graph19->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph19->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph19->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph19->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph19->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph19);
   
   graph->Draw("p");
   
   Double_t Graph_fx20[35] = { 10, 30, 50, 70, 90, 110, 130, 150, 170, 190, 210, 230, 250, 270, 290, 310, 330,
   350, 370, 395, 425, 460, 505, 560, 625, 710, 820, 955, 1120, 1325, 1585, 1865, 2250,
   2850, 3600 };
   Double_t Graph_fy20[35] = { 2.723492, 1.783431, 1.653187, 0.8408705, 2.058963, 1.429926, 0.5457827, 0.09234814, 0.3367603, 1.035326, 1.210715, 1.677416, 1.14797, 2.130157, 1.004021, 1.866981, 2.624103,
   0.290049, 1.425476, 3.279522, 4.233921, 2.15791, 3.429965, 2.4058, 4.27695, 4.374646, 3.991177, 8.64937, 17.57119, 39.00473, 36.70775, 72.60997, 52.13359,
   111.4476, 1.021417 };
   graph = new TGraph(35,Graph_fx20,Graph_fy20);
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
   
   TH1F *Graph_Graph20 = new TH1F("Graph_Graph20","",100,0,3959);
   Graph_Graph20->SetMinimum(0.08311333);
   Graph_Graph20->SetMaximum(122.5832);
   Graph_Graph20->SetDirectory(nullptr);
   Graph_Graph20->SetStats(0);
   Graph_Graph20->SetLineWidth(2);
   Graph_Graph20->SetMarkerStyle(20);
   Graph_Graph20->SetMarkerSize(0.9);
   Graph_Graph20->GetXaxis()->SetLabelFont(42);
   Graph_Graph20->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph20->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph20->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph20->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph20->GetXaxis()->SetTitleFont(42);
   Graph_Graph20->GetYaxis()->SetLabelFont(42);
   Graph_Graph20->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph20->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph20->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph20->GetYaxis()->SetTickLength(0.02);
   Graph_Graph20->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph20->GetYaxis()->SetTitleFont(42);
   Graph_Graph20->GetZaxis()->SetLabelFont(42);
   Graph_Graph20->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph20->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph20->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph20->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph20->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph20);
   
   graph->Draw("p");
   
   Double_t Graph_fx21[35] = { 10, 30, 50, 70, 90, 110, 130, 150, 170, 190, 210, 230, 250, 270, 290, 310, 330,
   350, 370, 395, 425, 460, 505, 560, 625, 710, 820, 955, 1120, 1325, 1585, 1865, 2250,
   2850, 3600 };
   Double_t Graph_fy21[35] = { 65.46573, 2.600605, 6.16757, 4.165288, 3.440046, 2.861705, 3.2886, 7.798443, 17.18396, 12.94307, 8.458521, 7.894301, 11.93579, 28.63337, 2.331084, 29.90494, 22.95629,
   29.99766, 49.50439, 49.11245, 9.905559, 19.28987, 8.233043, 19.42489, 1.898264, 19.2277, 8.052808, 15.9092, 5.515006, 12.7753, 19.54778, 14.07376, 6.929901,
   11.89567, 4.710624 };
   graph = new TGraph(35,Graph_fx21,Graph_fy21);
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
   
   TH1F *Graph_Graph21 = new TH1F("Graph_Graph21","",100,0,3959);
   Graph_Graph21->SetMinimum(1.708438);
   Graph_Graph21->SetMaximum(71.82248);
   Graph_Graph21->SetDirectory(nullptr);
   Graph_Graph21->SetStats(0);
   Graph_Graph21->SetLineWidth(2);
   Graph_Graph21->SetMarkerStyle(20);
   Graph_Graph21->SetMarkerSize(0.9);
   Graph_Graph21->GetXaxis()->SetLabelFont(42);
   Graph_Graph21->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph21->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph21->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph21->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph21->GetXaxis()->SetTitleFont(42);
   Graph_Graph21->GetYaxis()->SetLabelFont(42);
   Graph_Graph21->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph21->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph21->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph21->GetYaxis()->SetTickLength(0.02);
   Graph_Graph21->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph21->GetYaxis()->SetTitleFont(42);
   Graph_Graph21->GetZaxis()->SetLabelFont(42);
   Graph_Graph21->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph21->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph21->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph21->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph21->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph21);
   
   graph->Draw("p");
   
   Double_t Graph_fx22[35] = { 10, 30, 50, 70, 90, 110, 130, 150, 170, 190, 210, 230, 250, 270, 290, 310, 330,
   350, 370, 395, 425, 460, 505, 560, 625, 710, 820, 955, 1120, 1325, 1585, 1865, 2250,
   2850, 3600 };
   Double_t Graph_fy22[35] = { 2.869458, 2.674025, 1.544326, 2.183707, 4.381514, 3.802248, 3.431229, 5.754657, 2.663491, 6.636624, 6.883515, 3.513615, 17.59848, 25.69675, 5.096463, 2.891637, 19.80829,
   29.93513, 17.03603, 4.316218, 7.873837, 18.302, 8.30891, 5.458855, 27.53051, 4.664272, 21.96137, 48.4327, 27.89454, 64.78715, 48.6136, 50.96828, 46.1116,
   52.46042, 113.2808 };
   graph = new TGraph(35,Graph_fx22,Graph_fy22);
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
   
   TH1F *Graph_Graph22 = new TH1F("Graph_Graph22","",100,0,3959);
   Graph_Graph22->SetMinimum(1.389893);
   Graph_Graph22->SetMaximum(124.4545);
   Graph_Graph22->SetDirectory(nullptr);
   Graph_Graph22->SetStats(0);
   Graph_Graph22->SetLineWidth(2);
   Graph_Graph22->SetMarkerStyle(20);
   Graph_Graph22->SetMarkerSize(0.9);
   Graph_Graph22->GetXaxis()->SetLabelFont(42);
   Graph_Graph22->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph22->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph22->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph22->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph22->GetXaxis()->SetTitleFont(42);
   Graph_Graph22->GetYaxis()->SetLabelFont(42);
   Graph_Graph22->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph22->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph22->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph22->GetYaxis()->SetTickLength(0.02);
   Graph_Graph22->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph22->GetYaxis()->SetTitleFont(42);
   Graph_Graph22->GetZaxis()->SetLabelFont(42);
   Graph_Graph22->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph22->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph22->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph22->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph22->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph22);
   
   graph->Draw("p");
   
   Double_t Graph_fx23[35] = { 10, 30, 50, 70, 90, 110, 130, 150, 170, 190, 210, 230, 250, 270, 290, 310, 330,
   350, 370, 395, 425, 460, 505, 560, 625, 710, 820, 955, 1120, 1325, 1585, 1865, 2250,
   2850, 3600 };
   Double_t Graph_fy23[35] = { 0.4997595, 0.5006406, 0.500524, 0.362915, 0.2002021, 0.2046389, 0.1676263, 0.07008904, 0.1839721, 0.281213, 0.5458331, 0.58119, 0.7910021, 1.075082, 1.128124, 1.060673, 1.707581,
   1.0182, 1.553658, 1.793042, 2.095706, 1.64117, 2.418882, 2.148527, 2.498931, 2.363747, 2.326971, 2.638668, 2.532825, 3.024594, 2.819884, 2.656021, 2.570691,
   1.985139, 0.6418216 };
   graph = new TGraph(35,Graph_fx23,Graph_fy23);
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
   
   TH1F *Graph_Graph23 = new TH1F("Graph_Graph23","",100,0,3959);
   Graph_Graph23->SetMinimum(0.06308014);
   Graph_Graph23->SetMaximum(3.320044);
   Graph_Graph23->SetDirectory(nullptr);
   Graph_Graph23->SetStats(0);
   Graph_Graph23->SetLineWidth(2);
   Graph_Graph23->SetMarkerStyle(20);
   Graph_Graph23->SetMarkerSize(0.9);
   Graph_Graph23->GetXaxis()->SetLabelFont(42);
   Graph_Graph23->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph23->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph23->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph23->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph23->GetXaxis()->SetTitleFont(42);
   Graph_Graph23->GetYaxis()->SetLabelFont(42);
   Graph_Graph23->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph23->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph23->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph23->GetYaxis()->SetTickLength(0.02);
   Graph_Graph23->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph23->GetYaxis()->SetTitleFont(42);
   Graph_Graph23->GetZaxis()->SetLabelFont(42);
   Graph_Graph23->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph23->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph23->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph23->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph23->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph23);
   
   graph->Draw("p");
   
   Double_t Graph_fx24[35] = { 10, 30, 50, 70, 90, 110, 130, 150, 170, 190, 210, 230, 250, 270, 290, 310, 330,
   350, 370, 395, 425, 460, 505, 560, 625, 710, 820, 955, 1120, 1325, 1585, 1865, 2250,
   2850, 3600 };
   Double_t Graph_fy24[35] = { 0.03889379, 0.03889954, 0.03890386, 0.03886237, 0.03832257, 0.03779024, 0.03693639, 0.03700432, 0.03428108, 0.03216734, 0.02813821, 0.02561727, 0.02545428, 0.007819971, 0.006946082, 0.01844659, 0.02968378,
   0.05658461, 0.1108001, 0.1502525, 0.2559141, 0.3571785, 0.7469522, 1.268337, 2.107357, 3.625128, 6.352781, 8.520328, 11.50261, 13.19013, 16.16456, 16.85539, 23.54245,
   23.05252, 4.931773 };
   graph = new TGraph(35,Graph_fx24,Graph_fy24);
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
   
   TH1F *Graph_Graph24 = new TH1F("Graph_Graph24","",100,0,3959);
   Graph_Graph24->SetMinimum(0.006251474);
   Graph_Graph24->SetMaximum(25.89601);
   Graph_Graph24->SetDirectory(nullptr);
   Graph_Graph24->SetStats(0);
   Graph_Graph24->SetLineWidth(2);
   Graph_Graph24->SetMarkerStyle(20);
   Graph_Graph24->SetMarkerSize(0.9);
   Graph_Graph24->GetXaxis()->SetLabelFont(42);
   Graph_Graph24->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph24->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph24->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph24->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph24->GetXaxis()->SetTitleFont(42);
   Graph_Graph24->GetYaxis()->SetLabelFont(42);
   Graph_Graph24->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph24->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph24->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph24->GetYaxis()->SetTickLength(0.02);
   Graph_Graph24->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph24->GetYaxis()->SetTitleFont(42);
   Graph_Graph24->GetZaxis()->SetLabelFont(42);
   Graph_Graph24->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph24->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph24->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph24->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph24->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph24);
   
   graph->Draw("p");
   
   Double_t Graph_fx25[35] = { 10, 30, 50, 70, 90, 110, 130, 150, 170, 190, 210, 230, 250, 270, 290, 310, 330,
   350, 370, 395, 425, 460, 505, 560, 625, 710, 820, 955, 1120, 1325, 1585, 1865, 2250,
   2850, 3600 };
   Double_t Graph_fy25[35] = { 1.450626, 1.289068, 0.8646722, 0.4437479, 0.1160849, 0.05569227, 0.1937446, 0.2652258, 0.3630208, 0.4321621, 0.5961298, 0.5792433, 0.6059865, 0.6312045, 0.8044318, 0.6515816, 1.158608,
   0.6445907, 1.038662, 1.012565, 1.094671, 1.089745, 1.260923, 1.414261, 1.580096, 1.15729, 1.100414, 0.8099668, 0.9912934, 1.655021, 1.401672, 3.304037, 3.277214,
   4.256061, 1.491655 };
   graph = new TGraph(35,Graph_fx25,Graph_fy25);
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
   
   TH1F *Graph_Graph25 = new TH1F("Graph_Graph25","",100,0,3959);
   Graph_Graph25->SetMinimum(0.05012305);
   Graph_Graph25->SetMaximum(4.676098);
   Graph_Graph25->SetDirectory(nullptr);
   Graph_Graph25->SetStats(0);
   Graph_Graph25->SetLineWidth(2);
   Graph_Graph25->SetMarkerStyle(20);
   Graph_Graph25->SetMarkerSize(0.9);
   Graph_Graph25->GetXaxis()->SetLabelFont(42);
   Graph_Graph25->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph25->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph25->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph25->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph25->GetXaxis()->SetTitleFont(42);
   Graph_Graph25->GetYaxis()->SetLabelFont(42);
   Graph_Graph25->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph25->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph25->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph25->GetYaxis()->SetTickLength(0.02);
   Graph_Graph25->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph25->GetYaxis()->SetTitleFont(42);
   Graph_Graph25->GetZaxis()->SetLabelFont(42);
   Graph_Graph25->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph25->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph25->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph25->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph25->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph25);
   
   graph->Draw("p");
   
   Double_t Graph_fx26[35] = { 10, 30, 50, 70, 90, 110, 130, 150, 170, 190, 210, 230, 250, 270, 290, 310, 330,
   350, 370, 395, 425, 460, 505, 560, 625, 710, 820, 955, 1120, 1325, 1585, 1865, 2250,
   2850, 3600 };
   Double_t Graph_fy26[35] = { 2.813266, 1.587571, 1.699007, 1.447404, 0.9553053, 0.2946432, 0.1784848, 0.6576195, 0.9882194, 1.33481, 1.541582, 1.881072, 2.135209, 2.388974, 2.370404, 2.746556, 2.614332,
   2.922129, 3.004261, 3.269094, 3.324621, 3.489991, 3.704441, 3.795619, 3.9774, 4.355426, 4.232359, 4.748636, 5.093599, 7.405264, 9.440163, 13.10447, 14.34351,
   12.64017, 8.997161 };
   graph = new TGraph(35,Graph_fx26,Graph_fy26);
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
   
   TH1F *Graph_Graph26 = new TH1F("Graph_Graph26","",100,0,3959);
   Graph_Graph26->SetMinimum(0.1606363);
   Graph_Graph26->SetMaximum(15.76001);
   Graph_Graph26->SetDirectory(nullptr);
   Graph_Graph26->SetStats(0);
   Graph_Graph26->SetLineWidth(2);
   Graph_Graph26->SetMarkerStyle(20);
   Graph_Graph26->SetMarkerSize(0.9);
   Graph_Graph26->GetXaxis()->SetLabelFont(42);
   Graph_Graph26->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph26->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph26->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph26->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph26->GetXaxis()->SetTitleFont(42);
   Graph_Graph26->GetYaxis()->SetLabelFont(42);
   Graph_Graph26->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph26->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph26->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph26->GetYaxis()->SetTickLength(0.02);
   Graph_Graph26->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph26->GetYaxis()->SetTitleFont(42);
   Graph_Graph26->GetZaxis()->SetLabelFont(42);
   Graph_Graph26->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph26->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph26->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph26->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph26->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph26);
   
   graph->Draw("p");
   
   Double_t Graph_fx27[35] = { 10, 30, 50, 70, 90, 110, 130, 150, 170, 190, 210, 230, 250, 270, 290, 310, 330,
   350, 370, 395, 425, 460, 505, 560, 625, 710, 820, 955, 1120, 1325, 1585, 1865, 2250,
   2850, 3600 };
   Double_t Graph_fy27[35] = { 65.72569, 4.857462, 6.970199, 5.15469, 6.118802, 5.091267, 4.907416, 9.775184, 17.45968, 14.69692, 11.18275, 9.13318, 21.46998, 38.65545, 6.519705, 30.29484, 30.67836,
   42.53223, 52.52823, 49.59716, 14.10001, 27.03538, 13.21134, 20.97799, 28.55012, 21.37864, 25.31395, 52.92551, 36.62113, 79.57307, 69.10211, 95.36774, 76.85343,
   128.6401, 127.5144 };
   graph = new TGraph(35,Graph_fx27,Graph_fy27);
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
   
   TH1F *Graph_Graph27 = new TH1F("Graph_Graph27","",100,0,3959);
   Graph_Graph27->SetMinimum(4.371716);
   Graph_Graph27->SetMaximum(141.0184);
   Graph_Graph27->SetDirectory(nullptr);
   Graph_Graph27->SetStats(0);
   Graph_Graph27->SetLineWidth(2);
   Graph_Graph27->SetMarkerStyle(20);
   Graph_Graph27->SetMarkerSize(0.9);
   Graph_Graph27->GetXaxis()->SetLabelFont(42);
   Graph_Graph27->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph27->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph27->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph27->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph27->GetXaxis()->SetTitleFont(42);
   Graph_Graph27->GetYaxis()->SetLabelFont(42);
   Graph_Graph27->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph27->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph27->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph27->GetYaxis()->SetTickLength(0.02);
   Graph_Graph27->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph27->GetYaxis()->SetTitleFont(42);
   Graph_Graph27->GetZaxis()->SetLabelFont(42);
   Graph_Graph27->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph27->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph27->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph27->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph27->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph27);
   
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
      tex = new TLatex(0.75,0.88,"#bf{1#leq|#eta|<2.4}");
   tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.07);
   tex->SetLineWidth(2);
   tex->Draw();
   c2_425->Modified();
   c2_425->SetSelected(c2_425);
}
