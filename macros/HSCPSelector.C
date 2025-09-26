#define HSCPSelector_cxx

#include "HSCPSelector.h"
#include <TH2.h>
#include <TH1.h>
#include <TStyle.h>
#include <functional>


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
bool HSCPSelector::PassHSCPpresel_sel(int i){
   if (i<0 || i>(int)Pt.GetSize()) return false;
   return (true);
}



void HSCPSelector::Begin(TTree * /*tree*/)
{
    TString option = GetOption();
    TObjArray *tx = option.Tokenize(",");

    // Output file
    std::string ext = ".root";

    std::string ptname( ((TObjString *)(tx->At(1)))->String().Data());
    int ptInt = std::stoi(ptname);

    oFile_ = ((TObjString *)(tx->At(9)))->String().Data();
    oFile_ += "_Eta2p4";
    oFile_ += ext;

    //FILL-SELECTION-VECTOR
selections_.push_back(&HSCPSelector::PassHSCPpresel_sel);
selLabels_.push_back("sel");


    std::cout << std::endl;
    std::cout << "Number of selections: " << selLabels_.size() << std::endl;
    std::cout << "Output file: " << oFile_.c_str() << std::endl;
    std::cout << std::endl;
}



void HSCPSelector::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();
   TObjArray *tx = option.Tokenize(",");

   std::string dataset( ((TObjString *)(tx->At(9)))->String().Data());
   dataset_ = dataset;
   if(dataset_ == "Gluino2000"){ 
       K = K_signal2018;
       C = C_signal2018;
       year = 2018;
   }


   //-------------------------------------
   //Add selections into a vector - to be updated
   //FILL-SELECTION-VECTOR
selections_.push_back(&HSCPSelector::PassHSCPpresel_sel);
selLabels_.push_back("sel");

   //-------------------------------------
   
   //-------------------------------------
   //create RegionMassPlot for all selection
   //-------------------------------------
    for(unsigned int i=0;i<selLabels_.size();i++)
    {
        CPlots plots;

        plots.AddHisto1D(selLabels_[i]+"_Ih", 200, 0, 20);
        plots.AddHisto1D(selLabels_[i]+"_Pt", 100, 0, 2000);
        plots.AddHisto1D(selLabels_[i]+"_Eta", 50, -2.5, 2.5);
        plots.AddHisto1D(selLabels_[i]+"_NbPixelHit_noL1", 10, 0, 10);
        plots.AddHisto1D(selLabels_[i]+"_NOM_noL1", 50, 0, 50);
        plots.AddHisto1D(selLabels_[i]+"_FracOfValidHit", 50, 0, 1);
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
        plots.AddHisto1D(selLabels_[i]+"_RecoCaloMET", 100, 0, 500);
        plots.AddHisto1D(selLabels_[i]+"_Flag_allMETFilters", 2, -0.5, 1.5);
        


        vcp.push_back(std::move(plots));
   }
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

    for(unsigned int i=0;i<Pt.GetSize();i++){
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
   } //End of loop over all HSCP candidates

   //for(unsigned int i=0;i<Pt.GetSize();i++){    // Every candidate

    for(unsigned int s=0;s<selections_.size();s++){ 
    //bool (HSCPSelector::*ptr)(int);
    //ptr = selections_[s];
    //if((this->*ptr)(i)){

        int i = iCand[s];     // most ionising candidate
	    if (i < 0) continue;

        if (selections_[s]){

            // Fill the histograms based on the list : Pt Eta NbPixelHit_noL1 NOM_noL1 FracOfValidHit isHighPurityTrack miniRelIsoAll IsoSumPt_dr03 IsoTrack_dz IsoTrack_dxy IsoTrack_normChi2 EoP ptOverptErrptErr ptOverptErr Fpix RecoCaloMET Flag_allMETFilters
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
            vcp[s].FillHisto1D(selLabels_[s]+"_RecoCaloMET", RecoCaloMET[0]);
            vcp[s].FillHisto1D(selLabels_[s]+"_Flag_allMETFilters", Flag_allMETFilters[0]);
        }

    }
   //} 
   //}

   return kTRUE;
}

void HSCPSelector::SlaveTerminate()
{
   for(auto obj: vcp) obj.AddToList(fOutput);
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
