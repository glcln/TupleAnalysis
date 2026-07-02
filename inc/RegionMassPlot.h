#ifndef RegionMassPlot_h
#define RegionMassPlot_h


#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TH3F.h>
#include <TProfile.h>
#include <TCanvas.h>
#include <TMath.h>
#include <iostream>

#include "PlotTools.h"
#include "MassTools.h"

class RegionMassPlot{

    public:
        RegionMassPlot(std::string suffix,int etabins,int ihbins,int pbins,int massbins,int fpixbins, float C_parameter);
        ~RegionMassPlot();
       
        //Methods
	void initHisto();
        void initHisto(int& etabins,int& ihbins,int& pbins,int& massbins,int& fpixbins, float& C_parameter);
        void fill(float eta, float nhits, float p, float pt, float pterr, float ih, float ias, float m, float npv, float fpix, float w);
        void OneOverPreweighting(TH2F* ih_p_1, TH1F* p2);
        void fillMassFrom1DTemplatesEtaBinning(float weight_);
        void plotMass();
        void write();
        void addToList(TList* list);	

	//Data members
	std::string suffix_;
       
	//Plots binning
	int nbins;
        float* xbins;
        int np;
        double* xp;
        float plow;
        float pup;
        int npt;
        float ptlow;
        float ptup;
        int nih;
        float ihlow;
        float ihup;
        int nias;
        float iaslow;
        float iasup;
        int neta;
        float etalow;
        float etaup;
        int nmass;
        float masslow;
        float massup;
        int nfpix;
        float fpixlow;
        float fpixup;
        
        //List of all histos 
	TCanvas* c;
        TH2F* ih_pt;
        TH2F* ias_pt;
        TH2F* ih_ias;
        TH2F* ih_fpix;
        TH2F* eta_fpix;
        TH2F* oP_fpix;
        TH2F* ih_nhits;
        TH2F* ias_nhits;
        TH2F* eta_pt;
        TH2F* eta_1oP;
        TH2F* eta_p;
        TH2F* eta_pterrOpt;
        TH2F* nhits_pt;
        TH2F* eta_nhits;
        TH2F* ih_eta;
        TH2F* ih_p;
        TH2F* ias_p;
        TH2F* pt_pterroverpt;
        TH2F* ias_eta;
        TH2F* mass_eta;
        TH2F* eta_npv;
        TH2F* p_npv;
        TH2F* ih_npv;
        TH2F* mass_p;
        TH2F* mass_ih;
	TH1F* mass;
        TH1F* massFrom1DTemplates;
        TH1F* massFrom1DTemplatesEtaBinning;
        TH1F* pred_mass;
        TH2F* eta_p_rebinned;

        //vector histogram
        TH1F* errMass;
        TH2F* Mass_errMass;
        TH2F* cross1Dtemplates;
        TH1F* ih_used;
        TH2F* mapM800;
        TH1F* momentumDistribM1000;
        TH1F* dedxDistribM1000;
};

#endif
