#ifdef __CLING__
#pragma cling optimize(0)
#endif
void summary_binned_syst()
{
//=========Macro generated from canvas: c2/c2
//=========  (Thu Sep  3 15:08:55 2026) by ROOT version 6.32.13
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
   Double_t Graph0_fy1[35] = { 1.155837, 0.8762997, 0.8102518, 0.7632787, 0.7756702, 0.8313199, 0.8791128, 0.9229993, 0.9784553, 1.041045, 1.174931, 1.212611, 1.295846, 1.382794, 1.465638, 1.523439, 1.808113,
   1.655643, 1.796152, 1.724713, 1.888612, 1.592862, 1.859172, 1.891127, 2.167078, 2.434176, 3.261691, 4.542423, 6.791879, 12.62103, 15.72215, 20.87687, 13.88155,
   20.03137, 0.0002074168 };
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
   Double_t Graph1_fy2[35] = { 0.3701627, 0.3182292, 0.2307653, 0.1851439, 0.6682217, 0.6034911, 0.2883375, 0.3165841, 0.3732085, 0.8356214, 0.9685397, 1.308405, 0.8232117, 1.772726, 0.6723046, 1.645637, 2.061307,
   0.3373027, 1.566505, 2.430439, 3.398204, 1.739717, 2.608919, 1.426411, 3.334045, 3.992152, 3.200579, 7.881677, 13.91994, 30.29484, 27.40663, 52.00907, 38.87976,
   86.06296, 3.827429 };
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
   Graph_Graph12->SetMinimum(0.1666296);
   Graph_Graph12->SetMaximum(94.65074);
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
   Double_t Graph2_fy3[35] = { 5.192029, 0.4683137, 0.9196758, 2.687132, 3.456235, 1.924807, 2.628422, 7.832706, 17.17554, 12.84225, 8.039295, 8.185124, 11.84692, 29.20727, 1.809096, 29.35971, 20.61518,
   28.75788, 46.51379, 46.65174, 10.73071, 19.35833, 8.508325, 19.38355, 3.458107, 19.06133, 8.050823, 17.07914, 6.647933, 13.23761, 30.16419, 15.30315, 5.28081,
   8.788699, 52.25927 };
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
   Graph_Graph23->SetMinimum(0.4214823);
   Graph_Graph23->SetMaximum(57.43836);
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
   Double_t Graph3_fy4[35] = { 0.3727674, 0.5689621, 0.4869878, 1.1132, 3.796762, 3.945136, 2.900207, 5.493289, 2.563453, 6.831819, 6.726611, 3.806674, 17.80487, 24.59071, 5.687547, 3.480482, 18.50035,
   29.47189, 15.64963, 4.741919, 9.001625, 19.17194, 8.695518, 7.096827, 28.34137, 5.730206, 22.95294, 49.64585, 30.88865, 57.77317, 43.4679, 40.51184, 44.99795,
   54.71284, 106.4735 };
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
   Graph_Graph34->SetMinimum(0.3354907);
   Graph_Graph34->SetMaximum(117.0836);
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
   Double_t Graph4_fy5[35] = { 0.005125999, 0.01487136, 0.009524822, 0.00140667, 0.008928776, 0.01335144, 0.01366138, 0.01491308, 0.01425743, 0.01434088, 0.0120163, 0.01231432, 0.008249283, 0.008547306, 0.009202957, 0.01059771, 0.005018711,
   0.0125885, 0.00667572, 0.004810095, 0.006973743, 0.002717972, 0.009596348, 0.00924468, 0.0109911, 0.01466274, 0.004279613, 0.01960993, 0.0445962, 0.07418394, 0.1284242, 0.1505613, 0.2134562,
   0.2039552, 0.234735 };
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
   Graph_Graph45->SetMinimum(0.001266003);
   Graph_Graph45->SetMaximum(0.2580678);
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
   Double_t Graph5_fy6[35] = { 0.4546702, 0.2361596, 0.01550913, 0.04460812, 0.07835627, 0.1220345, 0.1592398, 0.1684189, 0.20293, 0.2095103, 0.2515316, 0.2186537, 0.2282977, 0.2180576, 0.2604604, 0.2722383, 0.3587961,
   0.3359079, 0.2889991, 0.3203988, 0.3479242, 0.3221631, 0.3233433, 0.3558755, 0.3721356, 0.5827904, 0.6022334, 0.5158663, 0.62989, 0.9432793, 1.058698, 1.241446, 1.741242,
   2.249062, 2.010846 };
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
   Graph_Graph56->SetMinimum(0.01395822);
   Graph_Graph56->SetMaximum(2.472417);
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
   Double_t Graph6_fy7[35] = { 3.685611, 3.138703, 0.8573949, 0.9828925, 1.438141, 1.666653, 1.82873, 2.063978, 2.233374, 2.412558, 2.482963, 2.713394, 2.86094, 2.966189, 2.960777, 3.293109, 3.082597,
   3.40699, 3.470767, 3.491449, 3.683436, 3.713429, 3.875709, 4.023278, 3.892314, 4.75738, 4.764819, 5.232573, 6.649995, 14.50525, 15.93622, 26.36421, 22.0435,
   29.8254, 26.95727 };
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
   Graph_Graph67->SetMinimum(0.7716554);
   Graph_Graph67->SetMaximum(32.7222);
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
   Double_t Graph7_fy8[35] = { 0.06040335, 0.05863905, 0.0459075, 0.009155273, 0.02353191, 0.02659559, 0.03142357, 0.04224777, 0.07247925, 0.07731915, 0.1090646, 0.1043558, 0.1209259, 0.1526952, 0.1533508, 0.1477361, 0.2132654,
   0.1348138, 0.2092242, 0.2185225, 0.2460361, 0.2012014, 0.2924562, 0.2630472, 0.3002524, 0.2885342, 0.2707481, 0.2876043, 0.2518654, 0.2726793, 0.2914906, 0.2369404, 0.2956033,
   0.262773, 0.4056931 };
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
   Graph_Graph78->SetMinimum(0.008239746);
   Graph_Graph78->SetMaximum(0.4453468);
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
   Double_t Graph8_fy9[35] = { 6.508705, 3.364981, 1.590687, 3.169372, 5.429933, 4.808096, 4.42115, 9.837176, 17.54143, 14.80708, 10.88285, 9.596392, 21.63265, 38.36263, 6.861395, 29.83414, 28.00792,
   41.35458, 49.25746, 47.11787, 15.00138, 27.60083, 13.1711, 21.16792, 29.09265, 21.00209, 25.21259, 53.54336, 35.81735, 69.29224, 63.66186, 75.58356, 65.16223,
   108.506, 121.7097 };
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
   Graph_Graph89->SetMinimum(1.431619);
   Graph_Graph89->SetMaximum(133.7216);
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
      tex = new TLatex(0.8,0.88,"#bf{|#eta|<2.4}");
   tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.07);
   tex->SetLineWidth(2);
   tex->Draw();
   c2->Modified();
   c2->SetSelected(c2);
}
