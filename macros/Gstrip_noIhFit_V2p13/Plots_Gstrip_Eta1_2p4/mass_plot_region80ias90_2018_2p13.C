void mass_plot_region80ias90_2018_2p13()
{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Feb 11 17:06:04 2025) by ROOT version 6.14/09
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
   Double_t xAxis7[36] = {0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000, 2500, 3200, 4000}; 
   
   TH1F *pred_new__11 = new TH1F("pred_new__11","",35, xAxis7);
   pred_new__11->SetBinContent(1,2500.779);
   pred_new__11->SetBinContent(2,8549.393);
   pred_new__11->SetBinContent(3,29194.08);
   pred_new__11->SetBinContent(4,49297.09);
   pred_new__11->SetBinContent(5,46751.35);
   pred_new__11->SetBinContent(6,38059.13);
   pred_new__11->SetBinContent(7,32989.43);
   pred_new__11->SetBinContent(8,27646.07);
   pred_new__11->SetBinContent(9,21153.51);
   pred_new__11->SetBinContent(10,15724.35);
   pred_new__11->SetBinContent(11,10584.95);
   pred_new__11->SetBinContent(12,7099.415);
   pred_new__11->SetBinContent(13,5412.602);
   pred_new__11->SetBinContent(14,3551.863);
   pred_new__11->SetBinContent(15,2585.409);
   pred_new__11->SetBinContent(16,1812.656);
   pred_new__11->SetBinContent(17,1252.233);
   pred_new__11->SetBinContent(18,947.5469);
   pred_new__11->SetBinContent(19,732.3422);
   pred_new__11->SetBinContent(20,731.7791);
   pred_new__11->SetBinContent(21,499.4962);
   pred_new__11->SetBinContent(22,429.3569);
   pred_new__11->SetBinContent(23,313.2071);
   pred_new__11->SetBinContent(24,202.8403);
   pred_new__11->SetBinContent(25,121.5144);
   pred_new__11->SetBinContent(26,78.38297);
   pred_new__11->SetBinContent(27,37.65041);
   pred_new__11->SetBinContent(28,15.95034);
   pred_new__11->SetBinContent(29,6.560309);
   pred_new__11->SetBinContent(30,2.656386);
   pred_new__11->SetBinContent(31,0.8287289);
   pred_new__11->SetBinContent(32,0.2237096);
   pred_new__11->SetBinContent(33,0.08241045);
   pred_new__11->SetBinContent(34,0.01778745);
   pred_new__11->SetBinContent(35,0.002537929);
   pred_new__11->SetBinError(1,234.3084);
   pred_new__11->SetBinError(2,135.2913);
   pred_new__11->SetBinError(3,195.9066);
   pred_new__11->SetBinError(4,428.6409);
   pred_new__11->SetBinError(5,1141.719);
   pred_new__11->SetBinError(6,868.6938);
   pred_new__11->SetBinError(7,623.2041);
   pred_new__11->SetBinError(8,1341.98);
   pred_new__11->SetBinError(9,1079.467);
   pred_new__11->SetBinError(10,447.0648);
   pred_new__11->SetBinError(11,548.1883);
   pred_new__11->SetBinError(12,489.3248);
   pred_new__11->SetBinError(13,446.2614);
   pred_new__11->SetBinError(14,240.6655);
   pred_new__11->SetBinError(15,139.8256);
   pred_new__11->SetBinError(16,161.5708);
   pred_new__11->SetBinError(17,112.3595);
   pred_new__11->SetBinError(18,89.02478);
   pred_new__11->SetBinError(19,87.92375);
   pred_new__11->SetBinError(20,83.97336);
   pred_new__11->SetBinError(21,67.32614);
   pred_new__11->SetBinError(22,56.9166);
   pred_new__11->SetBinError(23,43.05391);
   pred_new__11->SetBinError(24,35.10631);
   pred_new__11->SetBinError(25,24.09706);
   pred_new__11->SetBinError(26,16.09294);
   pred_new__11->SetBinError(27,11.87052);
   pred_new__11->SetBinError(28,4.216704);
   pred_new__11->SetBinError(29,1.64415);
   pred_new__11->SetBinError(30,0.8097961);
   pred_new__11->SetBinError(31,0.3526074);
   pred_new__11->SetBinError(32,0.1199805);
   pred_new__11->SetBinError(33,0.0001668499);
   pred_new__11->SetBinError(34,3.952125e-05);
   pred_new__11->SetBinError(35,5.897287e-06);
   pred_new__11->SetMinimum(0.0001);
   pred_new__11->SetMaximum(5000000);
   pred_new__11->SetEntries(438);
   pred_new__11->SetFillColor(5);
   pred_new__11->SetLineColor(5);
   pred_new__11->SetMarkerColor(5);
   pred_new__11->SetMarkerStyle(22);
   pred_new__11->GetXaxis()->SetRange(1,35);
   pred_new__11->GetXaxis()->SetLabelFont(42);
   pred_new__11->GetXaxis()->SetLabelSize(0.035);
   pred_new__11->GetXaxis()->SetTitleSize(0.035);
   pred_new__11->GetXaxis()->SetTitleFont(42);
   pred_new__11->GetYaxis()->SetTitle("Events / bin");
   pred_new__11->GetYaxis()->SetLabelFont(43);
   pred_new__11->GetYaxis()->SetLabelSize(20);
   pred_new__11->GetYaxis()->SetTitleSize(20);
   pred_new__11->GetYaxis()->SetTitleOffset(2);
   pred_new__11->GetYaxis()->SetTitleFont(43);
   pred_new__11->GetZaxis()->SetLabelFont(42);
   pred_new__11->GetZaxis()->SetLabelSize(0.035);
   pred_new__11->GetZaxis()->SetTitleSize(0.035);
   pred_new__11->GetZaxis()->SetTitleFont(42);
   pred_new__11->Draw(" E5");
   Double_t xAxis8[36] = {0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000, 2500, 3200, 4000}; 
   
   TH1F *pred_noSyst_new__12 = new TH1F("pred_noSyst_new__12","",35, xAxis8);
   pred_noSyst_new__12->SetBinContent(1,2500.779);
   pred_noSyst_new__12->SetBinContent(2,8549.393);
   pred_noSyst_new__12->SetBinContent(3,29194.08);
   pred_noSyst_new__12->SetBinContent(4,49297.09);
   pred_noSyst_new__12->SetBinContent(5,46751.35);
   pred_noSyst_new__12->SetBinContent(6,38059.13);
   pred_noSyst_new__12->SetBinContent(7,32989.43);
   pred_noSyst_new__12->SetBinContent(8,27646.07);
   pred_noSyst_new__12->SetBinContent(9,21153.51);
   pred_noSyst_new__12->SetBinContent(10,15724.35);
   pred_noSyst_new__12->SetBinContent(11,10584.95);
   pred_noSyst_new__12->SetBinContent(12,7099.415);
   pred_noSyst_new__12->SetBinContent(13,5412.602);
   pred_noSyst_new__12->SetBinContent(14,3551.863);
   pred_noSyst_new__12->SetBinContent(15,2585.409);
   pred_noSyst_new__12->SetBinContent(16,1812.656);
   pred_noSyst_new__12->SetBinContent(17,1252.233);
   pred_noSyst_new__12->SetBinContent(18,947.5469);
   pred_noSyst_new__12->SetBinContent(19,732.3422);
   pred_noSyst_new__12->SetBinContent(20,731.7791);
   pred_noSyst_new__12->SetBinContent(21,499.4962);
   pred_noSyst_new__12->SetBinContent(22,429.3569);
   pred_noSyst_new__12->SetBinContent(23,313.2071);
   pred_noSyst_new__12->SetBinContent(24,202.8403);
   pred_noSyst_new__12->SetBinContent(25,121.5144);
   pred_noSyst_new__12->SetBinContent(26,78.38297);
   pred_noSyst_new__12->SetBinContent(27,37.65041);
   pred_noSyst_new__12->SetBinContent(28,15.95034);
   pred_noSyst_new__12->SetBinContent(29,6.560309);
   pred_noSyst_new__12->SetBinContent(30,2.656386);
   pred_noSyst_new__12->SetBinContent(31,0.8287289);
   pred_noSyst_new__12->SetBinContent(32,0.2237096);
   pred_noSyst_new__12->SetBinContent(33,0.08241045);
   pred_noSyst_new__12->SetBinContent(34,0.01778745);
   pred_noSyst_new__12->SetBinContent(35,0.002537929);
   pred_noSyst_new__12->SetBinError(1,49.01049);
   pred_noSyst_new__12->SetBinError(2,65.20948);
   pred_noSyst_new__12->SetBinError(3,98.83813);
   pred_noSyst_new__12->SetBinError(4,125.7422);
   pred_noSyst_new__12->SetBinError(5,109.8526);
   pred_noSyst_new__12->SetBinError(6,94.32947);
   pred_noSyst_new__12->SetBinError(7,72.02321);
   pred_noSyst_new__12->SetBinError(8,59.37962);
   pred_noSyst_new__12->SetBinError(9,48.53062);
   pred_noSyst_new__12->SetBinError(10,38.81378);
   pred_noSyst_new__12->SetBinError(11,27.88919);
   pred_noSyst_new__12->SetBinError(12,20.43022);
   pred_noSyst_new__12->SetBinError(13,17.71836);
   pred_noSyst_new__12->SetBinError(14,12.97763);
   pred_noSyst_new__12->SetBinError(15,9.867733);
   pred_noSyst_new__12->SetBinError(16,6.920734);
   pred_noSyst_new__12->SetBinError(17,4.800525);
   pred_noSyst_new__12->SetBinError(18,3.626352);
   pred_noSyst_new__12->SetBinError(19,2.808098);
   pred_noSyst_new__12->SetBinError(20,2.297078);
   pred_noSyst_new__12->SetBinError(21,1.598048);
   pred_noSyst_new__12->SetBinError(22,1.176943);
   pred_noSyst_new__12->SetBinError(23,0.7879262);
   pred_noSyst_new__12->SetBinError(24,0.4633646);
   pred_noSyst_new__12->SetBinError(25,0.2668339);
   pred_noSyst_new__12->SetBinError(26,0.145185);
   pred_noSyst_new__12->SetBinError(27,0.06605522);
   pred_noSyst_new__12->SetBinError(28,0.02693392);
   pred_noSyst_new__12->SetBinError(29,0.01124193);
   pred_noSyst_new__12->SetBinError(30,0.004683778);
   pred_noSyst_new__12->SetBinError(31,0.001564829);
   pred_noSyst_new__12->SetBinError(32,0.0005091787);
   pred_noSyst_new__12->SetBinError(33,0.0001668499);
   pred_noSyst_new__12->SetBinError(34,3.952125e-05);
   pred_noSyst_new__12->SetBinError(35,5.897287e-06);
   pred_noSyst_new__12->SetMinimum(0.0001);
   pred_noSyst_new__12->SetMaximum(5000000);
   pred_noSyst_new__12->SetEntries(405);
   pred_noSyst_new__12->SetFillColor(5);
   pred_noSyst_new__12->SetLineColor(5);
   pred_noSyst_new__12->SetMarkerColor(5);
   pred_noSyst_new__12->SetMarkerStyle(22);
   pred_noSyst_new__12->SetMarkerSize(0.1);
   pred_noSyst_new__12->GetXaxis()->SetRange(1,35);
   pred_noSyst_new__12->GetXaxis()->SetLabelFont(42);
   pred_noSyst_new__12->GetXaxis()->SetLabelSize(0.035);
   pred_noSyst_new__12->GetXaxis()->SetTitleSize(0.035);
   pred_noSyst_new__12->GetXaxis()->SetTitleFont(42);
   pred_noSyst_new__12->GetYaxis()->SetTitle("Events / bin");
   pred_noSyst_new__12->GetYaxis()->SetLabelFont(43);
   pred_noSyst_new__12->GetYaxis()->SetLabelSize(20);
   pred_noSyst_new__12->GetYaxis()->SetTitleSize(20);
   pred_noSyst_new__12->GetYaxis()->SetTitleOffset(7);
   pred_noSyst_new__12->GetYaxis()->SetTitleFont(43);
   pred_noSyst_new__12->GetZaxis()->SetLabelFont(42);
   pred_noSyst_new__12->GetZaxis()->SetLabelSize(0.035);
   pred_noSyst_new__12->GetZaxis()->SetTitleSize(0.035);
   pred_noSyst_new__12->GetZaxis()->SetTitleFont(42);
   pred_noSyst_new__12->Draw("same E5");
   Double_t xAxis9[36] = {0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000, 2500, 3200, 4000}; 
   
   TH1F *pred_new__13 = new TH1F("pred_new__13","",35, xAxis9);
   pred_new__13->SetBinContent(1,2500.779);
   pred_new__13->SetBinContent(2,8549.393);
   pred_new__13->SetBinContent(3,29194.08);
   pred_new__13->SetBinContent(4,49297.09);
   pred_new__13->SetBinContent(5,46751.35);
   pred_new__13->SetBinContent(6,38059.13);
   pred_new__13->SetBinContent(7,32989.43);
   pred_new__13->SetBinContent(8,27646.07);
   pred_new__13->SetBinContent(9,21153.51);
   pred_new__13->SetBinContent(10,15724.35);
   pred_new__13->SetBinContent(11,10584.95);
   pred_new__13->SetBinContent(12,7099.415);
   pred_new__13->SetBinContent(13,5412.602);
   pred_new__13->SetBinContent(14,3551.863);
   pred_new__13->SetBinContent(15,2585.409);
   pred_new__13->SetBinContent(16,1812.656);
   pred_new__13->SetBinContent(17,1252.233);
   pred_new__13->SetBinContent(18,947.5469);
   pred_new__13->SetBinContent(19,732.3422);
   pred_new__13->SetBinContent(20,731.7791);
   pred_new__13->SetBinContent(21,499.4962);
   pred_new__13->SetBinContent(22,429.3569);
   pred_new__13->SetBinContent(23,313.2071);
   pred_new__13->SetBinContent(24,202.8403);
   pred_new__13->SetBinContent(25,121.5144);
   pred_new__13->SetBinContent(26,78.38297);
   pred_new__13->SetBinContent(27,37.65041);
   pred_new__13->SetBinContent(28,15.95034);
   pred_new__13->SetBinContent(29,6.560309);
   pred_new__13->SetBinContent(30,2.656386);
   pred_new__13->SetBinContent(31,0.8287289);
   pred_new__13->SetBinContent(32,0.2237096);
   pred_new__13->SetBinContent(33,0.08241045);
   pred_new__13->SetBinContent(34,0.01778745);
   pred_new__13->SetBinContent(35,0.002537929);
   pred_new__13->SetBinError(1,234.3084);
   pred_new__13->SetBinError(2,135.2913);
   pred_new__13->SetBinError(3,195.9066);
   pred_new__13->SetBinError(4,428.6409);
   pred_new__13->SetBinError(5,1141.719);
   pred_new__13->SetBinError(6,868.6938);
   pred_new__13->SetBinError(7,623.2041);
   pred_new__13->SetBinError(8,1341.98);
   pred_new__13->SetBinError(9,1079.467);
   pred_new__13->SetBinError(10,447.0648);
   pred_new__13->SetBinError(11,548.1883);
   pred_new__13->SetBinError(12,489.3248);
   pred_new__13->SetBinError(13,446.2614);
   pred_new__13->SetBinError(14,240.6655);
   pred_new__13->SetBinError(15,139.8256);
   pred_new__13->SetBinError(16,161.5708);
   pred_new__13->SetBinError(17,112.3595);
   pred_new__13->SetBinError(18,89.02478);
   pred_new__13->SetBinError(19,87.92375);
   pred_new__13->SetBinError(20,83.97336);
   pred_new__13->SetBinError(21,67.32614);
   pred_new__13->SetBinError(22,56.9166);
   pred_new__13->SetBinError(23,43.05391);
   pred_new__13->SetBinError(24,35.10631);
   pred_new__13->SetBinError(25,24.09706);
   pred_new__13->SetBinError(26,16.09294);
   pred_new__13->SetBinError(27,11.87052);
   pred_new__13->SetBinError(28,4.216704);
   pred_new__13->SetBinError(29,1.64415);
   pred_new__13->SetBinError(30,0.8097961);
   pred_new__13->SetBinError(31,0.3526074);
   pred_new__13->SetBinError(32,0.1199805);
   pred_new__13->SetBinError(33,0.0001668499);
   pred_new__13->SetBinError(34,3.952125e-05);
   pred_new__13->SetBinError(35,5.897287e-06);
   pred_new__13->SetEntries(438);
   pred_new__13->SetLineColor(2);
   pred_new__13->SetMarkerColor(2);
   pred_new__13->SetMarkerStyle(21);
   pred_new__13->GetXaxis()->SetTitle("Mass [GeV]");
   pred_new__13->GetXaxis()->SetRange(1,400);
   pred_new__13->GetXaxis()->SetLabelFont(42);
   pred_new__13->GetXaxis()->SetLabelSize(0.035);
   pred_new__13->GetXaxis()->SetTitleSize(0.035);
   pred_new__13->GetXaxis()->SetTitleFont(42);
   pred_new__13->GetYaxis()->SetLabelFont(42);
   pred_new__13->GetYaxis()->SetLabelSize(0.035);
   pred_new__13->GetYaxis()->SetTitleSize(0.035);
   pred_new__13->GetYaxis()->SetTitleOffset(0);
   pred_new__13->GetYaxis()->SetTitleFont(42);
   pred_new__13->GetZaxis()->SetLabelFont(42);
   pred_new__13->GetZaxis()->SetLabelSize(0.035);
   pred_new__13->GetZaxis()->SetTitleSize(0.035);
   pred_new__13->GetZaxis()->SetTitleFont(42);
   pred_new__13->Draw("same HIST P");
   Double_t xAxis10[36] = {0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000, 2500, 3200, 4000}; 
   
   TH1F *obs_new__14 = new TH1F("obs_new__14","",35, xAxis10);
   obs_new__14->SetBinContent(1,2918);
   obs_new__14->SetBinContent(2,9090);
   obs_new__14->SetBinContent(3,31975);
   obs_new__14->SetBinContent(4,53656);
   obs_new__14->SetBinContent(5,49862);
   obs_new__14->SetBinContent(6,40320);
   obs_new__14->SetBinContent(7,33812);
   obs_new__14->SetBinContent(8,27816);
   obs_new__14->SetBinContent(9,22248);
   obs_new__14->SetBinContent(10,16310);
   obs_new__14->SetBinContent(11,11263);
   obs_new__14->SetBinContent(12,7555);
   obs_new__14->SetBinContent(13,5199);
   obs_new__14->SetBinContent(14,3638);
   obs_new__14->SetBinContent(15,2624);
   obs_new__14->SetBinContent(16,1848);
   obs_new__14->SetBinContent(17,1391);
   obs_new__14->SetBinContent(18,958);
   obs_new__14->SetBinContent(19,777);
   obs_new__14->SetBinContent(20,770);
   obs_new__14->SetBinContent(21,540);
   obs_new__14->SetBinContent(22,451);
   obs_new__14->SetBinContent(23,347);
   obs_new__14->SetBinContent(24,216);
   obs_new__14->SetBinContent(25,132);
   obs_new__14->SetBinContent(26,82);
   obs_new__14->SetBinContent(27,47);
   obs_new__14->SetBinContent(28,23);
   obs_new__14->SetBinContent(29,11);
   obs_new__14->SetBinContent(30,2);
   obs_new__14->SetBinContent(33,2);
   obs_new__14->SetBinContent(34,1);
   obs_new__14->SetEntries(325884);
   obs_new__14->SetMarkerStyle(20);
   obs_new__14->GetXaxis()->SetTitle("Mass [GeV]");
   obs_new__14->GetXaxis()->SetRange(1,35);
   obs_new__14->GetXaxis()->SetLabelFont(42);
   obs_new__14->GetXaxis()->SetLabelSize(0.035);
   obs_new__14->GetXaxis()->SetTitleSize(0.035);
   obs_new__14->GetXaxis()->SetTitleFont(42);
   obs_new__14->GetYaxis()->SetLabelFont(42);
   obs_new__14->GetYaxis()->SetLabelSize(0.035);
   obs_new__14->GetYaxis()->SetTitleSize(0.035);
   obs_new__14->GetYaxis()->SetTitleOffset(0);
   obs_new__14->GetYaxis()->SetTitleFont(42);
   obs_new__14->GetZaxis()->SetLabelFont(42);
   obs_new__14->GetZaxis()->SetLabelSize(0.035);
   obs_new__14->GetZaxis()->SetTitleSize(0.035);
   obs_new__14->GetZaxis()->SetTitleFont(42);
   obs_new__14->Draw("same E1");
   
   TLegend *leg = new TLegend(0.5,0.6,0.8,0.95,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(43);
   leg->SetTextSize(14);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("NULL","SR(80-90)","h");
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
   
   TH1D *frameR2__15 = new TH1D("frameR2__15","",1,0,4000);
   frameR2__15->SetMinimum(0);
   frameR2__15->SetMaximum(2);
   frameR2__15->SetStats(0);
   frameR2__15->SetLineStyle(0);
   frameR2__15->SetMarkerStyle(20);
   frameR2__15->GetXaxis()->SetNdivisions(505);
   frameR2__15->GetXaxis()->SetLabelFont(43);
   frameR2__15->GetXaxis()->SetLabelOffset(0.007);
   frameR2__15->GetXaxis()->SetLabelSize(20);
   frameR2__15->GetXaxis()->SetTitleSize(20);
   frameR2__15->GetXaxis()->SetTitleOffset(3.75);
   frameR2__15->GetXaxis()->SetTitleFont(43);
   frameR2__15->GetYaxis()->SetTitle("obs / pred");
   frameR2__15->GetYaxis()->SetNdivisions(503);
   frameR2__15->GetYaxis()->SetLabelFont(43);
   frameR2__15->GetYaxis()->SetLabelOffset(0.007);
   frameR2__15->GetYaxis()->SetLabelSize(12);
   frameR2__15->GetYaxis()->SetTitleSize(14);
   frameR2__15->GetYaxis()->SetTitleOffset(1.25);
   frameR2__15->GetYaxis()->SetTitleFont(43);
   frameR2__15->GetZaxis()->SetLabelFont(42);
   frameR2__15->GetZaxis()->SetLabelOffset(0.007);
   frameR2__15->GetZaxis()->SetLabelSize(0.05);
   frameR2__15->GetZaxis()->SetTitleSize(0.06);
   frameR2__15->GetZaxis()->SetTitleFont(42);
   frameR2__15->Draw("AXIS");
   Double_t xAxis11[36] = {0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000, 2500, 3200, 4000}; 
   
   TH1F *obs_new__16 = new TH1F("obs_new__16","",35, xAxis11);
   obs_new__16->SetBinContent(1,1.166836);
   obs_new__16->SetBinContent(2,1.063233);
   obs_new__16->SetBinContent(3,1.095256);
   obs_new__16->SetBinContent(4,1.088421);
   obs_new__16->SetBinContent(5,1.066536);
   obs_new__16->SetBinContent(6,1.059404);
   obs_new__16->SetBinContent(7,1.024934);
   obs_new__16->SetBinContent(8,1.006147);
   obs_new__16->SetBinContent(9,1.05174);
   obs_new__16->SetBinContent(10,1.037245);
   obs_new__16->SetBinContent(11,1.064058);
   obs_new__16->SetBinContent(12,1.064172);
   obs_new__16->SetBinContent(13,0.9605362);
   obs_new__16->SetBinContent(14,1.024251);
   obs_new__16->SetBinContent(15,1.014926);
   obs_new__16->SetBinContent(16,1.019499);
   obs_new__16->SetBinContent(17,1.110816);
   obs_new__16->SetBinContent(18,1.011032);
   obs_new__16->SetBinContent(19,1.060979);
   obs_new__16->SetBinContent(20,1.05223);
   obs_new__16->SetBinContent(21,1.081089);
   obs_new__16->SetBinContent(22,1.050408);
   obs_new__16->SetBinContent(23,1.107893);
   obs_new__16->SetBinContent(24,1.064877);
   obs_new__16->SetBinContent(25,1.086291);
   obs_new__16->SetBinContent(26,1.046146);
   obs_new__16->SetBinContent(27,1.248327);
   obs_new__16->SetBinContent(28,1.441976);
   obs_new__16->SetBinContent(29,1.67675);
   obs_new__16->SetBinContent(30,0.7529026);
   obs_new__16->SetBinContent(33,24.26877);
   obs_new__16->SetBinContent(34,56.21943);
   obs_new__16->SetBinError(1,0.1114393);
   obs_new__16->SetBinError(2,0.02018551);
   obs_new__16->SetBinError(3,0.00956737);
   obs_new__16->SetBinError(4,0.01056617);
   obs_new__16->SetBinError(5,0.02648029);
   obs_new__16->SetBinError(6,0.02474962);
   obs_new__16->SetBinError(7,0.0201484);
   obs_new__16->SetBinError(8,0.04921099);
   obs_new__16->SetBinError(9,0.0541317);
   obs_new__16->SetBinError(10,0.03058825);
   obs_new__16->SetBinError(11,0.05601159);
   obs_new__16->SetBinError(12,0.07436251);
   obs_new__16->SetBinError(13,0.08030746);
   obs_new__16->SetBinError(14,0.07144813);
   obs_new__16->SetBinError(15,0.05835625);
   obs_new__16->SetBinError(16,0.0939165);
   obs_new__16->SetBinError(17,0.1040253);
   obs_new__16->SetBinError(18,0.1004489);
   obs_new__16->SetBinError(19,0.1329445);
   obs_new__16->SetBinError(20,0.1265602);
   obs_new__16->SetBinError(21,0.1529644);
   obs_new__16->SetBinError(22,0.1477686);
   obs_new__16->SetBinError(23,0.163494);
   obs_new__16->SetBinError(24,0.1980331);
   obs_new__16->SetBinError(25,0.2352543);
   obs_new__16->SetBinError(26,0.2438844);
   obs_new__16->SetBinError(27,0.4336561);
   obs_new__16->SetBinError(28,0.4855131);
   obs_new__16->SetBinError(29,0.6574056);
   obs_new__16->SetBinError(30,0.579751);
   obs_new__16->SetBinError(33,17.16068);
   obs_new__16->SetBinError(34,56.21957);
   obs_new__16->SetEntries(3.699731);
   obs_new__16->SetMarkerStyle(21);
   obs_new__16->SetMarkerSize(0.7);
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
   obs_new__16->Draw("same E0");
   TLine *line = new TLine(0,1,4000,1);
   line->SetLineStyle(3);
   line->Draw();
   t3->Modified();
   c1->cd();
  
// ------------>Primitives in pad: t4
   TPad *t4 = new TPad("t4", "t4",0,0,0.95,0.25);
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
   
   TH1D *frameR3__17 = new TH1D("frameR3__17","",1,0,4000);
   frameR3__17->SetMinimum(-3);
   frameR3__17->SetMaximum(3);
   frameR3__17->SetStats(0);
   frameR3__17->SetLineStyle(0);
   frameR3__17->SetMarkerStyle(20);
   frameR3__17->GetXaxis()->SetTitle("Mass (GeV)");
   frameR3__17->GetXaxis()->SetLabelFont(43);
   frameR3__17->GetXaxis()->SetLabelOffset(0.007);
   frameR3__17->GetXaxis()->SetLabelSize(14);
   frameR3__17->GetXaxis()->SetTitleSize(20);
   frameR3__17->GetXaxis()->SetTitleOffset(3.75);
   frameR3__17->GetXaxis()->SetTitleFont(43);
   frameR3__17->GetYaxis()->SetTitle("#frac{Data-pred}{#sigma}");
   frameR3__17->GetYaxis()->SetNdivisions(503);
   frameR3__17->GetYaxis()->SetLabelFont(43);
   frameR3__17->GetYaxis()->SetLabelOffset(0.007);
   frameR3__17->GetYaxis()->SetLabelSize(12);
   frameR3__17->GetYaxis()->SetTitleSize(16);
   frameR3__17->GetYaxis()->SetTickLength(0.06);
   frameR3__17->GetYaxis()->SetTitleOffset(1.25);
   frameR3__17->GetYaxis()->SetTitleFont(43);
   frameR3__17->GetZaxis()->SetLabelFont(42);
   frameR3__17->GetZaxis()->SetLabelOffset(0.007);
   frameR3__17->GetZaxis()->SetLabelSize(0.05);
   frameR3__17->GetZaxis()->SetTitleSize(0.06);
   frameR3__17->GetZaxis()->SetTitleFont(42);
   frameR3__17->Draw("AXIS");
   Double_t xAxis12[36] = {0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 410, 440, 480, 530, 590, 660, 760, 880, 1030, 1210, 1440, 1730, 2000, 2500, 3200, 4000}; 
   
   TH1F *pred_new__18 = new TH1F("pred_new__18","",35, xAxis12);
   pred_new__18->SetBinContent(1,1.741428);
   pred_new__18->SetBinContent(2,3.299017);
   pred_new__18->SetBinContent(3,10.69795);
   pred_new__18->SetBinContent(4,9.029671);
   pred_new__18->SetBinContent(5,2.676948);
   pred_new__18->SetBinContent(6,2.539358);
   pred_new__18->SetBinContent(7,1.267184);
   pred_new__18->SetBinContent(8,0.1256652);
   pred_new__18->SetBinContent(9,1.004839);
   pred_new__18->SetBinContent(10,1.261309);
   pred_new__18->SetBinContent(11,1.215666);
   pred_new__18->SetBinContent(12,0.9175459);
   pred_new__18->SetBinContent(13,-0.4722719);
   pred_new__18->SetBinContent(14,0.3474185);
   pred_new__18->SetBinContent(15,0.2593736);
   pred_new__18->SetBinContent(16,0.211533);
   pred_new__18->SetBinContent(17,1.177985);
   pred_new__18->SetBinContent(18,0.1109716);
   pred_new__18->SetBinContent(19,0.4854414);
   pred_new__18->SetBinContent(20,0.4332309);
   pred_new__18->SetBinContent(21,0.5709693);
   pred_new__18->SetBinContent(22,0.3573178);
   pred_new__18->SetBinContent(23,0.725958);
   pred_new__18->SetBinContent(24,0.3473558);
   pred_new__18->SetBinContent(25,0.3957019);
   pred_new__18->SetBinContent(26,0.1969256);
   pred_new__18->SetBinContent(27,0.6996826);
   pred_new__18->SetBinContent(28,1.213819);
   pred_new__18->SetBinContent(29,1.458694);
   pred_new__18->SetBinContent(30,-0.360665);
   pred_new__18->SetBinContent(31,-0.8488914);
   pred_new__18->SetBinContent(32,-0.4584589);
   pred_new__18->SetBinContent(33,6.679815);
   pred_new__18->SetBinContent(34,7.364592);
   pred_new__18->SetBinContent(35,-0.05037786);
   pred_new__18->SetBinError(1,234.3084);
   pred_new__18->SetBinError(2,135.2913);
   pred_new__18->SetBinError(3,195.9066);
   pred_new__18->SetBinError(4,428.6409);
   pred_new__18->SetBinError(5,1141.719);
   pred_new__18->SetBinError(6,868.6938);
   pred_new__18->SetBinError(7,623.2041);
   pred_new__18->SetBinError(8,1341.98);
   pred_new__18->SetBinError(9,1079.467);
   pred_new__18->SetBinError(10,447.0648);
   pred_new__18->SetBinError(11,548.1883);
   pred_new__18->SetBinError(12,489.3248);
   pred_new__18->SetBinError(13,446.2614);
   pred_new__18->SetBinError(14,240.6655);
   pred_new__18->SetBinError(15,139.8256);
   pred_new__18->SetBinError(16,161.5708);
   pred_new__18->SetBinError(17,112.3595);
   pred_new__18->SetBinError(18,89.02478);
   pred_new__18->SetBinError(19,87.92375);
   pred_new__18->SetBinError(20,83.97336);
   pred_new__18->SetBinError(21,67.32614);
   pred_new__18->SetBinError(22,56.9166);
   pred_new__18->SetBinError(23,43.05391);
   pred_new__18->SetBinError(24,35.10631);
   pred_new__18->SetBinError(25,24.09706);
   pred_new__18->SetBinError(26,16.09294);
   pred_new__18->SetBinError(27,11.87052);
   pred_new__18->SetBinError(28,4.216704);
   pred_new__18->SetBinError(29,1.64415);
   pred_new__18->SetBinError(30,0.8097961);
   pred_new__18->SetBinError(31,0.3526074);
   pred_new__18->SetBinError(32,0.1199805);
   pred_new__18->SetBinError(33,0.0001668499);
   pred_new__18->SetBinError(34,3.952125e-05);
   pred_new__18->SetBinError(35,5.897287e-06);
   pred_new__18->SetEntries(473);
   pred_new__18->SetFillColor(38);
   pred_new__18->GetXaxis()->SetTitle("Mass [GeV]");
   pred_new__18->GetXaxis()->SetRange(1,400);
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
   pred_new__18->Draw("same HIST");
   
   TH1D *frameR3_copy__19 = new TH1D("frameR3_copy__19","",1,0,4000);
   frameR3_copy__19->SetMinimum(-3);
   frameR3_copy__19->SetMaximum(3);
   frameR3_copy__19->SetDirectory(0);
   frameR3_copy__19->SetStats(0);
   frameR3_copy__19->SetLineStyle(0);
   frameR3_copy__19->SetMarkerStyle(20);
   frameR3_copy__19->GetXaxis()->SetTitle("Mass (GeV)");
   frameR3_copy__19->GetXaxis()->SetLabelFont(43);
   frameR3_copy__19->GetXaxis()->SetLabelOffset(0.007);
   frameR3_copy__19->GetXaxis()->SetLabelSize(14);
   frameR3_copy__19->GetXaxis()->SetTitleSize(20);
   frameR3_copy__19->GetXaxis()->SetTitleOffset(3.75);
   frameR3_copy__19->GetXaxis()->SetTitleFont(43);
   frameR3_copy__19->GetYaxis()->SetTitle("#frac{Data-pred}{#sigma}");
   frameR3_copy__19->GetYaxis()->SetNdivisions(503);
   frameR3_copy__19->GetYaxis()->SetLabelFont(43);
   frameR3_copy__19->GetYaxis()->SetLabelOffset(0.007);
   frameR3_copy__19->GetYaxis()->SetLabelSize(12);
   frameR3_copy__19->GetYaxis()->SetTitleSize(16);
   frameR3_copy__19->GetYaxis()->SetTickLength(0.06);
   frameR3_copy__19->GetYaxis()->SetTitleOffset(1.25);
   frameR3_copy__19->GetYaxis()->SetTitleFont(43);
   frameR3_copy__19->GetZaxis()->SetLabelFont(42);
   frameR3_copy__19->GetZaxis()->SetLabelOffset(0.007);
   frameR3_copy__19->GetZaxis()->SetLabelSize(0.05);
   frameR3_copy__19->GetZaxis()->SetTitleSize(0.06);
   frameR3_copy__19->GetZaxis()->SetTitleFont(42);
   frameR3_copy__19->Draw("sameaxis");
   
   TH1D *frameR3_copy__20 = new TH1D("frameR3_copy__20","",1,0,4000);
   frameR3_copy__20->SetMinimum(-3);
   frameR3_copy__20->SetMaximum(3);
   frameR3_copy__20->SetDirectory(0);
   frameR3_copy__20->SetStats(0);
   frameR3_copy__20->SetLineStyle(0);
   frameR3_copy__20->SetMarkerStyle(20);
   frameR3_copy__20->GetXaxis()->SetTitle("Mass (GeV)");
   frameR3_copy__20->GetXaxis()->SetLabelFont(43);
   frameR3_copy__20->GetXaxis()->SetLabelOffset(0.007);
   frameR3_copy__20->GetXaxis()->SetLabelSize(14);
   frameR3_copy__20->GetXaxis()->SetTitleSize(20);
   frameR3_copy__20->GetXaxis()->SetTitleOffset(3.75);
   frameR3_copy__20->GetXaxis()->SetTitleFont(43);
   frameR3_copy__20->GetYaxis()->SetTitle("#frac{Data-pred}{#sigma}");
   frameR3_copy__20->GetYaxis()->SetNdivisions(503);
   frameR3_copy__20->GetYaxis()->SetLabelFont(43);
   frameR3_copy__20->GetYaxis()->SetLabelOffset(0.007);
   frameR3_copy__20->GetYaxis()->SetLabelSize(12);
   frameR3_copy__20->GetYaxis()->SetTitleSize(16);
   frameR3_copy__20->GetYaxis()->SetTickLength(0.06);
   frameR3_copy__20->GetYaxis()->SetTitleOffset(1.25);
   frameR3_copy__20->GetYaxis()->SetTitleFont(43);
   frameR3_copy__20->GetZaxis()->SetLabelFont(42);
   frameR3_copy__20->GetZaxis()->SetLabelOffset(0.007);
   frameR3_copy__20->GetZaxis()->SetLabelSize(0.05);
   frameR3_copy__20->GetZaxis()->SetTitleSize(0.06);
   frameR3_copy__20->GetZaxis()->SetTitleFont(42);
   frameR3_copy__20->Draw("sameaxig");
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
