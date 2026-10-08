#ifdef __CLING__
#pragma cling optimize(0)
#endif
void summary_binned_syst()
{
//=========Macro generated from canvas: c2/c2
//=========  (Fri Sep  4 10:53:23 2026) by ROOT version 6.32.13
   TCanvas *c2 = new TCanvas("c2", "c2",0,0,800,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c2->SetHighLightColor(2);
   c2->Range(-418.2588,-1.621836,3764.329,3.560128);
   c2->SetFillColor(0);
   c2->SetBorderMode(0);
   c2->SetBorderSize(2);
   c2->SetLogy();
   c2->SetGridx();
   c2->SetGridy();
   c2->SetRightMargin(0.05);
   c2->SetTopMargin(0.05);
   c2->SetBottomMargin(0.12);
   c2->SetFrameLineWidth(2);
   c2->SetFrameBorderMode(0);
   c2->SetFrameLineWidth(2);
   c2->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1[35] = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320,
   340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000,
   2500, 3200 };
   Double_t Graph0_fy1[35] = { 1.504253, 1.168622, 1.116185, 1.140345, 1.178002, 1.211898, 1.298479, 1.33679, 1.477857, 1.531078, 1.732963, 1.912514, 2.180003, 2.625009, 2.691874, 3.131594, 3.565994,
   4.185144, 4.391402, 4.22948, 4.505348, 4.452711, 4.41208, 4.509467, 4.595193, 4.490648, 5.670129, 5.95037, 7.049024, 8.472282, 11.02327, 13.79475, 17.6137,
   22.0026, 2.132163e-08 };
   TGraph *graph = new TGraph(35,Graph0_fx1,Graph0_fy1);
   graph->SetName("Graph0");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetFillStyle(1000);
   graph->SetMarkerStyle(20);
   graph->SetMarkerSize(1.2);
   
   TH1F *Graph_Graph01 = new TH1F("Graph_Graph01","Graph",100,0,3520);
   Graph_Graph01->SetMinimum(0.1);
   Graph_Graph01->SetMaximum(2000);
   Graph_Graph01->SetDirectory(nullptr);
   Graph_Graph01->SetStats(0);
   Graph_Graph01->SetLineWidth(2);
   Graph_Graph01->SetMarkerStyle(20);
   Graph_Graph01->SetMarkerSize(0.9);
   Graph_Graph01->GetXaxis()->SetTitle("Mass bin");
   Graph_Graph01->GetXaxis()->SetRange(1,101);
   Graph_Graph01->GetXaxis()->SetLabelFont(43);
   Graph_Graph01->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph01->GetXaxis()->SetLabelSize(24);
   Graph_Graph01->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph01->GetXaxis()->SetTitleOffset(1);
   Graph_Graph01->GetXaxis()->SetTitleFont(42);
   Graph_Graph01->GetYaxis()->SetTitle("Systematic Uncertainty [%]");
   Graph_Graph01->GetYaxis()->SetLabelFont(43);
   Graph_Graph01->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph01->GetYaxis()->SetLabelSize(24);
   Graph_Graph01->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph01->GetYaxis()->SetTickLength(0.02);
   Graph_Graph01->GetYaxis()->SetTitleOffset(1);
   Graph_Graph01->GetYaxis()->SetTitleFont(42);
   Graph_Graph01->GetZaxis()->SetLabelFont(42);
   Graph_Graph01->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph01->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph01->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph01->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph01->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph01);
   
   graph->Draw("ap");
   
   TLegend *leg = new TLegend(0.12,0.7,0.5,0.93,NULL,"brNDC");
   leg->SetTextFont(62);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Graph","Total","PE1");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
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
   entry=leg->AddEntry("Graph","#eta binning","PE1");

   ci = TColor::GetColor("#ff99ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#ff99ff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph","I_{h} binning","PE1");

   ci = TColor::GetColor("#9933ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#9933ff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(22);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph","p binning","PE1");

   ci = TColor::GetColor("#0000cc");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#0000cc");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(23);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph","p fit","PE1");

   ci = TColor::GetColor("#00ffff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#00ffff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(29);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph","I_{h} fit","PE1");

   ci = TColor::GetColor("#ff9933");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#ff9933");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(33);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph","corr template I_{h}","PE1");

   ci = TColor::GetColor("#ffcc00");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#ffcc00");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(39);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph","corr template 1/p","PE1");

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
   
   Double_t Graph1_fx2[35] = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320,
   340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000,
   2500, 3200 };
   Double_t Graph1_fy2[35] = { 0.09895563, 0.2487838, 0.1454115, 0.1437426, 0.2919793, 0.4586697, 0.6492376, 0.5895734, 0.7731676, 0.9255409, 0.5758286, 0.8746862, 0.492692, 1.409543, 1.143491, 0.8378148, 1.715553,
   1.000667, 3.847575, 2.731848, 4.866052, 3.637469, 5.594242, 5.562627, 8.068932, 8.84707, 8.4921, 9.142124, 8.442652, 7.342887, 8.492422, 11.63744, 14.74919,
   17.8793, 26.15256 };
   graph = new TGraph(35,Graph1_fx2,Graph1_fy2);
   graph->SetName("Graph1");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#ff99ff");
   graph->SetFillColor(ci);
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#ff99ff");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#ff99ff");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(21);
   graph->SetMarkerSize(1.2);
   
   TH1F *Graph_Graph12 = new TH1F("Graph_Graph12","Graph",100,0,3520);
   Graph_Graph12->SetMinimum(0.08906007);
   Graph_Graph12->SetMaximum(28.75792);
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
   
   Double_t Graph2_fx3[35] = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320,
   340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000,
   2500, 3200 };
   Double_t Graph2_fy3[35] = { 3.08044, 1.014507, 0.1363873, 2.026784, 2.978694, 1.000166, 2.088058, 6.120438, 16.08143, 11.83543, 6.068182, 7.022595, 10.78305, 33.55738, 4.899484, 27.47792, 11.69839,
   19.65919, 22.41694, 26.42014, 4.362214, 14.39007, 9.551895, 8.222914, 4.429102, 9.925985, 8.27803, 16.33034, 5.525935, 8.11249, 9.532368, 19.20461, 9.385139,
   7.190847, 7.438171 };
   graph = new TGraph(35,Graph2_fx3,Graph2_fy3);
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
   
   TH1F *Graph_Graph23 = new TH1F("Graph_Graph23","Graph",100,0,3520);
   Graph_Graph23->SetMinimum(0.1227486);
   Graph_Graph23->SetMaximum(36.89948);
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
   
   Double_t Graph3_fx4[35] = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320,
   340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000,
   2500, 3200 };
   Double_t Graph3_fy4[35] = { 0.325954, 0.4012346, 0.3780723, 0.5213499, 3.055936, 4.267406, 1.216102, 3.953177, 2.376568, 6.242406, 6.320238, 6.967878, 17.41587, 24.18164, 10.551, 7.844889, 11.62208,
   24.68098, 14.42491, 18.94492, 31.70974, 30.35002, 33.22171, 33.26639, 59.0322, 32.2318, 45.65543, 71.86703, 43.32974, 85.49888, 91.93797, 120.0691, 80.61356,
   89.84712, 89.4174 };
   graph = new TGraph(35,Graph3_fx4,Graph3_fy4);
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
   
   TH1F *Graph_Graph34 = new TH1F("Graph_Graph34","Graph",100,0,3520);
   Graph_Graph34->SetMinimum(0.2933586);
   Graph_Graph34->SetMaximum(132.0434);
   Graph_Graph34->SetDirectory(nullptr);
   Graph_Graph34->SetStats(0);
   Graph_Graph34->SetLineWidth(2);
   Graph_Graph34->SetMarkerStyle(20);
   Graph_Graph34->SetMarkerSize(0.9);
   Graph_Graph34->GetXaxis()->SetLabelFont(42);
   Graph_Graph34->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph34->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph34->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph34->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph34->GetXaxis()->SetTitleFont(42);
   Graph_Graph34->GetYaxis()->SetLabelFont(42);
   Graph_Graph34->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph34->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph34->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph34->GetYaxis()->SetTickLength(0.02);
   Graph_Graph34->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph34->GetYaxis()->SetTitleFont(42);
   Graph_Graph34->GetZaxis()->SetLabelFont(42);
   Graph_Graph34->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph34->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph34->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph34->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph34->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph34);
   
   graph->Draw("p");
   
   Double_t Graph4_fx5[35] = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320,
   340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000,
   2500, 3200 };
   Double_t Graph4_fy5[35] = { 0.001728535, 0.0009119511, 0.001353025, 0.003552437, 0.007140636, 0.003159046, 0.005656481, 0.008034706, 0.01787543, 0.01422763, 0.01298189, 0.01401305, 0.01869202, 0.005125999, 0.01342893, 0.02262592, 0.02388954,
   0.03834963, 0.01732707, 0.0467658, 0.02176166, 0.04023314, 0.0302434, 0.05193949, 0.04951954, 0.05702972, 0.07208586, 0.08987188, 0.121069, 0.1489043, 0.2074003, 0.2503276, 0.295949,
   0.3553987, 0.3746867 };
   graph = new TGraph(35,Graph4_fx5,Graph4_fy5);
   graph->SetName("Graph4");
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
   
   TH1F *Graph_Graph45 = new TH1F("Graph_Graph45","Graph",100,0,3520);
   Graph_Graph45->SetMinimum(0.000820756);
   Graph_Graph45->SetMaximum(0.4120642);
   Graph_Graph45->SetDirectory(nullptr);
   Graph_Graph45->SetStats(0);
   Graph_Graph45->SetLineWidth(2);
   Graph_Graph45->SetMarkerStyle(20);
   Graph_Graph45->SetMarkerSize(0.9);
   Graph_Graph45->GetXaxis()->SetLabelFont(42);
   Graph_Graph45->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph45->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph45->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph45->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph45->GetXaxis()->SetTitleFont(42);
   Graph_Graph45->GetYaxis()->SetLabelFont(42);
   Graph_Graph45->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph45->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph45->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph45->GetYaxis()->SetTickLength(0.02);
   Graph_Graph45->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph45->GetYaxis()->SetTitleFont(42);
   Graph_Graph45->GetZaxis()->SetLabelFont(42);
   Graph_Graph45->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph45->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph45->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph45->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph45->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph45);
   
   graph->Draw("p");
   
   Double_t Graph5_fx6[35] = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320,
   340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000,
   2500, 3200 };
   Double_t Graph5_fy6[35] = { 1.327586, 0.551784, 0.1535535, 0.459969, 0.6572247, 0.7475257, 0.8748293, 0.8876204, 0.9425759, 1.027405, 1.160502, 1.122403, 1.123917, 1.304317, 1.537275, 1.150596, 1.602983,
   1.421154, 1.860356, 1.543283, 2.050471, 1.697564, 1.990819, 1.863706, 2.059042, 2.24396, 2.333593, 2.701521, 2.856946, 3.176749, 3.459263, 3.794372, 3.945374,
   4.558158, 4.590774 };
   graph = new TGraph(35,Graph5_fx6,Graph5_fy6);
   graph->SetName("Graph5");
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
   
   TH1F *Graph_Graph56 = new TH1F("Graph_Graph56","Graph",100,0,3520);
   Graph_Graph56->SetMinimum(0.1381981);
   Graph_Graph56->SetMaximum(5.034496);
   Graph_Graph56->SetDirectory(nullptr);
   Graph_Graph56->SetStats(0);
   Graph_Graph56->SetLineWidth(2);
   Graph_Graph56->SetMarkerStyle(20);
   Graph_Graph56->SetMarkerSize(0.9);
   Graph_Graph56->GetXaxis()->SetLabelFont(42);
   Graph_Graph56->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph56->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph56->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph56->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph56->GetXaxis()->SetTitleFont(42);
   Graph_Graph56->GetYaxis()->SetLabelFont(42);
   Graph_Graph56->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph56->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph56->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph56->GetYaxis()->SetTickLength(0.02);
   Graph_Graph56->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph56->GetYaxis()->SetTitleFont(42);
   Graph_Graph56->GetZaxis()->SetLabelFont(42);
   Graph_Graph56->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph56->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph56->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph56->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph56->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph56);
   
   graph->Draw("p");
   
   Double_t Graph6_fx7[35] = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320,
   340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000,
   2500, 3200 };
   Double_t Graph6_fy7[35] = { 1.365876, 1.229781, 0.276494, 0.8331776, 1.564455, 2.058816, 2.426767, 2.757823, 2.871776, 3.156042, 3.213644, 3.315926, 3.529751, 3.657222, 3.989458, 3.645885, 3.648984,
   4.941356, 4.197919, 4.300773, 4.544044, 5.080378, 4.610264, 4.989493, 4.901278, 5.201995, 5.532563, 5.846989, 6.244779, 6.752312, 7.403588, 8.006489, 8.79637,
   9.470642, 9.213281 };
   graph = new TGraph(35,Graph6_fx7,Graph6_fy7);
   graph->SetName("Graph6");
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
   
   TH1F *Graph_Graph67 = new TH1F("Graph_Graph67","Graph",100,0,3520);
   Graph_Graph67->SetMinimum(0.2488446);
   Graph_Graph67->SetMaximum(10.39006);
   Graph_Graph67->SetDirectory(nullptr);
   Graph_Graph67->SetStats(0);
   Graph_Graph67->SetLineWidth(2);
   Graph_Graph67->SetMarkerStyle(20);
   Graph_Graph67->SetMarkerSize(0.9);
   Graph_Graph67->GetXaxis()->SetLabelFont(42);
   Graph_Graph67->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph67->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph67->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph67->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph67->GetXaxis()->SetTitleFont(42);
   Graph_Graph67->GetYaxis()->SetLabelFont(42);
   Graph_Graph67->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph67->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph67->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph67->GetYaxis()->SetTickLength(0.02);
   Graph_Graph67->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph67->GetYaxis()->SetTitleFont(42);
   Graph_Graph67->GetZaxis()->SetLabelFont(42);
   Graph_Graph67->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph67->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph67->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph67->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph67->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph67);
   
   graph->Draw("p");
   
   Double_t Graph7_fx8[35] = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320,
   340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000,
   2500, 3200 };
   Double_t Graph7_fy8[35] = { 0.05230904, 0.04726648, 0.0300765, 0.02746582, 0.068748, 0.104332, 0.1323283, 0.1549661, 0.1924515, 0.1923323, 0.2391756, 0.2143085, 0.249064, 0.3028035, 0.3062665, 0.3161132, 0.3830731,
   0.3199697, 0.4222572, 0.4333794, 0.4546702, 0.4570484, 0.5979061, 0.6066263, 0.7341325, 0.828284, 0.8426011, 1.055545, 1.049846, 1.473856, 1.527131, 1.681167, 1.607269,
   1.748896, 2.007127 };
   graph = new TGraph(35,Graph7_fx8,Graph7_fy8);
   graph->SetName("Graph7");
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
   
   TH1F *Graph_Graph78 = new TH1F("Graph_Graph78","Graph",100,0,3520);
   Graph_Graph78->SetMinimum(0.02471924);
   Graph_Graph78->SetMaximum(2.205093);
   Graph_Graph78->SetDirectory(nullptr);
   Graph_Graph78->SetStats(0);
   Graph_Graph78->SetLineWidth(2);
   Graph_Graph78->SetMarkerStyle(20);
   Graph_Graph78->SetMarkerSize(0.9);
   Graph_Graph78->GetXaxis()->SetLabelFont(42);
   Graph_Graph78->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph78->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph78->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph78->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph78->GetXaxis()->SetTitleFont(42);
   Graph_Graph78->GetYaxis()->SetLabelFont(42);
   Graph_Graph78->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph78->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph78->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph78->GetYaxis()->SetTickLength(0.02);
   Graph_Graph78->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph78->GetYaxis()->SetTitleFont(42);
   Graph_Graph78->GetZaxis()->SetLabelFont(42);
   Graph_Graph78->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph78->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph78->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph78->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph78->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph78);
   
   graph->Draw("p");
   
   Double_t Graph8_fx9[35] = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320,
   340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000,
   2500, 3200 };
   Double_t Graph8_fy9[35] = { 3.936847, 2.106382, 1.236724, 2.570454, 4.750637, 5.069376, 3.823417, 7.977437, 16.61972, 13.90321, 9.583038, 10.70478, 20.93721, 41.65207, 12.73795, 29.01386, 17.42459,
   32.25976, 27.67576, 33.21677, 33.06922, 34.49866, 35.65472, 35.4159, 60.16182, 35.61792, 47.89552, 74.78732, 45.57681, 86.94508, 93.8416, 123.2579, 84.91184,
   95.0876, 94.04723 };
   graph = new TGraph(35,Graph8_fx9,Graph8_fy9);
   graph->SetName("Graph8");
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
   
   TH1F *Graph_Graph89 = new TH1F("Graph_Graph89","Graph",100,0,3520);
   Graph_Graph89->SetMinimum(1.113052);
   Graph_Graph89->SetMaximum(135.4601);
   Graph_Graph89->SetDirectory(nullptr);
   Graph_Graph89->SetStats(0);
   Graph_Graph89->SetLineWidth(2);
   Graph_Graph89->SetMarkerStyle(20);
   Graph_Graph89->SetMarkerSize(0.9);
   Graph_Graph89->GetXaxis()->SetLabelFont(42);
   Graph_Graph89->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph89->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph89->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph89->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph89->GetXaxis()->SetTitleFont(42);
   Graph_Graph89->GetYaxis()->SetLabelFont(42);
   Graph_Graph89->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph89->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph89->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph89->GetYaxis()->SetTickLength(0.02);
   Graph_Graph89->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph89->GetYaxis()->SetTitleFont(42);
   Graph_Graph89->GetZaxis()->SetLabelFont(42);
   Graph_Graph89->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph89->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph89->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph89->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph89->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph89);
   
   graph->Draw("p");
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
   c2->Modified();
   c2->SetSelected(c2);
}
