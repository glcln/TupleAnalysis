#ifdef __CLING__
#pragma cling optimize(0)
#endif
void summary_binned_syst()
{
//=========Macro generated from canvas: c1/c1
//=========  (Sat Jul 18 11:02:09 2026) by ROOT version 6.32.13
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,700,500);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c1->SetHighLightColor(2);
   c1->Range(-418.2588,-0.3883565,3764.329,3.495208);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetLogy();
   c1->SetGridx();
   c1->SetGridy();
   c1->SetRightMargin(0.05);
   c1->SetTopMargin(0.05);
   c1->SetFrameLineWidth(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameLineWidth(2);
   c1->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1[35] = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320,
   340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000,
   2500, 3200 };
   Double_t Graph0_fy1[35] = { 1.57523, 1.236004, 1.16143, 1.181782, 1.23557, 1.287905, 1.349175, 1.401724, 1.531397, 1.631551, 2.03532, 2.177246, 2.460404, 2.81597, 2.789593, 2.978634, 3.587991,
   3.571823, 3.915967, 3.334936, 3.634427, 3.278154, 3.173272, 3.262585, 3.44876, 3.609638, 4.482384, 4.624461, 5.333817, 6.302278, 7.866167, 9.548921, 11.41219,
   13.1411, 8.422409e-08 };
   TGraph *graph = new TGraph(35,Graph0_fx1,Graph0_fy1);
   graph->SetName("Graph0");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetFillStyle(1000);
   graph->SetMarkerStyle(20);
   graph->SetMarkerSize(0.9);
   
   TH1F *Graph_Graph01 = new TH1F("Graph_Graph01","Graph",100,0,3520);
   Graph_Graph01->SetMinimum(1);
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
   entry->SetLineColor(28);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(28);
   entry->SetMarkerStyle(34);
   entry->SetMarkerSize(0.9);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph0","Stat.","PE1");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(0.9);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph","#eta binning","PE1");
   entry->SetLineColor(30);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(30);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(0.9);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph","I_{h} binning","PE1");
   entry->SetLineColor(38);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(38);
   entry->SetMarkerStyle(22);
   entry->SetMarkerSize(0.9);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph","p binning","PE1");
   entry->SetLineColor(46);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(46);
   entry->SetMarkerStyle(23);
   entry->SetMarkerSize(0.9);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph","p fit","PE1");
   entry->SetLineColor(47);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(47);
   entry->SetMarkerStyle(47);
   entry->SetMarkerSize(0.9);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph","I_{h} fit","PE1");
   entry->SetLineColor(39);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(39);
   entry->SetMarkerStyle(29);
   entry->SetMarkerSize(0.9);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph","corr template I_{h}","PE1");
   entry->SetLineColor(13);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(13);
   entry->SetMarkerStyle(49);
   entry->SetMarkerSize(0.9);
   entry->SetTextFont(62);
   leg->Draw();
   
   Double_t Graph1_fx2[35] = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320,
   340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000,
   2500, 3200 };
   Double_t Graph1_fy2[35] = { 0.2334356, 0.3331542, 0.1702785, 0.3421783, 0.4272401, 0.4506171, 0.6142259, 0.7013202, 0.7671595, 0.9473443, 0.7230163, 1.231027, 1.236963, 1.864254, 1.533318, 2.410114, 3.093982,
   2.780581, 4.065299, 4.127002, 5.040932, 4.761302, 4.819548, 4.536641, 6.077123, 5.782068, 5.660701, 6.762397, 6.528318, 7.294792, 8.484507, 9.547085, 10.36296,
   12.14884, 11.16902 };
   graph = new TGraph(35,Graph1_fx2,Graph1_fy2);
   graph->SetName("Graph1");
   graph->SetTitle("Graph");
   graph->SetFillColor(30);
   graph->SetFillStyle(1000);
   graph->SetLineColor(30);
   graph->SetMarkerColor(30);
   graph->SetMarkerStyle(21);
   graph->SetMarkerSize(0.9);
   
   TH1F *Graph_Graph12 = new TH1F("Graph_Graph12","Graph",100,0,3520);
   Graph_Graph12->SetMinimum(0.1532507);
   Graph_Graph12->SetMaximum(13.3467);
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
   Double_t Graph2_fy3[35] = { 1.467156, 0.2794385, 0.2333283, 1.583946, 3.088093, 0.95855, 1.835614, 6.272948, 16.31513, 11.66707, 4.047561, 6.286049, 8.018213, 32.74247, 5.05693, 23.64573, 6.509817,
   9.215957, 6.421947, 9.738148, 4.241788, 9.426081, 4.507148, 3.795815, 0.8474946, 5.154169, 12.87497, 11.77664, 11.13166, 5.121642, 7.503164, 10.81927, 18.43788,
   8.434576, 9.36659 };
   graph = new TGraph(35,Graph2_fx3,Graph2_fy3);
   graph->SetName("Graph2");
   graph->SetTitle("Graph");
   graph->SetFillColor(38);
   graph->SetFillStyle(1000);
   graph->SetLineColor(38);
   graph->SetMarkerColor(38);
   graph->SetMarkerStyle(22);
   graph->SetMarkerSize(0.9);
   
   TH1F *Graph_Graph23 = new TH1F("Graph_Graph23","Graph",100,0,3520);
   Graph_Graph23->SetMinimum(0.2099955);
   Graph_Graph23->SetMaximum(35.99338);
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
   Double_t Graph3_fy4[35] = { 0.3289282, 0.2352536, 0.217104, 0.3217578, 2.72904, 4.635692, 1.370716, 3.16298, 2.410388, 6.344008, 7.44704, 3.786576, 19.01602, 15.77424, 21.25785, 16.65814, 21.03843,
   33.54834, 36.84763, 33.7777, 41.97396, 38.62944, 35.73557, 36.94501, 55.69935, 34.89578, 43.14321, 60.20422, 46.58511, 62.22812, 56.97393, 68.57404, 44.80432,
   40.92231, 39.94886 };
   graph = new TGraph(35,Graph3_fx4,Graph3_fy4);
   graph->SetName("Graph3");
   graph->SetTitle("Graph");
   graph->SetFillColor(46);
   graph->SetFillStyle(1000);
   graph->SetLineColor(46);
   graph->SetMarkerColor(46);
   graph->SetMarkerStyle(23);
   graph->SetMarkerSize(0.9);
   
   TH1F *Graph_Graph34 = new TH1F("Graph_Graph34","Graph",100,0,3520);
   Graph_Graph34->SetMinimum(0.1953936);
   Graph_Graph34->SetMaximum(75.40973);
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
   Double_t Graph4_fy5[35] = { 0.008785725, 0.001168251, 0.0003576279, 0.001442432, 0.00320673, 0.003421307, 0.007498264, 0.01233816, 0.01885891, 0.01690388, 0.02400875, 0.01860857, 0.02557039, 0.02318621, 0.03552437, 0.03086329, 0.02942085,
   0.06769896, 0.06217957, 0.0561595, 0.07665157, 0.07600784, 0.07021427, 0.06257296, 0.0619173, 0.06630421, 0.07578135, 0.08440018, 0.09829998, 0.1194, 0.1400232, 0.1693249, 0.2077341,
   0.2433181, 0.3067613 };
   graph = new TGraph(35,Graph4_fx5,Graph4_fy5);
   graph->SetName("Graph4");
   graph->SetTitle("Graph");
   graph->SetFillColor(47);
   graph->SetFillStyle(1000);
   graph->SetLineColor(47);
   graph->SetMarkerColor(47);
   graph->SetMarkerStyle(47);
   graph->SetMarkerSize(0.9);
   
   TH1F *Graph_Graph45 = new TH1F("Graph_Graph45","Graph",100,0,3520);
   Graph_Graph45->SetMinimum(0.0003218651);
   Graph_Graph45->SetMaximum(0.3374016);
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
   Double_t Graph5_fy6[35] = { 1.44105, 0.5720556, 0.2568364, 0.6788373, 0.8782268, 0.9541512, 1.043677, 1.003027, 1.048899, 1.074123, 1.144683, 1.107907, 1.068044, 1.277626, 1.264179, 1.060808, 1.283848,
   0.991118, 1.449084, 1.178694, 1.369023, 1.256955, 1.342309, 1.433766, 1.789021, 1.780343, 1.841283, 2.224219, 2.371609, 2.607262, 2.873814, 3.230739, 3.378499,
   3.909183, 4.619539 };
   graph = new TGraph(35,Graph5_fx6,Graph5_fy6);
   graph->SetName("Graph5");
   graph->SetTitle("Graph");
   graph->SetFillColor(13);
   graph->SetFillStyle(1000);
   graph->SetLineColor(13);
   graph->SetMarkerColor(13);
   graph->SetMarkerStyle(49);
   graph->SetMarkerSize(0.9);
   
   TH1F *Graph_Graph56 = new TH1F("Graph_Graph56","Graph",100,0,3520);
   Graph_Graph56->SetMinimum(0.2311528);
   Graph_Graph56->SetMaximum(5.055809);
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
   Double_t Graph6_fy7[35] = { 0.0330627, 0.03544092, 0.01858473, 0.03327131, 0.06804466, 0.0933826, 0.108546, 0.1169264, 0.1379013, 0.1327157, 0.1599908, 0.1598001, 0.1776218, 0.2189398, 0.2118111, 0.2253532, 0.2583206,
   0.2275229, 0.2661943, 0.2722263, 0.2912879, 0.2850056, 0.3233314, 0.3273129, 0.3813386, 0.4140377, 0.4217386, 0.5370975, 0.5037069, 0.7383347, 0.7690191, 0.8553386, 0.8185029,
   0.9546161, 1.236725 };
   graph = new TGraph(35,Graph6_fx7,Graph6_fy7);
   graph->SetName("Graph6");
   graph->SetTitle("Graph");
   graph->SetFillColor(39);
   graph->SetFillStyle(1000);
   graph->SetLineColor(39);
   graph->SetMarkerColor(39);
   graph->SetMarkerStyle(29);
   graph->SetMarkerSize(0.9);
   
   TH1F *Graph_Graph67 = new TH1F("Graph_Graph67","Graph",100,0,3520);
   Graph_Graph67->SetMinimum(0.01672626);
   Graph_Graph67->SetMaximum(1.358539);
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
   Double_t Graph7_fy8[35] = { 2.621904, 1.449356, 1.243302, 2.14197, 4.412377, 5.018899, 2.923524, 7.268486, 16.61465, 13.45726, 8.822863, 7.833373, 20.84844, 36.52371, 22.11891, 29.19712, 22.56447,
   35.09919, 37.85532, 35.57225, 42.66604, 40.2016, 36.50416, 37.58635, 56.17215, 35.97344, 45.63782, 61.93219, 48.69335, 63.23654, 58.69463, 70.80241, 50.96213,
   45.63236, 42.79434 };
   graph = new TGraph(35,Graph7_fx8,Graph7_fy8);
   graph->SetName("Graph7");
   graph->SetTitle("Graph");
   graph->SetFillColor(28);
   graph->SetFillStyle(1000);
   graph->SetLineColor(28);
   graph->SetMarkerColor(28);
   graph->SetMarkerStyle(34);
   graph->SetMarkerSize(0.9);
   
   TH1F *Graph_Graph78 = new TH1F("Graph_Graph78","Graph",100,0,3520);
   Graph_Graph78->SetMinimum(1.118972);
   Graph_Graph78->SetMaximum(77.75833);
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
   c1->Modified();
   c1->SetSelected(c1);
}
