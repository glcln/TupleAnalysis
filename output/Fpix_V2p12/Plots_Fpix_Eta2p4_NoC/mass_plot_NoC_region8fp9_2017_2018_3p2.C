void mass_plot_NoC_region8fp9_2017_2018_3p2()
{
//=========Macro generated from canvas: c1/c1
//=========  (Fri May 23 16:43:26 2025) by ROOT version 6.14/09
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
   pred_new__13->SetBinContent(1,131966.4);
   pred_new__13->SetBinContent(2,327076.7);
   pred_new__13->SetBinContent(3,217657);
   pred_new__13->SetBinContent(4,131960.3);
   pred_new__13->SetBinContent(5,91061.41);
   pred_new__13->SetBinContent(6,59644.67);
   pred_new__13->SetBinContent(7,40661.31);
   pred_new__13->SetBinContent(8,27661.78);
   pred_new__13->SetBinContent(9,18287.83);
   pred_new__13->SetBinContent(10,12424.97);
   pred_new__13->SetBinContent(11,8240.555);
   pred_new__13->SetBinContent(12,5697.284);
   pred_new__13->SetBinContent(13,3970.043);
   pred_new__13->SetBinContent(14,2648.1);
   pred_new__13->SetBinContent(15,1900.787);
   pred_new__13->SetBinContent(16,1370.819);
   pred_new__13->SetBinContent(17,955.7472);
   pred_new__13->SetBinContent(18,710.0013);
   pred_new__13->SetBinContent(19,538.6984);
   pred_new__13->SetBinContent(20,543.7465);
   pred_new__13->SetBinContent(21,371.7344);
   pred_new__13->SetBinContent(22,314.0145);
   pred_new__13->SetBinContent(23,231.512);
   pred_new__13->SetBinContent(24,148.0529);
   pred_new__13->SetBinContent(25,89.74448);
   pred_new__13->SetBinContent(26,58.40685);
   pred_new__13->SetBinContent(27,28.21793);
   pred_new__13->SetBinContent(28,12.43674);
   pred_new__13->SetBinContent(29,5.185317);
   pred_new__13->SetBinContent(30,2.091573);
   pred_new__13->SetBinContent(31,0.6811122);
   pred_new__13->SetBinContent(32,0.1818479);
   pred_new__13->SetBinContent(33,0.08089744);
   pred_new__13->SetBinContent(34,0.0161996);
   pred_new__13->SetBinContent(35,0.002573487);
   pred_new__13->SetBinError(1,9010.643);
   pred_new__13->SetBinError(2,4722.053);
   pred_new__13->SetBinError(3,9625.234);
   pred_new__13->SetBinError(4,2106.058);
   pred_new__13->SetBinError(5,2451.395);
   pred_new__13->SetBinError(6,1795.706);
   pred_new__13->SetBinError(7,876.2772);
   pred_new__13->SetBinError(8,1241.71);
   pred_new__13->SetBinError(9,1491.202);
   pred_new__13->SetBinError(10,442.8483);
   pred_new__13->SetBinError(11,352.6351);
   pred_new__13->SetBinError(12,212.6013);
   pred_new__13->SetBinError(13,133.9636);
   pred_new__13->SetBinError(14,344.7392);
   pred_new__13->SetBinError(15,148.9502);
   pred_new__13->SetBinError(16,100.4248);
   pred_new__13->SetBinError(17,146.7843);
   pred_new__13->SetBinError(18,132.5448);
   pred_new__13->SetBinError(19,73.06891);
   pred_new__13->SetBinError(20,94.89624);
   pred_new__13->SetBinError(21,36.74844);
   pred_new__13->SetBinError(22,56.76758);
   pred_new__13->SetBinError(23,31.27852);
   pred_new__13->SetBinError(24,39.7736);
   pred_new__13->SetBinError(25,14.46024);
   pred_new__13->SetBinError(26,11.99781);
   pred_new__13->SetBinError(27,4.886443);
   pred_new__13->SetBinError(28,2.580522);
   pred_new__13->SetBinError(29,0.9526943);
   pred_new__13->SetBinError(30,0.5466954);
   pred_new__13->SetBinError(31,0.1941936);
   pred_new__13->SetBinError(32,0.08194028);
   pred_new__13->SetBinError(33,0.0378153);
   pred_new__13->SetBinError(34,0.009904124);
   pred_new__13->SetBinError(35,0.001860584);
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
   pred_noSyst_new__14->SetBinContent(1,131966.4);
   pred_noSyst_new__14->SetBinContent(2,327076.7);
   pred_noSyst_new__14->SetBinContent(3,217657);
   pred_noSyst_new__14->SetBinContent(4,131960.3);
   pred_noSyst_new__14->SetBinContent(5,91061.41);
   pred_noSyst_new__14->SetBinContent(6,59644.67);
   pred_noSyst_new__14->SetBinContent(7,40661.31);
   pred_noSyst_new__14->SetBinContent(8,27661.78);
   pred_noSyst_new__14->SetBinContent(9,18287.83);
   pred_noSyst_new__14->SetBinContent(10,12424.97);
   pred_noSyst_new__14->SetBinContent(11,8240.555);
   pred_noSyst_new__14->SetBinContent(12,5697.284);
   pred_noSyst_new__14->SetBinContent(13,3970.043);
   pred_noSyst_new__14->SetBinContent(14,2648.1);
   pred_noSyst_new__14->SetBinContent(15,1900.787);
   pred_noSyst_new__14->SetBinContent(16,1370.819);
   pred_noSyst_new__14->SetBinContent(17,955.7472);
   pred_noSyst_new__14->SetBinContent(18,710.0013);
   pred_noSyst_new__14->SetBinContent(19,538.6984);
   pred_noSyst_new__14->SetBinContent(20,543.7465);
   pred_noSyst_new__14->SetBinContent(21,371.7344);
   pred_noSyst_new__14->SetBinContent(22,314.0145);
   pred_noSyst_new__14->SetBinContent(23,231.512);
   pred_noSyst_new__14->SetBinContent(24,148.0529);
   pred_noSyst_new__14->SetBinContent(25,89.74448);
   pred_noSyst_new__14->SetBinContent(26,58.40685);
   pred_noSyst_new__14->SetBinContent(27,28.21793);
   pred_noSyst_new__14->SetBinContent(28,12.43674);
   pred_noSyst_new__14->SetBinContent(29,5.185317);
   pred_noSyst_new__14->SetBinContent(30,2.091573);
   pred_noSyst_new__14->SetBinContent(31,0.6811122);
   pred_noSyst_new__14->SetBinContent(32,0.1818479);
   pred_noSyst_new__14->SetBinContent(33,0.08089744);
   pred_noSyst_new__14->SetBinContent(34,0.0161996);
   pred_noSyst_new__14->SetBinContent(35,0.002573487);
   pred_noSyst_new__14->SetBinError(1,184.4701);
   pred_noSyst_new__14->SetBinError(2,302.4453);
   pred_noSyst_new__14->SetBinError(3,209.5494);
   pred_noSyst_new__14->SetBinError(4,139.0365);
   pred_noSyst_new__14->SetBinError(5,97.6213);
   pred_noSyst_new__14->SetBinError(6,65.242);
   pred_noSyst_new__14->SetBinError(7,45.73101);
   pred_noSyst_new__14->SetBinError(8,31.75457);
   pred_noSyst_new__14->SetBinError(9,23.07912);
   pred_noSyst_new__14->SetBinError(10,16.51365);
   pred_noSyst_new__14->SetBinError(11,11.55291);
   pred_noSyst_new__14->SetBinError(12,8.547163);
   pred_noSyst_new__14->SetBinError(13,6.424723);
   pred_noSyst_new__14->SetBinError(14,4.40781);
   pred_noSyst_new__14->SetBinError(15,3.349892);
   pred_noSyst_new__14->SetBinError(16,2.467651);
   pred_noSyst_new__14->SetBinError(17,1.815556);
   pred_noSyst_new__14->SetBinError(18,1.353353);
   pred_noSyst_new__14->SetBinError(19,1.027743);
   pred_noSyst_new__14->SetBinError(20,0.8726337);
   pred_noSyst_new__14->SetBinError(21,0.6022663);
   pred_noSyst_new__14->SetBinError(22,0.4483993);
   pred_noSyst_new__14->SetBinError(23,0.3028868);
   pred_noSyst_new__14->SetBinError(24,0.1821112);
   pred_noSyst_new__14->SetBinError(25,0.1058813);
   pred_noSyst_new__14->SetBinError(26,0.06020778);
   pred_noSyst_new__14->SetBinError(27,0.02810885);
   pred_noSyst_new__14->SetBinError(28,0.01176963);
   pred_noSyst_new__14->SetBinError(29,0.005316125);
   pred_noSyst_new__14->SetBinError(30,0.002427325);
   pred_noSyst_new__14->SetBinError(31,0.0009118437);
   pred_noSyst_new__14->SetBinError(32,0.0003418431);
   pred_noSyst_new__14->SetBinError(33,0.0001355537);
   pred_noSyst_new__14->SetBinError(34,3.193545e-05);
   pred_noSyst_new__14->SetBinError(35,5.840729e-06);
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
   pred_new__15->SetBinContent(1,131966.4);
   pred_new__15->SetBinContent(2,327076.7);
   pred_new__15->SetBinContent(3,217657);
   pred_new__15->SetBinContent(4,131960.3);
   pred_new__15->SetBinContent(5,91061.41);
   pred_new__15->SetBinContent(6,59644.67);
   pred_new__15->SetBinContent(7,40661.31);
   pred_new__15->SetBinContent(8,27661.78);
   pred_new__15->SetBinContent(9,18287.83);
   pred_new__15->SetBinContent(10,12424.97);
   pred_new__15->SetBinContent(11,8240.555);
   pred_new__15->SetBinContent(12,5697.284);
   pred_new__15->SetBinContent(13,3970.043);
   pred_new__15->SetBinContent(14,2648.1);
   pred_new__15->SetBinContent(15,1900.787);
   pred_new__15->SetBinContent(16,1370.819);
   pred_new__15->SetBinContent(17,955.7472);
   pred_new__15->SetBinContent(18,710.0013);
   pred_new__15->SetBinContent(19,538.6984);
   pred_new__15->SetBinContent(20,543.7465);
   pred_new__15->SetBinContent(21,371.7344);
   pred_new__15->SetBinContent(22,314.0145);
   pred_new__15->SetBinContent(23,231.512);
   pred_new__15->SetBinContent(24,148.0529);
   pred_new__15->SetBinContent(25,89.74448);
   pred_new__15->SetBinContent(26,58.40685);
   pred_new__15->SetBinContent(27,28.21793);
   pred_new__15->SetBinContent(28,12.43674);
   pred_new__15->SetBinContent(29,5.185317);
   pred_new__15->SetBinContent(30,2.091573);
   pred_new__15->SetBinContent(31,0.6811122);
   pred_new__15->SetBinContent(32,0.1818479);
   pred_new__15->SetBinContent(33,0.08089744);
   pred_new__15->SetBinContent(34,0.0161996);
   pred_new__15->SetBinContent(35,0.002573487);
   pred_new__15->SetBinError(1,9010.643);
   pred_new__15->SetBinError(2,4722.053);
   pred_new__15->SetBinError(3,9625.234);
   pred_new__15->SetBinError(4,2106.058);
   pred_new__15->SetBinError(5,2451.395);
   pred_new__15->SetBinError(6,1795.706);
   pred_new__15->SetBinError(7,876.2772);
   pred_new__15->SetBinError(8,1241.71);
   pred_new__15->SetBinError(9,1491.202);
   pred_new__15->SetBinError(10,442.8483);
   pred_new__15->SetBinError(11,352.6351);
   pred_new__15->SetBinError(12,212.6013);
   pred_new__15->SetBinError(13,133.9636);
   pred_new__15->SetBinError(14,344.7392);
   pred_new__15->SetBinError(15,148.9502);
   pred_new__15->SetBinError(16,100.4248);
   pred_new__15->SetBinError(17,146.7843);
   pred_new__15->SetBinError(18,132.5448);
   pred_new__15->SetBinError(19,73.06891);
   pred_new__15->SetBinError(20,94.89624);
   pred_new__15->SetBinError(21,36.74844);
   pred_new__15->SetBinError(22,56.76758);
   pred_new__15->SetBinError(23,31.27852);
   pred_new__15->SetBinError(24,39.7736);
   pred_new__15->SetBinError(25,14.46024);
   pred_new__15->SetBinError(26,11.99781);
   pred_new__15->SetBinError(27,4.886443);
   pred_new__15->SetBinError(28,2.580522);
   pred_new__15->SetBinError(29,0.9526943);
   pred_new__15->SetBinError(30,0.5466954);
   pred_new__15->SetBinError(31,0.1941936);
   pred_new__15->SetBinError(32,0.08194028);
   pred_new__15->SetBinError(33,0.0378153);
   pred_new__15->SetBinError(34,0.009904124);
   pred_new__15->SetBinError(35,0.001860584);
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
   obs_new__16->SetBinContent(1,127724);
   obs_new__16->SetBinContent(2,302969);
   obs_new__16->SetBinContent(3,212094);
   obs_new__16->SetBinContent(4,136963);
   obs_new__16->SetBinContent(5,95959);
   obs_new__16->SetBinContent(6,66326);
   obs_new__16->SetBinContent(7,45891);
   obs_new__16->SetBinContent(8,31203);
   obs_new__16->SetBinContent(9,20992);
   obs_new__16->SetBinContent(10,13872);
   obs_new__16->SetBinContent(11,9312);
   obs_new__16->SetBinContent(12,6389);
   obs_new__16->SetBinContent(13,4282);
   obs_new__16->SetBinContent(14,2983);
   obs_new__16->SetBinContent(15,2119);
   obs_new__16->SetBinContent(16,1530);
   obs_new__16->SetBinContent(17,1135);
   obs_new__16->SetBinContent(18,813);
   obs_new__16->SetBinContent(19,622);
   obs_new__16->SetBinContent(20,652);
   obs_new__16->SetBinContent(21,371);
   obs_new__16->SetBinContent(22,376);
   obs_new__16->SetBinContent(23,291);
   obs_new__16->SetBinContent(24,182);
   obs_new__16->SetBinContent(25,114);
   obs_new__16->SetBinContent(26,71);
   obs_new__16->SetBinContent(27,37);
   obs_new__16->SetBinContent(28,12);
   obs_new__16->SetBinContent(29,6);
   obs_new__16->SetBinContent(30,7);
   obs_new__16->SetBinContent(31,4);
   obs_new__16->SetBinContent(34,2);
   obs_new__16->SetEntries(1085303);
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
   pred_new__18->SetBinContent(0,0.9991369);
   pred_new__18->SetBinContent(1,0.9991369);
   pred_new__18->SetBinContent(2,1.003463);
   pred_new__18->SetBinContent(3,1.043706);
   pred_new__18->SetBinContent(4,1.080518);
   pred_new__18->SetBinContent(5,1.100774);
   pred_new__18->SetBinContent(6,1.123716);
   pred_new__18->SetBinContent(7,1.129215);
   pred_new__18->SetBinContent(8,1.129497);
   pred_new__18->SetBinContent(9,1.130195);
   pred_new__18->SetBinContent(10,1.122169);
   pred_new__18->SetBinContent(11,1.124716);
   pred_new__18->SetBinContent(12,1.122485);
   pred_new__18->SetBinContent(13,1.122925);
   pred_new__18->SetBinContent(14,1.140655);
   pred_new__18->SetBinContent(15,1.145814);
   pred_new__18->SetBinContent(16,1.156768);
   pred_new__18->SetBinContent(17,1.170662);
   pred_new__18->SetBinContent(18,1.165377);
   pred_new__18->SetBinContent(19,1.171526);
   pred_new__18->SetBinContent(20,1.176564);
   pred_new__18->SetBinContent(21,1.166863);
   pred_new__18->SetBinContent(22,1.237333);
   pred_new__18->SetBinContent(23,1.259082);
   pred_new__18->SetBinContent(24,1.26051);
   pred_new__18->SetBinContent(25,1.283967);
   pred_new__18->SetBinContent(26,1.295421);
   pred_new__18->SetBinContent(27,1.390758);
   pred_new__18->SetBinContent(28,1.499304);
   pred_new__18->SetBinContent(29,2.305959);
   pred_new__18->SetBinContent(30,4.256429);
   pred_new__18->SetBinContent(31,6.23292);
   pred_new__18->SetBinContent(32,7.104331);
   pred_new__18->SetBinContent(33,20.06611);
   pred_new__18->SetBinContent(34,106.5355);
   pred_new__18->SetBinError(0,0.01351905);
   pred_new__18->SetBinError(1,0.01351905);
   pred_new__18->SetBinError(2,0.01220393);
   pred_new__18->SetBinError(3,0.01761447);
   pred_new__18->SetBinError(4,0.01155397);
   pred_new__18->SetBinError(5,0.01516044);
   pred_new__18->SetBinError(6,0.01758509);
   pred_new__18->SetBinError(7,0.0203765);
   pred_new__18->SetBinError(8,0.02759853);
   pred_new__18->SetBinError(9,0.03270777);
   pred_new__18->SetBinError(10,0.02214963);
   pred_new__18->SetBinError(11,0.02631844);
   pred_new__18->SetBinError(12,0.03098756);
   pred_new__18->SetBinError(13,0.03977486);
   pred_new__18->SetBinError(14,0.05397489);
   pred_new__18->SetBinError(15,0.04965812);
   pred_new__18->SetBinError(16,0.05914799);
   pred_new__18->SetBinError(17,0.07407596);
   pred_new__18->SetBinError(18,0.07823044);
   pred_new__18->SetBinError(19,0.07718216);
   pred_new__18->SetBinError(20,0.08754135);
   pred_new__18->SetBinError(21,0.08572058);
   pred_new__18->SetBinError(22,0.115298);
   pred_new__18->SetBinError(23,0.1273819);
   pred_new__18->SetBinError(24,0.1728943);
   pred_new__18->SetBinError(25,0.151182);
   pred_new__18->SetBinError(26,0.1941305);
   pred_new__18->SetBinError(27,0.2327313);
   pred_new__18->SetBinError(28,0.3378071);
   pred_new__18->SetBinError(29,0.6147881);
   pred_new__18->SetBinError(30,1.436442);
   pred_new__18->SetBinError(31,2.898549);
   pred_new__18->SetBinError(32,5.521505);
   pred_new__18->SetBinError(33,16.22962);
   pred_new__18->SetBinError(34,94.58007);
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
   obs_new__20->SetBinContent(1,0.9678526);
   obs_new__20->SetBinContent(2,0.9262934);
   obs_new__20->SetBinContent(3,0.9744416);
   obs_new__20->SetBinContent(4,1.03791);
   obs_new__20->SetBinContent(5,1.053783);
   obs_new__20->SetBinContent(6,1.112019);
   obs_new__20->SetBinContent(7,1.128616);
   obs_new__20->SetBinContent(8,1.128018);
   obs_new__20->SetBinContent(9,1.147867);
   obs_new__20->SetBinContent(10,1.116462);
   obs_new__20->SetBinContent(11,1.130021);
   obs_new__20->SetBinContent(12,1.121411);
   obs_new__20->SetBinContent(13,1.078578);
   obs_new__20->SetBinContent(14,1.126468);
   obs_new__20->SetBinContent(15,1.114801);
   obs_new__20->SetBinContent(16,1.116121);
   obs_new__20->SetBinContent(17,1.187553);
   obs_new__20->SetBinContent(18,1.145068);
   obs_new__20->SetBinContent(19,1.154635);
   obs_new__20->SetBinContent(20,1.199088);
   obs_new__20->SetBinContent(21,0.9980243);
   obs_new__20->SetBinContent(22,1.197397);
   obs_new__20->SetBinContent(23,1.256954);
   obs_new__20->SetBinContent(24,1.22929);
   obs_new__20->SetBinContent(25,1.270273);
   obs_new__20->SetBinContent(26,1.215611);
   obs_new__20->SetBinContent(27,1.311223);
   obs_new__20->SetBinContent(28,0.9648829);
   obs_new__20->SetBinContent(29,1.157113);
   obs_new__20->SetBinContent(30,3.346764);
   obs_new__20->SetBinContent(31,5.872747);
   obs_new__20->SetBinContent(34,123.4599);
   obs_new__20->SetBinError(1,0.06614029);
   obs_new__20->SetBinError(2,0.0134785);
   obs_new__20->SetBinError(3,0.04314371);
   obs_new__20->SetBinError(4,0.01680055);
   obs_new__20->SetBinError(5,0.02857134);
   obs_new__20->SetBinError(6,0.03375655);
   obs_new__20->SetBinError(7,0.02488645);
   obs_new__20->SetBinError(8,0.05103673);
   obs_new__20->SetBinError(9,0.09393255);
   obs_new__20->SetBinError(10,0.04090619);
   obs_new__20->SetBinError(11,0.04975428);
   obs_new__20->SetBinError(12,0.04413608);
   obs_new__20->SetBinError(13,0.0399535);
   obs_new__20->SetBinError(14,0.1480909);
   obs_new__20->SetBinError(15,0.0906532);
   obs_new__20->SetBinError(16,0.08660178);
   obs_new__20->SetBinError(17,0.1857603);
   obs_new__20->SetBinError(18,0.2175038);
   obs_new__20->SetBinError(19,0.1633139);
   obs_new__20->SetBinError(20,0.2144726);
   obs_new__20->SetBinError(21,0.1114399);
   obs_new__20->SetBinError(22,0.2251012);
   obs_new__20->SetBinError(23,0.1851178);
   obs_new__20->SetBinError(24,0.3425825);
   obs_new__20->SetBinError(25,0.2367408);
   obs_new__20->SetBinError(26,0.2883869);
   obs_new__20->SetBinError(27,0.3130893);
   obs_new__20->SetBinError(28,0.3430239);
   obs_new__20->SetBinError(29,0.5180239);
   obs_new__20->SetBinError(30,1.537971);
   obs_new__20->SetBinError(31,3.38022);
   obs_new__20->SetBinError(34,115.406);
   obs_new__20->SetEntries(2.047987);
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
   pred_new__22->SetBinContent(1,-0.4704483);
   pred_new__22->SetBinContent(2,-5.071012);
   pred_new__22->SetBinContent(3,-0.5772963);
   pred_new__22->SetBinContent(4,2.339526);
   pred_new__22->SetBinContent(5,1.982114);
   pred_new__22->SetBinContent(6,3.683039);
   pred_new__22->SetBinContent(7,5.797355);
   pred_new__22->SetBinContent(8,2.823463);
   pred_new__22->SetBinContent(9,1.804914);
   pred_new__22->SetBinContent(10,3.157789);
   pred_new__22->SetBinContent(11,2.930651);
   pred_new__22->SetBinContent(12,3.045464);
   pred_new__22->SetBinContent(13,2.092402);
   pred_new__22->SetBinContent(14,0.9594932);
   pred_new__22->SetBinContent(15,1.399698);
   pred_new__22->SetBinContent(16,1.47702);
   pred_new__22->SetBinContent(17,1.190259);
   pred_new__22->SetBinContent(18,0.7597128);
   pred_new__22->SetBinContent(19,1.078955);
   pred_new__22->SetBinContent(20,1.101595);
   pred_new__22->SetBinContent(21,-0.01770309);
   pred_new__22->SetBinContent(22,1.033347);
   pred_new__22->SetBinContent(23,1.669924);
   pred_new__22->SetBinContent(24,0.8083541);
   pred_new__22->SetBinContent(25,1.350106);
   pred_new__22->SetBinContent(26,0.8596207);
   pred_new__22->SetBinContent(27,1.128674);
   pred_new__22->SetBinContent(28,-0.1020295);
   pred_new__22->SetBinContent(29,0.317797);
   pred_new__22->SetBinContent(30,1.860152);
   pred_new__22->SetBinContent(31,1.724847);
   pred_new__22->SetBinContent(32,-2.219274);
   pred_new__22->SetBinContent(33,-2.139278);
   pred_new__22->SetBinContent(34,1.535625);
   pred_new__22->SetBinContent(35,-1.383161);
   pred_new__22->SetBinError(1,9010.643);
   pred_new__22->SetBinError(2,4722.053);
   pred_new__22->SetBinError(3,9625.234);
   pred_new__22->SetBinError(4,2106.058);
   pred_new__22->SetBinError(5,2451.395);
   pred_new__22->SetBinError(6,1795.706);
   pred_new__22->SetBinError(7,876.2772);
   pred_new__22->SetBinError(8,1241.71);
   pred_new__22->SetBinError(9,1491.202);
   pred_new__22->SetBinError(10,442.8483);
   pred_new__22->SetBinError(11,352.6351);
   pred_new__22->SetBinError(12,212.6013);
   pred_new__22->SetBinError(13,133.9636);
   pred_new__22->SetBinError(14,344.7392);
   pred_new__22->SetBinError(15,148.9502);
   pred_new__22->SetBinError(16,100.4248);
   pred_new__22->SetBinError(17,146.7843);
   pred_new__22->SetBinError(18,132.5448);
   pred_new__22->SetBinError(19,73.06891);
   pred_new__22->SetBinError(20,94.89624);
   pred_new__22->SetBinError(21,36.74844);
   pred_new__22->SetBinError(22,56.76758);
   pred_new__22->SetBinError(23,31.27852);
   pred_new__22->SetBinError(24,39.7736);
   pred_new__22->SetBinError(25,14.46024);
   pred_new__22->SetBinError(26,11.99781);
   pred_new__22->SetBinError(27,4.886443);
   pred_new__22->SetBinError(28,2.580522);
   pred_new__22->SetBinError(29,0.9526943);
   pred_new__22->SetBinError(30,0.5466954);
   pred_new__22->SetBinError(31,0.1941936);
   pred_new__22->SetBinError(32,0.08194028);
   pred_new__22->SetBinError(33,0.0378153);
   pred_new__22->SetBinError(34,0.009904124);
   pred_new__22->SetBinError(35,0.001860584);
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
