import ROOT
import sys
import os
from binningVar import *
from USE_DATE import USED_DATE, VERSION 



def create_all_name(signalName,massPoints):
    allNames = ["HSCP"+signalName+"_M-"+massPoints[i] for i in range(len(massPoints))]
    allNamestoferrUp = ["HSCP"+signalName+"_M-"+massPoints[i]+"_toferrUp" for i in range(len(massPoints))]
    allNamestoferrDown = ["HSCP"+signalName+"_M-"+massPoints[i]+"_toferrDown" for i in range(len(massPoints))]
    
    allNamesfpixUp = ["HSCP"+signalName+"_M-"+massPoints[i]+"_fpixUp" for i in range(len(massPoints))]
    allNamesfpixDown = ["HSCP"+signalName+"_M-"+massPoints[i]+"_fpixDown" for i in range(len(massPoints))]
    allNamespuUp = ["HSCP"+signalName+"_M-"+massPoints[i]+"_puUp" for i in range(len(massPoints))]
    allNamespuDown = ["HSCP"+signalName+"_M-"+massPoints[i]+"_puDown" for i in range(len(massPoints))]
    allNamespTUp = ["HSCP"+signalName+"_M-"+massPoints[i]+"_pTUp" for i in range(len(massPoints))]
    allNamespTDown = ["HSCP"+signalName+"_M-"+massPoints[i]+"_pTDown" for i in range(len(massPoints))]
    allNamesTriggerUp = ["HSCP"+signalName+"_M-"+massPoints[i]+"_triggerUp" for i in range(len(massPoints))]
    allNamesTriggerDown = ["HSCP"+signalName+"_M-"+massPoints[i]+"_triggerDown" for i in range(len(massPoints))]
    allNamesMuTriggerUp = ["HSCP"+signalName+"_M-"+massPoints[i]+"_muTriggerUp" for i in range(len(massPoints))]
    allNamesMuTriggerDown = ["HSCP"+signalName+"_M-"+massPoints[i]+"_muTriggerDown" for i in range(len(massPoints))]
    allNamesMuRecoUp = ["HSCP"+signalName+"_M-"+massPoints[i]+"_muRecoUp" for i in range(len(massPoints))]
    allNamesMuRecoDown = ["HSCP"+signalName+"_M-"+massPoints[i]+"_muRecoDown" for i in range(len(massPoints))]
    allNamesMuIdUp = ["HSCP"+signalName+"_M-"+massPoints[i]+"_muIdUp" for i in range(len(massPoints))]
    allNamesMuIdDown = ["HSCP"+signalName+"_M-"+massPoints[i]+"_muIdDown" for i in range(len(massPoints))]

    return allNames,allNamestoferrUp,allNamestoferrDown,allNamesfpixUp,allNamesfpixDown,allNamespuUp,allNamespuDown,allNamespTUp,allNamespTDown,allNamesTriggerUp,allNamesTriggerDown,allNamesMuTriggerUp,allNamesMuTriggerDown,allNamesMuRecoUp,allNamesMuRecoDown,allNamesMuIdUp,allNamesMuIdDown
    

    
    
massPointsStau = ["200","247","308","432","557","651","745","871","1029"]
massPointsDY1e = ["100","200","400","500","800","1000","1800","2200","2600"]
massPointsDY2e = ["100","200","400","500","1400","1800","2200","2600"]

iMarkers = [39,22,23,8]
iColors = [26,30,41,46]
pt_name = ["100"]

if  len(sys.argv) != 3:
    print("Usage : python display_signal.py <PT cut> <Search Region (SR0...)>")

version = VERSION
ptCUT = sys.argv[1]
SearchRegion = sys.argv[2]


pathSig = "/opt/sbg/cms/ui4_data1/rhaeberl/CMSSW_10_6_30/src/HSCPTreeAnalyzer/macros/Signal_good/VATLAS_final_v4/"
extRoo = "_massCut_0_pT100_V7p0_final_atlas_ih0_beta0_allTests_corrected_oldError.root"

input_filesStau = [pathSig + "pStau"+massPointsStau[i]+extRoo for i in range(len(massPointsStau))]
input_filesDY1e = [pathSig + "tauprime1e"+massPointsDY1e[i]+extRoo for i in range(len(massPointsDY1e))]
input_filesDY2e = [pathSig + "tauprime2e"+massPointsDY2e[i]+extRoo for i in range(len(massPointsDY2e))]

allInputFiles = [input_filesStau,input_filesDY1e,input_filesDY2e]


allNames,allNamestoferrUp,allNamestoferrDown,allNamesfpixUp,allNamesfpixDown,allNamespuUp,allNamespuDown,allNamespTUp,allNamespTDown,allNamesTriggerUp,allNamesTriggerDown,allNamesMuTriggerUp,allNamesMuTriggerDown,allNamesMuRecoUp,allNamesMuRecoDown,allNamesMuIdUp,allNamesMuIdDown  = create_all_name("pairStau",massPointsStau)

allNames2,allNamestoferrUp2,allNamestoferrDown2,allNamesfpixUp2,allNamesfpixDown2,allNamespuUp2,allNamespuDown2,allNamespTUp2,allNamespTDown2,allNamesTriggerUp2,allNamesTriggerDown2,allNamesMuTriggerUp2,allNamesMuTriggerDown2,allNamesMuRecoUp2,allNamesMuRecoDown2,allNamesMuIdUp2,allNamesMuIdDown2  = create_all_name("DYcharge1e",massPointsDY1e)

allNames3,allNamestoferrUp3,allNamestoferrDown3,allNamesfpixUp3,allNamesfpixDown3,allNamespuUp3,allNamespuDown3,allNamespTUp3,allNamespTDown3,allNamesTriggerUp3,allNamesTriggerDown3,allNamesMuTriggerUp3,allNamesMuTriggerDown3,allNamesMuRecoUp3,allNamesMuRecoDown3,allNamesMuIdUp3,allNamesMuIdDown3  = create_all_name("DYcharge2e",massPointsDY2e)

allNamesTrio = [allNames,allNames2,allNames3]
allNamestoferrUpTrio = [allNamestoferrUp,allNamestoferrUp2,allNamestoferrUp3]
allNamestoferrDownTrio = [allNamestoferrDown,allNamestoferrDown2,allNamestoferrDown3]
allNamesfpixUpTrio = [allNamesfpixUp,allNamesfpixUp2,allNamesfpixUp3]
allNamesfpixDownTrio = [allNamesfpixDown,allNamesfpixDown2,allNamesfpixDown3]
allNamespuUpTrio = [allNamespuUp,allNamespuUp2,allNamespuUp3]
allNamespuDownTrio = [allNamespuDown,allNamespuDown2,allNamespuDown3]
allNamespTUpTrio = [allNamespTUp,allNamespTUp2,allNamespTUp3]
allNamespTDownTrio = [allNamespTDown,allNamespTDown2,allNamespTDown3]
allNamesTriggerUpTrio = [allNamesTriggerUp,allNamesTriggerUp2,allNamesTriggerUp3]
allNamesTriggerDownTrio = [allNamesTriggerDown,allNamesTriggerDown2,allNamesTriggerDown3]
allNamesMuTriggerUpTrio = [allNamesMuTriggerUp,allNamesMuTriggerUp2,allNamesMuTriggerUp3]
allNamesMuTriggerDownTrio = [allNamesMuTriggerDown,allNamesMuTriggerDown2,allNamesMuTriggerDown3]
allNamesMuRecoUpTrio = [allNamesMuRecoUp,allNamesMuRecoUp2,allNamesMuRecoUp3]
allNamesMuRecoDownTrio = [allNamesMuRecoDown,allNamesMuRecoDown2,allNamesMuRecoDown3]
allNamesMuIdUpTrio = [allNamesMuIdUp,allNamesMuIdUp2,allNamesMuIdUp3]
allNamesMuIdDownTrio = [allNamesMuIdDown,allNamesMuIdDown2,allNamesMuIdDown3]



nameFiles = [allNames[i].split("_")[0]+allNames[i].split("_")[1]+ '_Sys.root' for i in range(len(allNames))]
nameFiles2 = [allNames2[i].split("_")[0]+allNames2[i].split("_")[1]+ '_Sys.root' for i in range(len(allNames2))]
nameFiles3 = [allNames3[i].split("_")[0]+allNames3[i].split("_")[1]+ '_Sys.root' for i in range(len(allNames3))]

allnameFiles = [nameFiles,nameFiles2,nameFiles3]

nameRootSR ="sigMass_"+SearchRegion+"_pT"+ptCUT+".root"
path_direc = "V"+version+"/SignalMass_V"+version+SearchRegion+"_pT"+ptCUT

if not os.path.exists(path_direc):
    os.makedirs(path_direc)


signalFiles = [ROOT.TFile.Open(path_direc+"/" +name , "RECREATE") for name in nameFiles]

signalFiles2 = [ROOT.TFile.Open(path_direc+"/" +name , "RECREATE") for name in nameFiles2]
signalFiles3 = [ROOT.TFile.Open(path_direc+"/" +name , "RECREATE") for name in nameFiles3]

allSignalFiles = [signalFiles,signalFiles2,signalFiles3]

for fi in range(3):
    rFiles = [ROOT.TFile(allInputFiles[fi][m]) for m in range(len(allInputFiles[fi]))]
    massDistribSR = [rFiles[i].Get("testIhPt_hMassMuonCombined_SR1_9fp10") for i in range(len(rFiles))]
    
    massDistribSR_toferrUp = [rFiles[i].Get("testIhPt_hMassMuonCombined_SR1_9fp10_toferrUp") for i in range(len(rFiles))]
    massDistribSR_toferrDown = [rFiles[i].Get("testIhPt_hMassMuonCombined_SR1_9fp10_toferrDown") for i in range(len(rFiles))]
    
    massDistribSR_triggerUp = [rFiles[i].Get("testIhPt_hMassMuonCombined_SR1_9fp10_triggerUp") for i in range(len(rFiles))]
    massDistribSR_triggerDown = [rFiles[i].Get("testIhPt_hMassMuonCombined_SR1_9fp10_triggerDown") for i in range(len(rFiles))]
    massDistribSR_puUp = [rFiles[i].Get("testIhPt_hMassMuonCombined_SR1_9fp10_puUp") for i in range(len(rFiles))]
    massDistribSR_puDown = [rFiles[i].Get("testIhPt_hMassMuonCombined_SR1_9fp10_puDown") for i in range(len(rFiles))]
    massDistribSR_pTUp = [rFiles[i].Get("testIhPt_hMassMuonCombined_SR1_9fp10_pTUp") for i in range(len(rFiles))]
    massDistribSR_pTDown = [rFiles[i].Get("testIhPt_hMassMuonCombined_SR1_9fp10_pTDown") for i in range(len(rFiles))]
    massDistribSR_fpixUp = [rFiles[i].Get("testIhPt_hMassMuonCombined_SR1_9fp10_fpixUp") for i in range(len(rFiles))]
    massDistribSR_fpixDown = [rFiles[i].Get("testIhPt_hMassMuonCombined_SR1_9fp10_fpixDown") for i in range(len(rFiles))]
    massDistribSR_muRecoUp = [rFiles[i].Get("testIhPt_hMassMuonCombined_SR1_9fp10_muRecoUp") for i in range(len(rFiles))]
    massDistribSR_muRecoDown = [rFiles[i].Get("testIhPt_hMassMuonCombined_SR1_9fp10_muRecoDown") for i in range(len(rFiles))]
    massDistribSR_muTriggerUp = [rFiles[i].Get("testIhPt_hMassMuonCombined_SR1_9fp10_muTriggerUp") for i in range(len(rFiles))]
    massDistribSR_muTriggerDown = [rFiles[i].Get("testIhPt_hMassMuonCombined_SR1_9fp10_muTriggerDown") for i in range(len(rFiles))]
    massDistribSR_muIdUp = [rFiles[i].Get("testIhPt_hMassMuonCombined_SR1_9fp10_muIdUp") for i in range(len(rFiles))]
    massDistribSR_muIdDown = [rFiles[i].Get("testIhPt_hMassMuonCombined_SR1_9fp10_muIdDown") for i in range(len(rFiles))]
    
    
    for i in range(len(massDistribSR)):
        massDistribSR[i] = massDistribSR[i].Rebin(sizeRebinning,'pt'+ptCUT+str(i),rebinning)
        massDistribSR_toferrUp[i] = massDistribSR_toferrUp[i].Rebin(sizeRebinning,'pt'+ptCUT+str(i),rebinning)
        massDistribSR_toferrDown[i] = massDistribSR_toferrDown[i].Rebin(sizeRebinning,'pt'+ptCUT+str(i),rebinning)
       
        massDistribSR_triggerUp[i] = massDistribSR_triggerUp[i].Rebin(sizeRebinning,'',rebinning)
        massDistribSR_triggerDown[i] = massDistribSR_triggerDown[i].Rebin(sizeRebinning,'',rebinning)
        massDistribSR_puUp[i] = massDistribSR_puUp[i].Rebin(sizeRebinning,'',rebinning)
        massDistribSR_puDown[i] = massDistribSR_puDown[i].Rebin(sizeRebinning,'',rebinning)
        massDistribSR_pTUp[i] = massDistribSR_pTUp[i].Rebin(sizeRebinning,'',rebinning)
        massDistribSR_pTDown[i] = massDistribSR_pTDown[i].Rebin(sizeRebinning,'',rebinning)
        massDistribSR_fpixUp[i] = massDistribSR_fpixUp[i].Rebin(sizeRebinning,'',rebinning)
        massDistribSR_fpixDown[i] = massDistribSR_fpixDown[i].Rebin(sizeRebinning,'',rebinning)
        massDistribSR_muRecoUp[i] = massDistribSR_muRecoUp[i].Rebin(sizeRebinning,'',rebinning)
        massDistribSR_muRecoDown[i] = massDistribSR_muRecoDown[i].Rebin(sizeRebinning,'',rebinning)
        massDistribSR_muTriggerUp[i] = massDistribSR_muTriggerUp[i].Rebin(sizeRebinning,'',rebinning)
        massDistribSR_muTriggerDown[i] = massDistribSR_muTriggerDown[i].Rebin(sizeRebinning,'',rebinning)
        massDistribSR_muIdUp[i] = massDistribSR_muIdUp[i].Rebin(sizeRebinning,'',rebinning)
        massDistribSR_muIdDown[i] = massDistribSR_muIdDown[i].Rebin(sizeRebinning,'',rebinning)
        
    
    for i in range(len(massDistribSR)):
        massDistribSR[i].SetMarkerStyle(iMarkers[0])
        massDistribSR[i].SetMarkerColor(iColors[0])
    
    for i in range(len(allSignalFiles[fi])):
        allSignalFiles[fi][i].cd()
        massDistribSR[i].Write(str(allnameFiles[fi][i]))
        massDistribSR_toferrUp[i].Write(str(allNamestoferrUpTrio[fi][i]))
        massDistribSR_toferrDown[i].Write(str(allNamestoferrDownTrio[fi][i]))
        massDistribSR_puUp[i].Write(str(allNamespuUpTrio[fi][i]))
        massDistribSR_puDown[i].Write(str(allNamespuDownTrio[fi][i]))
        massDistribSR_pTUp[i].Write(str(allNamespTUpTrio[fi][i]))
        massDistribSR_pTDown[i].Write(str(allNamespTDownTrio[fi][i]))
        massDistribSR_triggerUp[i].Write(str(allNamesTriggerUpTrio[fi][i]))
        massDistribSR_triggerDown[i].Write(str(allNamesTriggerDownTrio[fi][i]))
        massDistribSR_fpixUp[i].Write(str(allNamesfpixUpTrio[fi][i]))
        massDistribSR_fpixDown[i].Write(str(allNamesfpixDownTrio[fi][i]))
        massDistribSR_muRecoUp[i].Write(str(allNamesMuRecoUpTrio[fi][i]))
        massDistribSR_muRecoDown[i].Write(str(allNamesMuRecoDownTrio[fi][i]))
        massDistribSR_muTriggerUp[i].Write(str(allNamesMuTriggerUpTrio[fi][i]))
        massDistribSR_muTriggerDown[i].Write(str(allNamesMuTriggerDownTrio[fi][i]))
        massDistribSR_muIdUp[i].Write(str(allNamesMuIdUpTrio[fi][i]))
        massDistribSR_muIdDown[i].Write(str(allNamesMuIdDownTrio[fi][i]))
        allSignalFiles[fi][i].Close()
    
    
    for i in range(len(rFiles)):
        rFiles[i].Close()

