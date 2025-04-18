void mass_plot_region8fp9_2018_lowmass_2p12()
{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Feb 11 17:44:03 2025) by ROOT version 6.14/09
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
   pred_new__1->SetBinContent(1,14481.69);
   pred_new__1->SetBinContent(2,70564.73);
   pred_new__1->SetBinContent(3,102287.1);
   pred_new__1->SetBinContent(4,104869.9);
   pred_new__1->SetBinContent(5,85927.47);
   pred_new__1->SetBinContent(6,59627.48);
   pred_new__1->SetBinContent(7,41751.92);
   pred_new__1->SetBinContent(8,28784.48);
   pred_new__1->SetBinContent(9,19171.57);
   pred_new__1->SetBinContent(10,13083.11);
   pred_new__1->SetBinContent(11,8707.402);
   pred_new__1->SetBinContent(12,6033.939);
   pred_new__1->SetBinContent(13,4213.823);
   pred_new__1->SetBinContent(14,2818.985);
   pred_new__1->SetBinContent(15,2027.679);
   pred_new__1->SetBinContent(16,1466.461);
   pred_new__1->SetBinError(1,1327.806);
   pred_new__1->SetBinError(2,986.1065);
   pred_new__1->SetBinError(3,609.4954);
   pred_new__1->SetBinError(4,882.999);
   pred_new__1->SetBinError(5,2091.874);
   pred_new__1->SetBinError(6,1355.339);
   pred_new__1->SetBinError(7,785.6548);
   pred_new__1->SetBinError(8,1396.535);
   pred_new__1->SetBinError(9,977.8066);
   pred_new__1->SetBinError(10,371.2085);
   pred_new__1->SetBinError(11,450.6333);
   pred_new__1->SetBinError(12,415.6744);
   pred_new__1->SetBinError(13,347.2454);
   pred_new__1->SetBinError(14,190.8121);
   pred_new__1->SetBinError(15,109.4677);
   pred_new__1->SetBinError(16,130.6291);
   pred_new__1->SetBinError(17,1021.416);
   pred_new__1->SetBinError(18,760.8915);
   pred_new__1->SetBinError(19,578.5812);
   pred_new__1->SetBinError(20,585.2563);
   pred_new__1->SetBinError(21,400.829);
   pred_new__1->SetBinError(22,339.2204);
   pred_new__1->SetBinError(23,250.4472);
   pred_new__1->SetBinError(24,160.4703);
   pred_new__1->SetBinError(25,97.53664);
   pred_new__1->SetBinError(26,63.62972);
   pred_new__1->SetBinError(27,30.8291);
   pred_new__1->SetBinError(28,13.61627);
   pred_new__1->SetBinError(29,5.692301);
   pred_new__1->SetBinError(30,2.301607);
   pred_new__1->SetBinError(31,0.7521303);
   pred_new__1->SetBinError(32,0.2014345);
   pred_new__1->SetBinError(33,0.09015022);
   pred_new__1->SetBinError(34,0.01817313);
   pred_new__1->SetBinError(35,0.002879041);
   pred_new__1->SetMinimum(0.0001);
   pred_new__1->SetMaximum(5000000);
   pred_new__1->SetEntries(424);
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
   pred_noSyst_new__2->SetBinContent(1,14481.69);
   pred_noSyst_new__2->SetBinContent(2,70564.73);
   pred_noSyst_new__2->SetBinContent(3,102287.1);
   pred_noSyst_new__2->SetBinContent(4,104869.9);
   pred_noSyst_new__2->SetBinContent(5,85927.47);
   pred_noSyst_new__2->SetBinContent(6,59627.48);
   pred_noSyst_new__2->SetBinContent(7,41751.92);
   pred_noSyst_new__2->SetBinContent(8,28784.48);
   pred_noSyst_new__2->SetBinContent(9,19171.57);
   pred_noSyst_new__2->SetBinContent(10,13083.11);
   pred_noSyst_new__2->SetBinContent(11,8707.402);
   pred_noSyst_new__2->SetBinContent(12,6033.939);
   pred_noSyst_new__2->SetBinContent(13,4213.823);
   pred_noSyst_new__2->SetBinContent(14,2818.985);
   pred_noSyst_new__2->SetBinContent(15,2027.679);
   pred_noSyst_new__2->SetBinContent(16,1466.461);
   pred_noSyst_new__2->SetBinContent(17,1021.414);
   pred_noSyst_new__2->SetBinContent(18,760.8898);
   pred_noSyst_new__2->SetBinContent(19,578.5798);
   pred_noSyst_new__2->SetBinContent(20,585.2554);
   pred_noSyst_new__2->SetBinContent(21,400.8284);
   pred_noSyst_new__2->SetBinContent(22,339.22);
   pred_noSyst_new__2->SetBinContent(23,250.4469);
   pred_noSyst_new__2->SetBinContent(24,160.4702);
   pred_noSyst_new__2->SetBinContent(25,97.53656);
   pred_noSyst_new__2->SetBinContent(26,63.62968);
   pred_noSyst_new__2->SetBinContent(27,30.82908);
   pred_noSyst_new__2->SetBinContent(28,13.61626);
   pred_noSyst_new__2->SetBinContent(29,5.692298);
   pred_noSyst_new__2->SetBinContent(30,2.301605);
   pred_noSyst_new__2->SetBinContent(31,0.7521297);
   pred_noSyst_new__2->SetBinContent(32,0.2014343);
   pred_noSyst_new__2->SetBinContent(33,0.09015013);
   pred_noSyst_new__2->SetBinContent(34,0.01817311);
   pred_noSyst_new__2->SetBinContent(35,0.002879036);
   pred_noSyst_new__2->SetBinError(1,50.75885);
   pred_noSyst_new__2->SetBinError(2,123.1008);
   pred_noSyst_new__2->SetBinError(3,142.362);
   pred_noSyst_new__2->SetBinError(4,140.6066);
   pred_noSyst_new__2->SetBinError(5,115.0651);
   pred_noSyst_new__2->SetBinError(6,80.60192);
   pred_noSyst_new__2->SetBinError(7,58.79672);
   pred_noSyst_new__2->SetBinError(8,43.01077);
   pred_noSyst_new__2->SetBinError(9,30.22647);
   pred_noSyst_new__2->SetBinError(10,21.82951);
   pred_noSyst_new__2->SetBinError(11,15.48176);
   pred_noSyst_new__2->SetBinError(12,11.15932);
   pred_noSyst_new__2->SetBinError(13,8.150232);
   pred_noSyst_new__2->SetBinError(14,5.610776);
   pred_noSyst_new__2->SetBinError(15,4.158119);
   pred_noSyst_new__2->SetBinError(16,3.078835);
   pred_noSyst_new__2->SetBinError(17,2.187603);
   pred_noSyst_new__2->SetBinError(18,1.64321);
   pred_noSyst_new__2->SetBinError(19,1.247785);
   pred_noSyst_new__2->SetBinError(20,1.052601);
   pred_noSyst_new__2->SetBinError(21,0.7288132);
   pred_noSyst_new__2->SetBinError(22,0.5399683);
   pred_noSyst_new__2->SetBinError(23,0.3618955);
   pred_noSyst_new__2->SetBinError(24,0.2157289);
   pred_noSyst_new__2->SetBinError(25,0.1249224);
   pred_noSyst_new__2->SetBinError(26,0.07057568);
   pred_noSyst_new__2->SetBinError(27,0.03230239);
   pred_noSyst_new__2->SetBinError(28,0.01347443);
   pred_noSyst_new__2->SetBinError(29,0.005752845);
   pred_noSyst_new__2->SetBinError(30,0.002397275);
   pred_noSyst_new__2->SetBinError(31,0.0008834021);
   pred_noSyst_new__2->SetBinError(32,0.0003012681);
   pred_noSyst_new__2->SetBinError(33,0.0001337093);
   pred_noSyst_new__2->SetBinError(34,2.982711e-05);
   pred_noSyst_new__2->SetBinError(35,5.566847e-06);
   pred_noSyst_new__2->SetMinimum(0.0001);
   pred_noSyst_new__2->SetMaximum(5000000);
   pred_noSyst_new__2->SetEntries(405);
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
   pred_new__3->SetBinContent(1,14481.69);
   pred_new__3->SetBinContent(2,70564.73);
   pred_new__3->SetBinContent(3,102287.1);
   pred_new__3->SetBinContent(4,104869.9);
   pred_new__3->SetBinContent(5,85927.47);
   pred_new__3->SetBinContent(6,59627.48);
   pred_new__3->SetBinContent(7,41751.92);
   pred_new__3->SetBinContent(8,28784.48);
   pred_new__3->SetBinContent(9,19171.57);
   pred_new__3->SetBinContent(10,13083.11);
   pred_new__3->SetBinContent(11,8707.402);
   pred_new__3->SetBinContent(12,6033.939);
   pred_new__3->SetBinContent(13,4213.823);
   pred_new__3->SetBinContent(14,2818.985);
   pred_new__3->SetBinContent(15,2027.679);
   pred_new__3->SetBinContent(16,1466.461);
   pred_new__3->SetBinError(1,1327.806);
   pred_new__3->SetBinError(2,986.1065);
   pred_new__3->SetBinError(3,609.4954);
   pred_new__3->SetBinError(4,882.999);
   pred_new__3->SetBinError(5,2091.874);
   pred_new__3->SetBinError(6,1355.339);
   pred_new__3->SetBinError(7,785.6548);
   pred_new__3->SetBinError(8,1396.535);
   pred_new__3->SetBinError(9,977.8066);
   pred_new__3->SetBinError(10,371.2085);
   pred_new__3->SetBinError(11,450.6333);
   pred_new__3->SetBinError(12,415.6744);
   pred_new__3->SetBinError(13,347.2454);
   pred_new__3->SetBinError(14,190.8121);
   pred_new__3->SetBinError(15,109.4677);
   pred_new__3->SetBinError(16,130.6291);
   pred_new__3->SetBinError(17,1021.416);
   pred_new__3->SetBinError(18,760.8915);
   pred_new__3->SetBinError(19,578.5812);
   pred_new__3->SetBinError(20,585.2563);
   pred_new__3->SetBinError(21,400.829);
   pred_new__3->SetBinError(22,339.2204);
   pred_new__3->SetBinError(23,250.4472);
   pred_new__3->SetBinError(24,160.4703);
   pred_new__3->SetBinError(25,97.53664);
   pred_new__3->SetBinError(26,63.62972);
   pred_new__3->SetBinError(27,30.8291);
   pred_new__3->SetBinError(28,13.61627);
   pred_new__3->SetBinError(29,5.692301);
   pred_new__3->SetBinError(30,2.301607);
   pred_new__3->SetBinError(31,0.7521303);
   pred_new__3->SetBinError(32,0.2014345);
   pred_new__3->SetBinError(33,0.09015022);
   pred_new__3->SetBinError(34,0.01817313);
   pred_new__3->SetBinError(35,0.002879041);
   pred_new__3->SetEntries(424);
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
   obs_new__4->SetBinContent(1,19471);
   obs_new__4->SetBinContent(2,61677);
   obs_new__4->SetBinContent(3,99338);
   obs_new__4->SetBinContent(4,105327);
   obs_new__4->SetBinContent(5,85784);
   obs_new__4->SetBinContent(6,62467);
   obs_new__4->SetBinContent(7,44247);
   obs_new__4->SetBinContent(8,30349);
   obs_new__4->SetBinContent(9,20559);
   obs_new__4->SetBinContent(10,13632);
   obs_new__4->SetBinContent(11,9174);
   obs_new__4->SetBinContent(12,6308);
   obs_new__4->SetBinContent(13,4231);
   obs_new__4->SetBinContent(14,2950);
   obs_new__4->SetBinContent(15,2093);
   obs_new__4->SetBinContent(16,1515);
   obs_new__4->SetEntries(569122);
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
   Double_t xAxis5[36] = {0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000, 2500, 3200, 4000}; 
   
   TH1F *C_mass_new__5 = new TH1F("C_mass_new__5","",35, xAxis5);
   C_mass_new__5->SetBinContent(1,20350.26);
   C_mass_new__5->SetBinContent(2,65161.54);
   C_mass_new__5->SetBinContent(3,102979.1);
   C_mass_new__5->SetBinContent(4,106780.1);
   C_mass_new__5->SetBinContent(5,84692.09);
   C_mass_new__5->SetBinContent(6,60225.48);
   C_mass_new__5->SetBinContent(7,41474.88);
   C_mass_new__5->SetBinContent(8,28285.22);
   C_mass_new__5->SetBinContent(9,19064.69);
   C_mass_new__5->SetBinContent(10,12713.04);
   C_mass_new__5->SetBinContent(11,8498.754);
   C_mass_new__5->SetBinContent(12,5744.998);
   C_mass_new__5->SetBinContent(13,3931.246);
   C_mass_new__5->SetBinContent(14,2730.774);
   C_mass_new__5->SetBinContent(15,1933.841);
   C_mass_new__5->SetBinContent(16,1365.905);
   C_mass_new__5->SetBinContent(17,1014.542);
   C_mass_new__5->SetBinContent(18,727.5714);
   C_mass_new__5->SetBinContent(19,532.1168);
   C_mass_new__5->SetBinContent(20,561.7249);
   C_mass_new__5->SetBinContent(21,387.3893);
   C_mass_new__5->SetBinContent(22,319.4771);
   C_mass_new__5->SetBinContent(23,257.7764);
   C_mass_new__5->SetBinContent(24,163.9831);
   C_mass_new__5->SetBinContent(25,97.10615);
   C_mass_new__5->SetBinContent(26,66.87694);
   C_mass_new__5->SetBinContent(27,33.95609);
   C_mass_new__5->SetBinContent(28,18.22034);
   C_mass_new__5->SetBinContent(29,9.110171);
   C_mass_new__5->SetBinContent(30,3.933938);
   C_mass_new__5->SetBinContent(31,2.070493);
   C_mass_new__5->SetBinContent(32,0.4140987);
   C_mass_new__5->SetBinContent(33,1.242296);
   C_mass_new__5->SetBinError(1,64.91154);
   C_mass_new__5->SetBinError(2,116.1536);
   C_mass_new__5->SetBinError(3,146.0197);
   C_mass_new__5->SetBinError(4,148.6901);
   C_mass_new__5->SetBinError(5,132.4215);
   C_mass_new__5->SetBinError(6,111.6676);
   C_mass_new__5->SetBinError(7,92.66794);
   C_mass_new__5->SetBinError(8,76.52736);
   C_mass_new__5->SetBinError(9,62.82779);
   C_mass_new__5->SetBinError(10,51.30522);
   C_mass_new__5->SetBinError(11,41.94832);
   C_mass_new__5->SetBinError(12,34.4891);
   C_mass_new__5->SetBinError(13,28.53002);
   C_mass_new__5->SetBinError(14,23.77825);
   C_mass_new__5->SetBinError(15,20.01001);
   C_mass_new__5->SetBinError(16,16.81695);
   C_mass_new__5->SetBinError(17,14.49345);
   C_mass_new__5->SetBinError(18,12.27368);
   C_mass_new__5->SetBinError(19,10.4964);
   C_mass_new__5->SetBinError(20,10.78447);
   C_mass_new__5->SetBinError(21,8.955932);
   C_mass_new__5->SetBinError(22,8.133114);
   C_mass_new__5->SetBinError(23,7.305645);
   C_mass_new__5->SetBinError(24,5.826885);
   C_mass_new__5->SetBinError(25,4.483945);
   C_mass_new__5->SetBinError(26,3.721133);
   C_mass_new__5->SetBinError(27,2.651525);
   C_mass_new__5->SetBinError(28,1.942295);
   C_mass_new__5->SetBinError(29,1.37341);
   C_mass_new__5->SetBinError(30,0.9025072);
   C_mass_new__5->SetBinError(31,0.6547475);
   C_mass_new__5->SetBinError(32,0.292812);
   C_mass_new__5->SetBinError(33,0.5071653);
   C_mass_new__5->SetEntries(2753592);
   C_mass_new__5->SetLineColor(8);
   C_mass_new__5->SetMarkerColor(8);
   C_mass_new__5->SetMarkerStyle(23);
   C_mass_new__5->GetXaxis()->SetTitle("Mass [GeV]");
   C_mass_new__5->GetXaxis()->SetRange(1,400);
   C_mass_new__5->GetXaxis()->SetLabelFont(42);
   C_mass_new__5->GetXaxis()->SetLabelSize(0.035);
   C_mass_new__5->GetXaxis()->SetTitleSize(0.035);
   C_mass_new__5->GetXaxis()->SetTitleFont(42);
   C_mass_new__5->GetYaxis()->SetLabelFont(42);
   C_mass_new__5->GetYaxis()->SetLabelSize(0.035);
   C_mass_new__5->GetYaxis()->SetTitleSize(0.035);
   C_mass_new__5->GetYaxis()->SetTitleOffset(0);
   C_mass_new__5->GetYaxis()->SetTitleFont(42);
   C_mass_new__5->GetZaxis()->SetLabelFont(42);
   C_mass_new__5->GetZaxis()->SetLabelSize(0.035);
   C_mass_new__5->GetZaxis()->SetTitleSize(0.035);
   C_mass_new__5->GetZaxis()->SetTitleFont(42);
   C_mass_new__5->Draw("same E1");
   
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
   entry=leg->AddEntry("C_mass_new","Observed in C","PE1");
   entry->SetLineColor(8);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(8);
   entry->SetMarkerStyle(23);
   entry->SetMarkerSize(1);
   entry->SetTextFont(43);
   entry=leg->AddEntry("pred_new","Data-based pred.","PE");
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(2);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(43);
   leg->Draw();
   t1->Modified();
   c1->cd();
  
// ------------>Primitives in pad: t2
   TPad *t2 = new TPad("t2", "t2",0,0.3,0.95,0.45);
   t2->Draw();
   t2->cd();
   t2->Range(0,0,1,1);
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
   t2->Modified();
   c1->cd();
  
// ------------>Primitives in pad: t3
   TPad *t3 = new TPad("t3", "t3",0,0.25,0.95,0.45);
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
   
   TH1D *frameR2__6 = new TH1D("frameR2__6","",1,0,300);
   frameR2__6->SetMinimum(0);
   frameR2__6->SetMaximum(2);
   frameR2__6->SetStats(0);
   frameR2__6->SetLineStyle(0);
   frameR2__6->SetMarkerStyle(20);
   frameR2__6->GetXaxis()->SetNdivisions(505);
   frameR2__6->GetXaxis()->SetLabelFont(43);
   frameR2__6->GetXaxis()->SetLabelOffset(0.007);
   frameR2__6->GetXaxis()->SetLabelSize(20);
   frameR2__6->GetXaxis()->SetTitleSize(20);
   frameR2__6->GetXaxis()->SetTitleOffset(3.75);
   frameR2__6->GetXaxis()->SetTitleFont(43);
   frameR2__6->GetYaxis()->SetTitle("obs / pred");
   frameR2__6->GetYaxis()->SetNdivisions(503);
   frameR2__6->GetYaxis()->SetLabelFont(43);
   frameR2__6->GetYaxis()->SetLabelOffset(0.007);
   frameR2__6->GetYaxis()->SetLabelSize(12);
   frameR2__6->GetYaxis()->SetTitleSize(14);
   frameR2__6->GetYaxis()->SetTitleOffset(1.25);
   frameR2__6->GetYaxis()->SetTitleFont(43);
   frameR2__6->GetZaxis()->SetLabelFont(42);
   frameR2__6->GetZaxis()->SetLabelOffset(0.007);
   frameR2__6->GetZaxis()->SetLabelSize(0.05);
   frameR2__6->GetZaxis()->SetTitleSize(0.06);
   frameR2__6->GetZaxis()->SetTitleFont(42);
   frameR2__6->Draw("AXIS");
   Double_t xAxis6[36] = {0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000, 2500, 3200, 4000}; 
   
   TH1F *obs_new__7 = new TH1F("obs_new__7","",35, xAxis6);
   obs_new__7->SetBinContent(1,1.344525);
   obs_new__7->SetBinContent(2,0.8740485);
   obs_new__7->SetBinContent(3,0.9711682);
   obs_new__7->SetBinContent(4,1.004359);
   obs_new__7->SetBinContent(5,0.9983304);
   obs_new__7->SetBinContent(6,1.047621);
   obs_new__7->SetBinContent(7,1.05976);
   obs_new__7->SetBinContent(8,1.054353);
   obs_new__7->SetBinContent(9,1.072369);
   obs_new__7->SetBinContent(10,1.041954);
   obs_new__7->SetBinContent(11,1.053586);
   obs_new__7->SetBinContent(12,1.04542);
   obs_new__7->SetBinContent(13,1.004076);
   obs_new__7->SetBinContent(14,1.046476);
   obs_new__7->SetBinContent(15,1.032214);
   obs_new__7->SetBinContent(16,1.033099);
   obs_new__7->SetBinError(1,0.1236536);
   obs_new__7->SetBinError(2,0.01271132);
   obs_new__7->SetBinError(3,0.006556098);
   obs_new__7->SetBinError(4,0.009005119);
   obs_new__7->SetBinError(5,0.02454186);
   obs_new__7->SetBinError(6,0.02417863);
   obs_new__7->SetBinError(7,0.02056829);
   obs_new__7->SetBinError(8,0.05151073);
   obs_new__7->SetBinError(9,0.05520295);
   obs_new__7->SetBinError(10,0.03088108);
   obs_new__7->SetBinError(11,0.05562462);
   obs_new__7->SetBinError(12,0.07321132);
   obs_new__7->SetBinError(13,0.08416979);
   obs_new__7->SetBinError(14,0.07340774);
   obs_new__7->SetBinError(15,0.06012014);
   obs_new__7->SetBinError(16,0.09577737);
   obs_new__7->SetEntries(4835.96);
   
   TF1 *pol11 = new TF1("pol1","pol1",50,250, TF1::EAddToList::kNo);
   pol11->SetFillColor(19);
   pol11->SetFillStyle(0);
   pol11->SetMarkerStyle(20);
   pol11->SetLineColor(2);
   pol11->SetLineWidth(1);
   pol11->SetChisquare(10.05319);
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
   pol11->SetParameter(0,0.9454575);
   pol11->SetParError(0,0.01057064);
   pol11->SetParLimits(0,0,0);
   pol11->SetParameter(1,0.0006721004);
   pol11->SetParError(1,0.0001317725);
   pol11->SetParLimits(1,0,0);
   pol11->SetParent(obs_new__7);
   obs_new__7->GetListOfFunctions()->Add(pol11);
   obs_new__7->SetMarkerStyle(21);
   obs_new__7->SetMarkerSize(0.7);
   obs_new__7->GetXaxis()->SetTitle("Mass [GeV]");
   obs_new__7->GetXaxis()->SetRange(1,15);
   obs_new__7->GetXaxis()->SetLabelFont(42);
   obs_new__7->GetXaxis()->SetLabelSize(0.035);
   obs_new__7->GetXaxis()->SetTitleSize(0.035);
   obs_new__7->GetXaxis()->SetTitleFont(42);
   obs_new__7->GetYaxis()->SetLabelFont(42);
   obs_new__7->GetYaxis()->SetLabelSize(0.035);
   obs_new__7->GetYaxis()->SetTitleSize(0.035);
   obs_new__7->GetYaxis()->SetTitleOffset(0);
   obs_new__7->GetYaxis()->SetTitleFont(42);
   obs_new__7->GetZaxis()->SetLabelFont(42);
   obs_new__7->GetZaxis()->SetLabelSize(0.035);
   obs_new__7->GetZaxis()->SetTitleSize(0.035);
   obs_new__7->GetZaxis()->SetTitleFont(42);
   obs_new__7->Draw("same E0");
   Double_t xAxis7[36] = {0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000, 2500, 3200, 4000}; 
   
   TH1F *C_mass_new__8 = new TH1F("C_mass_new__8","",35, xAxis7);
   C_mass_new__8->SetBinContent(1,1.40524);
   C_mass_new__8->SetBinContent(2,0.9234292);
   C_mass_new__8->SetBinContent(3,1.006765);
   C_mass_new__8->SetBinContent(4,1.018215);
   C_mass_new__8->SetBinContent(5,0.9856229);
   C_mass_new__8->SetBinContent(6,1.010029);
   C_mass_new__8->SetBinContent(7,0.9933646);
   C_mass_new__8->SetBinContent(8,0.982655);
   C_mass_new__8->SetBinContent(9,0.9944249);
   C_mass_new__8->SetBinContent(10,0.971714);
   C_mass_new__8->SetBinContent(11,0.9760378);
   C_mass_new__8->SetBinContent(12,0.952114);
   C_mass_new__8->SetBinContent(13,0.9329405);
   C_mass_new__8->SetBinContent(14,0.9687083);
   C_mass_new__8->SetBinContent(15,0.9537212);
   C_mass_new__8->SetBinContent(16,0.931429);
   C_mass_new__8->SetBinError(1,0.1289224);
   C_mass_new__8->SetBinError(2,0.01300902);
   C_mass_new__8->SetBinError(3,0.006166497);
   C_mass_new__8->SetBinError(4,0.008689774);
   C_mass_new__8->SetBinError(5,0.02404408);
   C_mass_new__8->SetBinError(6,0.02303432);
   C_mass_new__8->SetBinError(7,0.01882366);
   C_mass_new__8->SetBinError(8,0.04774947);
   C_mass_new__8->SetBinError(9,0.05082436);
   C_mass_new__8->SetBinError(10,0.02784804);
   C_mass_new__8->SetBinError(11,0.05074199);
   C_mass_new__8->SetBinError(12,0.06583914);
   C_mass_new__8->SetBinError(13,0.07717771);
   C_mass_new__8->SetBinError(14,0.06611048);
   C_mass_new__8->SetBinError(15,0.05242543);
   C_mass_new__8->SetBinError(16,0.0837584);
   C_mass_new__8->SetEntries(5023.054);
   C_mass_new__8->SetLineColor(8);
   C_mass_new__8->SetMarkerColor(8);
   C_mass_new__8->SetMarkerStyle(23);
   C_mass_new__8->GetXaxis()->SetTitle("Mass [GeV]");
   C_mass_new__8->GetXaxis()->SetRange(1,400);
   C_mass_new__8->GetXaxis()->SetLabelFont(42);
   C_mass_new__8->GetXaxis()->SetLabelSize(0.035);
   C_mass_new__8->GetXaxis()->SetTitleSize(0.035);
   C_mass_new__8->GetXaxis()->SetTitleFont(42);
   C_mass_new__8->GetYaxis()->SetLabelFont(42);
   C_mass_new__8->GetYaxis()->SetLabelSize(0.035);
   C_mass_new__8->GetYaxis()->SetTitleSize(0.035);
   C_mass_new__8->GetYaxis()->SetTitleOffset(0);
   C_mass_new__8->GetYaxis()->SetTitleFont(42);
   C_mass_new__8->GetZaxis()->SetLabelFont(42);
   C_mass_new__8->GetZaxis()->SetLabelSize(0.035);
   C_mass_new__8->GetZaxis()->SetTitleSize(0.035);
   C_mass_new__8->GetZaxis()->SetTitleFont(42);
   C_mass_new__8->Draw("same E0");
   TLine *line = new TLine(0,1,300,1);
   line->SetLineStyle(3);
   line->Draw();
   t3->Modified();
   c1->cd();
  
// ------------>Primitives in pad: t4
   TPad *t4 = new TPad("t4", "t4",0,0,0.95,0.25);
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
   Double_t xAxis8[36] = {0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000, 2500, 3200, 4000}; 
   
   TH1F *pred_new__10 = new TH1F("pred_new__10","",35, xAxis8);
   pred_new__10->SetBinContent(1,3.74222);
   pred_new__10->SetBinContent(2,-8.70272);
   pred_new__10->SetBinContent(3,-4.284583);
   pred_new__10->SetBinContent(4,0.4860483);
   pred_new__10->SetBinContent(5,-0.06792022);
   pred_new__10->SetBinContent(6,2.061862);
   pred_new__10->SetBinContent(7,3.073545);
   pred_new__10->SetBinContent(8,1.112108);
   pred_new__10->SetBinContent(9,1.404901);
   pred_new__10->SetBinContent(10,1.413106);
   pred_new__10->SetBinContent(11,1.013917);
   pred_new__10->SetBinContent(12,0.6480962);
   pred_new__10->SetBinContent(13,0.04862482);
   pred_new__10->SetBinContent(14,0.6614894);
   pred_new__10->SetBinContent(15,0.5518456);
   pred_new__10->SetBinContent(16,0.3565714);
   pred_new__10->SetBinError(1,1327.806);
   pred_new__10->SetBinError(2,986.1065);
   pred_new__10->SetBinError(3,609.4954);
   pred_new__10->SetBinError(4,882.999);
   pred_new__10->SetBinError(5,2091.874);
   pred_new__10->SetBinError(6,1355.339);
   pred_new__10->SetBinError(7,785.6548);
   pred_new__10->SetBinError(8,1396.535);
   pred_new__10->SetBinError(9,977.8066);
   pred_new__10->SetBinError(10,371.2085);
   pred_new__10->SetBinError(11,450.6333);
   pred_new__10->SetBinError(12,415.6744);
   pred_new__10->SetBinError(13,347.2454);
   pred_new__10->SetBinError(14,190.8121);
   pred_new__10->SetBinError(15,109.4677);
   pred_new__10->SetBinError(16,130.6291);
   pred_new__10->SetBinError(17,1021.416);
   pred_new__10->SetBinError(18,760.8915);
   pred_new__10->SetBinError(19,578.5812);
   pred_new__10->SetBinError(20,585.2563);
   pred_new__10->SetBinError(21,400.829);
   pred_new__10->SetBinError(22,339.2204);
   pred_new__10->SetBinError(23,250.4472);
   pred_new__10->SetBinError(24,160.4703);
   pred_new__10->SetBinError(25,97.53664);
   pred_new__10->SetBinError(26,63.62972);
   pred_new__10->SetBinError(27,30.8291);
   pred_new__10->SetBinError(28,13.61627);
   pred_new__10->SetBinError(29,5.692301);
   pred_new__10->SetBinError(30,2.301607);
   pred_new__10->SetBinError(31,0.7521303);
   pred_new__10->SetBinError(32,0.2014345);
   pred_new__10->SetBinError(33,0.09015022);
   pred_new__10->SetBinError(34,0.01817313);
   pred_new__10->SetBinError(35,0.002879041);
   pred_new__10->SetEntries(459);
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
