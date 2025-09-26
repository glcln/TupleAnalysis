#ifndef HSCPSelector_h
#define HSCPSelector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TProof.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>
#include <TEfficiency.h>
#include <TLorentzVector.h>
#include <map>
#include <vector>
#include <iostream>
#include "TObjString.h"

#include "../inc/RegionMassPlot.h"
#include "../inc/CPlots.h"

using namespace std;


class HSCPSelector : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   TTree *outputTree = 0;

   //ADD-HSCP-SELECTION
bool PassHSCPpresel_sel(int hscpIndex);


   bool do1Dplots;
   bool do2Dplots;
   bool doPreselPlots;

   bool UseFpixel;
   bool UseGstrip;
   bool CalibrationZmumu;
   bool FillTree;
   bool computeAtlasMass;
   bool correctEstimators;
   bool isSimulation;
   bool debug;
   bool debugSignal;

   int etabins_;
   int ihbins_;
   int pbins_;
   int massbins_;
   int masscut_;
   int tofbins_;
   int fpixbins_;
   double ptcut_;
   double tofcut_;
 

   int PFMu;
   int GlobalMu;
   int passedSel;
   int tot;


   int muBadReco;
   int muGoodReco;
   int muGoodRecoGoodError;
   int muGoodRecoButBadError;
 
   std::string numbersMpoint_;
   int massPointSig_;
 
   std::string dataset_;
   std::string oFile_;
   std::string version_;

   int filltofErrUp =0;
   int toferrUpEqualsZero = 0;
   int fillNominal = 0;

   int befPreSel=0;
   int preselTestIh = 0;

   vector< vector <float> > ratioPandEta;

   vector<float> ratioPmuPele;
   vector<float> ratioIHmuIHele;
   vector<float> ratioEtaMuEtaEle;

   vector<float> etaMin;
   vector<float> etaMax;
   vector<float> etaWeights;
 
   vector<float> toferrMin;
   vector<float> toferrMax;
   vector<float> toferrWeights;


   vector<double> Ih_cut_values;

   std::vector<double> ptErrScaleFactors;
   std::vector<std::pair<double,double>> ptBinRanges = { {0, 100}, {100, 200}, {200, 300},{300, 400}, {400, 500},{500, 600}, {600, 700}, {700, 800}, {800, 900}, {900, 1000},{1000, 1100}, {1100, 1200}, {1200, 1300}, {1300, 1400}, {1400, 100000}
   };

   std::vector<bool (HSCPSelector::*)(int)> selections_;
   std::vector<string> selLabels_;

   //Test
   TFile* fout;
   TFile* treeTest;
   //Will be used to proced mass plots at given selections (see selLabels)


   //Will be used to produce many plots at given selections (see selLabels)
   std::vector<CPlots> vcp; 

   // Readers to access the data (delete the ones you do not need).
   TTreeReaderArray<float> Ih_Strip = {fReader, "DeDx_IhStrip"};
   TTreeReaderArray<double> Pt = {fReader, "IsoTrack_pt"};
   TTreeReaderArray<double> Eta = {fReader, "IsoTrack_eta"};
   TTreeReaderArray<uint32_t> NbPixelHit_noL1 = {fReader, "DeDx_PixelNoL1NOM"};
   TTreeReaderArray<uint32_t> NOM_noL1 = {fReader, "DeDx_NoL1NOM"};
   TTreeReaderArray<double> FracOfValidHit = {fReader, "IsoTrack_fractionOfValidHits"};
   TTreeReaderArray<bool> isHighPurityTrack = {fReader, "IsoTrack_isHighPurityTrack"};
   TTreeReaderArray<float> miniRelIsoAll = {fReader, "IsoTrack_pfMiniRelIsoAll"};
   TTreeReaderArray<float> IsoSumPt_dr03 = {fReader, "IsoTrack_IsoSumPt_dr03"};
   TTreeReaderArray<float> dz = {fReader, "IsoTrack_dz"};
   TTreeReaderArray<float> dxy = {fReader, "IsoTrack_dxy"};
   TTreeReaderArray<double> normChi2 = {fReader, "IsoTrack_normChi2"};
   TTreeReaderArray<double> EoP = {fReader, "IsoTrack_pfEnergyOverP"};
   TTreeReaderArray<double> ptOverptErrptErr = {fReader, "IsoTrack_ptErrOverPt2"};
   TTreeReaderArray<double> ptOverptErr = {fReader, "IsoTrack_ptErrOverPt"};
   TTreeReaderArray<float> Fpix = {fReader, "DeDx_FiPixelNoL1"};
   TTreeReaderArray<double> RecoCaloMET = {fReader, "RecoCaloMET"};
   TTreeReaderArray<bool> Flag_allMETFilters = {fReader, "Flag_allMETFilters"};

   HSCPSelector()
   {
      fout = 0;
      treeTest = 0;
   }

   virtual ~HSCPSelector() 
   {
      if(!fout) delete fout;
      if(!treeTest) delete treeTest; 
   }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList   *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(HSCPSelector,0);
};

#endif


#ifdef HSCPSelector_cxx


void HSCPSelector::Init(TTree *tree)
{
   fReader.SetTree(tree);
}

Bool_t HSCPSelector::Notify()
{
   return kTRUE;
}

#endif // #ifdef HSCPSelector_cxx