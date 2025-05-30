void mass_plot_NoC_region8fp9_2017_2018_3p2()
{
//=========Macro generated from canvas: c1/c1
//=========  (Tue May 13 17:24:00 2025) by ROOT version 6.14/09
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
   pred_new__13->SetBinContent(1,212.17);
   pred_new__13->SetBinContent(2,970.7791);
   pred_new__13->SetBinContent(3,1052.914);
   pred_new__13->SetBinContent(4,954.3486);
   pred_new__13->SetBinContent(5,734.9473);
   pred_new__13->SetBinContent(6,632.7654);
   pred_new__13->SetBinContent(7,415.5552);
   pred_new__13->SetBinContent(8,470.0375);
   pred_new__13->SetBinContent(9,218.9709);
   pred_new__13->SetBinContent(10,193.9733);
   pred_new__13->SetBinContent(11,225.0691);
   pred_new__13->SetBinContent(12,196.5539);
   pred_new__13->SetBinContent(13,106.6334);
   pred_new__13->SetBinContent(14,182.0241);
   pred_new__13->SetBinContent(15,9.032637);
   pred_new__13->SetBinContent(16,135.9829);
   pred_new__13->SetBinContent(17,33.08488);
   pred_new__13->SetBinContent(18,110.1941);
   pred_new__13->SetBinContent(19,14.93564);
   pred_new__13->SetBinContent(20,43.59269);
   pred_new__13->SetBinContent(21,56.16457);
   pred_new__13->SetBinContent(22,34.21167);
   pred_new__13->SetBinContent(23,36.43483);
   pred_new__13->SetBinContent(24,24.47875);
   pred_new__13->SetBinContent(25,11.51213);
   pred_new__13->SetBinContent(26,14.6574);
   pred_new__13->SetBinContent(27,5.168866);
   pred_new__13->SetBinContent(28,4.058104);
   pred_new__13->SetBinContent(29,1.995009);
   pred_new__13->SetBinContent(30,0.8741885);
   pred_new__13->SetBinContent(31,0.4506491);
   pred_new__13->SetBinContent(32,0.3069458);
   pred_new__13->SetBinContent(33,0.134003);
   pred_new__13->SetBinContent(34,0.02244494);
   pred_new__13->SetBinContent(35,0.00100653);
   pred_new__13->SetBinError(1,51.21879);
   pred_new__13->SetBinError(2,66.81537);
   pred_new__13->SetBinError(3,65.68538);
   pred_new__13->SetBinError(4,51.93794);
   pred_new__13->SetBinError(5,39.23066);
   pred_new__13->SetBinError(6,36.23766);
   pred_new__13->SetBinError(7,25.54838);
   pred_new__13->SetBinError(8,41.07919);
   pred_new__13->SetBinError(9,23.10371);
   pred_new__13->SetBinError(10,17.16253);
   pred_new__13->SetBinError(11,29.21578);
   pred_new__13->SetBinError(12,18.85032);
   pred_new__13->SetBinError(13,12.88028);
   pred_new__13->SetBinError(14,25.27689);
   pred_new__13->SetBinError(15,1.322023);
   pred_new__13->SetBinError(16,24.78383);
   pred_new__13->SetBinError(17,8.322754);
   pred_new__13->SetBinError(18,46.25578);
   pred_new__13->SetBinError(19,6.496672);
   pred_new__13->SetBinError(20,10.59118);
   pred_new__13->SetBinError(21,13.73239);
   pred_new__13->SetBinError(22,9.582587);
   pred_new__13->SetBinError(23,13.06909);
   pred_new__13->SetBinError(24,10.23896);
   pred_new__13->SetBinError(25,5.358762);
   pred_new__13->SetBinError(26,7.779541);
   pred_new__13->SetBinError(27,2.723499);
   pred_new__13->SetBinError(28,1.87964);
   pred_new__13->SetBinError(29,1.119914);
   pred_new__13->SetBinError(30,0.2740874);
   pred_new__13->SetBinError(31,0.17598);
   pred_new__13->SetBinError(32,0.1865517);
   pred_new__13->SetBinError(33,0.0890124);
   pred_new__13->SetBinError(34,0.01476443);
   pred_new__13->SetBinError(35,0.0008669921);
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
   pred_noSyst_new__14->SetBinContent(1,212.17);
   pred_noSyst_new__14->SetBinContent(2,970.7791);
   pred_noSyst_new__14->SetBinContent(3,1052.914);
   pred_noSyst_new__14->SetBinContent(4,954.3486);
   pred_noSyst_new__14->SetBinContent(5,734.9473);
   pred_noSyst_new__14->SetBinContent(6,632.7654);
   pred_noSyst_new__14->SetBinContent(7,415.5552);
   pred_noSyst_new__14->SetBinContent(8,470.0375);
   pred_noSyst_new__14->SetBinContent(9,218.9709);
   pred_noSyst_new__14->SetBinContent(10,193.9733);
   pred_noSyst_new__14->SetBinContent(11,225.0691);
   pred_noSyst_new__14->SetBinContent(12,196.5539);
   pred_noSyst_new__14->SetBinContent(13,106.6334);
   pred_noSyst_new__14->SetBinContent(14,182.0241);
   pred_noSyst_new__14->SetBinContent(15,9.032637);
   pred_noSyst_new__14->SetBinContent(16,135.9829);
   pred_noSyst_new__14->SetBinContent(17,33.08488);
   pred_noSyst_new__14->SetBinContent(18,110.1941);
   pred_noSyst_new__14->SetBinContent(19,14.93564);
   pred_noSyst_new__14->SetBinContent(20,43.59269);
   pred_noSyst_new__14->SetBinContent(21,56.16457);
   pred_noSyst_new__14->SetBinContent(22,34.21167);
   pred_noSyst_new__14->SetBinContent(23,36.43483);
   pred_noSyst_new__14->SetBinContent(24,24.47875);
   pred_noSyst_new__14->SetBinContent(25,11.51213);
   pred_noSyst_new__14->SetBinContent(26,14.6574);
   pred_noSyst_new__14->SetBinContent(27,5.168866);
   pred_noSyst_new__14->SetBinContent(28,4.058104);
   pred_noSyst_new__14->SetBinContent(29,1.995009);
   pred_noSyst_new__14->SetBinContent(30,0.8741885);
   pred_noSyst_new__14->SetBinContent(31,0.4506491);
   pred_noSyst_new__14->SetBinContent(32,0.3069458);
   pred_noSyst_new__14->SetBinContent(33,0.134003);
   pred_noSyst_new__14->SetBinContent(34,0.02244494);
   pred_noSyst_new__14->SetBinContent(35,0.00100653);
   pred_noSyst_new__14->SetBinError(1,18.30064);
   pred_noSyst_new__14->SetBinError(2,49.27848);
   pred_noSyst_new__14->SetBinError(3,46.02751);
   pred_noSyst_new__14->SetBinError(4,39.5986);
   pred_noSyst_new__14->SetBinError(5,30.50174);
   pred_noSyst_new__14->SetBinError(6,27.82831);
   pred_noSyst_new__14->SetBinError(7,20.51422);
   pred_noSyst_new__14->SetBinError(8,25.03265);
   pred_noSyst_new__14->SetBinError(9,14.68733);
   pred_noSyst_new__14->SetBinError(10,12.50134);
   pred_noSyst_new__14->SetBinError(11,15.61677);
   pred_noSyst_new__14->SetBinError(12,13.63636);
   pred_noSyst_new__14->SetBinError(13,7.140866);
   pred_noSyst_new__14->SetBinError(14,13.37439);
   pred_noSyst_new__14->SetBinError(15,0.6657637);
   pred_noSyst_new__14->SetBinError(16,13.0654);
   pred_noSyst_new__14->SetBinError(17,2.957154);
   pred_noSyst_new__14->SetBinError(18,9.723761);
   pred_noSyst_new__14->SetBinError(19,1.374571);
   pred_noSyst_new__14->SetBinError(20,3.049462);
   pred_noSyst_new__14->SetBinError(21,4.627688);
   pred_noSyst_new__14->SetBinError(22,2.430705);
   pred_noSyst_new__14->SetBinError(23,2.42967);
   pred_noSyst_new__14->SetBinError(24,1.814376);
   pred_noSyst_new__14->SetBinError(25,0.8464172);
   pred_noSyst_new__14->SetBinError(26,1.139975);
   pred_noSyst_new__14->SetBinError(27,0.4718003);
   pred_noSyst_new__14->SetBinError(28,0.3825264);
   pred_noSyst_new__14->SetBinError(29,0.1989761);
   pred_noSyst_new__14->SetBinError(30,0.1506342);
   pred_noSyst_new__14->SetBinError(31,0.1079395);
   pred_noSyst_new__14->SetBinError(32,0.08095883);
   pred_noSyst_new__14->SetBinError(33,0.03261793);
   pred_noSyst_new__14->SetBinError(34,0.006111725);
   pred_noSyst_new__14->SetBinError(35,0.0006363726);
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
   pred_new__15->SetBinContent(1,212.17);
   pred_new__15->SetBinContent(2,970.7791);
   pred_new__15->SetBinContent(3,1052.914);
   pred_new__15->SetBinContent(4,954.3486);
   pred_new__15->SetBinContent(5,734.9473);
   pred_new__15->SetBinContent(6,632.7654);
   pred_new__15->SetBinContent(7,415.5552);
   pred_new__15->SetBinContent(8,470.0375);
   pred_new__15->SetBinContent(9,218.9709);
   pred_new__15->SetBinContent(10,193.9733);
   pred_new__15->SetBinContent(11,225.0691);
   pred_new__15->SetBinContent(12,196.5539);
   pred_new__15->SetBinContent(13,106.6334);
   pred_new__15->SetBinContent(14,182.0241);
   pred_new__15->SetBinContent(15,9.032637);
   pred_new__15->SetBinContent(16,135.9829);
   pred_new__15->SetBinContent(17,33.08488);
   pred_new__15->SetBinContent(18,110.1941);
   pred_new__15->SetBinContent(19,14.93564);
   pred_new__15->SetBinContent(20,43.59269);
   pred_new__15->SetBinContent(21,56.16457);
   pred_new__15->SetBinContent(22,34.21167);
   pred_new__15->SetBinContent(23,36.43483);
   pred_new__15->SetBinContent(24,24.47875);
   pred_new__15->SetBinContent(25,11.51213);
   pred_new__15->SetBinContent(26,14.6574);
   pred_new__15->SetBinContent(27,5.168866);
   pred_new__15->SetBinContent(28,4.058104);
   pred_new__15->SetBinContent(29,1.995009);
   pred_new__15->SetBinContent(30,0.8741885);
   pred_new__15->SetBinContent(31,0.4506491);
   pred_new__15->SetBinContent(32,0.3069458);
   pred_new__15->SetBinContent(33,0.134003);
   pred_new__15->SetBinContent(34,0.02244494);
   pred_new__15->SetBinContent(35,0.00100653);
   pred_new__15->SetBinError(1,51.21879);
   pred_new__15->SetBinError(2,66.81537);
   pred_new__15->SetBinError(3,65.68538);
   pred_new__15->SetBinError(4,51.93794);
   pred_new__15->SetBinError(5,39.23066);
   pred_new__15->SetBinError(6,36.23766);
   pred_new__15->SetBinError(7,25.54838);
   pred_new__15->SetBinError(8,41.07919);
   pred_new__15->SetBinError(9,23.10371);
   pred_new__15->SetBinError(10,17.16253);
   pred_new__15->SetBinError(11,29.21578);
   pred_new__15->SetBinError(12,18.85032);
   pred_new__15->SetBinError(13,12.88028);
   pred_new__15->SetBinError(14,25.27689);
   pred_new__15->SetBinError(15,1.322023);
   pred_new__15->SetBinError(16,24.78383);
   pred_new__15->SetBinError(17,8.322754);
   pred_new__15->SetBinError(18,46.25578);
   pred_new__15->SetBinError(19,6.496672);
   pred_new__15->SetBinError(20,10.59118);
   pred_new__15->SetBinError(21,13.73239);
   pred_new__15->SetBinError(22,9.582587);
   pred_new__15->SetBinError(23,13.06909);
   pred_new__15->SetBinError(24,10.23896);
   pred_new__15->SetBinError(25,5.358762);
   pred_new__15->SetBinError(26,7.779541);
   pred_new__15->SetBinError(27,2.723499);
   pred_new__15->SetBinError(28,1.87964);
   pred_new__15->SetBinError(29,1.119914);
   pred_new__15->SetBinError(30,0.2740874);
   pred_new__15->SetBinError(31,0.17598);
   pred_new__15->SetBinError(32,0.1865517);
   pred_new__15->SetBinError(33,0.0890124);
   pred_new__15->SetBinError(34,0.01476443);
   pred_new__15->SetBinError(35,0.0008669921);
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
   pred_new__18->SetBinContent(0,1.081076);
   pred_new__18->SetBinContent(1,1.081076);
   pred_new__18->SetBinContent(2,1.062412);
   pred_new__18->SetBinContent(3,1.085274);
   pred_new__18->SetBinContent(4,1.106986);
   pred_new__18->SetBinContent(5,1.134441);
   pred_new__18->SetBinContent(6,1.14443);
   pred_new__18->SetBinContent(7,1.20144);
   pred_new__18->SetBinContent(8,1.194993);
   pred_new__18->SetBinContent(9,1.27129);
   pred_new__18->SetBinContent(10,1.234784);
   pred_new__18->SetBinContent(11,1.193516);
   pred_new__18->SetBinContent(12,1.20195);
   pred_new__18->SetBinContent(13,1.237362);
   pred_new__18->SetBinContent(14,1.215041);
   pred_new__18->SetBinContent(15,1.395885);
   pred_new__18->SetBinContent(16,1.207737);
   pred_new__18->SetBinContent(17,1.374026);
   pred_new__18->SetBinContent(18,1.258376);
   pred_new__18->SetBinContent(19,1.562256);
   pred_new__18->SetBinContent(20,1.422692);
   pred_new__18->SetBinContent(21,1.401791);
   pred_new__18->SetBinContent(22,1.585931);
   pred_new__18->SetBinContent(23,1.608483);
   pred_new__18->SetBinContent(24,1.508023);
   pred_new__18->SetBinContent(25,1.58241);
   pred_new__18->SetBinContent(26,1.445681);
   pred_new__18->SetBinContent(27,1.306565);
   pred_new__18->SetBinContent(28,1.402641);
   pred_new__18->SetBinContent(29,1.057014);
   pred_new__18->SetBinError(0,0.02736762);
   pred_new__18->SetBinError(1,0.02736762);
   pred_new__18->SetBinError(2,0.02653731);
   pred_new__18->SetBinError(3,0.02847741);
   pred_new__18->SetBinError(4,0.03115078);
   pred_new__18->SetBinError(5,0.03564313);
   pred_new__18->SetBinError(6,0.04090521);
   pred_new__18->SetBinError(7,0.04935156);
   pred_new__18->SetBinError(8,0.05594604);
   pred_new__18->SetBinError(9,0.06755115);
   pred_new__18->SetBinError(10,0.07223972);
   pred_new__18->SetBinError(11,0.07828272);
   pred_new__18->SetBinError(12,0.08834013);
   pred_new__18->SetBinError(13,0.1070826);
   pred_new__18->SetBinError(14,0.1178518);
   pred_new__18->SetBinError(15,0.1647583);
   pred_new__18->SetBinError(16,0.1459);
   pred_new__18->SetBinError(17,0.2014082);
   pred_new__18->SetBinError(18,0.199323);
   pred_new__18->SetBinError(19,0.1955479);
   pred_new__18->SetBinError(20,0.1857921);
   pred_new__18->SetBinError(21,0.2073154);
   pred_new__18->SetBinError(22,0.2778702);
   pred_new__18->SetBinError(23,0.3368725);
   pred_new__18->SetBinError(24,0.3735353);
   pred_new__18->SetBinError(25,0.4539798);
   pred_new__18->SetBinError(26,0.5012008);
   pred_new__18->SetBinError(27,0.4743328);
   pred_new__18->SetBinError(28,0.5803116);
   pred_new__18->SetBinError(29,0.623538);
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
   obs_new__20->SetBinContent(1,1.687326);
   obs_new__20->SetBinContent(2,0.92297);
   obs_new__20->SetBinContent(3,0.9848858);
   obs_new__20->SetBinContent(4,0.9943955);
   obs_new__20->SetBinContent(5,1.091235);
   obs_new__20->SetBinContent(6,0.9150311);
   obs_new__20->SetBinContent(7,1.234493);
   obs_new__20->SetBinContent(8,0.9254581);
   obs_new__20->SetBinContent(9,1.511616);
   obs_new__20->SetBinContent(10,1.500207);
   obs_new__20->SetBinContent(11,1.155201);
   obs_new__20->SetBinContent(12,1.053146);
   obs_new__20->SetBinContent(13,1.387933);
   obs_new__20->SetBinContent(14,0.6812285);
   obs_new__20->SetBinContent(15,12.39948);
   obs_new__20->SetBinContent(16,0.7280328);
   obs_new__20->SetBinContent(17,2.6296);
   obs_new__20->SetBinContent(18,0.5717184);
   obs_new__20->SetBinContent(19,3.749421);
   obs_new__20->SetBinContent(20,1.514015);
   obs_new__20->SetBinContent(21,0.9614602);
   obs_new__20->SetBinContent(22,1.519949);
   obs_new__20->SetBinContent(23,1.784007);
   obs_new__20->SetBinContent(24,1.38896);
   obs_new__20->SetBinContent(25,1.911027);
   obs_new__20->SetBinContent(26,1.569174);
   obs_new__20->SetBinContent(27,1.160796);
   obs_new__20->SetBinContent(28,1.724944);
   obs_new__20->SetBinContent(29,2.005004);
   obs_new__20->SetBinError(1,0.4169757);
   obs_new__20->SetBinError(2,0.07061272);
   obs_new__20->SetBinError(3,0.06863269);
   obs_new__20->SetBinError(4,0.06301313);
   obs_new__20->SetBinError(5,0.06984062);
   obs_new__20->SetBinError(6,0.06474658);
   obs_new__20->SetBinError(7,0.09343996);
   obs_new__20->SetBinError(8,0.09225307);
   obs_new__20->SetBinError(9,0.1798353);
   obs_new__20->SetBinError(10,0.1592265);
   obs_new__20->SetBinError(11,0.1661896);
   obs_new__20->SetBinError(12,0.1247368);
   obs_new__20->SetBinError(13,0.2027859);
   obs_new__20->SetBinError(14,0.1126567);
   obs_new__20->SetBinError(15,2.160146);
   obs_new__20->SetBinError(16,0.1515263);
   obs_new__20->SetBinError(17,0.7190669);
   obs_new__20->SetBinError(18,0.2505646);
   obs_new__20->SetBinError(19,1.706142);
   obs_new__20->SetBinError(20,0.4123572);
   obs_new__20->SetBinError(21,0.2690372);
   obs_new__20->SetBinError(22,0.4750542);
   obs_new__20->SetBinError(23,0.6770978);
   obs_new__20->SetBinError(24,0.6279104);
   obs_new__20->SetBinError(25,0.978427);
   obs_new__20->SetBinError(26,0.8948186);
   obs_new__20->SetBinError(27,0.7737341);
   obs_new__20->SetBinError(28,1.031214);
   obs_new__20->SetBinError(29,1.507254);
   obs_new__20->SetEntries(171.5185);
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
   pred_new__22->SetBinContent(1,2.738605);
   pred_new__22->SetBinContent(2,-1.014326);
   pred_new__22->SetBinContent(3,-0.2172163);
   pred_new__22->SetBinContent(4,-0.08850818);
   pred_new__22->SetBinContent(5,1.406119);
   pred_new__22->SetBinContent(6,-1.218818);
   pred_new__22->SetBinContent(7,2.98138);
   pred_new__22->SetBinContent(8,-0.7543166);
   pred_new__22->SetBinContent(9,4.083238);
   pred_new__22->SetBinContent(10,4.389829);
   pred_new__22->SetBinContent(11,1.063588);
   pred_new__22->SetBinContent(12,0.444662);
   pred_new__22->SetBinContent(13,2.505758);
   pred_new__22->SetBinContent(14,-2.025123);
   pred_new__22->SetBinContent(15,31.36047);
   pred_new__22->SetBinContent(16,-1.350225);
   pred_new__22->SetBinContent(17,5.329175);
   pred_new__22->SetBinContent(18,-0.9949853);
   pred_new__22->SetBinContent(19,5.432326);
   pred_new__22->SetBinContent(20,1.79537);
   pred_new__22->SetBinContent(21,-0.1383621);
   pred_new__22->SetBinContent(22,1.584473);
   pred_new__22->SetBinContent(23,1.984286);
   pred_new__22->SetBinContent(24,0.8372773);
   pred_new__22->SetBinContent(25,1.653562);
   pred_new__22->SetBinContent(26,0.9621756);
   pred_new__22->SetBinContent(27,0.2342727);
   pred_new__22->SetBinContent(28,1.06776);
   pred_new__22->SetBinContent(29,1.112303);
   pred_new__22->SetBinContent(30,-0.8972232);
   pred_new__22->SetBinContent(31,-0.6493623);
   pred_new__22->SetBinContent(32,-0.5250602);
   pred_new__22->SetBinContent(33,-0.3556995);
   pred_new__22->SetBinContent(34,-0.1490941);
   pred_new__22->SetBinContent(35,-0.03171402);
   pred_new__22->SetBinError(1,51.21879);
   pred_new__22->SetBinError(2,66.81537);
   pred_new__22->SetBinError(3,65.68538);
   pred_new__22->SetBinError(4,51.93794);
   pred_new__22->SetBinError(5,39.23066);
   pred_new__22->SetBinError(6,36.23766);
   pred_new__22->SetBinError(7,25.54838);
   pred_new__22->SetBinError(8,41.07919);
   pred_new__22->SetBinError(9,23.10371);
   pred_new__22->SetBinError(10,17.16253);
   pred_new__22->SetBinError(11,29.21578);
   pred_new__22->SetBinError(12,18.85032);
   pred_new__22->SetBinError(13,12.88028);
   pred_new__22->SetBinError(14,25.27689);
   pred_new__22->SetBinError(15,1.322023);
   pred_new__22->SetBinError(16,24.78383);
   pred_new__22->SetBinError(17,8.322754);
   pred_new__22->SetBinError(18,46.25578);
   pred_new__22->SetBinError(19,6.496672);
   pred_new__22->SetBinError(20,10.59118);
   pred_new__22->SetBinError(21,13.73239);
   pred_new__22->SetBinError(22,9.582587);
   pred_new__22->SetBinError(23,13.06909);
   pred_new__22->SetBinError(24,10.23896);
   pred_new__22->SetBinError(25,5.358762);
   pred_new__22->SetBinError(26,7.779541);
   pred_new__22->SetBinError(27,2.723499);
   pred_new__22->SetBinError(28,1.87964);
   pred_new__22->SetBinError(29,1.119914);
   pred_new__22->SetBinError(30,0.2740874);
   pred_new__22->SetBinError(31,0.17598);
   pred_new__22->SetBinError(32,0.1865517);
   pred_new__22->SetBinError(33,0.0890124);
   pred_new__22->SetBinError(34,0.01476443);
   pred_new__22->SetBinError(35,0.0008669921);
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
