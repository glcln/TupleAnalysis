#include "PlotTools.h"



// Scale the 1D-histogram given to the unit 
void scale(TH1* h)
{
    h->Scale(1./h->Integral(0,h->GetNbinsX()+1));
}

// Inverse the scaling ; scale the 1D-histogram to its number of entries
void invScale(TH1* h)
{
    h->Sumw2();
    h->Scale(h->GetEntries());
}

// Function returning the ratio of right integer (from x to infty) for two 1D-histograms
// This function is used in the Hscp data-driven background estimate to test the mass shape prediction
// The argument to use this type of ratio is that we're in case of cut & count experiment 
TH1D* ratioIntegral(TH1D* h1, TH1D* h2)
{    
    //float SystError = 0.2;
    TH1D* res = (TH1D*) h1->Clone(); res->Reset();
    for(int i=0;i<h1->GetNbinsX()+1;i++)
    {   
        double Perr=0, Derr=0;
        double P=h1->IntegralAndError(i,h1->GetNbinsX()+1,Perr); if(P<=0) continue;
        double D=h2->IntegralAndError(i,h2->GetNbinsX()+1,Derr);
        //Perr = sqrt(Perr*Perr + pow(P*SystError,2));
        res->SetBinContent(i,D/P);
        res->SetBinError(i,sqrt(pow(Derr*P,2)+pow(Perr*D,2))/pow(P,2));
    }
    return res;
}

TH1F* ratioIntegral(TH1F* h1, TH1F* h2)
{    
    //float SystError = 0.2;
    TH1F* res = (TH1F*) h1->Clone(); res->Reset();
    for(int i=0;i<h1->GetNbinsX()+1;i++)
    {   
        double Perr=0, Derr=0;
        double P=h1->IntegralAndError(i,h1->GetNbinsX()+1,Perr); if(P<=0) continue;
        double D=h2->IntegralAndError(i,h2->GetNbinsX()+1,Derr);
        //Perr = sqrt(Perr*Perr + pow(P*SystError,2));
        res->SetBinContent(i,D/P);
        res->SetBinError(i,sqrt(pow(Derr*P,2)+pow(Perr*D,2))/pow(P,2));
    }
    return res;
}

// Function returning chi2/ndof compatibility test for two 1D-histograms
// As a reference, we've access to the number of degrees of freedom 
float chi2test(TH1* h1, TH1* h2,int& dof)
{
    float res=0;
    int ndof=0;
    for(int i=1;i<h1->GetNbinsX();i++)
    {
        res += h2->GetBinContent(i)>0 ? pow((h1->GetBinContent(i)-h2->GetBinContent(i)),2)/h2->GetBinContent(i) : 0 ;
        if(h2->GetBinContent(i)>0) ndof++;
    }
    dof=ndof;
    return res/ndof;
}

void overflowLastBin(TH1* h){
    h->SetBinContent(h->GetNbinsX(),h->GetBinContent(h->GetNbinsX())+h->GetBinContent(h->GetNbinsX()+1));
    h->SetBinContent(h->GetNbinsX()+1,0);
}

void overflowLastBin(TH1* h, const float &x){
    for(int i=h->FindBin(x);i<=h->GetNbinsX()+1;i++){
        h->SetBinContent(h->FindBin(x)-1,h->GetBinContent(h->FindBin(x)-1)+h->GetBinContent(i));
        h->SetBinContent(i,0);
    }
}

