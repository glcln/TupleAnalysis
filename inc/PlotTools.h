#ifndef PlotTools_h
#define PlotTools_h


#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1D.h>
#include <TH2F.h>
#include <TProfile.h>
#include <TGraphErrors.h>
#include <TLegend.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TRandom3.h>
#include <TMath.h>


// Scale the 1D-histogram given to the unit 
void scale(TH1* h);

// Inverse the scaling ; scale the 1D-histogram to its number of entries
void invScale(TH1* h);

// Function returning the ratio of right integer (from x to infty) for two 1D-histograms
// This function is used in the Hscp data-driven background estimate to test the mass shape prediction
// The argument to use this type of ratio is that we're in case of cut & count experiment 
TH1F* ratioIntegral(TH1F* h1, TH1F* h2);

void overflowLastBin(TH1* h);

void overflowLastBin(TH1* h, const float &x);

#endif
