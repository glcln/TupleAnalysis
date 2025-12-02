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

bool HSCPSelector::PassHSCPpresel_OnlyMET(int i){
   if (i<0 || i>(int)Pt.GetSize()) {
      cout << i << endl;
      return false;
   }
   return (( (Flag_allMETFilters[0] == true) && (Pt[i] > 55.0) && (abs(Eta[i]) < 2.4) && (NbPixelHit_noL1[i] >= 2) && (FracOfValidHit[i] > 0.8) && (NOM_noL1[i] >= 10) && (isHighPurityTrack[i] == true) && (normChi2[i] < 5.0) && (abs(dz[i]) < 0.1) && (abs(dxy[i]) < 0.02) && (miniRelIsoAll[i] < 0.02) && (EoP[i] < 0.3) && (IsoSumPt_dr03[i] < 15) && (ptOverptErrptErr[i] < 0.0008) && (Fpix[i] > 0.3) ));
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

selections_.push_back(&HSCPSelector::PassHSCPpresel_OnlyMET);
selLabels_.push_back("OnlyMET");


    std::cout << std::endl;
    std::cout << "Number of selections: " << selLabels_.size() << std::endl;
    std::cout << "Output file: " << oFile_.c_str() << std::endl;
    std::cout << std::endl;
}



void HSCPSelector::SlaveBegin(TTree *tree)
{
    TString option = GetOption();
    TObjArray *tx = option.Tokenize(",");


    //-------------------------------------
    //Add selections into a vector - to be updated
    //FILL-SELECTION-VECTOR
selections_.push_back(&HSCPSelector::PassHSCPpresel_NoCriteria);
selLabels_.push_back("NoCriteria");

selections_.push_back(&HSCPSelector::PassHSCPpresel_OnlyMET);
selLabels_.push_back("OnlyMET");

    //-------------------------------------

    //-------------------------------------
    //create RegionMassPlot for all selection
    //-------------------------------------
    for(unsigned int i=0;i<selLabels_.size();i++)
    {
        CPlots plots;

        plots.AddHisto1D(selLabels_[i]+"_massGEN", 200, 0, 4000);
        plots.AddHisto1D(selLabels_[i]+"_massKC", 200, 0, 4000);
        plots.AddHisto1D(selLabels_[i]+"_massATLAS", 200, 0, 4000);

        vcp.push_back(std::move(plots));
    }

    std::cout << "Got ouf of loop on selections_" <<std::endl;
}

Bool_t HSCPSelector::Process(Long64_t entry)
{
    fReader.SetEntry(entry);

    //----------------------------------
    //Loop over all HSCP candidates
    //----------------------------------
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
        i++;
    } //End of loop over all HSCP candidates


    // Loop over the gen candidates:
    for (unsigned int m=0; m<GenPart_mass.GetSize(); m++){

        for(unsigned int s=0; s<selections_.size(); s++){
            bool (HSCPSelector::*ptr)(int);
            ptr = selections_[s];
            if((this->*ptr)(i)){
                if (fabs(GenPart_pdgId[km]) > 100000) plots.FillHisto1D(selLabels_[s]+"_massGEN", GenPart_mass[m]);
            }
        }
    }



    i = 0;
    for(unsigned int j=0; j<HSCP_hasTrack.GetSize(); j++){    // Every candidate

        if (!HSCP_hasTrack[j]) continue;

        for(unsigned int s=0;s<selections_.size();s++){ 
            bool (HSCPSelector::*ptr)(int);
            ptr = selections_[s];
            if((this->*ptr)(i)){

                AtLeastOneSelPassed = true;

                //int i = iCand[s];     // most ionising candidate
                if (i < 0) continue;

                if (selections_[s]) {
                    plots.FillHisto1D(selLabels_[s]+"_massKC", GetMass(IsoTrack_p[i], Ih_Strip[i], K_signal2018, C_signal2018));
                    plots.FillHisto1D(selLabels_[s]+"_massATLAS", findMass(IsoTrack_p[i], Ih_Strip[i]));
                }
            }
        }
        i++;

    } // End of loop over all candidates

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