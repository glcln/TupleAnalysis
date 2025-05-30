void mass_plot_NoC_region8fp9_2017_2018_lowmass_3p2()
{
//=========Macro generated from canvas: c1/c1
//=========  (Fri May 23 16:33:03 2025) by ROOT version 6.14/09
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,700,700);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c1->SetHighLightColor(2);
   c1->Range(0,0,1,1);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetTickx(1);
   c1->SetTicky(1);
   c1->SetLeftMargin(0.16);
   c1->SetRightMargin(0.02);
   c1->SetTopMargin(0.05);
   c1->SetBottomMargin(0.13);
   c1->SetFrameFillStyle(0);
   c1->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: t1
   TPad *t1 = new TPad("t1", "t1",0,0.45,0.95,0.95);
   t1->Draw();
   t1->cd();
   t1->Range(-58.53658,-4.053926,307.3171,6.731326);
   t1->SetFillColor(0);
   t1->SetBorderMode(0);
   t1->SetBorderSize(2);
   t1->SetLogy();
   t1->SetTickx(1);
   t1->SetTicky(1);
   t1->SetLeftMargin(0.16);
   t1->SetRightMargin(0.02);
   t1->SetTopMargin(0.003);
   t1->SetBottomMargin(0.005);
   t1->SetFrameFillStyle(0);
   t1->SetFrameBorderMode(0);
   t1->SetFrameFillStyle(0);
   t1->SetFrameBorderMode(0);
   Double_t xAxis1[36] = {0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000, 2500, 3200, 4000}; 
   
   TH1F *pred_new__1 = new TH1F("pred_new__1","",35, xAxis1);
   pred_new__1->SetBinContent(1,122788.6);
   pred_new__1->SetBinContent(2,310370.2);
   pred_new__1->SetBinContent(3,212958);
   pred_new__1->SetBinContent(4,135654.2);
   pred_new__1->SetBinContent(5,97175.11);
   pred_new__1->SetBinContent(6,65558.69);
   pred_new__1->SetBinContent(7,45174.16);
   pred_new__1->SetBinContent(8,31370.79);
   pred_new__1->SetBinContent(9,20418.81);
   pred_new__1->SetBinContent(10,13948.36);
   pred_new__1->SetBinContent(11,9237.615);
   pred_new__1->SetBinContent(12,6352.484);
   pred_new__1->SetBinContent(13,4255.592);
   pred_new__1->SetBinContent(14,2928.764);
   pred_new__1->SetBinContent(15,2046.296);
   pred_new__1->SetBinContent(16,1483.841);
   pred_new__1->SetBinError(1,8384.565);
   pred_new__1->SetBinError(2,4483.47);
   pred_new__1->SetBinError(3,9417.678);
   pred_new__1->SetBinError(4,2166.083);
   pred_new__1->SetBinError(5,2616.793);
   pred_new__1->SetBinError(6,1974.568);
   pred_new__1->SetBinError(7,974.6339);
   pred_new__1->SetBinError(8,1408.656);
   pred_new__1->SetBinError(9,1665.177);
   pred_new__1->SetBinError(10,497.5426);
   pred_new__1->SetBinError(11,395.5488);
   pred_new__1->SetBinError(12,237.2902);
   pred_new__1->SetBinError(13,143.8477);
   pred_new__1->SetBinError(14,381.3236);
   pred_new__1->SetBinError(15,160.4235);
   pred_new__1->SetBinError(16,108.7754);
   pred_new__1->SetBinError(17,1095.184);
   pred_new__1->SetBinError(18,746.0742);
   pred_new__1->SetBinError(19,602.7457);
   pred_new__1->SetBinError(20,603.0703);
   pred_new__1->SetBinError(21,430.7242);
   pred_new__1->SetBinError(22,340.254);
   pred_new__1->SetBinError(23,278.2657);
   pred_new__1->SetBinError(24,163.0563);
   pred_new__1->SetBinError(25,106.078);
   pred_new__1->SetBinError(26,71.20052);
   pred_new__1->SetBinError(27,36.06265);
   pred_new__1->SetBinError(28,17.38978);
   pred_new__1->SetBinError(29,8.246458);
   pred_new__1->SetBinError(30,3.970643);
   pred_new__1->SetBinError(31,1.635199);
   pred_new__1->SetBinError(32,0.575956);
   pred_new__1->SetBinError(33,0.3747009);
   pred_new__1->SetBinError(34,0.1446313);
   pred_new__1->SetBinError(35,0.0559234);
   pred_new__1->SetMinimum(0.0001);
   pred_new__1->SetMaximum(5000000);
   pred_new__1->SetEntries(422);
   pred_new__1->SetFillColor(5);
   pred_new__1->SetLineColor(5);
   pred_new__1->SetMarkerColor(5);
   pred_new__1->SetMarkerStyle(22);
   pred_new__1->GetXaxis()->SetRange(1,15);
   pred_new__1->GetXaxis()->SetLabelFont(42);
   pred_new__1->GetXaxis()->SetLabelSize(0.035);
   pred_new__1->GetXaxis()->SetTitleSize(0.035);
   pred_new__1->GetXaxis()->SetTitleFont(42);
   pred_new__1->GetYaxis()->SetTitle("Events / bin");
   pred_new__1->GetYaxis()->SetLabelFont(43);
   pred_new__1->GetYaxis()->SetLabelSize(20);
   pred_new__1->GetYaxis()->SetTitleSize(20);
   pred_new__1->GetYaxis()->SetTitleOffset(2);
   pred_new__1->GetYaxis()->SetTitleFont(43);
   pred_new__1->GetZaxis()->SetLabelFont(42);
   pred_new__1->GetZaxis()->SetLabelSize(0.035);
   pred_new__1->GetZaxis()->SetTitleSize(0.035);
   pred_new__1->GetZaxis()->SetTitleFont(42);
   pred_new__1->Draw(" E5");
   Double_t xAxis2[36] = {0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000, 2500, 3200, 4000}; 
   
   TH1F *pred_noSyst_new__2 = new TH1F("pred_noSyst_new__2","",35, xAxis2);
   pred_noSyst_new__2->SetBinContent(1,122788.6);
   pred_noSyst_new__2->SetBinContent(2,310370.2);
   pred_noSyst_new__2->SetBinContent(3,212958);
   pred_noSyst_new__2->SetBinContent(4,135654.2);
   pred_noSyst_new__2->SetBinContent(5,97175.11);
   pred_noSyst_new__2->SetBinContent(6,65558.69);
   pred_noSyst_new__2->SetBinContent(7,45174.16);
   pred_noSyst_new__2->SetBinContent(8,31370.79);
   pred_noSyst_new__2->SetBinContent(9,20418.81);
   pred_noSyst_new__2->SetBinContent(10,13948.36);
   pred_noSyst_new__2->SetBinContent(11,9237.615);
   pred_noSyst_new__2->SetBinContent(12,6352.484);
   pred_noSyst_new__2->SetBinContent(13,4255.592);
   pred_noSyst_new__2->SetBinContent(14,2928.764);
   pred_noSyst_new__2->SetBinContent(15,2046.296);
   pred_noSyst_new__2->SetBinContent(16,1483.841);
   pred_noSyst_new__2->SetBinContent(17,1095.177);
   pred_noSyst_new__2->SetBinContent(18,746.0688);
   pred_noSyst_new__2->SetBinContent(19,602.74);
   pred_noSyst_new__2->SetBinContent(20,603.0653);
   pred_noSyst_new__2->SetBinContent(21,430.7195);
   pred_noSyst_new__2->SetBinContent(22,340.2487);
   pred_noSyst_new__2->SetBinContent(23,278.2602);
   pred_noSyst_new__2->SetBinContent(24,163.0499);
   pred_noSyst_new__2->SetBinContent(25,106.07);
   pred_noSyst_new__2->SetBinContent(26,71.19112);
   pred_noSyst_new__2->SetBinContent(27,36.05217);
   pred_noSyst_new__2->SetBinContent(28,17.37934);
   pred_noSyst_new__2->SetBinContent(29,8.235868);
   pred_noSyst_new__2->SetBinContent(30,3.961051);
   pred_noSyst_new__2->SetBinContent(31,1.627022);
   pred_noSyst_new__2->SetBinContent(32,0.5698371);
   pred_noSyst_new__2->SetBinContent(33,0.3692169);
   pred_noSyst_new__2->SetBinContent(34,0.1398791);
   pred_noSyst_new__2->SetBinContent(35,0.05299988);
   pred_noSyst_new__2->SetBinError(1,197.8611);
   pred_noSyst_new__2->SetBinError(2,325.2351);
   pred_noSyst_new__2->SetBinError(3,215.9067);
   pred_noSyst_new__2->SetBinError(4,158.3466);
   pred_noSyst_new__2->SetBinError(5,122.9691);
   pred_noSyst_new__2->SetBinError(6,91.33738);
   pred_noSyst_new__2->SetBinError(7,68.76056);
   pred_noSyst_new__2->SetBinError(8,50.70139);
   pred_noSyst_new__2->SetBinError(9,37.06776);
   pred_noSyst_new__2->SetBinError(10,27.19121);
   pred_noSyst_new__2->SetBinError(11,19.05019);
   pred_noSyst_new__2->SetBinError(12,14.29544);
   pred_noSyst_new__2->SetBinError(13,10.9046);
   pred_noSyst_new__2->SetBinError(14,7.703911);
   pred_noSyst_new__2->SetBinError(15,5.976487);
   pred_noSyst_new__2->SetBinError(16,4.745751);
   pred_noSyst_new__2->SetBinError(17,3.89605);
   pred_noSyst_new__2->SetBinError(18,2.829841);
   pred_noSyst_new__2->SetBinError(19,2.6309);
   pred_noSyst_new__2->SetBinError(20,2.463444);
   pred_noSyst_new__2->SetBinError(21,2.02802);
   pred_noSyst_new__2->SetBinError(22,1.898049);
   pred_noSyst_new__2->SetBinError(23,1.744466);
   pred_noSyst_new__2->SetBinError(24,1.442103);
   pred_noSyst_new__2->SetBinError(25,1.297651);
   pred_noSyst_new__2->SetBinError(26,1.157202);
   pred_noSyst_new__2->SetBinError(27,0.8693566);
   pred_noSyst_new__2->SetBinError(28,0.602471);
   pred_noSyst_new__2->SetBinError(29,0.4177784);
   pred_noSyst_new__2->SetBinError(30,0.2758271);
   pred_noSyst_new__2->SetBinError(31,0.1633227);
   pred_noSyst_new__2->SetBinError(32,0.0837318);
   pred_noSyst_new__2->SetBinError(33,0.06387194);
   pred_noSyst_new__2->SetBinError(34,0.03677008);
   pred_noSyst_new__2->SetBinError(35,0.01784487);
   pred_noSyst_new__2->SetMinimum(0.0001);
   pred_noSyst_new__2->SetMaximum(5000000);
   pred_noSyst_new__2->SetEntries(403);
   pred_noSyst_new__2->SetFillColor(5);
   pred_noSyst_new__2->SetLineColor(5);
   pred_noSyst_new__2->SetMarkerColor(5);
   pred_noSyst_new__2->SetMarkerStyle(22);
   pred_noSyst_new__2->SetMarkerSize(0.1);
   pred_noSyst_new__2->GetXaxis()->SetRange(1,15);
   pred_noSyst_new__2->GetXaxis()->SetLabelFont(42);
   pred_noSyst_new__2->GetXaxis()->SetLabelSize(0.035);
   pred_noSyst_new__2->GetXaxis()->SetTitleSize(0.035);
   pred_noSyst_new__2->GetXaxis()->SetTitleFont(42);
   pred_noSyst_new__2->GetYaxis()->SetTitle("Events / bin");
   pred_noSyst_new__2->GetYaxis()->SetLabelFont(43);
   pred_noSyst_new__2->GetYaxis()->SetLabelSize(20);
   pred_noSyst_new__2->GetYaxis()->SetTitleSize(20);
   pred_noSyst_new__2->GetYaxis()->SetTitleOffset(7);
   pred_noSyst_new__2->GetYaxis()->SetTitleFont(43);
   pred_noSyst_new__2->GetZaxis()->SetLabelFont(42);
   pred_noSyst_new__2->GetZaxis()->SetLabelSize(0.035);
   pred_noSyst_new__2->GetZaxis()->SetTitleSize(0.035);
   pred_noSyst_new__2->GetZaxis()->SetTitleFont(42);
   pred_noSyst_new__2->Draw("same E5");
   Double_t xAxis3[36] = {0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000, 2500, 3200, 4000}; 
   
   TH1F *pred_new__3 = new TH1F("pred_new__3","",35, xAxis3);
   pred_new__3->SetBinContent(1,122788.6);
   pred_new__3->SetBinContent(2,310370.2);
   pred_new__3->SetBinContent(3,212958);
   pred_new__3->SetBinContent(4,135654.2);
   pred_new__3->SetBinContent(5,97175.11);
   pred_new__3->SetBinContent(6,65558.69);
   pred_new__3->SetBinContent(7,45174.16);
   pred_new__3->SetBinContent(8,31370.79);
   pred_new__3->SetBinContent(9,20418.81);
   pred_new__3->SetBinContent(10,13948.36);
   pred_new__3->SetBinContent(11,9237.615);
   pred_new__3->SetBinContent(12,6352.484);
   pred_new__3->SetBinContent(13,4255.592);
   pred_new__3->SetBinContent(14,2928.764);
   pred_new__3->SetBinContent(15,2046.296);
   pred_new__3->SetBinContent(16,1483.841);
   pred_new__3->SetBinError(1,8384.565);
   pred_new__3->SetBinError(2,4483.47);
   pred_new__3->SetBinError(3,9417.678);
   pred_new__3->SetBinError(4,2166.083);
   pred_new__3->SetBinError(5,2616.793);
   pred_new__3->SetBinError(6,1974.568);
   pred_new__3->SetBinError(7,974.6339);
   pred_new__3->SetBinError(8,1408.656);
   pred_new__3->SetBinError(9,1665.177);
   pred_new__3->SetBinError(10,497.5426);
   pred_new__3->SetBinError(11,395.5488);
   pred_new__3->SetBinError(12,237.2902);
   pred_new__3->SetBinError(13,143.8477);
   pred_new__3->SetBinError(14,381.3236);
   pred_new__3->SetBinError(15,160.4235);
   pred_new__3->SetBinError(16,108.7754);
   pred_new__3->SetBinError(17,1095.184);
   pred_new__3->SetBinError(18,746.0742);
   pred_new__3->SetBinError(19,602.7457);
   pred_new__3->SetBinError(20,603.0703);
   pred_new__3->SetBinError(21,430.7242);
   pred_new__3->SetBinError(22,340.254);
   pred_new__3->SetBinError(23,278.2657);
   pred_new__3->SetBinError(24,163.0563);
   pred_new__3->SetBinError(25,106.078);
   pred_new__3->SetBinError(26,71.20052);
   pred_new__3->SetBinError(27,36.06265);
   pred_new__3->SetBinError(28,17.38978);
   pred_new__3->SetBinError(29,8.246458);
   pred_new__3->SetBinError(30,3.970643);
   pred_new__3->SetBinError(31,1.635199);
   pred_new__3->SetBinError(32,0.575956);
   pred_new__3->SetBinError(33,0.3747009);
   pred_new__3->SetBinError(34,0.1446313);
   pred_new__3->SetBinError(35,0.0559234);
   pred_new__3->SetEntries(422);
   pred_new__3->SetLineColor(2);
   pred_new__3->SetMarkerColor(2);
   pred_new__3->SetMarkerStyle(21);
   pred_new__3->GetXaxis()->SetTitle("Mass [GeV]");
   pred_new__3->GetXaxis()->SetRange(1,400);
   pred_new__3->GetXaxis()->SetLabelFont(42);
   pred_new__3->GetXaxis()->SetLabelSize(0.035);
   pred_new__3->GetXaxis()->SetTitleSize(0.035);
   pred_new__3->GetXaxis()->SetTitleFont(42);
   pred_new__3->GetYaxis()->SetLabelFont(42);
   pred_new__3->GetYaxis()->SetLabelSize(0.035);
   pred_new__3->GetYaxis()->SetTitleSize(0.035);
   pred_new__3->GetYaxis()->SetTitleOffset(0);
   pred_new__3->GetYaxis()->SetTitleFont(42);
   pred_new__3->GetZaxis()->SetLabelFont(42);
   pred_new__3->GetZaxis()->SetLabelSize(0.035);
   pred_new__3->GetZaxis()->SetTitleSize(0.035);
   pred_new__3->GetZaxis()->SetTitleFont(42);
   pred_new__3->Draw("same HIST P");
   Double_t xAxis4[36] = {0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000, 2500, 3200, 4000}; 
   
   TH1F *obs_new__4 = new TH1F("obs_new__4","",35, xAxis4);
   obs_new__4->SetBinContent(1,127724);
   obs_new__4->SetBinContent(2,302969);
   obs_new__4->SetBinContent(3,212094);
   obs_new__4->SetBinContent(4,136963);
   obs_new__4->SetBinContent(5,95959);
   obs_new__4->SetBinContent(6,66326);
   obs_new__4->SetBinContent(7,45891);
   obs_new__4->SetBinContent(8,31203);
   obs_new__4->SetBinContent(9,20992);
   obs_new__4->SetBinContent(10,13872);
   obs_new__4->SetBinContent(11,9312);
   obs_new__4->SetBinContent(12,6389);
   obs_new__4->SetBinContent(13,4282);
   obs_new__4->SetBinContent(14,2983);
   obs_new__4->SetBinContent(15,2119);
   obs_new__4->SetBinContent(16,1530);
   obs_new__4->SetEntries(1080608);
   obs_new__4->SetMarkerStyle(20);
   obs_new__4->GetXaxis()->SetTitle("Mass [GeV]");
   obs_new__4->GetXaxis()->SetRange(1,15);
   obs_new__4->GetXaxis()->SetLabelFont(42);
   obs_new__4->GetXaxis()->SetLabelSize(0.035);
   obs_new__4->GetXaxis()->SetTitleSize(0.035);
   obs_new__4->GetXaxis()->SetTitleFont(42);
   obs_new__4->GetYaxis()->SetLabelFont(42);
   obs_new__4->GetYaxis()->SetLabelSize(0.035);
   obs_new__4->GetYaxis()->SetTitleSize(0.035);
   obs_new__4->GetYaxis()->SetTitleOffset(0);
   obs_new__4->GetYaxis()->SetTitleFont(42);
   obs_new__4->GetZaxis()->SetLabelFont(42);
   obs_new__4->GetZaxis()->SetLabelSize(0.035);
   obs_new__4->GetZaxis()->SetTitleSize(0.035);
   obs_new__4->GetZaxis()->SetTitleFont(42);
   obs_new__4->Draw("same E1");
   
   TLegend *leg = new TLegend(0.5,0.6,0.8,0.95,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(43);
   leg->SetTextSize(14);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("NULL","8fp9","h");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(43);
   entry=leg->AddEntry("obs_new","Observed","PE1");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(43);
   leg->Draw();
   t1->Modified();
   c1->cd();
  
// ------------>Primitives in pad: t2
   TPad *t2 = new TPad("t2", "t2",0,0.3,0.95,0.45);
   t2->Draw();
   t2->cd();
   t2->Range(-58.53658,-0.04545454,307.3171,2.227273);
   t2->SetFillColor(0);
   t2->SetBorderMode(0);
   t2->SetBorderSize(2);
   t2->SetGridy();
   t2->SetTickx(1);
   t2->SetTicky(1);
   t2->SetLeftMargin(0.16);
   t2->SetRightMargin(0.02);
   t2->SetBottomMargin(0.02);
   t2->SetFrameFillStyle(0);
   t2->SetFrameBorderMode(0);
   t2->SetFrameFillStyle(0);
   t2->SetFrameBorderMode(0);
   
   TH1D *frameR__5 = new TH1D("frameR__5","",1,0,300);
   frameR__5->SetMinimum(0);
   frameR__5->SetMaximum(2);
   frameR__5->SetStats(0);
   frameR__5->SetLineStyle(0);
   frameR__5->SetMarkerStyle(20);
   frameR__5->GetXaxis()->SetNdivisions(505);
   frameR__5->GetXaxis()->SetLabelFont(43);
   frameR__5->GetXaxis()->SetLabelOffset(0.007);
   frameR__5->GetXaxis()->SetLabelSize(20);
   frameR__5->GetXaxis()->SetTitleSize(20);
   frameR__5->GetXaxis()->SetTitleOffset(3.75);
   frameR__5->GetXaxis()->SetTitleFont(43);
   frameR__5->GetYaxis()->SetTitle("RatioR     ");
   frameR__5->GetYaxis()->SetNdivisions(503);
   frameR__5->GetYaxis()->SetLabelFont(43);
   frameR__5->GetYaxis()->SetLabelOffset(0.007);
   frameR__5->GetYaxis()->SetLabelSize(12);
   frameR__5->GetYaxis()->SetTitleSize(14);
   frameR__5->GetYaxis()->SetTitleOffset(1.25);
   frameR__5->GetYaxis()->SetTitleFont(43);
   frameR__5->GetZaxis()->SetLabelFont(42);
   frameR__5->GetZaxis()->SetLabelOffset(0.007);
   frameR__5->GetZaxis()->SetLabelSize(0.05);
   frameR__5->GetZaxis()->SetTitleSize(0.06);
   frameR__5->GetZaxis()->SetTitleFont(42);
   frameR__5->Draw("AXIS");
   Double_t xAxis5[36] = {0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000, 2500, 3200, 4000}; 
   
   TH1F *pred_new__6 = new TH1F("pred_new__6","",35, xAxis5);
   pred_new__6->SetBinContent(0,0.9989707);
   pred_new__6->SetBinContent(1,0.9989707);
   pred_new__6->SetBinContent(2,0.9936922);
   pred_new__6->SetBinContent(3,1.002085);
   pred_new__6->SetBinContent(4,1.005088);
   pred_new__6->SetBinContent(5,1.003026);
   pred_new__6->SetBinContent(6,1.010473);
   pred_new__6->SetBinContent(7,1.009884);
   pred_new__6->SetBinContent(8,1.006947);
   pred_new__6->SetBinContent(9,1.013305);
   pred_new__6->SetBinContent(10,1.005814);
   pred_new__6->SetBinContent(11,1.011801);
   pred_new__6->SetBinContent(12,1.013829);
   pred_new__6->SetBinContent(13,1.01862);
   pred_new__6->SetBinContent(14,1.0268);
   pred_new__6->SetBinContent(15,1.033671);
   pred_new__6->SetBinContent(16,1.031108);
   pred_new__6->SetBinError(0,0.01321909);
   pred_new__6->SetBinError(1,0.01321909);
   pred_new__6->SetBinError(2,0.01201668);
   pred_new__6->SetBinError(3,0.01650104);
   pred_new__6->SetBinError(4,0.01157108);
   pred_new__6->SetBinError(5,0.01507495);
   pred_new__6->SetBinError(6,0.01822588);
   pred_new__6->SetBinError(7,0.02258057);
   pred_new__6->SetBinError(8,0.03174283);
   pred_new__6->SetBinError(9,0.0422617);
   pred_new__6->SetBinError(10,0.04747846);
   pred_new__6->SetBinError(11,0.07038961);
   pred_new__6->SetBinError(12,0.1059838);
   pred_new__6->SetBinError(13,0.1679412);
   pred_new__6->SetBinError(14,0.2797067);
   pred_new__6->SetBinError(15,0.5026984);
   pred_new__6->SetBinError(16,1.18736);
   pred_new__6->SetEntries(36);
   pred_new__6->SetMarkerStyle(21);
   pred_new__6->SetMarkerSize(0.7);
   pred_new__6->GetXaxis()->SetTitle("Mass [GeV]");
   pred_new__6->GetXaxis()->SetRange(1,15);
   pred_new__6->GetXaxis()->SetLabelFont(42);
   pred_new__6->GetXaxis()->SetLabelSize(0.035);
   pred_new__6->GetXaxis()->SetTitleSize(0.035);
   pred_new__6->GetXaxis()->SetTitleFont(42);
   pred_new__6->GetYaxis()->SetLabelFont(42);
   pred_new__6->GetYaxis()->SetLabelSize(0.035);
   pred_new__6->GetYaxis()->SetTitleSize(0.035);
   pred_new__6->GetYaxis()->SetTitleOffset(0);
   pred_new__6->GetYaxis()->SetTitleFont(42);
   pred_new__6->GetZaxis()->SetLabelFont(42);
   pred_new__6->GetZaxis()->SetLabelSize(0.035);
   pred_new__6->GetZaxis()->SetTitleSize(0.035);
   pred_new__6->GetZaxis()->SetTitleFont(42);
   pred_new__6->Draw("same E0");
   TLine *line = new TLine(0,1,300,1);
   line->SetLineStyle(3);
   line->Draw();
   t2->Modified();
   c1->cd();
  
// ------------>Primitives in pad: t3
   TPad *t3 = new TPad("t3", "t3",0,0.15,0.95,0.3);
   t3->Draw();
   t3->cd();
   t3->Range(-58.53658,-0.04545454,307.3171,2.227273);
   t3->SetFillColor(0);
   t3->SetBorderMode(0);
   t3->SetBorderSize(2);
   t3->SetGridy();
   t3->SetTickx(1);
   t3->SetTicky(1);
   t3->SetLeftMargin(0.16);
   t3->SetRightMargin(0.02);
   t3->SetBottomMargin(0.02);
   t3->SetFrameFillStyle(0);
   t3->SetFrameBorderMode(0);
   t3->SetFrameFillStyle(0);
   t3->SetFrameBorderMode(0);
   
   TH1D *frameR2__7 = new TH1D("frameR2__7","",1,0,300);
   frameR2__7->SetMinimum(0);
   frameR2__7->SetMaximum(2);
   frameR2__7->SetStats(0);
   frameR2__7->SetLineStyle(0);
   frameR2__7->SetMarkerStyle(20);
   frameR2__7->GetXaxis()->SetNdivisions(505);
   frameR2__7->GetXaxis()->SetLabelFont(43);
   frameR2__7->GetXaxis()->SetLabelOffset(0.007);
   frameR2__7->GetXaxis()->SetLabelSize(20);
   frameR2__7->GetXaxis()->SetTitleSize(20);
   frameR2__7->GetXaxis()->SetTitleOffset(3.75);
   frameR2__7->GetXaxis()->SetTitleFont(43);
   frameR2__7->GetYaxis()->SetTitle("obs / pred");
   frameR2__7->GetYaxis()->SetNdivisions(503);
   frameR2__7->GetYaxis()->SetLabelFont(43);
   frameR2__7->GetYaxis()->SetLabelOffset(0.007);
   frameR2__7->GetYaxis()->SetLabelSize(12);
   frameR2__7->GetYaxis()->SetTitleSize(14);
   frameR2__7->GetYaxis()->SetTitleOffset(1.25);
   frameR2__7->GetYaxis()->SetTitleFont(43);
   frameR2__7->GetZaxis()->SetLabelFont(42);
   frameR2__7->GetZaxis()->SetLabelOffset(0.007);
   frameR2__7->GetZaxis()->SetLabelSize(0.05);
   frameR2__7->GetZaxis()->SetTitleSize(0.06);
   frameR2__7->GetZaxis()->SetTitleFont(42);
   frameR2__7->Draw("AXIS");
   Double_t xAxis6[36] = {0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000, 2500, 3200, 4000}; 
   
   TH1F *obs_new__8 = new TH1F("obs_new__8","",35, xAxis6);
   obs_new__8->SetBinContent(1,1.040194);
   obs_new__8->SetBinContent(2,0.9761538);
   obs_new__8->SetBinContent(3,0.995943);
   obs_new__8->SetBinContent(4,1.009648);
   obs_new__8->SetBinContent(5,0.9874854);
   obs_new__8->SetBinContent(6,1.011704);
   obs_new__8->SetBinContent(7,1.015868);
   obs_new__8->SetBinContent(8,0.9946514);
   obs_new__8->SetBinContent(9,1.028072);
   obs_new__8->SetBinContent(10,0.9945254);
   obs_new__8->SetBinContent(11,1.008052);
   obs_new__8->SetBinContent(12,1.005748);
   obs_new__8->SetBinContent(13,1.006205);
   obs_new__8->SetBinContent(14,1.018518);
   obs_new__8->SetBinContent(15,1.035529);
   obs_new__8->SetBinContent(16,1.031108);
   obs_new__8->SetBinError(1,0.07108879);
   obs_new__8->SetBinError(2,0.01421217);
   obs_new__8->SetBinError(3,0.04409682);
   obs_new__8->SetBinError(4,0.01635095);
   obs_new__8->SetBinError(5,0.02678203);
   obs_new__8->SetBinError(6,0.03072379);
   obs_new__8->SetBinError(7,0.02242454);
   obs_new__8->SetBinError(8,0.04501682);
   obs_new__8->SetBinError(9,0.08414012);
   obs_new__8->SetBinError(10,0.03646614);
   obs_new__8->SetBinError(11,0.04441024);
   obs_new__8->SetBinError(12,0.03961978);
   obs_new__8->SetBinError(13,0.0373262);
   obs_new__8->SetBinError(14,0.1339154);
   obs_new__8->SetBinError(15,0.08424151);
   obs_new__8->SetBinError(16,0.08005187);
   obs_new__8->SetEntries(4626.543);
   
   TF1 *pol11 = new TF1("pol1","pol1",50,250, TF1::EAddToList::kNo);
   pol11->SetBit(TF1::kNotDraw);
   pol11->SetFillColor(19);
   pol11->SetFillStyle(0);
   pol11->SetMarkerStyle(20);
   pol11->SetLineColor(2);
   pol11->SetLineWidth(1);
   pol11->SetChisquare(1.041036);
   pol11->SetNDF(9);
   pol11->GetXaxis()->SetLabelFont(42);
   pol11->GetXaxis()->SetLabelOffset(0.007);
   pol11->GetXaxis()->SetLabelSize(0.05);
   pol11->GetXaxis()->SetTitleSize(0.06);
   pol11->GetXaxis()->SetTitleOffset(0.9);
   pol11->GetXaxis()->SetTitleFont(42);
   pol11->GetYaxis()->SetLabelFont(42);
   pol11->GetYaxis()->SetLabelOffset(0.007);
   pol11->GetYaxis()->SetLabelSize(0.05);
   pol11->GetYaxis()->SetTitleSize(0.06);
   pol11->GetYaxis()->SetTitleOffset(1.25);
   pol11->GetYaxis()->SetTitleFont(42);
   pol11->SetParameter(0,1.005639);
   pol11->SetParError(0,0.02102038);
   pol11->SetParLimits(0,0,0);
   pol11->SetParameter(1,1.74834e-06);
   pol11->SetParError(1,0.0001546866);
   pol11->SetParLimits(1,0,0);
   pol11->SetParent(obs_new__8);
   obs_new__8->GetListOfFunctions()->Add(pol11);
   obs_new__8->SetMarkerStyle(21);
   obs_new__8->SetMarkerSize(0.7);
   obs_new__8->GetXaxis()->SetTitle("Mass [GeV]");
   obs_new__8->GetXaxis()->SetRange(1,15);
   obs_new__8->GetXaxis()->SetLabelFont(42);
   obs_new__8->GetXaxis()->SetLabelSize(0.035);
   obs_new__8->GetXaxis()->SetTitleSize(0.035);
   obs_new__8->GetXaxis()->SetTitleFont(42);
   obs_new__8->GetYaxis()->SetLabelFont(42);
   obs_new__8->GetYaxis()->SetLabelSize(0.035);
   obs_new__8->GetYaxis()->SetTitleSize(0.035);
   obs_new__8->GetYaxis()->SetTitleOffset(0);
   obs_new__8->GetYaxis()->SetTitleFont(42);
   obs_new__8->GetZaxis()->SetLabelFont(42);
   obs_new__8->GetZaxis()->SetLabelSize(0.035);
   obs_new__8->GetZaxis()->SetTitleSize(0.035);
   obs_new__8->GetZaxis()->SetTitleFont(42);
   obs_new__8->Draw("same E0");
   line = new TLine(0,1,300,1);
   line->SetLineStyle(3);
   line->Draw();
   t3->Modified();
   c1->cd();
  
// ------------>Primitives in pad: t4
   TPad *t4 = new TPad("t4", "t4",0,0,0.95,0.15);
   t4->Draw();
   t4->cd();
   t4->Range(-58.53658,-6,307.3171,4);
   t4->SetFillColor(0);
   t4->SetBorderMode(0);
   t4->SetBorderSize(2);
   t4->SetGridy();
   t4->SetTickx(1);
   t4->SetTicky(1);
   t4->SetLeftMargin(0.16);
   t4->SetRightMargin(0.02);
   t4->SetBottomMargin(0.3);
   t4->SetFrameFillStyle(0);
   t4->SetFrameBorderMode(0);
   t4->SetFrameFillStyle(0);
   t4->SetFrameBorderMode(0);
   
   TH1D *frameR3__9 = new TH1D("frameR3__9","",1,0,300);
   frameR3__9->SetMinimum(-3);
   frameR3__9->SetMaximum(3);
   frameR3__9->SetStats(0);
   frameR3__9->SetLineStyle(0);
   frameR3__9->SetMarkerStyle(20);
   frameR3__9->GetXaxis()->SetTitle("Mass (GeV)");
   frameR3__9->GetXaxis()->SetLabelFont(43);
   frameR3__9->GetXaxis()->SetLabelOffset(0.007);
   frameR3__9->GetXaxis()->SetLabelSize(14);
   frameR3__9->GetXaxis()->SetTitleSize(20);
   frameR3__9->GetXaxis()->SetTitleOffset(3.75);
   frameR3__9->GetXaxis()->SetTitleFont(43);
   frameR3__9->GetYaxis()->SetTitle("#frac{Data-pred}{#sigma}");
   frameR3__9->GetYaxis()->SetNdivisions(503);
   frameR3__9->GetYaxis()->SetLabelFont(43);
   frameR3__9->GetYaxis()->SetLabelOffset(0.007);
   frameR3__9->GetYaxis()->SetLabelSize(12);
   frameR3__9->GetYaxis()->SetTitleSize(16);
   frameR3__9->GetYaxis()->SetTickLength(0.06);
   frameR3__9->GetYaxis()->SetTitleOffset(1.25);
   frameR3__9->GetYaxis()->SetTitleFont(43);
   frameR3__9->GetZaxis()->SetLabelFont(42);
   frameR3__9->GetZaxis()->SetLabelOffset(0.007);
   frameR3__9->GetZaxis()->SetLabelSize(0.05);
   frameR3__9->GetZaxis()->SetTitleSize(0.06);
   frameR3__9->GetZaxis()->SetTitleFont(42);
   frameR3__9->Draw("AXIS");
   Double_t xAxis7[36] = {0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000, 2500, 3200, 4000}; 
   
   TH1F *pred_new__10 = new TH1F("pred_new__10","",35, xAxis7);
   pred_new__10->SetBinContent(1,0.5880932);
   pred_new__10->SetBinContent(2,-1.638464);
   pred_new__10->SetBinContent(3,-0.09162955);
   pred_new__10->SetBinContent(4,0.5956066);
   pred_new__10->SetBinContent(5,-0.4615102);
   pred_new__10->SetBinContent(6,0.3853339);
   pred_new__10->SetBinContent(7,0.7183532);
   pred_new__10->SetBinContent(8,-0.1181872);
   pred_new__10->SetBinContent(9,0.3429245);
   pred_new__10->SetBinContent(10,-0.1493495);
   pred_new__10->SetBinContent(11,0.1826966);
   pred_new__10->SetBinContent(12,0.1458368);
   pred_new__10->SetBinContent(13,0.1671045);
   pred_new__10->SetBinContent(14,0.1407951);
   pred_new__10->SetBinContent(15,0.4356231);
   pred_new__10->SetBinContent(16,0.3993269);
   pred_new__10->SetBinError(1,8384.565);
   pred_new__10->SetBinError(2,4483.47);
   pred_new__10->SetBinError(3,9417.678);
   pred_new__10->SetBinError(4,2166.083);
   pred_new__10->SetBinError(5,2616.793);
   pred_new__10->SetBinError(6,1974.568);
   pred_new__10->SetBinError(7,974.6339);
   pred_new__10->SetBinError(8,1408.656);
   pred_new__10->SetBinError(9,1665.177);
   pred_new__10->SetBinError(10,497.5426);
   pred_new__10->SetBinError(11,395.5488);
   pred_new__10->SetBinError(12,237.2902);
   pred_new__10->SetBinError(13,143.8477);
   pred_new__10->SetBinError(14,381.3236);
   pred_new__10->SetBinError(15,160.4235);
   pred_new__10->SetBinError(16,108.7754);
   pred_new__10->SetBinError(17,1095.184);
   pred_new__10->SetBinError(18,746.0742);
   pred_new__10->SetBinError(19,602.7457);
   pred_new__10->SetBinError(20,603.0703);
   pred_new__10->SetBinError(21,430.7242);
   pred_new__10->SetBinError(22,340.254);
   pred_new__10->SetBinError(23,278.2657);
   pred_new__10->SetBinError(24,163.0563);
   pred_new__10->SetBinError(25,106.078);
   pred_new__10->SetBinError(26,71.20052);
   pred_new__10->SetBinError(27,36.06265);
   pred_new__10->SetBinError(28,17.38978);
   pred_new__10->SetBinError(29,8.246458);
   pred_new__10->SetBinError(30,3.970643);
   pred_new__10->SetBinError(31,1.635199);
   pred_new__10->SetBinError(32,0.575956);
   pred_new__10->SetBinError(33,0.3747009);
   pred_new__10->SetBinError(34,0.1446313);
   pred_new__10->SetBinError(35,0.0559234);
   pred_new__10->SetEntries(457);
   pred_new__10->SetFillColor(38);
   pred_new__10->GetXaxis()->SetTitle("Mass [GeV]");
   pred_new__10->GetXaxis()->SetRange(1,400);
   pred_new__10->GetXaxis()->SetLabelFont(42);
   pred_new__10->GetXaxis()->SetLabelSize(0.035);
   pred_new__10->GetXaxis()->SetTitleSize(0.035);
   pred_new__10->GetXaxis()->SetTitleFont(42);
   pred_new__10->GetYaxis()->SetLabelFont(42);
   pred_new__10->GetYaxis()->SetLabelSize(0.035);
   pred_new__10->GetYaxis()->SetTitleSize(0.035);
   pred_new__10->GetYaxis()->SetTitleOffset(0);
   pred_new__10->GetYaxis()->SetTitleFont(42);
   pred_new__10->GetZaxis()->SetLabelFont(42);
   pred_new__10->GetZaxis()->SetLabelSize(0.035);
   pred_new__10->GetZaxis()->SetTitleSize(0.035);
   pred_new__10->GetZaxis()->SetTitleFont(42);
   pred_new__10->Draw("same HIST");
   
   TH1D *frameR3_copy__11 = new TH1D("frameR3_copy__11","",1,0,300);
   frameR3_copy__11->SetMinimum(-3);
   frameR3_copy__11->SetMaximum(3);
   frameR3_copy__11->SetDirectory(0);
   frameR3_copy__11->SetStats(0);
   frameR3_copy__11->SetLineStyle(0);
   frameR3_copy__11->SetMarkerStyle(20);
   frameR3_copy__11->GetXaxis()->SetTitle("Mass (GeV)");
   frameR3_copy__11->GetXaxis()->SetLabelFont(43);
   frameR3_copy__11->GetXaxis()->SetLabelOffset(0.007);
   frameR3_copy__11->GetXaxis()->SetLabelSize(14);
   frameR3_copy__11->GetXaxis()->SetTitleSize(20);
   frameR3_copy__11->GetXaxis()->SetTitleOffset(3.75);
   frameR3_copy__11->GetXaxis()->SetTitleFont(43);
   frameR3_copy__11->GetYaxis()->SetTitle("#frac{Data-pred}{#sigma}");
   frameR3_copy__11->GetYaxis()->SetNdivisions(503);
   frameR3_copy__11->GetYaxis()->SetLabelFont(43);
   frameR3_copy__11->GetYaxis()->SetLabelOffset(0.007);
   frameR3_copy__11->GetYaxis()->SetLabelSize(12);
   frameR3_copy__11->GetYaxis()->SetTitleSize(16);
   frameR3_copy__11->GetYaxis()->SetTickLength(0.06);
   frameR3_copy__11->GetYaxis()->SetTitleOffset(1.25);
   frameR3_copy__11->GetYaxis()->SetTitleFont(43);
   frameR3_copy__11->GetZaxis()->SetLabelFont(42);
   frameR3_copy__11->GetZaxis()->SetLabelOffset(0.007);
   frameR3_copy__11->GetZaxis()->SetLabelSize(0.05);
   frameR3_copy__11->GetZaxis()->SetTitleSize(0.06);
   frameR3_copy__11->GetZaxis()->SetTitleFont(42);
   frameR3_copy__11->Draw("sameaxis");
   
   TH1D *frameR3_copy__12 = new TH1D("frameR3_copy__12","",1,0,300);
   frameR3_copy__12->SetMinimum(-3);
   frameR3_copy__12->SetMaximum(3);
   frameR3_copy__12->SetDirectory(0);
   frameR3_copy__12->SetStats(0);
   frameR3_copy__12->SetLineStyle(0);
   frameR3_copy__12->SetMarkerStyle(20);
   frameR3_copy__12->GetXaxis()->SetTitle("Mass (GeV)");
   frameR3_copy__12->GetXaxis()->SetLabelFont(43);
   frameR3_copy__12->GetXaxis()->SetLabelOffset(0.007);
   frameR3_copy__12->GetXaxis()->SetLabelSize(14);
   frameR3_copy__12->GetXaxis()->SetTitleSize(20);
   frameR3_copy__12->GetXaxis()->SetTitleOffset(3.75);
   frameR3_copy__12->GetXaxis()->SetTitleFont(43);
   frameR3_copy__12->GetYaxis()->SetTitle("#frac{Data-pred}{#sigma}");
   frameR3_copy__12->GetYaxis()->SetNdivisions(503);
   frameR3_copy__12->GetYaxis()->SetLabelFont(43);
   frameR3_copy__12->GetYaxis()->SetLabelOffset(0.007);
   frameR3_copy__12->GetYaxis()->SetLabelSize(12);
   frameR3_copy__12->GetYaxis()->SetTitleSize(16);
   frameR3_copy__12->GetYaxis()->SetTickLength(0.06);
   frameR3_copy__12->GetYaxis()->SetTitleOffset(1.25);
   frameR3_copy__12->GetYaxis()->SetTitleFont(43);
   frameR3_copy__12->GetZaxis()->SetLabelFont(42);
   frameR3_copy__12->GetZaxis()->SetLabelOffset(0.007);
   frameR3_copy__12->GetZaxis()->SetLabelSize(0.05);
   frameR3_copy__12->GetZaxis()->SetTitleSize(0.06);
   frameR3_copy__12->GetZaxis()->SetTitleFont(42);
   frameR3_copy__12->Draw("sameaxig");
   line = new TLine(0,0,300,0);
   line->Draw();
   line = new TLine(0,1,300,1);
   line->SetLineStyle(4);
   line->Draw();
   line = new TLine(0,-1,300,-1);
   line->SetLineStyle(4);
   line->Draw();
   line = new TLine(0,2,300,2);
   line->SetLineStyle(4);
   line->Draw();
   line = new TLine(0,-2,300,-2);
   line->SetLineStyle(4);
   line->Draw();
   t4->Modified();
   c1->cd();
   TLatex *   tex = new TLatex(0.928,0.955,"#scale[0.85]{84.5 fb^{-1} (13 TeV)}");
tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetTextFont(42);
   tex->SetTextSize(0.0275);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.16,0.955,"Private work");
tex->SetNDC();
   tex->SetTextFont(52);
   tex->SetTextSize(0.03);
   tex->SetLineWidth(2);
   tex->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
