#ifndef MassTools_h
#define MassTools_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TRandom3.h>
#include <TMath.h>
#include <TH1D.h>
#include <TH2D.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <TMatrixDSym.h>
#include <TMatrixDSymEigen.h>
#include <TVectorD.h>
#include <TF1.h>
#include <TProfile.h>
#include <TCanvas.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


    // K & C method
float GetMass(float p, float ih, float k, float c);

    // other
float deltaR(float eta1, float phi1, float eta2, float phi2);

void loadSF(const std::string& filepath,
            bool SFisUp, bool SFisDown,
            std::vector<float>& SF_PseudoMETvalue,
            std::vector<float>& SF_triggerEff);

void loadSF2D(const std::string& filepath,
            std::vector<float>& SF_PseudoMETlo,
            std::vector<float>& SF_PseudoMEThi,
            std::vector<float>& SF_PUppiMETlo,
            std::vector<float>& SF_PUppiMEThi,
            std::vector<float>& SF_Down,
            std::vector<float>& SF,
            std::vector<float>& SF_Up);
            
void loadSF1D(const std::string& filepath,
            std::vector<float>& SF_MET,
            std::vector<float>& SF_Down,
            std::vector<float>& SF,
            std::vector<float>& SF_Up);
#endif
