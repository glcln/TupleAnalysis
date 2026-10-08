#ifdef __CLING__
#pragma cling optimize(0)
#endif
void summary_binned_syst()
{
//=========Macro generated from canvas: c2/c2
//=========  (Fri Sep  4 10:54:08 2026) by ROOT version 6.32.13
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
   Double_t Graph0_fy1[35] = { 1.138596, 0.8483396, 0.7715915, 0.7214105, 0.741766, 0.780033, 0.8113061, 0.874369, 0.9559523, 1.047617, 1.180648, 1.232341, 1.289239, 1.376083, 1.50125, 1.447659, 1.79705,
   1.628879, 1.802097, 1.65547, 1.816542, 1.57189, 1.830466, 1.867857, 2.163219, 2.534534, 3.239282, 4.571309, 6.483943, 11.92077, 14.90786, 21.02214, 8.293296,
   11.9194, 8.760372e-05 };
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
   Double_t Graph1_fy2[35] = { 0.4340231, 0.3593743, 0.06848574, 0.1344085, 0.6331027, 0.5116105, 0.1023054, 0.3596783, 0.4934907, 0.9884596, 1.108515, 1.453972, 0.9222627, 1.930153, 0.7545114, 1.662493, 2.132332,
   0.4630804, 1.539576, 2.512062, 3.556573, 2.060902, 2.571678, 1.714659, 3.472722, 3.24378, 2.38502, 3.766704, 6.118298, 8.873701, 5.243909, 11.27026, 26.86884,
   36.7716, 53.7057 };
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
   Graph_Graph12->SetMinimum(0.06163716);
   Graph_Graph12->SetMaximum(59.06942);
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
   Double_t Graph2_fy3[35] = { 5.223489, 0.3582239, 0.8582354, 2.696198, 3.483343, 1.88337, 2.689886, 7.731861, 17.36909, 12.69209, 8.244491, 8.002925, 11.63533, 29.51183, 2.159524, 29.34217, 20.95652,
   28.60715, 46.31942, 46.7931, 10.82888, 19.14715, 8.388901, 19.02804, 3.514409, 18.77096, 8.752382, 14.48636, 8.343798, 14.09372, 11.10761, 13.19295, 14.13582,
   10.769, 12.38504 };
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
   Graph_Graph23->SetMinimum(0.3224015);
   Graph_Graph23->SetMaximum(51.43659);
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
   Double_t Graph3_fy4[35] = { 0.496161, 0.4518867, 0.5889952, 1.153421, 3.717792, 4.030454, 2.932906, 5.483472, 2.753532, 6.615162, 6.691766, 3.856218, 17.58418, 25.05423, 5.691433, 3.129286, 18.51275,
   29.2548, 15.81054, 4.418659, 8.693064, 18.92985, 8.213592, 7.300413, 27.65923, 4.789233, 23.81043, 51.97179, 30.09222, 64.93111, 59.92975, 56.55095, 43.70437,
   38.65878, 61.11008 };
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
   Graph_Graph34->SetMinimum(0.406698);
   Graph_Graph34->SetMaximum(71.37903);
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
   Double_t Graph4_fy5[35] = { 0.01285672, 0.01011491, 0.004839897, 0.004661083, 0.01044273, 0.01137257, 0.00950098, 0.008970499, 0.01107454, 0.01006722, 0.01139641, 0.007879734, 0.004434586, 0.008964539, 0.006347895, 0.006365776, 0.01460314,
   0.008547306, 0.005704165, 0.006830692, 0.008618832, 0.009691715, 0.01672506, 0.01461506, 0.01434088, 0.02209544, 0.03559589, 0.04795194, 0.04409552, 0.162971, 0.1853943, 0.4166722, 0.2327204,
   0.3752112, 0.4514694 };
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
   Graph_Graph45->SetMinimum(0.003991127);
   Graph_Graph45->SetMaximum(0.4961729);
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
   Double_t Graph5_fy6[35] = { 0.4619896, 0.2397716, 0.02766848, 0.04546642, 0.08858442, 0.129199, 0.1926661, 0.2068758, 0.2393723, 0.2295852, 0.2540946, 0.2374649, 0.19418, 0.2230525, 0.2542734, 0.1700163, 0.286603,
   0.1935124, 0.1564026, 0.2527595, 0.216341, 0.2488613, 0.2580166, 0.305438, 0.2277851, 0.2161741, 0.1797318, 0.05679131, 0.1983047, 0.6045282, 0.5085051, 1.326966, 1.025295,
   1.256168, 1.531869 };
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
   Graph_Graph56->SetMinimum(0.02490163);
   Graph_Graph56->SetMaximum(1.682289);
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
   Double_t Graph6_fy7[35] = { 3.655148, 3.114337, 0.8333683, 0.9977937, 1.424479, 1.632655, 1.779819, 2.013636, 2.203727, 2.389026, 2.457631, 2.726722, 2.909005, 3.041947, 2.983057, 3.333366, 3.218997,
   3.44646, 3.319979, 3.697717, 3.679252, 3.853643, 3.88484, 3.898287, 3.648531, 3.967786, 3.743351, 4.177296, 4.743254, 8.702731, 9.597433, 17.48911, 13.0793,
   17.87479, 21.19975 };
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
   Graph_Graph67->SetMinimum(0.7500315);
   Graph_Graph67->SetMaximum(23.23639);
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
   Double_t Graph7_fy8[35] = { 0.04726052, 0.04675388, 0.03493428, 0.009965897, 0.02405643, 0.02194643, 0.02009869, 0.02381802, 0.05215406, 0.05872846, 0.08744001, 0.0818789, 0.09815693, 0.1266181, 0.1318812, 0.1239538, 0.1839221,
   0.126642, 0.1854479, 0.2045751, 0.2200246, 0.1776695, 0.2544761, 0.2264857, 0.2596259, 0.2822101, 0.2845526, 0.3281534, 0.2269387, 0.1611948, 0.1636386, 0.196743, 0.1212358,
   0.1297593, 0.1784086 };
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
   Graph_Graph78->SetMinimum(0.008969307);
   Graph_Graph78->SetMaximum(0.3599721);
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
   Double_t Graph8_fy9[35] = { 6.526234, 3.307601, 1.542738, 3.183731, 5.379997, 4.831635, 4.439761, 9.738696, 17.75785, 14.58382, 11.02209, 9.489367, 21.34494, 38.90503, 6.989972, 29.77869, 28.28695,
   41.09759, 49.11375, 47.24351, 14.91359, 27.32425, 12.7681, 20.90772, 28.4175, 20.20153, 25.95861, 54.43868, 32.82114, 68.64171, 63.69558, 65.18324, 55.4328,
   58.53152, 84.99497 };
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
   Graph_Graph89->SetMinimum(1.388464);
   Graph_Graph89->SetMaximum(93.3402);
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
