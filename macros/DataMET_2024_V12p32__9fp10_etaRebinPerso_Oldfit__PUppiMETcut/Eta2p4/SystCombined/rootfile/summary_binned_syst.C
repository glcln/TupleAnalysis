#ifdef __CLING__
#pragma cling optimize(0)
#endif
void summary_binned_syst()
{
//=========Macro generated from canvas: c2/c2
//=========  (Mon Jul 27 19:22:11 2026) by ROOT version 6.32.13
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
   Double_t Graph0_fy1[35] = { 1.157404, 0.8746894, 0.8095629, 0.7634615, 0.7725219, 0.8247769, 0.8680853, 0.9099955, 0.9651054, 1.029814, 1.163747, 1.203066, 1.289888, 1.376767, 1.458318, 1.516735, 1.796759,
   1.64722, 1.793063, 1.72266, 1.881578, 1.591966, 1.858053, 1.890577, 2.167856, 2.431867, 3.26518, 4.546232, 6.794394, 12.60873, 15.70587, 20.85993, 13.8627,
   20.02175, 0.0002073794 };
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
   Graph_Graph01->GetXaxis()->SetLabelSize(20);
   Graph_Graph01->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph01->GetXaxis()->SetTitleOffset(1);
   Graph_Graph01->GetXaxis()->SetTitleFont(42);
   Graph_Graph01->GetYaxis()->SetTitle("Systematic Uncertainty [%]");
   Graph_Graph01->GetYaxis()->SetLabelFont(43);
   Graph_Graph01->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph01->GetYaxis()->SetLabelSize(20);
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
   leg->Draw();
   
   Double_t Graph1_fx2[35] = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320,
   340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000,
   2500, 3200 };
   Double_t Graph1_fy2[35] = { 0.3638506, 0.306648, 0.2450109, 0.1885056, 0.6749392, 0.6168187, 0.3060043, 0.3322721, 0.3631413, 0.8183479, 0.9539127, 1.29106, 0.8038759, 1.752162, 0.6565571, 1.625633, 2.043903,
   0.3264785, 1.567554, 2.424407, 3.398037, 1.727581, 2.616632, 1.428461, 3.338683, 3.991723, 3.192472, 7.882345, 13.97108, 30.46013, 27.50976, 52.25127, 38.98395,
   86.51754, 3.878438 };
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
   Graph_Graph12->SetMinimum(0.1696551);
   Graph_Graph12->SetMaximum(95.15044);
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
   Double_t Graph2_fy3[35] = { 5.18086, 0.4832029, 0.9287238, 2.69143, 3.444719, 1.93826, 2.636594, 7.846439, 17.16213, 12.848, 8.033156, 8.197826, 11.85253, 29.19276, 1.800573, 29.36429, 20.59556,
   28.77717, 46.5134, 46.65234, 10.72353, 19.3738, 8.503855, 19.3675, 3.462642, 19.01045, 8.090514, 16.99029, 6.619442, 13.13901, 29.62966, 14.88603, 4.748034,
   8.119667, 51.53971 };
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
   Graph_Graph23->SetMinimum(0.4348826);
   Graph_Graph23->SetMaximum(56.64536);
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
   Double_t Graph3_fy4[35] = { 0.3641248, 0.5861044, 0.4699767, 1.114058, 3.80801, 3.925037, 2.881563, 5.509269, 2.53967, 6.854648, 6.719112, 3.812844, 17.82265, 24.56022, 5.679941, 3.506756, 18.49891,
   29.49142, 15.62674, 4.746413, 8.991003, 19.20399, 8.691335, 7.09486, 28.33023, 5.783296, 22.88575, 49.55159, 30.86644, 57.60232, 43.25455, 40.52071, 44.99802,
   54.69133, 106.3097 };
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
   Graph_Graph34->SetMinimum(0.3277123);
   Graph_Graph34->SetMaximum(116.9043);
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
   Double_t Graph4_fy5[35] = { 0.001335144, 0.005626678, 0.003683567, 0.002646446, 0.00513196, 0.006979704, 0.005120039, 0.004541874, 0.001657009, 0.00191927, 0.004506111, 0.00576973, 0.00641942, 0.003969669, 0.01144409, 0.005674362, 0.01130104,
   0.004589558, 0.01261234, 0.009810925, 0.01251698, 0.005054474, 0.00795126, 0.008523464, 0.004154444, 0.01987815, 0.03941655, 0.05412698, 0.07812977, 0.2540946, 0.3217101, 0.4947782, 0.3098249,
   0.3126264, 0.3183603 };
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
   Graph_Graph45->SetMinimum(0.00120163);
   Graph_Graph45->SetMaximum(0.5441225);
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
   Double_t Graph5_fy6[35] = { 1.636654, 0.7948339, 0.09402037, 0.144124, 0.325501, 0.4289627, 0.5471468, 0.5705714, 0.685668, 0.7227063, 0.87955, 0.8303761, 0.8623958, 0.8910775, 0.9482503, 0.9428024, 1.349735,
   0.8994699, 1.043391, 1.198447, 1.307464, 1.254249, 1.25984, 1.329446, 1.38166, 1.655018, 1.700377, 1.749396, 2.238297, 3.694987, 4.046261, 6.454337, 5.930126,
   8.211077, 7.47323 };
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
   Graph_Graph56->SetMinimum(0.08461833);
   Graph_Graph56->SetMaximum(9.022782);
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
   Double_t Graph6_fy7[35] = { 0.05028248, 0.04799962, 0.04041195, 0.008022785, 0.01635551, 0.01919866, 0.02422333, 0.03441572, 0.06138086, 0.06970763, 0.09740591, 0.09331703, 0.1106024, 0.1389027, 0.1428604, 0.1279831, 0.1999736,
   0.125128, 0.1878023, 0.2096653, 0.2172828, 0.1793325, 0.2542615, 0.229758, 0.2640188, 0.2686262, 0.2561748, 0.2825856, 0.2583504, 0.4149079, 0.4685163, 0.5002975, 0.5377769,
   0.5693078, 0.725162 };
   graph = new TGraph(35,Graph6_fx7,Graph6_fy7);
   graph->SetName("Graph6");
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
   
   TH1F *Graph_Graph67 = new TH1F("Graph_Graph67","Graph",100,0,3520);
   Graph_Graph67->SetMinimum(0.007220507);
   Graph_Graph67->SetMaximum(0.796876);
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
   Double_t Graph7_fy8[35] = { 5.57916, 1.438824, 1.345108, 3.020624, 5.246485, 4.517512, 4.049966, 9.653181, 17.39327, 14.63949, 10.61722, 9.249574, 21.47546, 38.22565, 6.243498, 29.67166, 27.85058,
   41.24942, 49.13744, 47.00314, 14.58342, 27.40915, 12.64143, 20.80558, 28.85164, 20.48178, 24.75936, 53.19749, 35.25609, 67.75951, 61.39243, 71.21101, 61.60228,
   104.9336, 118.4467 };
   graph = new TGraph(35,Graph7_fx8,Graph7_fy8);
   graph->SetName("Graph7");
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
   
   TH1F *Graph_Graph78 = new TH1F("Graph_Graph78","Graph",100,0,3520);
   Graph_Graph78->SetMinimum(1.210597);
   Graph_Graph78->SetMaximum(130.1568);
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
   TLatex *   tex = new TLatex(0.1,0.96,"#scale[1.3]{#it{Private work (CMS data)}}");
   tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.74,0.96,"109 fb^{-1} (13.6 TeV)");
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
   c2->Modified();
   c2->SetSelected(c2);
}
