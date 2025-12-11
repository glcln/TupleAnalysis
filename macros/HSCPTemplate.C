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
    std::string ext = ".root";

    std::string ptname( ((TObjString *)(tx->At(1)))->String().Data());
    int ptInt = std::stoi(ptname);

    oFile_ = ((TObjString *)(tx->At(9)))->String().Data();
    oFile_ += "_";
    oFile_ += ((TObjString *)(tx->At(10)))->String().Data();
    oFile_ += "_Eta2p4";
    oFile_ += ext;

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


    //-------------------------------------
    //Add selections into a vector - to be updated
    //FILL-SELECTION-VECTOR
    //-------------------------------------

    //-------------------------------------
    //create RegionMassPlot for all selection
    //-------------------------------------
    for(unsigned int i=0;i<selLabels_.size();i++)
    {
        CPlots plots;

        plots.AddHisto1D(selLabels_[i]+"_massKC", 200, 0, 4000);
        plots.AddHisto1D(selLabels_[i]+"_massATLAS", 200, 0, 4000);
        plots.AddHisto1D(selLabels_[i]+"_massATLAS_sup", 200, 0, 4000);

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
    vector<int> iCand(selLabels_.size(),-1);
    vector<float> maxIh(selLabels_.size(),-1);
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


    i = 0;
    for(unsigned int j=0; j<HSCP_hasTrack.GetSize(); j++){    // Every candidate

        if (!HSCP_hasTrack[j]) continue;

        for(unsigned int s=0;s<selections_.size();s++){ 
            bool (HSCPSelector::*ptr)(int);
            ptr = selections_[s];
            if((this->*ptr)(i)){

                //int i = iCand[s];     // most ionising candidate
                //if (i < 0) continue;

                if (selections_[s]) {
                    double P = Pt_pseudo[i]*cosh(Eta_pseudo[i]);
                    vcp[s].FillHisto1D(selLabels_[s]+"_massKC", GetMass(P, Ih_Strip[i], K_signal2018, C_signal2018));
                    vcp[s].FillHisto1D(selLabels_[s]+"_massATLAS", findMass(P, Ih_Strip[i], "2024", false, false, false)); // only nominal here

                    vcp[s].FillHisto1D(selLabels_[s]+"_massATLAS_sup", findMass(P, Ih_Strip[i], "2024", false, false, true));
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