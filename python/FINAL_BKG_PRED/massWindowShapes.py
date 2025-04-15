import ROOT
import os
import re

def process_root_files(directory):
    files = [f for f in os.listdir(directory) if f.endswith('.root')]
    print(files)
    for file in files:
        mass_point = re.search(r'Histos_massShape_HSCPpairStauM-(\d+)\.root', file).group(1)
        
        root_file = ROOT.TFile.Open(os.path.join(directory, file))
        sig = root_file.Get("signal_Ch2017")
        mean = sig.GetMean()
        std_dev = sig.GetStdDev()
        low = mean - std_dev
        high = mean + 2 * std_dev
        max_bin = sig.GetMaximumBin()
        max_count = sig.GetBinContent(max_bin)

        keys = root_file.GetListOfKeys()
        print("############### Stau M = {} ###############".format(mass_point))
        #print("Mass window for integration = [{},{}]".format(low,high))
        print("Bin with maximum value in signal is bin #{}, with content = {}".format(max_bin,max_count))
        for key in keys:
            obj = key.ReadObj()
            if isinstance(obj, ROOT.TH1F):
                #integral = obj.Integral(obj.FindBin(low), obj.FindBin(high))
                content = obj.GetBinContent(max_bin)
                print("{}, Yield =  {}".format(obj.GetName(), content))
        
        root_file.Close()


directory = 'V80p9/MassShapeHistos_pT100_SR1_V80p9_Ih4p35'
process_root_files(directory)
