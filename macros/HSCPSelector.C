#define HSCPSelector_cxx
// The class definition in HSCPSelector.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.


// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("HSCPSelector.C")
// root> T->Process("HSCPSelector.C","some options")
// root> T->Process("HSCPSelector.C+")
//

#include "HSCPSelector.h"
#include <TH2.h>
#include <TH1.h>
#include <TStyle.h>


//K and C values are set based on the config file dataset name (see below)
float K(2.54), C(3.14); 


float K_signal2017(2.48), C_signal2017(3.19); //MC signal 2017
float K_signal2018(2.49), C_signal2018(3.18); //MC signal 2018

float K_bckg2017(2.48), C_bckg2017(3.19); //MC background 2017
float K_bckg2018(2.49), C_bckg2018(3.18); //MC background 2018

float K_data2018(2.55), C_data2018(3.14); //Data 2018
float K_data2017(2.54), C_data2017(3.14); //Data 2017

int year(2018);



//std::ofstream OutputTuples("/opt/sbg/cms/ui3_data1/gcoulon/CMSSW_10_6_30/src/HSCPTreeAnalyzer/macros/massForRegions.txt", std::ios::app);


//ADD-SELECTION-METHODS
bool HSCPSelector::PassHSCPpresel_SingleMu(int i){
   if (i<0 || i>(int)Pt.GetSize()) return false;
   return ( ( (*Trig.Get() > 0) && (Pt[i] > 55.0) && (abs(eta[i]) < 2.4) && (NOPH[i] >= 2) && (FOVH[i] > 0.8) && (NOM[i] >= 10) && ((*isHighPurity.Get())[i] == true) && (Chi2[i]/Ndof[i] < 5.0) && (abs(dZ[i]) < 0.1) && (abs(dXY[i]) < 0.02) && (PFMiniIso_relative[i] < 0.02) && (EoverP[i] < 0.3) && (PtErr[i]/Pt[i] < 1) && (track_genTrackIsoSumPt_dr03[i] < 15) && (PtErr[i]/(Pt[i]*Pt[i]) < 0.0008) && (PtErr[i]/(Pt[i]*Pt[i]) > 0) && (ProbQ_noL1[i] < 0.7) && (ProbQ_noL1[i] > 0) && (Ih_StripOnly[i] > 3.14) ) );
}

bool HSCPSelector::PassHSCPpresel_METContainingMu(int i){
   if (i<0 || i>(int)Pt.GetSize()) return false;
   return ( ( (*HLT_PFMET120_PFMHT120_IDTight.Get()==true || *HLT_PFHT500_PFMET100_PFMHT100_IDTight.Get()==true || *HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60.Get()==true || *HLT_MET105_IsoTrk50.Get()==true) && (*RecoCaloMET.Get() > 170) && (*Flag_allMETFilters.Get() == true) && (Pt[i] > 55.0) && (abs(eta[i]) < 2.4) && (NOPH[i] >= 2) && (FOVH[i] > 0.8) && (NOM[i] >= 10) && ((*isHighPurity.Get())[i] == true) && (Chi2[i]/Ndof[i] < 5.0) && (abs(dZ[i]) < 0.1) && (abs(dXY[i]) < 0.02) && (PFMiniIso_relative[i] < 0.02) && (EoverP[i] < 0.3) && (PtErr[i]/Pt[i] < 1) && (track_genTrackIsoSumPt_dr03[i] < 15) && (PtErr[i]/(Pt[i]*Pt[i]) < 0.0008) && (PtErr[i]/(Pt[i]*Pt[i]) > 0) && (ProbQ_noL1[i] < 0.7) && (ProbQ_noL1[i] > 0) && (Ih_StripOnly[i] > 3.14) ) );
}

bool HSCPSelector::PassHSCPpresel_OnlyMET(int i){
   if (i<0 || i>(int)Pt.GetSize()) return false;
   return ( ( (*HLT_Mu50.Get() == false) && (*HLT_PFMET120_PFMHT120_IDTight.Get()==true || *HLT_PFHT500_PFMET100_PFMHT100_IDTight.Get()==true || *HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60.Get()==true || *HLT_MET105_IsoTrk50.Get()==true) && (*RecoCaloMET.Get() > 170) && (*Flag_allMETFilters.Get() == true) && (Pt[i] > 55.0) && (abs(eta[i]) < 2.4) && (NOPH[i] >= 2) && (FOVH[i] > 0.8) && (NOM[i] >= 10) && ((*isHighPurity.Get())[i] == true) && (Chi2[i]/Ndof[i] < 5.0) && (abs(dZ[i]) < 0.1) && (abs(dXY[i]) < 0.02) && (PFMiniIso_relative[i] < 0.02) && (EoverP[i] < 0.3) && (PtErr[i]/Pt[i] < 1) && (track_genTrackIsoSumPt_dr03[i] < 15) && (PtErr[i]/(Pt[i]*Pt[i]) < 0.0008) && (PtErr[i]/(Pt[i]*Pt[i]) > 0) && (ProbQ_noL1[i] < 0.7) && (ProbQ_noL1[i] > 0) && (Ih_StripOnly[i] > 3.14) ) );
}

bool HSCPSelector::PassPreselection(int hscpIndex){
  if (hscpIndex<0 || hscpIndex>(int)Pt.GetSize()) return false;
  return passPreselection->at(hscpIndex);
}

bool HSCPSelector::PassPreselectionSept8(int hscpIndex){
  if (hscpIndex<0 || hscpIndex>(int)Pt.GetSize()) return false;
  return passPreselectionSept8[hscpIndex];
}




void HSCPSelector::Begin(TTree * /*tree*/)
{
    // The Begin() function is called at the start of the query.
    // When running with PROOF Begin() is only called on the client.
    // The tree argument is deprecated (on PROOF 0 is passed).

    TString option = GetOption();
    TObjArray *tx = option.Tokenize(",");

    // Output file
    std::string ext = ".root";

    std::string ptname( ((TObjString *)(tx->At(1)))->String().Data());
    int ptInt = std::stoi(ptname);

    oFile_ = ((TObjString *)(tx->At(9)))->String().Data();
    oFile_ += "_massCut_";
    oFile_ += ((TObjString *)(tx->At(6)))->String().Data();
    oFile_ += "_pT";
    oFile_ += to_string(ptInt);
    oFile_ += "_";
    oFile_ += ((TObjString *)(tx->At(10)))->String().Data();
    oFile_ += "_Eta2p4";
    oFile_ += ext;

    // Add selections into a vector

    //FILL-SELECTION-VECTOR
selections_.push_back(&HSCPSelector::PassHSCPpresel_SingleMu);
selLabels_.push_back("SingleMu");

selections_.push_back(&HSCPSelector::PassHSCPpresel_METContainingMu);
selLabels_.push_back("METContainingMu");

selections_.push_back(&HSCPSelector::PassHSCPpresel_OnlyMET);
selLabels_.push_back("OnlyMET");

    //selections_.push_back(&HSCPSelector::PassPreselection);
    //selections_.push_back(&HSCPSelector::PassPreselectionSept8);
    //selLabels_.push_back("PassPreselection");
    //selLabels_.push_back("PassPreselectionSept8");

    //https://root-forum.cern.ch/t/proof-session-tselector-how-to-pass-object-to-slaves/25502

    std::cout << std::endl;
    std::cout << "Number of selections: " << selLabels_.size() << std::endl;
    std::cout << "Output file: " << oFile_.c_str() << std::endl;
    std::cout << std::endl;
}



void HSCPSelector::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).



   //CALL METHOD FOR BINNING

   TString option = GetOption();
   //GetOption() func retrieves the options sent in the macro.cc file when calling chain->Process();


   TObjArray *tx = option.Tokenize(",");
   //Tokenize splits the initial TString by the delimiter "," and returns an array of strings 
   //EXAMPLE : TString m = "14,8,3,17" | m.Tokenize(",") |  tx->Print() will display 14
   //								                                                  8
   //								                                                  3
   //								                                                 17


   //OutputTree is a new tree that is produced when reading the TTree from HSCP analyzer, which is a skimmed version to study the different mass recontructions for instance (for quick validation in FPix regions)
   //Printing the content of option

   //Here we read every TString and transform them into strings

   std::string tofTmp( ((TObjString *)(tx->At(0)))->String().Data());
   std::string ptTmp( ((TObjString *)(tx->At(1)))->String().Data());
   std::string etaTmp( ((TObjString *)(tx->At(2)))->String().Data());
   std::string ihTmp( ((TObjString *)(tx->At(3)))->String().Data());
   std::string pTmp( ((TObjString *)(tx->At(4)))->String().Data());
   std::string massTmp( ((TObjString *)(tx->At(5)))->String().Data());
   std::string massCutTmp( ((TObjString *)(tx->At(6)))->String().Data());

   std::string tofCutTmp( ((TObjString *)(tx->At(7)))->String().Data());
   std::string fpixCutTmp( ((TObjString *)(tx->At(8)))->String().Data());

   std::string dataset( ((TObjString *)(tx->At(9)))->String().Data());
   std::string version( ((TObjString *)(tx->At(10)))->String().Data());

   doPreselPlots = true;

   //old TRUE
   FillTree = false; 

   //Finally, transform strings into int for cuts/binning, and make them correspond to header defined variables (binning and pt cut)
   tofcut_ = std::stod(tofTmp);
   ptcut_ = std::stod(ptTmp);
   etabins_ = std::stoi(etaTmp);
   ihbins_ = std::stoi(ihTmp); 
   pbins_ = std::stoi(pTmp);
   massbins_ = std::stoi(massTmp);
   masscut_ = std::stoi(massCutTmp);
   tofbins_ = std::stoi(tofCutTmp);
   fpixbins_ = std::stoi(fpixCutTmp);
   dataset_ = dataset;
   version_ = version; 

   //isSimulation will detect automatically if you run on data or not, and make histograms accordingly
   isSimulation = false;

   //Change here to add debug informations in the log of each worker in /~.proof
   debug = false;
   debugSignal = false;

   if(dataset_ != "Mu2017" && dataset_ != "Mu2018" && dataset_ != "MET_2017_2018"){
       isSimulation = true;
       std::cout <<"This is SIMULATION running" << std::endl;
   }
   else{
       std::cout <<"This is DATA running" << std::endl;
   }

   //Do this to create region based on FPIXELS slices (0.3 - 0.4) (0.4 - 0.5) ectc.. (not needed anymore but for validation slices, it can be used)
   UseFpixel = true;
   //This is for regions based on Gstrip (mass method)
   UseGstrip = true;


   muBadReco = 0;
   muGoodReco = 0;
   muGoodRecoGoodError = 0;
   muGoodRecoButBadError = 0;
   tot = 0;
   PFMu = 0; 
   GlobalMu = 0; 
   passedSel =0;
   for (char c : dataset_){
       if (isdigit(c)){
           numbersMpoint_ += c;
       }
   }
   //Find the mass of the signal studied if you run on simulation
   massPointSig_ = std::stoi(numbersMpoint_);


   //create all objects that will be used by the methods Process    
   std::string firstThreeChars = dataset_.substr(0, 3);

   if(dataset_ == "highmass2017B"){
       K = K_data2017;
       C = C_data2017;
   }

   if(dataset_ == "Mu2017" || dataset_ == "Ele2017"){ 
       K = K_data2017;
       C = C_data2017;
       year = 2017;
   }
   if(dataset_ == "Mu2018"){ 
       K = K_data2018;
       C = C_data2018;
       year = 2018;
   }
   if(dataset_ == "MET_2017_2018"){ 
       K = K_data2018;
       C = C_data2018;
       year = 2018;
   }
   if(dataset_ == "Gluino2400" || dataset_ == "Gluino2000"){ 
       K = K_data2018;
       C = C_data2018;
       year = 2018;
   }
   if(firstThreeChars == "Glu" || firstThreeChars == "pSt" || firstThreeChars == "Sto" || firstThreeChars == "gms"){ 
       K = K_signal2018;
       C = C_signal2018;
   }
   if(dataset_ == "qcd170_300" || dataset_ == "wjets_0j"){
       K = K_bckg2017;
       C = C_bckg2017;
   }

   std::cout << "Dataset is : " << dataset_ << " , mass point then is : " << massPointSig_ <<  " , C = "<< C << " and K = " << K << std::endl;
   std::cout << " Starting SLAVE ---------PT  cut for regions = " << ptcut_ << " tof cut for SR = " << tofcut_ << " , Eta #bin : "<< etabins_ << ", Ih #bins" << ihbins_ << " , P #bins " << pbins_ << " , mass #bins " << massbins_ << " TOF #bins " << tofbins_ <<" , Fpix #bins " << fpixbins_  <<  ", mass cut : " << masscut_ << " , sel labels size : " << selLabels_.size() << std::endl;



   //-------------------------------------
   //Add selections into a vector - to be updated
   //FILL-SELECTION-VECTOR
selections_.push_back(&HSCPSelector::PassHSCPpresel_SingleMu);
selLabels_.push_back("SingleMu");

selections_.push_back(&HSCPSelector::PassHSCPpresel_METContainingMu);
selLabels_.push_back("METContainingMu");

selections_.push_back(&HSCPSelector::PassHSCPpresel_OnlyMET);
selLabels_.push_back("OnlyMET");

   //-------------------------------------
   //selections_.push_back(&HSCPSelector::PassPreselection);
   //selections_.push_back(&HSCPSelector::PassPreselectionSept8);
   //selLabels_.push_back("PassPreselection");
   //selLabels_.push_back("PassPreselectionSept8");
   //Change here the naming of the hists to be compatible with old way 
   
   //-------------------------------------
   //create RegionMassPlot for all selection
   //-------------------------------------
   for(unsigned int i=0;i<selLabels_.size();i++){
      //The binning has to be changed and to become configurable 
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
          
          RegionMassPlot regAll(label_FpixAll.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 

          RegionMassPlot regA_3f4(label_FpixA_3f4.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C);
          RegionMassPlot regA_3f6(label_FpixA_3f6.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regA_3f8(label_FpixA_3f8.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regA_3f9(label_FpixA_3f9.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regA_4f5(label_FpixA_4f5.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regA_5f6(label_FpixA_5f6.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regA_6f7(label_FpixA_6f7.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C);
          RegionMassPlot regA_6f9(label_FpixA_6f9.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C);
          RegionMassPlot regA_7f8(label_FpixA_7f8.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C);
          RegionMassPlot regA_8f9(label_FpixA_8f9.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regA_9f10(label_FpixA_9f10.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regA_99f10(label_FpixA_99f10.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regA_999f10(label_FpixA_999f10.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 

          RegionMassPlot regB_3f4(label_FpixB_3f4.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regB_3f6(label_FpixB_3f6.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regB_3f8(label_FpixB_3f8.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regB_3f9(label_FpixB_3f9.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regB_4f5(label_FpixB_4f5.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regB_5f6(label_FpixB_5f6.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regB_6f7(label_FpixB_6f7.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regB_6f9(label_FpixB_6f9.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regB_7f8(label_FpixB_7f8.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C);     
          RegionMassPlot regB_8f9(label_FpixB_8f9.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regB_8f10(label_FpixB_8f10.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regB_9f10(label_FpixB_9f10.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regB_99f10(label_FpixB_99f10.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regB_999f10(label_FpixB_999f10.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 

          RegionMassPlot regC_3f4(label_FpixC_3f4.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regC_3f6(label_FpixC_3f6.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regC_3f8(label_FpixC_3f8.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regC_3f9(label_FpixC_3f9.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regC_4f5(label_FpixC_4f5.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regC_5f6(label_FpixC_5f6.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regC_6f7(label_FpixC_6f7.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regC_6f9(label_FpixC_6f9.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regC_7f8(label_FpixC_7f8.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regC_8f9(label_FpixC_8f9.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 

          RegionMassPlot regD_3f4(label_FpixD_3f4.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regD_3f8(label_FpixD_3f8.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regD_4f5(label_FpixD_4f5.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regD_5f6(label_FpixD_5f6.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regD_6f7(label_FpixD_6f7.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regD_6f9(label_FpixD_6f9.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regD_7f8(label_FpixD_7f8.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C);     
          RegionMassPlot regD_8f9(label_FpixD_8f9.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regD_8f10(label_FpixD_8f10.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regD_9f10(label_FpixD_9f10.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regD_99f10(label_FpixD_99f10.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
          RegionMassPlot regD_999f10(label_FpixD_999f10.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C); 
       

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

      
      if(UseGstrip){    
          //Definition of regions A with all quantiles and different names
          std::string labelA_50ias = rA_med + "_" + selLabels_[i];
          RegionMassPlot regA_ias50(labelA_50ias.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C);
          std::string labelA_80ias = rA_80 + "_" + selLabels_[i];
          RegionMassPlot regA_ias80(labelA_80ias.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C);
          std::string labelA_90ias = rA_90 + "_" + selLabels_[i];
          RegionMassPlot regA_ias90(labelA_90ias.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C);
    
          //Definition of regions B with all quantiles and different names
          std::string labelB_50ias60 = rB_50 + "_" + selLabels_[i];
          RegionMassPlot regB_50ias60(labelB_50ias60.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C);
          std::string labelB_50ias90 = rB_50_90 + "_" + selLabels_[i];
          RegionMassPlot regB_50ias90(labelB_50ias90.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C);
          std::string labelB_50ias99 = rB_50_99 + "_" + selLabels_[i];
          RegionMassPlot regB_50ias99(labelB_50ias99.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C);
          std::string labelB_50ias999 = rB_50_999 + "_" + selLabels_[i];
          RegionMassPlot regB_50ias999(labelB_50ias999.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C);
          std::string labelB_50ias100 = rB_50_100 + "_" + selLabels_[i];
          RegionMassPlot regB_50ias100(labelB_50ias100.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C);
          std::string labelB_60ias70 = rB_60 + "_" + selLabels_[i];
          RegionMassPlot regB_60ias70(labelB_60ias70.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C);
          std::string labelB_70ias80 = rB_70 + "_" + selLabels_[i];
          RegionMassPlot regB_70ias80(labelB_70ias80.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C);
          std::string labelB_80ias90 = rB_80 + "_" + selLabels_[i];
          RegionMassPlot regB_80ias90(labelB_80ias90.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C);
          std::string labelB_90ias100 = rB_90_100 + "_" + selLabels_[i];
          RegionMassPlot regB_90ias100(labelB_90ias100.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C);
          std::string labelB_99ias100 = rB_99_100 + "_" + selLabels_[i];
          RegionMassPlot regB_99ias100(labelB_99ias100.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C);
          std::string labelB_999ias100 = rB_999_100 + "_" + selLabels_[i];
          RegionMassPlot regB_999ias100(labelB_999ias100.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C);

          //Definition of regions C with all quantiles and different names
          std::string labelC_50ias = rC_med + "_" + selLabels_[i];
          RegionMassPlot regC_ias50(labelC_50ias.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C);
          std::string labelC_80ias = rC_80 + "_" + selLabels_[i];
          RegionMassPlot regC_ias80(labelC_80ias.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C);
          std::string labelC_90ias = rC_90 + "_" + selLabels_[i];
          RegionMassPlot regC_ias90(labelC_90ias.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C);

          //Definition of regions D with all quantiles and different names
          std::string labelD_50ias60 = rD_50 + "_" + selLabels_[i];
          RegionMassPlot regD_50ias60(labelD_50ias60.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C);
          std::string labelD_50ias90 = rD_50_90 + "_" + selLabels_[i];
          RegionMassPlot regD_50ias90(labelD_50ias90.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C);
          std::string labelD_50ias99 = rD_50_99 + "_" + selLabels_[i];
          RegionMassPlot regD_50ias99(labelD_50ias99.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C);
          std::string labelD_50ias999 = rD_50_999 + "_" + selLabels_[i];
          RegionMassPlot regD_50ias999(labelD_50ias999.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C);
          std::string labelD_60ias70 = rD_60 + "_" + selLabels_[i];
          RegionMassPlot regD_60ias70(labelD_60ias70.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C);
          std::string labelD_70ias80 = rD_70 + "_" + selLabels_[i];
          RegionMassPlot regD_70ias80(labelD_70ias80.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C);
          std::string labelD_80ias90 = rD_80 + "_" + selLabels_[i];
          RegionMassPlot regD_80ias90(labelD_80ias90.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C);
          std::string labelD_90ias100 = rD_90_100 + "_" + selLabels_[i];
          RegionMassPlot regD_90ias100(labelD_90ias100.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C);
          std::string labelD_99ias100 = rD_99_100 + "_" + selLabels_[i];
          RegionMassPlot regD_99ias100(labelD_99ias100.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C);
          std::string labelD_999ias100 = rD_999_100 + "_" + selLabels_[i];
          RegionMassPlot regD_999ias100(labelD_999ias100.c_str(),etabins_,ihbins_,pbins_,massbins_,tofbins_,fpixbins_, C);

    
          vmrp_regionA_ias50.push_back(std::move(regA_ias50));
          vmrp_regionA_ias80.push_back(std::move(regA_ias80));
          vmrp_regionA_ias90.push_back(std::move(regA_ias90));
    
          vmrp_regionB_50ias60.push_back(std::move(regB_50ias60));
          vmrp_regionB_50ias90.push_back(std::move(regB_50ias90));
          vmrp_regionB_50ias99.push_back(std::move(regB_50ias99));
          vmrp_regionB_50ias999.push_back(std::move(regB_50ias999));
          vmrp_regionB_50ias100.push_back(std::move(regB_50ias100));
          vmrp_regionB_60ias70.push_back(std::move(regB_60ias70));
          vmrp_regionB_70ias80.push_back(std::move(regB_70ias80));
          vmrp_regionB_80ias90.push_back(std::move(regB_80ias90));
          vmrp_regionB_90ias100.push_back(std::move(regB_90ias100));
          vmrp_regionB_99ias100.push_back(std::move(regB_99ias100));
          vmrp_regionB_999ias100.push_back(std::move(regB_999ias100));

          vmrp_regionC_ias50.push_back(std::move(regC_ias50));
          vmrp_regionC_ias80.push_back(std::move(regC_ias80));
          vmrp_regionC_ias90.push_back(std::move(regC_ias90));

          vmrp_regionD_50ias60.push_back(std::move(regD_50ias60));
          vmrp_regionD_50ias90.push_back(std::move(regD_50ias90));
          vmrp_regionD_50ias99.push_back(std::move(regD_50ias99));
          vmrp_regionD_50ias999.push_back(std::move(regD_50ias999));
          vmrp_regionD_60ias70.push_back(std::move(regD_60ias70));
          vmrp_regionD_70ias80.push_back(std::move(regD_70ias80));
          vmrp_regionD_80ias90.push_back(std::move(regD_80ias90));
          vmrp_regionD_90ias100.push_back(std::move(regD_90ias100));
          vmrp_regionD_99ias100.push_back(std::move(regD_99ias100));
          vmrp_regionD_999ias100.push_back(std::move(regD_999ias100));
    
      }
        

      CPlots plots;

      plots.AddHisto1D(selLabels_[i]+"_TrigInfo", 5, 0, 5);
      plots.AddHisto1D(selLabels_[i]+"_p",40,0,4000);
      plots.AddHisto1D(selLabels_[i]+"_eta",48,-2.4,+2.4);
      plots.AddHisto1D(selLabels_[i]+"_cand",10,0,10);
      plots.AddHisto2D(selLabels_[i]+"_Fpix_vs_Gstrip",50,0,1,50,0,1);

      plots.AddHisto1D(selLabels_[i]+"_Cutflow", 20, 0, 20);


      //Need to add plots here
      //ADD-CPLOTS-HERE

      vcp.push_back(std::move(plots));
      
   }
   std::cout << "Got ouf of loop on selections_" <<std::endl;
   //fOutput->Add(fout);
}

Bool_t HSCPSelector::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // When processing keyed objects with PROOF, the object is already loaded
   // and is available via the fObject pointer.
   //
   // This function should contain the \"body\" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.
   //std::cout << "Entering Process" << std::endl; 
   
   fReader.SetLocalEntry(entry);
   //----------------------------------
   //Loop over all HSCP candidates
   //----------------------------------
   
   //Use the size of any array such as Pt
   
   //Store the index (in iCand) of the most ionizing candidate (maxIh) 
   //passing the preselection
   //int iCand = -1; // index on the selected candidate per event

   vector<int> iCand(selLabels_.size(),-1);
   vector<float> maxIh(selLabels_.size(),-1);
   vector<bool> foundOnePF(selLabels_.size(),false); 
   vector<bool> foundOneGlobal(selLabels_.size(),false); 
   vector<bool> passedThisSel(selLabels_.size(),false); 


   for(unsigned int i=0;i<Pt.GetSize();i++){
      
            //TAKE MOST IONIZING CANDIDATE
        for(unsigned int s=0;s<selections_.size();s++){
            bool (HSCPSelector::*ptr)(int);
            ptr = selections_[s];
            if((this->*ptr)(i)){
                if(Ih_StripOnly[i]>maxIh[s]){
                    maxIh[s]=Ih_StripOnly[i];
                    iCand[s]=i;
                }
            }
        }


        // CUTFLOW
        for(unsigned int s=0;s<selections_.size();s++){ 
            if (selLabels_[s] == "OnlyMET" || selLabels_[s] == "METContaningMu"){
                
                std::string cutflowName = selLabels_[s] + "_Cutflow";
                bool trigger = true;
                
                if (selLabels_[s] == "OnlyMET") trigger = (*HLT_Mu50.Get() == false) && (
                    *HLT_PFMET120_PFMHT120_IDTight.Get() ||
                    *HLT_PFHT500_PFMET100_PFMHT100_IDTight.Get() ||
                    *HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60.Get() ||
                    *HLT_MET105_IsoTrk50.Get());
                else trigger = *HLT_PFMET120_PFMHT120_IDTight.Get() ||
                    *HLT_PFHT500_PFMET100_PFMHT100_IDTight.Get() ||
                    *HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60.Get() ||
                    *HLT_MET105_IsoTrk50.Get();
                

                vcp[s].FillHisto1D(cutflowName, 0.5); // All events

                while (true) {
                    if (!trigger) break;
                    vcp[s].FillHisto1D(cutflowName, 1.5);

                    if (!(*Flag_allMETFilters.Get())) break;
                    vcp[s].FillHisto1D(cutflowName, 2.5);

                    if (!(*RecoCaloMET.Get() > 170)) break;
                    vcp[s].FillHisto1D(cutflowName, 3.5);

                    if (!(Pt[i] > 55.0)) break;
                    vcp[s].FillHisto1D(cutflowName, 4.5);

                    if (!(fabs(eta[i]) < 2.4)) break;
                    vcp[s].FillHisto1D(cutflowName, 5.5);

                    if (!(NOPH[i] >= 2)) break;
                    vcp[s].FillHisto1D(cutflowName, 6.5);

                    if (!(FOVH[i] > 0.8)) break;
                    vcp[s].FillHisto1D(cutflowName, 7.5);

                    if (!(NOM[i] >= 10)) break;
                    vcp[s].FillHisto1D(cutflowName, 8.5);

                    if (!(*isHighPurity.Get())[i]) break;
                    vcp[s].FillHisto1D(cutflowName, 9.5);

                    if (!(Chi2[i]/Ndof[i] < 5.0)) break;
                    vcp[s].FillHisto1D(cutflowName, 10.5);

                    if (!(fabs(dZ[i]) < 0.1)) break;
                    vcp[s].FillHisto1D(cutflowName, 11.5);

                    if (!(fabs(dXY[i]) < 0.02)) break;
                    vcp[s].FillHisto1D(cutflowName, 12.5);

                    if (!(PFMiniIso_relative[i] < 0.02)) break;
                    vcp[s].FillHisto1D(cutflowName, 13.5);

                    if (!(track_genTrackIsoSumPt_dr03[i] < 15)) break;
                    vcp[s].FillHisto1D(cutflowName, 14.5);

                    if (!(EoverP[i] < 0.3)) break;
                    vcp[s].FillHisto1D(cutflowName, 15.5);

                    double relPtErr2 = PtErr[i] / (Pt[i] * Pt[i]);
                    if (!(relPtErr2 > 0 && relPtErr2 < 0.0008)) break;
                    vcp[s].FillHisto1D(cutflowName, 16.5);

                    if (!(ProbQ_noL1[i] > 0 && ProbQ_noL1[i] < 0.7)) break;
                    vcp[s].FillHisto1D(cutflowName, 17.5);
                    if (!(PtErr[i]/Pt[i] < 1)) break;
                    vcp[s].FillHisto1D(cutflowName, 18.5);

                    if (!(Ih_StripOnly[i] > 3.14)) break;
                    vcp[s].FillHisto1D(cutflowName, 19.5);

                    break;
                }
            }
        }

            //TAKE MOST IONIZING PF AND GLOBAL MUON CANDIDATE
        /*
        for(unsigned int s=0;s<selections_.size();s++){
            bool (HSCPSelector::*ptr)(int);
        ptr = selections_[s];
        if((this->*ptr)(i)){
            bool hscpPFmuon = (*isMuon.Get())[i];
            bool hscpGlobalMuon = (*isGlobalMuon.Get())[i];
            if(hscpPFmuon) foundOnePF[s] = true;
            if(hscpGlobalMuon) foundOneGlobal[s] = true;
            passedThisSel[s] = true;
        vcp[s].FillHisto1D(selLabels_[s]+"_hIh",Ih_StripOnly[i]);
        if(Ih_StripOnly[i]>maxIh[s] && ((*isMuon.Get())[i]) && ((*isGlobalMuon.Get())[i])){
                maxIh[s]=Ih_StripOnly[i];
                iCand[s]=i;
            }
            }
        }
        */
   }

   tot += 1;
   if(passedThisSel[2]) passedSel += 1;
   if(foundOnePF[2]) PFMu += 1;
   if(foundOneGlobal[2]) GlobalMu += 1;
   //End of loop over all HSCP candidates

   //for(unsigned int i=0;i<Pt.GetSize();i++){    // Every candidate

    for(unsigned int s=0;s<selections_.size();s++){ 
    //bool (HSCPSelector::*ptr)(int);
    //ptr = selections_[s];
    //if((this->*ptr)(i)){

        int i = iCand[s];     // most ionising candidate
	    if (i<0) continue;

        //FILL-CPLOTS-HERE
        if (selections_[s]){
            vcp[s].FillHisto1D(selLabels_[s]+"_TrigInfo", *Trig.Get());
            vcp[s].FillHisto1D(selLabels_[s]+"_p",Pt[i]*cosh(eta[i]));
            vcp[s].FillHisto1D(selLabels_[s]+"_eta",eta[i]);
            vcp[s].FillHisto1D(selLabels_[s]+"_cand",HSCP_cand[i]);
            vcp[s].FillHisto2D(selLabels_[s]+"_Fpix_vs_Gstrip", float(1.0 - ProbQ_noL1[i]), Ias_StripOnly[i]);
        }


        double Ias = Ias_StripOnly[i];
        float P = 10000./(Pt[i]*cosh(eta[i]));
        float Ih = Ih_StripOnly[i];
        float Fpix = float(1.0 - ProbQ_noL1[i]);
        float newWeight = *Weight;
        float pt = Pt[i];
       
        bool HLTmu = *HLT_Mu50.Get();

        double massDedx = GetMass(pt*cosh(eta[i]),Ih_StripOnly[i],K,C);
        double massDedxInit = GetMass(pt*cosh(eta[i]),Ih_StripOnly[i],K,C);
        double massBeta = GetMassBeta(pt*cosh(eta[i]),(1./TOF[i]));
        double massAtlas = -1;
        float massForRegions = massDedx; 
 

        //USING MUONS 

        /*if(doPreselPlots && selLabels_[s] == "allInclusive"){
            bool passedCutsArray[2];
            std::fill(std::begin(passedCutsArray), std::end(passedCutsArray),false);
            passedCutsArray[0]  = HLTmu;


            //passedCutsArray[1]  = (NOPH[i] >= 2) && (FOVH[i] > 0.8) && (NOM[i] >= 10) && ((*isHighPurity.Get())[i]) && ((Chi2[i]/Ndof[i]) < 5.0) && (abs(dZ[i]) < 0.1) && (abs(dXY[i]) < 0.02) && (PFMiniIso_relative[i] < 0.02) && (EoverP[i] < 0.3) && ((PtErr[i]/(Pt[i]*Pt[i]))<0.0008) && ((PtErr[i]/(Pt[i]))<1) && ((PtErr[i]/(Pt[i]*Pt[i]))>0) && (track_genTrackAbsIsoSumPtFix[i] < 15.0) && (Ih_StripOnly[i]>3.14) && (abs(eta[i]) < 1) && Pt[i] > 50 && (ProbQ_noL1[i] < 0.7) && (ProbQ_noL1[i] > 0.0);
            passedCutsArray[1]  = (NOPH[i] >= 2) && (FOVH[i] > 0.8) && (NOM[i] >= 10) && ((*isHighPurity.Get())[i]) && ((Chi2[i]/Ndof[i]) < 5.0) && (abs(dZ[i]) < 0.1) && (abs(dXY[i]) < 0.02) && (PFMiniIso_relative[i] < 0.02) && (EoverP[i] < 0.3) && ((PtErr[i]/(Pt[i]*Pt[i]))<0.0008) && ((PtErr[i]/(Pt[i]))<1) && ((PtErr[i]/(Pt[i]*Pt[i]))>0) && (track_genTrackAbsIsoSumPtFix[i] < 15.0) && (Ih_StripOnly[i]>C) && (abs(eta[i]) < 1.0) && Pt[i] > 70 && Ias > quan999 && (ProbQ_noL1[i] < 0.7) && (ProbQ_noL1[i] > 0.0);

            for (size_t k=0;k<sizeof(passedCutsArray);k++) {
                bool allCutsPassedSoFar = true;
                for (size_t j=0;j<=k;j++) {
                    if(!passedCutsArray[j]) {
                        allCutsPassedSoFar = false;
                        break;
                    }
                }
                if (allCutsPassedSoFar) {
                   vcp[s].FillHisto1D(selLabels_[s]+"_hN1_CutFlow",k+1);  
                }
            }
        }*/



        if(UseFpixel){           
            //vmrp_regionFpix_all[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);

           if(pt <= ptcut_){
               if( (Fpix > fpix3) && (Fpix <= fpix4) ) vmrp_regionA_3f4[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix3) && (Fpix <= fpix6) ) vmrp_regionA_3f6[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix3) && (Fpix <= fpix8) ) vmrp_regionA_3f8[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix3) && (Fpix <= fpix9) ) vmrp_regionA_3f9[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix4) && (Fpix <= fpix5) ) vmrp_regionA_4f5[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix5) && (Fpix <= fpix6) ) vmrp_regionA_5f6[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix6) && (Fpix <= fpix7) ) vmrp_regionA_6f7[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix6) && (Fpix <= fpix9) ) vmrp_regionA_6f9[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix7) && (Fpix <= fpix8) ) vmrp_regionA_7f8[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix8) && (Fpix <= fpix9) ) vmrp_regionA_8f9[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix9) && (Fpix <= fpix10) ) vmrp_regionA_9f10[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix99) && (Fpix <= fpix10) ) vmrp_regionA_99f10[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix999) && (Fpix <= fpix10) ) vmrp_regionA_999f10[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               
               if( (Fpix > fpix3) && (Fpix <= fpix4) ) vmrp_regionB_3f4[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix3) && (Fpix <= fpix6) ) vmrp_regionB_3f6[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix3) && (Fpix <= fpix8) ) vmrp_regionB_3f8[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix3) && (Fpix <= fpix9) ) vmrp_regionB_3f9[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix4) && (Fpix <= fpix5) ) vmrp_regionB_4f5[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix5) && (Fpix <= fpix6) ) vmrp_regionB_5f6[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix6) && (Fpix <= fpix7) ) vmrp_regionB_6f7[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix6) && (Fpix <= fpix9) ) vmrp_regionB_6f9[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix7) && (Fpix <= fpix8) ) vmrp_regionB_7f8[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix8) && (Fpix <= fpix9) ) vmrp_regionB_8f9[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix8) && (Fpix <= fpix10) ) vmrp_regionB_8f10[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix9) && (Fpix <= fpix10) ) vmrp_regionB_9f10[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix99) && (Fpix <= fpix10) ) vmrp_regionB_99f10[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix999) && (Fpix <= fpix10) ) vmrp_regionB_999f10[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
           }
           else{
               if( (Fpix > fpix3) && (Fpix <= fpix4) ) vmrp_regionC_3f4[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix3) && (Fpix <= fpix6) ) vmrp_regionC_3f6[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix3) && (Fpix <= fpix8) ) vmrp_regionC_3f8[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix3) && (Fpix <= fpix9) ) vmrp_regionC_3f9[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix4) && (Fpix <= fpix5) ) vmrp_regionC_4f5[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix5) && (Fpix <= fpix6) ) vmrp_regionC_5f6[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix6) && (Fpix <= fpix7) ) vmrp_regionC_6f7[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix6) && (Fpix <= fpix9) ) vmrp_regionC_6f9[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix7) && (Fpix <= fpix8) ) vmrp_regionC_7f8[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix8) && (Fpix <= fpix9) ) vmrp_regionC_8f9[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               
               if( (Fpix > fpix3) && (Fpix <= fpix4) ) vmrp_regionD_3f4[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix3) && (Fpix <= fpix8) ) vmrp_regionD_3f8[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix4) && (Fpix <= fpix5) ) vmrp_regionD_4f5[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix5) && (Fpix <= fpix6) ) vmrp_regionD_5f6[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix6) && (Fpix <= fpix7) ) vmrp_regionD_6f7[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix6) && (Fpix <= fpix9) ) vmrp_regionD_6f9[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix7) && (Fpix <= fpix8) ) vmrp_regionD_7f8[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix8) && (Fpix <= fpix9) )
               {
                    vmrp_regionD_8f9[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);

                        // write in a .txt file the following information:
                        // mass pT eta phi Ih Ias Fpix NOPH FOVH NOM Chi2oNDF dZ dXY PFMiniIso_relative EoverP PtErr[i]/Pt[i] PtErr[i]/(Pt[i]*Pt[i]) track_genTrackIsoSumPt_dr03
                    
                    /*if (massForRegions > 2000)
                    {
                        OutputTuples << massForRegions << " " << pt << " " << eta[i] << " " << phi[i] << " " << Ih << " " << Ias << " " << Fpix << " " << NOPH[i] << " " << FOVH[i] << " " << NOM[i] << " " << Chi2[i]/Ndof[i] << " " << dZ[i] << " " << dXY[i] << " " << PFMiniIso_relative[i] << " " << EoverP[i] << " " << PtErr[i]/(Pt[i]) << " " << PtErr[i]/(Pt[i]*Pt[i]) << " " << track_genTrackIsoSumPt_dr03[i] << "\n";
                    }*/
               }
               if( (Fpix > fpix8) && (Fpix <= fpix10) ) vmrp_regionD_8f10[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix9) && (Fpix <= fpix10) ) vmrp_regionD_9f10[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix99) && (Fpix <= fpix10) ) vmrp_regionD_99f10[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
               if( (Fpix > fpix999) && (Fpix <= fpix10) ) vmrp_regionD_999f10[s].fill(eta[i],NOM[i],P,pt,PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massForRegions,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
            }
        }
     
        if(UseGstrip){

            if(Pt[i] <= ptcut_){               
                if(Ias < quan50) vmrp_regionA_ias50[s].fill(eta[i],NOM[i],P,Pt[i],PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massDedx,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
                if(Ias < quan80) vmrp_regionA_ias80[s].fill(eta[i],NOM[i],P,Pt[i],PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massDedx,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
                if(Ias < quan90) vmrp_regionA_ias90[s].fill(eta[i],NOM[i],P,Pt[i],PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massDedx,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
    
                if(Ias >= quan50 && Ias < quan60) vmrp_regionB_50ias60[s].fill(eta[i],NOM[i],P,Pt[i],PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massDedx,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
                if(Ias >= quan50 && Ias < quan90) vmrp_regionB_50ias90[s].fill(eta[i],NOM[i],P,Pt[i],PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massDedx,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
                if(Ias >= quan50 && Ias < quan99) vmrp_regionB_50ias99[s].fill(eta[i],NOM[i],P,Pt[i],PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massDedx,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
                if(Ias >= quan50 && Ias < quan999) vmrp_regionB_50ias999[s].fill(eta[i],NOM[i],P,Pt[i],PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massDedx,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
                if(Ias >= quan50) vmrp_regionB_50ias100[s].fill(eta[i],NOM[i],P,Pt[i],PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massDedx,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
                if(Ias >= quan60 && Ias < quan70) vmrp_regionB_60ias70[s].fill(eta[i],NOM[i],P,Pt[i],PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massDedx,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
                if(Ias >= quan70 && Ias < quan80) vmrp_regionB_70ias80[s].fill(eta[i],NOM[i],P,Pt[i],PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massDedx,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
                if(Ias >= quan80 && Ias < quan90) vmrp_regionB_80ias90[s].fill(eta[i],NOM[i],P,Pt[i],PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massDedx,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
                if(Ias >= quan90) vmrp_regionB_90ias100[s].fill(eta[i],NOM[i],P,Pt[i],PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massDedx,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
                if(Ias >= quan99) vmrp_regionB_99ias100[s].fill(eta[i],NOM[i],P,Pt[i],PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massDedx,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
                if(Ias >= quan999) vmrp_regionB_999ias100[s].fill(eta[i],NOM[i],P,Pt[i],PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massDedx,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
            }
            else{
                
                if(Ias < quan50) vmrp_regionC_ias50[s].fill(eta[i],NOM[i],P,Pt[i],PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massDedx,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
                if(Ias < quan80) vmrp_regionC_ias80[s].fill(eta[i],NOM[i],P,Pt[i],PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massDedx,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
                if(Ias < quan90) vmrp_regionC_ias90[s].fill(eta[i],NOM[i],P,Pt[i],PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massDedx,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
    
                if(Ias >= quan50 && Ias < quan60) vmrp_regionD_50ias60[s].fill(eta[i],NOM[i],P,Pt[i],PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massDedx,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
                if(Ias >= quan50 && Ias < quan90) vmrp_regionD_50ias90[s].fill(eta[i],NOM[i],P,Pt[i],PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massDedx,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
                if(Ias >= quan50 && Ias < quan99) vmrp_regionD_50ias99[s].fill(eta[i],NOM[i],P,Pt[i],PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massDedx,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
                if(Ias >= quan50 && Ias < quan999) vmrp_regionD_50ias999[s].fill(eta[i],NOM[i],P,Pt[i],PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massDedx,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
                if(Ias >= quan60 && Ias < quan70) vmrp_regionD_60ias70[s].fill(eta[i],NOM[i],P,Pt[i],PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massDedx,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
                if(Ias >= quan70 && Ias < quan80) vmrp_regionD_70ias80[s].fill(eta[i],NOM[i],P,Pt[i],PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massDedx,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
                if(Ias >= quan80 && Ias < quan90) vmrp_regionD_80ias90[s].fill(eta[i],NOM[i],P,Pt[i],PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massDedx,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
                if(Ias >= quan90 ) vmrp_regionD_90ias100[s].fill(eta[i],NOM[i],P,Pt[i],PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massDedx,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
                if(Ias >= quan99 ) vmrp_regionD_99ias100[s].fill(eta[i],NOM[i],P,Pt[i],PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massDedx,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
                if(Ias >= quan999 ) vmrp_regionD_999ias100[s].fill(eta[i],NOM[i],P,Pt[i],PtErr[i],Ih_StripOnly[i],Ias_StripOnly[i],-1,massDedx,TOF[i],*nofVtx.Get(),Fpix,newWeight,1);
            }
            
        }  
        
        
        //TEST NEW OUTPUT TTREE
        float massDedxMuonInit = -1;
        float massMuonBeta = -1;

        float massCombinedWeighted = -1;
        float massCombinedMuonWeighted = -1;
        float chi2CombMuonNoSquare = -1;


        TreeInverseBeta=TOF[i];
        TreeIh = Ih_StripOnly[i];

        TreeMassIh = massDedxInit; 
        TreeMuonMassIh = massDedxMuonInit;

        TreeMassBeta = massBeta;
        TreeMuonMassBeta = massMuonBeta;

        TreeMassCombined = massCombinedWeighted;
        TreeMuonMassCombined = massCombinedMuonWeighted;

        TreeMuonMassAtlas = massAtlas;
        float hscpMuonPt = -1;
        TreePt = hscpMuonPt;
        TreeFpix = Fpix;
        TreeChi2 = chi2CombMuonNoSquare;

        if(selLabels_[s] == "testIhPt" && FillTree){        
            outputTree->Fill();
        }
    }
   //} 
   //}

   return kTRUE;
}

void HSCPSelector::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.
   // All plots should be added to the list fOutput to be later on merged

   //Add plots for all MassRegionPlots
   std::cout << "There was " << befPreSel << " events passing empty preselection" << std::endl;
   std::cout << "There was " << preselTestIh << " events passing testIhPt preselection" << std::endl;
   cout << "Total number of events  = " << tot << std::endl;
   cout <<"Total events passing preselection testIhPt = " << passedSel << std::endl;
   cout <<"Number of events where one of the HSCP passing presel testIhPt is a PF muon = " << PFMu << std::endl;
   cout <<"Number of events where one of the HSCP passing presel testIhPt is a Global muon = " << GlobalMu << std::endl;
   cout << "There was " << muBadReco << " events where candidate being PF muon is not associated to a muon in the event (weird)" << std::endl;
   cout << "There was " << muGoodReco << "events where we found a muon linked to the highest muon passing presel (as expected)" << std::endl;

   //cout << "    Out of these " << muGoodReco << "events, " << muGoodRecoGoodError << " Had a sigmaPt/pt < 0.125, and " << muGoodRecoButBadError << " had one above 0.125, which means the efficiency of sigma pt/pt for muon passing presel is " << (muGoodRecoGoodError - muGoodRecoButBadError)/muGoodRecoGoodError << std::endl;

   if(FillTree) fOutput->Add(outputTree);

   for(auto obj: vcp) obj.AddToList(fOutput);
   
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

   if(UseGstrip){ 
       //for(auto obj: vmrp_region_all) obj.addToList(fOutput);

       for(auto obj: vmrp_regionA_ias50) obj.addToList(fOutput);
       for(auto obj: vmrp_regionA_ias80) obj.addToList(fOutput);
       for(auto obj: vmrp_regionA_ias90) obj.addToList(fOutput);
    
       for(auto obj: vmrp_regionB_50ias60) obj.addToList(fOutput);
       for(auto obj: vmrp_regionB_50ias90) obj.addToList(fOutput);
       for(auto obj: vmrp_regionB_50ias99) obj.addToList(fOutput);
       for(auto obj: vmrp_regionB_50ias999) obj.addToList(fOutput);
       for(auto obj: vmrp_regionB_60ias70) obj.addToList(fOutput);
       for(auto obj: vmrp_regionB_70ias80) obj.addToList(fOutput);
       for(auto obj: vmrp_regionB_80ias90) obj.addToList(fOutput);
       for(auto obj: vmrp_regionB_90ias100) obj.addToList(fOutput);
       for(auto obj: vmrp_regionB_99ias100) obj.addToList(fOutput);
       for(auto obj: vmrp_regionB_999ias100) obj.addToList(fOutput);

       for(auto obj: vmrp_regionC_ias50) obj.addToList(fOutput);
       for(auto obj: vmrp_regionC_ias80) obj.addToList(fOutput);
       for(auto obj: vmrp_regionC_ias90) obj.addToList(fOutput);

       for(auto obj: vmrp_regionD_50ias60) obj.addToList(fOutput);
       for(auto obj: vmrp_regionD_50ias90) obj.addToList(fOutput);
       for(auto obj: vmrp_regionD_50ias99) obj.addToList(fOutput);
       for(auto obj: vmrp_regionD_50ias999) obj.addToList(fOutput);
       for(auto obj: vmrp_regionD_60ias70) obj.addToList(fOutput);
       for(auto obj: vmrp_regionD_70ias80) obj.addToList(fOutput);
       for(auto obj: vmrp_regionD_80ias90) obj.addToList(fOutput);
       for(auto obj: vmrp_regionD_90ias100) obj.addToList(fOutput);
       for(auto obj: vmrp_regionD_99ias100) obj.addToList(fOutput);
       for(auto obj: vmrp_regionD_999ias100) obj.addToList(fOutput);
   }

}

void HSCPSelector::Terminate()
{
    // The Terminate() function is the last function to be called during
    // a query. It always runs on the client, it can be used to present
    // the results graphically or save the results to file.
    // calling Print on fOutput create an error - don't do that !

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
