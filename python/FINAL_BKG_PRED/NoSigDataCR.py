'''
    Description:
        - Plot histograms for comparison
          given two ROOT files
    Requirements:
        - json file "histos.json"
        - ROOT
    ________________________

    json file needs : name of histograms, and full path within the root files

    <raphael.julien.haberle@cern.ch>
'''
import os, sys, argparse, json, copy, array, numpy, struct
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
parser = argparse.ArgumentParser(prog='python '+sys.argv[0])
parser.add_argument('ref', metavar='ref-rootfile', help='Ref ROOT file with full path')
parser.add_argument('output', metavar='output-dir', help='output directory')

sys.path.append('../')

args = parser.parse_args()
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
import ROOT
import math
import CMS_lumi, tdrstyle
from ROOT import gROOT, gStyle, TFile, TH1F, TLegend, TCanvas, TPad, TLine, TH1D, TH2F, TPaveText, gPad, gDirectory,TFitResultPtr

from binningVar import *
from SignalXS import *

from makeDataCards import *
from datetime import datetime

from FpixConstants import regions_extension as extension, extDataCards
from ValidationFunctionsData  import *

def fix_empty_bins(inputhist):
    hist = inputhist.Clone("interpolated_bkg")
    first_non_empty_bin = None
    for bin_idx in range(1, hist.GetNbinsX() + 1):
        if hist.GetBinContent(bin_idx) > 0:
            first_non_empty_bin = bin_idx
            break
    
    if first_non_empty_bin is not None:
        last_non_empty_content = hist.GetBinContent(first_non_empty_bin)
        for bin_idx in range(first_non_empty_bin + 1, hist.GetNbinsX() + 1):
            if hist.GetBinContent(bin_idx) == 0:
                hist.SetBinContent(bin_idx, last_non_empty_content)
            else:
                last_non_empty_content = hist.GetBinContent(bin_idx)
    
    return hist


if __name__ == "__main__":

    gROOT.SetBatch()
    gStyle.SetOptStat(0)


    ref = args.ref           # PedestalEqualizationReference.root'
    outdir = args.output
    InterpolateBinning = False

    try:
        os.makedirs(outdir)
    except OSError:
        if not os.path.isdir(outdir):
            raise

    fref = TFile(ref, "READ")

    year = '2018'
    if '2018' in ref:
        year = '2018'
    if '2017' in ref:
        year = '2017'
    if 'merge' in ref:
        year = '2017and2018'
    
    now = datetime.now()
    day = now.strftime("%d")
    month = now.strftime("%m")
    date = str(day) + "_" + str(month)

    ForTests = True

    nameRootSR = year+"_SR1_predMass.root"
    namePredSR = year+"_SR1_predMass"
    namePredRaw = year+"_SR1_predMass_raw"
    namePredRebin = year+"_SR1_predMass_rebin"

    scalePredMass = ROOT.TFile.Open(outdir + "/" + nameRootSR, "RECREATE")

    CRMass = ROOT.TFile.Open(outdir + "/CR_Mass_"+year+".root", "RECREATE")

    nameSR= "SR1"

    histA_cr = 'mass_regionA_3fp8'+extension
    histC_cr = 'mass_regionC_3fp8'+extension

    histD_sr1 = 'mass_regionD_9fp10'+extension
    histB_sr1 = 'mass_regionB_9fp10'+extension

    if(ForTests): 
        histA_cr = 'testIhPt_hmass_regionA_3fp8_ih3p89_beta1p13'
        histC_cr = 'testIhPt_hmass_regionC_3fp8_ih3p89_beta1p13'
        histD_sr1 = 'testIhPt_hmass_regionD_9fp10_ih3p89_beta1p13'
        histB_sr1 = 'testIhPt_hmass_regionB_9fp10_ih3p89_beta1p13'


    regA3fp8 = getHistogram(fref, histA_cr, 'regA3fp8')
    regC3fp8 = getHistogram(fref, histC_cr, 'regC3fp8')


    regC3f8_SR = regC3fp8.Clone("CR_scaled_SR1")
    regC3f8_RAW = regC3fp8.Clone("CR_raw_SR1")
    regC3f8_Rebin = regC3fp8.Clone("CR_rebin_SR1")
    
 
    regB_SR = getHistogram(fref, histB_sr1, 'regB9fp10')
    regD_SR = getHistogram(fref, histD_sr1, 'regD9fp10')
    
    print("Loaded histograms for regions !")
    print("Region A = {}".format(regA3fp8))
    print("Region B = {}".format(regB_SR))
    print("Region C = {}".format(regC3fp8))

   
 
    predD = regB_SR.GetEntries()*regC3fp8.GetEntries()/regA3fp8.GetEntries()
    print("In region A 3f8, entries = {}. region B 9f10, entries = {}. region C 3f8, entries = {}.".format(regA3fp8.GetEntries(),regB_SR.GetEntries(),regC3fp8.GetEntries()))
    print("Prediction in region D = B * C / A = {}*{}/{}  = {} entries".format(regB_SR.GetEntries(),regC3fp8.GetEntries(),regA3fp8.GetEntries(),predD))
    

    SF = predD / regC3fp8.GetEntries()

    nameSFtxt =outdir + '/' + year + "_SF_CR_SRs_stau.txt"
    with open(nameSFtxt, "w") as file:
        line = nameSR + '_' + year + '_ScaleFactor_CR_SR_stau : ' + str( (SF) ) + '\n' 
        file.write(line)


    print("Scale factor applied on region C [0.3 - 0.8] = {}".format(SF))
    scale_histogram_with_poissonian_errors(regC3f8_SR, SF)
    
 
    lejDataSR1 = "SR F^{pix}" + "[0.9 - 1]"


    
    regA3fp8 = regA3fp8.Rebin(sizeRebinning,'regA3fp8',rebinning)
    regB_SR = regB_SR.Rebin(sizeRebinning,'regB9fp10',rebinning)
    regD_SR = regD_SR.Rebin(sizeRebinning,lejDataSR1,rebinning)
    regC3f8_Rebin = regC3f8_Rebin.Rebin(sizeRebinning,lejDataSR1,rebinning)

    if(InterpolateBinning):
        regC3f8_SR = fix_empty_bins(regC3f8_SR)
        regC3f8_RAW = fix_empty_bins(regC3f8_RAW)
        regC3f8_Rebin = fix_empty_bins(regC3f8_Rebin)
            
    regC3f8_SR = regC3f8_SR.Rebin(sizeRebinning,'',rebinning)

    print("YEAR {} : Integral of background prediction in the final signal region scaled with SF = {} ---> itg = {}".format(year,SF,regC3f8_SR.Integral()))
    scalePredMass.cd()
    regC3f8_SR.Write(str(namePredSR))
    regC3f8_RAW.Write(str(namePredRaw)) 
    regC3f8_Rebin.Write(str(namePredRebin))
    scalePredMass.Close()


    CRMass.cd()
    regC3fp8.GetXaxis().SetRangeUser(0,1400)
    regC3fp8.GetYaxis().SetRangeUser(0.001,1000000)
    regC3fp8.Write(str(year+"_CR_Mass_"+year))
    CRMass.Close()
