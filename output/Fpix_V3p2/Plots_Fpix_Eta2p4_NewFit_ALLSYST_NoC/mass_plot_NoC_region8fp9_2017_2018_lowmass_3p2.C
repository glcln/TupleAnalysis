void mass_plot_NoC_region8fp9_2017_2018_lowmass_3p2()
{
//=========Macro generated from canvas: c1/c1
//=========  (Mon May 12 13:41:09 2025) by ROOT version 6.14/09
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
   pred_new__1->SetBinContent(1,4055.55);
   pred_new__1->SetBinContent(2,13491.87);
   pred_new__1->SetBinContent(3,14342.72);
   pred_new__1->SetBinContent(4,11698.56);
   pred_new__1->SetBinContent(5,9292.152);
   pred_new__1->SetBinContent(6,6802.063);
   pred_new__1->SetBinContent(7,5187.979);
   pred_new__1->SetBinContent(8,4141.814);
   pred_new__1->SetBinContent(9,3153.41);
   pred_new__1->SetBinContent(10,2519.189);
   pred_new__1->SetBinContent(11,2029.224);
   pred_new__1->SetBinContent(12,1679.211);
   pred_new__1->SetBinContent(13,1294.895);
   pred_new__1->SetBinContent(14,1077.745);
   pred_new__1->SetBinContent(15,852.3317);
   pred_new__1->SetBinContent(16,718.2972);
   pred_new__1->SetBinError(1,918.3141);
   pred_new__1->SetBinError(2,654.9268);
   pred_new__1->SetBinError(3,662.5496);
   pred_new__1->SetBinError(4,431.8765);
   pred_new__1->SetBinError(5,328.1899);
   pred_new__1->SetBinError(6,261.8014);
   pred_new__1->SetBinError(7,201.3289);
   pred_new__1->SetBinError(8,293.161);
   pred_new__1->SetBinError(9,261.6489);
   pred_new__1->SetBinError(10,158.7238);
   pred_new__1->SetBinError(11,225.7179);
   pred_new__1->SetBinError(12,115.7078);
   pred_new__1->SetBinError(13,132.835);
   pred_new__1->SetBinError(14,128.9526);
   pred_new__1->SetBinError(15,109.9123);
   pred_new__1->SetBinError(16,112.6093);
   pred_new__1->SetBinError(17,601.2172);
   pred_new__1->SetBinError(18,424.4099);
   pred_new__1->SetBinError(19,412.3174);
   pred_new__1->SetBinError(20,452.3039);
   pred_new__1->SetBinError(21,335.4995);
   pred_new__1->SetBinError(22,325.6838);
   pred_new__1->SetBinError(23,300.7566);
   pred_new__1->SetBinError(24,182.7886);
   pred_new__1->SetBinError(25,130.9587);
   pred_new__1->SetBinError(26,94.56289);
   pred_new__1->SetBinError(27,54.18751);
   pred_new__1->SetBinError(28,27.72011);
   pred_new__1->SetBinError(29,13.44761);
   pred_new__1->SetBinError(30,7.508749);
   pred_new__1->SetBinError(31,4.017466);
   pred_new__1->SetBinError(32,1.810689);
   pred_new__1->SetBinError(33,1.625886);
   pred_new__1->SetBinError(34,0.8774018);
   pred_new__1->SetBinError(35,0.4374665);
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
   pred_noSyst_new__2->SetBinContent(1,4055.55);
   pred_noSyst_new__2->SetBinContent(2,13491.87);
   pred_noSyst_new__2->SetBinContent(3,14342.72);
   pred_noSyst_new__2->SetBinContent(4,11698.56);
   pred_noSyst_new__2->SetBinContent(5,9292.152);
   pred_noSyst_new__2->SetBinContent(6,6802.063);
   pred_noSyst_new__2->SetBinContent(7,5187.979);
   pred_noSyst_new__2->SetBinContent(8,4141.814);
   pred_noSyst_new__2->SetBinContent(9,3153.41);
   pred_noSyst_new__2->SetBinContent(10,2519.189);
   pred_noSyst_new__2->SetBinContent(11,2029.224);
   pred_noSyst_new__2->SetBinContent(12,1679.211);
   pred_noSyst_new__2->SetBinContent(13,1294.895);
   pred_noSyst_new__2->SetBinContent(14,1077.745);
   pred_noSyst_new__2->SetBinContent(15,852.3317);
   pred_noSyst_new__2->SetBinContent(16,718.2972);
   pred_noSyst_new__2->SetBinContent(17,601.0275);
   pred_noSyst_new__2->SetBinContent(18,424.241);
   pred_noSyst_new__2->SetBinContent(19,412.1501);
   pred_noSyst_new__2->SetBinContent(20,452.1475);
   pred_noSyst_new__2->SetBinContent(21,335.3406);
   pred_noSyst_new__2->SetBinContent(22,325.5179);
   pred_noSyst_new__2->SetBinContent(23,300.5789);
   pred_noSyst_new__2->SetBinContent(24,182.58);
   pred_noSyst_new__2->SetBinContent(25,130.7551);
   pred_noSyst_new__2->SetBinContent(26,94.40057);
   pred_noSyst_new__2->SetBinContent(27,54.07051);
   pred_noSyst_new__2->SetBinContent(28,27.66089);
   pred_noSyst_new__2->SetBinContent(29,13.41871);
   pred_noSyst_new__2->SetBinContent(30,7.497583);
   pred_noSyst_new__2->SetBinContent(31,4.012967);
   pred_noSyst_new__2->SetBinContent(32,1.809037);
   pred_noSyst_new__2->SetBinContent(33,1.624853);
   pred_noSyst_new__2->SetBinContent(34,0.8768029);
   pred_noSyst_new__2->SetBinContent(35,0.4371564);
   pred_noSyst_new__2->SetBinError(1,81.54951);
   pred_noSyst_new__2->SetBinError(2,185.7389);
   pred_noSyst_new__2->SetBinError(3,175.2773);
   pred_noSyst_new__2->SetBinError(4,129.6673);
   pred_noSyst_new__2->SetBinError(5,101.5092);
   pred_noSyst_new__2->SetBinError(6,78.57635);
   pred_noSyst_new__2->SetBinError(7,66.11576);
   pred_noSyst_new__2->SetBinError(8,59.29026);
   pred_noSyst_new__2->SetBinError(9,49.49511);
   pred_noSyst_new__2->SetBinError(10,42.19484);
   pred_noSyst_new__2->SetBinError(11,36.02974);
   pred_noSyst_new__2->SetBinError(12,31.45249);
   pred_noSyst_new__2->SetBinError(13,25.50987);
   pred_noSyst_new__2->SetBinError(14,22.91871);
   pred_noSyst_new__2->SetBinError(15,18.97514);
   pred_noSyst_new__2->SetBinError(16,17.00743);
   pred_noSyst_new__2->SetBinError(17,15.10465);
   pred_noSyst_new__2->SetBinError(18,11.96983);
   pred_noSyst_new__2->SetBinError(19,11.74368);
   pred_noSyst_new__2->SetBinError(20,11.89251);
   pred_noSyst_new__2->SetBinError(21,10.32491);
   pred_noSyst_new__2->SetBinError(22,10.39126);
   pred_noSyst_new__2->SetBinError(23,10.33722);
   pred_noSyst_new__2->SetBinError(24,8.731809);
   pred_noSyst_new__2->SetBinError(25,7.300775);
   pred_noSyst_new__2->SetBinError(26,5.538231);
   pred_noSyst_new__2->SetBinError(27,3.558894);
   pred_noSyst_new__2->SetBinError(28,1.811065);
   pred_noSyst_new__2->SetBinError(29,0.8811258);
   pred_noSyst_new__2->SetBinError(30,0.4093395);
   pred_noSyst_new__2->SetBinError(31,0.1900778);
   pred_noSyst_new__2->SetBinError(32,0.07731475);
   pred_noSyst_new__2->SetBinError(33,0.05794973);
   pred_noSyst_new__2->SetBinError(34,0.03241196);
   pred_noSyst_new__2->SetBinError(35,0.01646962);
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
   pred_new__3->SetBinContent(1,4055.55);
   pred_new__3->SetBinContent(2,13491.87);
   pred_new__3->SetBinContent(3,14342.72);
   pred_new__3->SetBinContent(4,11698.56);
   pred_new__3->SetBinContent(5,9292.152);
   pred_new__3->SetBinContent(6,6802.063);
   pred_new__3->SetBinContent(7,5187.979);
   pred_new__3->SetBinContent(8,4141.814);
   pred_new__3->SetBinContent(9,3153.41);
   pred_new__3->SetBinContent(10,2519.189);
   pred_new__3->SetBinContent(11,2029.224);
   pred_new__3->SetBinContent(12,1679.211);
   pred_new__3->SetBinContent(13,1294.895);
   pred_new__3->SetBinContent(14,1077.745);
   pred_new__3->SetBinContent(15,852.3317);
   pred_new__3->SetBinContent(16,718.2972);
   pred_new__3->SetBinError(1,918.3141);
   pred_new__3->SetBinError(2,654.9268);
   pred_new__3->SetBinError(3,662.5496);
   pred_new__3->SetBinError(4,431.8765);
   pred_new__3->SetBinError(5,328.1899);
   pred_new__3->SetBinError(6,261.8014);
   pred_new__3->SetBinError(7,201.3289);
   pred_new__3->SetBinError(8,293.161);
   pred_new__3->SetBinError(9,261.6489);
   pred_new__3->SetBinError(10,158.7238);
   pred_new__3->SetBinError(11,225.7179);
   pred_new__3->SetBinError(12,115.7078);
   pred_new__3->SetBinError(13,132.835);
   pred_new__3->SetBinError(14,128.9526);
   pred_new__3->SetBinError(15,109.9123);
   pred_new__3->SetBinError(16,112.6093);
   pred_new__3->SetBinError(17,601.2172);
   pred_new__3->SetBinError(18,424.4099);
   pred_new__3->SetBinError(19,412.3174);
   pred_new__3->SetBinError(20,452.3039);
   pred_new__3->SetBinError(21,335.4995);
   pred_new__3->SetBinError(22,325.6838);
   pred_new__3->SetBinError(23,300.7566);
   pred_new__3->SetBinError(24,182.7886);
   pred_new__3->SetBinError(25,130.9587);
   pred_new__3->SetBinError(26,94.56289);
   pred_new__3->SetBinError(27,54.18751);
   pred_new__3->SetBinError(28,27.72011);
   pred_new__3->SetBinError(29,13.44761);
   pred_new__3->SetBinError(30,7.508749);
   pred_new__3->SetBinError(31,4.017466);
   pred_new__3->SetBinError(32,1.810689);
   pred_new__3->SetBinError(33,1.625886);
   pred_new__3->SetBinError(34,0.8774018);
   pred_new__3->SetBinError(35,0.4374665);
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
   obs_new__4->SetBinContent(1,4761);
   obs_new__4->SetBinContent(2,13138);
   obs_new__4->SetBinContent(3,14077);
   obs_new__4->SetBinContent(4,11930);
   obs_new__4->SetBinContent(5,9358);
   obs_new__4->SetBinContent(6,6999);
   obs_new__4->SetBinContent(7,5460);
   obs_new__4->SetBinContent(8,4226);
   obs_new__4->SetBinContent(9,3152);
   obs_new__4->SetBinContent(10,2659);
   obs_new__4->SetBinContent(11,2063);
   obs_new__4->SetBinContent(12,1660);
   obs_new__4->SetBinContent(13,1343);
   obs_new__4->SetBinContent(14,1022);
   obs_new__4->SetBinContent(15,879);
   obs_new__4->SetBinContent(16,700);
   obs_new__4->SetEntries(83427);
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
   pred_new__6->SetBinContent(0,1.013238);
   pred_new__6->SetBinContent(1,1.013238);
   pred_new__6->SetBinContent(2,1.004912);
   pred_new__6->SetBinContent(3,1.011397);
   pred_new__6->SetBinContent(4,1.019905);
   pred_new__6->SetBinContent(5,1.019941);
   pred_new__6->SetBinContent(6,1.023996);
   pred_new__6->SetBinContent(7,1.022508);
   pred_new__6->SetBinContent(8,1.01362);
   pred_new__6->SetBinContent(9,1.011535);
   pred_new__6->SetBinContent(10,1.01525);
   pred_new__6->SetBinContent(11,1.001999);
   pred_new__6->SetBinContent(12,0.9967133);
   pred_new__6->SetBinContent(13,1.000186);
   pred_new__6->SetBinContent(14,0.9821122);
   pred_new__6->SetBinContent(15,1.00533);
   pred_new__6->SetBinContent(16,0.9745269);
   pred_new__6->SetBinError(0,0.02394915);
   pred_new__6->SetBinError(1,0.02394915);
   pred_new__6->SetBinError(2,0.02201412);
   pred_new__6->SetBinError(3,0.02467258);
   pred_new__6->SetBinError(4,0.02890773);
   pred_new__6->SetBinError(5,0.03576786);
   pred_new__6->SetBinError(6,0.04571793);
   pred_new__6->SetBinError(7,0.05805477);
   pred_new__6->SetBinError(8,0.07361163);
   pred_new__6->SetBinError(9,0.09356301);
   pred_new__6->SetBinError(10,0.1200866);
   pred_new__6->SetBinError(11,0.1560316);
   pred_new__6->SetBinError(12,0.2072493);
   pred_new__6->SetBinError(13,0.2948932);
   pred_new__6->SetBinError(14,0.4281206);
   pred_new__6->SetBinError(15,0.7340162);
   pred_new__6->SetBinError(16,1.54817);
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
   obs_new__8->SetBinContent(1,1.173947);
   obs_new__8->SetBinContent(2,0.9737714);
   obs_new__8->SetBinContent(3,0.9814733);
   obs_new__8->SetBinContent(4,1.019783);
   obs_new__8->SetBinContent(5,1.007086);
   obs_new__8->SetBinContent(6,1.028952);
   obs_new__8->SetBinContent(7,1.052433);
   obs_new__8->SetBinContent(8,1.020326);
   obs_new__8->SetBinContent(9,0.9995527);
   obs_new__8->SetBinContent(10,1.055498);
   obs_new__8->SetBinContent(11,1.016645);
   obs_new__8->SetBinContent(12,0.9885595);
   obs_new__8->SetBinContent(13,1.03715);
   obs_new__8->SetBinContent(14,0.9482767);
   obs_new__8->SetBinContent(15,1.031289);
   obs_new__8->SetBinContent(16,0.9745269);
   obs_new__8->SetBinError(1,0.2663653);
   obs_new__8->SetBinError(2,0.0480265);
   obs_new__8->SetBinError(3,0.04608679);
   obs_new__8->SetBinError(4,0.03878785);
   obs_new__8->SetBinError(5,0.03706153);
   obs_new__8->SetBinError(6,0.04146876);
   obs_new__8->SetBinError(7,0.04325382);
   obs_new__8->SetBinError(8,0.07390536);
   obs_new__8->SetBinError(9,0.08482565);
   obs_new__8->SetBinError(10,0.06958147);
   obs_new__8->SetBinError(11,0.115279);
   obs_new__8->SetBinError(12,0.07230998);
   obs_new__8->SetBinError(13,0.1100943);
   obs_new__8->SetBinError(14,0.117275);
   obs_new__8->SetBinError(15,0.1374634);
   obs_new__8->SetBinError(16,0.1571565);
   obs_new__8->SetEntries(1419.874);
   
   TF1 *pol11 = new TF1("pol1","pol1",50,250, TF1::EAddToList::kNo);
   pol11->SetBit(TF1::kNotDraw);
   pol11->SetFillColor(19);
   pol11->SetFillStyle(0);
   pol11->SetMarkerStyle(20);
   pol11->SetLineColor(2);
   pol11->SetLineWidth(1);
   pol11->SetChisquare(1.732563);
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
   pol11->SetParameter(0,1.001983);
   pol11->SetParError(0,0.03878844);
   pol11->SetParLimits(0,0,0);
   pol11->SetParameter(1,0.0001456386);
   pol11->SetParError(1,0.0003094954);
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
   pred_new__10->SetBinContent(1,0.7663606);
   pred_new__10->SetBinContent(2,-0.5320221);
   pred_new__10->SetBinContent(3,-0.3946651);
   pred_new__10->SetBinContent(4,0.5198294);
   pred_new__10->SetBinContent(5,0.1925068);
   pred_new__10->SetBinContent(6,0.7174762);
   pred_new__10->SetBinContent(7,1.272167);
   pred_new__10->SetBinContent(8,0.2804858);
   pred_new__10->SetBinContent(9,-0.005270414);
   pred_new__10->SetBinContent(10,0.8398517);
   pred_new__10->SetBinContent(11,0.1467459);
   pred_new__10->SetBinContent(12,-0.1565048);
   pred_new__10->SetBinContent(13,0.349545);
   pred_new__10->SetBinContent(14,-0.4189244);
   pred_new__10->SetBinContent(15,0.234501);
   pred_new__10->SetBinContent(16,-0.158069);
   pred_new__10->SetBinError(1,918.3141);
   pred_new__10->SetBinError(2,654.9268);
   pred_new__10->SetBinError(3,662.5496);
   pred_new__10->SetBinError(4,431.8765);
   pred_new__10->SetBinError(5,328.1899);
   pred_new__10->SetBinError(6,261.8014);
   pred_new__10->SetBinError(7,201.3289);
   pred_new__10->SetBinError(8,293.161);
   pred_new__10->SetBinError(9,261.6489);
   pred_new__10->SetBinError(10,158.7238);
   pred_new__10->SetBinError(11,225.7179);
   pred_new__10->SetBinError(12,115.7078);
   pred_new__10->SetBinError(13,132.835);
   pred_new__10->SetBinError(14,128.9526);
   pred_new__10->SetBinError(15,109.9123);
   pred_new__10->SetBinError(16,112.6093);
   pred_new__10->SetBinError(17,601.2172);
   pred_new__10->SetBinError(18,424.4099);
   pred_new__10->SetBinError(19,412.3174);
   pred_new__10->SetBinError(20,452.3039);
   pred_new__10->SetBinError(21,335.4995);
   pred_new__10->SetBinError(22,325.6838);
   pred_new__10->SetBinError(23,300.7566);
   pred_new__10->SetBinError(24,182.7886);
   pred_new__10->SetBinError(25,130.9587);
   pred_new__10->SetBinError(26,94.56289);
   pred_new__10->SetBinError(27,54.18751);
   pred_new__10->SetBinError(28,27.72011);
   pred_new__10->SetBinError(29,13.44761);
   pred_new__10->SetBinError(30,7.508749);
   pred_new__10->SetBinError(31,4.017466);
   pred_new__10->SetBinError(32,1.810689);
   pred_new__10->SetBinError(33,1.625886);
   pred_new__10->SetBinError(34,0.8774018);
   pred_new__10->SetBinError(35,0.4374665);
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
   TLatex *   tex = new TLatex(0.928,0.955,"#scale[0.85]{78.37 fb^{-1} (13 TeV)}");
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
