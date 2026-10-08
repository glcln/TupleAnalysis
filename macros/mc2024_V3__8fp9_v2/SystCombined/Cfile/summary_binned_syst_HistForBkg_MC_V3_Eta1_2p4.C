#ifdef __CLING__
#pragma cling optimize(0)
#endif
void summary_binned_syst_HistForBkg_MC_V3_Eta1_2p4()
{
//=========Macro generated from canvas: c2_315/c2
//=========  (Sun Sep  6 11:16:22 2026) by ROOT version 6.32.13
   TCanvas *c2_315 = new TCanvas("c2_315", "c2",0,0,800,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c2_315->SetHighLightColor(2);
   c2_315->Range(-470.5883,-1.621836,4235.294,3.560128);
   c2_315->SetFillColor(0);
   c2_315->SetBorderMode(0);
   c2_315->SetBorderSize(2);
   c2_315->SetLogy();
   c2_315->SetGridx();
   c2_315->SetGridy();
   c2_315->SetRightMargin(0.05);
   c2_315->SetTopMargin(0.05);
   c2_315->SetBottomMargin(0.12);
   c2_315->SetFrameLineWidth(2);
   c2_315->SetFrameBorderMode(0);
   c2_315->SetFrameLineWidth(2);
   c2_315->SetFrameBorderMode(0);
   
   TH1D *frameSummary_316__3 = new TH1D("frameSummary_316__3","",1,0,4000);
   frameSummary_316__3->SetMinimum(0.1);
   frameSummary_316__3->SetMaximum(2000);
   frameSummary_316__3->SetDirectory(nullptr);
   frameSummary_316__3->SetStats(0);
   frameSummary_316__3->SetLineWidth(2);
   frameSummary_316__3->SetMarkerStyle(20);
   frameSummary_316__3->SetMarkerSize(0.9);
   frameSummary_316__3->GetXaxis()->SetTitle("Mass (GeV)");
   frameSummary_316__3->GetXaxis()->SetLabelFont(43);
   frameSummary_316__3->GetXaxis()->SetLabelOffset(0.015);
   frameSummary_316__3->GetXaxis()->SetLabelSize(24);
   frameSummary_316__3->GetXaxis()->SetTitleSize(0.05);
   frameSummary_316__3->GetXaxis()->SetTitleOffset(1);
   frameSummary_316__3->GetXaxis()->SetTitleFont(42);
   frameSummary_316__3->GetYaxis()->SetTitle("Systematic Uncertainty [%]");
   frameSummary_316__3->GetYaxis()->SetLabelFont(43);
   frameSummary_316__3->GetYaxis()->SetLabelOffset(0.015);
   frameSummary_316__3->GetYaxis()->SetLabelSize(24);
   frameSummary_316__3->GetYaxis()->SetTitleSize(0.05);
   frameSummary_316__3->GetYaxis()->SetTickLength(0.02);
   frameSummary_316__3->GetYaxis()->SetTitleOffset(1);
   frameSummary_316__3->GetYaxis()->SetTitleFont(42);
   frameSummary_316__3->GetZaxis()->SetLabelFont(42);
   frameSummary_316__3->GetZaxis()->SetLabelOffset(0.015);
   frameSummary_316__3->GetZaxis()->SetLabelSize(0.05);
   frameSummary_316__3->GetZaxis()->SetTitleSize(0.065);
   frameSummary_316__3->GetZaxis()->SetTitleOffset(1.1);
   frameSummary_316__3->GetZaxis()->SetTitleFont(42);
   frameSummary_316__3->Draw("AXIS");
   
   TH1D *frameSummary_316__4 = new TH1D("frameSummary_316__4","",1,0,4000);
   frameSummary_316__4->SetMinimum(0.1);
   frameSummary_316__4->SetMaximum(2000);
   frameSummary_316__4->SetDirectory(nullptr);
   frameSummary_316__4->SetStats(0);
   frameSummary_316__4->SetLineWidth(2);
   frameSummary_316__4->SetMarkerStyle(20);
   frameSummary_316__4->SetMarkerSize(0.9);
   frameSummary_316__4->GetXaxis()->SetTitle("Mass (GeV)");
   frameSummary_316__4->GetXaxis()->SetLabelFont(43);
   frameSummary_316__4->GetXaxis()->SetLabelOffset(0.015);
   frameSummary_316__4->GetXaxis()->SetLabelSize(24);
   frameSummary_316__4->GetXaxis()->SetTitleSize(0.05);
   frameSummary_316__4->GetXaxis()->SetTitleOffset(1);
   frameSummary_316__4->GetXaxis()->SetTitleFont(42);
   frameSummary_316__4->GetYaxis()->SetTitle("Systematic Uncertainty [%]");
   frameSummary_316__4->GetYaxis()->SetLabelFont(43);
   frameSummary_316__4->GetYaxis()->SetLabelOffset(0.015);
   frameSummary_316__4->GetYaxis()->SetLabelSize(24);
   frameSummary_316__4->GetYaxis()->SetTitleSize(0.05);
   frameSummary_316__4->GetYaxis()->SetTickLength(0.02);
   frameSummary_316__4->GetYaxis()->SetTitleOffset(1);
   frameSummary_316__4->GetYaxis()->SetTitleFont(42);
   frameSummary_316__4->GetZaxis()->SetLabelFont(42);
   frameSummary_316__4->GetZaxis()->SetLabelOffset(0.015);
   frameSummary_316__4->GetZaxis()->SetLabelSize(0.05);
   frameSummary_316__4->GetZaxis()->SetTitleSize(0.065);
   frameSummary_316__4->GetZaxis()->SetTitleOffset(1.1);
   frameSummary_316__4->GetZaxis()->SetTitleFont(42);
   frameSummary_316__4->Draw("SAME AXIG");
   
   Double_t Graph0_fx11[35] = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320,
   340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000,
   2500, 3200 };
   Double_t Graph0_fy11[35] = { 2.528129, 1.150334, 1.088728, 1.012282, 0.9630728, 0.987325, 1.04294, 1.077309, 1.135792, 1.237207, 1.419364, 1.538409, 1.611285, 1.704509, 1.986326, 1.891541, 2.30039,
   2.132439, 2.389012, 2.510316, 2.532808, 2.1198, 2.407321, 2.755065, 3.342029, 3.857537, 4.606788, 5.755735, 7.495712, 10.91865, 15.54477, 30.6511, 34.83467,
   34.00608, 236.286 };
   TGraph *graph = new TGraph(35,Graph0_fx11,Graph0_fy11);
   graph->SetName("Graph0");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetFillStyle(1000);
   graph->SetMarkerStyle(20);
   graph->SetMarkerSize(1.2);
   
   TH1F *Graph_Graph011 = new TH1F("Graph_Graph011","Graph",100,0,3520);
   Graph_Graph011->SetMinimum(0.8667655);
   Graph_Graph011->SetMaximum(259.8183);
   Graph_Graph011->SetDirectory(nullptr);
   Graph_Graph011->SetStats(0);
   Graph_Graph011->SetLineWidth(2);
   Graph_Graph011->SetMarkerStyle(20);
   Graph_Graph011->SetMarkerSize(0.9);
   Graph_Graph011->GetXaxis()->SetLabelFont(42);
   Graph_Graph011->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph011->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph011->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph011->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph011->GetXaxis()->SetTitleFont(42);
   Graph_Graph011->GetYaxis()->SetLabelFont(42);
   Graph_Graph011->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph011->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph011->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph011->GetYaxis()->SetTickLength(0.02);
   Graph_Graph011->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph011->GetYaxis()->SetTitleFont(42);
   Graph_Graph011->GetZaxis()->SetLabelFont(42);
   Graph_Graph011->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph011->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph011->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph011->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph011->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph011);
   
   graph->Draw("p");
   
   Double_t Graph1_fx12[35] = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320,
   340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000,
   2500, 3200 };
   Double_t Graph1_fy12[35] = { 1.511242, 1.027314, 0.639408, 0.5065054, 0.1632548, 0.1374181, 0.5443447, 0.5965465, 0.6103753, 0.7315278, 0.8008398, 1.221039, 0.6303938, 1.291719, 1.209183, 1.015337, 1.337864,
   1.143638, 1.813146, 1.877192, 1.853432, 1.370419, 1.671494, 2.785369, 2.357873, 3.92704, 5.164404, 3.56776, 9.140764, 5.434965, 17.10473, 2.089174, 44.22716,
   58.64238, 32.97965 };
   graph = new TGraph(35,Graph1_fx12,Graph1_fy12);
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
   
   TH1F *Graph_Graph112 = new TH1F("Graph_Graph112","Graph",100,0,3520);
   Graph_Graph112->SetMinimum(0.1236763);
   Graph_Graph112->SetMaximum(64.49288);
   Graph_Graph112->SetDirectory(nullptr);
   Graph_Graph112->SetStats(0);
   Graph_Graph112->SetLineWidth(2);
   Graph_Graph112->SetMarkerStyle(20);
   Graph_Graph112->SetMarkerSize(0.9);
   Graph_Graph112->GetXaxis()->SetLabelFont(42);
   Graph_Graph112->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph112->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph112->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph112->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph112->GetXaxis()->SetTitleFont(42);
   Graph_Graph112->GetYaxis()->SetLabelFont(42);
   Graph_Graph112->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph112->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph112->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph112->GetYaxis()->SetTickLength(0.02);
   Graph_Graph112->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph112->GetYaxis()->SetTitleFont(42);
   Graph_Graph112->GetZaxis()->SetLabelFont(42);
   Graph_Graph112->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph112->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph112->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph112->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph112->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph112);
   
   graph->Draw("p");
   
   Double_t Graph2_fx13[35] = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320,
   340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000,
   2500, 3200 };
   Double_t Graph2_fy13[35] = { 60.8621, 2.607352, 5.597446, 3.156257, 2.576357, 3.422521, 4.763777, 6.108657, 4.544302, 10.67071, 13.73431, 9.068842, 11.01576, 9.214383, 11.23408, 15.69479, 57.94211,
   30.2816, 47.66335, 65.59772, 19.14427, 18.07956, 11.04281, 35.5206, 24.24131, 5.295938, 4.015575, 21.32036, 10.45297, 11.69089, 30.06882, 36.47421, 12.72303,
   30.04269, 100.6026 };
   graph = new TGraph(35,Graph2_fx13,Graph2_fy13);
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
   
   TH1F *Graph_Graph213 = new TH1F("Graph_Graph213","Graph",100,0,3520);
   Graph_Graph213->SetMinimum(2.318721);
   Graph_Graph213->SetMaximum(110.4052);
   Graph_Graph213->SetDirectory(nullptr);
   Graph_Graph213->SetStats(0);
   Graph_Graph213->SetLineWidth(2);
   Graph_Graph213->SetMarkerStyle(20);
   Graph_Graph213->SetMarkerSize(0.9);
   Graph_Graph213->GetXaxis()->SetLabelFont(42);
   Graph_Graph213->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph213->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph213->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph213->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph213->GetXaxis()->SetTitleFont(42);
   Graph_Graph213->GetYaxis()->SetLabelFont(42);
   Graph_Graph213->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph213->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph213->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph213->GetYaxis()->SetTickLength(0.02);
   Graph_Graph213->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph213->GetYaxis()->SetTitleFont(42);
   Graph_Graph213->GetZaxis()->SetLabelFont(42);
   Graph_Graph213->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph213->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph213->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph213->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph213->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph213);
   
   graph->Draw("p");
   
   Double_t Graph3_fx14[35] = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320,
   340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000,
   2500, 3200 };
   Double_t Graph3_fy14[35] = { 3.021961, 2.675937, 3.139812, 3.44557, 6.070279, 4.585067, 4.292198, 7.182446, 5.076392, 3.668594, 5.203584, 16.86109, 18.60301, 17.58868, 16.83313, 12.21202, 19.99952,
   32.69298, 29.76037, 23.55395, 38.92733, 27.64186, 5.589351, 11.31437, 28.00161, 12.81245, 11.9412, 19.32927, 26.64611, 43.36338, 41.36047, 46.74275, 68.2302,
   48.62983, 3597.833 };
   graph = new TGraph(35,Graph3_fx14,Graph3_fy14);
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
   
   TH1F *Graph_Graph314 = new TH1F("Graph_Graph314","Graph",100,0,3520);
   Graph_Graph314->SetMinimum(2.408343);
   Graph_Graph314->SetMaximum(3957.349);
   Graph_Graph314->SetDirectory(nullptr);
   Graph_Graph314->SetStats(0);
   Graph_Graph314->SetLineWidth(2);
   Graph_Graph314->SetMarkerStyle(20);
   Graph_Graph314->SetMarkerSize(0.9);
   Graph_Graph314->GetXaxis()->SetLabelFont(42);
   Graph_Graph314->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph314->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph314->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph314->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph314->GetXaxis()->SetTitleFont(42);
   Graph_Graph314->GetYaxis()->SetLabelFont(42);
   Graph_Graph314->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph314->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph314->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph314->GetYaxis()->SetTickLength(0.02);
   Graph_Graph314->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph314->GetYaxis()->SetTitleFont(42);
   Graph_Graph314->GetZaxis()->SetLabelFont(42);
   Graph_Graph314->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph314->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph314->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph314->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph314->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph314);
   
   graph->Draw("p");
   
   Double_t Graph4_fx15[35] = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320,
   340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000,
   2500, 3200 };
   Double_t Graph4_fy15[35] = { 0.2591164, 0.2581128, 0.2579618, 0.2530926, 0.2206049, 0.1515868, 0.07995556, 0.02584244, 0.3030799, 0.4684107, 0.6705192, 0.8570987, 0.8277415, 0.9749636, 1.199404, 1.010727, 1.397575,
   1.023282, 1.127383, 1.878273, 1.737365, 1.610634, 2.066493, 2.1845, 2.876727, 2.511476, 2.12425, 2.161111, 3.818607, 3.121424, 2.172052, 2.018399, 0.6682772,
   0.1829087, 1.033467 };
   graph = new TGraph(35,Graph4_fx15,Graph4_fy15);
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
   
   TH1F *Graph_Graph415 = new TH1F("Graph_Graph415","Graph",100,0,3520);
   Graph_Graph415->SetMinimum(0.02325819);
   Graph_Graph415->SetMaximum(4.197884);
   Graph_Graph415->SetDirectory(nullptr);
   Graph_Graph415->SetStats(0);
   Graph_Graph415->SetLineWidth(2);
   Graph_Graph415->SetMarkerStyle(20);
   Graph_Graph415->SetMarkerSize(0.9);
   Graph_Graph415->GetXaxis()->SetLabelFont(42);
   Graph_Graph415->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph415->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph415->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph415->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph415->GetXaxis()->SetTitleFont(42);
   Graph_Graph415->GetYaxis()->SetLabelFont(42);
   Graph_Graph415->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph415->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph415->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph415->GetYaxis()->SetTickLength(0.02);
   Graph_Graph415->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph415->GetYaxis()->SetTitleFont(42);
   Graph_Graph415->GetZaxis()->SetLabelFont(42);
   Graph_Graph415->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph415->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph415->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph415->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph415->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph415);
   
   graph->Draw("p");
   
   Double_t Graph5_fx16[35] = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320,
   340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000,
   2500, 3200 };
   Double_t Graph5_fy16[35] = { 0.01593969, 0.0159316, 0.01593064, 0.01569827, 0.01518187, 0.01465088, 0.01338363, 0.01265732, 0.01135744, 0.007574567, 0.00472595, 0.002765061, 0.0002992764, 0.01799274, 0.02915762, 0.03815016, 0.06978746,
   0.0818115, 0.1240363, 0.200586, 0.3018172, 0.3446073, 0.6562217, 0.9897967, 1.758704, 2.518357, 4.697347, 6.438596, 8.437255, 7.987949, 8.227271, 9.087706, 4.68832,
   2.397346, 3.746542 };
   graph = new TGraph(35,Graph5_fx16,Graph5_fy16);
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
   
   TH1F *Graph_Graph516 = new TH1F("Graph_Graph516","Graph",100,0,3520);
   Graph_Graph516->SetMinimum(0.0002693487);
   Graph_Graph516->SetMaximum(9.996447);
   Graph_Graph516->SetDirectory(nullptr);
   Graph_Graph516->SetStats(0);
   Graph_Graph516->SetLineWidth(2);
   Graph_Graph516->SetMarkerStyle(20);
   Graph_Graph516->SetMarkerSize(0.9);
   Graph_Graph516->GetXaxis()->SetLabelFont(42);
   Graph_Graph516->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph516->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph516->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph516->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph516->GetXaxis()->SetTitleFont(42);
   Graph_Graph516->GetYaxis()->SetLabelFont(42);
   Graph_Graph516->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph516->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph516->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph516->GetYaxis()->SetTickLength(0.02);
   Graph_Graph516->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph516->GetYaxis()->SetTitleFont(42);
   Graph_Graph516->GetZaxis()->SetLabelFont(42);
   Graph_Graph516->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph516->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph516->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph516->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph516->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph516);
   
   graph->Draw("p");
   
   Double_t Graph6_fx17[35] = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320,
   340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000,
   2500, 3200 };
   Double_t Graph6_fy17[35] = { 0.8380959, 0.8382106, 0.838211, 0.7773767, 0.5438544, 0.3603469, 0.0507279, 0.02304091, 0.5978909, 0.9171364, 1.269563, 2.20291, 2.166101, 2.519968, 4.951853, 3.613252, 3.530928,
   3.308058, 4.967864, 7.073251, 6.895625, 7.161113, 7.990415, 6.659782, 6.401033, 10.70813, 4.66077, 10.14634, 7.635638, 25.86668, 19.13299, 50.97171, 37.85644,
   38.55587, 110.1754 };
   graph = new TGraph(35,Graph6_fx17,Graph6_fy17);
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
   
   TH1F *Graph_Graph617 = new TH1F("Graph_Graph617","Graph",100,0,3520);
   Graph_Graph617->SetMinimum(0.02073682);
   Graph_Graph617->SetMaximum(121.1906);
   Graph_Graph617->SetDirectory(nullptr);
   Graph_Graph617->SetStats(0);
   Graph_Graph617->SetLineWidth(2);
   Graph_Graph617->SetMarkerStyle(20);
   Graph_Graph617->SetMarkerSize(0.9);
   Graph_Graph617->GetXaxis()->SetLabelFont(42);
   Graph_Graph617->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph617->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph617->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph617->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph617->GetXaxis()->SetTitleFont(42);
   Graph_Graph617->GetYaxis()->SetLabelFont(42);
   Graph_Graph617->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph617->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph617->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph617->GetYaxis()->SetTickLength(0.02);
   Graph_Graph617->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph617->GetYaxis()->SetTitleFont(42);
   Graph_Graph617->GetZaxis()->SetLabelFont(42);
   Graph_Graph617->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph617->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph617->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph617->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph617->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph617);
   
   graph->Draw("p");
   
   Double_t Graph7_fx18[35] = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320,
   340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000,
   2500, 3200 };
   Double_t Graph7_fy18[35] = { 1.155946, 0.9516678, 0.6107021, 0.2537349, 0.001960264, 0.179279, 0.2808486, 0.3903436, 0.4691782, 0.6140314, 0.6977248, 0.7228014, 0.7330231, 0.6820453, 1.060033, 0.8256579, 1.016504,
   1.050074, 1.031887, 0.9760681, 1.183795, 1.280249, 1.408345, 1.356547, 1.454815, 1.130747, 1.573293, 1.517486, 1.244238, 0.5789303, 2.016134, 4.543554, 7.128562,
   10.13516, 16.44054 };
   graph = new TGraph(35,Graph7_fx18,Graph7_fy18);
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
   
   TH1F *Graph_Graph718 = new TH1F("Graph_Graph718","Graph",100,0,3520);
   Graph_Graph718->SetMinimum(0.001764237);
   Graph_Graph718->SetMaximum(18.0844);
   Graph_Graph718->SetDirectory(nullptr);
   Graph_Graph718->SetStats(0);
   Graph_Graph718->SetLineWidth(2);
   Graph_Graph718->SetMarkerStyle(20);
   Graph_Graph718->SetMarkerSize(0.9);
   Graph_Graph718->GetXaxis()->SetLabelFont(42);
   Graph_Graph718->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph718->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph718->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph718->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph718->GetXaxis()->SetTitleFont(42);
   Graph_Graph718->GetYaxis()->SetLabelFont(42);
   Graph_Graph718->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph718->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph718->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph718->GetYaxis()->SetTickLength(0.02);
   Graph_Graph718->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph718->GetYaxis()->SetTitleFont(42);
   Graph_Graph718->GetZaxis()->SetLabelFont(42);
   Graph_Graph718->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph718->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph718->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph718->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph718->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph718);
   
   graph->Draw("p");
   
   Double_t Graph8_fx19[35] = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320,
   340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000,
   2500, 3200 };
   Double_t Graph8_fy19[35] = { 2.849079, 1.53881, 1.434113, 0.9050063, 0.267002, 0.2343792, 0.6535134, 0.9531489, 1.344338, 1.519993, 1.71221, 1.941218, 2.20219, 2.413144, 2.278149, 2.747106, 2.477217,
   2.730324, 3.061604, 3.053727, 3.034011, 3.17085, 3.165326, 2.989206, 2.913208, 3.32006, 2.490411, 3.330538, 4.217529, 6.423176, 6.648461, 6.812344, 8.153502,
   8.548082, 24.29525 };
   graph = new TGraph(35,Graph8_fx19,Graph8_fy19);
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
   
   TH1F *Graph_Graph819 = new TH1F("Graph_Graph819","Graph",100,0,3520);
   Graph_Graph819->SetMinimum(0.2109413);
   Graph_Graph819->SetMaximum(26.70134);
   Graph_Graph819->SetDirectory(nullptr);
   Graph_Graph819->SetStats(0);
   Graph_Graph819->SetLineWidth(2);
   Graph_Graph819->SetMarkerStyle(20);
   Graph_Graph819->SetMarkerSize(0.9);
   Graph_Graph819->GetXaxis()->SetLabelFont(42);
   Graph_Graph819->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph819->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph819->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph819->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph819->GetXaxis()->SetTitleFont(42);
   Graph_Graph819->GetYaxis()->SetLabelFont(42);
   Graph_Graph819->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph819->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph819->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph819->GetYaxis()->SetTickLength(0.02);
   Graph_Graph819->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph819->GetYaxis()->SetTitleFont(42);
   Graph_Graph819->GetZaxis()->SetLabelFont(42);
   Graph_Graph819->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph819->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph819->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph819->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph819->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph819);
   
   graph->Draw("p");
   
   Double_t Graph9_fx20[35] = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320,
   340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000,
   2500, 3200 };
   Double_t Graph9_fy20[35] = { 61.0862, 4.435994, 6.729074, 4.905394, 6.675347, 5.817255, 6.558437, 9.56459, 7.085363, 11.50197, 14.90747, 19.37584, 21.82853, 20.15142, 20.56014, 20.23166, 61.42864,
   44.73559, 56.37547, 69.86788, 43.65096, 33.34248, 13.35954, 37.70417, 37.55572, 15.73083, 15.55203, 30.55417, 32.62091, 47.75938, 57.18135, 67.91774, 90.14684,
   89.69023, 3607.259 };
   graph = new TGraph(35,Graph9_fx20,Graph9_fy20);
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
   
   TH1F *Graph_Graph920 = new TH1F("Graph_Graph920","Graph",100,0,3520);
   Graph_Graph920->SetMinimum(3.992395);
   Graph_Graph920->SetMaximum(3967.541);
   Graph_Graph920->SetDirectory(nullptr);
   Graph_Graph920->SetStats(0);
   Graph_Graph920->SetLineWidth(2);
   Graph_Graph920->SetMarkerStyle(20);
   Graph_Graph920->SetMarkerSize(0.9);
   Graph_Graph920->GetXaxis()->SetLabelFont(42);
   Graph_Graph920->GetXaxis()->SetLabelOffset(0.015);
   Graph_Graph920->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph920->GetXaxis()->SetTitleSize(0.065);
   Graph_Graph920->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph920->GetXaxis()->SetTitleFont(42);
   Graph_Graph920->GetYaxis()->SetLabelFont(42);
   Graph_Graph920->GetYaxis()->SetLabelOffset(0.015);
   Graph_Graph920->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph920->GetYaxis()->SetTitleSize(0.065);
   Graph_Graph920->GetYaxis()->SetTickLength(0.02);
   Graph_Graph920->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph920->GetYaxis()->SetTitleFont(42);
   Graph_Graph920->GetZaxis()->SetLabelFont(42);
   Graph_Graph920->GetZaxis()->SetLabelOffset(0.015);
   Graph_Graph920->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph920->GetZaxis()->SetTitleSize(0.065);
   Graph_Graph920->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph920->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph920);
   
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
      tex = new TLatex(0.75,0.88,"#bf{1#leq|#eta|<2.4}");
   tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.07);
   tex->SetLineWidth(2);
   tex->Draw();
   c2_315->Modified();
   c2_315->SetSelected(c2_315);
}
