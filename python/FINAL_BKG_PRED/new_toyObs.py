import os
import ROOT
from binningVar import *
import sys
from USE_DATE import USED_DATE,VERSION


def poissonHisto(h, RNG):
    hres = h.Clone()
    for i in range(h.GetNbinsX()+1):
        poissonRandom = RNG.Poisson(h.GetBinContent(i))
        hres.SetBinContent(i, poissonRandom)
        print("Bin {} : Initial content was {}, poisson draw content = {}".format(i,h.GetBinContent(i),poissonRandom))    
    return hres



input_base_path = "V"+VERSION + '/' +USED_DATE  + "pt"
output_base_path = "V"+VERSION + "/data"+VERSION + "_pt"

pt_values = ["100"]
years = ["2017", "2018"]
sr_values = ["SR1"]

for pt in pt_values:
    input_dir = input_base_path + pt
    output_dir = output_base_path + pt

    if not os.path.exists(output_dir):
        os.makedirs(output_dir)
        print("Made dir {}".format(output_dir))

    for year in years:
        for sr in sr_values:
            input_file_name = '{}_{}_predMass.root'.format(year, sr)
            input_file_path = os.path.join(input_dir, input_file_name)

            output_file_name = '{}_{}_ObsMassPoisson.root'.format(year, sr)
            output_file_path = os.path.join(output_dir, output_file_name)

            output_file_name_rebin = '{}_{}_ObsMass_poissonHisto_rebin'.format(year, sr)
            output_file_name_raw = '{}_{}_ObsMass_poissonHisto_raw'.format(year, sr)
            
            print("Trying to open root file {}".format(input_file_path)) 
            input_file = ROOT.TFile(input_file_path, "READ")

             
            #input_hist_name = os.path.splitext(input_file_name)[0]+'_raw'
            input_hist_name = os.path.splitext(input_file_name)[0]
            print("Retrieving histo {} from file  {}".format(input_hist_name,input_file_path))

            input_hist = input_file.Get(input_hist_name)
            if not isinstance(input_hist, ROOT.TH1F): 
                print("Histo is not a TH1F")
                print(input_hist)
                continue

            print("Input hist ={}".format(input_hist))        
            input_hist = input_hist.Rebin(sizeRebinning,"",rebinning)      


            output_file = ROOT.TFile(output_file_path, "RECREATE")

            rng = ROOT.TRandom3()
            
            output_hist = poissonHisto(input_hist, rng)
            output_hist.Write(output_file_name_raw)

            output_hist.Write(output_file_name_rebin)
            output_file.Close()

            input_file.Close()
