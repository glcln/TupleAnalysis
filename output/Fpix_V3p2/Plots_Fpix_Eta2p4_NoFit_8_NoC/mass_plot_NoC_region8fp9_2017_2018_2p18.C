void mass_plot_NoC_region8fp9_2017_2018_2p18()
{
//=========Macro generated from canvas: c1/c1
//=========  (Tue May 13 14:10:17 2025) by ROOT version 6.14/09
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
   pred_new__13->SetBinContent(1,280.3193);
   pred_new__13->SetBinContent(2,976.565);
   pred_new__13->SetBinContent(3,1073.055);
   pred_new__13->SetBinContent(4,915.9171);
   pred_new__13->SetBinContent(5,759.8992);
   pred_new__13->SetBinContent(6,580.2087);
   pred_new__13->SetBinContent(7,459.6114);
   pred_new__13->SetBinContent(8,376.4216);
   pred_new__13->SetBinContent(9,296.4292);
   pred_new__13->SetBinContent(10,242.5459);
   pred_new__13->SetBinContent(11,201.1622);
   pred_new__13->SetBinContent(12,171.5632);
   pred_new__13->SetBinContent(13,135.531);
   pred_new__13->SetBinContent(14,115.7865);
   pred_new__13->SetBinContent(15,93.70778);
   pred_new__13->SetBinContent(16,80.8329);
   pred_new__13->SetBinContent(17,68.08804);
   pred_new__13->SetBinContent(18,48.97922);
   pred_new__13->SetBinContent(19,48.25222);
   pred_new__13->SetBinContent(20,53.39867);
   pred_new__13->SetBinContent(21,40.10362);
   pred_new__13->SetBinContent(22,39.26965);
   pred_new__13->SetBinContent(23,36.66173);
   pred_new__13->SetBinContent(24,22.30715);
   pred_new__13->SetBinContent(25,16.26169);
   pred_new__13->SetBinContent(26,11.52701);
   pred_new__13->SetBinContent(27,6.957576);
   pred_new__13->SetBinContent(28,3.411278);
   pred_new__13->SetBinContent(29,1.576481);
   pred_new__13->SetBinContent(30,0.7016932);
   pred_new__13->SetBinContent(31,0.4017936);
   pred_new__13->SetBinContent(32,0.1880017);
   pred_new__13->SetBinContent(33,0.1297573);
   pred_new__13->SetBinContent(34,0.06509919);
   pred_new__13->SetBinContent(35,0.008424601);
   pred_new__13->SetBinError(1,67.62968);
   pred_new__13->SetBinError(2,71.76902);
   pred_new__13->SetBinError(3,72.61024);
   pred_new__13->SetBinError(4,54.10522);
   pred_new__13->SetBinError(5,42.97857);
   pred_new__13->SetBinError(6,33.9105);
   pred_new__13->SetBinError(7,27.47199);
   pred_new__13->SetBinError(8,32.0577);
   pred_new__13->SetBinError(9,28.64456);
   pred_new__13->SetBinError(10,19.7129);
   pred_new__13->SetBinError(11,24.80241);
   pred_new__13->SetBinError(12,15.02019);
   pred_new__13->SetBinError(13,15.76372);
   pred_new__13->SetBinError(14,15.31613);
   pred_new__13->SetBinError(15,13.18662);
   pred_new__13->SetBinError(16,13.51735);
   pred_new__13->SetBinError(17,16.62238);
   pred_new__13->SetBinError(18,20.36481);
   pred_new__13->SetBinError(19,20.77564);
   pred_new__13->SetBinError(20,12.79762);
   pred_new__13->SetBinError(21,9.532463);
   pred_new__13->SetBinError(22,10.85865);
   pred_new__13->SetBinError(23,13.05624);
   pred_new__13->SetBinError(24,9.257593);
   pred_new__13->SetBinError(25,7.521038);
   pred_new__13->SetBinError(26,6.077054);
   pred_new__13->SetBinError(27,3.62764);
   pred_new__13->SetBinError(28,1.559506);
   pred_new__13->SetBinError(29,0.8784549);
   pred_new__13->SetBinError(30,0.1995681);
   pred_new__13->SetBinError(31,0.1388314);
   pred_new__13->SetBinError(32,0.1121185);
   pred_new__13->SetBinError(33,0.08638209);
   pred_new__13->SetBinError(34,0.04235337);
   pred_new__13->SetBinError(35,0.005657255);
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
   pred_noSyst_new__14->SetBinContent(1,280.3193);
   pred_noSyst_new__14->SetBinContent(2,976.565);
   pred_noSyst_new__14->SetBinContent(3,1073.055);
   pred_noSyst_new__14->SetBinContent(4,915.9171);
   pred_noSyst_new__14->SetBinContent(5,759.8992);
   pred_noSyst_new__14->SetBinContent(6,580.2087);
   pred_noSyst_new__14->SetBinContent(7,459.6114);
   pred_noSyst_new__14->SetBinContent(8,376.4216);
   pred_noSyst_new__14->SetBinContent(9,296.4292);
   pred_noSyst_new__14->SetBinContent(10,242.5459);
   pred_noSyst_new__14->SetBinContent(11,201.1622);
   pred_noSyst_new__14->SetBinContent(12,171.5632);
   pred_noSyst_new__14->SetBinContent(13,135.531);
   pred_noSyst_new__14->SetBinContent(14,115.7865);
   pred_noSyst_new__14->SetBinContent(15,93.70778);
   pred_noSyst_new__14->SetBinContent(16,80.8329);
   pred_noSyst_new__14->SetBinContent(17,68.08804);
   pred_noSyst_new__14->SetBinContent(18,48.97922);
   pred_noSyst_new__14->SetBinContent(19,48.25222);
   pred_noSyst_new__14->SetBinContent(20,53.39867);
   pred_noSyst_new__14->SetBinContent(21,40.10362);
   pred_noSyst_new__14->SetBinContent(22,39.26965);
   pred_noSyst_new__14->SetBinContent(23,36.66173);
   pred_noSyst_new__14->SetBinContent(24,22.30715);
   pred_noSyst_new__14->SetBinContent(25,16.26169);
   pred_noSyst_new__14->SetBinContent(26,11.52701);
   pred_noSyst_new__14->SetBinContent(27,6.957576);
   pred_noSyst_new__14->SetBinContent(28,3.411278);
   pred_noSyst_new__14->SetBinContent(29,1.576481);
   pred_noSyst_new__14->SetBinContent(30,0.7016932);
   pred_noSyst_new__14->SetBinContent(31,0.4017936);
   pred_noSyst_new__14->SetBinContent(32,0.1880017);
   pred_noSyst_new__14->SetBinContent(33,0.1297573);
   pred_noSyst_new__14->SetBinContent(34,0.06509919);
   pred_noSyst_new__14->SetBinContent(35,0.008424601);
   pred_noSyst_new__14->SetBinError(1,24.06486);
   pred_noSyst_new__14->SetBinError(2,55.5925);
   pred_noSyst_new__14->SetBinError(3,54.69362);
   pred_noSyst_new__14->SetBinError(4,43.43976);
   pred_noSyst_new__14->SetBinError(5,34.58955);
   pred_noSyst_new__14->SetBinError(6,26.39979);
   pred_noSyst_new__14->SetBinError(7,21.70368);
   pred_noSyst_new__14->SetBinError(8,18.63671);
   pred_noSyst_new__14->SetBinError(9,15.41509);
   pred_noSyst_new__14->SetBinError(10,13.13056);
   pred_noSyst_new__14->SetBinError(11,11.31912);
   pred_noSyst_new__14->SetBinError(12,9.826301);
   pred_noSyst_new__14->SetBinError(13,7.928753);
   pred_noSyst_new__14->SetBinError(14,6.959535);
   pred_noSyst_new__14->SetBinError(15,5.786765);
   pred_noSyst_new__14->SetBinError(16,5.098546);
   pred_noSyst_new__14->SetBinError(17,4.468708);
   pred_noSyst_new__14->SetBinError(18,3.270918);
   pred_noSyst_new__14->SetBinError(19,3.290046);
   pred_noSyst_new__14->SetBinError(20,3.068832);
   pred_noSyst_new__14->SetBinError(21,2.374838);
   pred_noSyst_new__14->SetBinError(22,2.170243);
   pred_noSyst_new__14->SetBinError(23,1.872757);
   pred_noSyst_new__14->SetBinError(24,1.173151);
   pred_noSyst_new__14->SetBinError(25,0.8344593);
   pred_noSyst_new__14->SetBinError(26,0.5510586);
   pred_noSyst_new__14->SetBinError(27,0.3516845);
   pred_noSyst_new__14->SetBinError(28,0.197293);
   pred_noSyst_new__14->SetBinError(29,0.1150363);
   pred_noSyst_new__14->SetBinError(30,0.07774957);
   pred_noSyst_new__14->SetBinError(31,0.06259153);
   pred_noSyst_new__14->SetBinError(32,0.04442652);
   pred_noSyst_new__14->SetBinError(33,0.03209924);
   pred_noSyst_new__14->SetBinError(34,0.01656058);
   pred_noSyst_new__14->SetBinError(35,0.002777728);
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
   pred_new__15->SetBinContent(1,280.3193);
   pred_new__15->SetBinContent(2,976.565);
   pred_new__15->SetBinContent(3,1073.055);
   pred_new__15->SetBinContent(4,915.9171);
   pred_new__15->SetBinContent(5,759.8992);
   pred_new__15->SetBinContent(6,580.2087);
   pred_new__15->SetBinContent(7,459.6114);
   pred_new__15->SetBinContent(8,376.4216);
   pred_new__15->SetBinContent(9,296.4292);
   pred_new__15->SetBinContent(10,242.5459);
   pred_new__15->SetBinContent(11,201.1622);
   pred_new__15->SetBinContent(12,171.5632);
   pred_new__15->SetBinContent(13,135.531);
   pred_new__15->SetBinContent(14,115.7865);
   pred_new__15->SetBinContent(15,93.70778);
   pred_new__15->SetBinContent(16,80.8329);
   pred_new__15->SetBinContent(17,68.08804);
   pred_new__15->SetBinContent(18,48.97922);
   pred_new__15->SetBinContent(19,48.25222);
   pred_new__15->SetBinContent(20,53.39867);
   pred_new__15->SetBinContent(21,40.10362);
   pred_new__15->SetBinContent(22,39.26965);
   pred_new__15->SetBinContent(23,36.66173);
   pred_new__15->SetBinContent(24,22.30715);
   pred_new__15->SetBinContent(25,16.26169);
   pred_new__15->SetBinContent(26,11.52701);
   pred_new__15->SetBinContent(27,6.957576);
   pred_new__15->SetBinContent(28,3.411278);
   pred_new__15->SetBinContent(29,1.576481);
   pred_new__15->SetBinContent(30,0.7016932);
   pred_new__15->SetBinContent(31,0.4017936);
   pred_new__15->SetBinContent(32,0.1880017);
   pred_new__15->SetBinContent(33,0.1297573);
   pred_new__15->SetBinContent(34,0.06509919);
   pred_new__15->SetBinContent(35,0.008424601);
   pred_new__15->SetBinError(1,67.62968);
   pred_new__15->SetBinError(2,71.76902);
   pred_new__15->SetBinError(3,72.61024);
   pred_new__15->SetBinError(4,54.10522);
   pred_new__15->SetBinError(5,42.97857);
   pred_new__15->SetBinError(6,33.9105);
   pred_new__15->SetBinError(7,27.47199);
   pred_new__15->SetBinError(8,32.0577);
   pred_new__15->SetBinError(9,28.64456);
   pred_new__15->SetBinError(10,19.7129);
   pred_new__15->SetBinError(11,24.80241);
   pred_new__15->SetBinError(12,15.02019);
   pred_new__15->SetBinError(13,15.76372);
   pred_new__15->SetBinError(14,15.31613);
   pred_new__15->SetBinError(15,13.18662);
   pred_new__15->SetBinError(16,13.51735);
   pred_new__15->SetBinError(17,16.62238);
   pred_new__15->SetBinError(18,20.36481);
   pred_new__15->SetBinError(19,20.77564);
   pred_new__15->SetBinError(20,12.79762);
   pred_new__15->SetBinError(21,9.532463);
   pred_new__15->SetBinError(22,10.85865);
   pred_new__15->SetBinError(23,13.05624);
   pred_new__15->SetBinError(24,9.257593);
   pred_new__15->SetBinError(25,7.521038);
   pred_new__15->SetBinError(26,6.077054);
   pred_new__15->SetBinError(27,3.62764);
   pred_new__15->SetBinError(28,1.559506);
   pred_new__15->SetBinError(29,0.8784549);
   pred_new__15->SetBinError(30,0.1995681);
   pred_new__15->SetBinError(31,0.1388314);
   pred_new__15->SetBinError(32,0.1121185);
   pred_new__15->SetBinError(33,0.08638209);
   pred_new__15->SetBinError(34,0.04235337);
   pred_new__15->SetBinError(35,0.005657255);
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
   pred_new__18->SetBinContent(0,1.072949);
   pred_new__18->SetBinContent(1,1.072949);
   pred_new__18->SetBinContent(2,1.064627);
   pred_new__18->SetBinContent(3,1.088975);
   pred_new__18->SetBinContent(4,1.116219);
   pred_new__18->SetBinContent(5,1.134973);
   pred_new__18->SetBinContent(6,1.154155);
   pred_new__18->SetBinContent(7,1.189402);
   pred_new__18->SetBinContent(8,1.205339);
   pred_new__18->SetBinContent(9,1.21612);
   pred_new__18->SetBinContent(10,1.23661);
   pred_new__18->SetBinContent(11,1.244076);
   pred_new__18->SetBinContent(12,1.234295);
   pred_new__18->SetBinContent(13,1.24007);
   pred_new__18->SetBinContent(14,1.269212);
   pred_new__18->SetBinContent(15,1.309289);
   pred_new__18->SetBinContent(16,1.331602);
   pred_new__18->SetBinContent(17,1.353288);
   pred_new__18->SetBinContent(18,1.368863);
   pred_new__18->SetBinContent(19,1.38325);
   pred_new__18->SetBinContent(20,1.429371);
   pred_new__18->SetBinContent(21,1.486877);
   pred_new__18->SetBinContent(22,1.527239);
   pred_new__18->SetBinContent(23,1.606824);
   pred_new__18->SetBinContent(24,1.510956);
   pred_new__18->SetBinContent(25,1.503803);
   pred_new__18->SetBinContent(26,1.602108);
   pred_new__18->SetBinContent(27,1.264871);
   pred_new__18->SetBinContent(28,1.696869);
   pred_new__18->SetBinContent(29,1.302401);
   pred_new__18->SetBinError(0,0.02769094);
   pred_new__18->SetBinError(1,0.02769094);
   pred_new__18->SetBinError(2,0.0265156);
   pred_new__18->SetBinError(3,0.02807758);
   pred_new__18->SetBinError(4,0.02995195);
   pred_new__18->SetBinError(5,0.03305044);
   pred_new__18->SetBinError(6,0.03736633);
   pred_new__18->SetBinError(7,0.0431249);
   pred_new__18->SetBinError(8,0.04952065);
   pred_new__18->SetBinError(9,0.05506778);
   pred_new__18->SetBinError(10,0.06131846);
   pred_new__18->SetBinError(11,0.06975733);
   pred_new__18->SetBinError(12,0.07574139);
   pred_new__18->SetBinError(13,0.08729168);
   pred_new__18->SetBinError(14,0.1008696);
   pred_new__18->SetBinError(15,0.1177818);
   pred_new__18->SetBinError(16,0.1362643);
   pred_new__18->SetBinError(17,0.1577537);
   pred_new__18->SetBinError(18,0.177158);
   pred_new__18->SetBinError(19,0.1822978);
   pred_new__18->SetBinError(20,0.1842323);
   pred_new__18->SetBinError(21,0.2183922);
   pred_new__18->SetBinError(22,0.2626617);
   pred_new__18->SetBinError(23,0.3319474);
   pred_new__18->SetBinError(24,0.3666414);
   pred_new__18->SetBinError(25,0.4274806);
   pred_new__18->SetBinError(26,0.532867);
   pred_new__18->SetBinError(27,0.4896535);
   pred_new__18->SetBinError(28,0.6977271);
   pred_new__18->SetBinError(29,0.759863);
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
   obs_new__20->SetBinContent(1,1.277115);
   obs_new__20->SetBinContent(2,0.9175016);
   obs_new__20->SetBinContent(3,0.9664);
   obs_new__20->SetBinContent(4,1.03612);
   obs_new__20->SetBinContent(5,1.055403);
   obs_new__20->SetBinContent(6,0.9979167);
   obs_new__20->SetBinContent(7,1.11616);
   obs_new__20->SetBinContent(8,1.155619);
   obs_new__20->SetBinContent(9,1.116624);
   obs_new__20->SetBinContent(10,1.199773);
   obs_new__20->SetBinContent(11,1.292489);
   obs_new__20->SetBinContent(12,1.206553);
   obs_new__20->SetBinContent(13,1.092001);
   obs_new__20->SetBinContent(14,1.070937);
   obs_new__20->SetBinContent(15,1.195205);
   obs_new__20->SetBinContent(16,1.224749);
   obs_new__20->SetBinContent(17,1.277758);
   obs_new__20->SetBinContent(18,1.28626);
   obs_new__20->SetBinContent(19,1.160568);
   obs_new__20->SetBinContent(20,1.235986);
   obs_new__20->SetBinContent(21,1.346512);
   obs_new__20->SetBinContent(22,1.324178);
   obs_new__20->SetBinContent(23,1.772966);
   obs_new__20->SetBinContent(24,1.524175);
   obs_new__20->SetBinContent(25,1.352873);
   obs_new__20->SetBinContent(26,1.995314);
   obs_new__20->SetBinContent(27,0.8623694);
   obs_new__20->SetBinContent(28,2.052017);
   obs_new__20->SetBinContent(29,2.537297);
   obs_new__20->SetBinError(1,0.3154226);
   obs_new__20->SetBinError(2,0.07406825);
   obs_new__20->SetBinError(3,0.07195056);
   obs_new__20->SetBinError(4,0.06983835);
   obs_new__20->SetBinError(5,0.0703703);
   obs_new__20->SetBinError(6,0.07156513);
   obs_new__20->SetBinError(7,0.08294233);
   obs_new__20->SetBinError(8,0.1129426);
   obs_new__20->SetBinError(9,0.1241358);
   obs_new__20->SetBinError(10,0.1202292);
   obs_new__20->SetBinError(11,0.178382);
   obs_new__20->SetBinError(12,0.1348738);
   obs_new__20->SetBinError(13,0.1555286);
   obs_new__20->SetBinError(14,0.1712236);
   obs_new__20->SetBinError(15,0.2025894);
   obs_new__20->SetBinError(16,0.2389531);
   obs_new__20->SetBinError(17,0.3406944);
   obs_new__20->SetBinError(18,0.5588202);
   obs_new__20->SetBinError(19,0.5232115);
   obs_new__20->SetBinError(20,0.3330042);
   obs_new__20->SetBinError(21,0.3688012);
   obs_new__20->SetBinError(22,0.4096215);
   obs_new__20->SetBinError(23,0.6686013);
   obs_new__20->SetBinError(24,0.6844232);
   obs_new__20->SetBinError(25,0.6889847);
   obs_new__20->SetBinError(26,1.131221);
   obs_new__20->SetBinError(27,0.5710673);
   obs_new__20->SetBinError(28,1.217201);
   obs_new__20->SetBinError(29,1.899586);
   obs_new__20->SetEntries(147.973);
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
   pred_new__22->SetBinContent(1,1.114959);
   pred_new__22->SetBinContent(2,-1.029224);
   pred_new__22->SetBinContent(3,-0.452622);
   pred_new__22->SetBinContent(4,0.5336441);
   pred_new__22->SetBinContent(5,0.8245471);
   pred_new__22->SetBinContent(6,-0.02905986);
   pred_new__22->SetBinContent(7,1.532082);
   pred_new__22->SetBinContent(8,1.563275);
   pred_new__22->SetBinContent(9,1.034414);
   pred_new__22->SetBinContent(10,1.928706);
   pred_new__22->SetBinContent(11,2.059327);
   pred_new__22->SetBinContent(12,1.778145);
   pred_new__22->SetBinContent(13,0.6362857);
   pred_new__22->SetBinContent(14,0.4387993);
   pred_new__22->SetBinContent(15,1.118221);
   pred_new__22->SetBinContent(16,1.119058);
   pred_new__22->SetBinContent(17,1.019085);
   pred_new__22->SetBinContent(18,0.6511057);
   pred_new__22->SetBinContent(19,0.3536804);
   pred_new__22->SetBinContent(20,0.8550842);
   pred_new__22->SetBinContent(21,1.214264);
   pred_new__22->SetBinContent(22,1.015411);
   pred_new__22->SetBinContent(23,1.969041);
   pred_new__22->SetBinContent(24,1.125092);
   pred_new__22->SetBinContent(25,0.6724126);
   pred_new__22->SetBinContent(26,1.648146);
   pred_new__22->SetBinContent(27,-0.2134951);
   pred_new__22->SetBinContent(28,1.484599);
   pred_new__22->SetBinContent(29,1.581547);
   pred_new__22->SetBinContent(30,-0.814865);
   pred_new__22->SetBinContent(31,-0.6191944);
   pred_new__22->SetBinContent(32,-0.4197845);
   pred_new__22->SetBinContent(33,-0.3502873);
   pred_new__22->SetBinContent(34,-0.2517012);
   pred_new__22->SetBinContent(35,-0.09161177);
   pred_new__22->SetBinError(1,67.62968);
   pred_new__22->SetBinError(2,71.76902);
   pred_new__22->SetBinError(3,72.61024);
   pred_new__22->SetBinError(4,54.10522);
   pred_new__22->SetBinError(5,42.97857);
   pred_new__22->SetBinError(6,33.9105);
   pred_new__22->SetBinError(7,27.47199);
   pred_new__22->SetBinError(8,32.0577);
   pred_new__22->SetBinError(9,28.64456);
   pred_new__22->SetBinError(10,19.7129);
   pred_new__22->SetBinError(11,24.80241);
   pred_new__22->SetBinError(12,15.02019);
   pred_new__22->SetBinError(13,15.76372);
   pred_new__22->SetBinError(14,15.31613);
   pred_new__22->SetBinError(15,13.18662);
   pred_new__22->SetBinError(16,13.51735);
   pred_new__22->SetBinError(17,16.62238);
   pred_new__22->SetBinError(18,20.36481);
   pred_new__22->SetBinError(19,20.77564);
   pred_new__22->SetBinError(20,12.79762);
   pred_new__22->SetBinError(21,9.532463);
   pred_new__22->SetBinError(22,10.85865);
   pred_new__22->SetBinError(23,13.05624);
   pred_new__22->SetBinError(24,9.257593);
   pred_new__22->SetBinError(25,7.521038);
   pred_new__22->SetBinError(26,6.077054);
   pred_new__22->SetBinError(27,3.62764);
   pred_new__22->SetBinError(28,1.559506);
   pred_new__22->SetBinError(29,0.8784549);
   pred_new__22->SetBinError(30,0.1995681);
   pred_new__22->SetBinError(31,0.1388314);
   pred_new__22->SetBinError(32,0.1121185);
   pred_new__22->SetBinError(33,0.08638209);
   pred_new__22->SetBinError(34,0.04235337);
   pred_new__22->SetBinError(35,0.005657255);
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
