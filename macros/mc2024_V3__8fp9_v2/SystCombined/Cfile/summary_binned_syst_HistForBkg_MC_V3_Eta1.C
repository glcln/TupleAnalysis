#ifdef __CLING__
#pragma cling optimize(0)
#endif
void summary_binned_syst_HistForBkg_MC_V3_Eta1()
{
//=========Macro generated from canvas: c2_157/c2
//=========  (Sun Sep  6 11:16:22 2026) by ROOT version 6.32.13
   TCanvas *c2_157 = new TCanvas("c2_157", "c2",0,0,800,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c2_157->SetHighLightColor(2);
   c2_157->Range(-470.5883,-1.621836,4235.294,3.560128);
   c2_157->SetFillColor(0);
   c2_157->SetBorderMode(0);
   c2_157->SetBorderSize(2);
   c2_157->SetLogy();
   c2_157->SetGridx();
   c2_157->SetGridy();
   c2_157->SetRightMargin(0.05);
   c2_157->SetTopMargin(0.05);
   c2_157->SetBottomMargin(0.12);
   c2_157->SetFrameLineWidth(2);
   c2_157->SetFrameBorderMode(0);
   c2_157->SetFrameLineWidth(2);
   c2_157->SetFrameBorderMode(0);
   
   TH1D *frameSummary_158__1 = new TH1D("frameSummary_158__1","",1,0,4000);
   frameSummary_158__1->SetMinimum(0.1);
   frameSummary_158__1->SetMaximum(2000);
   frameSummary_158__1->SetDirectory(nullptr);
   frameSummary_158__1->SetStats(0);
   frameSummary_158__1->SetLineWidth(2);
   frameSummary_158__1->SetMarkerStyle(20);
   frameSummary_158__1->SetMarkerSize(0.9);
   frameSummary_158__1->GetXaxis()->SetTitle("Mass (GeV)");
   frameSummary_158__1->GetXaxis()->SetLabelFont(43);
   frameSummary_158__1->GetXaxis()->SetLabelOffset(0.015);
   frameSummary_158__1->GetXaxis()->SetLabelSize(24);
   frameSummary_158__1->GetXaxis()->SetTitleSize(0.05);
   frameSummary_158__1->GetXaxis()->SetTitleOffset(1);
   frameSummary_158__1->GetXaxis()->SetTitleFont(42);
   frameSummary_158__1->GetYaxis()->SetTitle("Systematic Uncertainty [%]");
   frameSummary_158__1->GetYaxis()->SetLabelFont(43);
   frameSummary_158__1->GetYaxis()->SetLabelOffset(0.015);
   frameSummary_158__1->GetYaxis()->SetLabelSize(24);
   frameSummary_158__1->GetYaxis()->SetTitleSize(0.05);
   frameSummary_158__1->GetYaxis()->SetTickLength(0.02);
   frameSummary_158__1->GetYaxis()->SetTitleOffset(1);
   frameSummary_158__1->GetYaxis()->SetTitleFont(42);
   frameSummary_158__1->GetZaxis()->SetLabelFont(42);
   frameSummary_158__1->GetZaxis()->SetLabelOffset(0.015);
   frameSummary_158__1->GetZaxis()->SetLabelSize(0.05);
   frameSummary_158__1->GetZaxis()->SetTitleSize(0.065);
   frameSummary_158__1->GetZaxis()->SetTitleOffset(1.1);
   frameSummary_158__1->GetZaxis()->SetTitleFont(42);
   frameSummary_158__1->Draw("AXIS");
   
   TH1D *frameSummary_158__2 = new TH1D("frameSummary_158__2","",1,0,4000);
   frameSummary_158__2->SetMinimum(0.1);
   frameSummary_158__2->SetMaximum(2000);
   frameSummary_158__2->SetDirectory(nullptr);
   frameSummary_158__2->SetStats(0);
   frameSummary_158__2->SetLineWidth(2);
   frameSummary_158__2->SetMarkerStyle(20);
   frameSummary_158__2->SetMarkerSize(0.9);
   frameSummary_158__2->GetXaxis()->SetTitle("Mass (GeV)");
   frameSummary_158__2->GetXaxis()->SetLabelFont(43);
   frameSummary_158__2->GetXaxis()->SetLabelOffset(0.015);
   frameSummary_158__2->GetXaxis()->SetLabelSize(24);
   frameSummary_158__2->GetXaxis()->SetTitleSize(0.05);
   frameSummary_158__2->GetXaxis()->SetTitleOffset(1);
   frameSummary_158__2->GetXaxis()->SetTitleFont(42);
   frameSummary_158__2->GetYaxis()->SetTitle("Systematic Uncertainty [%]");
   frameSummary_158__2->GetYaxis()->SetLabelFont(43);
   frameSummary_158__2->GetYaxis()->SetLabelOffset(0.015);
   frameSummary_158__2->GetYaxis()->SetLabelSize(24);
   frameSummary_158__2->GetYaxis()->SetTitleSize(0.05);
   frameSummary_158__2->GetYaxis()->SetTickLength(0.02);
   frameSummary_158__2->GetYaxis()->SetTitleOffset(1);
   frameSummary_158__2->GetYaxis()->SetTitleFont(42);
   frameSummary_158__2->GetZaxis()->SetLabelFont(42);
   frameSummary_158__2->GetZaxis()->SetLabelOffset(0.015);
   frameSummary_158__2->GetZaxis()->SetLabelSize(0.05);
   frameSummary_158__2->GetZaxis()->SetTitleSize(0.065);
   frameSummary_158__2->GetZaxis()->SetTitleOffset(1.1);
   frameSummary_158__2->GetZaxis()->SetTitleFont(42);
   frameSummary_158__2->Draw("SAME AXIG");
   
   Double_t Graph0_fx1[35] = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320,
   340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000,
   2500, 3200 };
   Double_t Graph0_fy1[35] = { 1.206793, 0.9762654, 1.004466, 1.041433, 1.074243, 1.123617, 1.199819, 1.254836, 1.351818, 1.513446, 2.031351, 2.348726, 2.766587, 3.543488, 3.573905, 4.060887, 4.572309,
   5.323453, 7.792613, 6.87672, 8.108451, 7.60794, 8.294249, 8.89111, 10.34133, 14.30103, 19.59167, 26.17517, 29.29408, 34.97247, 81.4726, 180.2989, 298.3757,
   349.3395, 539.065 };
   TGraph *graph = new TGraph(35,Graph0_fx1,Graph0_fy1);
   graph->SetName("Graph0");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetFillStyle(1000);
   graph->SetMarkerStyle(20);
   graph->SetMarkerSize(1.2);
   
   TH1F *Graph_Graph01 = new TH1F("Graph_Graph01","Graph",100,0,3520);
   Graph_Graph01->SetMinimum(0.8786389);
   Graph_Graph01->SetMaximum(592.8739);
   Graph_Graph01->SetDirectory(nullptr);
   Graph_Graph01->SetStats(0);
   Graph_Graph01->SetLineWidth(2);
   Graph_Graph01->SetMarkerStyle(20);
   Graph_Graph01->SetMarkerSize(0.9);
   Graph_Graph01->GetXaxis()->SetLabelFont(42);
   Graph_Graph01->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph01->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph01->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph01->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph01->GetXaxis()->SetTitleFont(42);
   Graph_Graph01->GetYaxis()->SetLabelFont(42);
   Graph_Graph01->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph01->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph01->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph01->GetYaxis()->SetTickLength(0.02);
   Graph_Graph01->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph01->GetYaxis()->SetTitleFont(42);
   Graph_Graph01->GetZaxis()->SetLabelFont(42);
   Graph_Graph01->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph01->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph01->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph01->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph01->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph01);
   
   graph->Draw("p");
   
   Double_t Graph1_fx2[35] = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320,
   340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000,
   2500, 3200 };
   Double_t Graph1_fy2[35] = { 0.1166274, 0.2601418, 0.1087582, 0.3272593, 0.5369486, 0.7425342, 0.777559, 0.9995604, 0.6936179, 0.6424678, 1.032564, 0.1942332, 0.2830658, 0.854149, 0.7962749, 1.940014, 3.190288,
   4.015211, 3.832979, 6.10608, 8.168288, 6.130369, 5.721247, 3.691451, 6.874278, 14.27671, 17.09699, 24.62003, 26.38389, 27.13225, 31.57157, 32.70875, 51.4607,
   60.07245, 67.23887 };
   graph = new TGraph(35,Graph1_fx2,Graph1_fy2);
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
   
   TH1F *Graph_Graph12 = new TH1F("Graph_Graph12","Graph",100,0,3520);
   Graph_Graph12->SetMinimum(0.09788241);
   Graph_Graph12->SetMaximum(73.95188);
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
   Double_t Graph2_fy3[35] = { 2.748618, 0.7573831, 1.296205, 1.080616, 1.743798, 2.578228, 3.700897, 8.422753, 12.56858, 13.59173, 5.829528, 6.03273, 7.593691, 13.84706, 1.890183, 9.509036, 34.94448,
   18.9383, 18.90472, 29.42169, 7.455548, 12.83507, 9.729415, 28.57156, 2.063749, 8.714217, 11.34989, 14.31258, 18.16928, 7.940486, 28.58163, 25.72013, 23.15174,
   85.86554, 59.63367 };
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
   Graph_Graph23->SetMinimum(0.6816448);
   Graph_Graph23->SetMaximum(94.37635);
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
   Double_t Graph3_fy4[35] = { 1.167003, 0.5017853, 0.7954252, 1.305485, 4.11971, 4.864851, 1.183643, 7.18998, 3.153789, 6.500084, 4.738237, 11.54193, 22.61231, 13.88497, 16.86464, 21.32907, 24.35287,
   33.11784, 17.89224, 47.5085, 38.51061, 37.76184, 37.82095, 35.2155, 42.03557, 53.5602, 58.2696, 69.70799, 74.33448, 76.95971, 76.13064, 69.01828, 74.1605,
   77.3147, 93.3659 };
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
   Graph_Graph34->SetMinimum(0.4516068);
   Graph_Graph34->SetMaximum(102.6523);
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
   Double_t Graph4_fy5[35] = { 0.05577743, 0.05577759, 0.003688784, 0.08269923, 0.128044, 0.1588383, 0.1771398, 0.1901194, 0.2578199, 0.246774, 0.2903701, 0.3628751, 0.3290355, 0.3988756, 0.3911501, 0.3513447, 0.4242974,
   0.3753735, 0.4491278, 0.5480094, 0.5666185, 0.5443781, 0.602179, 0.7236451, 0.9317258, 0.8536708, 0.6223319, 0.4998775, 0.4004128, 0.4346726, 1.359524, 1.126323, 0.9000276,
   0.1335293, 0.1001037 };
   graph = new TGraph(35,Graph4_fx5,Graph4_fy5);
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
   
   TH1F *Graph_Graph45 = new TH1F("Graph_Graph45","Graph",100,0,3520);
   Graph_Graph45->SetMinimum(0.003319906);
   Graph_Graph45->SetMaximum(1.495107);
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
   Double_t Graph5_fy6[35] = { 0.01904203, 0.01904177, 0.01804824, 0.01229906, 0.006718103, 0.009466727, 0.04370122, 0.09077488, 0.2291027, 0.3511692, 0.6605604, 1.004545, 1.302828, 2.083111, 2.525356, 2.857032, 3.968775,
   4.010627, 5.298801, 6.391421, 7.266719, 7.325301, 9.683445, 11.1392, 12.34691, 12.06616, 12.26028, 8.748708, 7.534426, 5.891105, 8.065285, 9.014597, 6.511752,
   1.501851, 0.04777961 };
   graph = new TGraph(35,Graph5_fx6,Graph5_fy6);
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
   
   TH1F *Graph_Graph56 = new TH1F("Graph_Graph56","Graph",100,0,3520);
   Graph_Graph56->SetMinimum(0.006046293);
   Graph_Graph56->SetMaximum(13.58092);
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
   Double_t Graph6_fy7[35] = { 0.3658669, 0.3660108, 0.06186597, 0.4706176, 0.846038, 0.9771428, 1.437576, 1.232398, 2.274128, 1.732048, 0.9503464, 2.783662, 4.690055, 8.623573, 0.5233601, 12.07342, 3.973226,
   16.53624, 16.88647, 8.05754, 13.47459, 30.76712, 13.16582, 13.3883, 6.401564, 2.544046, 5.715553, 8.959305, 25.66624, 58.16858, 79.44132, 126.0934, 38.97013,
   1.330871, 0.3840081 };
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
   graph->SetMarkerStyle(20);
   graph->SetMarkerSize(1.2);
   
   TH1F *Graph_Graph67 = new TH1F("Graph_Graph67","Graph",100,0,3520);
   Graph_Graph67->SetMinimum(0.05567938);
   Graph_Graph67->SetMaximum(138.6966);
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
   Double_t Graph7_fy8[35] = { 1.052693, 0.3204832, 0.3490509, 0.6708509, 0.7920114, 0.9033634, 0.9760267, 1.033001, 1.048504, 1.119378, 1.139152, 1.230311, 1.032552, 1.072937, 1.277231, 1.135441, 1.144797,
   1.366222, 1.235255, 1.547807, 1.574443, 1.52286, 1.452539, 1.586728, 0.952556, 0.4782657, 1.050144, 1.480944, 1.421211, 0.05992413, 2.272808, 3.736012, 1.686065,
   0.6922605, 0.8406764 };
   graph = new TGraph(35,Graph7_fx8,Graph7_fy8);
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
   
   TH1F *Graph_Graph78 = new TH1F("Graph_Graph78","Graph",100,0,3520);
   Graph_Graph78->SetMinimum(0.05393172);
   Graph_Graph78->SetMaximum(4.103621);
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
   Double_t Graph8_fy9[35] = { 1.281651, 0.8734929, 0.2187512, 1.303558, 2.054392, 2.553105, 2.941381, 3.154282, 3.413673, 3.405749, 3.365306, 3.954678, 4.186921, 4.651643, 3.974318, 5.242215, 4.660167,
   6.558635, 5.762239, 5.545922, 5.689959, 7.814414, 6.354112, 6.386923, 6.620176, 6.559714, 6.529883, 8.589003, 9.720059, 9.772001, 9.189703, 7.342899, 1.613827,
   10.43936, 18.23756 };
   graph = new TGraph(35,Graph8_fx9,Graph8_fy9);
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
   
   TH1F *Graph_Graph89 = new TH1F("Graph_Graph89","Graph",100,0,3520);
   Graph_Graph89->SetMinimum(0.1968761);
   Graph_Graph89->SetMaximum(20.03944);
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
   
   Double_t Graph9_fx10[35] = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320,
   340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000,
   2500, 3200 };
   Double_t Graph9_fy10[35] = { 3.625053, 1.647835, 1.871806, 2.493993, 5.130244, 6.283919, 5.174887, 11.67361, 13.53128, 15.57966, 8.646992, 13.90893, 24.43597, 20.61812, 18.03754, 24.54917, 43.40763,
   39.50975, 28.56476, 57.28499, 41.94164, 42.46762, 41.99083, 48.13585, 46.0814, 59.51938, 66.29291, 80.67276, 86.96791, 89.86363, 120.016, 197.8712, 312.6671,
   372.9732, 554.7241 };
   graph = new TGraph(35,Graph9_fx10,Graph9_fy10);
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
   
   TH1F *Graph_Graph910 = new TH1F("Graph_Graph910","Graph",100,0,3520);
   Graph_Graph910->SetMinimum(1.483051);
   Graph_Graph910->SetMaximum(610.0318);
   Graph_Graph910->SetDirectory(nullptr);
   Graph_Graph910->SetStats(0);
   Graph_Graph910->SetLineWidth(2);
   Graph_Graph910->SetMarkerStyle(20);
   Graph_Graph910->SetMarkerSize(0.9);
   Graph_Graph910->GetXaxis()->SetLabelFont(42);
   Graph_Graph910->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph910->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph910->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph910->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph910->GetXaxis()->SetTitleFont(42);
   Graph_Graph910->GetYaxis()->SetLabelFont(42);
   Graph_Graph910->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph910->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph910->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph910->GetYaxis()->SetTickLength(0.02);
   Graph_Graph910->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph910->GetYaxis()->SetTitleFont(42);
   Graph_Graph910->GetZaxis()->SetLabelFont(42);
   Graph_Graph910->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph910->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph910->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph910->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph910->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph910);
   
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
      tex = new TLatex(0.8,0.88,"#bf{|#eta|<1}");
   tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.07);
   tex->SetLineWidth(2);
   tex->Draw();
   c2_157->Modified();
   c2_157->SetSelected(c2_157);
}
