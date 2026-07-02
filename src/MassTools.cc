#include "MassTools.h"
#include "PlotTools.h"

using namespace std;





float GetMass(float p, float ih, float k, float c)
{
    return (ih-c)<0?-1:sqrt((ih-c)/k)*p;
}


float deltaR(float eta1, float phi1, float eta2, float phi2) {
    float deta = eta1 - eta2;
    float dphi = phi1 - phi2;
    while (dphi > M_PI)
        dphi -= 2 * M_PI;
    while (dphi <= -M_PI)
        dphi += 2 * M_PI;
    return sqrt(deta * deta + dphi * dphi);
}

void loadSF(const std::string& filepath,
            bool SFisUp,
            bool SFisDown,
            std::vector<float>& SF_PseudoMETvalue,
            std::vector<float>& SF_triggerEff) {
                
    SF_PseudoMETvalue.clear();
    SF_triggerEff.clear();

    std::ifstream file(filepath);
    if (!file.is_open())
        throw std::runtime_error("Cannot open file: " + filepath);

    float pseudoMET, sfDown, sf, sfUp;
    cout << "Loading SF from file: " << filepath << endl;
    while (file >> pseudoMET >> sfDown >> sf >> sfUp) {
        SF_PseudoMETvalue.push_back(pseudoMET);

        if      (SFisUp)   SF_triggerEff.push_back(sfUp);
        else if (SFisDown) SF_triggerEff.push_back(sfDown);
        else               SF_triggerEff.push_back(sf);
    }

    return;
}


void loadSF2D(const std::string& filepath,
            std::vector<float>& SF_PseudoMETlo,
            std::vector<float>& SF_PseudoMEThi,
            std::vector<float>& SF_PUppiMETlo,
            std::vector<float>& SF_PUppiMEThi,
            std::vector<float>& SF_Down,
            std::vector<float>& SF,
            std::vector<float>& SF_Up) {

    SF_PseudoMETlo.clear();
    SF_PseudoMEThi.clear();
    SF_PUppiMETlo.clear();
    SF_PUppiMEThi.clear();
    SF_Down.clear();
    SF.clear();
    SF_Up.clear();

    std::ifstream file(filepath);
    if (!file.is_open())
        throw std::runtime_error("Cannot open file: " + filepath);

    float pseudoLo, pseudoHi, puppiLo, puppiHi, sfDown, sf, sfUp;
    cout << "Loading 2D SF from file: " << filepath << endl;
    while (file >> pseudoLo >> pseudoHi >> puppiLo >> puppiHi >> sfDown >> sf >> sfUp) {
        SF_PseudoMETlo.push_back(pseudoLo);
        SF_PseudoMEThi.push_back(pseudoHi);
        SF_PUppiMETlo.push_back(puppiLo);
        SF_PUppiMEThi.push_back(puppiHi);

        SF_Down.push_back(sfDown);
        SF.push_back(sf);
        SF_Up.push_back(sfUp);
    }

    return;
}

void loadSF1D(const std::string& filepath,
            std::vector<float>& SF_MET,
            std::vector<float>& SF_Down,
            std::vector<float>& SF,
            std::vector<float>& SF_Up) {
                
    SF_MET.clear();
    SF_Down.clear();
    SF.clear();
    SF_Up.clear();

    std::ifstream file(filepath);
    if (!file.is_open())
        throw std::runtime_error("Cannot open file: " + filepath);

    float MET, sfDown, sf, sfUp;
    cout << "Loading SF from file: " << filepath << endl;
    while (file >> MET >> sfDown >> sf >> sfUp) {
        SF_MET.push_back(MET);

        SF_Down.push_back(sfDown);
        SF.push_back(sf);
        SF_Up.push_back(sfUp);
    }

    return;
}