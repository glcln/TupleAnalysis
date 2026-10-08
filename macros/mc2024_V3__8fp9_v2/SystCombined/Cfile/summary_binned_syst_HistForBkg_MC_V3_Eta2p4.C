#ifdef __CLING__
#pragma cling optimize(0)
#endif
void summary_binned_syst_HistForBkg_MC_V3_Eta2p4()
{
//=========Macro generated from canvas: c2_473/c2
//=========  (Sun Sep  6 11:16:22 2026) by ROOT version 6.32.13
   TCanvas *c2_473 = new TCanvas("c2_473", "c2",0,0,800,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c2_473->SetHighLightColor(2);
   c2_473->Range(-470.5883,-1.621836,4235.294,3.560128);
   c2_473->SetFillColor(0);
   c2_473->SetBorderMode(0);
   c2_473->SetBorderSize(2);
   c2_473->SetLogy();
   c2_473->SetGridx();
   c2_473->SetGridy();
   c2_473->SetRightMargin(0.05);
   c2_473->SetTopMargin(0.05);
   c2_473->SetBottomMargin(0.12);
   c2_473->SetFrameLineWidth(2);
   c2_473->SetFrameBorderMode(0);
   c2_473->SetFrameLineWidth(2);
   c2_473->SetFrameBorderMode(0);
   
   TH1D *frameSummary_474__5 = new TH1D("frameSummary_474__5","",1,0,4000);
   frameSummary_474__5->SetMinimum(0.1);
   frameSummary_474__5->SetMaximum(2000);
   frameSummary_474__5->SetDirectory(nullptr);
   frameSummary_474__5->SetStats(0);
   frameSummary_474__5->SetLineWidth(2);
   frameSummary_474__5->SetMarkerStyle(20);
   frameSummary_474__5->SetMarkerSize(0.9);
   frameSummary_474__5->GetXaxis()->SetTitle("Mass (GeV)");
   frameSummary_474__5->GetXaxis()->SetLabelFont(43);
   frameSummary_474__5->GetXaxis()->SetLabelOffset(0.015);
   frameSummary_474__5->GetXaxis()->SetLabelSize(24);
   frameSummary_474__5->GetXaxis()->SetTitleSize(0.05);
   frameSummary_474__5->GetXaxis()->SetTitleOffset(1);
   frameSummary_474__5->GetXaxis()->SetTitleFont(42);
   frameSummary_474__5->GetYaxis()->SetTitle("Systematic Uncertainty [%]");
   frameSummary_474__5->GetYaxis()->SetLabelFont(43);
   frameSummary_474__5->GetYaxis()->SetLabelOffset(0.015);
   frameSummary_474__5->GetYaxis()->SetLabelSize(24);
   frameSummary_474__5->GetYaxis()->SetTitleSize(0.05);
   frameSummary_474__5->GetYaxis()->SetTickLength(0.02);
   frameSummary_474__5->GetYaxis()->SetTitleOffset(1);
   frameSummary_474__5->GetYaxis()->SetTitleFont(42);
   frameSummary_474__5->GetZaxis()->SetLabelFont(42);
   frameSummary_474__5->GetZaxis()->SetLabelOffset(0.015);
   frameSummary_474__5->GetZaxis()->SetLabelSize(0.05);
   frameSummary_474__5->GetZaxis()->SetTitleSize(0.065);
   frameSummary_474__5->GetZaxis()->SetTitleOffset(1.1);
   frameSummary_474__5->GetZaxis()->SetTitleFont(42);
   frameSummary_474__5->Draw("AXIS");
   
   TH1D *frameSummary_474__6 = new TH1D("frameSummary_474__6","",1,0,4000);
   frameSummary_474__6->SetMinimum(0.1);
   frameSummary_474__6->SetMaximum(2000);
   frameSummary_474__6->SetDirectory(nullptr);
   frameSummary_474__6->SetStats(0);
   frameSummary_474__6->SetLineWidth(2);
   frameSummary_474__6->SetMarkerStyle(20);
   frameSummary_474__6->SetMarkerSize(0.9);
   frameSummary_474__6->GetXaxis()->SetTitle("Mass (GeV)");
   frameSummary_474__6->GetXaxis()->SetLabelFont(43);
   frameSummary_474__6->GetXaxis()->SetLabelOffset(0.015);
   frameSummary_474__6->GetXaxis()->SetLabelSize(24);
   frameSummary_474__6->GetXaxis()->SetTitleSize(0.05);
   frameSummary_474__6->GetXaxis()->SetTitleOffset(1);
   frameSummary_474__6->GetXaxis()->SetTitleFont(42);
   frameSummary_474__6->GetYaxis()->SetTitle("Systematic Uncertainty [%]");
   frameSummary_474__6->GetYaxis()->SetLabelFont(43);
   frameSummary_474__6->GetYaxis()->SetLabelOffset(0.015);
   frameSummary_474__6->GetYaxis()->SetLabelSize(24);
   frameSummary_474__6->GetYaxis()->SetTitleSize(0.05);
   frameSummary_474__6->GetYaxis()->SetTickLength(0.02);
   frameSummary_474__6->GetYaxis()->SetTitleOffset(1);
   frameSummary_474__6->GetYaxis()->SetTitleFont(42);
   frameSummary_474__6->GetZaxis()->SetLabelFont(42);
   frameSummary_474__6->GetZaxis()->SetLabelOffset(0.015);
   frameSummary_474__6->GetZaxis()->SetLabelSize(0.05);
   frameSummary_474__6->GetZaxis()->SetTitleSize(0.065);
   frameSummary_474__6->GetZaxis()->SetTitleOffset(1.1);
   frameSummary_474__6->GetZaxis()->SetTitleFont(42);
   frameSummary_474__6->Draw("SAME AXIG");
   
   Double_t Graph0_fx21[35] = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320,
   340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000,
   2500, 3200 };
   Double_t Graph0_fy21[35] = { 1.067774, 0.7553931, 0.6995188, 0.7460933, 0.845906, 0.9345069, 1.022942, 1.100094, 1.215785, 1.311559, 1.513139, 1.645398, 1.6796, 1.798501, 2.085241, 1.963734, 2.255756,
   2.177613, 2.553253, 2.557437, 2.625775, 2.178839, 2.503197, 2.769911, 3.40388, 3.794719, 4.481002, 5.684787, 7.947114, 11.57747, 15.7084, 29.95174, 33.37782,
   32.32227, 215.8005 };
   TGraph *graph = new TGraph(35,Graph0_fx21,Graph0_fy21);
   graph->SetName("Graph0");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetFillStyle(1000);
   graph->SetMarkerStyle(20);
   graph->SetMarkerSize(1.2);
   
   TH1F *Graph_Graph021 = new TH1F("Graph_Graph021","Graph",100,0,3520);
   Graph_Graph021->SetMinimum(0.6295669);
   Graph_Graph021->SetMaximum(237.3106);
   Graph_Graph021->SetDirectory(nullptr);
   Graph_Graph021->SetStats(0);
   Graph_Graph021->SetLineWidth(2);
   Graph_Graph021->SetMarkerStyle(20);
   Graph_Graph021->SetMarkerSize(0.9);
   Graph_Graph021->GetXaxis()->SetLabelFont(42);
   Graph_Graph021->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph021->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph021->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph021->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph021->GetXaxis()->SetTitleFont(42);
   Graph_Graph021->GetYaxis()->SetLabelFont(42);
   Graph_Graph021->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph021->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph021->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph021->GetYaxis()->SetTickLength(0.02);
   Graph_Graph021->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph021->GetYaxis()->SetTitleFont(42);
   Graph_Graph021->GetZaxis()->SetLabelFont(42);
   Graph_Graph021->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph021->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph021->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph021->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph021->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph021);
   
   graph->Draw("p");
   
   Double_t Graph1_fx22[35] = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320,
   340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000,
   2500, 3200 };
   Double_t Graph1_fy22[35] = { 0.2833088, 0.1646851, 0.1332393, 0.2777265, 0.1466375, 0.172478, 0.3975715, 0.3570401, 0.6000793, 0.7642739, 0.4545472, 0.9463617, 0.7541723, 0.6859996, 2.061649, 0.7920325, 0.6323831,
   1.422419, 1.018356, 1.290678, 0.7265035, 1.662569, 1.988697, 1.576725, 0.6901835, 1.584256, 2.76915, 5.643588, 14.65465, 9.404423, 16.12248, 7.374526, 42.42717,
   54.51572, 21.68255 };
   graph = new TGraph(35,Graph1_fx22,Graph1_fy22);
   graph->SetName("Graph1");
   graph->SetTitle("Graph");

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
   
   TH1F *Graph_Graph122 = new TH1F("Graph_Graph122","Graph",100,0,3520);
   Graph_Graph122->SetMinimum(0.1199154);
   Graph_Graph122->SetMaximum(59.95397);
   Graph_Graph122->SetDirectory(nullptr);
   Graph_Graph122->SetStats(0);
   Graph_Graph122->SetLineWidth(2);
   Graph_Graph122->SetMarkerStyle(20);
   Graph_Graph122->SetMarkerSize(0.9);
   Graph_Graph122->GetXaxis()->SetLabelFont(42);
   Graph_Graph122->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph122->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph122->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph122->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph122->GetXaxis()->SetTitleFont(42);
   Graph_Graph122->GetYaxis()->SetLabelFont(42);
   Graph_Graph122->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph122->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph122->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph122->GetYaxis()->SetTickLength(0.02);
   Graph_Graph122->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph122->GetYaxis()->SetTitleFont(42);
   Graph_Graph122->GetZaxis()->SetLabelFont(42);
   Graph_Graph122->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph122->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph122->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph122->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph122->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph122);
   
   graph->Draw("p");
   
   Double_t Graph2_fx23[35] = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320,
   340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000,
   2500, 3200 };
   Double_t Graph2_fy23[35] = { 7.436698, 0.8989176, 1.831467, 2.148896, 2.275716, 3.163679, 4.357758, 6.74947, 5.402921, 10.92168, 13.13455, 8.381291, 11.23359, 9.726794, 10.55553, 15.95099, 56.88892,
   29.72073, 46.47668, 64.04193, 18.84389, 18.50182, 11.24034, 35.18934, 23.46066, 5.395558, 5.041085, 19.71613, 10.52886, 9.367, 26.47147, 30.66628, 16.43168,
   34.11648, 52.78161 };
   graph = new TGraph(35,Graph2_fx23,Graph2_fy23);
   graph->SetName("Graph2");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#9933ff");
   graph->SetFillColor(ci);
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#9933ff");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#9933ff");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(22);
   graph->SetMarkerSize(1.2);
   
   TH1F *Graph_Graph223 = new TH1F("Graph_Graph223","Graph",100,0,3520);
   Graph_Graph223->SetMinimum(0.8090259);
   Graph_Graph223->SetMaximum(70.35624);
   Graph_Graph223->SetDirectory(nullptr);
   Graph_Graph223->SetStats(0);
   Graph_Graph223->SetLineWidth(2);
   Graph_Graph223->SetMarkerStyle(20);
   Graph_Graph223->SetMarkerSize(0.9);
   Graph_Graph223->GetXaxis()->SetLabelFont(42);
   Graph_Graph223->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph223->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph223->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph223->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph223->GetXaxis()->SetTitleFont(42);
   Graph_Graph223->GetYaxis()->SetLabelFont(42);
   Graph_Graph223->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph223->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph223->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph223->GetYaxis()->SetTickLength(0.02);
   Graph_Graph223->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph223->GetYaxis()->SetTitleFont(42);
   Graph_Graph223->GetZaxis()->SetLabelFont(42);
   Graph_Graph223->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph223->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph223->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph223->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph223->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph223);
   
   graph->Draw("p");
   
   Double_t Graph3_fx24[35] = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320,
   340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000,
   2500, 3200 };
   Double_t Graph3_fy24[35] = { 0.6697581, 0.9429091, 1.461475, 2.370038, 5.558877, 4.482943, 3.428651, 7.332732, 4.312473, 4.063428, 5.015296, 16.30791, 18.82813, 15.88701, 16.45978, 11.72785, 18.63456,
   32.80577, 28.18027, 21.91755, 38.28568, 26.67409, 7.092724, 11.41018, 27.41767, 13.0356, 13.0205, 17.92243, 26.72753, 43.81052, 40.92647, 46.21275, 67.35239,
   47.11942, 2348.036 };
   graph = new TGraph(35,Graph3_fx24,Graph3_fy24);
   graph->SetName("Graph3");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#0000cc");
   graph->SetFillColor(ci);
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#0000cc");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#0000cc");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(23);
   graph->SetMarkerSize(1.2);
   
   TH1F *Graph_Graph324 = new TH1F("Graph_Graph324","Graph",100,0,3520);
   Graph_Graph324->SetMinimum(0.6027823);
   Graph_Graph324->SetMaximum(2582.772);
   Graph_Graph324->SetDirectory(nullptr);
   Graph_Graph324->SetStats(0);
   Graph_Graph324->SetLineWidth(2);
   Graph_Graph324->SetMarkerStyle(20);
   Graph_Graph324->SetMarkerSize(0.9);
   Graph_Graph324->GetXaxis()->SetLabelFont(42);
   Graph_Graph324->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph324->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph324->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph324->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph324->GetXaxis()->SetTitleFont(42);
   Graph_Graph324->GetYaxis()->SetLabelFont(42);
   Graph_Graph324->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph324->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph324->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph324->GetYaxis()->SetTickLength(0.02);
   Graph_Graph324->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph324->GetYaxis()->SetTitleFont(42);
   Graph_Graph324->GetZaxis()->SetLabelFont(42);
   Graph_Graph324->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph324->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph324->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph324->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph324->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph324);
   
   graph->Draw("p");
   
   Double_t Graph4_fx25[35] = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320,
   340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000,
   2500, 3200 };
   Double_t Graph4_fy25[35] = { 0.1423756, 0.1422222, 0.1070015, 0.07391856, 0.05617357, 0.01598306, 0.03905188, 0.1259285, 0.3926751, 0.5345196, 0.7189351, 0.8938765, 0.8699302, 1.001682, 1.194094, 1.039177, 1.406069,
   1.074556, 1.173055, 1.84212, 1.716147, 1.592644, 2.016082, 2.121772, 2.695799, 2.449951, 2.176641, 2.149034, 3.410612, 3.346074, 2.403771, 2.099813, 0.8200355,
   0.3583661, 0.8847336 };
   graph = new TGraph(35,Graph4_fx25,Graph4_fy25);
   graph->SetName("Graph4");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#ff9933");
   graph->SetFillColor(ci);
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#ff9933");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#ff9933");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(33);
   graph->SetMarkerSize(1.2);
   
   TH1F *Graph_Graph425 = new TH1F("Graph_Graph425","Graph",100,0,3520);
   Graph_Graph425->SetMinimum(0.01438475);
   Graph_Graph425->SetMaximum(3.750075);
   Graph_Graph425->SetDirectory(nullptr);
   Graph_Graph425->SetStats(0);
   Graph_Graph425->SetLineWidth(2);
   Graph_Graph425->SetMarkerStyle(20);
   Graph_Graph425->SetMarkerSize(0.9);
   Graph_Graph425->GetXaxis()->SetLabelFont(42);
   Graph_Graph425->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph425->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph425->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph425->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph425->GetXaxis()->SetTitleFont(42);
   Graph_Graph425->GetYaxis()->SetLabelFont(42);
   Graph_Graph425->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph425->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph425->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph425->GetYaxis()->SetTickLength(0.02);
   Graph_Graph425->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph425->GetYaxis()->SetTitleFont(42);
   Graph_Graph425->GetZaxis()->SetLabelFont(42);
   Graph_Graph425->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph425->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph425->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph425->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph425->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph425);
   
   graph->Draw("p");
   
   Double_t Graph5_fx26[35] = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320,
   340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000,
   2500, 3200 };
   Double_t Graph5_fy26[35] = { 0.01778909, 0.01778964, 0.01699951, 0.01430928, 0.01320173, 0.009852714, 0.00420915, 0.001160879, 0.01556209, 0.02774601, 0.05321415, 0.07882314, 0.08426697, 0.1348044, 0.1770418, 0.1716598, 0.2648999,
   0.24524, 0.3213517, 0.4461383, 0.5466127, 0.5466981, 0.9087802, 1.213845, 1.960303, 2.670019, 4.806315, 6.450204, 8.394516, 7.884739, 8.216973, 9.046855, 4.639052,
   2.356085, 2.655771 };
   graph = new TGraph(35,Graph5_fx26,Graph5_fy26);
   graph->SetName("Graph5");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00ffff");
   graph->SetFillColor(ci);
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#00ffff");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#00ffff");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(29);
   graph->SetMarkerSize(1.2);
   
   TH1F *Graph_Graph526 = new TH1F("Graph_Graph526","Graph",100,0,3520);
   Graph_Graph526->SetMinimum(0.001044791);
   Graph_Graph526->SetMaximum(9.951425);
   Graph_Graph526->SetDirectory(nullptr);
   Graph_Graph526->SetStats(0);
   Graph_Graph526->SetLineWidth(2);
   Graph_Graph526->SetMarkerStyle(20);
   Graph_Graph526->SetMarkerSize(0.9);
   Graph_Graph526->GetXaxis()->SetLabelFont(42);
   Graph_Graph526->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph526->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph526->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph526->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph526->GetXaxis()->SetTitleFont(42);
   Graph_Graph526->GetYaxis()->SetLabelFont(42);
   Graph_Graph526->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph526->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph526->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph526->GetYaxis()->SetTickLength(0.02);
   Graph_Graph526->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph526->GetYaxis()->SetTitleFont(42);
   Graph_Graph526->GetZaxis()->SetLabelFont(42);
   Graph_Graph526->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph526->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph526->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph526->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph526->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph526);
   
   graph->Draw("p");
   
   Double_t Graph6_fx27[35] = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320,
   340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000,
   2500, 3200 };
   Double_t Graph6_fy27[35] = { 0.5686843, 0.568858, 0.3440307, 0.1322861, 0.009546117, 0.09054696, 0.4567324, 0.3597305, 0.9556115, 1.136652, 1.391905, 2.445345, 2.507813, 3.038338, 4.770437, 4.174817, 3.801651,
   3.981413, 5.621991, 7.323685, 7.344588, 8.092652, 8.319704, 7.209638, 6.763588, 11.10095, 4.898333, 10.69313, 9.317311, 27.26472, 20.49342, 50.65855, 36.42096,
   35.24883, 73.62222 };
   graph = new TGraph(35,Graph6_fx27,Graph6_fy27);
   graph->SetName("Graph6");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#009900");
   graph->SetFillColor(ci);
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#009900");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#009900");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(20);
   graph->SetMarkerSize(1.2);
   
   TH1F *Graph_Graph627 = new TH1F("Graph_Graph627","Graph",100,0,3520);
   Graph_Graph627->SetMinimum(0.008591505);
   Graph_Graph627->SetMaximum(80.98349);
   Graph_Graph627->SetDirectory(nullptr);
   Graph_Graph627->SetStats(0);
   Graph_Graph627->SetLineWidth(2);
   Graph_Graph627->SetMarkerStyle(20);
   Graph_Graph627->SetMarkerSize(0.9);
   Graph_Graph627->GetXaxis()->SetLabelFont(42);
   Graph_Graph627->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph627->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph627->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph627->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph627->GetXaxis()->SetTitleFont(42);
   Graph_Graph627->GetYaxis()->SetLabelFont(42);
   Graph_Graph627->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph627->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph627->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph627->GetYaxis()->SetTickLength(0.02);
   Graph_Graph627->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph627->GetYaxis()->SetTitleFont(42);
   Graph_Graph627->GetZaxis()->SetLabelFont(42);
   Graph_Graph627->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph627->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph627->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph627->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph627->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph627);
   
   graph->Draw("p");
   
   Double_t Graph7_fx28[35] = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320,
   340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000,
   2500, 3200 };
   Double_t Graph7_fy28[35] = { 0.293575, 0.1007213, 0.0280624, 0.05978883, 0.06646673, 0.08684101, 0.1018978, 0.116643, 0.0988204, 0.1573699, 0.1719024, 0.143249, 0.1712456, 0.1408065, 0.2042066, 0.2013843, 0.2800718,
   0.2529427, 0.2545561, 0.06714737, 0.3258328, 0.2984131, 0.2451224, 0.2744096, 0.2691736, 0.04310463, 0.09326893, 0.144625, 0.02086924, 0.486483, 0.228885, 0.5460541, 0.4751852,
   0.6193799, 0.8661393 };
   graph = new TGraph(35,Graph7_fx28,Graph7_fy28);
   graph->SetName("Graph7");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#ffcc00");
   graph->SetFillColor(ci);
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#ffcc00");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#ffcc00");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(39);
   graph->SetMarkerSize(1.2);
   
   TH1F *Graph_Graph728 = new TH1F("Graph_Graph728","Graph",100,0,3520);
   Graph_Graph728->SetMinimum(0.01878231);
   Graph_Graph728->SetMaximum(0.9506663);
   Graph_Graph728->SetDirectory(nullptr);
   Graph_Graph728->SetStats(0);
   Graph_Graph728->SetLineWidth(2);
   Graph_Graph728->SetMarkerStyle(20);
   Graph_Graph728->SetMarkerSize(0.9);
   Graph_Graph728->GetXaxis()->SetLabelFont(42);
   Graph_Graph728->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph728->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph728->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph728->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph728->GetXaxis()->SetTitleFont(42);
   Graph_Graph728->GetYaxis()->SetLabelFont(42);
   Graph_Graph728->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph728->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph728->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph728->GetYaxis()->SetTickLength(0.02);
   Graph_Graph728->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph728->GetYaxis()->SetTitleFont(42);
   Graph_Graph728->GetZaxis()->SetLabelFont(42);
   Graph_Graph728->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph728->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph728->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph728->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph728->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph728);
   
   graph->Draw("p");
   
   Double_t Graph8_fx29[35] = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320,
   340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000,
   2500, 3200 };
   Double_t Graph8_fy29[35] = { 3.637935, 2.432152, 0.1270092, 1.237395, 1.719363, 1.943766, 2.149836, 2.285755, 2.556601, 2.610617, 2.784102, 3.016526, 3.245837, 3.450305, 3.22036, 3.832696, 3.584085,
   3.769753, 4.156521, 4.10738, 4.149141, 4.323337, 4.456559, 4.08432, 3.798486, 4.583156, 3.272468, 4.756914, 6.453889, 9.684518, 9.713786, 10.06041, 7.688224,
   7.844797, 16.83055 };
   graph = new TGraph(35,Graph8_fx29,Graph8_fy29);
   graph->SetName("Graph8");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#009900");
   graph->SetFillColor(ci);
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#009900");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#009900");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(30);
   graph->SetMarkerSize(1.2);
   
   TH1F *Graph_Graph829 = new TH1F("Graph_Graph829","Graph",100,0,3520);
   Graph_Graph829->SetMinimum(0.1143083);
   Graph_Graph829->SetMaximum(18.5009);
   Graph_Graph829->SetDirectory(nullptr);
   Graph_Graph829->SetStats(0);
   Graph_Graph829->SetLineWidth(2);
   Graph_Graph829->SetMarkerStyle(20);
   Graph_Graph829->SetMarkerSize(0.9);
   Graph_Graph829->GetXaxis()->SetLabelFont(42);
   Graph_Graph829->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph829->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph829->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph829->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph829->GetXaxis()->SetTitleFont(42);
   Graph_Graph829->GetYaxis()->SetLabelFont(42);
   Graph_Graph829->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph829->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph829->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph829->GetYaxis()->SetTickLength(0.02);
   Graph_Graph829->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph829->GetYaxis()->SetTitleFont(42);
   Graph_Graph829->GetZaxis()->SetLabelFont(42);
   Graph_Graph829->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph829->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph829->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph829->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph829->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph829);
   
   graph->Draw("p");
   
   Double_t Graph9_fx30[35] = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320,
   340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000,
   2500, 3200 };
   Double_t Graph9_fy30[35] = { 8.385392, 2.8707, 2.454774, 3.522643, 6.307219, 5.898713, 6.048462, 10.29156, 7.505173, 12.05095, 14.43837, 18.70086, 22.25782, 19.06984, 20.07018, 20.30516, 60.03379,
   44.51736, 54.59475, 67.90009, 42.99853, 32.90823, 14.54938, 37.43491, 36.60335, 15.81415, 16.16322, 29.0341, 35.02694, 48.95892, 55.2278, 64.92529, 88.32902,
   86.42032, 2358.684 };
   graph = new TGraph(35,Graph9_fx30,Graph9_fy30);
   graph->SetName("Graph9");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#ff0000");
   graph->SetFillColor(ci);
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#ff0000");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#ff0000");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(34);
   graph->SetMarkerSize(1.2);
   
   TH1F *Graph_Graph930 = new TH1F("Graph_Graph930","Graph",100,0,3520);
   Graph_Graph930->SetMinimum(2.209297);
   Graph_Graph930->SetMaximum(2594.307);
   Graph_Graph930->SetDirectory(nullptr);
   Graph_Graph930->SetStats(0);
   Graph_Graph930->SetLineWidth(2);
   Graph_Graph930->SetMarkerStyle(20);
   Graph_Graph930->SetMarkerSize(0.9);
   Graph_Graph930->GetXaxis()->SetLabelFont(42);
   Graph_Graph930->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph930->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph930->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph930->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph930->GetXaxis()->SetTitleFont(42);
   Graph_Graph930->GetYaxis()->SetLabelFont(42);
   Graph_Graph930->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph930->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph930->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph930->GetYaxis()->SetTickLength(0.02);
   Graph_Graph930->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph930->GetYaxis()->SetTitleFont(42);
   Graph_Graph930->GetZaxis()->SetLabelFont(42);
   Graph_Graph930->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph930->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph930->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph930->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph930->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph930);
   
   graph->Draw("p");
   
   TLegend *leg = new TLegend(0.12,0.7,0.5,0.93,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(62);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("Graph9","Total","PE1");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#ff0000");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(34);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph0","Stat.","PE1");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph1","#eta binning","PE1");

   ci = TColor::GetColor("#ff99ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#ff99ff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph2","I_{h} binning","PE1");

   ci = TColor::GetColor("#9933ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#9933ff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(22);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph3","p binning","PE1");

   ci = TColor::GetColor("#0000cc");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#0000cc");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(23);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph4","I_{h} fit","PE1");

   ci = TColor::GetColor("#ff9933");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#ff9933");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(33);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph5","p fit","PE1");

   ci = TColor::GetColor("#00ffff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#00ffff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(29);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph6","No fit","PE1");

   ci = TColor::GetColor("#009900");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#009900");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph7","corr template I_{h}","PE1");

   ci = TColor::GetColor("#ffcc00");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#ffcc00");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(39);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph8","corr template 1/p","PE1");

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
   c2_473->Modified();
   c2_473->SetSelected(c2_473);
}
