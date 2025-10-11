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
bool PassHSCPpresel_Comp(int hscpIndex);


   int etabins_;
   int ihbins_;
   int pbins_;
   int massbins_;
   int masscut_;
   int tofbins_;
   int fpixbins_;
   double ptcut_;
   double tofcut_;
 
   std::string dataset_;
   std::string oFile_;
   std::string version_;
   std::vector<bool (HSCPSelector::*)(int)> selections_;
   std::vector<string> selLabels_;
   std::vector<CPlots> vcp; 

   TFile* fout;


   // Readers to access the data (delete the ones you do not need).

   bool isAOD = false;

   TTreeReaderValue<ULong64_t> Event = {fReader, "event"};
   TTreeReaderValue<uint32_t> Run = {fReader, "run"};
   TTreeReaderValue<uint32_t> Lumi = {fReader, "luminosityBlock"};

   TTreeReaderArray<float> Ih_Strip = {fReader, "DeDx_IhStrip"};
   TTreeReaderArray<double> P = {fReader, "IsoTrack_p"};
   TTreeReaderArray<double> Pt = {fReader, "IsoTrack_pt"};
   TTreeReaderArray<double> Pterr = {fReader, "IsoTrack_ptError"};
   TTreeReaderArray<double> Eta = {fReader, "IsoTrack_eta"};
   TTreeReaderArray<double> Phi = {fReader, "IsoTrack_phi"};
   TTreeReaderArray<uint32_t> NbPixelHit_noL1 = {fReader, "DeDx_PixelNoL1NOM"};
   TTreeReaderArray<uint32_t> NOM_noL1 = {fReader, "DeDx_NoL1NOM"};
   TTreeReaderArray<double> FracOfValidHit = {fReader, "IsoTrack_fractionOfValidHits"};
   TTreeReaderArray<bool> isHighPurityTrack = {fReader, "IsoTrack_isHighPurityTrack"};
   TTreeReaderArray<float> miniRelIsoAll = {fReader, "IsoTrack_pfMiniRelIsoAll"};
   TTreeReaderArray<float> miniRelIsoChg = {fReader, "IsoTrack_pfMiniRelIsoChg"};
   TTreeReaderArray<float> IsoSumPt_dr03 = {fReader, "IsoTrack_IsoSumPt_dr03"};
   TTreeReaderArray<double> dz = {fReader, "IsoTrack_dz"};
   TTreeReaderArray<double> dxy = {fReader, "IsoTrack_dxy"};
   TTreeReaderArray<double> normChi2 = {fReader, "IsoTrack_normChi2"};
   TTreeReaderArray<double> EoP = {fReader, "IsoTrack_pfEnergyOverP"};
   TTreeReaderArray<double> ptOverptErrptErr = {fReader, "IsoTrack_ptErrOverPt2"};
   TTreeReaderArray<double> ptOverptErr = {fReader, "IsoTrack_ptErrOverPt"};
   TTreeReaderArray<float> Fpix = {fReader, "DeDx_FiPixelNoL1"};
   TTreeReaderArray<double> CaloJets = {fReader, "CaloJets"};
   TTreeReaderArray<int> HSCP_type = {fReader, "HSCP_type"};
   TTreeReaderArray<bool> Flag_allMETFilters = {fReader, "Flag_allMETFilters"};
   TTreeReaderArray<double> RecoPFMET = {fReader, "RecoPFMET"};
   TTreeReaderArray<double> RecoPFMET_phi = {fReader, "RecoPFMET_phi"};

   // only in AOD : 
   //TTreeReaderArray<double> RecoCaloMET_phi = {fReader, "RecoCaloMET_phi"};
   //TTreeReaderArray<double> RecoCaloMET = {fReader, "RecoCaloMET"};

   // only in miniAOD :
   TTreeReaderArray<double> PatCaloMET = {fReader, "PatCaloMET"};
   TTreeReaderArray<double> PatCaloMET_phi = {fReader, "PatCaloMET_phi"};
   TTreeReaderArray<double> RecoPuppiMET = {fReader, "RecoPuppiMET"};
   TTreeReaderArray<double> RecoPuppiMET_phi = {fReader, "RecoPuppiMET_phi"};
   
   
   HSCPSelector()
   {
      fout = 0;
   }

   virtual ~HSCPSelector() 
   {
      if(!fout) delete fout;
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