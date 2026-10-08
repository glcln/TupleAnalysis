#ifndef MassTools_h
#define MassTools_h

#include <string>
#include <vector>


    // K & C method
float GetMass(float p, float ih, float k, float c);

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
