#ifndef CPlots_h
#define CPlots_h

#include <TH1.h>
#include <TH2.h>
#include <TList.h>
#include <map>
#include <string>


/**
 The class CPlots is used to create, store & fill many histograms (TH1D, TH1F, TH2F),
 addressed by their name through std::map containers.
 Ordered usage of methods:
   - AddHisto* before any loop (in initialization). A name already booked is ignored.
   - FillHisto* within the loop(s). Returns false if no histogram has this name.
   - AddToList after the loop(s), to hand the histograms over to an output list.
 The histograms are never deleted by CPlots, and copies of a CPlots share the same histograms.
 **/

class CPlots{
    public:
        CPlots(){}
        ~CPlots();
        void AddHisto1F(std::string name, int nbins, float xmin, float xmax, std::string title = "");
        void AddHisto2F(std::string name, int nbinsx, float xmin, float xmax,int nbinsy,float ymin, float ymax,std::string title = "");
        void AddHisto1D(std::string name, int nbins, float xmin, float xmax, std::string title = "");
        bool FillHisto1D(std::string name, float value, float weight = 1);
        bool FillHisto1F(std::string name, float value, float weight = 1);
        bool FillHisto2F(std::string name, float xvalue,float yvalue, float weight = 1);
        bool AddToList(TList* list);	

    private:
        std::map<std::string,TH1D*> mh1D_;
        std::map<std::string,TH1F*> mh1F_;
        std::map<std::string,TH2F*> mh2F_;
};

#endif
