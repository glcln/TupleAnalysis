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
float K_data2024(2.8202), C_data2024(2.9784); //Data 2024



//ADD-SELECTION-METHODS
bool HSCPSelector::PassHSCPpresel_METanalysis_PseudoMETrescaled_Eta1_2p4_newIhcut(int i){
   if (i<0 || i>(int)Pt.GetSize()) {
      cout << i << endl;
      return false;
   }
   return (( (*HLT_PFMET120_PFMHT120_IDTight || *HLT_PFHT500_PFMET100_PFMHT100_IDTight || *HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 || *HLT_MET105_IsoTrk50) && (Flag_allMETFilters[0] == true) && (PseudoCaloMET[0]*163.451/146.864 > 170.) && (Pt[i] > 50.0) && (Pt_pseudo[i] > 50.0) && (abs(Eta[i]) < 2.4) && (abs(Eta[i]) >= 1) && (NbPixelHit_noL1[i] >= 2) && (FracOfValidHit[i] > 0.8) && (NOM_noL1[i] >= 10) && (isHighPurityTrack[i] == true) && (normChi2[i] < 5.0) && (abs(dz[i]) < 0.1) && (abs(dxy[i]) < 0.02) && (miniRelIsoAll[i] < 0.02) && (EoP[i] < 0.3) && (IsoSumPt_dr03[i] < 15) && (ptOverptErrptErr[i] < 0.0008) && (Fpix[i] > 0.3) && (ptOverptErr[i] < 1) && (Ih_Strip[i] > 4.1) ));
}



void HSCPSelector::Begin(TTree *tree)
{
    TString option = GetOption();
    TObjArray *tx = option.Tokenize(",");

    // Output file
    oFile_ = ((TObjString *)(tx->At(7)))->String().Data();
    oFile_ += "_";
    oFile_ += ((TObjString *)(tx->At(8)))->String().Data();
    oFile_ += ".root";


    // Options
    UseFpixel = true;

    // Fill the SF;
    SFisUp = false; SFisDown = false;
    loadSF("PlayWithHistos/SF_TriggerEff_Mu2024_WMuNu_PseudoMETrescaled.txt", SFisUp, SFisDown, SF_PseudoMETvalue, SF_triggerEff);
    loadSF("PlayWithHistos/SF_TriggerEff_Mu2024_WMuNu_PseudoMET.txt", SFisUp, SFisDown, SF_PseudoMETvalue_NOTrescaled, SF_triggerEff_NOTrescaled);
    
    SFisUp = true; SFisDown = false;
    loadSF("PlayWithHistos/SF_TriggerEff_Mu2024_WMuNu_PseudoMETrescaled.txt", SFisUp, SFisDown, SF_PseudoMETvalue_Up, SF_triggerEff_Up);
    SFisUp = false; SFisDown = true;
    loadSF("PlayWithHistos/SF_TriggerEff_Mu2024_WMuNu_PseudoMETrescaled.txt", SFisUp, SFisDown, SF_PseudoMETvalue_Down, SF_triggerEff_Down);
    


    //FILL-SELECTION-VECTOR
selections_.push_back(&HSCPSelector::PassHSCPpresel_METanalysis_PseudoMETrescaled_Eta1_2p4_newIhcut);
selLabels_.push_back("METanalysis_PseudoMETrescaled_Eta1_2p4_newIhcut");


    std::cout << std::endl;
    std::cout << "Number of selections: " << selLabels_.size() << std::endl;
    std::cout << "Output file: " << oFile_.c_str() << std::endl;
    std::cout << std::endl;
}



void HSCPSelector::SlaveBegin(TTree *tree)
{
    TString option = GetOption();
    TObjArray *tx = option.Tokenize(",");

    std::string dataset( ((TObjString *)(tx->At(7)))->String().Data());
    dataset_ = dataset;
    std::string ptTmp( ((TObjString *)(tx->At(0)))->String().Data());
    ptcut_ = std::stod(ptTmp);
    std::string etaTmp( ((TObjString *)(tx->At(1)))->String().Data());
    etabins_ = std::stoi(etaTmp);
    std::string ihTmp( ((TObjString *)(tx->At(2)))->String().Data());
    ihbins_ = std::stoi(ihTmp); 
    std::string pTmp( ((TObjString *)(tx->At(3)))->String().Data());
    pbins_ = std::stoi(pTmp);
    std::string massTmp( ((TObjString *)(tx->At(4)))->String().Data());
    massbins_ = std::stoi(massTmp);
    std::string fpixCutTmp( ((TObjString *)(tx->At(6)))->String().Data());
    fpixbins_ = std::stoi(fpixCutTmp);


    if(dataset_.find("2024") != std::string::npos || dataset_.find("Gluino") != std::string::npos) {//dataset_ == "Gluino2000"){ 
        K = K_data2024;
        C = C_data2024;
    }


    //-------------------------------------
    //create RegionMassPlot for all selection
    //-------------------------------------
    for(unsigned int i=0; i<selLabels_.size();i++)
    {
        if(UseFpixel) {
            cout << "Initialisation of the regions for selection: " << selLabels_[i] << endl;

            //Create names for each plot in each regions (slices in Fpixels)
            std::string label_FpixAll = regFpixAll + "_" + selLabels_[i]; 
            
            std::string label_FpixA_3f4 = regFpixA_3f4 + "_" + selLabels_[i]; 
            std::string label_FpixA_3f6 = regFpixA_3f6 + "_" + selLabels_[i]; 
            std::string label_FpixA_3f8 = regFpixA_3f8 + "_" + selLabels_[i]; 
            std::string label_FpixA_3f9 = regFpixA_3f9 + "_" + selLabels_[i]; 
            std::string label_FpixA_4f5 = regFpixA_4f5 + "_" + selLabels_[i]; 
            std::string label_FpixA_5f6 = regFpixA_5f6 + "_" + selLabels_[i]; 
            std::string label_FpixA_6f7 = regFpixA_6f7 + "_" + selLabels_[i]; 
            std::string label_FpixA_6f9 = regFpixA_6f9 + "_" + selLabels_[i]; 
            std::string label_FpixA_7f8 = regFpixA_7f8 + "_" + selLabels_[i]; 
            std::string label_FpixA_8f9 = regFpixA_8f9 + "_" + selLabels_[i]; 
            std::string label_FpixA_9f10 = regFpixA_9f10 + "_" + selLabels_[i];
            std::string label_FpixA_99f10 = regFpixA_99f10 + "_" + selLabels_[i];
            std::string label_FpixA_999f10 = regFpixA_999f10 + "_" + selLabels_[i];

            std::string label_FpixB_3f4 = regFpixB_3f4 + "_" + selLabels_[i]; 
            std::string label_FpixB_3f6 = regFpixB_3f6 + "_" + selLabels_[i]; 
            std::string label_FpixB_3f8 = regFpixB_3f8 + "_" + selLabels_[i]; 
            std::string label_FpixB_3f9 = regFpixB_3f9 + "_" + selLabels_[i]; 
            std::string label_FpixB_4f5 = regFpixB_4f5 + "_" + selLabels_[i]; 
            std::string label_FpixB_5f6 = regFpixB_5f6 + "_" + selLabels_[i]; 
            std::string label_FpixB_6f7 = regFpixB_6f7 + "_" + selLabels_[i]; 
            std::string label_FpixB_6f9 = regFpixB_6f9 + "_" + selLabels_[i]; 
            std::string label_FpixB_7f8 = regFpixB_7f8 + "_" + selLabels_[i]; 
            std::string label_FpixB_8f9 = regFpixB_8f9 + "_" + selLabels_[i]; 
            std::string label_FpixB_8f10 = regFpixB_8f10 + "_" + selLabels_[i];
            std::string label_FpixB_9f10 = regFpixB_9f10 + "_" + selLabels_[i];
            std::string label_FpixB_99f10 = regFpixB_99f10 + "_" + selLabels_[i];
            std::string label_FpixB_999f10 = regFpixB_999f10 + "_" + selLabels_[i];

            std::string label_FpixC_3f4 = regFpixC_3f4 + "_" + selLabels_[i]; 
            std::string label_FpixC_3f6 = regFpixC_3f6 + "_" + selLabels_[i]; 
            std::string label_FpixC_3f8 = regFpixC_3f8 + "_" + selLabels_[i]; 
            std::string label_FpixC_3f9 = regFpixC_3f9 + "_" + selLabels_[i]; 
            std::string label_FpixC_4f5 = regFpixC_4f5 + "_" + selLabels_[i]; 
            std::string label_FpixC_5f6 = regFpixC_5f6 + "_" + selLabels_[i]; 
            std::string label_FpixC_6f7 = regFpixC_6f7 + "_" + selLabels_[i]; 
            std::string label_FpixC_6f9 = regFpixC_6f9 + "_" + selLabels_[i]; 
            std::string label_FpixC_7f8 = regFpixC_7f8 + "_" + selLabels_[i]; 
            std::string label_FpixC_8f9 = regFpixC_8f9 + "_" + selLabels_[i]; 

            std::string label_FpixD_3f4 = regFpixD_3f4 + "_" + selLabels_[i];
            std::string label_FpixD_3f8 = regFpixD_3f8 + "_" + selLabels_[i];
            std::string label_FpixD_4f5 = regFpixD_4f5 + "_" + selLabels_[i]; 
            std::string label_FpixD_5f6 = regFpixD_5f6 + "_" + selLabels_[i]; 
            std::string label_FpixD_6f7 = regFpixD_6f7 + "_" + selLabels_[i]; 
            std::string label_FpixD_6f9 = regFpixD_6f9 + "_" + selLabels_[i];
            std::string label_FpixD_7f8 = regFpixD_7f8 + "_" + selLabels_[i]; 
            std::string label_FpixD_8f9 = regFpixD_8f9 + "_" + selLabels_[i]; 
            std::string label_FpixD_8f10 = regFpixD_8f10 + "_" + selLabels_[i];
            std::string label_FpixD_9f10 = regFpixD_9f10 + "_" + selLabels_[i]; 
            std::string label_FpixD_99f10 = regFpixD_99f10 + "_" + selLabels_[i]; 
            std::string label_FpixD_999f10 = regFpixD_999f10 + "_" + selLabels_[i]; 


            //Create objects RegionMassPlot using the names defined above 
            RegionMassPlot regAll(label_FpixAll.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 

            RegionMassPlot regA_3f4(label_FpixA_3f4.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C);
            RegionMassPlot regA_3f6(label_FpixA_3f6.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regA_3f8(label_FpixA_3f8.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regA_3f9(label_FpixA_3f9.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regA_4f5(label_FpixA_4f5.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regA_5f6(label_FpixA_5f6.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regA_6f7(label_FpixA_6f7.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C);
            RegionMassPlot regA_6f9(label_FpixA_6f9.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C);
            RegionMassPlot regA_7f8(label_FpixA_7f8.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C);
            RegionMassPlot regA_8f9(label_FpixA_8f9.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regA_9f10(label_FpixA_9f10.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regA_99f10(label_FpixA_99f10.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regA_999f10(label_FpixA_999f10.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 

            RegionMassPlot regB_3f4(label_FpixB_3f4.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regB_3f6(label_FpixB_3f6.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regB_3f8(label_FpixB_3f8.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regB_3f9(label_FpixB_3f9.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regB_4f5(label_FpixB_4f5.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regB_5f6(label_FpixB_5f6.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regB_6f7(label_FpixB_6f7.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regB_6f9(label_FpixB_6f9.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regB_7f8(label_FpixB_7f8.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C);     
            RegionMassPlot regB_8f9(label_FpixB_8f9.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regB_8f10(label_FpixB_8f10.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regB_9f10(label_FpixB_9f10.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regB_99f10(label_FpixB_99f10.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regB_999f10(label_FpixB_999f10.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C);

            RegionMassPlot regC_3f4(label_FpixC_3f4.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regC_3f6(label_FpixC_3f6.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regC_3f8(label_FpixC_3f8.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regC_3f9(label_FpixC_3f9.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regC_4f5(label_FpixC_4f5.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regC_5f6(label_FpixC_5f6.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regC_6f7(label_FpixC_6f7.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regC_6f9(label_FpixC_6f9.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regC_7f8(label_FpixC_7f8.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regC_8f9(label_FpixC_8f9.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 

            RegionMassPlot regD_3f4(label_FpixD_3f4.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regD_3f8(label_FpixD_3f8.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regD_4f5(label_FpixD_4f5.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regD_5f6(label_FpixD_5f6.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regD_6f7(label_FpixD_6f7.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regD_6f9(label_FpixD_6f9.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regD_7f8(label_FpixD_7f8.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C);     
            RegionMassPlot regD_8f9(label_FpixD_8f9.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regD_8f10(label_FpixD_8f10.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regD_9f10(label_FpixD_9f10.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regD_99f10(label_FpixD_99f10.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
            RegionMassPlot regD_999f10(label_FpixD_999f10.c_str(), etabins_, ihbins_, pbins_, massbins_, fpixbins_, C); 
        

            //push the RegionMassPlot objects created in vectors, because you have a set of different plot for each region, for each selection (defined in the configuration file) 

            vmrp_regionFpix_all.push_back(std::move(regAll));
            
            vmrp_regionA_3f4.push_back(std::move(regA_3f4));
            vmrp_regionA_3f6.push_back(std::move(regA_3f6));
            vmrp_regionA_3f8.push_back(std::move(regA_3f8));
            vmrp_regionA_3f9.push_back(std::move(regA_3f9));
            vmrp_regionA_4f5.push_back(std::move(regA_4f5));
            vmrp_regionA_5f6.push_back(std::move(regA_5f6));
            vmrp_regionA_6f7.push_back(std::move(regA_6f7));
            vmrp_regionA_6f9.push_back(std::move(regA_6f9));
            vmrp_regionA_7f8.push_back(std::move(regA_7f8));
            vmrp_regionA_8f9.push_back(std::move(regA_8f9));
            vmrp_regionA_9f10.push_back(std::move(regA_9f10));
            vmrp_regionA_99f10.push_back(std::move(regA_99f10));
            vmrp_regionA_999f10.push_back(std::move(regA_999f10));

            vmrp_regionB_3f4.push_back(std::move(regB_3f4));
            vmrp_regionB_3f6.push_back(std::move(regB_3f6));
            vmrp_regionB_3f8.push_back(std::move(regB_3f8));
            vmrp_regionB_3f9.push_back(std::move(regB_3f9));
            vmrp_regionB_4f5.push_back(std::move(regB_4f5));
            vmrp_regionB_5f6.push_back(std::move(regB_5f6));
            vmrp_regionB_6f7.push_back(std::move(regB_6f7));
            vmrp_regionB_6f9.push_back(std::move(regB_6f9));
            vmrp_regionB_7f8.push_back(std::move(regB_7f8));
            vmrp_regionB_8f9.push_back(std::move(regB_8f9));
            vmrp_regionB_8f10.push_back(std::move(regB_8f10));
            vmrp_regionB_9f10.push_back(std::move(regB_9f10));
            vmrp_regionB_99f10.push_back(std::move(regB_99f10));
            vmrp_regionB_999f10.push_back(std::move(regB_999f10));

            vmrp_regionC_3f4.push_back(std::move(regC_3f4));
            vmrp_regionC_3f6.push_back(std::move(regC_3f6));
            vmrp_regionC_3f8.push_back(std::move(regC_3f8));
            vmrp_regionC_3f9.push_back(std::move(regC_3f9));    
            vmrp_regionC_4f5.push_back(std::move(regC_4f5));
            vmrp_regionC_5f6.push_back(std::move(regC_5f6));
            vmrp_regionC_6f7.push_back(std::move(regC_6f7));
            vmrp_regionC_6f9.push_back(std::move(regC_6f9));
            vmrp_regionC_7f8.push_back(std::move(regC_7f8));
            vmrp_regionC_8f9.push_back(std::move(regC_8f9));

            vmrp_regionD_3f4.push_back(std::move(regD_3f4));
            vmrp_regionD_3f8.push_back(std::move(regD_3f8));
            vmrp_regionD_4f5.push_back(std::move(regD_4f5));
            vmrp_regionD_5f6.push_back(std::move(regD_5f6));
            vmrp_regionD_6f7.push_back(std::move(regD_6f7));
            vmrp_regionD_6f9.push_back(std::move(regD_6f9));
            vmrp_regionD_7f8.push_back(std::move(regD_7f8));
            vmrp_regionD_8f9.push_back(std::move(regD_8f9));
            vmrp_regionD_8f10.push_back(std::move(regD_8f10));
            vmrp_regionD_9f10.push_back(std::move(regD_9f10));
            vmrp_regionD_99f10.push_back(std::move(regD_99f10));
            vmrp_regionD_999f10.push_back(std::move(regD_999f10));
        }


        CPlots plots;

        // mass calibration
        // plots.AddHisto2F(selLabels_[i]+"_Mu_ih_vs_betagamma", 500, 0., 15000., 100, 0., 10.);
        // plots.AddHisto2F(selLabels_[i]+"_Mu_ih_vs_p", 500, 0., 6000., 100, 0.,10.);
        // plots.AddHisto2F(selLabels_[i]+"_KPpi_ih_vs_betagamma", 500, 0., 5000., 100, 0., 10.);
        // plots.AddHisto2F(selLabels_[i]+"_KPpi_ih_vs_p", 500, 0., 3000., 100, 0., 10.);
        // plots.AddHisto2F(selLabels_[i]+"_Gluino_ih_vs_betagamma", 1000, 0., 5., 500, 0., 50.);
        // plots.AddHisto2F(selLabels_[i]+"_Gluino_ih_vs_p", 500, 0., 3000., 500, 0.,50.);


        // Trigger efficiency
        plots.AddHisto1F(selLabels_[i]+"_L1MET", 40, 0, 1000);
        plots.AddHisto1F(selLabels_[i]+"_HLTCaloMET", 40, 0, 1000);
        plots.AddHisto1F(selLabels_[i]+"_HLTCaloMHT", 40, 0, 1000);
        plots.AddHisto1F(selLabels_[i]+"_HLTPFMHT", 40, 0, 1000);
        plots.AddHisto1F(selLabels_[i]+"_HLTPFMET", 40, 0, 1000);

        plots.AddHisto1F(selLabels_[i]+"_PuppiMET", 100, 0, 2500);
        
        plots.AddHisto1F(selLabels_[i]+"_PseudoCaloMET", 100, 0, 2500);
        plots.AddHisto1F(selLabels_[i]+"_PseudoCaloMET_rescaled", 200, 0, 2000);
        plots.AddHisto1F(selLabels_[i]+"_PseudoCaloMET_NOTrescaled", 200, 0, 2000);
        plots.AddHisto1F(selLabels_[i]+"_if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET", 100, 0, 2500);
        plots.AddHisto1F(selLabels_[i]+"_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET", 100, 0, 2500);
        plots.AddHisto1F(selLabels_[i]+"_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET", 100, 0, 2500);
        plots.AddHisto1F(selLabels_[i]+"_if___HLT_MET105_IsoTrk50___PseudoCaloMET", 100, 0, 2500);
        plots.AddHisto1F(selLabels_[i]+"_if___orMETtrg___PseudoCaloMET", 100, 0, 2500);

        plots.AddHisto1F(selLabels_[i]+"_RecoPFMET", 100, 0, 2500);
        plots.AddHisto1F(selLabels_[i]+"_if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET", 100, 0, 2500);
        plots.AddHisto1F(selLabels_[i]+"_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET", 100, 0, 2500);
        plots.AddHisto1F(selLabels_[i]+"_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET", 100, 0, 2500);
        plots.AddHisto1F(selLabels_[i]+"_if___HLT_MET105_IsoTrk50___RecoPFMET", 100, 0, 2500);
        plots.AddHisto1F(selLabels_[i]+"_if___orMETtrg___RecoPFMET", 100, 0, 2500);

        plots.AddHisto1F(selLabels_[i]+"_PseudoCaloMET__RecoPFMETCut", 100, 0, 2500); 
        plots.AddHisto1F(selLabels_[i]+"_if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET__RecoPFMETCut", 100, 0, 2500); 
        plots.AddHisto1F(selLabels_[i]+"_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET__RecoPFMETCut", 100, 0, 2500); 
        plots.AddHisto1F(selLabels_[i]+"_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET__RecoPFMETCut", 100, 0, 2500); 
        plots.AddHisto1F(selLabels_[i]+"_if___HLT_MET105_IsoTrk50___PseudoCaloMET__RecoPFMETCut", 100, 0, 2500); 
        plots.AddHisto1F(selLabels_[i]+"_if___orMETtrg___PseudoCaloMET__RecoPFMETCut", 100, 0, 2500); 

        plots.AddHisto1F(selLabels_[i]+"_RecoPFMET__PseudoCaloMETCut", 100, 0, 2500); 
        plots.AddHisto1F(selLabels_[i]+"_if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET__PseudoCaloMETCut", 100, 0, 2500); 
        plots.AddHisto1F(selLabels_[i]+"_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET__PseudoCaloMETCut", 100, 0, 2500);         
        plots.AddHisto1F(selLabels_[i]+"_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET__PseudoCaloMETCut", 100, 0, 2500); 
        plots.AddHisto1F(selLabels_[i]+"_if___HLT_MET105_IsoTrk50___RecoPFMET__PseudoCaloMETCut", 100, 0, 2500); 
        plots.AddHisto1F(selLabels_[i]+"_if___orMETtrg___RecoPFMET__PseudoCaloMETCut", 100, 0, 2500); 

        plots.AddHisto1F(selLabels_[i]+"_RecoCaloMET", 100, 0, 2500);
        plots.AddHisto1F(selLabels_[i]+"_if___HLT_PFMET120_PFMHT120_IDTight___RecoCaloMET", 100, 0, 2500);
        plots.AddHisto1F(selLabels_[i]+"_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoCaloMET", 100, 0, 2500);
        plots.AddHisto1F(selLabels_[i]+"_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoCaloMET", 100, 0, 2500);
        plots.AddHisto1F(selLabels_[i]+"_if___HLT_MET105_IsoTrk50___RecoCaloMET", 100, 0, 2500);
        plots.AddHisto1F(selLabels_[i]+"_if___orMETtrg___RecoCaloMET", 100, 0, 2500);
        

        // General plots
        plots.AddHisto1F(selLabels_[i]+"_nHSCP", 10, 0, 10);
        plots.AddHisto1F(selLabels_[i]+"_nPVgood", 150, 0, 150);
        plots.AddHisto1F(selLabels_[i]+"_ndEdx_StripOnly", 50, 0, 50);
        plots.AddHisto1F(selLabels_[i]+"_Ptpseudo", 300, 0, 3000);
        plots.AddHisto1F(selLabels_[i]+"_P", 200, 0, 8000);
        plots.AddHisto1F(selLabels_[i]+"_pT", 300, 0, 3000);
        plots.AddHisto1F(selLabels_[i]+"_10000oP", 300, 0, 300);
        plots.AddHisto2F(selLabels_[i]+"_10000oP_vs_Eta", 300, 0, 300, 60, -3, +3);
        plots.AddHisto1F(selLabels_[i]+"_eta", 60, -3, +3);
        plots.AddHisto1F(selLabels_[i]+"_phi", 64, -3.2, 3.2);
        plots.AddHisto1F(selLabels_[i]+"_PFMiniIso", 1000, 0, 0.5);
        plots.AddHisto1F(selLabels_[i]+"_TrkIso", 400, 0, 200);
        plots.AddHisto1F(selLabels_[i]+"_EoverP", 500, 0, 5);
        plots.AddHisto1F(selLabels_[i]+"_PtErr_over_PtPt", 500, 0, 0.01);
        plots.AddHisto1F(selLabels_[i]+"_Fpix", 21, 0, 1.1);
        plots.AddHisto1F(selLabels_[i]+"_PtErr_over_Pt", 800, 0, 4);
        plots.AddHisto1F(selLabels_[i]+"_Ih", 200, 0, 10);
        plots.AddHisto1F(selLabels_[i]+"_Ih_rescaled", 200, 0, 10);
        plots.AddHisto1F(selLabels_[i]+"_Ih_oldCorr", 200, 0, 10);
        plots.AddHisto1F(selLabels_[i]+"_Ih_noSF", 200, 0, 10);
        plots.AddHisto1F(selLabels_[i]+"_PthatQCD", 2000, 0, 2000);

        plots.AddHisto2F(selLabels_[i]+"_Fpix_vs_RunNumber", 5000, 378000, 388000, 20, 0, 1);
        plots.AddHisto2F(selLabels_[i]+"_Ih_vs_RunNumber", 5000, 378000, 388000, 200, 0, 10);
        plots.AddHisto2F(selLabels_[i]+"_Ih_oldCorr_vs_RunNumber", 5000, 378000, 388000, 200, 0, 10);
        plots.AddHisto2F(selLabels_[i]+"_NPV_vs_RunNumber", 5000, 378000, 388000, 150, 0, 150);
        
        plots.AddHisto2F(selLabels_[i]+"_Fpix_vs_IhnearC", 200, C-0.3, C+0.3, 20, 0, 1);
        plots.AddHisto2F(selLabels_[i]+"_pT_vs_Fpixel", 50, 0, 1, 100, 50, 1000);

        plots.AddHisto1F(selLabels_[i]+"_electron_pt", 2000, 0, 2000);
        plots.AddHisto1F(selLabels_[i]+"_electron_eta", 60, -3, +3);
        plots.AddHisto1F(selLabels_[i]+"_electron_phi", 64, -3.2, 3.2);
        plots.AddHisto1F(selLabels_[i]+"_muon_pt", 2000, 0, 2000);
        plots.AddHisto1F(selLabels_[i]+"_muon_eta", 60, -3, +3);
        plots.AddHisto1F(selLabels_[i]+"_muon_phi", 64, -3.2, 3.2);


        // Syst on signal
        plots.AddHisto1F(selLabels_[i]+"_9fp10_SignalMass_nominal", 400, 0, 4000);
        plots.AddHisto1F(selLabels_[i]+"_9fp10_SignalMass_PUUp", 400, 0, 4000);
        plots.AddHisto1F(selLabels_[i]+"_9fp10_SignalMass_PUDown", 400, 0, 4000);
        plots.AddHisto1F(selLabels_[i]+"_9fp10_SignalMass_FpixUp", 400, 0, 4000);
        plots.AddHisto1F(selLabels_[i]+"_9fp10_SignalMass_FpixDown", 400, 0, 4000);
        plots.AddHisto1F(selLabels_[i]+"_9fp10_SignalMass_TriggerSFUp", 400, 0, 4000);
        plots.AddHisto1F(selLabels_[i]+"_9fp10_SignalMass_TriggerSFDown", 400, 0, 4000);
        plots.AddHisto1F(selLabels_[i]+"_9fp10_SignalMass_KUp", 400, 0, 4000);
        plots.AddHisto1F(selLabels_[i]+"_9fp10_SignalMass_KDown", 400, 0, 4000);
        plots.AddHisto1F(selLabels_[i]+"_9fp10_SignalMass_CUp", 400, 0, 4000);
        plots.AddHisto1F(selLabels_[i]+"_9fp10_SignalMass_CDown", 400, 0, 4000);



        vcp.push_back(std::move(plots));
    }

        // Without selections
    CPlots plots;
    plots.AddHisto1D("CandidateCutflow", 20, 0, 20);
    plots.AddHisto1D("EventCutflow", 20, 0, 20);
    plots.AddHisto1D("EventCutflow_NotrackCut", 20, 0, 20);
    plots.AddHisto1D("EventCutflow__isGen_lastbin", 2, -0.5, 1.5);

    plots.AddHisto1F("nHSCP", 10, 0, 10);
    plots.AddHisto1F("nPVgood", 150, 0, 150);
    plots.AddHisto1F("ndEdx_StripOnly", 50, 0, 50);

    plots.AddHisto1F("Trigger", 3, -1, 2);

    plots.AddHisto1F("Nm1_trigger", 4, -1.5, 2.5);
    plots.AddHisto1F("Nm1_METfilters", 4, -1.5, 2.5);
    plots.AddHisto1F("Nm1_CaloMET", 200, 0, 2000);
    plots.AddHisto1F("Nm1_CaloMET_rescaled", 200, 0, 2000);
    plots.AddHisto1F("Nm1_CaloMET_OTHERrescaled", 200, 0, 2000);
    plots.AddHisto1F("Nm1_Ptpseudo", 300, 0, 3000);
    plots.AddHisto1F("Nm1_eta", 60, -3, +3);
    plots.AddHisto1F("Nm1_NOPH", 15, 0, 15);
    plots.AddHisto1F("Nm1_FOVH", 50, 0, 1.1);
    plots.AddHisto1F("Nm1_NOM", 50, 0, 50);
    plots.AddHisto1F("Nm1_HighPurity", 4, -1.5, 2.5);
    plots.AddHisto1F("Nm1_Chi2", 14, 0, 14);
    plots.AddHisto1F("Nm1_dZ", 100, -0.8, 0.8);
    plots.AddHisto1F("Nm1_dXY", 100, -0.1, 0.1);
    plots.AddHisto1F("Nm1_PFMiniIso", 1000, 0, 0.5);
    plots.AddHisto1F("Nm1_TrkIso", 400, 0, 200);
    plots.AddHisto1F("Nm1_EoverP", 500, 0, 5);
    plots.AddHisto1F("Nm1_PtErr_over_PtPt", 500, 0, 0.01);
    plots.AddHisto1F("Nm1_Fpix", 21, 0, 1.1);
    plots.AddHisto1F("Nm1_PtErr_over_Pt", 800, 0, 4);
    plots.AddHisto1F("Nm1_Ih_StripOnly", 200, 0, 10);
    plots.AddHisto1F("Nm1_Ih_StripOnly_rescaled", 200, 0, 10);


    plots.AddHisto1F("Nm1_event_trigger",           4,    -1.5,  2.5);
    plots.AddHisto1F("Nm1_event_METfilters",        4,    -1.5,  2.5);
    plots.AddHisto1F("Nm1_event_CaloMET",           200,   0,    2000);
    plots.AddHisto1F("Nm1_event_CaloMET_rescaled",  200,   0,    2000);
    plots.AddHisto1F("Nm1_event_CaloMET_OTHERrescaled",  200,   0,    2000);
    plots.AddHisto1F("Nm1_event_Ptpseudo",          300,   0,    3000);
    plots.AddHisto1F("Nm1_event_eta",               60,   -3,    3);
    plots.AddHisto1F("Nm1_event_NOPH",              15,    0,    15);
    plots.AddHisto1F("Nm1_event_FOVH",              50,    0,    1.1);
    plots.AddHisto1F("Nm1_event_NOM",               50,    0,    50);
    plots.AddHisto1F("Nm1_event_HighPurity",        4,    -1.5,  2.5);
    plots.AddHisto1F("Nm1_event_Chi2",              14,    0,    14);
    plots.AddHisto1F("Nm1_event_dZ",                100,  -0.8,  0.8);
    plots.AddHisto1F("Nm1_event_dXY",               100,  -0.1,  0.1);
    plots.AddHisto1F("Nm1_event_PFMiniIso",         1000,  0,    0.5);
    plots.AddHisto1F("Nm1_event_TrkIso",            400,   0,    200);
    plots.AddHisto1F("Nm1_event_EoverP",            500,   0,    5);
    plots.AddHisto1F("Nm1_event_PtErr_over_PtPt",   500,   0,    0.01);
    plots.AddHisto1F("Nm1_event_Fpix",              21,    0,    1.1);
    plots.AddHisto1F("Nm1_event_PtErr_over_Pt",     800,   0,    4);
    plots.AddHisto1F("Nm1_event_Ih_StripOnly",      200,   0,    10);
    plots.AddHisto1F("Nm1_event_Ih_StripOnly_rescaled",      200,   0,    10);

    plots.AddHisto1F("Pt_lastBin", 100, 0, 2000);
    plots.AddHisto1F("HSCPtype_lastBin", 6, -0.5, 5.5);
    plots.AddHisto1F("PFtype_lastBin", 250, 0, 250);

    plots.AddHisto1F("RecoPFMET", 400, 0, 2000);
    plots.AddHisto1F("RecoPFMET___wPseudoCaloMETCut", 400, 0, 2000);
    plots.AddHisto1F("RecoPFMET___wCaloMETCut", 400, 0, 2000);


    plots.AddHisto2F("LastBinEventCutflow___GenPt_vs_trackPt", 100, 0, 2500, 100, 0, 2500);
    plots.AddHisto1F("LastBinEventCutflow___HSCP_type", 6, -0.5, 5.5);
    plots.AddHisto1F("LastBinEventCutflow___PF_type", 250, 0, 250);

    plots.AddHisto1F("PostTrigger_PseudoCaloMET_SF_rescaled", 200, 0, 2000);
    plots.AddHisto1F("PostTrigger_PseudoCaloMET_SF_NOTrescaled", 200, 0, 2000);

    plots.AddHisto1F("PostTrigger_PseudoCaloMET_rescaled", 200, 0, 2000);
    plots.AddHisto1F("PostTrigger_PseudoCaloMET_NOTrescaled", 200, 0, 2000);


    // General plots
    plots.AddHisto1F("Nosel_test", 200, 0, 2000);
    plots.AddHisto1F("Nosel_test_2", 200, 0, 2000);
    plots.AddHisto1F("Nosel_PseudoCaloMET", 200, 0, 2000);
    plots.AddHisto1F("Nosel_PseudoCaloMET_rescaled", 200, 0, 2000);
    plots.AddHisto1F("Nosel_Ptpseudo", 300, 0, 3000);
    plots.AddHisto1F("Nosel_P", 200, 0, 8000);
    plots.AddHisto1F("Nosel_10000oP", 300, 0, 300);
    plots.AddHisto2F("Nosel_10000oP_vs_Eta", 300, 0, 300, 60, -3, +3);
    plots.AddHisto1F("Nosel_eta", 60, -3, +3);
    plots.AddHisto1F("Nosel_phi", 64, -3.2, 3.2);
    plots.AddHisto1F("Nosel_PFMiniIso", 1000, 0, 0.5);
    plots.AddHisto1F("Nosel_TrkIso", 400, 0, 200);
    plots.AddHisto1F("Nosel_EoverP", 500, 0, 5);
    plots.AddHisto1F("Nosel_PtErr_over_PtPt", 500, 0, 0.01);
    plots.AddHisto1F("Nosel_Fpix", 21, 0, 1.1);
    plots.AddHisto1F("Nosel_PtErr_over_Pt", 800, 0, 4);
    plots.AddHisto1F("Nosel_Ih", 200, 0, 10);
    plots.AddHisto1F("Nosel_Ih_rescaled", 200, 0, 10);
    plots.AddHisto1F("Nosel_Ih_oldCorr", 200, 0, 10);
    plots.AddHisto1F("Nosel_Ih_noSF", 200, 0, 10);
    plots.AddHisto1F("Nosel_PthatQCD", 2000, 0, 2000);

    plots.AddHisto2F("Nosel_Fpix_vs_RunNumber", 5000, 378000, 388000, 20, 0, 1);
    plots.AddHisto2F("Nosel_Ih_vs_RunNumber", 5000, 378000, 388000, 200, 0, 10);
    plots.AddHisto2F("Nosel_Ih_oldCorr_vs_RunNumber", 5000, 378000, 388000, 200, 0, 10);
    plots.AddHisto2F("Nosel_NPV_vs_RunNumber", 5000, 378000, 388000, 150, 0, 150);

    plots.AddHisto2F("Nosel_Fpix_vs_IhnearC", 200, C-0.3, C+0.3, 20, 0, 1);
    plots.AddHisto2F("Nosel_pT_vs_Fpixel", 50, 0, 1, 100, 50, 1000);
    plots.AddHisto2F("Nosel_PseudoMET_vs_PFMET", 200, 0, 2000, 200, 0, 2000);

    plots.AddHisto1F("Nosel_electron_pt", 2000, 0, 2000);
    plots.AddHisto1F("Nosel_electron_eta", 60, -3, +3);
    plots.AddHisto1F("Nosel_electron_phi", 64, -3.2, 3.2);
    plots.AddHisto1F("Nosel_electron_trackIso_dr04", 500, 0, 500);
    plots.AddHisto1F("Nosel_electron_pfMiniRelIsoAll", 500, 0, 500);
    plots.AddHisto1F("Nosel_muon_pt", 2000, 0, 2000);
    plots.AddHisto1F("Nosel_muon_eta", 60, -3, +3);
    plots.AddHisto1F("Nosel_muon_phi", 64, -3.2, 3.2);
    plots.AddHisto1F("Nosel_muon_trackIso_dr04", 500, 0, 500);
    plots.AddHisto1F("Nosel_muon_pfMiniRelIsoAll", 500, 0, 500);
    
    plots.AddHisto2F("trackPT_vs_trackPseudoTrackPT", 100, 0, 2500, 100, 0, 2500);
    plots.AddHisto2F("trackETA_vs_trackPseudoTrackETA", 60, -3, +3, 60, -3, +3);
    plots.AddHisto2F("trackPHI_vs_trackPseudoTrackPHI", 64, -3.2, 3.2, 64, -3.2, 3.2);
    plots.AddHisto2F("genPT_vs_trackPseudoTrackPT", 100, 0, 2500, 100, 0, 2500);
    plots.AddHisto2F("genPT_vs_trackPT", 100, 0, 2500, 100, 0, 2500);
    plots.AddHisto1F("PseudoTrack_m_gen_over_gen", 60, -3, +3);
    plots.AddHisto2F("gen__vs__PseudoTrack_m_gen_over_gen", 100, 0, 2500, 60, -3, +3);
    plots.AddHisto1F("Track_m_gen_over_gen", 60, -3, +3);
    plots.AddHisto2F("gen__vs__Track_m_gen_over_gen", 100, 0, 2500, 60, -3, +3);

    
    vcp_nosel.push_back(std::move(plots));

    std::cout << std::endl;
    std::cout << "Histograms initialised" <<std::endl;
}

Bool_t HSCPSelector::Process(Long64_t entry)
{
    fReader.SetLocalEntry(entry);
    
    //----------------------------------
    //Loop over all HSCP candidates
    //----------------------------------
    vector<int> iCand(selLabels_.size(),-1);
    vector<float> maxIh(selLabels_.size(),-1);

    std::vector<bool> eventCuts(19, false);
    std::vector<bool> eventCuts_noTrackCut(19, false);
    std::vector<bool> singleCut(19, false);
    std::vector<bool> eventPassedNm1(19, false);
    std::vector<unsigned int> iCandNm1(19, (int)-1);
    std::vector<float> maxIhNm1(19, -999.);

    bool trigger = false;
    bool METfilters = false;
    float CaloMET_pseudoMET = -1;
    bool isMC = false, isSignal = false;
    float AppliedWeight = 1., AppliedWeight_NOTrescaled = 1.;
    float AppliedWeight_SF_Up = 1., AppliedWeight_SF_Down = 1.;
    float AppliedWeight_PU_Up = 1., AppliedWeight_PU_Down = 1.;
    if (dataset_.find("Mu2024") != std::string::npos ||
        dataset_.find("TestMuon2024") != std::string::npos) {
        trigger = *HLT_Mu50;
        METfilters = true; // no MET filters in muon datasets
        CaloMET_pseudoMET = 200; // no CaloMET in muon datasets, set it to pass the cut
    }
    else if (dataset_.find("MET") != std::string::npos || 
             dataset_.find("QCD2024") != std::string::npos || 
             dataset_.find("TTbar2024") != std::string::npos ||
             dataset_.find("Wjets") != std::string::npos ||
             dataset_.find("Gluino") != std::string::npos ||
             dataset_.find("WjetMuNu") != std::string::npos) {
        trigger = *HLT_PFMET120_PFMHT120_IDTight || *HLT_PFHT500_PFMET100_PFMHT100_IDTight
        || *HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 || *HLT_MET105_IsoTrk50;

        METfilters = Flag_allMETFilters[0];
        CaloMET_pseudoMET = PseudoCaloMET[0];
    }
    if (dataset_.find("Gluino") != std::string::npos ||
        dataset_.find("QCD2024") != std::string::npos || 
        dataset_.find("TTbar2024") != std::string::npos ||
        dataset_.find("Wjets") != std::string::npos ||
        dataset_.find("WjetMuNu") != std::string::npos) {
        isMC = true;

        float SF = 1., SF_NOTrescaled = 1.;
        float SF_Up = 1., SF_Down = 1.;
        if (CaloMET_pseudoMET < 0) SF = 0;
        else {
            for (size_t i = 0; i < SF_PseudoMETvalue.size(); i++) {
                if (CaloMET_pseudoMET < SF_PseudoMETvalue[i]) {
                    SF = SF_triggerEff[i-1];
                    SF_NOTrescaled = SF_triggerEff_NOTrescaled[i-1];
                    SF_Up = SF_triggerEff_Up[i-1];
                    SF_Down = SF_triggerEff_Down[i-1];
                    break;
                }
                else if (CaloMET_pseudoMET >= SF_PseudoMETvalue.back()) {
                    SF = SF_triggerEff.back();
                    SF_NOTrescaled = SF_triggerEff_NOTrescaled.back();
                    SF_Up = SF_triggerEff_Up.back();
                    SF_Down = SF_triggerEff_Down.back();
                    break;
                }
            }
        }

        AppliedWeight = *weightPU * SF;
        AppliedWeight_NOTrescaled = *weightPU * SF_NOTrescaled;

        AppliedWeight_SF_Up = *weightPU * SF_Up;
        AppliedWeight_SF_Down = *weightPU * SF_Down;

        //AppliedWeight_PU_Up = *weightPU_Up * SF;
        //AppliedWeight_PU_Down = *weightPU_Down * SF;
    }
    if (dataset_.find("Gluino") != std::string::npos) {
        isSignal = true;
    }
    //AppliedWeight = *weightPU; // temporary for TTbar calib

    vcp_nosel[0].FillHisto1D("CandidateCutflow", 0, AppliedWeight); // All events
    
    singleCut[0] = trigger;
    if (singleCut[0]) {
        vcp_nosel[0].FillHisto1D("EventCutflow", 1.5, AppliedWeight);
        vcp_nosel[0].FillHisto1D("EventCutflow_NotrackCut", 1.5, AppliedWeight);
    }
    singleCut[1] = singleCut[0] && METfilters;
    if (singleCut[1]) {
        vcp_nosel[0].FillHisto1D("EventCutflow", 2.5, AppliedWeight);
        vcp_nosel[0].FillHisto1D("EventCutflow_NotrackCut", 2.5, AppliedWeight);
    }
    singleCut[2] = singleCut[1] && (CaloMET_pseudoMET > 170.);
    if (singleCut[2]) {
        vcp_nosel[0].FillHisto1D("EventCutflow", 3.5, AppliedWeight);
        vcp_nosel[0].FillHisto1D("EventCutflow_NotrackCut", 3.5, AppliedWeight);
    }


        //
    vcp_nosel[0].FillHisto1F("Trigger", *HLT_FilterOR, AppliedWeight);
    vcp_nosel[0].FillHisto1F("RecoPFMET", RecoPFMET[0], AppliedWeight);
    if (PseudoCaloMET[0] > 170) vcp_nosel[0].FillHisto1F("RecoPFMET___wPseudoCaloMETCut", RecoPFMET[0], AppliedWeight);
    //if (RecoCaloMET[0] > 170) vcp_nosel[0].FillHisto1F("RecoPFMET___wCaloMETCut", RecoPFMET[0], AppliedWeight);
    vcp_nosel[0].FillHisto1F("nHSCP", *HSCP_n, AppliedWeight);
    vcp_nosel[0].FillHisto1F("nPVgood", *PV_npvsGood, AppliedWeight);


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
        singleCut[3] = singleCut[2] && (Pt_pseudo[i] > 50.) && (Pt[i] > 50.);
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
        singleCut[18] = singleCut[17] && (Ih_Strip[i] > C);

            // candidate CUTFLOW
        for (unsigned int j = 0; j < singleCut.size(); j++) {
            if (singleCut[j]) vcp_nosel[0].FillHisto1D("CandidateCutflow", j+1, AppliedWeight);
        }


        std::vector<std::function<bool(int)>> cuts;
        cuts.push_back([&](int i){ return trigger; });
        cuts.push_back([&](int i){ return METfilters; });
        cuts.push_back([&](int i){ return CaloMET_pseudoMET > 170; });
        cuts.push_back([&](int i){ return ((Pt_pseudo[i] > 50.0) && (Pt[i] > 50.0)); });
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
        cuts.push_back([&](int i){ return Ih_Strip[i] > C; });
        

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

            // N-1 distributions
        std::vector <bool> passedCuts(cuts.size(), true);
        for (unsigned int icut = 0; icut < cuts.size(); ++icut) {
            bool passedAllButOne = true;
            for (unsigned int jcut = 0; jcut < cuts.size(); ++jcut) {
                if (jcut == icut) continue;
                if (!cuts[jcut](i)) { passedAllButOne = false; break; }
            }
            passedCuts[icut] = passedAllButOne; // N-1 candidat
            if (passedAllButOne) {              // N-1 event
                eventPassedNm1[icut] = true;
                if (Ih_Strip[i] > maxIhNm1[icut]) {
                    maxIhNm1[icut] = Ih_Strip[i];
                    iCandNm1[icut] = i;
                }
            }
        }



        if (passedCuts[0]) vcp_nosel[0].FillHisto1F("Nm1_trigger", trigger, AppliedWeight);
        if (passedCuts[1]) vcp_nosel[0].FillHisto1F("Nm1_METfilters", METfilters, AppliedWeight);
        if (passedCuts[2]) vcp_nosel[0].FillHisto1F("Nm1_CaloMET", CaloMET_pseudoMET, AppliedWeight);
        if (passedCuts[2]) vcp_nosel[0].FillHisto1F("Nm1_CaloMET_rescaled", CaloMET_pseudoMET*163.451/146.864, AppliedWeight); // max_data/max_MC
        if (passedCuts[2]) vcp_nosel[0].FillHisto1F("Nm1_CaloMET_OTHERrescaled", -1.56407e-05*CaloMET_pseudoMET*CaloMET_pseudoMET + 1.01015*CaloMET_pseudoMET + 7.7078, AppliedWeight); // polynomial
        if (passedCuts[3]) vcp_nosel[0].FillHisto1F("Nm1_Ptpseudo", Pt_pseudo[i], AppliedWeight);
        if (passedCuts[4]) vcp_nosel[0].FillHisto1F("Nm1_eta", Eta[i], AppliedWeight);
        if (passedCuts[5]) vcp_nosel[0].FillHisto1F("Nm1_NOPH", NbPixelHit_noL1[i], AppliedWeight);
        if (passedCuts[6]) vcp_nosel[0].FillHisto1F("Nm1_FOVH", FracOfValidHit[i], AppliedWeight);
        if (passedCuts[7]) vcp_nosel[0].FillHisto1F("Nm1_NOM", NOM_noL1[i], AppliedWeight);
        if (passedCuts[8]) vcp_nosel[0].FillHisto1F("Nm1_HighPurity", isHighPurityTrack[i], AppliedWeight);
        if (passedCuts[9]) vcp_nosel[0].FillHisto1F("Nm1_Chi2", normChi2[i], AppliedWeight);
        if (passedCuts[10]) vcp_nosel[0].FillHisto1F("Nm1_dZ", dz[i], AppliedWeight);
        if (passedCuts[11]) vcp_nosel[0].FillHisto1F("Nm1_dXY", dxy[i], AppliedWeight);
        if (passedCuts[12]) vcp_nosel[0].FillHisto1F("Nm1_PFMiniIso", miniRelIsoAll[i], AppliedWeight);
        if (passedCuts[13]) vcp_nosel[0].FillHisto1F("Nm1_TrkIso", IsoSumPt_dr03[i], AppliedWeight);
        if (passedCuts[14]) vcp_nosel[0].FillHisto1F("Nm1_EoverP", EoP[i], AppliedWeight);
        if (passedCuts[15]) vcp_nosel[0].FillHisto1F("Nm1_PtErr_over_PtPt", ptOverptErrptErr[i], AppliedWeight);
        if (passedCuts[16] && isMC) vcp_nosel[0].FillHisto1F("Nm1_Fpix", Fpix[i], AppliedWeight);
        else if (passedCuts[16] && !isMC && Fpix[i] <= 0.9) vcp_nosel[0].FillHisto1F("Nm1_Fpix", Fpix[i], AppliedWeight);
        if (passedCuts[17]) vcp_nosel[0].FillHisto1F("Nm1_PtErr_over_Pt", ptOverptErr[i], AppliedWeight);
        if (passedCuts[18] && isSignal) vcp_nosel[0].FillHisto1F("Nm1_Ih_StripOnly", Ih_Strip[i], AppliedWeight);
        else if (passedCuts[18] && !isSignal && Fpix[i] <= 0.9) vcp_nosel[0].FillHisto1F("Nm1_Ih_StripOnly", Ih_Strip[i], AppliedWeight);
        if (passedCuts[18] && isSignal) vcp_nosel[0].FillHisto1F("Nm1_Ih_StripOnly_rescaled", Ih_Strip[i]*3.2168/3.12692, AppliedWeight);       // MPV_data/MPV_MC
        else if (passedCuts[18] && !isSignal && Fpix[i] <= 0.9) vcp_nosel[0].FillHisto1F("Nm1_Ih_StripOnly_rescaled", Ih_Strip[i]*3.2168/3.12692, AppliedWeight);


            // Event cutflow last bin: check GenPart info and PF_type
        if (eventCuts[18]) {
            for (unsigned int j = 0; j < GenPart_pt.GetSize(); j++) {
                float dEta = GenPart_eta[j] - Eta[i];
                float dPhi = GenPart_phi[j] - Phi[i];
                while (dPhi >  M_PI) dPhi -= 2*M_PI;
                while (dPhi < -M_PI) dPhi += 2*M_PI;
                if (std::sqrt(dEta*dEta + dPhi*dPhi) < 0.01) {
                    vcp_nosel[0].FillHisto2F("LastBinEventCutflow___GenPt_vs_trackPt", GenPart_pt[j], Pt_pseudo[i], AppliedWeight);
                    vcp_nosel[0].FillHisto1D("EventCutflow__isGen_lastbin", 1, AppliedWeight);
                }
            }
            vcp_nosel[0].FillHisto1F("LastBinEventCutflow___HSCP_type", HSCP_type[i], AppliedWeight);
            vcp_nosel[0].FillHisto1F("LastBinEventCutflow___PF_type", PF_type[i], AppliedWeight);
        }

        i++;
    } //End of loop over all HSCP candidates

    // Event CUTFLOW
    vcp_nosel[0].FillHisto1D("EventCutflow", 0.5, AppliedWeight); // All events
    for (unsigned int j = 3; j < 19; ++j) { // cuts length
        if (eventCuts[j]) vcp_nosel[0].FillHisto1D("EventCutflow", j+1.5, AppliedWeight);
    }

    vcp_nosel[0].FillHisto1D("EventCutflow_NotrackCut", 0.5, AppliedWeight); // All events
    for (unsigned int j = 3; j < 19; ++j) { // cuts length
        if (eventCuts_noTrackCut[j]) vcp_nosel[0].FillHisto1D("EventCutflow_NotrackCut", j+1.5, AppliedWeight);
    }

    // N-1 EVENT CUTFLOW histograms
    if (eventPassedNm1[0])  vcp_nosel[0].FillHisto1F("Nm1_event_trigger",          trigger, AppliedWeight);
    if (eventPassedNm1[1])  vcp_nosel[0].FillHisto1F("Nm1_event_METfilters",       METfilters, AppliedWeight);
    if (eventPassedNm1[2])  vcp_nosel[0].FillHisto1F("Nm1_event_CaloMET",          CaloMET_pseudoMET, AppliedWeight);
    if (eventPassedNm1[2])  vcp_nosel[0].FillHisto1F("Nm1_event_CaloMET_rescaled", CaloMET_pseudoMET*163.451/146.864, AppliedWeight); // max_data/max_MC scale factor for PseudoCaloMET
    if (eventPassedNm1[2])  vcp_nosel[0].FillHisto1F("Nm1_event_CaloMET_OTHERrescaled", -1.56407e-05*CaloMET_pseudoMET*CaloMET_pseudoMET + 1.01015*CaloMET_pseudoMET + 7.7078, AppliedWeight); // max_data/max_MC scale factor for PseudoCaloMET
    if (eventPassedNm1[3])  vcp_nosel[0].FillHisto1F("Nm1_event_Ptpseudo",         Pt_pseudo[iCandNm1[3]], AppliedWeight);
    if (eventPassedNm1[4])  vcp_nosel[0].FillHisto1F("Nm1_event_eta",              Eta[iCandNm1[4]], AppliedWeight);
    if (eventPassedNm1[5])  vcp_nosel[0].FillHisto1F("Nm1_event_NOPH",             NbPixelHit_noL1[iCandNm1[5]], AppliedWeight);
    if (eventPassedNm1[6])  vcp_nosel[0].FillHisto1F("Nm1_event_FOVH",             FracOfValidHit[iCandNm1[6]], AppliedWeight);
    if (eventPassedNm1[7])  vcp_nosel[0].FillHisto1F("Nm1_event_NOM",              NOM_noL1[iCandNm1[7]], AppliedWeight);
    if (eventPassedNm1[8])  vcp_nosel[0].FillHisto1F("Nm1_event_HighPurity",       isHighPurityTrack[iCandNm1[8]], AppliedWeight);
    if (eventPassedNm1[9])  vcp_nosel[0].FillHisto1F("Nm1_event_Chi2",             normChi2[iCandNm1[9]], AppliedWeight);
    if (eventPassedNm1[10]) vcp_nosel[0].FillHisto1F("Nm1_event_dZ",               dz[iCandNm1[10]], AppliedWeight);
    if (eventPassedNm1[11]) vcp_nosel[0].FillHisto1F("Nm1_event_dXY",              dxy[iCandNm1[11]], AppliedWeight);
    if (eventPassedNm1[12]) vcp_nosel[0].FillHisto1F("Nm1_event_PFMiniIso",        miniRelIsoAll[iCandNm1[12]], AppliedWeight);
    if (eventPassedNm1[13]) vcp_nosel[0].FillHisto1F("Nm1_event_TrkIso",           IsoSumPt_dr03[iCandNm1[13]], AppliedWeight);
    if (eventPassedNm1[14]) vcp_nosel[0].FillHisto1F("Nm1_event_EoverP",           EoP[iCandNm1[14]], AppliedWeight);
    if (eventPassedNm1[15]) vcp_nosel[0].FillHisto1F("Nm1_event_PtErr_over_PtPt",  ptOverptErrptErr[iCandNm1[15]], AppliedWeight);
    if (eventPassedNm1[16] && isMC)  vcp_nosel[0].FillHisto1F("Nm1_event_Fpix",    Fpix[iCandNm1[16]], AppliedWeight);
    else if (eventPassedNm1[16] && !isMC && Fpix[iCandNm1[16]] <= 0.9) vcp_nosel[0].FillHisto1F("Nm1_event_Fpix", Fpix[iCandNm1[16]], AppliedWeight);
    if (eventPassedNm1[17]) vcp_nosel[0].FillHisto1F("Nm1_event_PtErr_over_Pt",    ptOverptErr[iCandNm1[17]], AppliedWeight);
    if (eventPassedNm1[18] && isSignal) vcp_nosel[0].FillHisto1F("Nm1_event_Ih_StripOnly", Ih_Strip[iCandNm1[18]], AppliedWeight);
    else if (eventPassedNm1[18] && !isSignal && Fpix[iCandNm1[18]] <= 0.9) vcp_nosel[0].FillHisto1F("Nm1_event_Ih_StripOnly", Ih_Strip[iCandNm1[18]], AppliedWeight);
    if (eventPassedNm1[18] && isSignal) vcp_nosel[0].FillHisto1F("Nm1_event_Ih_StripOnly_rescaled", Ih_Strip[iCandNm1[18]]*3.2168/3.12692, AppliedWeight);
    else if (eventPassedNm1[18] && !isSignal && Fpix[iCandNm1[18]] <= 0.9) vcp_nosel[0].FillHisto1F("Nm1_event_Ih_StripOnly_rescaled", Ih_Strip[iCandNm1[18]]*3.2168/3.12692, AppliedWeight);


    // PseudoCaloMET variable calibration
    for (unsigned int im = 0; im < muon_pt.GetSize(); im++) {
        vcp_nosel[0].FillHisto1F("Nosel_muon_pt", muon_pt[im], *weightPU);
        vcp_nosel[0].FillHisto1F("Nosel_muon_eta", muon_eta[im], *weightPU);
        vcp_nosel[0].FillHisto1F("Nosel_muon_phi", muon_phi[im], *weightPU);
        vcp_nosel[0].FillHisto1F("Nosel_muon_trackIso_dr04", muon_trackIso_dr04[im], *weightPU);
        vcp_nosel[0].FillHisto1F("Nosel_muon_pfMiniRelIsoAll", muon_pfMiniRelIsoAll[im], *weightPU);
    }
    for (unsigned int ie = 0; ie < electron_pt.GetSize(); ie++) {
        vcp_nosel[0].FillHisto1F("Nosel_electron_pt", electron_pt[ie], *weightPU);
        vcp_nosel[0].FillHisto1F("Nosel_electron_eta", electron_eta[ie], *weightPU);
        vcp_nosel[0].FillHisto1F("Nosel_electron_phi", electron_phi[ie], *weightPU);
        vcp_nosel[0].FillHisto1F("Nosel_electron_trackIso_dr04", electron_trackIso_dr04[ie], *weightPU);
        vcp_nosel[0].FillHisto1F("Nosel_electron_pfMiniRelIsoAll", electron_pfMiniRelIsoAll[ie], *weightPU);
    }
    for(unsigned int s=0;s<selections_.size();s++) {
        if (selLabels_[s] == "CalibPseudoMET" || selLabels_[s] == "CalibPseudoMET_isRescaled") {
            bool BasicSel = false;
            unsigned int hasPassedMuon = 0;
            unsigned int hasPassedElectron = 0;
            unsigned int hadPassedHSCP = 0;

            if (*HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ && 
                *HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL && 
                muon_pt.GetSize()>0 && electron_pt.GetSize()>0 && Flag_allMETFilters[0]) BasicSel = true;

            for (unsigned int im = 0; im < muon_pt.GetSize(); im++) {
                if (muon_isTight[im] && muon_pt[im]>50 && muon_pfMiniRelIsoAll[im]<0.15) hasPassedMuon++;
            }
            for (unsigned int ie = 0; ie < electron_pt.GetSize(); ie++) {
                if (electron_isTight[ie]==1 && electron_pt[ie]>20 && electron_pfMiniRelIsoAll[ie]<0.15) hasPassedElectron++;
            }

            unsigned int i_track = 0;
            for(unsigned int j=0; j<HSCP_hasTrack.GetSize(); j++){    

                if (!HSCP_hasTrack[j]) continue;

                if ( (Pt[i_track] > 50.0) && (Pt_pseudo[i_track] > 50.0) && (abs(Eta[i_track]) < 2.4) && (NbPixelHit_noL1[i_track] >= 2) && (FracOfValidHit[i_track] > 0.8) && 
                (NOM_noL1[i_track] >= 10) && (isHighPurityTrack[i_track] == true) && (normChi2[i_track] < 5.0) && (abs(dz[i_track]) < 0.1) && (abs(dxy[i_track]) < 0.02) && 
                (miniRelIsoAll[i_track] < 0.02) && (IsoSumPt_dr03[i_track] < 15) && (ptOverptErrptErr[i_track] < 0.0008) ) hadPassedHSCP++;

                i_track++;
            }
            
            if (BasicSel && hasPassedMuon==1 && hasPassedElectron==1 && hadPassedHSCP>0) {

                float isRescaled = (selLabels_[s] == "CalibPseudoMET_isRescaled") ? 163.451/146.864 : 1;
                float weightOnCalib = *weightPU;

                for (unsigned int im = 0; im < muon_pt.GetSize(); im++) {
                    if (muon_isTight[im] && muon_pt[im]>50 && muon_pfMiniRelIsoAll[im]<0.15) {
                        vcp[s].FillHisto1F(selLabels_[s]+"_muon_pt", muon_pt[im], weightOnCalib);
                        vcp[s].FillHisto1F(selLabels_[s]+"_muon_eta", muon_eta[im], weightOnCalib);
                        vcp[s].FillHisto1F(selLabels_[s]+"_muon_phi", muon_phi[im], weightOnCalib);
                    }
                }
                for (unsigned int ie = 0; ie < electron_pt.GetSize(); ie++) {
                    if (electron_isTight[ie]==1 && electron_pt[ie]>20 && electron_pfMiniRelIsoAll[ie]<0.15) {
                        vcp[s].FillHisto1F(selLabels_[s]+"_electron_pt", electron_pt[ie], weightOnCalib);
                        vcp[s].FillHisto1F(selLabels_[s]+"_electron_eta", electron_eta[ie], weightOnCalib);
                        vcp[s].FillHisto1F(selLabels_[s]+"_electron_phi", electron_phi[ie], weightOnCalib);
                    }
                }
                
                vcp[s].FillHisto1F(selLabels_[s]+"_PuppiMET", RecoPuppiMET[0], weightOnCalib);
                vcp[s].FillHisto1F(selLabels_[s]+"_PseudoCaloMET", PseudoCaloMET[0]*isRescaled, weightOnCalib);
                vcp[s].FillHisto1F(selLabels_[s]+"_RecoPFMET", RecoPFMET[0], weightOnCalib);
                if (PseudoCaloMET[0] > 170) vcp[s].FillHisto1F(selLabels_[s]+"_RecoPFMET__PseudoCaloMETCut", RecoPFMET[0], weightOnCalib);
                if (RecoPFMET[0] > 170) vcp[s].FillHisto1F(selLabels_[s]+"_PseudoCaloMET__RecoPFMETCut", PseudoCaloMET[0]*isRescaled, weightOnCalib);
                vcp[s].FillHisto1F(selLabels_[s]+"_L1MET", L1MET[0], weightOnCalib);
                vcp[s].FillHisto1F(selLabels_[s]+"_HLTCaloMET", HLTCaloMET[0], weightOnCalib);
                vcp[s].FillHisto1F(selLabels_[s]+"_HLTCaloMHT", HLTCaloMHT[0], weightOnCalib);
                vcp[s].FillHisto1F(selLabels_[s]+"_HLTPFMHT", HLTPFMHT[0], weightOnCalib);
                vcp[s].FillHisto1F(selLabels_[s]+"_HLTPFMET", HLTPFMET[0], weightOnCalib);

                if (*HLT_PFMET120_PFMHT120_IDTight) {
                    vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET", PseudoCaloMET[0]*isRescaled, weightOnCalib);
                    vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET", RecoPFMET[0], weightOnCalib);
                    if (PseudoCaloMET[0] > 170) vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET__PseudoCaloMETCut", RecoPFMET[0], weightOnCalib);
                    if (RecoPFMET[0] > 170) vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET__RecoPFMETCut", PseudoCaloMET[0]*isRescaled, weightOnCalib);
                }
                if (*HLT_PFHT500_PFMET100_PFMHT100_IDTight) {
                    vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET", PseudoCaloMET[0]*isRescaled, weightOnCalib);
                    vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET", RecoPFMET[0], weightOnCalib);
                    if (PseudoCaloMET[0] > 170) vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET__PseudoCaloMETCut", RecoPFMET[0], weightOnCalib);
                    if (RecoPFMET[0] > 170) vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET__RecoPFMETCut", PseudoCaloMET[0]*isRescaled, weightOnCalib);
                }
                if (*HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60) {
                    vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET", PseudoCaloMET[0]*isRescaled, weightOnCalib);
                    vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET", RecoPFMET[0], weightOnCalib);
                    if (PseudoCaloMET[0] > 170) vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET__PseudoCaloMETCut", RecoPFMET[0], weightOnCalib);
                    if (RecoPFMET[0] > 170) vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET__RecoPFMETCut", PseudoCaloMET[0]*isRescaled, weightOnCalib);
                }
                if (*HLT_MET105_IsoTrk50) {
                    vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_MET105_IsoTrk50___PseudoCaloMET", PseudoCaloMET[0]*isRescaled, weightOnCalib);
                    vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_MET105_IsoTrk50___RecoPFMET", RecoPFMET[0], weightOnCalib);
                    if (PseudoCaloMET[0] > 170) vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_MET105_IsoTrk50___RecoPFMET__PseudoCaloMETCut", RecoPFMET[0], weightOnCalib);
                    if (RecoPFMET[0] > 170) vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_MET105_IsoTrk50___PseudoCaloMET__RecoPFMETCut", PseudoCaloMET[0]*isRescaled, weightOnCalib);
                }
                if (*HLT_PFMET120_PFMHT120_IDTight || *HLT_PFHT500_PFMET100_PFMHT100_IDTight
                    || *HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 || *HLT_MET105_IsoTrk50) {
                    vcp[s].FillHisto1F(selLabels_[s]+"_if___orMETtrg___PseudoCaloMET", PseudoCaloMET[0]*isRescaled, weightOnCalib);
                    vcp[s].FillHisto1F(selLabels_[s]+"_if___orMETtrg___RecoPFMET", RecoPFMET[0], weightOnCalib);
                    if (PseudoCaloMET[0] > 170) vcp[s].FillHisto1F(selLabels_[s]+"_if___orMETtrg___RecoPFMET__PseudoCaloMETCut", RecoPFMET[0], weightOnCalib);
                    if (RecoPFMET[0] > 170) vcp[s].FillHisto1F(selLabels_[s]+"_if___orMETtrg___PseudoCaloMET__RecoPFMETCut", PseudoCaloMET[0]*isRescaled, weightOnCalib);
                }
                
            }

        }
    }


    // using Wjets and Muon dataset
    for(unsigned int s=0;s<selections_.size();s++) {
        if (selLabels_[s] == "CalibPseudoMET_MuWay" || selLabels_[s] == "CalibPseudoMET_MuWay_isRescaled" || selLabels_[s] == "CalibPseudoMET_MuWay_OTHERisRescaled") {
            bool BasicSel = false;
            unsigned int hasPassedMuon = 0;
            unsigned int hadPassedHSCP = 0;

            if (*HLT_IsoMu27 && muon_pt.GetSize()==1 && Flag_allMETFilters[0]) BasicSel = true;

            for (unsigned int im = 0; im < muon_pt.GetSize(); im++) {
                if (muon_isTight[im] && muon_pt[im]>30 && muon_pfMiniRelIsoAll[im]<0.15) hasPassedMuon++;
            }

            unsigned int i_track = 0;
            for(unsigned int j=0; j<HSCP_hasTrack.GetSize(); j++){    

                if (!HSCP_hasTrack[j]) continue;

                if ( (Pt[i_track] > 50.0) && (Pt_pseudo[i_track] > 50.0) && (abs(Eta[i_track]) < 2.4) && (NbPixelHit_noL1[i_track] >= 2) && (FracOfValidHit[i_track] > 0.8) && 
                (NOM_noL1[i_track] >= 10) && (isHighPurityTrack[i_track] == true) && (normChi2[i_track] < 5.0) && (abs(dz[i_track]) < 0.1) && (abs(dxy[i_track]) < 0.02) && 
                (miniRelIsoAll[i_track] < 0.02) && (EoP[i_track] < 0.3) && (IsoSumPt_dr03[i_track] < 15) && (ptOverptErrptErr[i_track] < 0.0008) && 
                (Fpix[i_track] < 0.9)) hadPassedHSCP++;

                i_track++;
            }
            
            if (BasicSel && hasPassedMuon==1 && hadPassedHSCP>0) {

                for (unsigned int im = 0; im < muon_pt.GetSize(); im++) {
                    if (muon_isTight[im] && muon_pt[im]>30 && muon_pfMiniRelIsoAll[im]<0.15) {
                        vcp[s].FillHisto1F(selLabels_[s]+"_muon_pt", muon_pt[im], *weightPU);
                        vcp[s].FillHisto1F(selLabels_[s]+"_muon_eta", muon_eta[im], *weightPU);
                        vcp[s].FillHisto1F(selLabels_[s]+"_muon_phi", muon_phi[im], *weightPU);
                    }
                }

                // After a fit performed on Nm1 CaloMET data and MC (max_data/max_MC)
                float isRescaled = -1, weightOnCalib = *weightPU;
                if (selLabels_[s] == "CalibPseudoMET_MuWay_isRescaled") isRescaled = 163.451/146.864; // = 1.113
                else if (selLabels_[s] == "CalibPseudoMET_MuWay") isRescaled = 1;
                else if (selLabels_[s] == "CalibPseudoMET_MuWay_OTHERisRescaled") isRescaled = (-1.56407e-05*PseudoCaloMET[0]*PseudoCaloMET[0] + 1.01015*PseudoCaloMET[0] + 7.7078)/PseudoCaloMET[0];


                vcp[s].FillHisto1F(selLabels_[s]+"_PuppiMET", RecoPuppiMET[0], weightOnCalib);
                vcp[s].FillHisto1F(selLabels_[s]+"_PseudoCaloMET", PseudoCaloMET[0]*isRescaled, weightOnCalib);
                vcp[s].FillHisto1F(selLabels_[s]+"_RecoPFMET", RecoPFMET[0], weightOnCalib);
                if (PseudoCaloMET[0] > 170) vcp[s].FillHisto1F(selLabels_[s]+"_RecoPFMET__PseudoCaloMETCut", RecoPFMET[0], weightOnCalib);
                if (RecoPFMET[0] > 170) vcp[s].FillHisto1F(selLabels_[s]+"_PseudoCaloMET__RecoPFMETCut", PseudoCaloMET[0]*isRescaled, weightOnCalib);
                vcp[s].FillHisto1F(selLabels_[s]+"_L1MET", L1MET[0], weightOnCalib);
                vcp[s].FillHisto1F(selLabels_[s]+"_HLTCaloMET", HLTCaloMET[0], weightOnCalib);
                vcp[s].FillHisto1F(selLabels_[s]+"_HLTCaloMHT", HLTCaloMHT[0], weightOnCalib);
                vcp[s].FillHisto1F(selLabels_[s]+"_HLTPFMHT", HLTPFMHT[0], weightOnCalib);
                vcp[s].FillHisto1F(selLabels_[s]+"_HLTPFMET", HLTPFMET[0], weightOnCalib);

                if (*HLT_PFMET120_PFMHT120_IDTight) {
                    vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET", PseudoCaloMET[0]*isRescaled, weightOnCalib);
                    vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET", RecoPFMET[0], weightOnCalib);
                    if (PseudoCaloMET[0] > 170) vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET__PseudoCaloMETCut", RecoPFMET[0], weightOnCalib);
                    if (RecoPFMET[0] > 170) vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET__RecoPFMETCut", PseudoCaloMET[0]*isRescaled, weightOnCalib);
                }
                if (*HLT_PFHT500_PFMET100_PFMHT100_IDTight) {
                    vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET", PseudoCaloMET[0]*isRescaled, weightOnCalib);
                    vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET", RecoPFMET[0], weightOnCalib);
                    if (PseudoCaloMET[0] > 170) vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET__PseudoCaloMETCut", RecoPFMET[0], weightOnCalib);
                    if (RecoPFMET[0] > 170) vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET__RecoPFMETCut", PseudoCaloMET[0]*isRescaled, weightOnCalib);
                }
                if (*HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60) {
                    vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET", PseudoCaloMET[0]*isRescaled, weightOnCalib);
                    vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET", RecoPFMET[0], weightOnCalib);
                    if (PseudoCaloMET[0] > 170) vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET__PseudoCaloMETCut", RecoPFMET[0], weightOnCalib);
                    if (RecoPFMET[0] > 170) vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET__RecoPFMETCut", PseudoCaloMET[0]*isRescaled, weightOnCalib);
                }
                if (*HLT_MET105_IsoTrk50) {
                    vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_MET105_IsoTrk50___PseudoCaloMET", PseudoCaloMET[0]*isRescaled, weightOnCalib);
                    vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_MET105_IsoTrk50___RecoPFMET", RecoPFMET[0], weightOnCalib);
                    if (PseudoCaloMET[0] > 170) vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_MET105_IsoTrk50___RecoPFMET__PseudoCaloMETCut", RecoPFMET[0], weightOnCalib);
                    if (RecoPFMET[0] > 170) vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_MET105_IsoTrk50___PseudoCaloMET__RecoPFMETCut", PseudoCaloMET[0]*isRescaled, weightOnCalib);
                }
                if (*HLT_PFMET120_PFMHT120_IDTight || *HLT_PFHT500_PFMET100_PFMHT100_IDTight
                    || *HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 || *HLT_MET105_IsoTrk50) {
                    vcp[s].FillHisto1F(selLabels_[s]+"_if___orMETtrg___PseudoCaloMET", PseudoCaloMET[0]*isRescaled, weightOnCalib);
                    vcp[s].FillHisto1F(selLabels_[s]+"_if___orMETtrg___RecoPFMET", RecoPFMET[0], weightOnCalib);
                    if (PseudoCaloMET[0] > 170) vcp[s].FillHisto1F(selLabels_[s]+"_if___orMETtrg___RecoPFMET__PseudoCaloMETCut", RecoPFMET[0], weightOnCalib);
                    if (RecoPFMET[0] > 170) vcp[s].FillHisto1F(selLabels_[s]+"_if___orMETtrg___PseudoCaloMET__RecoPFMETCut", PseudoCaloMET[0]*isRescaled, weightOnCalib);
                }

            }
        }
    }



    // HSCP loop 
    int i_track = 0;
    for(unsigned int j=0; j<HSCP_hasTrack.GetSize(); j++){    // Every candidate

        if (!HSCP_hasTrack[j]) continue;


        vcp_nosel[0].FillHisto1F("ndEdx_StripOnly", NOM_noL1[i_track] - NbPixelHit_noL1[i_track], *weightPU);
        vcp_nosel[0].FillHisto1F("Nosel_Ptpseudo", Pt_pseudo[i_track], *weightPU);
        vcp_nosel[0].FillHisto1F("Nosel_P", Pt_pseudo[i_track]*cosh(Eta[i_track]), *weightPU);
        vcp_nosel[0].FillHisto1F("Nosel_10000oP", 10000./(Pt_pseudo[i_track]*cosh(Eta[i_track])), *weightPU);
        vcp_nosel[0].FillHisto2F("Nosel_10000oP_vs_Eta", 10000./(Pt_pseudo[i_track]*cosh(Eta[i_track])), Eta[i_track], *weightPU);
        vcp_nosel[0].FillHisto1F("Nosel_eta", Eta[i_track], *weightPU);
        vcp_nosel[0].FillHisto1F("Nosel_phi", Phi[i_track], *weightPU);
        vcp_nosel[0].FillHisto1F("Nosel_PFMiniIso", miniRelIsoAll[i_track], *weightPU);
        vcp_nosel[0].FillHisto1F("Nosel_TrkIso", IsoSumPt_dr03[i_track], *weightPU);
        vcp_nosel[0].FillHisto1F("Nosel_EoverP", EoP[i_track], *weightPU);
        vcp_nosel[0].FillHisto1F("Nosel_PtErr_over_PtPt", ptOverptErrptErr[i_track], *weightPU); 
        if (isMC) {
            vcp_nosel[0].FillHisto1F("Nosel_Fpix", Fpix[i_track], *weightPU);
            if (isSignal) {
                vcp_nosel[0].FillHisto1F("Nosel_Ih", Ih_Strip[i_track], *weightPU);
                vcp_nosel[0].FillHisto1F("Nosel_Ih_rescaled", Ih_Strip[i_track]*3.2168/3.12692, *weightPU);
                vcp_nosel[0].FillHisto1F("Nosel_Ih_oldCorr", Ih_Strip_oldCorr[i_track], *weightPU);
                vcp_nosel[0].FillHisto1F("Nosel_Ih_noSF", Ih_Strip_noSF[i_track], *weightPU);
            }
        }
        if (!isSignal && Fpix[i_track] <= 0.9) {
            vcp_nosel[0].FillHisto1F("Nosel_Ih", Ih_Strip[i_track], *weightPU);
            vcp_nosel[0].FillHisto1F("Nosel_Ih_oldCorr", Ih_Strip_oldCorr[i_track], *weightPU);
            vcp_nosel[0].FillHisto1F("Nosel_Ih_noSF", Ih_Strip_noSF[i_track], *weightPU);
        }
        vcp_nosel[0].FillHisto1F("Nosel_PtErr_over_Pt", ptOverptErr[i_track], *weightPU);
        vcp_nosel[0].FillHisto1F("Nosel_PthatQCD", PthatQCD[i_track], *weightPU);

        vcp_nosel[0].FillHisto2F("Nosel_Fpix_vs_RunNumber", *Run, Fpix[i_track], *weightPU);
        vcp_nosel[0].FillHisto2F("Nosel_Ih_vs_RunNumber", *Run, Ih_Strip[i_track], *weightPU);
        vcp_nosel[0].FillHisto2F("Nosel_Ih_oldCorr_vs_RunNumber", *Run, Ih_Strip_oldCorr[i_track], *weightPU);
        vcp_nosel[0].FillHisto2F("Nosel_NPV_vs_RunNumber", *Run, *PV_npvsGood, *weightPU);

        vcp_nosel[0].FillHisto2F("Nosel_Fpix_vs_IhnearC", Ih_Strip[i_track], Fpix[i_track], *weightPU);


        vcp_nosel[0].FillHisto2F("trackPT_vs_trackPseudoTrackPT", Pt[i_track], Pt_pseudo[i_track], AppliedWeight);
        vcp_nosel[0].FillHisto2F("trackETA_vs_trackPseudoTrackETA", Eta[i_track], Eta_pseudo[i_track], AppliedWeight);
        vcp_nosel[0].FillHisto2F("trackPHI_vs_trackPseudoTrackPHI", Phi[i_track], Phi_pseudo[i_track], AppliedWeight);


        // ABCD method
        if (isMC) {
            vcp_nosel[0].FillHisto2F("Nosel_pT_vs_Fpixel", Fpix[i_track], Pt_pseudo[i_track], *weightPU);
        }
        else if (!isMC && (Pt_pseudo[i_track] < 70 || Fpix[i_track] <= 0.9)) {
            vcp_nosel[0].FillHisto2F("Nosel_pT_vs_Fpixel", Fpix[i_track], Pt_pseudo[i_track], *weightPU);
        }

        for(unsigned int s=0;s<selections_.size();s++) { 
            bool (HSCPSelector::*ptr)(int);
            ptr = selections_[s];

            // COMMENT HERE TO KEEP ALL THE CANDIDATES
            i_track = iCand[s];     // most ionising candidate
            if (i_track<0) continue;
            //----------------------------
            if((this->*ptr)(i_track)) {

                vcp[s].FillHisto1F(selLabels_[s]+"_ndEdx_StripOnly", NOM_noL1[i_track] - NbPixelHit_noL1[i_track], AppliedWeight);
                vcp[s].FillHisto1F(selLabels_[s]+"_Ptpseudo", Pt_pseudo[i_track], AppliedWeight);
                vcp[s].FillHisto1F(selLabels_[s]+"_P", Pt_pseudo[i_track]*cosh(Eta[i_track]), AppliedWeight);
                vcp[s].FillHisto1F(selLabels_[s]+"_Pt", Pt_pseudo[i_track], AppliedWeight);
                vcp[s].FillHisto1F(selLabels_[s]+"_10000oP", 10000./(Pt_pseudo[i_track]*cosh(Eta[i_track])), AppliedWeight);
                vcp[s].FillHisto2F(selLabels_[s]+"_10000oP_vs_Eta", 10000./(Pt_pseudo[i_track]*cosh(Eta[i_track])), Eta[i_track], AppliedWeight);
                vcp[s].FillHisto1F(selLabels_[s]+"_eta", Eta[i_track], AppliedWeight);
                vcp[s].FillHisto1F(selLabels_[s]+"_phi", Phi[i_track], AppliedWeight);
                vcp[s].FillHisto1F(selLabels_[s]+"_PFMiniIso", miniRelIsoAll[i_track], AppliedWeight);
                vcp[s].FillHisto1F(selLabels_[s]+"_TrkIso", IsoSumPt_dr03[i_track], AppliedWeight);
                vcp[s].FillHisto1F(selLabels_[s]+"_EoverP", EoP[i_track], AppliedWeight);
                vcp[s].FillHisto1F(selLabels_[s]+"_PtErr_over_PtPt", ptOverptErrptErr[i_track], AppliedWeight); 
                if (isMC) {
                    vcp[s].FillHisto1F(selLabels_[s]+"_Fpix", Fpix[i_track], AppliedWeight);
                    if (isSignal) {
                        vcp[s].FillHisto1F(selLabels_[s]+"_Ih", Ih_Strip[i_track], AppliedWeight);
                        vcp[s].FillHisto1F(selLabels_[s]+"_Ih_rescaled", Ih_Strip[i_track]*3.2168/3.12692, AppliedWeight);
                        vcp[s].FillHisto1F(selLabels_[s]+"_Ih_oldCorr", Ih_Strip_oldCorr[i_track], AppliedWeight);
                        vcp[s].FillHisto1F(selLabels_[s]+"_Ih_noSF", Ih_Strip_noSF[i_track], AppliedWeight);
                    }
                }
                if (!isSignal && Fpix[i_track] <= 0.9) {
                    vcp[s].FillHisto1F(selLabels_[s]+"_Ih", Ih_Strip[i_track], AppliedWeight);
                    vcp[s].FillHisto1F(selLabels_[s]+"_Ih_oldCorr", Ih_Strip_oldCorr[i_track], AppliedWeight);
                    vcp[s].FillHisto1F(selLabels_[s]+"_Ih_noSF", Ih_Strip_noSF[i_track], AppliedWeight);
                }              
                vcp[s].FillHisto1F(selLabels_[s]+"_PtErr_over_Pt", ptOverptErr[i_track], AppliedWeight);
                vcp[s].FillHisto1F(selLabels_[s]+"_PthatQCD", PthatQCD[i_track], AppliedWeight);
                vcp[s].FillHisto2F(selLabels_[s]+"_Fpix_vs_RunNumber", *Run, Fpix[i_track], AppliedWeight);
                vcp[s].FillHisto2F(selLabels_[s]+"_Ih_vs_RunNumber", *Run, Ih_Strip[i_track], AppliedWeight);
                vcp[s].FillHisto2F(selLabels_[s]+"_Ih_oldCorr_vs_RunNumber", *Run, Ih_Strip_oldCorr[i_track], AppliedWeight);
                vcp[s].FillHisto2F(selLabels_[s]+"_NPV_vs_RunNumber", *Run, *PV_npvsGood, AppliedWeight);
                
                

                vcp[s].FillHisto2F(selLabels_[s]+"_Fpix_vs_IhnearC", Ih_Strip[i_track], Fpix[i_track], AppliedWeight);
                
                

                // ABCD method
                if (isMC) {
                    vcp[s].FillHisto2F(selLabels_[s]+"_pT_vs_Fpixel", Fpix[i_track], Pt_pseudo[i_track], AppliedWeight);
                }
                else if (!isMC && (Pt_pseudo[i_track] < 70 || Fpix[i_track] <= 0.9)) {
                    vcp[s].FillHisto2F(selLabels_[s]+"_pT_vs_Fpixel", Fpix[i_track], Pt_pseudo[i_track], AppliedWeight);
                }

                if(UseFpixel) {
                    double overP = 10000./(Pt_pseudo[i_track]*cosh(Eta[i_track]));
                    double newWeight = AppliedWeight;
                    double massForRegions = GetMass(Pt_pseudo[i_track]*cosh(Eta[i_track]),Ih_Strip[i_track],K,C);

                    //vmrp_regionFpix_all[s].fill(Eta[i], NOM_noL1[i], overP, Pt_pseudo[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);

                    if(Pt_pseudo[i_track] <= ptcut_) {
                        if( (Fpix[i_track] > fpix3) && (Fpix[i_track] <= fpix4) ) vmrp_regionA_3f4[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix3) && (Fpix[i_track] <= fpix6) ) vmrp_regionA_3f6[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix3) && (Fpix[i_track] <= fpix8) ) vmrp_regionA_3f8[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix3) && (Fpix[i_track] <= fpix9) ) vmrp_regionA_3f9[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix4) && (Fpix[i_track] <= fpix5) ) vmrp_regionA_4f5[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix5) && (Fpix[i_track] <= fpix6) ) vmrp_regionA_5f6[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix6) && (Fpix[i_track] <= fpix7) ) vmrp_regionA_6f7[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix6) && (Fpix[i_track] <= fpix9) ) vmrp_regionA_6f9[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix7) && (Fpix[i_track] <= fpix8) ) vmrp_regionA_7f8[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix8) && (Fpix[i_track] <= fpix9) ) vmrp_regionA_8f9[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix9) && (Fpix[i_track] <= fpix10) ) vmrp_regionA_9f10[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix99) && (Fpix[i_track] <= fpix10) ) vmrp_regionA_99f10[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix999) && (Fpix[i_track] <= fpix10) ) vmrp_regionA_999f10[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        
                        if( (Fpix[i_track] > fpix3) && (Fpix[i_track] <= fpix4) ) vmrp_regionB_3f4[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix3) && (Fpix[i_track] <= fpix6) ) vmrp_regionB_3f6[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix3) && (Fpix[i_track] <= fpix8) ) vmrp_regionB_3f8[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix3) && (Fpix[i_track] <= fpix9) ) vmrp_regionB_3f9[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix4) && (Fpix[i_track] <= fpix5) ) vmrp_regionB_4f5[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix5) && (Fpix[i_track] <= fpix6) ) vmrp_regionB_5f6[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix6) && (Fpix[i_track] <= fpix7) ) vmrp_regionB_6f7[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix6) && (Fpix[i_track] <= fpix9) ) vmrp_regionB_6f9[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix7) && (Fpix[i_track] <= fpix8) ) vmrp_regionB_7f8[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix8) && (Fpix[i_track] <= fpix9) ) vmrp_regionB_8f9[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix8) && (Fpix[i_track] <= fpix10) ) vmrp_regionB_8f10[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix9) && (Fpix[i_track] <= fpix10) ) vmrp_regionB_9f10[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix99) && (Fpix[i_track] <= fpix10) ) vmrp_regionB_99f10[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix999) && (Fpix[i_track] <= fpix10) ) vmrp_regionB_999f10[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                    }
                    else {
                        if( (Fpix[i_track] > fpix3) && (Fpix[i_track] <= fpix4) ) vmrp_regionC_3f4[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix3) && (Fpix[i_track] <= fpix6) ) vmrp_regionC_3f6[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix3) && (Fpix[i_track] <= fpix8) ) vmrp_regionC_3f8[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix3) && (Fpix[i_track] <= fpix9) ) vmrp_regionC_3f9[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix4) && (Fpix[i_track] <= fpix5) ) vmrp_regionC_4f5[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix5) && (Fpix[i_track] <= fpix6) ) vmrp_regionC_5f6[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix6) && (Fpix[i_track] <= fpix7) ) vmrp_regionC_6f7[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix6) && (Fpix[i_track] <= fpix9) ) vmrp_regionC_6f9[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix7) && (Fpix[i_track] <= fpix8) ) vmrp_regionC_7f8[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix8) && (Fpix[i_track] <= fpix9) ) vmrp_regionC_8f9[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        
                        if( (Fpix[i_track] > fpix3) && (Fpix[i_track] <= fpix4) ) vmrp_regionD_3f4[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix3) && (Fpix[i_track] <= fpix8) ) vmrp_regionD_3f8[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix4) && (Fpix[i_track] <= fpix5) ) vmrp_regionD_4f5[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix5) && (Fpix[i_track] <= fpix6) ) vmrp_regionD_5f6[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix6) && (Fpix[i_track] <= fpix7) ) vmrp_regionD_6f7[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix6) && (Fpix[i_track] <= fpix9) ) vmrp_regionD_6f9[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix7) && (Fpix[i_track] <= fpix8) ) vmrp_regionD_7f8[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix8) && (Fpix[i_track] <= fpix9) ) vmrp_regionD_8f9[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix8) && (Fpix[i_track] <= fpix10) ) vmrp_regionD_8f10[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix9) && (Fpix[i_track] <= fpix10) ) vmrp_regionD_9f10[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix99) && (Fpix[i_track] <= fpix10) ) vmrp_regionD_99f10[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                        if( (Fpix[i_track] > fpix999) && (Fpix[i_track] <= fpix10) ) vmrp_regionD_999f10[s].fill(Eta[i_track], NOM_noL1[i_track], overP, Pt_pseudo[i_track], Pterr[i_track], Ih_Strip[i_track], GStrip[i_track], massForRegions, *PV_npvsGood, Fpix[i_track], newWeight);
                    }

                    /*if(isMC && Pt_pseudo[i_track] > ptcut_ && Fpix[i_track] > fpix9 && Fpix[i_track] <= fpix10) {
                        vcp[s].FillHisto1F(selLabels_[s]+"_9fp10_SignalMass_nominal", massForRegions, AppliedWeight);
                        vcp[s].FillHisto1F(selLabels_[s]+"_9fp10_SignalMass_PUUp", massForRegions, AppliedWeight_PU_Up);
                        vcp[s].FillHisto1F(selLabels_[s]+"_9fp10_SignalMass_PUDown", massForRegions, AppliedWeight_PU_Down);
                        vcp[s].FillHisto1F(selLabels_[s]+"_9fp10_SignalMass_TriggerSFUp", massForRegions, AppliedWeight_SF_Up);
                        vcp[s].FillHisto1F(selLabels_[s]+"_9fp10_SignalMass_TriggerSFDown", massForRegions, AppliedWeight_SF_Down);
                        vcp[s].FillHisto1F(selLabels_[s]+"_9fp10_SignalMass_KUp", GetMass(Pt_pseudo[i_track]*cosh(Eta[i_track]),Ih_Strip[i_track],K+0.05,C), AppliedWeight);
                        vcp[s].FillHisto1F(selLabels_[s]+"_9fp10_SignalMass_KDown", GetMass(Pt_pseudo[i_track]*cosh(Eta[i_track]),Ih_Strip[i_track],K-0.05,C), AppliedWeight);
                        vcp[s].FillHisto1F(selLabels_[s]+"_9fp10_SignalMass_CUp", GetMass(Pt_pseudo[i_track]*cosh(Eta[i_track]),Ih_Strip[i_track],K,C+0.02), AppliedWeight);
                        vcp[s].FillHisto1F(selLabels_[s]+"_9fp10_SignalMass_CDown", GetMass(Pt_pseudo[i_track]*cosh(Eta[i_track]),Ih_Strip[i_track],K,C-0.02), AppliedWeight);
                        if (Fpix[i_track] * 1.005 > 0.3) vcp[s].FillHisto1F(selLabels_[s]+"_9fp10_SignalMass_FpixUp", massForRegions, AppliedWeight);
                        if (Fpix[i_track] * 0.995 > 0.3) vcp[s].FillHisto1F(selLabels_[s]+"_9fp10_SignalMass_FpixDown", massForRegions, AppliedWeight);
                    }*/

                }
            
            }
        }
        

        /*
            // No selections
        

            for (unsigned int k = 0; k < GenPart_pt.GetSize(); k++) {
                double dRgen = deltaR(Eta[i_track], Phi[i_track], GenPart_eta[k], GenPart_phi[k]);

                if (dRgen < 0.01 && fabs(GenPart_pdgId[k]) > 100000 ) {
                    vcp_nosel[0].FillHisto2F("genPT_vs_trackPseudoTrackPT", GenPart_pt[i_track] , Pt_pseudo[i_track], AppliedWeight);
                    vcp_nosel[0].FillHisto2F("genPT_vs_trackPT", GenPart_Pt_pseudo[i_track], Pt[i_track], AppliedWeight);

                    vcp_nosel[0].FillHisto1F("PseudoTrack_m_gen_over_gen", (Pt_pseudo[i_track]-GenPart_pt[i_track])/GenPart_pt[i_track], AppliedWeight);
                    vcp_nosel[0].FillHisto2F("gen__vs__PseudoTrack_m_gen_over_gen", GenPart_pt[i_track], (Pt_pseudo[i_track]-GenPart_pt[i_track])/GenPart_pt[i_track], AppliedWeight);
                    vcp_nosel[0].FillHisto1F("Track_m_gen_over_gen", (Pt[i_track]-GenPart_pt[i_track])/GenPart_pt[i_track], AppliedWeight);
                    vcp_nosel[0].FillHisto2F("gen__vs__Track_m_gen_over_gen", GenPart_pt[i_track], (Pt[i_track]-GenPart_pt[i_track])/GenPart_pt[i_track], AppliedWeight);
                }
            }
        

            for(unsigned int s=0;s<selections_.size();s++){ 
                bool (HSCPSelector::*ptr)(int);
                ptr = selections_[s];
                if((this->*ptr)(i_track)){

                    float P_pseudo = Pt_pseudo[i_track]*cosh(Eta[i_track]);

                    // Gen loop: mass calibration on K/pi/proton and gluino
                    for (unsigned int ig = 0; ig < GenPart_pt.GetSize(); ig++) {
                        double dRgen = deltaR(Eta[i_track], Phi[i_track], GenPart_eta[ig], GenPart_phi[ig]);

                        if (dRgen < 0.01 && (abs(GenPart_pdgId[ig])==211 || abs(GenPart_pdgId[ig])==321 || abs(GenPart_pdgId[ig])==2212)) {
                            if (abs(GenPart_pdgId[ig])==321 && P_pseudo/0.49367 > 1.5) {
                                vcp[s].FillHisto2F(selLabels_[s]+"_KPpi_ih_vs_betagamma", P_pseudo/0.49367, Ih_Strip[i_track], AppliedWeight);
                                vcp[s].FillHisto2F(selLabels_[s]+"_KPpi_ih_vs_p", P_pseudo, Ih_Strip[i_track], AppliedWeight);
                            }
                            else if (abs(GenPart_pdgId[ig])==211 && P_pseudo/0.13957 > 1.5) {
                                vcp[s].FillHisto2F(selLabels_[s]+"_KPpi_ih_vs_betagamma", P_pseudo/0.13957, Ih_Strip[i_track], AppliedWeight);
                                vcp[s].FillHisto2F(selLabels_[s]+"_KPpi_ih_vs_p", P_pseudo, Ih_Strip[i_track], AppliedWeight);
                            }
                            else if (abs(GenPart_pdgId[ig])==2212 && P_pseudo/0.93827 > 1.5) {
                                vcp[s].FillHisto2F(selLabels_[s]+"_KPpi_ih_vs_betagamma", P_pseudo/0.93827, Ih_Strip[i_track], AppliedWeight);
                                vcp[s].FillHisto2F(selLabels_[s]+"_KPpi_ih_vs_p", P_pseudo, Ih_Strip[i_track], AppliedWeight);
                            }
                        }

                        // beta*gamma < 1.5 : gluino part
                        if (dRgen < 0.01 && abs(GenPart_pdgId[ig]) > 1000000) { // && P_pseudo/GenPart_mass[ig] < 1.5)
                            vcp[s].FillHisto2F(selLabels_[s]+"_Gluino_ih_vs_betagamma", P_pseudo/GenPart_mass[ig], Ih_Strip[i_track], AppliedWeight);
                            vcp[s].FillHisto2F(selLabels_[s]+"_Gluino_ih_vs_p", P_pseudo, Ih_Strip[i_track], AppliedWeight);
                        }

                    }

                    // Muon loop: mass calibration on K/pi/proton and gluino
                    for (unsigned int im = 0; im < muon_pt.GetSize(); im++) {
                        double dRmu = deltaR(Eta[i_track], Phi[i_track], muon_eta[im], muon_phi[im]);
                        if (dRmu < 0.01) {
                            vcp[s].FillHisto2F(selLabels_[s]+"_Mu_ih_vs_betagamma", P_pseudo/0.10566, Ih_Strip[i_track], AppliedWeight);
                            vcp[s].FillHisto2F(selLabels_[s]+"_Mu_ih_vs_p", P_pseudo, Ih_Strip[i_track], AppliedWeight);
                        }
                    }

                } 
            } // end of selections
        */
        i_track++;

    } // End of loop over all candidates


    if ((*HLT_PFMET120_PFMHT120_IDTight || *HLT_PFHT500_PFMET100_PFMHT100_IDTight || *HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 || *HLT_MET105_IsoTrk50) 
    && (Flag_allMETFilters[0] == true)) {
        vcp_nosel[0].FillHisto1F("PostTrigger_PseudoCaloMET_SF_rescaled", PseudoCaloMET[0]*163.451/146.864, AppliedWeight);
        vcp_nosel[0].FillHisto1F("PostTrigger_PseudoCaloMET_SF_NOTrescaled", PseudoCaloMET[0], AppliedWeight_NOTrescaled);
    }

    if ((*HLT_PFMET120_PFMHT120_IDTight || *HLT_PFHT500_PFMET100_PFMHT100_IDTight || *HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 || *HLT_MET105_IsoTrk50) 
    && (Flag_allMETFilters[0] == true)) {
        vcp_nosel[0].FillHisto1F("PostTrigger_PseudoCaloMET_rescaled", PseudoCaloMET[0]*163.451/146.864, *weightPU);
        vcp_nosel[0].FillHisto1F("PostTrigger_PseudoCaloMET_NOTrescaled", PseudoCaloMET[0], *weightPU);
    }
    
    vcp_nosel[0].FillHisto2F("Nosel_PseudoMET_vs_PFMET", PseudoCaloMET[0], RecoPFMET[0], *weightPU);
    vcp_nosel[0].FillHisto1F("Nosel_PseudoCaloMET", PseudoCaloMET[0], *weightPU);
    if (isMC) vcp_nosel[0].FillHisto1F("Nosel_PseudoCaloMET_rescaled", PseudoCaloMET[0]*163.451/146.864, *weightPU); // rescale = MAX_data/MAX_MC
    


    // for all event, compute the trigger efficiency vs the PseudoCaloMET
    for(unsigned int s=0;s<selections_.size();s++) { 

        bool SelPassed = false;
        for(unsigned int j=0; j<HSCP_hasTrack.GetSize(); j++){
            if (!HSCP_hasTrack[j]) continue;
            if ((this->*selections_[s])(j)) SelPassed = true;
        }

        if (SelPassed) {
            vcp[s].FillHisto1F(selLabels_[s]+"_nHSCP", *HSCP_n, AppliedWeight);
            vcp[s].FillHisto1F(selLabels_[s]+"_nPVgood", *PV_npvsGood, AppliedWeight);
        }

        if (SelPassed) { //&& (selLabels_[s]=="METanalysis_Eta2p4" || selLabels_[s]=="METanalysis_Eta1_2p4" || selLabels_[s]=="METanalysis_Eta1" || selLabels_[s]=="METanalysis_Eta2p4_EffTrg")) { // at least one candidate passes the selection

            // Trigger efficiency
            vcp[s].FillHisto1F(selLabels_[s]+"_PuppiMET", RecoPuppiMET[0], AppliedWeight);
            vcp[s].FillHisto1F(selLabels_[s]+"_PseudoCaloMET", PseudoCaloMET[0], AppliedWeight);
            if (isMC) {
                vcp[s].FillHisto1F(selLabels_[s]+"_PseudoCaloMET_rescaled", PseudoCaloMET[0]*163.451/146.864, AppliedWeight); // weight = MAX_data/MAX_MC
                vcp[s].FillHisto1F(selLabels_[s]+"_PseudoCaloMET_NOTrescaled", PseudoCaloMET[0], AppliedWeight_NOTrescaled);
            }
            vcp[s].FillHisto1F(selLabels_[s]+"_RecoPFMET", RecoPFMET[0], AppliedWeight);    
            if (PseudoCaloMET[0] > 170) vcp[s].FillHisto1F(selLabels_[s]+"_RecoPFMET__PseudoCaloMETCut", RecoPFMET[0], AppliedWeight);
            if (RecoPFMET[0] > 170) vcp[s].FillHisto1F(selLabels_[s]+"_PseudoCaloMET__RecoPFMETCut", PseudoCaloMET[0], AppliedWeight);
            vcp[s].FillHisto1F(selLabels_[s]+"_L1MET", L1MET[0], AppliedWeight);
            vcp[s].FillHisto1F(selLabels_[s]+"_HLTCaloMET", HLTCaloMET[0], AppliedWeight);
            vcp[s].FillHisto1F(selLabels_[s]+"_HLTCaloMHT", HLTCaloMHT[0], AppliedWeight);
            vcp[s].FillHisto1F(selLabels_[s]+"_HLTPFMHT", HLTPFMHT[0], AppliedWeight);
            vcp[s].FillHisto1F(selLabels_[s]+"_HLTPFMET", HLTPFMET[0], AppliedWeight);


            if (*HLT_PFMET120_PFMHT120_IDTight) {
                vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET", PseudoCaloMET[0], AppliedWeight);
                vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET", RecoPFMET[0], AppliedWeight);
                if (PseudoCaloMET[0] > 170) vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET__PseudoCaloMETCut", RecoPFMET[0], AppliedWeight);
                if (RecoPFMET[0] > 170) vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFMET120_PFMHT120_IDTight___PseudoCaloMET__RecoPFMETCut", PseudoCaloMET[0], AppliedWeight);
            }
            if (*HLT_PFHT500_PFMET100_PFMHT100_IDTight) {
                vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET", PseudoCaloMET[0], AppliedWeight);
                vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET", RecoPFMET[0], AppliedWeight);
                if (PseudoCaloMET[0] > 170) vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET__PseudoCaloMETCut", RecoPFMET[0], AppliedWeight);
                if (RecoPFMET[0] > 170) vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___PseudoCaloMET__RecoPFMETCut", PseudoCaloMET[0], AppliedWeight);
            }
            if (*HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60) {
                vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET", PseudoCaloMET[0], AppliedWeight);
                vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET", RecoPFMET[0], AppliedWeight);
                if (PseudoCaloMET[0] > 170) vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET__PseudoCaloMETCut", RecoPFMET[0], AppliedWeight);
                if (RecoPFMET[0] > 170) vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___PseudoCaloMET__RecoPFMETCut", PseudoCaloMET[0], AppliedWeight);
            }
            if (*HLT_MET105_IsoTrk50) {
                vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_MET105_IsoTrk50___PseudoCaloMET", PseudoCaloMET[0], AppliedWeight);
                vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_MET105_IsoTrk50___RecoPFMET", RecoPFMET[0], AppliedWeight);
                if (PseudoCaloMET[0] > 170) vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_MET105_IsoTrk50___RecoPFMET__PseudoCaloMETCut", RecoPFMET[0], AppliedWeight);
                if (RecoPFMET[0] > 170) vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_MET105_IsoTrk50___PseudoCaloMET__RecoPFMETCut", PseudoCaloMET[0], AppliedWeight);
            }
            if (*HLT_PFMET120_PFMHT120_IDTight || *HLT_PFHT500_PFMET100_PFMHT100_IDTight
                || *HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 || *HLT_MET105_IsoTrk50) {
                vcp[s].FillHisto1F(selLabels_[s]+"_if___orMETtrg___PseudoCaloMET", PseudoCaloMET[0], AppliedWeight);
                vcp[s].FillHisto1F(selLabels_[s]+"_if___orMETtrg___RecoPFMET", RecoPFMET[0], AppliedWeight);
                if (PseudoCaloMET[0] > 170) vcp[s].FillHisto1F(selLabels_[s]+"_if___orMETtrg___RecoPFMET__PseudoCaloMETCut", RecoPFMET[0], AppliedWeight);
                if (RecoPFMET[0] > 170) vcp[s].FillHisto1F(selLabels_[s]+"_if___orMETtrg___PseudoCaloMET__RecoPFMETCut", PseudoCaloMET[0], AppliedWeight);
             }
                

    //         if (isAOD) {
    //             vcp[s].FillHisto1F(selLabels_[s]+"_RecoCaloMET", RecoCaloMET[0], AppliedWeight);
    //             if (*HLT_PFMET120_PFMHT120_IDTight) vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFMET120_PFMHT120_IDTight___RecoCaloMET", RecoCaloMET[0], AppliedWeight);                
    //             if (*HLT_PFHT500_PFMET100_PFMHT100_IDTight) vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoCaloMET", RecoCaloMET[0], AppliedWeight);
    //             if (*HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60) vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoCaloMET", RecoCaloMET[0], AppliedWeight);
    //             if (*HLT_MET105_IsoTrk50) vcp[s].FillHisto1F(selLabels_[s]+"_if___HLT_MET105_IsoTrk50___RecoCaloMET", RecoCaloMET[0], AppliedWeight);
    //             if (*HLT_PFMET120_PFMHT120_IDTight || *HLT_PFHT500_PFMET100_PFMHT100_IDTight
    //                 || *HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 || *HLT_MET105_IsoTrk50)
    //                 vcp[s].FillHisto1F(selLabels_[s]+"_if___orMETtrg___RecoCaloMET", RecoCaloMET[0], AppliedWeight);
    //         }

        }
    }

   return kTRUE;
}


void HSCPSelector::SlaveTerminate()
{
    std::cout << std::endl;
    cout << "Object are saved" << endl;
    for(auto obj: vcp) obj.AddToList(fOutput);
    for(auto obj: vcp_nosel) obj.AddToList(fOutput);

    if(UseFpixel){

        //for(auto obj: vmrp_regionFpix_all) obj.addToList(fOutput);

        for(auto obj: vmrp_regionA_3f4) obj.addToList(fOutput);
        for(auto obj: vmrp_regionA_3f6) obj.addToList(fOutput);
        for(auto obj: vmrp_regionA_3f8) obj.addToList(fOutput);
        for(auto obj: vmrp_regionA_3f9) obj.addToList(fOutput);
        for(auto obj: vmrp_regionA_4f5) obj.addToList(fOutput);
        for(auto obj: vmrp_regionA_5f6) obj.addToList(fOutput);
        for(auto obj: vmrp_regionA_6f7) obj.addToList(fOutput);
        for(auto obj: vmrp_regionA_6f9) obj.addToList(fOutput);
        for(auto obj: vmrp_regionA_7f8) obj.addToList(fOutput);
        for(auto obj: vmrp_regionA_8f9) obj.addToList(fOutput);
        for(auto obj: vmrp_regionA_9f10) obj.addToList(fOutput);
        for(auto obj: vmrp_regionA_99f10) obj.addToList(fOutput);
        for(auto obj: vmrp_regionA_999f10) obj.addToList(fOutput);

        for(auto obj: vmrp_regionB_3f4) obj.addToList(fOutput);
        for(auto obj: vmrp_regionB_3f6) obj.addToList(fOutput);
        for(auto obj: vmrp_regionB_3f8) obj.addToList(fOutput);
        for(auto obj: vmrp_regionB_3f9) obj.addToList(fOutput);
        for(auto obj: vmrp_regionB_4f5) obj.addToList(fOutput);
        for(auto obj: vmrp_regionB_5f6) obj.addToList(fOutput);
        for(auto obj: vmrp_regionB_6f7) obj.addToList(fOutput);
        for(auto obj: vmrp_regionB_6f9) obj.addToList(fOutput);
        for(auto obj: vmrp_regionB_7f8) obj.addToList(fOutput);
        for(auto obj: vmrp_regionB_8f9) obj.addToList(fOutput);
        for(auto obj: vmrp_regionB_8f10) obj.addToList(fOutput);
        for(auto obj: vmrp_regionB_9f10) obj.addToList(fOutput);
        for(auto obj: vmrp_regionB_99f10) obj.addToList(fOutput);
        for(auto obj: vmrp_regionB_999f10) obj.addToList(fOutput);

        for(auto obj: vmrp_regionC_3f4) obj.addToList(fOutput);
        for(auto obj: vmrp_regionC_3f6) obj.addToList(fOutput);
        for(auto obj: vmrp_regionC_3f8) obj.addToList(fOutput);
        for(auto obj: vmrp_regionC_3f9) obj.addToList(fOutput);
        for(auto obj: vmrp_regionC_4f5) obj.addToList(fOutput);
        for(auto obj: vmrp_regionC_5f6) obj.addToList(fOutput);
        for(auto obj: vmrp_regionC_6f7) obj.addToList(fOutput);
        for(auto obj: vmrp_regionC_6f9) obj.addToList(fOutput);
        for(auto obj: vmrp_regionC_7f8) obj.addToList(fOutput);
        for(auto obj: vmrp_regionC_8f9) obj.addToList(fOutput);

        for(auto obj: vmrp_regionD_3f4) obj.addToList(fOutput);
        for(auto obj: vmrp_regionD_3f8) obj.addToList(fOutput);
        for(auto obj: vmrp_regionD_4f5) obj.addToList(fOutput);
        for(auto obj: vmrp_regionD_5f6) obj.addToList(fOutput);
        for(auto obj: vmrp_regionD_6f7) obj.addToList(fOutput);
        for(auto obj: vmrp_regionD_6f9) obj.addToList(fOutput);
        for(auto obj: vmrp_regionD_7f8) obj.addToList(fOutput);
        for(auto obj: vmrp_regionD_8f9) obj.addToList(fOutput);
        for(auto obj: vmrp_regionD_8f10) obj.addToList(fOutput);
        for(auto obj: vmrp_regionD_9f10) obj.addToList(fOutput);
        for(auto obj: vmrp_regionD_99f10) obj.addToList(fOutput);
        for(auto obj: vmrp_regionD_999f10) obj.addToList(fOutput);
    }
}

void HSCPSelector::Terminate()
{
    //create the output file
    std::cout << std::endl;
    std::cout << "Terminate function" << std::endl;
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