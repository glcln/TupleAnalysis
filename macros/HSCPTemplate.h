#ifndef HSCPSelector_h
#define HSCPSelector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>
#include <TEfficiency.h>
#include <TLorentzVector.h>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include "ROOT/RConfig.hxx"
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

   int etabins_;
   int ihbins_;
   int pbins_;
   int massbins_;
   int masscut_;
   int fpixbins_;
   double ptcut_;
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

   // DATA-MC SF for the signal (derived from the trigg. eff.)
   std::vector <float> SF_triggerEff;
   std::vector <float> SF_PseudoMETvalue;
   bool SFisUp;
   bool SFisDown;
   std::vector <float> SF_triggerEff_NOTrescaled;
   std::vector <float> SF_PseudoMETvalue_NOTrescaled;

   TFile* fout;


   // Readers to access the data (delete the ones you do not need).

   // TRIGGERS
   TTreeReaderValue<bool> HLT_Mu50 = {fReader, "HLT_Mu50"};
   TTreeReaderValue<bool> HLT_IsoMu27 = {fReader, "HLT_IsoMu27"};
   TTreeReaderValue<bool> HLT_FilterOR = {fReader, "HLT_FilterOR"};

   TTreeReaderValue<bool> HLT_PFMET120_PFMHT120_IDTight = {fReader, "HLT_PFMET120_PFMHT120_IDTight"};
   TTreeReaderValue<bool> HLT_PFHT500_PFMET100_PFMHT100_IDTight = {fReader, "HLT_PFHT500_PFMET100_PFMHT100_IDTight"};
   TTreeReaderValue<bool> HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 = {fReader, "HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60"};
   TTreeReaderValue<bool> HLT_MET105_IsoTrk50 = {fReader, "HLT_MET105_IsoTrk50"};

   TTreeReaderValue<bool> HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ = {fReader, "HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ"};
   TTreeReaderValue<bool> HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL = {fReader, "HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL"};

   TTreeReaderArray<double> L1MET = {fReader, "L1MET"};
   TTreeReaderArray<float> HLTCaloMET = {fReader, "HLTCaloMET"};
   TTreeReaderArray<float> HLTCaloMHT = {fReader, "HLTCaloMHT"};
   TTreeReaderArray<float> HLTPFMHT = {fReader, "HLTPFMHT"};
   TTreeReaderArray<float> HLTPFMET = {fReader, "HLTPFMET"};

   // EVENT INFO
   TTreeReaderValue<ULong64_t> Event = {fReader, "event"};
   TTreeReaderValue<uint32_t> Run = {fReader, "run"};
   TTreeReaderValue<uint32_t> Lumi = {fReader, "luminosityBlock"};
   TTreeReaderValue<uint32_t> PV_npvsGood = {fReader, "PV_npvsGood"};
   TTreeReaderValue<int> trueNPV = {fReader, "trueNPV"};
   TTreeReaderValue<uint32_t> HSCP_n = {fReader, "HSCP_n"};
   TTreeReaderValue<float> weightPU = {fReader, "weightPU"};
   

   // TRACK INFO
   TTreeReaderArray<int> PF_type = {fReader, "IsoTrack_pfType"};
   TTreeReaderArray<int> HSCP_type = {fReader, "HSCP_type"};
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
   TTreeReaderArray<float> Ih_Strip_noSF = {fReader, "DeDx_IhStrip_noSF"};
   TTreeReaderArray<float> Ih_Strip_oldCorr = {fReader, "DeDx_IhStrip_oldCorr"};

   TTreeReaderArray<uint32_t> NbPixelHit_noL1 = {fReader, "DeDx_PixelNoL1NOM"};
   TTreeReaderArray<uint32_t> NOM_noL1 = {fReader, "DeDx_NoL1NOM"};
   TTreeReaderArray<double> FracOfValidHit = {fReader, "IsoTrack_fractionOfValidHits"};
   
   TTreeReaderArray<float> Fpix = {fReader, "DeDx_FiPixelNoL1"};
   TTreeReaderArray<float> GStrip = {fReader, "DeDx_GiStrip"};
   TTreeReaderArray<float> GStrip_oldCorr = {fReader, "DeDx_GiStrip_oldCorr"};

   TTreeReaderArray<float> miniRelIsoAll = {fReader, "IsoTrack_pfMiniRelIsoAll"};
   TTreeReaderArray<float> miniRelIsoChg = {fReader, "IsoTrack_pfMiniRelIsoChg"};
   TTreeReaderArray<float> IsoSumPt_dr03 = {fReader, "IsoTrack_IsoSumPt_dr03"};
   
   TTreeReaderArray<bool> Flag_allMETFilters = {fReader, "Flag_allMETFilters"};
   TTreeReaderArray<double> RecoPFMET = {fReader, "RecoPFMET"};
   TTreeReaderArray<double> RecoPFMET_phi = {fReader, "RecoPFMET_phi"};
   TTreeReaderArray<double> PseudoCaloMET = {fReader, "PseudoMET_viaCaloJets"};
   TTreeReaderArray<double> RecoPuppiMET = {fReader, "RecoPuppiMET"};

   // Pseudo variable (reco in miniAOD)
   TTreeReaderArray<double> Pt_pseudo = {fReader, "IsoTrack_PseudoTrack_pt"};
   TTreeReaderArray<double> Eta_pseudo = {fReader, "IsoTrack_PseudoTrack_eta"};
   TTreeReaderArray<double> Phi_pseudo = {fReader, "IsoTrack_PseudoTrack_phi"};

   
   // GEN INFO
   TTreeReaderArray<double> GenPart_pt = {fReader, "GenPart_pt"};
   TTreeReaderArray<double> GenPart_eta = {fReader, "GenPart_eta"};
   TTreeReaderArray<double> GenPart_phi = {fReader, "GenPart_phi"};
   TTreeReaderArray<double> GenPart_mass = {fReader, "GenPart_mass"};
   TTreeReaderArray<int> GenPart_pdgId = {fReader, "GenPart_pdgId"};

   TTreeReaderArray<double> PthatQCD = {fReader, "weight_generatorBinningValues"};


   // muon info
   TTreeReaderArray<double> muon_pt = {fReader, "muon_pt"};
   TTreeReaderArray<double> muon_eta = {fReader, "muon_eta"};
   TTreeReaderArray<double> muon_phi = {fReader, "muon_phi"};
   TTreeReaderArray<bool> muon_isLoose = {fReader, "muon_isLoose"};
   TTreeReaderArray<bool> muon_isMedium = {fReader, "muon_isMedium"};
   TTreeReaderArray<bool> muon_isTight = {fReader, "muon_isTight"};
   TTreeReaderArray<float> muon_trackIso_dr04 = {fReader, "muon_trackIso_dr04"};
   TTreeReaderArray<float> muon_pfMiniRelIsoAll = {fReader, "muon_pfMiniRelIsoAll"};


   // electron info
   TTreeReaderArray<double> electron_pt = {fReader, "electron_pt"};
   TTreeReaderArray<double> electron_eta = {fReader, "electron_eta"};
   TTreeReaderArray<double> electron_phi = {fReader, "electron_phi"};
   TTreeReaderArray<float> electron_isLoose = {fReader, "electron_isLoose"};
   TTreeReaderArray<float> electron_isMedium = {fReader, "electron_isMedium"};
   TTreeReaderArray<float> electron_isTight = {fReader, "electron_isTight"};
   TTreeReaderArray<float> electron_trackIso_dr04 = {fReader, "electron_trackIso_dr04"};
   TTreeReaderArray<float> electron_pfMiniRelIsoAll = {fReader, "electron_pfMiniRelIsoAll"};

   // only in AOD : 
   //TTreeReaderArray<double> RecoCaloMET_phi = {fReader, "RecoCaloMET_phi"};
   //TTreeReaderArray<double> RecoCaloMET = {fReader, "RecoCaloMET"};


   // BACKGROUND ESTIMATION METHOD: HISTOGRAMS
   bool UseFpixel;
   
   float fpix0 = 0.0;
   float fpix3 = 0.3;
   float fpix4 = 0.4;
   float fpix5 = 0.5;
   float fpix6 = 0.6;
   float fpix7 = 0.7;
   float fpix8 = 0.8;
   float fpix9 = 0.9;
   float fpix99 = 0.99;
   float fpix999 = 0.999;
   float fpix10 = 1.0;


   std::string regFpixAll = "_regionAll";

   std::string regFpixA_3f4 = "_regionA_3fp4";
   std::string regFpixA_3f6 = "_regionA_3fp6";
   std::string regFpixA_3f8 = "_regionA_3fp8";
   std::string regFpixA_3f9 = "_regionA_3fp9";
   std::string regFpixA_4f5 = "_regionA_4fp5";
   std::string regFpixA_5f6 = "_regionA_5fp6";
   std::string regFpixA_6f7 = "_regionA_6fp7";
   std::string regFpixA_6f9 = "_regionA_6fp9";
   std::string regFpixA_7f8 = "_regionA_7fp8";
   std::string regFpixA_8f9 = "_regionA_8fp9";
   std::string regFpixA_9f10 = "_regionA_9fp10";
   std::string regFpixA_99f10 = "_regionA_99fp10";
   std::string regFpixA_999f10 = "_regionA_999fp10";

   std::string regFpixB_3f4 = "_regionB_3fp4";
   std::string regFpixB_3f6 = "_regionB_3fp6";
   std::string regFpixB_3f8 = "_regionB_3fp8";
   std::string regFpixB_3f9 = "_regionB_3fp9";
   std::string regFpixB_4f5 = "_regionB_4fp5";
   std::string regFpixB_5f6 = "_regionB_5fp6";
   std::string regFpixB_6f7 = "_regionB_6fp7";
   std::string regFpixB_6f9 = "_regionB_6fp9";
   std::string regFpixB_7f8 = "_regionB_7fp8";
   std::string regFpixB_8f9 = "_regionB_8fp9";
   std::string regFpixB_8f10 = "_regionB_8fp10";
   std::string regFpixB_9f10 = "_regionB_9fp10";
   std::string regFpixB_99f10 = "_regionB_99fp10";
   std::string regFpixB_999f10 = "_regionB_999fp10";

   std::string regFpixC_3f4 = "_regionC_3fp4";
   std::string regFpixC_3f6 = "_regionC_3fp6";
   std::string regFpixC_3f8 = "_regionC_3fp8";
   std::string regFpixC_3f9 = "_regionC_3fp9";
   std::string regFpixC_4f5 = "_regionC_4fp5";
   std::string regFpixC_5f6 = "_regionC_5fp6";
   std::string regFpixC_6f7 = "_regionC_6fp7";
   std::string regFpixC_6f9 = "_regionC_6fp9";
   std::string regFpixC_7f8 = "_regionC_7fp8";
   std::string regFpixC_8f9 = "_regionC_8fp9";

   std::string regFpixD_3f4 = "_regionD_3fp4";
   std::string regFpixD_3f8 = "_regionD_3fp8";
   std::string regFpixD_4f5 = "_regionD_4fp5";
   std::string regFpixD_5f6 = "_regionD_5fp6";
   std::string regFpixD_6f7 = "_regionD_6fp7";
   std::string regFpixD_6f9 = "_regionD_6fp9";
   std::string regFpixD_7f8 = "_regionD_7fp8";
   std::string regFpixD_8f9 = "_regionD_8fp9";
   std::string regFpixD_8f10 = "_regionD_8fp10";
   std::string regFpixD_9f10 = "_regionD_9fp10";
   std::string regFpixD_99f10 = "_regionD_99fp10";
   std::string regFpixD_999f10 = "_regionD_999fp10";

  
   std::vector<RegionMassPlot> vmrp_regionFpix_all;

   std::vector<RegionMassPlot> vmrp_regionA_3f4;
   std::vector<RegionMassPlot> vmrp_regionA_3f6;
   std::vector<RegionMassPlot> vmrp_regionA_3f8;
   std::vector<RegionMassPlot> vmrp_regionA_3f9;
   std::vector<RegionMassPlot> vmrp_regionA_4f5;
   std::vector<RegionMassPlot> vmrp_regionA_5f6;
   std::vector<RegionMassPlot> vmrp_regionA_6f7;
   std::vector<RegionMassPlot> vmrp_regionA_6f9;
   std::vector<RegionMassPlot> vmrp_regionA_7f8;
   std::vector<RegionMassPlot> vmrp_regionA_8f9;
   std::vector<RegionMassPlot> vmrp_regionA_9f10;
   std::vector<RegionMassPlot> vmrp_regionA_99f10;
   std::vector<RegionMassPlot> vmrp_regionA_999f10;

   std::vector<RegionMassPlot> vmrp_regionB_3f4;
   std::vector<RegionMassPlot> vmrp_regionB_3f6;
   std::vector<RegionMassPlot> vmrp_regionB_3f8;
   std::vector<RegionMassPlot> vmrp_regionB_3f9;
   std::vector<RegionMassPlot> vmrp_regionB_4f5;
   std::vector<RegionMassPlot> vmrp_regionB_5f6;
   std::vector<RegionMassPlot> vmrp_regionB_6f7;
   std::vector<RegionMassPlot> vmrp_regionB_6f9;
   std::vector<RegionMassPlot> vmrp_regionB_7f8;
   std::vector<RegionMassPlot> vmrp_regionB_8f9;
   std::vector<RegionMassPlot> vmrp_regionB_8f10;
   std::vector<RegionMassPlot> vmrp_regionB_9f10;
   std::vector<RegionMassPlot> vmrp_regionB_99f10;
   std::vector<RegionMassPlot> vmrp_regionB_999f10;

   std::vector<RegionMassPlot> vmrp_regionC_3f4;
   std::vector<RegionMassPlot> vmrp_regionC_3f6;
   std::vector<RegionMassPlot> vmrp_regionC_3f8;
   std::vector<RegionMassPlot> vmrp_regionC_3f9;
   std::vector<RegionMassPlot> vmrp_regionC_4f5;
   std::vector<RegionMassPlot> vmrp_regionC_5f6;
   std::vector<RegionMassPlot> vmrp_regionC_6f7;
   std::vector<RegionMassPlot> vmrp_regionC_6f9;
   std::vector<RegionMassPlot> vmrp_regionC_7f8;
   std::vector<RegionMassPlot> vmrp_regionC_8f9;

   std::vector<RegionMassPlot> vmrp_regionD_3f4;
   std::vector<RegionMassPlot> vmrp_regionD_3f8;
   std::vector<RegionMassPlot> vmrp_regionD_4f5;
   std::vector<RegionMassPlot> vmrp_regionD_5f6;
   std::vector<RegionMassPlot> vmrp_regionD_6f7;
   std::vector<RegionMassPlot> vmrp_regionD_6f9;
   std::vector<RegionMassPlot> vmrp_regionD_7f8;
   std::vector<RegionMassPlot> vmrp_regionD_8f9;
   std::vector<RegionMassPlot> vmrp_regionD_8f10;
   std::vector<RegionMassPlot> vmrp_regionD_9f10;
   std::vector<RegionMassPlot> vmrp_regionD_99f10;
   std::vector<RegionMassPlot> vmrp_regionD_999f10;

   
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

double deltaR(double eta1, double phi1, double eta2, double phi2) {
   double dphi = phi1 - phi2;
   while (dphi >  M_PI) dphi -= 2*M_PI;
   while (dphi <= -M_PI) dphi += 2*M_PI;

   double deta = eta1 - eta2;
   return std::sqrt(deta*deta + dphi*dphi);
}

#endif // #ifdef HSCPSelector_cxx