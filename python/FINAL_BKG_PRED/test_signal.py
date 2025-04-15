import ROOT
import sys
import os
from binningVar import *
from USE_DATE import USED_DATE, VERSION 


massPoints = ["200","247","308","432","557","651","745","871","1029"]
massPoints = ["200","247","308","432"]

sType = ['$\\tilde{\\tau}$ (M='+i+' GeV)' for i in massPoints]



iMarkers = [39,22,23,8]
iColors = [26,30,41,46]
pt_name = ["100"]

if  len(sys.argv) != 3:
    print("Usage : python display_signal.py <PT cut> <Search Region (SR0...)>")

version = VERSION
ptCUT = sys.argv[1]
SearchRegion = sys.argv[2]


pathSig = "/opt/sbg/cms/ui4_data1/rhaeberl/CMSSW_10_6_30/src/HSCPTreeAnalyzer/macros/Signal_good/VTOF_v1/"

input_files = [pathSig + "pStau"+massPoints[i]+"_massCut_0_pT100_V7p0_Fpix_pt_ih3p35_betainf1_ALLCUTS_cutChi2_40.root" for i in range(len(massPoints))]

allNames = ["HSCPpairStau_M-"+massPoints[i] for i in range(len(massPoints))]

nameFiles = [allNames[i].split("_")[0]+allNames[i].split("_")[1]+ '_Sys.root' for i in range(len(allNames))]

nameRootSR ="sigMass_"+SearchRegion+"_pT"+ptCUT+".root"
path_direc = "V"+version+"/SignalMass_V"+version+SearchRegion+"_pT"+ptCUT

if not os.path.exists(path_direc):
    os.makedirs(path_direc)


signalFiles = [ROOT.TFile.Open(path_direc+"/" +name , "RECREATE") for name in nameFiles]

rFiles = [ROOT.TFile(input_files[i]) for i in range(len(input_files))]

massDistribSR = [rFiles[i].Get("mass_regionD_9fp10_testIhPt") for i in range(len(rFiles))]

for i in range(len(massDistribSR)):
    massDistribSR[i] = massDistribSR[i].Rebin(sizeRebinning,'pt'+ptCUT+str(i),rebinning)

for i in range(len(massDistribSR)):
    massDistribSR[i].SetMarkerStyle(iMarkers[0])
    massDistribSR[i].SetMarkerColor(iColors[0])

for i in range(len(signalFiles)):
    signalFiles[i].cd()
    massDistribSR[i].Write(str(allNames[i]))
    signalFiles[i].Close()


for i in range(len(rFiles)):
    rFiles[i].Close()
