#include "RegionMassPlot.h"

float K(2.54), C(3.14); //Data

float K_data2018(2.55), C_data2018(3.14); //Data 2018
float K_data2017(2.54), C_data2017(3.14);

RegionMassPlot::RegionMassPlot(std::string suffix,int etabins,int ihbins,int pbins,int massbins,int fpixbins, float C_parameter)
{

    xbins=0;
    xp=0;
    c=0;
    ih_pt=0;
    ias_pt=0;
    ih_ias=0;
    ih_fpix=0;
    eta_fpix=0;
    oP_fpix=0;
    ih_nhits=0;
    ias_nhits=0;
    eta_pt=0;
    eta_1oP=0;
    eta_p=0;
    eta_pterrOpt=0;
    eta_p_rebinned=0; 
    nhits_pt=0;
    eta_nhits=0;
    ih_eta=0;
    ih_p=0;
    ias_p=0;
    pt_pterroverpt=0;
    ias_eta=0;
    mass_eta=0;
    eta_npv=0;
    p_npv=0;
    ih_npv=0;
    mass=0;
    mass_ih=0;
    mass_p=0;
    massFrom1DTemplates=0;
    massFrom1DTemplatesEtaBinning=0;
    pred_mass=0;
    errMass=0;
    Mass_errMass=0;
    cross1Dtemplates=0;
    ih_used=0;
    mapM800=0;
    momentumDistribM1000=0;
    dedxDistribM1000=0;
    suffix_ = suffix;
    std::cout << "init"+suffix << " with eta bins : " << etabins << " , ih bins : " << ihbins << " , p bins : " << pbins << " , and mass bins : " << massbins << std::endl;

    initHisto(etabins,ihbins,pbins,massbins,fpixbins,C_parameter);

} 

RegionMassPlot::~RegionMassPlot(){
    if(!xbins) delete xbins;
    if(!xp) delete xp;
    if(!c) delete c;
    if(!ih_pt) delete ih_pt;
    if(!ias_pt) delete ias_pt;
    if(!ih_ias) delete ih_ias;
    if(!ih_fpix) delete ih_fpix;
    if(!eta_fpix) delete eta_fpix;
    if(!oP_fpix) delete oP_fpix;
    if(!ih_nhits) delete ih_nhits;
    if(!ias_nhits) delete ias_nhits;
    if(!eta_pt) delete eta_pt;
    if(!eta_1oP) delete eta_1oP;
    if(!eta_p) delete eta_p;
    if(!eta_pterrOpt) delete eta_pterrOpt;
    if(!eta_p_rebinned) delete eta_p_rebinned;
    if(!nhits_pt) delete nhits_pt;
    if(!eta_nhits) delete eta_nhits;
    if(!ih_eta) delete ih_eta;
    if(!ih_p) delete ih_p;
    if(!ias_p) delete ias_p;
    if(!pt_pterroverpt) delete pt_pterroverpt;
    if(!ias_eta) delete ias_eta;
    if(!mass_eta) delete mass_eta;
    if(!eta_npv) delete eta_npv;
    if(!p_npv) delete p_npv;
    if(!ih_npv) delete ih_npv;
    if(!mass) delete mass;
    if(!mass_p) delete mass_p;
    if(!mass_ih) delete mass_ih;
    if(!massFrom1DTemplates) delete massFrom1DTemplates;
    if(!massFrom1DTemplatesEtaBinning) delete massFrom1DTemplatesEtaBinning;
    if(!pred_mass) delete pred_mass;
    if(!errMass) delete errMass;
    if(!Mass_errMass) delete Mass_errMass;
    if(!cross1Dtemplates) delete cross1Dtemplates;
    if(!ih_used) delete ih_used;
    if(!mapM800) delete mapM800;
    if(!momentumDistribM1000) delete momentumDistribM1000;
    if(!dedxDistribM1000) delete dedxDistribM1000;
}

// Function which intializes the histograms with given binnings 
void RegionMassPlot::initHisto(int& etabins,int& ihbins,int& pbins,int& massbins,int& fpixbins, float& C_parameter)
{
    np = pbins;
    plow = 0;
    pup = 200;

    npt = pbins;
    ptlow = 0;
    ptup = 10000; //instead of 4000

    nih = ihbins;
    ihlow = C_parameter;
    ihup = C_parameter + 5;

    nias = ihbins;
    iaslow = 0;
    iasup = 1;

    neta = etabins;
    etalow = -2.4;
    etaup = 2.4;

    nmass = massbins;
    masslow = 0;
    massup = 4000;

    nfpix = fpixbins;
    fpixlow = 0;
    fpixup = 1.;

    std::string suffix = suffix_;
    
    ih_pt = new TH2F(("ih_pt"+suffix).c_str(),";pt [GeV];I_{h} [MeV/cm]",npt,ptlow,ptup,nih,ihlow,ihup); ih_pt->Sumw2();
    ias_pt = new TH2F(("ias_pt"+suffix).c_str(),";pt [GeV];I_{as}",npt,ptlow,ptup,nias,iaslow,iasup); ias_pt->Sumw2();
    ih_ias = new TH2F(("ias_ih"+suffix).c_str(),";I_{as};I_{h} [MeV/cm]",nias,iaslow,iasup,nih,ihlow,ihup); ih_ias->Sumw2();
    ih_fpix = new TH2F(("fpix_ih"+suffix).c_str(),";F^{pix};I_{h} [MeV/cm]",nfpix,fpixlow,fpixup,nih,ihlow,ihup); ih_fpix->Sumw2();
    eta_fpix = new TH2F(("fpix_eta"+suffix).c_str(),";F^{pix};#eta",nfpix,fpixlow,fpixup,neta,etalow,etaup); eta_fpix->Sumw2();
    oP_fpix = new TH2F(("oP_fpix"+suffix).c_str(),";10^{4}/p [GeV];F^{pix}",np,plow,pup,nfpix,fpixlow,fpixup); oP_fpix->Sumw2();
    ih_nhits = new TH2F(("ih_nhits"+suffix).c_str(),";nhits;I_{h} [MeV/cm]",20,0,20,nih,ihlow,ihup); ih_nhits->Sumw2();
    ias_nhits = new TH2F(("ias_nhits"+suffix).c_str(),";nhits;I_{as}",20,0,20,nias,iaslow,iasup); ias_nhits->Sumw2();
    eta_pt = new TH2F(("eta_pt"+suffix).c_str(),";pt [GeV];#eta",npt,ptlow,ptup,neta,etalow,etaup); eta_pt->Sumw2();
    eta_1oP = new TH2F(("eta_1oP"+suffix).c_str(),";10^{4}/p [GeV^{-1}];#eta",np,plow,pup,neta,etalow,etaup); eta_1oP->Sumw2();
    eta_p = new TH2F(("eta_p"+suffix).c_str(),";p [GeV];#eta",npt,ptlow,ptup,neta,etalow,etaup); eta_p->Sumw2();
    eta_pterrOpt = new TH2F(("eta_pterrOpt"+suffix).c_str(),";#eta;#frac{#sigma_{pT}}{p_{T}}",neta,etalow,etaup,np,0,1); eta_pterrOpt->Sumw2();
    eta_p_rebinned = nullptr; 
    nhits_pt = new TH2F(("nhits_pt"+suffix).c_str(),";pt [GeV];nhits",npt,ptlow,ptup,20,0,20); nhits_pt->Sumw2();
    eta_nhits = new TH2F(("eta_nhits"+suffix).c_str(),";nhits;#eta",20,0,20,neta,etalow,etaup); eta_nhits->Sumw2();
    ih_eta = new TH2F(("ih_eta"+suffix).c_str(),";#eta;I_{h} [MeV/cm]",neta,etalow,etaup,nih,ihlow,ihup); ih_eta->Sumw2();
    ih_p = new TH2F(("ih_p"+suffix).c_str(),";10^{4}/p [GeV^{-1}];I_{h} [MeV/cm]",np,plow,pup,nih,ihlow,ihup); ih_p->Sumw2();
    ias_p = new TH2F(("ias_p"+suffix).c_str(),";10^{4}/p [GeV^{-1}];I_{as}",np,plow,pup,nias,iaslow,iasup); ias_p->Sumw2();
    pt_pterroverpt = new TH2F(("pt_pterroverpt"+suffix).c_str(),";p_{T} [GeV];#frac{#sigma_{pT}}{p_{T}}",npt,ptlow,ptup,100,0,1); pt_pterroverpt->Sumw2();
    ias_eta = new TH2F(("ias_eta"+suffix).c_str(),";#eta;I_{as}",neta,etalow,etaup,nias,iaslow,iasup); ias_eta->Sumw2();
    mass_eta = new TH2F(("mass_eta"+suffix).c_str(),";#eta;Mass [GeV]",neta,etalow,etaup,nmass,masslow,massup); mass_eta->Sumw2();
    eta_npv = new TH2F(("eta_npv"+suffix).c_str(),";npv;#eta",100,0,100,neta,etalow,etaup); eta_npv->Sumw2();
    p_npv = new TH2F(("p_npv"+suffix).c_str(),";npv;p [GeV]",100,0,100,np,plow,pup); p_npv->Sumw2();
    ih_npv = new TH2F(("ih_npv"+suffix).c_str(),";npv;I_{h} [MeV/cm]",100,0,100,nih,ihlow,ihup); ih_npv->Sumw2();
    mass = new TH1F(("mass"+suffix).c_str(),";Mass [GeV]",nmass,masslow,massup); mass->Sumw2();
    mass_p = new TH2F(("mass_p"+suffix).c_str(),";Mass [GeV]",np,plow,pup,nmass,masslow,massup); mass_p->Sumw2();
    mass_ih = new TH2F(("mass_ih"+suffix).c_str(),";Mass [GeV]",nih,ihlow,ihup,nmass,masslow,massup); mass_ih->Sumw2();
    massFrom1DTemplates = new TH1F(("massFrom1DTemplates"+suffix).c_str(),";Mass [GeV]",nmass,masslow,massup); massFrom1DTemplates->Sumw2();
    massFrom1DTemplatesEtaBinning = new TH1F(("massFrom1DTemplatesEtaBinning"+suffix).c_str(),";Mass [GeV]",nmass,masslow,massup); massFrom1DTemplatesEtaBinning->Sumw2();
    pred_mass = new TH1F(("pred_mass"+suffix).c_str(),";Mass [GeV]",nmass,masslow,massup); pred_mass->Sumw2();
   
    mass->SetBinErrorOption(TH1::EBinErrorOpt::kPoisson);
    massFrom1DTemplates->SetBinErrorOption(TH1::EBinErrorOpt::kPoisson);
    massFrom1DTemplatesEtaBinning->SetBinErrorOption(TH1::EBinErrorOpt::kPoisson);
    pred_mass->SetBinErrorOption(TH1::EBinErrorOpt::kPoisson);

    errMass = new TH1F(("errMass"+suffix).c_str(),";Mass error [GeV]",nmass,masslow,massup); errMass->Sumw2();
    Mass_errMass = new TH2F(("Mass_errMass"+suffix).c_str(),";Mass [GeV];Mass error [GeV]",nmass,masslow,massup,nmass,masslow,massup); Mass_errMass->Sumw2();
    cross1Dtemplates = new TH2F(("cross1Dtemplates_ih_p_"+suffix).c_str(),";p [GeV];I_{h} [MeV/cm]",np,plow,pup,nih,ihlow,ihup); cross1Dtemplates->Sumw2();

    ih_used         = new TH1F(("ih_used"+suffix).c_str(),";I_{h} [MeV/cm];",nih,ihlow,ihup); ih_used->Sumw2();
    mapM800         = new TH2F(("mapM800_ih_p_"+suffix).c_str(),";p [GeV];I_{h} [MeV/cm]",np,plow,pup,nih,ihlow,ihup); mapM800->Sumw2();

    momentumDistribM1000    = new TH1F(("momentumDistribM1000_"+suffix).c_str(),";p [GeV]",np,plow,pup); momentumDistribM1000->Sumw2();
    dedxDistribM1000    = new TH1F(("dedxDistribM1000_"+suffix).c_str(),";I_{h} [MeV/cm]",nih,ihlow,ihup); dedxDistribM1000->Sumw2();

}

// Function which fills histograms
void RegionMassPlot::fill(float eta, float nhits, float p, float pt, float pterr, float ih, float ias, float m, float npv, float fpix, float w)
{
   ih_pt->Fill(pt,ih,w);
   ias_pt->Fill(pt,ias,w);
   ih_ias->Fill(ias,ih,w);
   ih_fpix->Fill(fpix,ih,w);
   eta_fpix->Fill(fpix,eta,w);
   oP_fpix->Fill(p,fpix,w);
   ih_nhits->Fill(nhits,ih,w);
   ias_nhits->Fill(nhits,ias,w);
   eta_pt->Fill(pt,eta,w);
   eta_1oP->Fill(p,eta,w);
   eta_p->Fill(pt*cosh(eta),eta,w);
   eta_pterrOpt->Fill(eta,pterr/pt,w);
   nhits_pt->Fill(pt,nhits,w);
   eta_nhits->Fill(nhits,eta,w);
   ih_eta->Fill(eta,ih,w);
  
   ih_p->Fill(p,ih,w);
   ias_p->Fill(p,ias,w);
   mass->Fill(m,w);
   mass_p->Fill(p,m,w);
   mass_ih->Fill(ih,m,w);
   mass_eta->Fill(eta,m,w);

   pt_pterroverpt->Fill(pt,pterr/pt,w);
   ias_eta->Fill(eta,ias,w);
   eta_npv->Fill(npv,eta,w);
   p_npv->Fill(npv,p,w);
   ih_npv->Fill(npv,ih,w);
}


void RegionMassPlot::OneOverPreweighting(TH2F* ih_p_1, TH1F* p2)
{
    TH1F* p1 = (TH1F*) ih_p_1->ProjectionX(); 
    p1->Scale(1./p1->Integral());
    p2->Scale(1./p2->Integral());
    p2->Divide(p1);
    for(int i=0;i<ih_p_1->GetNbinsX()+1;i++)
    {
        for(int j=0;j<ih_p_1->GetNbinsY()+1;j++)
        {
            float val_ij = ih_p_1->GetBinContent(i,j);
            float err_ij = ih_p_1->GetBinError(i,j);
            ih_p_1->SetBinContent(i,j,val_ij*p2->GetBinContent(i));
            ih_p_1->SetBinError(i,j,err_ij*p2->GetBinContent(i));
        }
    }
}

    

// in order to compute properly the uncertainties we use the methods SetBinContent SetBinError instead of Fill
// as several couples of bins in (p,ih) can provide the same mass estimate we need to properly sum the entries and errors
// for a couple of bins in (p,ih) where the bin content were (N_p,N_ih) the associated quantities should be 
// content: (N_p * N_ih) / N_total, where N_total represents the total number of events in the RegionMassPlot (integral of p, ih & mass distributions)
// error: content * sqrt( 1 / N_p + 1 / N_ih ) where we assume Poisson uncertainties in both distributions (independent distributions) and we neglect the uncertainty on N_total
// While combining the input for several couples leading to the same mass: 
// contents are added 
// errors: the sqrt of the squared uncertainties are added
// 
    
void RegionMassPlot::cross1D()
{
    crossHistosEtaBinning(cross1Dtemplates,eta_1oP,ih_eta);
}

void RegionMassPlot::plotMass()
{
    c->Divide(1,2);
    c->cd(1);
    scale(mass); scale(massFrom1DTemplates); scale(massFrom1DTemplatesEtaBinning);
    mass->Draw();
    massFrom1DTemplatesEtaBinning->Draw("same");
    massFrom1DTemplatesEtaBinning->SetLineColor(2);
    c->SetLogy();
    c->cd(2);
    TH1F* rat2 = ratioIntegral(massFrom1DTemplatesEtaBinning,mass);
    rat2->Draw();
}

void RegionMassPlot::write()
{
    ih_pt->Write();
    ias_pt->Write();
    ih_ias->Write();
    ih_fpix->Write();
    eta_fpix->Write();
    oP_fpix->Write();
    ih_nhits->Write();
    ias_nhits->Write();
    eta_pt->Write();
    eta_1oP->Write();
    eta_p->Write();
    eta_pterrOpt->Write();
    nhits_pt->Write();
    eta_nhits->Write();
    ih_eta->Write();
    ih_p->Write();
    cross1Dtemplates->Write();
    ias_p->Write();
    pt_pterroverpt->Write();
    ias_eta->Write();
    mass_eta->Write();
    eta_npv->Write();
    p_npv->Write();
    ih_npv->Write();
    mass->Write();
    mass_p->Write();
    mass_ih->Write();
    ih_pt->ProjectionY()->Write();
    ih_p->ProfileX()->Write();
    ias_p->ProfileX()->Write();
    ih_pt->ProfileX()->Write();
    ias_pt->ProfileX()->Write();
}

void RegionMassPlot::addToList(TList* list){
    list->Add(ih_pt);
    list->Add(ias_pt);
    list->Add(ih_ias);
    list->Add(ih_fpix);
    list->Add(eta_fpix);
    list->Add(oP_fpix);
    list->Add(ih_nhits);
    list->Add(ias_nhits);
    list->Add(eta_pt);
    list->Add(eta_1oP);
    list->Add(eta_p);
    list->Add(eta_pterrOpt);
    list->Add(nhits_pt);
    list->Add(eta_nhits);
    list->Add(ih_eta);
    list->Add(ih_p);
    list->Add(cross1Dtemplates);
    list->Add(ias_p);
    list->Add(pt_pterroverpt);
    list->Add(ias_eta);
    list->Add(eta_npv);
    list->Add(p_npv);
    list->Add(ih_npv);
    list->Add(mass);
    list->Add(mass_p);
    list->Add(mass_ih);
    list->Add(mass_eta);
    list->Add(ih_pt->ProjectionY());
    list->Add(ih_p->ProfileX());
    list->Add(ias_p->ProfileX());
    list->Add(ih_pt->ProfileX());
    list->Add(ias_pt->ProfileX());
}

