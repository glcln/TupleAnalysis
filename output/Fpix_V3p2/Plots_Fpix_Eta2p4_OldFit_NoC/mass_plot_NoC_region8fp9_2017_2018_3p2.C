void mass_plot_NoC_region8fp9_2017_2018_3p2()
{
//=========Macro generated from canvas: c1/c1
//=========  (Tue May 13 17:00:03 2025) by ROOT version 6.14/09
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
   t1->Range(-780.4877,-4.053926,4097.561,6.731326);
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
   Double_t xAxis8[36] = {0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000, 2500, 3200, 4000}; 
   
   TH1F *pred_new__13 = new TH1F("pred_new__13","",35, xAxis8);
   pred_new__13->SetBinContent(1,285.08);
   pred_new__13->SetBinContent(2,1011.828);
   pred_new__13->SetBinContent(3,1085.037);
   pred_new__13->SetBinContent(4,946.3818);
   pred_new__13->SetBinContent(5,800.6967);
   pred_new__13->SetBinContent(6,648.949);
   pred_new__13->SetBinContent(7,525.7104);
   pred_new__13->SetBinContent(8,410.5093);
   pred_new__13->SetBinContent(9,317.0763);
   pred_new__13->SetBinContent(10,240.1106);
   pred_new__13->SetBinContent(11,179.2214);
   pred_new__13->SetBinContent(12,136.5643);
   pred_new__13->SetBinContent(13,103.5081);
   pred_new__13->SetBinContent(14,78.55718);
   pred_new__13->SetBinContent(15,61.44736);
   pred_new__13->SetBinContent(16,48.89095);
   pred_new__13->SetBinContent(17,37.51278);
   pred_new__13->SetBinContent(18,30.02579);
   pred_new__13->SetBinContent(19,24.55728);
   pred_new__13->SetBinContent(20,27.4422);
   pred_new__13->SetBinContent(21,20.90587);
   pred_new__13->SetBinContent(22,19.25668);
   pred_new__13->SetBinContent(23,16.09739);
   pred_new__13->SetBinContent(24,11.68606);
   pred_new__13->SetBinContent(25,7.987091);
   pred_new__13->SetBinContent(26,5.983708);
   pred_new__13->SetBinContent(27,3.255225);
   pred_new__13->SetBinContent(28,1.681751);
   pred_new__13->SetBinContent(29,0.7778785);
   pred_new__13->SetBinContent(30,0.343031);
   pred_new__13->SetBinContent(31,0.1226436);
   pred_new__13->SetBinContent(32,0.03279123);
   pred_new__13->SetBinContent(33,0.0148011);
   pred_new__13->SetBinContent(34,0.002851793);
   pred_new__13->SetBinContent(35,0.0004143591);
   pred_new__13->SetBinError(1,68.14957);
   pred_new__13->SetBinError(2,70.67284);
   pred_new__13->SetBinError(3,71.20291);
   pred_new__13->SetBinError(4,53.87778);
   pred_new__13->SetBinError(5,44.10456);
   pred_new__13->SetBinError(6,37.54731);
   pred_new__13->SetBinError(7,31.44529);
   pred_new__13->SetBinError(8,35.16882);
   pred_new__13->SetBinError(9,30.71986);
   pred_new__13->SetBinError(10,19.3963);
   pred_new__13->SetBinError(11,21.90072);
   pred_new__13->SetBinError(12,11.67573);
   pred_new__13->SetBinError(13,11.81584);
   pred_new__13->SetBinError(14,10.1797);
   pred_new__13->SetBinError(15,8.450735);
   pred_new__13->SetBinError(16,8.022641);
   pred_new__13->SetBinError(17,9.050644);
   pred_new__13->SetBinError(18,12.42898);
   pred_new__13->SetBinError(19,10.52533);
   pred_new__13->SetBinError(20,6.500303);
   pred_new__13->SetBinError(21,4.901629);
   pred_new__13->SetBinError(22,5.270727);
   pred_new__13->SetBinError(23,5.700704);
   pred_new__13->SetBinError(24,4.825003);
   pred_new__13->SetBinError(25,3.678833);
   pred_new__13->SetBinError(26,3.145234);
   pred_new__13->SetBinError(27,1.690965);
   pred_new__13->SetBinError(28,0.7634998);
   pred_new__13->SetBinError(29,0.4300075);
   pred_new__13->SetBinError(30,0.09008544);
   pred_new__13->SetBinError(31,0.03788741);
   pred_new__13->SetBinError(32,0.01796492);
   pred_new__13->SetBinError(33,0.009150524);
   pred_new__13->SetBinError(34,0.001708231);
   pred_new__13->SetBinError(35,0.0002424814);
   pred_new__13->SetMinimum(0.0001);
   pred_new__13->SetMaximum(5000000);
   pred_new__13->SetEntries(405);
   pred_new__13->SetFillColor(5);
   pred_new__13->SetLineColor(5);
   pred_new__13->SetMarkerColor(5);
   pred_new__13->SetMarkerStyle(22);
   pred_new__13->GetXaxis()->SetRange(1,35);
   pred_new__13->GetXaxis()->SetLabelFont(42);
   pred_new__13->GetXaxis()->SetLabelSize(0.035);
   pred_new__13->GetXaxis()->SetTitleSize(0.035);
   pred_new__13->GetXaxis()->SetTitleFont(42);
   pred_new__13->GetYaxis()->SetTitle("Events / bin");
   pred_new__13->GetYaxis()->SetLabelFont(43);
   pred_new__13->GetYaxis()->SetLabelSize(20);
   pred_new__13->GetYaxis()->SetTitleSize(20);
   pred_new__13->GetYaxis()->SetTitleOffset(2);
   pred_new__13->GetYaxis()->SetTitleFont(43);
   pred_new__13->GetZaxis()->SetLabelFont(42);
   pred_new__13->GetZaxis()->SetLabelSize(0.035);
   pred_new__13->GetZaxis()->SetTitleSize(0.035);
   pred_new__13->GetZaxis()->SetTitleFont(42);
   pred_new__13->Draw(" E5");
   Double_t xAxis9[36] = {0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000, 2500, 3200, 4000}; 
   
   TH1F *pred_noSyst_new__14 = new TH1F("pred_noSyst_new__14","",35, xAxis9);
   pred_noSyst_new__14->SetBinContent(1,285.08);
   pred_noSyst_new__14->SetBinContent(2,1011.828);
   pred_noSyst_new__14->SetBinContent(3,1085.037);
   pred_noSyst_new__14->SetBinContent(4,946.3818);
   pred_noSyst_new__14->SetBinContent(5,800.6967);
   pred_noSyst_new__14->SetBinContent(6,648.949);
   pred_noSyst_new__14->SetBinContent(7,525.7104);
   pred_noSyst_new__14->SetBinContent(8,410.5093);
   pred_noSyst_new__14->SetBinContent(9,317.0763);
   pred_noSyst_new__14->SetBinContent(10,240.1106);
   pred_noSyst_new__14->SetBinContent(11,179.2214);
   pred_noSyst_new__14->SetBinContent(12,136.5643);
   pred_noSyst_new__14->SetBinContent(13,103.5081);
   pred_noSyst_new__14->SetBinContent(14,78.55718);
   pred_noSyst_new__14->SetBinContent(15,61.44736);
   pred_noSyst_new__14->SetBinContent(16,48.89095);
   pred_noSyst_new__14->SetBinContent(17,37.51278);
   pred_noSyst_new__14->SetBinContent(18,30.02579);
   pred_noSyst_new__14->SetBinContent(19,24.55728);
   pred_noSyst_new__14->SetBinContent(20,27.4422);
   pred_noSyst_new__14->SetBinContent(21,20.90587);
   pred_noSyst_new__14->SetBinContent(22,19.25668);
   pred_noSyst_new__14->SetBinContent(23,16.09739);
   pred_noSyst_new__14->SetBinContent(24,11.68606);
   pred_noSyst_new__14->SetBinContent(25,7.987091);
   pred_noSyst_new__14->SetBinContent(26,5.983708);
   pred_noSyst_new__14->SetBinContent(27,3.255225);
   pred_noSyst_new__14->SetBinContent(28,1.681751);
   pred_noSyst_new__14->SetBinContent(29,0.7778785);
   pred_noSyst_new__14->SetBinContent(30,0.343031);
   pred_noSyst_new__14->SetBinContent(31,0.1226436);
   pred_noSyst_new__14->SetBinContent(32,0.03279123);
   pred_noSyst_new__14->SetBinContent(33,0.0148011);
   pred_noSyst_new__14->SetBinContent(34,0.002851793);
   pred_noSyst_new__14->SetBinContent(35,0.0004143591);
   pred_noSyst_new__14->SetBinError(1,22.64666);
   pred_noSyst_new__14->SetBinError(2,52.7533);
   pred_noSyst_new__14->SetBinError(3,52.32378);
   pred_noSyst_new__14->SetBinError(4,42.33313);
   pred_noSyst_new__14->SetBinError(5,34.96776);
   pred_noSyst_new__14->SetBinError(6,29.03682);
   pred_noSyst_new__14->SetBinError(7,24.85335);
   pred_noSyst_new__14->SetBinError(8,20.68024);
   pred_noSyst_new__14->SetBinError(9,16.63722);
   pred_noSyst_new__14->SetBinError(10,12.81988);
   pred_noSyst_new__14->SetBinError(11,9.646389);
   pred_noSyst_new__14->SetBinError(12,7.386103);
   pred_noSyst_new__14->SetBinError(13,5.598314);
   pred_noSyst_new__14->SetBinError(14,4.235463);
   pred_noSyst_new__14->SetBinError(15,3.323356);
   pred_noSyst_new__14->SetBinError(16,2.651122);
   pred_noSyst_new__14->SetBinError(17,2.026409);
   pred_noSyst_new__14->SetBinError(18,1.625894);
   pred_noSyst_new__14->SetBinError(19,1.337185);
   pred_noSyst_new__14->SetBinError(20,1.219135);
   pred_noSyst_new__14->SetBinError(21,0.9302064);
   pred_noSyst_new__14->SetBinError(22,0.7483449);
   pred_noSyst_new__14->SetBinError(23,0.5568854);
   pred_noSyst_new__14->SetBinError(24,0.3714898);
   pred_noSyst_new__14->SetBinError(25,0.236458);
   pred_noSyst_new__14->SetBinError(26,0.1506758);
   pred_noSyst_new__14->SetBinError(27,0.07590231);
   pred_noSyst_new__14->SetBinError(28,0.03590238);
   pred_noSyst_new__14->SetBinError(29,0.01569876);
   pred_noSyst_new__14->SetBinError(30,0.006470007);
   pred_noSyst_new__14->SetBinError(31,0.002160403);
   pred_noSyst_new__14->SetBinError(32,0.0005988297);
   pred_noSyst_new__14->SetBinError(33,0.0002215873);
   pred_noSyst_new__14->SetBinError(34,4.427121e-05);
   pred_noSyst_new__14->SetBinError(35,6.334311e-06);
   pred_noSyst_new__14->SetMinimum(0.0001);
   pred_noSyst_new__14->SetMaximum(5000000);
   pred_noSyst_new__14->SetEntries(405);
   pred_noSyst_new__14->SetFillColor(5);
   pred_noSyst_new__14->SetLineColor(5);
   pred_noSyst_new__14->SetMarkerColor(5);
   pred_noSyst_new__14->SetMarkerStyle(22);
   pred_noSyst_new__14->SetMarkerSize(0.1);
   pred_noSyst_new__14->GetXaxis()->SetRange(1,35);
   pred_noSyst_new__14->GetXaxis()->SetLabelFont(42);
   pred_noSyst_new__14->GetXaxis()->SetLabelSize(0.035);
   pred_noSyst_new__14->GetXaxis()->SetTitleSize(0.035);
   pred_noSyst_new__14->GetXaxis()->SetTitleFont(42);
   pred_noSyst_new__14->GetYaxis()->SetTitle("Events / bin");
   pred_noSyst_new__14->GetYaxis()->SetLabelFont(43);
   pred_noSyst_new__14->GetYaxis()->SetLabelSize(20);
   pred_noSyst_new__14->GetYaxis()->SetTitleSize(20);
   pred_noSyst_new__14->GetYaxis()->SetTitleOffset(7);
   pred_noSyst_new__14->GetYaxis()->SetTitleFont(43);
   pred_noSyst_new__14->GetZaxis()->SetLabelFont(42);
   pred_noSyst_new__14->GetZaxis()->SetLabelSize(0.035);
   pred_noSyst_new__14->GetZaxis()->SetTitleSize(0.035);
   pred_noSyst_new__14->GetZaxis()->SetTitleFont(42);
   pred_noSyst_new__14->Draw("same E5");
   Double_t xAxis10[36] = {0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000, 2500, 3200, 4000}; 
   
   TH1F *pred_new__15 = new TH1F("pred_new__15","",35, xAxis10);
   pred_new__15->SetBinContent(1,285.08);
   pred_new__15->SetBinContent(2,1011.828);
   pred_new__15->SetBinContent(3,1085.037);
   pred_new__15->SetBinContent(4,946.3818);
   pred_new__15->SetBinContent(5,800.6967);
   pred_new__15->SetBinContent(6,648.949);
   pred_new__15->SetBinContent(7,525.7104);
   pred_new__15->SetBinContent(8,410.5093);
   pred_new__15->SetBinContent(9,317.0763);
   pred_new__15->SetBinContent(10,240.1106);
   pred_new__15->SetBinContent(11,179.2214);
   pred_new__15->SetBinContent(12,136.5643);
   pred_new__15->SetBinContent(13,103.5081);
   pred_new__15->SetBinContent(14,78.55718);
   pred_new__15->SetBinContent(15,61.44736);
   pred_new__15->SetBinContent(16,48.89095);
   pred_new__15->SetBinContent(17,37.51278);
   pred_new__15->SetBinContent(18,30.02579);
   pred_new__15->SetBinContent(19,24.55728);
   pred_new__15->SetBinContent(20,27.4422);
   pred_new__15->SetBinContent(21,20.90587);
   pred_new__15->SetBinContent(22,19.25668);
   pred_new__15->SetBinContent(23,16.09739);
   pred_new__15->SetBinContent(24,11.68606);
   pred_new__15->SetBinContent(25,7.987091);
   pred_new__15->SetBinContent(26,5.983708);
   pred_new__15->SetBinContent(27,3.255225);
   pred_new__15->SetBinContent(28,1.681751);
   pred_new__15->SetBinContent(29,0.7778785);
   pred_new__15->SetBinContent(30,0.343031);
   pred_new__15->SetBinContent(31,0.1226436);
   pred_new__15->SetBinContent(32,0.03279123);
   pred_new__15->SetBinContent(33,0.0148011);
   pred_new__15->SetBinContent(34,0.002851793);
   pred_new__15->SetBinContent(35,0.0004143591);
   pred_new__15->SetBinError(1,68.14957);
   pred_new__15->SetBinError(2,70.67284);
   pred_new__15->SetBinError(3,71.20291);
   pred_new__15->SetBinError(4,53.87778);
   pred_new__15->SetBinError(5,44.10456);
   pred_new__15->SetBinError(6,37.54731);
   pred_new__15->SetBinError(7,31.44529);
   pred_new__15->SetBinError(8,35.16882);
   pred_new__15->SetBinError(9,30.71986);
   pred_new__15->SetBinError(10,19.3963);
   pred_new__15->SetBinError(11,21.90072);
   pred_new__15->SetBinError(12,11.67573);
   pred_new__15->SetBinError(13,11.81584);
   pred_new__15->SetBinError(14,10.1797);
   pred_new__15->SetBinError(15,8.450735);
   pred_new__15->SetBinError(16,8.022641);
   pred_new__15->SetBinError(17,9.050644);
   pred_new__15->SetBinError(18,12.42898);
   pred_new__15->SetBinError(19,10.52533);
   pred_new__15->SetBinError(20,6.500303);
   pred_new__15->SetBinError(21,4.901629);
   pred_new__15->SetBinError(22,5.270727);
   pred_new__15->SetBinError(23,5.700704);
   pred_new__15->SetBinError(24,4.825003);
   pred_new__15->SetBinError(25,3.678833);
   pred_new__15->SetBinError(26,3.145234);
   pred_new__15->SetBinError(27,1.690965);
   pred_new__15->SetBinError(28,0.7634998);
   pred_new__15->SetBinError(29,0.4300075);
   pred_new__15->SetBinError(30,0.09008544);
   pred_new__15->SetBinError(31,0.03788741);
   pred_new__15->SetBinError(32,0.01796492);
   pred_new__15->SetBinError(33,0.009150524);
   pred_new__15->SetBinError(34,0.001708231);
   pred_new__15->SetBinError(35,0.0002424814);
   pred_new__15->SetEntries(405);
   pred_new__15->SetLineColor(2);
   pred_new__15->SetMarkerColor(2);
   pred_new__15->SetMarkerStyle(21);
   pred_new__15->GetXaxis()->SetTitle("Mass [GeV]");
   pred_new__15->GetXaxis()->SetRange(1,400);
   pred_new__15->GetXaxis()->SetLabelFont(42);
   pred_new__15->GetXaxis()->SetLabelSize(0.035);
   pred_new__15->GetXaxis()->SetTitleSize(0.035);
   pred_new__15->GetXaxis()->SetTitleFont(42);
   pred_new__15->GetYaxis()->SetLabelFont(42);
   pred_new__15->GetYaxis()->SetLabelSize(0.035);
   pred_new__15->GetYaxis()->SetTitleSize(0.035);
   pred_new__15->GetYaxis()->SetTitleOffset(0);
   pred_new__15->GetYaxis()->SetTitleFont(42);
   pred_new__15->GetZaxis()->SetLabelFont(42);
   pred_new__15->GetZaxis()->SetLabelSize(0.035);
   pred_new__15->GetZaxis()->SetTitleSize(0.035);
   pred_new__15->GetZaxis()->SetTitleFont(42);
   pred_new__15->Draw("same HIST P");
   Double_t xAxis11[36] = {0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000, 2500, 3200, 4000}; 
   
   TH1F *obs_new__16 = new TH1F("obs_new__16","",35, xAxis11);
   obs_new__16->SetBinContent(1,358);
   obs_new__16->SetBinContent(2,896);
   obs_new__16->SetBinContent(3,1037);
   obs_new__16->SetBinContent(4,949);
   obs_new__16->SetBinContent(5,802);
   obs_new__16->SetBinContent(6,579);
   obs_new__16->SetBinContent(7,513);
   obs_new__16->SetBinContent(8,435);
   obs_new__16->SetBinContent(9,331);
   obs_new__16->SetBinContent(10,291);
   obs_new__16->SetBinContent(11,260);
   obs_new__16->SetBinContent(12,207);
   obs_new__16->SetBinContent(13,148);
   obs_new__16->SetBinContent(14,124);
   obs_new__16->SetBinContent(15,112);
   obs_new__16->SetBinContent(16,99);
   obs_new__16->SetBinContent(17,87);
   obs_new__16->SetBinContent(18,63);
   obs_new__16->SetBinContent(19,56);
   obs_new__16->SetBinContent(20,66);
   obs_new__16->SetBinContent(21,54);
   obs_new__16->SetBinContent(22,52);
   obs_new__16->SetBinContent(23,65);
   obs_new__16->SetBinContent(24,34);
   obs_new__16->SetBinContent(25,22);
   obs_new__16->SetBinContent(26,23);
   obs_new__16->SetBinContent(27,6);
   obs_new__16->SetBinContent(28,7);
   obs_new__16->SetBinContent(29,4);
   obs_new__16->SetEntries(7680);
   obs_new__16->SetMarkerStyle(20);
   obs_new__16->GetXaxis()->SetTitle("Mass [GeV]");
   obs_new__16->GetXaxis()->SetRange(1,35);
   obs_new__16->GetXaxis()->SetLabelFont(42);
   obs_new__16->GetXaxis()->SetLabelSize(0.035);
   obs_new__16->GetXaxis()->SetTitleSize(0.035);
   obs_new__16->GetXaxis()->SetTitleFont(42);
   obs_new__16->GetYaxis()->SetLabelFont(42);
   obs_new__16->GetYaxis()->SetLabelSize(0.035);
   obs_new__16->GetYaxis()->SetTitleSize(0.035);
   obs_new__16->GetYaxis()->SetTitleOffset(0);
   obs_new__16->GetYaxis()->SetTitleFont(42);
   obs_new__16->GetZaxis()->SetLabelFont(42);
   obs_new__16->GetZaxis()->SetLabelSize(0.035);
   obs_new__16->GetZaxis()->SetTitleSize(0.035);
   obs_new__16->GetZaxis()->SetTitleFont(42);
   obs_new__16->Draw("same E1");
   
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
   entry=leg->AddEntry("pred_new","Data-based pred.","PF");
   entry->SetFillColor(5);
   entry->SetFillStyle(1001);
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
   t2->Range(-780.4877,-0.04545454,4097.561,2.227273);
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
   
   TH1D *frameR__17 = new TH1D("frameR__17","",1,0,4000);
   frameR__17->SetMinimum(0);
   frameR__17->SetMaximum(2);
   frameR__17->SetStats(0);
   frameR__17->SetLineStyle(0);
   frameR__17->SetMarkerStyle(20);
   frameR__17->GetXaxis()->SetNdivisions(505);
   frameR__17->GetXaxis()->SetLabelFont(43);
   frameR__17->GetXaxis()->SetLabelOffset(0.007);
   frameR__17->GetXaxis()->SetLabelSize(20);
   frameR__17->GetXaxis()->SetTitleSize(20);
   frameR__17->GetXaxis()->SetTitleOffset(3.75);
   frameR__17->GetXaxis()->SetTitleFont(43);
   frameR__17->GetYaxis()->SetTitle("RatioR     ");
   frameR__17->GetYaxis()->SetNdivisions(503);
   frameR__17->GetYaxis()->SetLabelFont(43);
   frameR__17->GetYaxis()->SetLabelOffset(0.007);
   frameR__17->GetYaxis()->SetLabelSize(12);
   frameR__17->GetYaxis()->SetTitleSize(14);
   frameR__17->GetYaxis()->SetTitleOffset(1.25);
   frameR__17->GetYaxis()->SetTitleFont(43);
   frameR__17->GetZaxis()->SetLabelFont(42);
   frameR__17->GetZaxis()->SetLabelOffset(0.007);
   frameR__17->GetZaxis()->SetLabelSize(0.05);
   frameR__17->GetZaxis()->SetTitleSize(0.06);
   frameR__17->GetZaxis()->SetTitleFont(42);
   frameR__17->Draw("AXIS");
   Double_t xAxis12[36] = {0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000, 2500, 3200, 4000}; 
   
   TH1F *pred_new__18 = new TH1F("pred_new__18","",35, xAxis12);
   pred_new__18->SetBinContent(0,1.083635);
   pred_new__18->SetBinContent(1,1.083635);
   pred_new__18->SetBinContent(2,1.076421);
   pred_new__18->SetBinContent(3,1.109778);
   pred_new__18->SetBinContent(4,1.145302);
   pred_new__18->SetBinContent(5,1.181188);
   pred_new__18->SetBinContent(6,1.229789);
   pred_new__18->SetBinContent(7,1.324654);
   pred_new__18->SetBinContent(8,1.427473);
   pred_new__18->SetBinContent(9,1.537439);
   pred_new__18->SetBinContent(10,1.685628);
   pred_new__18->SetBinContent(11,1.825033);
   pred_new__18->SetBinContent(12,1.930405);
   pred_new__18->SetBinContent(13,2.043633);
   pred_new__18->SetBinContent(14,2.203833);
   pred_new__18->SetBinContent(15,2.358309);
   pred_new__18->SetBinContent(16,2.486581);
   pred_new__18->SetBinContent(17,2.595261);
   pred_new__18->SetBinContent(18,2.656114);
   pred_new__18->SetBinContent(19,2.775644);
   pred_new__18->SetBinContent(20,2.880862);
   pred_new__18->SetBinContent(21,3.02899);
   pred_new__18->SetBinContent(22,3.167648);
   pred_new__18->SetBinContent(23,3.355171);
   pred_new__18->SetBinContent(24,3.010514);
   pred_new__18->SetBinContent(25,3.068975);
   pred_new__18->SetBinContent(26,3.274637);
   pred_new__18->SetBinContent(27,2.728124);
   pred_new__18->SetBinContent(28,3.696034);
   pred_new__18->SetBinContent(29,3.090207);
   pred_new__18->SetBinError(0,0.02759464);
   pred_new__18->SetBinError(1,0.02759464);
   pred_new__18->SetBinError(2,0.02634043);
   pred_new__18->SetBinError(3,0.02817461);
   pred_new__18->SetBinError(4,0.03023614);
   pred_new__18->SetBinError(5,0.03384707);
   pred_new__18->SetBinError(6,0.03917446);
   pred_new__18->SetBinError(7,0.04732968);
   pred_new__18->SetBinError(8,0.05840487);
   pred_new__18->SetBinError(9,0.06840418);
   pred_new__18->SetBinError(10,0.08015929);
   pred_new__18->SetBinError(11,0.09918604);
   pred_new__18->SetBinError(12,0.1121972);
   pred_new__18->SetBinError(13,0.1384486);
   pred_new__18->SetBinError(14,0.1706875);
   pred_new__18->SetBinError(15,0.2090471);
   pred_new__18->SetBinError(16,0.254871);
   pred_new__18->SetBinError(17,0.3071349);
   pred_new__18->SetBinError(18,0.3511803);
   pred_new__18->SetBinError(19,0.3642084);
   pred_new__18->SetBinError(20,0.3671612);
   pred_new__18->SetBinError(21,0.4397192);
   pred_new__18->SetBinError(22,0.5409227);
   pred_new__18->SetBinError(23,0.6891468);
   pred_new__18->SetBinError(24,0.7369678);
   pred_new__18->SetBinError(25,0.8811764);
   pred_new__18->SetBinError(26,1.113743);
   pred_new__18->SetBinError(27,1.065338);
   pred_new__18->SetBinError(28,1.562514);
   pred_new__18->SetBinError(29,1.870287);
   pred_new__18->SetEntries(36);
   pred_new__18->SetMarkerStyle(21);
   pred_new__18->SetMarkerSize(0.7);
   pred_new__18->GetXaxis()->SetTitle("Mass [GeV]");
   pred_new__18->GetXaxis()->SetRange(1,35);
   pred_new__18->GetXaxis()->SetLabelFont(42);
   pred_new__18->GetXaxis()->SetLabelSize(0.035);
   pred_new__18->GetXaxis()->SetTitleSize(0.035);
   pred_new__18->GetXaxis()->SetTitleFont(42);
   pred_new__18->GetYaxis()->SetLabelFont(42);
   pred_new__18->GetYaxis()->SetLabelSize(0.035);
   pred_new__18->GetYaxis()->SetTitleSize(0.035);
   pred_new__18->GetYaxis()->SetTitleOffset(0);
   pred_new__18->GetYaxis()->SetTitleFont(42);
   pred_new__18->GetZaxis()->SetLabelFont(42);
   pred_new__18->GetZaxis()->SetLabelSize(0.035);
   pred_new__18->GetZaxis()->SetTitleSize(0.035);
   pred_new__18->GetZaxis()->SetTitleFont(42);
   pred_new__18->Draw("same E0");
   TLine *line = new TLine(0,1,4000,1);
   line->SetLineStyle(3);
   line->Draw();
   t2->Modified();
   c1->cd();
  
// ------------>Primitives in pad: t3
   TPad *t3 = new TPad("t3", "t3",0,0.15,0.95,0.3);
   t3->Draw();
   t3->cd();
   t3->Range(-780.4877,-0.04545454,4097.561,2.227273);
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
   
   TH1D *frameR2__19 = new TH1D("frameR2__19","",1,0,4000);
   frameR2__19->SetMinimum(0);
   frameR2__19->SetMaximum(2);
   frameR2__19->SetStats(0);
   frameR2__19->SetLineStyle(0);
   frameR2__19->SetMarkerStyle(20);
   frameR2__19->GetXaxis()->SetNdivisions(505);
   frameR2__19->GetXaxis()->SetLabelFont(43);
   frameR2__19->GetXaxis()->SetLabelOffset(0.007);
   frameR2__19->GetXaxis()->SetLabelSize(20);
   frameR2__19->GetXaxis()->SetTitleSize(20);
   frameR2__19->GetXaxis()->SetTitleOffset(3.75);
   frameR2__19->GetXaxis()->SetTitleFont(43);
   frameR2__19->GetYaxis()->SetTitle("obs / pred");
   frameR2__19->GetYaxis()->SetNdivisions(503);
   frameR2__19->GetYaxis()->SetLabelFont(43);
   frameR2__19->GetYaxis()->SetLabelOffset(0.007);
   frameR2__19->GetYaxis()->SetLabelSize(12);
   frameR2__19->GetYaxis()->SetTitleSize(14);
   frameR2__19->GetYaxis()->SetTitleOffset(1.25);
   frameR2__19->GetYaxis()->SetTitleFont(43);
   frameR2__19->GetZaxis()->SetLabelFont(42);
   frameR2__19->GetZaxis()->SetLabelOffset(0.007);
   frameR2__19->GetZaxis()->SetLabelSize(0.05);
   frameR2__19->GetZaxis()->SetTitleSize(0.06);
   frameR2__19->GetZaxis()->SetTitleFont(42);
   frameR2__19->Draw("AXIS");
   Double_t xAxis13[36] = {0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000, 2500, 3200, 4000}; 
   
   TH1F *obs_new__20 = new TH1F("obs_new__20","",35, xAxis13);
   obs_new__20->SetBinContent(1,1.255788);
   obs_new__20->SetBinContent(2,0.8855262);
   obs_new__20->SetBinContent(3,0.9557279);
   obs_new__20->SetBinContent(4,1.002766);
   obs_new__20->SetBinContent(5,1.001628);
   obs_new__20->SetBinContent(6,0.8922119);
   obs_new__20->SetBinContent(7,0.9758223);
   obs_new__20->SetBinContent(8,1.059659);
   obs_new__20->SetBinContent(9,1.043913);
   obs_new__20->SetBinContent(10,1.211941);
   obs_new__20->SetBinContent(11,1.450719);
   obs_new__20->SetBinContent(12,1.51577);
   obs_new__20->SetBinContent(13,1.429839);
   obs_new__20->SetBinContent(14,1.578468);
   obs_new__20->SetBinContent(15,1.822698);
   obs_new__20->SetBinContent(16,2.024915);
   obs_new__20->SetBinContent(17,2.319209);
   obs_new__20->SetBinContent(18,2.098197);
   obs_new__20->SetBinContent(19,2.280383);
   obs_new__20->SetBinContent(20,2.405055);
   obs_new__20->SetBinContent(21,2.583007);
   obs_new__20->SetBinContent(22,2.700361);
   obs_new__20->SetBinContent(23,4.037921);
   obs_new__20->SetBinContent(24,2.90945);
   obs_new__20->SetBinContent(25,2.754445);
   obs_new__20->SetBinContent(26,3.84377);
   obs_new__20->SetBinContent(27,1.84319);
   obs_new__20->SetBinContent(28,4.162328);
   obs_new__20->SetBinContent(29,5.142191);
   obs_new__20->SetBinError(1,0.3074505);
   obs_new__20->SetBinError(2,0.0685619);
   obs_new__20->SetBinError(3,0.06938507);
   obs_new__20->SetBinError(4,0.06571601);
   obs_new__20->SetBinError(5,0.06553578);
   obs_new__20->SetBinError(6,0.06355868);
   obs_new__20->SetBinError(7,0.07254721);
   obs_new__20->SetBinError(8,0.1040324);
   obs_new__20->SetBinError(9,0.1162818);
   obs_new__20->SetBinError(10,0.1209634);
   obs_new__20->SetBinError(11,0.1988004);
   obs_new__20->SetBinError(12,0.1670136);
   obs_new__20->SetBinError(13,0.2011344);
   obs_new__20->SetBinError(14,0.2488597);
   obs_new__20->SetBinError(15,0.304137);
   obs_new__20->SetBinError(16,0.3896442);
   obs_new__20->SetBinError(17,0.6123092);
   obs_new__20->SetBinError(18,0.9078728);
   obs_new__20->SetBinError(19,1.023782);
   obs_new__20->SetBinError(20,0.6420194);
   obs_new__20->SetBinError(21,0.7002327);
   obs_new__20->SetBinError(22,0.8285638);
   obs_new__20->SetBinError(23,1.515155);
   obs_new__20->SetBinError(24,1.300776);
   obs_new__20->SetBinError(25,1.398012);
   obs_new__20->SetBinError(26,2.173577);
   obs_new__20->SetBinError(27,1.217772);
   obs_new__20->SetBinError(28,2.458823);
   obs_new__20->SetBinError(29,3.832856);
   obs_new__20->SetEntries(93.92284);
   obs_new__20->SetMarkerStyle(21);
   obs_new__20->SetMarkerSize(0.7);
   obs_new__20->GetXaxis()->SetTitle("Mass [GeV]");
   obs_new__20->GetXaxis()->SetRange(1,35);
   obs_new__20->GetXaxis()->SetLabelFont(42);
   obs_new__20->GetXaxis()->SetLabelSize(0.035);
   obs_new__20->GetXaxis()->SetTitleSize(0.035);
   obs_new__20->GetXaxis()->SetTitleFont(42);
   obs_new__20->GetYaxis()->SetLabelFont(42);
   obs_new__20->GetYaxis()->SetLabelSize(0.035);
   obs_new__20->GetYaxis()->SetTitleSize(0.035);
   obs_new__20->GetYaxis()->SetTitleOffset(0);
   obs_new__20->GetYaxis()->SetTitleFont(42);
   obs_new__20->GetZaxis()->SetLabelFont(42);
   obs_new__20->GetZaxis()->SetLabelSize(0.035);
   obs_new__20->GetZaxis()->SetTitleSize(0.035);
   obs_new__20->GetZaxis()->SetTitleFont(42);
   obs_new__20->Draw("same E0");
   line = new TLine(0,1,4000,1);
   line->SetLineStyle(3);
   line->Draw();
   t3->Modified();
   c1->cd();
  
// ------------>Primitives in pad: t4
   TPad *t4 = new TPad("t4", "t4",0,0,0.95,0.15);
   t4->Draw();
   t4->cd();
   t4->Range(-780.4877,-6,4097.561,4);
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
   
   TH1D *frameR3__21 = new TH1D("frameR3__21","",1,0,4000);
   frameR3__21->SetMinimum(-3);
   frameR3__21->SetMaximum(3);
   frameR3__21->SetStats(0);
   frameR3__21->SetLineStyle(0);
   frameR3__21->SetMarkerStyle(20);
   frameR3__21->GetXaxis()->SetTitle("Mass (GeV)");
   frameR3__21->GetXaxis()->SetLabelFont(43);
   frameR3__21->GetXaxis()->SetLabelOffset(0.007);
   frameR3__21->GetXaxis()->SetLabelSize(14);
   frameR3__21->GetXaxis()->SetTitleSize(20);
   frameR3__21->GetXaxis()->SetTitleOffset(3.75);
   frameR3__21->GetXaxis()->SetTitleFont(43);
   frameR3__21->GetYaxis()->SetTitle("#frac{Data-pred}{#sigma}");
   frameR3__21->GetYaxis()->SetNdivisions(503);
   frameR3__21->GetYaxis()->SetLabelFont(43);
   frameR3__21->GetYaxis()->SetLabelOffset(0.007);
   frameR3__21->GetYaxis()->SetLabelSize(12);
   frameR3__21->GetYaxis()->SetTitleSize(16);
   frameR3__21->GetYaxis()->SetTickLength(0.06);
   frameR3__21->GetYaxis()->SetTitleOffset(1.25);
   frameR3__21->GetYaxis()->SetTitleFont(43);
   frameR3__21->GetZaxis()->SetLabelFont(42);
   frameR3__21->GetZaxis()->SetLabelOffset(0.007);
   frameR3__21->GetZaxis()->SetLabelSize(0.05);
   frameR3__21->GetZaxis()->SetTitleSize(0.06);
   frameR3__21->GetZaxis()->SetTitleFont(42);
   frameR3__21->Draw("AXIS");
   Double_t xAxis14[36] = {0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000, 2500, 3200, 4000}; 
   
   TH1F *pred_new__22 = new TH1F("pred_new__22","",35, xAxis14);
   pred_new__22->SetBinContent(1,1.038598);
   pred_new__22->SetBinContent(2,-1.494522);
   pred_new__22->SetBinContent(3,-0.6123003);
   pred_new__22->SetBinContent(4,0.04219994);
   pred_new__22->SetBinContent(5,0.02487232);
   pred_new__22->SetBinContent(6,-1.541628);
   pred_new__22->SetBinContent(7,-0.3266058);
   pred_new__22->SetBinContent(8,0.6034022);
   pred_new__22->SetBinContent(9,0.3921337);
   pred_new__22->SetBinContent(10,2.049848);
   pred_new__22->SetBinContent(11,3.147014);
   pred_new__22->SetBinContent(12,4.263847);
   pred_new__22->SetBinContent(13,2.853437);
   pred_new__22->SetBinContent(14,3.366749);
   pred_new__22->SetBinContent(15,4.385741);
   pred_new__22->SetBinContent(16,4.70858);
   pred_new__22->SetBinContent(17,4.528369);
   pred_new__22->SetBinContent(18,2.42756);
   pred_new__22->SetBinContent(19,2.70276);
   pred_new__22->SetBinContent(20,4.618573);
   pred_new__22->SetBinContent(21,4.937123);
   pred_new__22->SetBinContent(22,4.774212);
   pred_new__22->SetBinContent(23,7.015109);
   pred_new__22->SetBinContent(24,3.77354);
   pred_new__22->SetBinContent(25,3.020633);
   pred_new__22->SetBinContent(26,4.270626);
   pred_new__22->SetBinContent(27,1.11);
   pred_new__22->SetBinContent(28,3.533987);
   pred_new__22->SetBinContent(29,3.283804);
   pred_new__22->SetBinContent(30,-0.5788809);
   pred_new__22->SetBinContent(31,-0.3481735);
   pred_new__22->SetBinContent(32,-0.1801989);
   pred_new__22->SetBinContent(33,-0.1213171);
   pred_new__22->SetBinContent(34,-0.05337488);
   pred_new__22->SetBinContent(35,-0.02035437);
   pred_new__22->SetBinError(1,68.14957);
   pred_new__22->SetBinError(2,70.67284);
   pred_new__22->SetBinError(3,71.20291);
   pred_new__22->SetBinError(4,53.87778);
   pred_new__22->SetBinError(5,44.10456);
   pred_new__22->SetBinError(6,37.54731);
   pred_new__22->SetBinError(7,31.44529);
   pred_new__22->SetBinError(8,35.16882);
   pred_new__22->SetBinError(9,30.71986);
   pred_new__22->SetBinError(10,19.3963);
   pred_new__22->SetBinError(11,21.90072);
   pred_new__22->SetBinError(12,11.67573);
   pred_new__22->SetBinError(13,11.81584);
   pred_new__22->SetBinError(14,10.1797);
   pred_new__22->SetBinError(15,8.450735);
   pred_new__22->SetBinError(16,8.022641);
   pred_new__22->SetBinError(17,9.050644);
   pred_new__22->SetBinError(18,12.42898);
   pred_new__22->SetBinError(19,10.52533);
   pred_new__22->SetBinError(20,6.500303);
   pred_new__22->SetBinError(21,4.901629);
   pred_new__22->SetBinError(22,5.270727);
   pred_new__22->SetBinError(23,5.700704);
   pred_new__22->SetBinError(24,4.825003);
   pred_new__22->SetBinError(25,3.678833);
   pred_new__22->SetBinError(26,3.145234);
   pred_new__22->SetBinError(27,1.690965);
   pred_new__22->SetBinError(28,0.7634998);
   pred_new__22->SetBinError(29,0.4300075);
   pred_new__22->SetBinError(30,0.09008544);
   pred_new__22->SetBinError(31,0.03788741);
   pred_new__22->SetBinError(32,0.01796492);
   pred_new__22->SetBinError(33,0.009150524);
   pred_new__22->SetBinError(34,0.001708231);
   pred_new__22->SetBinError(35,0.0002424814);
   pred_new__22->SetEntries(440);
   pred_new__22->SetFillColor(38);
   pred_new__22->GetXaxis()->SetTitle("Mass [GeV]");
   pred_new__22->GetXaxis()->SetRange(1,400);
   pred_new__22->GetXaxis()->SetLabelFont(42);
   pred_new__22->GetXaxis()->SetLabelSize(0.035);
   pred_new__22->GetXaxis()->SetTitleSize(0.035);
   pred_new__22->GetXaxis()->SetTitleFont(42);
   pred_new__22->GetYaxis()->SetLabelFont(42);
   pred_new__22->GetYaxis()->SetLabelSize(0.035);
   pred_new__22->GetYaxis()->SetTitleSize(0.035);
   pred_new__22->GetYaxis()->SetTitleOffset(0);
   pred_new__22->GetYaxis()->SetTitleFont(42);
   pred_new__22->GetZaxis()->SetLabelFont(42);
   pred_new__22->GetZaxis()->SetLabelSize(0.035);
   pred_new__22->GetZaxis()->SetTitleSize(0.035);
   pred_new__22->GetZaxis()->SetTitleFont(42);
   pred_new__22->Draw("same HIST");
   
   TH1D *frameR3_copy__23 = new TH1D("frameR3_copy__23","",1,0,4000);
   frameR3_copy__23->SetMinimum(-3);
   frameR3_copy__23->SetMaximum(3);
   frameR3_copy__23->SetDirectory(0);
   frameR3_copy__23->SetStats(0);
   frameR3_copy__23->SetLineStyle(0);
   frameR3_copy__23->SetMarkerStyle(20);
   frameR3_copy__23->GetXaxis()->SetTitle("Mass (GeV)");
   frameR3_copy__23->GetXaxis()->SetLabelFont(43);
   frameR3_copy__23->GetXaxis()->SetLabelOffset(0.007);
   frameR3_copy__23->GetXaxis()->SetLabelSize(14);
   frameR3_copy__23->GetXaxis()->SetTitleSize(20);
   frameR3_copy__23->GetXaxis()->SetTitleOffset(3.75);
   frameR3_copy__23->GetXaxis()->SetTitleFont(43);
   frameR3_copy__23->GetYaxis()->SetTitle("#frac{Data-pred}{#sigma}");
   frameR3_copy__23->GetYaxis()->SetNdivisions(503);
   frameR3_copy__23->GetYaxis()->SetLabelFont(43);
   frameR3_copy__23->GetYaxis()->SetLabelOffset(0.007);
   frameR3_copy__23->GetYaxis()->SetLabelSize(12);
   frameR3_copy__23->GetYaxis()->SetTitleSize(16);
   frameR3_copy__23->GetYaxis()->SetTickLength(0.06);
   frameR3_copy__23->GetYaxis()->SetTitleOffset(1.25);
   frameR3_copy__23->GetYaxis()->SetTitleFont(43);
   frameR3_copy__23->GetZaxis()->SetLabelFont(42);
   frameR3_copy__23->GetZaxis()->SetLabelOffset(0.007);
   frameR3_copy__23->GetZaxis()->SetLabelSize(0.05);
   frameR3_copy__23->GetZaxis()->SetTitleSize(0.06);
   frameR3_copy__23->GetZaxis()->SetTitleFont(42);
   frameR3_copy__23->Draw("sameaxis");
   
   TH1D *frameR3_copy__24 = new TH1D("frameR3_copy__24","",1,0,4000);
   frameR3_copy__24->SetMinimum(-3);
   frameR3_copy__24->SetMaximum(3);
   frameR3_copy__24->SetDirectory(0);
   frameR3_copy__24->SetStats(0);
   frameR3_copy__24->SetLineStyle(0);
   frameR3_copy__24->SetMarkerStyle(20);
   frameR3_copy__24->GetXaxis()->SetTitle("Mass (GeV)");
   frameR3_copy__24->GetXaxis()->SetLabelFont(43);
   frameR3_copy__24->GetXaxis()->SetLabelOffset(0.007);
   frameR3_copy__24->GetXaxis()->SetLabelSize(14);
   frameR3_copy__24->GetXaxis()->SetTitleSize(20);
   frameR3_copy__24->GetXaxis()->SetTitleOffset(3.75);
   frameR3_copy__24->GetXaxis()->SetTitleFont(43);
   frameR3_copy__24->GetYaxis()->SetTitle("#frac{Data-pred}{#sigma}");
   frameR3_copy__24->GetYaxis()->SetNdivisions(503);
   frameR3_copy__24->GetYaxis()->SetLabelFont(43);
   frameR3_copy__24->GetYaxis()->SetLabelOffset(0.007);
   frameR3_copy__24->GetYaxis()->SetLabelSize(12);
   frameR3_copy__24->GetYaxis()->SetTitleSize(16);
   frameR3_copy__24->GetYaxis()->SetTickLength(0.06);
   frameR3_copy__24->GetYaxis()->SetTitleOffset(1.25);
   frameR3_copy__24->GetYaxis()->SetTitleFont(43);
   frameR3_copy__24->GetZaxis()->SetLabelFont(42);
   frameR3_copy__24->GetZaxis()->SetLabelOffset(0.007);
   frameR3_copy__24->GetZaxis()->SetLabelSize(0.05);
   frameR3_copy__24->GetZaxis()->SetTitleSize(0.06);
   frameR3_copy__24->GetZaxis()->SetTitleFont(42);
   frameR3_copy__24->Draw("sameaxig");
   line = new TLine(0,0,4000,0);
   line->Draw();
   line = new TLine(0,1,4000,1);
   line->SetLineStyle(4);
   line->Draw();
   line = new TLine(0,-1,4000,-1);
   line->SetLineStyle(4);
   line->Draw();
   line = new TLine(0,2,4000,2);
   line->SetLineStyle(4);
   line->Draw();
   line = new TLine(0,-2,4000,-2);
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
