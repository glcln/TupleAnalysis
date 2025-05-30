void mass_plot_region8fp9_2018_lowmass_3p0()
{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Apr 22 17:02:39 2025) by ROOT version 6.14/09
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
   pred_new__1->SetBinContent(1,22555.69);
   pred_new__1->SetBinContent(2,67790.55);
   pred_new__1->SetBinContent(3,65607.62);
   pred_new__1->SetBinContent(4,47116.6);
   pred_new__1->SetBinContent(5,34506.98);
   pred_new__1->SetBinContent(6,24545.8);
   pred_new__1->SetBinContent(7,18498.26);
   pred_new__1->SetBinContent(8,14521.93);
   pred_new__1->SetBinContent(9,10701.17);
   pred_new__1->SetBinContent(10,8263.995);
   pred_new__1->SetBinContent(11,6340.267);
   pred_new__1->SetBinContent(12,4990.8);
   pred_new__1->SetBinContent(13,3694.393);
   pred_new__1->SetBinContent(14,2902.586);
   pred_new__1->SetBinContent(15,2187.023);
   pred_new__1->SetBinContent(16,1751.789);
   pred_new__1->SetBinError(1,2075.894);
   pred_new__1->SetBinError(2,1025.998);
   pred_new__1->SetBinError(3,529.5422);
   pred_new__1->SetBinError(4,465.9757);
   pred_new__1->SetBinError(5,860.2178);
   pred_new__1->SetBinError(6,575.239);
   pred_new__1->SetBinError(7,366.215);
   pred_new__1->SetBinError(8,710.9019);
   pred_new__1->SetBinError(9,550.7993);
   pred_new__1->SetBinError(10,241.9964);
   pred_new__1->SetBinError(11,331.7244);
   pred_new__1->SetBinError(12,346.1123);
   pred_new__1->SetBinError(13,306.029);
   pred_new__1->SetBinError(14,198.0781);
   pred_new__1->SetBinError(15,119.7309);
   pred_new__1->SetBinError(16,156.9179);
   pred_new__1->SetBinError(17,1398.425);
   pred_new__1->SetBinError(18,958.873);
   pred_new__1->SetBinError(19,868.7317);
   pred_new__1->SetBinError(20,906.997);
   pred_new__1->SetBinError(21,646.7758);
   pred_new__1->SetBinError(22,568.3403);
   pred_new__1->SetBinError(23,495.6029);
   pred_new__1->SetBinError(24,275.0444);
   pred_new__1->SetBinError(25,181.9005);
   pred_new__1->SetBinError(26,119.1027);
   pred_new__1->SetBinError(27,63.52849);
   pred_new__1->SetBinError(28,29.21599);
   pred_new__1->SetBinError(29,12.86254);
   pred_new__1->SetBinError(30,5.882365);
   pred_new__1->SetBinError(31,2.978223);
   pred_new__1->SetBinError(32,1.221377);
   pred_new__1->SetBinError(33,0.6845163);
   pred_new__1->SetBinError(34,0.2582677);
   pred_new__1->SetBinError(35,0.02737721);
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
   pred_noSyst_new__2->SetBinContent(1,22555.69);
   pred_noSyst_new__2->SetBinContent(2,67790.55);
   pred_noSyst_new__2->SetBinContent(3,65607.62);
   pred_noSyst_new__2->SetBinContent(4,47116.6);
   pred_noSyst_new__2->SetBinContent(5,34506.98);
   pred_noSyst_new__2->SetBinContent(6,24545.8);
   pred_noSyst_new__2->SetBinContent(7,18498.26);
   pred_noSyst_new__2->SetBinContent(8,14521.93);
   pred_noSyst_new__2->SetBinContent(9,10701.17);
   pred_noSyst_new__2->SetBinContent(10,8263.995);
   pred_noSyst_new__2->SetBinContent(11,6340.267);
   pred_noSyst_new__2->SetBinContent(12,4990.8);
   pred_noSyst_new__2->SetBinContent(13,3694.393);
   pred_noSyst_new__2->SetBinContent(14,2902.586);
   pred_noSyst_new__2->SetBinContent(15,2187.023);
   pred_noSyst_new__2->SetBinContent(16,1751.789);
   pred_noSyst_new__2->SetBinContent(17,1398.354);
   pred_noSyst_new__2->SetBinContent(18,958.8221);
   pred_noSyst_new__2->SetBinContent(19,868.6815);
   pred_noSyst_new__2->SetBinContent(20,906.9595);
   pred_noSyst_new__2->SetBinContent(21,646.7476);
   pred_noSyst_new__2->SetBinContent(22,568.3172);
   pred_noSyst_new__2->SetBinContent(23,495.5847);
   pred_noSyst_new__2->SetBinContent(24,275.0331);
   pred_noSyst_new__2->SetBinContent(25,181.8922);
   pred_noSyst_new__2->SetBinContent(26,119.0967);
   pred_noSyst_new__2->SetBinContent(27,63.52303);
   pred_noSyst_new__2->SetBinContent(28,29.21152);
   pred_noSyst_new__2->SetBinContent(29,12.85798);
   pred_noSyst_new__2->SetBinContent(30,5.877883);
   pred_noSyst_new__2->SetBinContent(31,2.973546);
   pred_noSyst_new__2->SetBinContent(32,1.216742);
   pred_noSyst_new__2->SetBinContent(33,0.6810766);
   pred_noSyst_new__2->SetBinContent(34,0.2560548);
   pred_noSyst_new__2->SetBinContent(35,0.02703019);
   pred_noSyst_new__2->SetBinError(1,196.346);
   pred_noSyst_new__2->SetBinError(2,411.3473);
   pred_noSyst_new__2->SetBinError(3,368.6776);
   pred_noSyst_new__2->SetBinError(4,252.4635);
   pred_noSyst_new__2->SetBinError(5,190.8105);
   pred_noSyst_new__2->SetBinError(6,143.9322);
   pred_noSyst_new__2->SetBinError(7,116.7403);
   pred_noSyst_new__2->SetBinError(8,97.20511);
   pred_noSyst_new__2->SetBinError(9,76.00381);
   pred_noSyst_new__2->SetBinError(10,61.43064);
   pred_noSyst_new__2->SetBinError(11,50.00725);
   pred_noSyst_new__2->SetBinError(12,40.8824);
   pred_noSyst_new__2->SetBinError(13,31.94373);
   pred_noSyst_new__2->SetBinError(14,25.83533);
   pred_noSyst_new__2->SetBinError(15,20.37277);
   pred_noSyst_new__2->SetBinError(16,16.92864);
   pred_noSyst_new__2->SetBinError(17,14.0895);
   pred_noSyst_new__2->SetBinError(18,9.882428);
   pred_noSyst_new__2->SetBinError(19,9.345057);
   pred_noSyst_new__2->SetBinError(20,8.25585);
   pred_noSyst_new__2->SetBinError(21,6.042274);
   pred_noSyst_new__2->SetBinError(22,5.120195);
   pred_noSyst_new__2->SetBinError(23,4.240178);
   pred_noSyst_new__2->SetBinError(24,2.493481);
   pred_noSyst_new__2->SetBinError(25,1.739758);
   pred_noSyst_new__2->SetBinError(26,1.191261);
   pred_noSyst_new__2->SetBinError(27,0.8333137);
   pred_noSyst_new__2->SetBinError(28,0.5111234);
   pred_noSyst_new__2->SetBinError(29,0.342319);
   pred_noSyst_new__2->SetBinError(30,0.2295926);
   pred_noSyst_new__2->SetBinError(31,0.1668574);
   pred_noSyst_new__2->SetBinError(32,0.1063007);
   pred_noSyst_new__2->SetBinError(33,0.06853636);
   pred_noSyst_new__2->SetBinError(34,0.03373581);
   pred_noSyst_new__2->SetBinError(35,0.00434519);
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
   pred_new__3->SetBinContent(1,22555.69);
   pred_new__3->SetBinContent(2,67790.55);
   pred_new__3->SetBinContent(3,65607.62);
   pred_new__3->SetBinContent(4,47116.6);
   pred_new__3->SetBinContent(5,34506.98);
   pred_new__3->SetBinContent(6,24545.8);
   pred_new__3->SetBinContent(7,18498.26);
   pred_new__3->SetBinContent(8,14521.93);
   pred_new__3->SetBinContent(9,10701.17);
   pred_new__3->SetBinContent(10,8263.995);
   pred_new__3->SetBinContent(11,6340.267);
   pred_new__3->SetBinContent(12,4990.8);
   pred_new__3->SetBinContent(13,3694.393);
   pred_new__3->SetBinContent(14,2902.586);
   pred_new__3->SetBinContent(15,2187.023);
   pred_new__3->SetBinContent(16,1751.789);
   pred_new__3->SetBinError(1,2075.894);
   pred_new__3->SetBinError(2,1025.998);
   pred_new__3->SetBinError(3,529.5422);
   pred_new__3->SetBinError(4,465.9757);
   pred_new__3->SetBinError(5,860.2178);
   pred_new__3->SetBinError(6,575.239);
   pred_new__3->SetBinError(7,366.215);
   pred_new__3->SetBinError(8,710.9019);
   pred_new__3->SetBinError(9,550.7993);
   pred_new__3->SetBinError(10,241.9964);
   pred_new__3->SetBinError(11,331.7244);
   pred_new__3->SetBinError(12,346.1123);
   pred_new__3->SetBinError(13,306.029);
   pred_new__3->SetBinError(14,198.0781);
   pred_new__3->SetBinError(15,119.7309);
   pred_new__3->SetBinError(16,156.9179);
   pred_new__3->SetBinError(17,1398.425);
   pred_new__3->SetBinError(18,958.873);
   pred_new__3->SetBinError(19,868.7317);
   pred_new__3->SetBinError(20,906.997);
   pred_new__3->SetBinError(21,646.7758);
   pred_new__3->SetBinError(22,568.3403);
   pred_new__3->SetBinError(23,495.6029);
   pred_new__3->SetBinError(24,275.0444);
   pred_new__3->SetBinError(25,181.9005);
   pred_new__3->SetBinError(26,119.1027);
   pred_new__3->SetBinError(27,63.52849);
   pred_new__3->SetBinError(28,29.21599);
   pred_new__3->SetBinError(29,12.86254);
   pred_new__3->SetBinError(30,5.882365);
   pred_new__3->SetBinError(31,2.978223);
   pred_new__3->SetBinError(32,1.221377);
   pred_new__3->SetBinError(33,0.6845163);
   pred_new__3->SetBinError(34,0.2582677);
   pred_new__3->SetBinError(35,0.02737721);
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
   obs_new__4->SetBinContent(1,24473);
   obs_new__4->SetBinContent(2,66182);
   obs_new__4->SetBinContent(3,64325);
   obs_new__4->SetBinContent(4,47273);
   obs_new__4->SetBinContent(5,34284);
   obs_new__4->SetBinContent(6,24937);
   obs_new__4->SetBinContent(7,18854);
   obs_new__4->SetBinContent(8,14453);
   obs_new__4->SetBinContent(9,10796);
   obs_new__4->SetBinContent(10,8476);
   obs_new__4->SetBinContent(11,6462);
   obs_new__4->SetBinContent(12,4861);
   obs_new__4->SetBinContent(13,3739);
   obs_new__4->SetBinContent(14,2863);
   obs_new__4->SetBinContent(15,2251);
   obs_new__4->SetBinContent(16,1719);
   obs_new__4->SetEntries(335948);
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
   pred_new__6->SetBinContent(0,0.9999183);
   pred_new__6->SetBinContent(1,0.9999183);
   pred_new__6->SetBinContent(2,0.993795);
   pred_new__6->SetBinContent(3,0.9986312);
   pred_new__6->SetBinContent(4,1.005257);
   pred_new__6->SetBinContent(5,1.005944);
   pred_new__6->SetBinContent(6,1.010295);
   pred_new__6->SetBinContent(7,1.008419);
   pred_new__6->SetBinContent(8,1.004806);
   pred_new__6->SetBinContent(9,1.008204);
   pred_new__6->SetBinContent(10,1.00797);
   pred_new__6->SetBinContent(11,1.001287);
   pred_new__6->SetBinContent(12,0.9939722);
   pred_new__6->SetBinContent(13,1.003437);
   pred_new__6->SetBinContent(14,0.9987724);
   pred_new__6->SetBinContent(15,1.007918);
   pred_new__6->SetBinContent(16,0.9812827);
   pred_new__6->SetBinError(0,0.01122961);
   pred_new__6->SetBinError(1,0.01122961);
   pred_new__6->SetBinError(2,0.00998022);
   pred_new__6->SetBinError(3,0.01205015);
   pred_new__6->SetBinError(4,0.01622037);
   pred_new__6->SetBinError(5,0.02163892);
   pred_new__6->SetBinError(6,0.02792809);
   pred_new__6->SetBinError(7,0.03623916);
   pred_new__6->SetBinError(8,0.04765284);
   pred_new__6->SetBinError(9,0.06232571);
   pred_new__6->SetBinError(10,0.08233458);
   pred_new__6->SetBinError(11,0.1120771);
   pred_new__6->SetBinError(12,0.1551628);
   pred_new__6->SetBinError(13,0.2283732);
   pred_new__6->SetBinError(14,0.3470865);
   pred_new__6->SetBinError(15,0.6061075);
   pred_new__6->SetBinError(16,1.324842);
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
   obs_new__8->SetBinContent(1,1.085003);
   obs_new__8->SetBinContent(2,0.9762717);
   obs_new__8->SetBinContent(3,0.98045);
   obs_new__8->SetBinContent(4,1.00332);
   obs_new__8->SetBinContent(5,0.9935382);
   obs_new__8->SetBinContent(6,1.015938);
   obs_new__8->SetBinContent(7,1.019231);
   obs_new__8->SetBinContent(8,0.9952537);
   obs_new__8->SetBinContent(9,1.008862);
   obs_new__8->SetBinContent(10,1.025654);
   obs_new__8->SetBinContent(11,1.0192);
   obs_new__8->SetBinContent(12,0.9739921);
   obs_new__8->SetBinContent(13,1.012074);
   obs_new__8->SetBinContent(14,0.9863617);
   obs_new__8->SetBinContent(15,1.029253);
   obs_new__8->SetBinContent(16,0.9812827);
   obs_new__8->SetBinError(1,0.1000979);
   obs_new__8->SetBinError(2,0.01525525);
   obs_new__8->SetBinError(3,0.0088073);
   obs_new__8->SetBinError(4,0.01094321);
   obs_new__8->SetBinError(5,0.02534231);
   obs_new__8->SetBinError(6,0.02466273);
   obs_new__8->SetBinError(7,0.02149999);
   obs_new__8->SetBinError(8,0.04941967);
   obs_new__8->SetBinError(9,0.05282703);
   obs_new__8->SetBinError(10,0.03203404);
   obs_new__8->SetBinError(11,0.05481136);
   obs_new__8->SetBinError(12,0.06897589);
   obs_new__8->SetBinError(13,0.08545449);
   obs_new__8->SetBinError(14,0.06978983);
   obs_new__8->SetBinError(15,0.06037934);
   obs_new__8->SetBinError(16,0.09102984);
   obs_new__8->SetEntries(5158.079);
   
   TF1 *pol11 = new TF1("pol1","pol1",50,250, TF1::EAddToList::kNo);
   pol11->SetBit(TF1::kNotDraw);
   pol11->SetFillColor(19);
   pol11->SetFillStyle(0);
   pol11->SetMarkerStyle(20);
   pol11->SetLineColor(2);
   pol11->SetLineWidth(1);
   pol11->SetChisquare(3.214026);
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
   pol11->SetParameter(0,0.9747725);
   pol11->SetParError(0,0.01256643);
   pol11->SetParLimits(0,0,0);
   pol11->SetParameter(1,0.0002594883);
   pol11->SetParError(1,0.0001407747);
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
   pred_new__10->SetBinContent(1,0.9211996);
   pred_new__10->SetBinContent(2,-1.519628);
   pred_new__10->SetBinContent(3,-2.180457);
   pred_new__10->SetBinContent(4,0.3042537);
   pred_new__10->SetBinContent(5,-0.2533691);
   pred_new__10->SetBinContent(6,0.6561689);
   pred_new__10->SetBinContent(7,0.9106141);
   pred_new__10->SetBinContent(8,-0.09559174);
   pred_new__10->SetBinContent(9,0.1692097);
   pred_new__10->SetBinContent(10,0.8201104);
   pred_new__10->SetBinContent(11,0.3568355);
   pred_new__10->SetBinContent(12,-0.3674476);
   pred_new__10->SetBinContent(13,0.1429695);
   pred_new__10->SetBinContent(14,-0.1928466);
   pred_new__10->SetBinContent(15,0.4977212);
   pred_new__10->SetBinContent(16,-0.2018967);
   pred_new__10->SetBinError(1,2075.894);
   pred_new__10->SetBinError(2,1025.998);
   pred_new__10->SetBinError(3,529.5422);
   pred_new__10->SetBinError(4,465.9757);
   pred_new__10->SetBinError(5,860.2178);
   pred_new__10->SetBinError(6,575.239);
   pred_new__10->SetBinError(7,366.215);
   pred_new__10->SetBinError(8,710.9019);
   pred_new__10->SetBinError(9,550.7993);
   pred_new__10->SetBinError(10,241.9964);
   pred_new__10->SetBinError(11,331.7244);
   pred_new__10->SetBinError(12,346.1123);
   pred_new__10->SetBinError(13,306.029);
   pred_new__10->SetBinError(14,198.0781);
   pred_new__10->SetBinError(15,119.7309);
   pred_new__10->SetBinError(16,156.9179);
   pred_new__10->SetBinError(17,1398.425);
   pred_new__10->SetBinError(18,958.873);
   pred_new__10->SetBinError(19,868.7317);
   pred_new__10->SetBinError(20,906.997);
   pred_new__10->SetBinError(21,646.7758);
   pred_new__10->SetBinError(22,568.3403);
   pred_new__10->SetBinError(23,495.6029);
   pred_new__10->SetBinError(24,275.0444);
   pred_new__10->SetBinError(25,181.9005);
   pred_new__10->SetBinError(26,119.1027);
   pred_new__10->SetBinError(27,63.52849);
   pred_new__10->SetBinError(28,29.21599);
   pred_new__10->SetBinError(29,12.86254);
   pred_new__10->SetBinError(30,5.882365);
   pred_new__10->SetBinError(31,2.978223);
   pred_new__10->SetBinError(32,1.221377);
   pred_new__10->SetBinError(33,0.6845163);
   pred_new__10->SetBinError(34,0.2582677);
   pred_new__10->SetBinError(35,0.02737721);
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
   TLatex *   tex = new TLatex(0.928,0.955,"#scale[0.85]{ (13 TeV)}");
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
