#define HSCPSelector_cxx

#include "HSCPSelector.h"
#include <TH2.h>
#include <TH1.h>
#include <TStyle.h>
#include <functional>
#include <cmath>


//K and C values are set based on the config file dataset name (see below)
float K(2.54), C(3.14); 

float K_signal2017(2.48), C_signal2017(3.19); //MC signal 2017
float K_signal2018(2.49), C_signal2018(3.18); //MC signal 2018

float K_bckg2017(2.48), C_bckg2017(3.19); //MC background 2017
float K_bckg2018(2.49), C_bckg2018(3.18); //MC background 2018

float K_data2018(2.55), C_data2018(3.14); //Data 2018
float K_data2017(2.54), C_data2017(3.14); //Data 2017

int year(2018);


//ADD-SELECTION-METHODS
bool HSCPSelector::PassHSCPpresel_NoCriteria(int i){
   if (i<0 || i>(int)Pt.GetSize()) {
      cout << i << endl;
      return false;
   }
   return (( true ));
}



void HSCPSelector::Begin(TTree *tree)
{
    TString option = GetOption();
    TObjArray *tx = option.Tokenize(",");

    // Output file
    std::string ext = ".root";

    std::string ptname( ((TObjString *)(tx->At(1)))->String().Data());
    int ptInt = std::stoi(ptname);

    oFile_ = ((TObjString *)(tx->At(9)))->String().Data();
    oFile_ += "_";
    oFile_ += ((TObjString *)(tx->At(10)))->String().Data();
    oFile_ += "_Eta2p4";
    oFile_ += ext;

    //FILL-SELECTION-VECTOR
selections_.push_back(&HSCPSelector::PassHSCPpresel_NoCriteria);
selLabels_.push_back("NoCriteria");


    std::cout << std::endl;
    std::cout << "Number of selections: " << selLabels_.size() << std::endl;
    std::cout << "Output file: " << oFile_.c_str() << std::endl;
    std::cout << std::endl;
}



void HSCPSelector::SlaveBegin(TTree *tree)
{
    TString option = GetOption();
    TObjArray *tx = option.Tokenize(",");

    std::string dataset( ((TObjString *)(tx->At(9)))->String().Data());
    dataset_ = dataset;
    if(true) {//dataset_ == "Gluino2000"){ 
        K = K_signal2018;
        C = C_signal2018;
        year = 2018;
    }

    if (dataset_.find("_AOD") != std::string::npos) {
        isAOD = true;
        std::ifstream infile("/opt/sbg/cms/safe1/cms/gcoulon/CMSSW_14_0_21/src/OnlyIn_AOD.txt");
        unsigned int value = 0;
        while (infile >> value) OnlyIn_AOD.push_back(value);
    }
    if (dataset_.find("_miniAOD") != std::string::npos) {
        isMiniAOD = true;
        std::ifstream infile("/opt/sbg/cms/safe1/cms/gcoulon/CMSSW_14_0_21/src/OnlyIn_miniAOD.txt");
        unsigned int value = 0;
        while (infile >> value) OnlyIn_MiniAOD.push_back(value);
    }


    //-------------------------------------
    //Add selections into a vector - to be updated
    //FILL-SELECTION-VECTOR
selections_.push_back(&HSCPSelector::PassHSCPpresel_NoCriteria);
selLabels_.push_back("NoCriteria");

    //-------------------------------------

    //-------------------------------------
    //create RegionMassPlot for all selection
    //-------------------------------------
    for(unsigned int i=0;i<selLabels_.size();i++)
    {
        CPlots plots;

        plots.AddHisto1D(selLabels_[i]+"_npv", 80, 0, 80);

        plots.AddHisto1D(selLabels_[i]+"_Ih", 200, 0, 20);
        plots.AddHisto1D(selLabels_[i]+"_Pt", 100, 0, 2000);
        plots.AddHisto1D(selLabels_[i]+"_Eta", 50, -2.5, 2.5);
        plots.AddHisto1D(selLabels_[i]+"_NbPixelHit_noL1", 10, 0, 10);
        plots.AddHisto1D(selLabels_[i]+"_NOM_noL1", 50, 0, 50);
        plots.AddHisto1D(selLabels_[i]+"_FracOfValidHit", 50, 0, 1.1);
        plots.AddHisto1D(selLabels_[i]+"_isHighPurityTrack", 2, -0.5, 1.5);
        plots.AddHisto1D(selLabels_[i]+"_miniRelIsoAll", 50, 0, 1);
        plots.AddHisto1D(selLabels_[i]+"_IsoSumPt_dr03", 10, 0, 100);
        plots.AddHisto1D(selLabels_[i]+"_dz", 100, -0.5, 0.5);
        plots.AddHisto1D(selLabels_[i]+"_dxy", 100, -0.5, 0.5);
        plots.AddHisto1D(selLabels_[i]+"_normChi2", 10, 0, 10);
        plots.AddHisto1D(selLabels_[i]+"_EoP", 100, 0, 10);
        plots.AddHisto1D(selLabels_[i]+"_ptOverptErrptErr", 1000, 0, 0.1);
        plots.AddHisto1D(selLabels_[i]+"_ptOverptErr", 100, 0, 1);
        plots.AddHisto1D(selLabels_[i]+"_Fpix", 100, 0, 1);
        plots.AddHisto1D(selLabels_[i]+"_GStrip", 100, 0, 1);
        plots.AddHisto1D(selLabels_[i]+"_Flag_allMETFilters", 2, -0.5, 1.5);
        plots.AddHisto1D(selLabels_[i]+"_HSCP_type", 6, -0.5, 5.5);
        plots.AddHisto1D(selLabels_[i]+"_PF_type", 250, 0, 250);
        plots.AddHisto1D(selLabels_[i]+"_PFMET", 100, 0, 500);
        plots.AddHisto1D(selLabels_[i]+"_PFMET_phi", 50, -3.5, 3.5);
        plots.AddHisto1D(selLabels_[i]+"_PseudoMET_viaCaloJets", 100, 0, 500);

        plots.AddHisto1D(selLabels_[i]+"_HLT_Mu50", 2, -0.5, 1.5);

        plots.AddHisto1D(selLabels_[i]+"_Pt_PFMuon", 100, 0, 2000);
        plots.AddHisto1D(selLabels_[i]+"_Pt_PFChgHadron", 100, 0, 2000);
        plots.AddHisto1D(selLabels_[i]+"_Pt_other", 100, 0, 2000);


        // Trigger efficiency
        plots.AddHisto1D(selLabels_[i]+"_CaloJets", 100, 0, 2500);
        plots.AddHisto1D(selLabels_[i]+"_if___HLT_PFMET120_PFMHT120_IDTight___CaloJets", 100, 0, 2500);
        plots.AddHisto1D(selLabels_[i]+"_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___CaloJets", 100, 0, 2500);
        plots.AddHisto1D(selLabels_[i]+"_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___CaloJets", 100, 0, 2500);
        plots.AddHisto1D(selLabels_[i]+"_if___HLT_MET105_IsoTrk50___CaloJets", 100, 0, 2500);

        plots.AddHisto1D(selLabels_[i]+"_RecoPFMET", 100, 0, 2500);
        plots.AddHisto1D(selLabels_[i]+"_if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET", 100, 0, 2500);
        plots.AddHisto1D(selLabels_[i]+"_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET", 100, 0, 2500);
        plots.AddHisto1D(selLabels_[i]+"_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET", 100, 0, 2500);
        plots.AddHisto1D(selLabels_[i]+"_if___HLT_MET105_IsoTrk50___RecoPFMET", 100, 0, 2500);

        plots.AddHisto1D(selLabels_[i]+"_if___orMETtrg___CaloJets", 100, 0, 2500);
        plots.AddHisto1D(selLabels_[i]+"_if___orMETtrg___RecoPFMET", 100, 0, 2500);

        plots.AddHisto1D(selLabels_[i]+"_RecoCaloMET", 100, 0, 2500);
        plots.AddHisto1D(selLabels_[i]+"_if___HLT_PFMET120_PFMHT120_IDTight___RecoCaloMET", 100, 0, 2500);
        plots.AddHisto1D(selLabels_[i]+"_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoCaloMET", 100, 0, 2500);
        plots.AddHisto1D(selLabels_[i]+"_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoCaloMET", 100, 0, 2500);
        plots.AddHisto1D(selLabels_[i]+"_if___HLT_MET105_IsoTrk50___RecoCaloMET", 100, 0, 2500);
        plots.AddHisto1D(selLabels_[i]+"_if___orMETtrg___RecoCaloMET", 100, 0, 2500);

        vcp.push_back(std::move(plots));
    }

        // Without selections
    CPlots plots;
    plots.AddHisto1D("CandidateCutflow", 18, 0, 18);
    plots.AddHisto1D("EventCutflow", 18, 0, 18);
    plots.AddHisto1D("EventCutflow_NotrackCut", 20, 0, 20);

    plots.AddHisto1D("Trigger", 3, -1, 2);

    plots.AddHisto1D("Nm1_trigger", 4, -1.5, 2.5);
    plots.AddHisto1D("Nm1_METfilters", 2, 0, 2);
    plots.AddHisto1D("Nm1_CaloMET", 100, 0, 1000);
    plots.AddHisto1D("Nm1_Pt", 100, 0, 2500);
    plots.AddHisto1D("Nm1_eta", 60, -3, +3);
    plots.AddHisto1D("Nm1_NOPH", 10, 0, 10);
    plots.AddHisto1D("Nm1_FOVH", 50, 0, 1.1);
    plots.AddHisto1D("Nm1_NOM", 50, 0, 50);
    plots.AddHisto1D("Nm1_HighPurity", 4, -1.5, 2.5);
    plots.AddHisto1D("Nm1_Chi2", 10, 0, 10);
    plots.AddHisto1D("Nm1_dZ", 100, -0.5, 0.5);
    plots.AddHisto1D("Nm1_dXY", 100, -0.1, 0.1);
    plots.AddHisto1D("Nm1_PFMiniIso", 400, 0, 0.05);
    plots.AddHisto1D("Nm1_TrkIso", 100, 0, 50);
    plots.AddHisto1D("Nm1_EoverP", 100, 0, 1);
    plots.AddHisto1D("Nm1_PtErr_over_PtPt", 100, 0, 0.001);
    plots.AddHisto1D("Nm1_Fpix", 100, 0, 1.1);
    plots.AddHisto1D("Nm1_PtErr_over_Pt", 100, 0, 0.5);
    plots.AddHisto1D("Nm1_Ih_StripOnly", 200, 0, 10);

    plots.AddHisto1D("Pt_lastBin", 100, 0, 2000);
    plots.AddHisto1D("HSCPtype_lastBin", 6, -0.5, 5.5);
    plots.AddHisto1D("PFtype_lastBin", 250, 0, 250);

    plots.AddHisto1D("RecoPFMET", 400, 0, 2000);
    plots.AddHisto1D("RecoPFMET___wCaloJetsCut", 400, 0, 2000);
    plots.AddHisto1D("RecoPFMET___wCaloMETCut", 400, 0, 2000);


    plots.AddHisto2D("LastBinEventCutflow___GenPt_vs_trackPt", 100, 0, 2500, 100, 0, 2500);
    plots.AddHisto1D("LastBinEventCutflow___HSCP_type", 6, -0.5, 5.5);
    plots.AddHisto1D("LastBinEventCutflow___PF_type", 250, 0, 250);


    // temp
    plots.AddHisto2D("trackPT_vs_trackPseudoTrackPT", 100, 0, 2500, 100, 0, 2500);
    plots.AddHisto2D("trackETA_vs_trackPseudoTrackETA", 60, -3, +3, 60, -3, +3);
    plots.AddHisto2D("trackPHI_vs_trackPseudoTrackPHI", 64, -3.2, 3.2, 64, -3.2, 3.2);
    plots.AddHisto2D("genPT_vs_trackPseudoTrackPT", 100, 0, 2500, 100, 0, 2500);
    plots.AddHisto2D("genPT_vs_trackPT", 100, 0, 2500, 100, 0, 2500);
    plots.AddHisto1D("PseudoTrack_m_gen_over_gen", 60, -3, +3);
    plots.AddHisto2D("gen__vs__PseudoTrack_m_gen_over_gen", 100, 0, 2500, 60, -3, +3);
    plots.AddHisto1D("Track_m_gen_over_gen", 60, -3, +3);
    plots.AddHisto2D("gen__vs__Track_m_gen_over_gen", 100, 0, 2500, 60, -3, +3);

    
    vcp_nosel.push_back(std::move(plots));

    std::cout << "Got ouf of loop on selections_" <<std::endl;
}

Bool_t HSCPSelector::Process(Long64_t entry)
{
    fReader.SetEntry(entry);

    //----------------------------------
    //Loop over all HSCP candidates
    //----------------------------------
    vector<int> iCand(selLabels_.size(),-1);
    vector<float> maxIh(selLabels_.size(),-1);

    std::vector<bool> eventCuts(19, false);
    std::vector<bool> eventCuts_noTrackCut(19, false);
    std::vector<bool> singleCut(19, false);

    bool trigger = false;
    bool METfilters = false;
    float CaloMET_pseudoMET = -1;
    if (dataset_.find("Mu50") != std::string::npos) {
        //trigger = *HLT_Mu50;
        trigger = *HLT_FilterOR;
        METfilters = true; // no MET filters in muon datasets
        CaloMET_pseudoMET = 200; // no CaloMET in muon datasets, set it to pass the cut
    }
    else if (dataset_.find("MET") != std::string::npos) {
        //trigger = *HLT_PFMET120_PFMHT120_IDTight || *HLT_PFHT500_PFMET100_PFMHT100_IDTight
        //|| *HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 || *HLT_MET105_IsoTrk50;
        trigger = *HLT_FilterOR;

        METfilters = Flag_allMETFilters[0];
        CaloMET_pseudoMET = 200; // to change with CaloJets[0];
    }
    vcp_nosel[0].FillHisto1D("CandidateCutflow", 0); // All events
    
    
    singleCut[0] = trigger;
    if (singleCut[0]) {
        vcp_nosel[0].FillHisto1D("EventCutflow", 1.5);
        vcp_nosel[0].FillHisto1D("EventCutflow_NotrackCut", 1.5);
    }
    singleCut[1] = singleCut[0] && METfilters;
    if (singleCut[1]) {
        vcp_nosel[0].FillHisto1D("EventCutflow", 2.5);
        vcp_nosel[0].FillHisto1D("EventCutflow_NotrackCut", 2.5);
    }
    singleCut[2] = singleCut[1] && (CaloMET_pseudoMET > 170.);
    if (singleCut[2]) {
        vcp_nosel[0].FillHisto1D("EventCutflow", 3.5);
        vcp_nosel[0].FillHisto1D("EventCutflow_NotrackCut", 3.5);
    }


        //
    vcp_nosel[0].FillHisto1D("Trigger", *HLT_FilterOR);
    vcp_nosel[0].FillHisto1D("RecoPFMET", RecoPFMET[0]);
    if (CaloJets[0] > 170) vcp_nosel[0].FillHisto1D("RecoPFMET___wCaloJetsCut", RecoPFMET[0]);
    //if (RecoCaloMET[0] > 170) vcp_nosel[0].FillHisto1D("RecoPFMET___wCaloMETCut", RecoPFMET[0]);


    unsigned int i = 0;
    for (unsigned int j=0; j<HSCP_hasTrack.GetSize(); j++){

        if (!HSCP_hasTrack[j]) continue;

            //TAKE MOST IONIZING CANDIDATE
        for(unsigned int s=0;s<selections_.size();s++){
            bool (HSCPSelector::*ptr)(int);
            ptr = selections_[s];
            if((this->*ptr)(i)){
                if(Ih_Strip[i]>maxIh[s]){
                    maxIh[s]=Ih_Strip[i];
                    iCand[s]=i;
                }
            }
        }

        // CUTFLOW
        singleCut[3] = singleCut[2] && (Pt[i] > 55.);
        singleCut[4] = singleCut[3] && (fabs(Eta[i]) < 2.4);
        singleCut[5] = singleCut[4] && (NbPixelHit_noL1[i] >= 2);
        singleCut[6] = singleCut[5] && (FracOfValidHit[i] > 0.8);
        singleCut[7] = singleCut[6] && (NOM_noL1[i] >= 10);
        singleCut[8] = singleCut[7] && isHighPurityTrack[i];
        singleCut[9] = singleCut[8] && (normChi2[i] < 5);
        singleCut[10] = singleCut[9] && (fabs(dz[i]) < 0.1);
        singleCut[11] = singleCut[10] && (fabs(dxy[i]) < 0.02);
        singleCut[12] = singleCut[11] && (miniRelIsoAll[i] < 0.02);
        singleCut[13] = singleCut[12] && (IsoSumPt_dr03[i] < 15);
        singleCut[14] = singleCut[13] && (EoP[i] < 0.3);
        singleCut[15] = singleCut[14] && (ptOverptErrptErr[i] < 0.0008);
        singleCut[16] = singleCut[15] && (Fpix[i] > 0.3);
        singleCut[17] = singleCut[16] && (ptOverptErr[i] < 1);
        singleCut[18] = singleCut[17] && (Ih_Strip[i] > 3.14);

            // candidate CUTFLOW
        for (unsigned int j = 0; j < singleCut.size(); j++) {
            if (singleCut[j]) vcp_nosel[0].FillHisto1D("CandidateCutflow", j+1);
        }


        std::vector<std::function<bool(int)>> cuts;
        cuts.push_back([&](int i){ return trigger; });
        cuts.push_back([&](int i){ return METfilters; });
        cuts.push_back([&](int i){ return CaloMET_pseudoMET > 170; });
        cuts.push_back([&](int i){ return Pt[i] > 55.0; });
        cuts.push_back([&](int i){ return fabs(Eta[i]) < 2.4; });
        cuts.push_back([&](int i){ return NbPixelHit_noL1[i] >= 2; });
        cuts.push_back([&](int i){ return FracOfValidHit[i] > 0.8; });
        cuts.push_back([&](int i){ return NOM_noL1[i] >= 10; });
        cuts.push_back([&](int i){ return isHighPurityTrack[i]; });
        cuts.push_back([&](int i){ return normChi2[i] < 5.0; });
        cuts.push_back([&](int i){ return fabs(dz[i]) < 0.1; });
        cuts.push_back([&](int i){ return fabs(dxy[i]) < 0.02; });
        cuts.push_back([&](int i){ return miniRelIsoAll[i] < 0.02; });
        cuts.push_back([&](int i){ return IsoSumPt_dr03[i] < 15; });
        cuts.push_back([&](int i){ return EoP[i] < 0.3; });
        cuts.push_back([&](int i){ return ptOverptErrptErr[i] < 0.0008; });
        cuts.push_back([&](int i){ return Fpix[i] > 0.3; });
        cuts.push_back([&](int i){ return ptOverptErr[i] < 1; });
        cuts.push_back([&](int i){ return Ih_Strip[i] > 3.14; });
        

            // Event CUTFLOW setup
        bool allPassed = true;
        for (unsigned int j = 0; j < cuts.size(); ++j) {
            if (allPassed && cuts[j](i)) eventCuts[j] = true;
            else allPassed = false;
        }

            // Event CUTFLOW without track cuts
        std::vector<std::function<bool(int)>> cuts_NotrackCut = cuts;
        cuts_NotrackCut[3] = [&](int i){ return true; }; // Pt
        cuts_NotrackCut[12] = [&](int i){ return true; }; // miniRelIsoAll
        cuts_NotrackCut[13] = [&](int i){ return true; }; // IsoSumPt_dr03
        cuts_NotrackCut[14] = [&](int i){ return true; }; // EoP
        cuts_NotrackCut[15] = [&](int i){ return true; }; // ptOverptErrptErr
        cuts_NotrackCut[17] = [&](int i){ return true; }; // ptOverptErr

        bool allPassed_NotrackCut = true;
        for (unsigned int j = 0; j < cuts.size(); ++j) {
            if (allPassed_NotrackCut && cuts_NotrackCut[j](i)) eventCuts_noTrackCut[j] = true;
            else allPassed_NotrackCut = false;
        }

            // N-1 candidate CUTFLOW
        std::vector <bool> passedCuts(cuts.size(), true);
        for (unsigned int icut = 0; icut < cuts.size(); ++icut) {
            for (unsigned int j = 0; j < cuts.size(); ++j) {
                if (j == icut) continue;
                if (!cuts[j](i)) {
                    passedCuts[icut] = false;
                    break;
                }
            }
        }

        if (passedCuts[0]) vcp_nosel[0].FillHisto1D("Nm1_trigger", trigger);
        if (passedCuts[1]) vcp_nosel[0].FillHisto1D("Nm1_METfilters", METfilters);
        if (passedCuts[2]) vcp_nosel[0].FillHisto1D("Nm1_CaloMET", CaloMET_pseudoMET);
        if (passedCuts[3]) vcp_nosel[0].FillHisto1D("Nm1_Pt", Pt[i]);
        if (passedCuts[4]) vcp_nosel[0].FillHisto1D("Nm1_eta", Eta[i]);
        if (passedCuts[5]) vcp_nosel[0].FillHisto1D("Nm1_NOPH", NbPixelHit_noL1[i]);
        if (passedCuts[6]) vcp_nosel[0].FillHisto1D("Nm1_FOVH", FracOfValidHit[i]);
        if (passedCuts[7]) vcp_nosel[0].FillHisto1D("Nm1_NOM", NOM_noL1[i]);
        if (passedCuts[8]) vcp_nosel[0].FillHisto1D("Nm1_HighPurity", isHighPurityTrack[i]);
        if (passedCuts[9]) vcp_nosel[0].FillHisto1D("Nm1_Chi2", normChi2[i]);
        if (passedCuts[10]) vcp_nosel[0].FillHisto1D("Nm1_dZ", dz[i]);
        if (passedCuts[11]) vcp_nosel[0].FillHisto1D("Nm1_dXY", dxy[i]);
        if (passedCuts[12]) vcp_nosel[0].FillHisto1D("Nm1_PFMiniIso", miniRelIsoAll[i]);
        if (passedCuts[13]) vcp_nosel[0].FillHisto1D("Nm1_TrkIso", IsoSumPt_dr03[i]);
        if (passedCuts[14]) vcp_nosel[0].FillHisto1D("Nm1_EoverP", EoP[i]);
        if (passedCuts[15]) vcp_nosel[0].FillHisto1D("Nm1_PtErr_over_PtPt", ptOverptErrptErr[i]);
        if (passedCuts[16]) vcp_nosel[0].FillHisto1D("Nm1_Fpix", Fpix[i]);
        if (passedCuts[17]) vcp_nosel[0].FillHisto1D("Nm1_PtErr_over_Pt", ptOverptErr[i]);
        if (passedCuts[18]) vcp_nosel[0].FillHisto1D("Nm1_Ih_StripOnly", Ih_Strip[i]);


            // Event cutflow last bin: check GenPart info and PF_type
        if (eventCuts[18]) {
            for (unsigned int j = 0; j < GenPart_pt.GetSize(); j++) {
                float dEta = GenPart_eta[j] - Eta[i];
                float dPhi = GenPart_phi[j] - Phi[i];
                while (dPhi >  M_PI) dPhi -= 2*M_PI;
                while (dPhi < -M_PI) dPhi += 2*M_PI;
                if (std::sqrt(dEta*dEta + dPhi*dPhi) < 0.01) vcp_nosel[0].FillHisto2D("LastBinEventCutflow___GenPt_vs_trackPt", GenPart_pt[j], Pt[i]);
            }
            vcp_nosel[0].FillHisto1D("LastBinEventCutflow___HSCP_type", HSCP_type[i]);
            vcp_nosel[0].FillHisto1D("LastBinEventCutflow___PF_type", PF_type[i]);
        }

        i++;
    } //End of loop over all HSCP candidates

    // Event CUTFLOW
    vcp_nosel[0].FillHisto1D("EventCutflow", 0.5); // All events
    for (unsigned int j = 3; j < 19; ++j) { // cuts length
        if (eventCuts[j]) vcp_nosel[0].FillHisto1D("EventCutflow", j+1.5);
    }

    vcp_nosel[0].FillHisto1D("EventCutflow_NotrackCut", 0.5); // All events
    for (unsigned int j = 3; j < 19; ++j) { // cuts length
        if (eventCuts_noTrackCut[j]) vcp_nosel[0].FillHisto1D("EventCutflow_NotrackCut", j+1.5);
    }



    bool AtLeastOneSelPassed = false;
    i = 0;
    for(unsigned int j=0; j<HSCP_hasTrack.GetSize(); j++){    // Every candidate

        if (!HSCP_hasTrack[j]) continue;

            // temp
        vcp_nosel[0].FillHisto2D("trackPT_vs_trackPseudoTrackPT", Pt[i], Pt_pseudo[i]);
        vcp_nosel[0].FillHisto2D("trackETA_vs_trackPseudoTrackETA", Eta[i], Eta_pseudo[i]);
        vcp_nosel[0].FillHisto2D("trackPHI_vs_trackPseudoTrackPHI", Phi[i], Phi_pseudo[i]);

        // loop over the generated particles
        for (unsigned int k = 0; k < GenPart_pt.GetSize(); k++) {
            float dEta = GenPart_eta[k] - Eta[i];
            float dPhi = GenPart_phi[k] - Phi[i];
            while (dPhi >  M_PI) dPhi -= 2*M_PI;
            while (dPhi < -M_PI) dPhi += 2*M_PI;
            if (std::sqrt(dEta*dEta + dPhi*dPhi) < 0.01 && fabs(GenPart_pdgId[k]) > 100000 ) {
                vcp_nosel[0].FillHisto2D("genPT_vs_trackPseudoTrackPT", GenPart_pt[i] , Pt_pseudo[i]);
                vcp_nosel[0].FillHisto2D("genPT_vs_trackPT", GenPart_pt[i], Pt[i]);

                vcp_nosel[0].FillHisto1D("PseudoTrack_m_gen_over_gen", (Pt_pseudo[i]-GenPart_pt[i])/GenPart_pt[i]);
                vcp_nosel[0].FillHisto2D("gen__vs__PseudoTrack_m_gen_over_gen", GenPart_pt[i], (Pt_pseudo[i]-GenPart_pt[i])/GenPart_pt[i]);
                vcp_nosel[0].FillHisto1D("Track_m_gen_over_gen", (Pt[i]-GenPart_pt[i])/GenPart_pt[i]);
                vcp_nosel[0].FillHisto2D("gen__vs__Track_m_gen_over_gen", GenPart_pt[i], (Pt[i]-GenPart_pt[i])/GenPart_pt[i]);
            }
        }
        

        for(unsigned int s=0;s<selections_.size();s++){ 
            bool (HSCPSelector::*ptr)(int);
            ptr = selections_[s];
            if((this->*ptr)(i)){

                AtLeastOneSelPassed = true;

                //int i = iCand[s];     // most ionising candidate
                //if (i < 0) continue;

                /*if (selections_[s]) {
                    vcp[s].FillHisto1D(selLabels_[s]+"_Ih", Ih_Strip[i]);
                    vcp[s].FillHisto1D(selLabels_[s]+"_Pt", Pt[i]);
                    vcp[s].FillHisto1D(selLabels_[s]+"_Eta", Eta[i]);
                    vcp[s].FillHisto1D(selLabels_[s]+"_NbPixelHit_noL1", NbPixelHit_noL1[i]);
                    vcp[s].FillHisto1D(selLabels_[s]+"_NOM_noL1", NOM_noL1[i]);
                    vcp[s].FillHisto1D(selLabels_[s]+"_FracOfValidHit", FracOfValidHit[i]);
                    vcp[s].FillHisto1D(selLabels_[s]+"_isHighPurityTrack", isHighPurityTrack[i]);
                    vcp[s].FillHisto1D(selLabels_[s]+"_miniRelIsoAll", miniRelIsoAll[i]);
                    vcp[s].FillHisto1D(selLabels_[s]+"_IsoSumPt_dr03", IsoSumPt_dr03[i]);
                    vcp[s].FillHisto1D(selLabels_[s]+"_dz", dz[i]);
                    vcp[s].FillHisto1D(selLabels_[s]+"_dxy", dxy[i]);
                    vcp[s].FillHisto1D(selLabels_[s]+"_normChi2", normChi2[i]);
                    vcp[s].FillHisto1D(selLabels_[s]+"_EoP", EoP[i]);
                    vcp[s].FillHisto1D(selLabels_[s]+"_ptOverptErrptErr", ptOverptErrptErr[i]);
                    vcp[s].FillHisto1D(selLabels_[s]+"_ptOverptErr", ptOverptErr[i]);
                    vcp[s].FillHisto1D(selLabels_[s]+"_Fpix", Fpix[i]);
                    vcp[s].FillHisto1D(selLabels_[s]+"_GStrip", GStrip[i]);
                    vcp[s].FillHisto1D(selLabels_[s]+"_HSCP_type", HSCP_type[i]);
                    vcp[s].FillHisto1D(selLabels_[s]+"_PF_type", PF_type[i]);

                    if (PF_type[i]==13) {
                        for(unsigned int j=0; j<Muon_pt.GetSize(); j++) {
                            float dEta = Muon_eta[j] - Eta[i];
                            float dPhi = Muon_phi[j] - Phi[i];
                            while (dPhi >  M_PI) dPhi -= 2*M_PI;
                            while (dPhi < -M_PI) dPhi += 2*M_PI;
                            if (std::sqrt(dEta*dEta + dPhi*dPhi) < 0.1) { vcp[s].FillHisto1D(selLabels_[s]+"_Pt_PFMuon", Pt[i]); break; }
                        }
                    }
                    else if (PF_type[i]==211 || PF_type[i]==11) vcp[s].FillHisto1D(selLabels_[s]+"_Pt_PFChgHadron", Pt[i]);
                    else vcp[s].FillHisto1D(selLabels_[s]+"_Pt_other", Pt[i]);
                }*/



            }
        }

        /*if (isAOD) {
            for (unsigned int j=0; j<OnlyIn_AOD.size(); j++) {
                if (*Event == OnlyIn_AOD[j]) {
                    vcp_nosel[0].FillHisto1D("Pt_lastBin", Pt[i]);
                    vcp_nosel[0].FillHisto1D("HSCPtype_lastBin", HSCP_type[i]);
                    vcp_nosel[0].FillHisto1D("PFtype_lastBin", PF_type[i]);
                    break;
                }
            }
        }
        if (isMiniAOD) {
            for (unsigned int j=0; j<OnlyIn_MiniAOD.size(); j++) {
                if (*Event == OnlyIn_MiniAOD[j]) {
                    vcp_nosel[0].FillHisto1D("Pt_lastBin", Pt[i]);
                    vcp_nosel[0].FillHisto1D("HSCPtype_lastBin", HSCP_type[i]);
                    vcp_nosel[0].FillHisto1D("PFtype_lastBin", PF_type[i]);
                    break;
                }
            }
        }*/
        i++;

    } // End of loop over all candidates


    // for all event, compute the trigger efficiency vs the caloJets
    for(unsigned int s=0;s<selections_.size();s++) { 
        bool SelPassed = false;

        for(unsigned int j=0; j<HSCP_hasTrack.GetSize(); j++){
            if (!HSCP_hasTrack[j]) continue;
            if ((this->*selections_[s])(j)) SelPassed = true;
        }

        if (SelPassed) {

            // Trigger efficiency
            vcp[s].FillHisto1D(selLabels_[s]+"_CaloJets", CaloJets[0]);
            vcp[s].FillHisto1D(selLabels_[s]+"_RecoPFMET", RecoPFMET[0]);
            if (*HLT_PFMET120_PFMHT120_IDTight) {
                vcp[s].FillHisto1D(selLabels_[s]+"_if___HLT_PFMET120_PFMHT120_IDTight___CaloJets", CaloJets[0]);
                vcp[s].FillHisto1D(selLabels_[s]+"_if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET", RecoPFMET[0]);                
            }
            if (*HLT_PFHT500_PFMET100_PFMHT100_IDTight) {
                vcp[s].FillHisto1D(selLabels_[s]+"_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___CaloJets", CaloJets[0]);
                vcp[s].FillHisto1D(selLabels_[s]+"_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET", RecoPFMET[0]);
            }
            if (*HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60) {
                vcp[s].FillHisto1D(selLabels_[s]+"_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___CaloJets", CaloJets[0]);
                vcp[s].FillHisto1D(selLabels_[s]+"_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET", RecoPFMET[0]);
            }
            if (*HLT_MET105_IsoTrk50) {
                vcp[s].FillHisto1D(selLabels_[s]+"_if___HLT_MET105_IsoTrk50___CaloJets", CaloJets[0]);
                vcp[s].FillHisto1D(selLabels_[s]+"_if___HLT_MET105_IsoTrk50___RecoPFMET", RecoPFMET[0]);
            }
            if (*HLT_PFMET120_PFMHT120_IDTight || *HLT_PFHT500_PFMET100_PFMHT100_IDTight
                || *HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 || *HLT_MET105_IsoTrk50) {
                vcp[s].FillHisto1D(selLabels_[s]+"_if___orMETtrg___CaloJets", CaloJets[0]);
                vcp[s].FillHisto1D(selLabels_[s]+"_if___orMETtrg___RecoPFMET", RecoPFMET[0]);
            }

            /*if (isAOD) {

                vcp[s].FillHisto1D(selLabels_[s]+"_RecoCaloMET", RecoCaloMET[0]);
                if (*HLT_PFMET120_PFMHT120_IDTight) vcp[s].FillHisto1D(selLabels_[s]+"_if___HLT_PFMET120_PFMHT120_IDTight___RecoCaloMET", RecoCaloMET[0]);                
                if (*HLT_PFHT500_PFMET100_PFMHT100_IDTight) vcp[s].FillHisto1D(selLabels_[s]+"_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoCaloMET", RecoCaloMET[0]);
                if (*HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60) vcp[s].FillHisto1D(selLabels_[s]+"_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoCaloMET", RecoCaloMET[0]);
                if (*HLT_MET105_IsoTrk50) vcp[s].FillHisto1D(selLabels_[s]+"_if___HLT_MET105_IsoTrk50___RecoCaloMET", RecoCaloMET[0]);
                if (*HLT_PFMET120_PFMHT120_IDTight || *HLT_PFHT500_PFMET100_PFMHT100_IDTight
                    || *HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 || *HLT_MET105_IsoTrk50)
                    vcp[s].FillHisto1D(selLabels_[s]+"_if___orMETtrg___RecoCaloMET", RecoCaloMET[0]);
                
            }*/

        }
    }

   return kTRUE;
}


void HSCPSelector::SlaveTerminate()
{
    for(auto obj: vcp) obj.AddToList(fOutput);
    for(auto obj: vcp_nosel) obj.AddToList(fOutput);
}

void HSCPSelector::Terminate()
{
    //create the output file
    std::cout << std::endl;
    std::cout << "We are in Terminate function, on client side" << std::endl;
    fout = new TFile(oFile_.c_str(),"RECREATE");

    //loop over all elements stored
    TIter next(fOutput);
    TObject* object = nullptr;
    while ((object = next())){
        const_cast<TObject*>(object)->Write();
    }

    //write and close the output file
    const_cast<TFile*>(fout)->Write();
    fout->Close();
}