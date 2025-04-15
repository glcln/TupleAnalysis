import ROOT, sys, os, time, re, numpy
from optparse import OptionParser
from tqdm import tqdm
from USE_DATE import USED_DATE, VERSION
import shutil


ROOT.gROOT.SetBatch(True)
ROOT.gStyle.SetPadRightMargin(.15)
ROOT.gStyle.SetPadTopMargin(0.1);
ROOT.gStyle.SetPadBottomMargin(0.14);
ROOT.gStyle.SetPadLeftMargin(0.15);

def copy_root_files_with_new_names(background_samples):
    for file_path in background_samples:
        new_file_path = file_path.replace(".root", "_notscaled.root")
        shutil.copy(file_path, new_file_path)
        print("Copied {} to {}".format(file_path,new_file_path))


sigPath ="/opt/sbg/cms/ui4_data1/rhaeberl/CMSSW_10_6_30/src/HSCPTreeAnalyzer/macros/Signal_good/VATLAS_final_v4/"

cutChi2 = "cutChi2_40"
ihCut = "ih3p65"
betaCut = "beta1p04"

EXTroot = "massCut_0_pT100_V7p0_final_atlas_ih0_beta0_allTests_corrected_oldError.root"
BackgroundSamples = [
sigPath + "pStau200_"+EXTroot,
sigPath + "pStau247_"+EXTroot,
sigPath + "pStau308_"+EXTroot,
sigPath + "pStau432_"+EXTroot,
sigPath + "pStau557_"+EXTroot,
sigPath + "pStau651_"+EXTroot,
sigPath + "pStau745_"+EXTroot,
sigPath + "pStau871_"+EXTroot,
sigPath + "pStau1029_"+EXTroot,
sigPath + "tauprime1e100_"+EXTroot,
sigPath + "tauprime1e200_"+EXTroot,
sigPath + "tauprime1e400_"+EXTroot,
sigPath + "tauprime1e500_"+EXTroot,
sigPath + "tauprime1e800_"+EXTroot,
sigPath + "tauprime1e1000_"+EXTroot,
sigPath + "tauprime1e1800_"+EXTroot,
sigPath + "tauprime1e2200_"+EXTroot,
sigPath + "tauprime1e2600_"+EXTroot,
sigPath + "tauprime2e100_"+EXTroot,
sigPath + "tauprime2e200_"+EXTroot,
sigPath + "tauprime2e400_"+EXTroot,
sigPath + "tauprime2e500_"+EXTroot,
#sigPath + "tauprime2e800_massCut_0_pT100_V7p0_final_atlas_20june.root",
sigPath + "tauprime2e1400_"+EXTroot,
sigPath + "tauprime2e1800_"+EXTroot,
sigPath + "tauprime2e2200_"+EXTroot,
sigPath + "tauprime2e2600_"+EXTroot,
]

copy_root_files_with_new_names(BackgroundSamples)

#Without 2017F which amounts to 13.54 inverse femtobarn
#intLumi = 87500

#For entire 2017 + 2018
intLumi = 101000.0


crossSectionArray = {

sigPath + "pStau200_"+EXTroot : 0.0303143567,
sigPath + "pStau247_"+EXTroot : 0.01354210931669562,
sigPath + "pStau308_"+EXTroot : 0.005617969677491303,
sigPath + "pStau432_"+EXTroot : 0.0013205993021946,
sigPath + "pStau557_"+EXTroot : 0.0003982919391389629,
sigPath + "pStau651_"+EXTroot : 0.00018170273864904894,
sigPath + "pStau745_"+EXTroot : 8.760649473515753e-5,
sigPath + "pStau871_"+EXTroot : 3.548748280460506e-5,
sigPath + "pStau1029_"+EXTroot : 1.1684554271190975e-5,
sigPath + "tauprime1e200_"+EXTroot : 1.833e-01,
sigPath + "tauprime1e400_"+EXTroot : 1.361e-02,
sigPath + "tauprime1e500_"+EXTroot : 6.0e-03,
sigPath + "tauprime1e800_"+EXTroot : 5.697e-04,
sigPath + "tauprime1e1000_"+EXTroot : 1.638e-04,
sigPath + "tauprime1e1800_"+EXTroot : 2.641e-06,
sigPath + "tauprime1e2200_"+EXTroot : 4.175e-07,
sigPath + "tauprime1e2600_"+EXTroot : 7.282e-08,
sigPath + "tauprime2e200_"+EXTroot : 7.332e-01,
sigPath + "tauprime2e400_"+EXTroot : 5.440e-02,
sigPath + "tauprime2e500_"+EXTroot : 2.50e-02,
sigPath + "tauprime2e1400_"+EXTroot : 7.477e-05,
sigPath + "tauprime2e1800_"+EXTroot : 1.056e-05,
sigPath + "tauprime2e2200_"+EXTroot : 1.670e-06,
sigPath + "tauprime2e2600_"+EXTroot : 2.913e-07,
}

# gluino x-sections from
# https://github.com/fuenfundachtzig/xsec/blob/master/json/pp13_gluino_NNLO%2BNNLL.json#L1820

fileInArray = []
for sample in BackgroundSamples:
  print(sample)
  if not os.path.exists(sample): continue
  fileInArray.append(ROOT.TFile.Open(sample,"UPDATE"))

print("Files in array : \n",fileInArray)



for fileIn in fileInArray:
  if not (fileIn.Get("preselectionSept8_PreTrigEvt")):
    print("NumEvents not found, exit for "+str(fileIn))
    continue
  print("Running on {}\n".format(fileIn)) 
  nEvetsPreTrig = fileIn.Get("preselectionSept8_PreTrigEvt").GetEntries()
  print("Number of events pre trigger = {}\n".format(nEvetsPreTrig))
  if (nEvetsPreTrig == 0):
    print("nEvetsPreTrig is zero, exiting")
    continue

  print(str(fileIn)) 
  start_index = str(fileIn).find('"') + 1
  print("start index = ", start_index)
  end_index = str(fileIn).find('.root')
  print("end index = ", end_index)
  nameFromTFile = str(fileIn)[start_index:end_index] + ".root"
  #nameFromTFile = str(fileIn)[str(fileIn).find("object")+3:str(fileIn).find("at")-3]
    
  #nameFromTFile = str(fileIn)[str(fileIn).find("Name")+6:str(fileIn).find("Title")-1]
  print nameFromTFile
  if not (crossSectionArray.get(nameFromTFile)) :
    print("No crossSectionArray for "+str(nameFromTFile))
    continue
  weight = intLumi*crossSectionArray.get(nameFromTFile)/nEvetsPreTrig
  start_idxWeights = str(fileIn).find('/stau/')
  end_idxWeights = str(fileIn).find('.root')
  name_idxWeights = str(fileIn)[start_idxWeights+6:end_idxWeights]
  print("Writing weight {} to txt file {}".format(weight,name_idxWeights))
  line = name_idxWeights + ' : ' + str(weight) + '\n'
  print("There are {} entries in the root file".format(fileIn.GetListOfKeys().GetEntries()))
  for i in tqdm(range(0, fileIn.GetListOfKeys().GetEntries())):
    keyname = fileIn.GetListOfKeys().At(i).GetName()
    if "PROOF" in keyname:
        continue
    if "Tree" in keyname:
        continue
    #print(keyname) 
    obj = fileIn.Get(keyname)
    
    if not (obj) : continue
    if (obj.GetEntries() == 0 ) :
        continue
    if obj.InheritsFrom("TObject"):
        obj.Scale(weight)
     

  fileIn.Write("",ROOT.TObject.kOverwrite)
  fileIn.Close()
