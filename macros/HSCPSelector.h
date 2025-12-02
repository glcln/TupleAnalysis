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
#include "../inc/ComputeATLASmass.h"

using namespace std;


class HSCPSelector : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   TTree *outputTree = 0;

   //ADD-HSCP-SELECTION
bool PassHSCPpresel_NoCriteria(int hscpIndex);

bool PassHSCPpresel_OnlyMET(int hscpIndex);


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
   std::vector<CPlots> vcp_nosel;

   std::vector<unsigned int> OnlyIn_AOD;
   std::vector<unsigned int> OnlyIn_MiniAOD;
   bool isAOD = false;
   bool isMiniAOD = false;
   

   TFile* fout;


   // Readers to access the data (delete the ones you do not need).

   // TRIGGERS
   //TTreeReaderValue<bool> HLT_Mu50 = {fReader, "HLT_Mu50"};
   TTreeReaderValue<bool> HLT_FilterOR = {fReader, "HLT_FilterOR"};

   TTreeReaderValue<bool> HLT_PFMET120_PFMHT120_IDTight = {fReader, "HLT_PFMET120_PFMHT120_IDTight"};
   TTreeReaderValue<bool> HLT_PFHT500_PFMET100_PFMHT100_IDTight = {fReader, "HLT_PFHT500_PFMET100_PFMHT100_IDTight"};
   TTreeReaderValue<bool> HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 = {fReader, "HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60"};
   TTreeReaderValue<bool> HLT_MET105_IsoTrk50 = {fReader, "HLT_MET105_IsoTrk50"};
   

   // EVENT INFO
   TTreeReaderValue<ULong64_t> Event = {fReader, "event"};
   TTreeReaderValue<uint32_t> Run = {fReader, "run"};
   TTreeReaderValue<uint32_t> Lumi = {fReader, "luminosityBlock"};
   TTreeReaderValue<uint32_t> PV_npvsGood = {fReader, "PV_npvsGood"};

      // track info
   TTreeReaderArray<int> PF_type = {fReader, "IsoTrack_pfType"};
   TTreeReaderArray<int> HSCP_type = {fReader, "HSCP_type"};
   TTreeReaderArray<uint32_t> HSCP_n = {fReader, "HSCP_n"};
   TTreeReaderArray<bool> HSCP_hasTrack = {fReader, "HSCP_hasTrack"};
   TTreeReaderArray<bool> HSCP_hasDeDx = {fReader, "HSCP_hasDeDx"};
   TTreeReaderArray<double> P = {fReader, "IsoTrack_p"};
   TTreeReaderArray<double> Pt = {fReader, "IsoTrack_pt"};
   TTreeReaderArray<double> Pterr = {fReader, "IsoTrack_ptError"};
   TTreeReaderArray<double> Eta = {fReader, "IsoTrack_eta"};
   TTreeReaderArray<double> Phi = {fReader, "IsoTrack_phi"};
   TTreeReaderArray<bool> isHighPurityTrack = {fReader, "IsoTrack_isHighPurityTrack"};
   TTreeReaderArray<double> dz = {fReader, "IsoTrack_dz"};
   TTreeReaderArray<double> dxy = {fReader, "IsoTrack_dxy"};
   TTreeReaderArray<double> normChi2 = {fReader, "IsoTrack_normChi2"};
   TTreeReaderArray<double> EoP = {fReader, "IsoTrack_pfEnergyOverP"};
   TTreeReaderArray<double> ptOverptErrptErr = {fReader, "IsoTrack_ptErrOverPt2"};
   TTreeReaderArray<double> ptOverptErr = {fReader, "IsoTrack_ptErrOverPt"};
   
   TTreeReaderArray<float> Ih_Strip = {fReader, "DeDx_IhStrip"};
   TTreeReaderArray<uint32_t> NbPixelHit_noL1 = {fReader, "DeDx_PixelNoL1NOM"};
   TTreeReaderArray<uint32_t> NOM_noL1 = {fReader, "DeDx_NoL1NOM"};
   TTreeReaderArray<double> FracOfValidHit = {fReader, "IsoTrack_fractionOfValidHits"};
   TTreeReaderArray<float> Fpix = {fReader, "DeDx_FiPixelNoL1"};
   TTreeReaderArray<float> GStrip = {fReader, "DeDx_GiStrip"};

   TTreeReaderArray<float> miniRelIsoAll = {fReader, "IsoTrack_pfMiniRelIsoAll"};
   TTreeReaderArray<float> miniRelIsoChg = {fReader, "IsoTrack_pfMiniRelIsoChg"};
   TTreeReaderArray<float> IsoSumPt_dr03 = {fReader, "IsoTrack_IsoSumPt_dr03"};
   
   TTreeReaderArray<bool> Flag_allMETFilters = {fReader, "Flag_allMETFilters"};
   TTreeReaderArray<double> RecoPFMET = {fReader, "RecoPFMET"};
   TTreeReaderArray<double> RecoPFMET_phi = {fReader, "RecoPFMET_phi"};
   TTreeReaderArray<double> CaloJets = {fReader, "PseudoMET_viaCaloJets"};

   TTreeReaderArray<double> Muon_pt = {fReader, "Muon_pt"};
   TTreeReaderArray<double> Muon_eta = {fReader, "Muon_eta"};
   TTreeReaderArray<double> Muon_phi = {fReader, "Muon_phi"};
   TTreeReaderArray<bool> hasMuon = {fReader, "HSCP_hasMuon"};


   // GENINFO
   TTreeReaderArray<double> GenPart_mass = {fReader, "GenPart_mass"};
   TTreeReaderArray<double> GenPart_pt = {fReader, "GenPart_pt"};
   TTreeReaderArray<double> GenPart_eta = {fReader, "GenPart_eta"};
   TTreeReaderArray<double> GenPart_phi = {fReader, "GenPart_phi"};
   TTreeReaderArray<int> GenPart_pdgId = {fReader, "GenPart_pdgId"};



   // only in AOD : 
   //TTreeReaderArray<double> RecoCaloMET_phi = {fReader, "RecoCaloMET_phi"};
   //TTreeReaderArray<double> RecoCaloMET = {fReader, "RecoCaloMET"};
   //TTreeReaderArray<double> CaloJets_wCut = {fReader, "PseudoMET_viaCaloJets_wCut"};

   
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