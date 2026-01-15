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


void HSCPSelector::Begin(TTree *tree)
{
    TString option = GetOption();
    TObjArray *tx = option.Tokenize(",");

    // Output file
    oFile_ = ((TObjString *)(tx->At(7)))->String().Data();
    oFile_ += "_";
    oFile_ += ((TObjString *)(tx->At(8)))->String().Data();
    oFile_ += "_Eta2p4";
    oFile_ += ".root";


    // Options
    UseFpixel = true;


    //FILL-SELECTION-VECTOR

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
    //-------------------------------------

    //-------------------------------------
    //create RegionMassPlot for all selection
    //-------------------------------------
    for(unsigned int i=0;i<selLabels_.size();i++)
    {
        if(UseFpixel){
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
            RegionMassPlot regAll(label_FpixAll.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 

            RegionMassPlot regA_3f4(label_FpixA_3f4.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C);
            RegionMassPlot regA_3f6(label_FpixA_3f6.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regA_3f8(label_FpixA_3f8.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regA_3f9(label_FpixA_3f9.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regA_4f5(label_FpixA_4f5.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regA_5f6(label_FpixA_5f6.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regA_6f7(label_FpixA_6f7.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C);
            RegionMassPlot regA_6f9(label_FpixA_6f9.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C);
            RegionMassPlot regA_7f8(label_FpixA_7f8.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C);
            RegionMassPlot regA_8f9(label_FpixA_8f9.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regA_9f10(label_FpixA_9f10.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regA_99f10(label_FpixA_99f10.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regA_999f10(label_FpixA_999f10.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 

            RegionMassPlot regB_3f4(label_FpixB_3f4.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regB_3f6(label_FpixB_3f6.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regB_3f8(label_FpixB_3f8.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regB_3f9(label_FpixB_3f9.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regB_4f5(label_FpixB_4f5.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regB_5f6(label_FpixB_5f6.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regB_6f7(label_FpixB_6f7.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regB_6f9(label_FpixB_6f9.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regB_7f8(label_FpixB_7f8.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C);     
            RegionMassPlot regB_8f9(label_FpixB_8f9.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regB_8f10(label_FpixB_8f10.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regB_9f10(label_FpixB_9f10.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regB_99f10(label_FpixB_99f10.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regB_999f10(label_FpixB_999f10.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C);

            RegionMassPlot regC_3f4(label_FpixC_3f4.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regC_3f6(label_FpixC_3f6.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regC_3f8(label_FpixC_3f8.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regC_3f9(label_FpixC_3f9.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regC_4f5(label_FpixC_4f5.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regC_5f6(label_FpixC_5f6.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regC_6f7(label_FpixC_6f7.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regC_6f9(label_FpixC_6f9.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regC_7f8(label_FpixC_7f8.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regC_8f9(label_FpixC_8f9.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 

            RegionMassPlot regD_3f4(label_FpixD_3f4.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regD_3f8(label_FpixD_3f8.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regD_4f5(label_FpixD_4f5.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regD_5f6(label_FpixD_5f6.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regD_6f7(label_FpixD_6f7.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regD_6f9(label_FpixD_6f9.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regD_7f8(label_FpixD_7f8.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C);     
            RegionMassPlot regD_8f9(label_FpixD_8f9.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regD_8f10(label_FpixD_8f10.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regD_9f10(label_FpixD_9f10.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regD_99f10(label_FpixD_99f10.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
            RegionMassPlot regD_999f10(label_FpixD_999f10.c_str(),etabins_,ihbins_,pbins_,massbins_,fpixbins_, C); 
        

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
        plots.AddHisto2D(selLabels_[i]+"_Mu_ih_vs_betagamma", 500, 0., 15000., 100, 0., 10.);
        plots.AddHisto2D(selLabels_[i]+"_Mu_ih_vs_p", 500, 0., 6000., 100, 0.,10.);
        plots.AddHisto2D(selLabels_[i]+"_KPpi_ih_vs_betagamma", 500, 0., 5000., 100, 0., 10.);
        plots.AddHisto2D(selLabels_[i]+"_KPpi_ih_vs_p", 500, 0., 3000., 100, 0., 10.);
        plots.AddHisto2D(selLabels_[i]+"_Gluino_ih_vs_betagamma", 1000, 0., 5., 500, 0., 50.);
        plots.AddHisto2D(selLabels_[i]+"_Gluino_ih_vs_p", 500, 0., 3000., 500, 0.,50.);


        // Trigger efficiency
        plots.AddHisto1D(selLabels_[i]+"_PuppiMET", 100, 0, 2500);

        plots.AddHisto1D(selLabels_[i]+"_CaloJets", 100, 0, 2500);
        plots.AddHisto1D(selLabels_[i]+"_if___HLT_PFMET120_PFMHT120_IDTight___CaloJets", 100, 0, 2500);
        plots.AddHisto1D(selLabels_[i]+"_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___CaloJets", 100, 0, 2500);
        plots.AddHisto1D(selLabels_[i]+"_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___CaloJets", 100, 0, 2500);
        plots.AddHisto1D(selLabels_[i]+"_if___HLT_MET105_IsoTrk50___CaloJets", 100, 0, 2500);

        plots.AddHisto1D(selLabels_[i]+"_RecoPFMET", 100, 0, 2500);
        plots.AddHisto1D(selLabels_[i]+"_RecoPFMET__CaloJetsCut", 100, 0, 2500);
        plots.AddHisto1D(selLabels_[i]+"_if___HLT_PFMET120_PFMHT120_IDTight___RecoPFMET", 100, 0, 2500);
        plots.AddHisto1D(selLabels_[i]+"_if___HLT_PFHT500_PFMET100_PFMHT100_IDTight___RecoPFMET", 100, 0, 2500);
        plots.AddHisto1D(selLabels_[i]+"_if___HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60___RecoPFMET", 100, 0, 2500);
        plots.AddHisto1D(selLabels_[i]+"_if___HLT_MET105_IsoTrk50___RecoPFMET", 100, 0, 2500);

        plots.AddHisto1D(selLabels_[i]+"_if___orMETtrg___CaloJets", 100, 0, 2500);
        plots.AddHisto1D(selLabels_[i]+"_if___orMETtrg___RecoPFMET", 100, 0, 2500);
        plots.AddHisto1D(selLabels_[i]+"_if___orMETtrg___RecoPFMET__CaloJetsCut", 100, 0, 2500);

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
    plots.AddHisto1D("EventCutflow__isGen_lastbin", 2, -0.5, 1.5);

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

    plots.AddHisto1D("Ih_Strip", 200, 0, 10);
    plots.AddHisto1D("Ih_Strip_oldCorr", 200, 0, 10);
    plots.AddHisto1D("GStrip", 200, 0, 1);
    plots.AddHisto1D("GStrip_oldCorr", 200, 0, 1);


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
    fReader.SetLocalEntry(entry);
    
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
        trigger = *HLT_Mu50;
        METfilters = true; // no MET filters in muon datasets
        CaloMET_pseudoMET = 200; // no CaloMET in muon datasets, set it to pass the cut
    }
    else if (dataset_.find("MET") != std::string::npos) {
        trigger = *HLT_PFMET120_PFMHT120_IDTight || *HLT_PFHT500_PFMET100_PFMHT100_IDTight
        || *HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 || *HLT_MET105_IsoTrk50;

        METfilters = Flag_allMETFilters[0];
        CaloMET_pseudoMET = CaloJets[0]; // to change with CaloJets[0];
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
        //cuts.push_back([&](int i){ return Pt_pseudo[i] > 55.0; });
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
        //cuts.push_back([&](int i){ return ptOverptErr[i] < 1; });
        //cuts.push_back([&](int i){ return Ih_Strip[i] > 3.14; });
        

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
        //cuts_NotrackCut[17] = [&](int i){ return true; }; // ptOverptErr

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
        //if (passedCuts[17]) vcp_nosel[0].FillHisto1D("Nm1_PtErr_over_Pt", ptOverptErr[i]);
        //if (passedCuts[18]) vcp_nosel[0].FillHisto1D("Nm1_Ih_StripOnly", Ih_Strip[i]);


            // Event cutflow last bin: check GenPart info and PF_type
        if (eventCuts[16]) {
            for (unsigned int j = 0; j < GenPart_pt.GetSize(); j++) {
                float dEta = GenPart_eta[j] - Eta[i];
                float dPhi = GenPart_phi[j] - Phi[i];
                while (dPhi >  M_PI) dPhi -= 2*M_PI;
                while (dPhi < -M_PI) dPhi += 2*M_PI;
                if (std::sqrt(dEta*dEta + dPhi*dPhi) < 0.01) {
                    vcp_nosel[0].FillHisto2D("LastBinEventCutflow___GenPt_vs_trackPt", GenPart_pt[j], Pt[i]);
                    vcp_nosel[0].FillHisto1D("EventCutflow__isGen_lastbin", 1);
                }
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


    i = 0;
    for(unsigned int j=0; j<HSCP_hasTrack.GetSize(); j++){    // Every candidate

        if (!HSCP_hasTrack[j]) continue;

        //vcp_nosel[0].FillHisto1D("Ih_Strip_oldCorr", Ih_Strip_oldCorr[i]);
        //vcp_nosel[0].FillHisto1D("GStrip_oldCorr", GStrip_oldCorr[i]);
        vcp_nosel[0].FillHisto1D("Ih_Strip", Ih_Strip[i]);
        vcp_nosel[0].FillHisto1D("GStrip", GStrip[i]);

        /*
        // No selections
        vcp_nosel[0].FillHisto2D("trackPT_vs_trackPseudoTrackPT", Pt[i], Pt_pseudo[i]);
        vcp_nosel[0].FillHisto2D("trackETA_vs_trackPseudoTrackETA", Eta[i], Eta_pseudo[i]);
        vcp_nosel[0].FillHisto2D("trackPHI_vs_trackPseudoTrackPHI", Phi[i], Phi_pseudo[i]);

        for (unsigned int k = 0; k < GenPart_pt.GetSize(); k++) {
            double dRgen = deltaR(Eta[i], Phi[i], GenPart_eta[k], GenPart_phi[k]);

            if (dRgen < 0.01 && fabs(GenPart_pdgId[k]) > 100000 ) {
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

                float P_pseudo = Pt_pseudo[i]*cosh(Eta[i]);

                // Gen loop: mass calibration on K/pi/proton and gluino
                for (unsigned int ig = 0; ig < GenPart_pt.GetSize(); ig++) {
                    double dRgen = deltaR(Eta[i], Phi[i], GenPart_eta[ig], GenPart_phi[ig]);

                    if (dRgen < 0.01 && (abs(GenPart_pdgId[ig])==211 || abs(GenPart_pdgId[ig])==321 || abs(GenPart_pdgId[ig])==2212)) {
                        if (abs(GenPart_pdgId[ig])==321 && P_pseudo/0.49367 > 1.5) {
                            vcp[s].FillHisto2D(selLabels_[s]+"_KPpi_ih_vs_betagamma", P_pseudo/0.49367, Ih_Strip[i]);
                            vcp[s].FillHisto2D(selLabels_[s]+"_KPpi_ih_vs_p", P_pseudo, Ih_Strip[i]);
                        }
                        else if (abs(GenPart_pdgId[ig])==211 && P_pseudo/0.13957 > 1.5) {
                            vcp[s].FillHisto2D(selLabels_[s]+"_KPpi_ih_vs_betagamma", P_pseudo/0.13957, Ih_Strip[i]);
                            vcp[s].FillHisto2D(selLabels_[s]+"_KPpi_ih_vs_p", P_pseudo, Ih_Strip[i]);
                        }
                        else if (abs(GenPart_pdgId[ig])==2212 && P_pseudo/0.93827 > 1.5) {
                            vcp[s].FillHisto2D(selLabels_[s]+"_KPpi_ih_vs_betagamma", P_pseudo/0.93827, Ih_Strip[i]);
                            vcp[s].FillHisto2D(selLabels_[s]+"_KPpi_ih_vs_p", P_pseudo, Ih_Strip[i]);
                        }
                    }

                    // beta*gamma < 1.5 : gluino part
                    if (dRgen < 0.01 && abs(GenPart_pdgId[ig]) > 1000000) { // && P_pseudo/GenPart_mass[ig] < 1.5)
                        vcp[s].FillHisto2D(selLabels_[s]+"_Gluino_ih_vs_betagamma", P_pseudo/GenPart_mass[ig], Ih_Strip[i]);
                        vcp[s].FillHisto2D(selLabels_[s]+"_Gluino_ih_vs_p", P_pseudo, Ih_Strip[i]);
                    }

                }

                // Muon loop: mass calibration on K/pi/proton and gluino
                for (unsigned int im = 0; im < muon_pt.GetSize(); im++) {
                    double dRmu = deltaR(Eta[i], Phi[i], muon_eta[im], muon_phi[im]);
                    if (dRmu < 0.01) {
                        vcp[s].FillHisto2D(selLabels_[s]+"_Mu_ih_vs_betagamma", P_pseudo/0.10566, Ih_Strip[i]);
                        vcp[s].FillHisto2D(selLabels_[s]+"_Mu_ih_vs_p", P_pseudo, Ih_Strip[i]);
                    }
                }

            } 
        } // end of selections
        */
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
            vcp[s].FillHisto1D(selLabels_[s]+"_PuppiMET", RecoPuppiMET[0]);
            vcp[s].FillHisto1D(selLabels_[s]+"_CaloJets", CaloJets[0]);     // usefull for calibration on ttbar
            vcp[s].FillHisto1D(selLabels_[s]+"_RecoPFMET", RecoPFMET[0]);
            if (CaloJets[0] > 170) vcp[s].FillHisto1D(selLabels_[s]+"_RecoPFMET__CaloJetsCut", RecoPFMET[0]);

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

                if (CaloJets[0] > 170)
                    vcp[s].FillHisto1D(selLabels_[s]+"_if___orMETtrg___RecoPFMET__CaloJetsCut", RecoPFMET[0]);
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


            if(UseFpixel) {
                double newWeight = 1.0;
                double massForRegions = GetMass(Pt[i]*cosh(Eta[i]),Ih_Strip[i],K,C);

                //vmrp_regionFpix_all[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);

                if(Pt[i] <= ptcut_) {
                    if( (Fpix[i] > fpix3) && (Fpix[i] <= fpix4) ) vmrp_regionA_3f4[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix3) && (Fpix[i] <= fpix6) ) vmrp_regionA_3f6[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix3) && (Fpix[i] <= fpix8) ) vmrp_regionA_3f8[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix3) && (Fpix[i] <= fpix9) ) vmrp_regionA_3f9[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix4) && (Fpix[i] <= fpix5) ) vmrp_regionA_4f5[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix5) && (Fpix[i] <= fpix6) ) vmrp_regionA_5f6[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix6) && (Fpix[i] <= fpix7) ) vmrp_regionA_6f7[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix6) && (Fpix[i] <= fpix9) ) vmrp_regionA_6f9[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix7) && (Fpix[i] <= fpix8) ) vmrp_regionA_7f8[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix8) && (Fpix[i] <= fpix9) ) vmrp_regionA_8f9[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix9) && (Fpix[i] <= fpix10) ) vmrp_regionA_9f10[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix99) && (Fpix[i] <= fpix10) ) vmrp_regionA_99f10[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix999) && (Fpix[i] <= fpix10) ) vmrp_regionA_999f10[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    
                    if( (Fpix[i] > fpix3) && (Fpix[i] <= fpix4) ) vmrp_regionB_3f4[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix3) && (Fpix[i] <= fpix6) ) vmrp_regionB_3f6[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix3) && (Fpix[i] <= fpix8) ) vmrp_regionB_3f8[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix3) && (Fpix[i] <= fpix9) ) vmrp_regionB_3f9[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix4) && (Fpix[i] <= fpix5) ) vmrp_regionB_4f5[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix5) && (Fpix[i] <= fpix6) ) vmrp_regionB_5f6[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix6) && (Fpix[i] <= fpix7) ) vmrp_regionB_6f7[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix6) && (Fpix[i] <= fpix9) ) vmrp_regionB_6f9[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix7) && (Fpix[i] <= fpix8) ) vmrp_regionB_7f8[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix8) && (Fpix[i] <= fpix9) ) vmrp_regionB_8f9[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix8) && (Fpix[i] <= fpix10) ) vmrp_regionB_8f10[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix9) && (Fpix[i] <= fpix10) ) vmrp_regionB_9f10[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix99) && (Fpix[i] <= fpix10) ) vmrp_regionB_99f10[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix999) && (Fpix[i] <= fpix10) ) vmrp_regionB_999f10[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                }
                else {
                    if( (Fpix[i] > fpix3) && (Fpix[i] <= fpix4) ) vmrp_regionC_3f4[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix3) && (Fpix[i] <= fpix6) ) vmrp_regionC_3f6[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix3) && (Fpix[i] <= fpix8) ) vmrp_regionC_3f8[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix3) && (Fpix[i] <= fpix9) ) vmrp_regionC_3f9[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix4) && (Fpix[i] <= fpix5) ) vmrp_regionC_4f5[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix5) && (Fpix[i] <= fpix6) ) vmrp_regionC_5f6[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix6) && (Fpix[i] <= fpix7) ) vmrp_regionC_6f7[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix6) && (Fpix[i] <= fpix9) ) vmrp_regionC_6f9[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix7) && (Fpix[i] <= fpix8) ) vmrp_regionC_7f8[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix8) && (Fpix[i] <= fpix9) ) vmrp_regionC_8f9[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    
                    if( (Fpix[i] > fpix3) && (Fpix[i] <= fpix4) ) vmrp_regionD_3f4[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix3) && (Fpix[i] <= fpix8) ) vmrp_regionD_3f8[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix4) && (Fpix[i] <= fpix5) ) vmrp_regionD_4f5[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix5) && (Fpix[i] <= fpix6) ) vmrp_regionD_5f6[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix6) && (Fpix[i] <= fpix7) ) vmrp_regionD_6f7[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix6) && (Fpix[i] <= fpix9) ) vmrp_regionD_6f9[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix7) && (Fpix[i] <= fpix8) ) vmrp_regionD_7f8[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix8) && (Fpix[i] <= fpix9) ) vmrp_regionD_8f9[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix8) && (Fpix[i] <= fpix10) ) vmrp_regionD_8f10[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix9) && (Fpix[i] <= fpix10) ) vmrp_regionD_9f10[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix99) && (Fpix[i] <= fpix10) ) vmrp_regionD_99f10[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                    if( (Fpix[i] > fpix999) && (Fpix[i] <= fpix10) ) vmrp_regionD_999f10[s].fill(Eta[i], NOM_noL1[i], P[i], Pt[i], Pterr[i], Ih_Strip[i], GStrip[i], massForRegions, *PV_npvsGood, Fpix[i], newWeight);
                }
            }

        }
    }

   return kTRUE;
}


void HSCPSelector::SlaveTerminate()
{
    for(auto obj: vcp) obj.AddToList(fOutput);
    for(auto obj: vcp_nosel) obj.AddToList(fOutput);

    if(UseFpixel){
       std::cout<<"We use Fpix for the cut on ionization (based on pixels, uncorellated with Ih_strip)" << std::endl;

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