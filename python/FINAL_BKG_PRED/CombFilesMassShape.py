import ROOT
import os
import sys
from USE_DATE import USED_DATE, VERSION

def find_root_files_in_directory(directory):
    root_files = []
    for root, _, files in os.walk(directory):
        for file in files:
            if file.endswith(".root"):
                root_files.append(os.path.join(root, file))
    return root_files

def vary_histogram_bins(hist, variation_percentage,year):
    """
    Clones the histogram N*2 times to create up and down variations for each bin.

    Parameters:
    hist (ROOT.TH1): The input histogram to be varied.
    variation_percentage (float): The percentage by which to vary each bin.

    Returns:
    list: A list of cloned histograms with up and down variations for each bin.
    """
    cloned_histograms = []

    num_bins = hist.GetNbinsX()
    for bin_idx in range(1, num_bins + 1):
        hist_up = hist.Clone("background_Ch{}_Bin{}Up".format(year,bin_idx))
        bin_content = hist.GetBinContent(bin_idx)
        hist_up.SetBinContent(bin_idx, bin_content * (1 + (variation_percentage / 100.0)))
        cloned_histograms.append(hist_up)

        hist_down = hist.Clone("background_Ch{}_Bin{}Down".format(year,bin_idx))
        hist_down.SetBinContent(bin_idx, bin_content * (1 - (variation_percentage / 100.0)))
        cloned_histograms.append(hist_down)

    return cloned_histograms


def add_all_histograms_from_directories(input_directories, objSig,objSigName, output_file_name,SearchRegion,ptCUT,ext_substracted):

    output_file = ROOT.TFile(output_file_name, "RECREATE")
    print("Searching for all hists in directories : ")
    print(input_directories)
    lumi2017 = 41.5
    lumi2018 = 59.7
    lumitot = 101.0
    
    #lumitot = 101.0
    nominal2018 = None
    nominal2017 = None
    foundNominal2017 = False
    foundNominal2018 = False
    for input_directory in input_directories:
        input_files = find_root_files_in_directory(input_directory)

        for file_path in input_files:
            input_file = ROOT.TFile.Open(file_path)

            for key in input_file.GetListOfKeys():
                obj = key.ReadObj()
                obj_name = key.GetName()
                if isinstance(obj, ROOT.TH1):
                    output_file.cd()
                    '''
                    if(obj_name == "2017_"+SearchRegion+"_ObsMass_poissonHisto_rebin"):
                        obs_2017 = obj.Clone("data_obs_Ch2017"+ext_substracted)
                        obs_2017.SetTitle("data_obs_Ch2017_title"+ext_substracted) 
                        obs_2017.SetName("data_obs_Ch2017"+ext_substracted) 
                        obs_2017.Write("data_obs_Ch2017"+ext_substracted)
                        print("Found ", obj," with name ", obj_name, "  in ", file_path)
                    '''
                    if(obj_name == "2017_"+SearchRegion+"_predMass_rebin"):
                        if not foundNominal2017:     
                            nominal2017 = obj.Clone("Nominal2017")
                            print("Setting nominal2017 to be {}".format(obj))
                            foundNominal2017 = True
                        bkg_2017 = obj.Clone("background_Ch2017"+ext_substracted)
                        bkg_2017.SetTitle("background_Ch2017_title"+ext_substracted)
                        bkg_2017.SetName("background_Ch2017"+ext_substracted)
                        bkg_2017.Write()
                        obs_2017 = obj.Clone("data_obs_Ch2017"+ext_substracted)
                        obs_2017.SetTitle("data_obs_Ch2017_title"+ext_substracted) 
                        obs_2017.SetName("data_obs_Ch2017"+ext_substracted) 
                        obs_2017.Write("data_obs_Ch2017"+ext_substracted)
                        print("Found ", obj," with name ", obj_name, "  in ", file_path)
                    '''
                    if(obj_name == "2018_"+SearchRegion+"_ObsMass_poissonHisto_rebin"):
                        obs_2018 = obj.Clone("data_obs_Ch2018"+ext_substracted)
                        obs_2018.SetTitle("data_obs_Ch2018_title"+ext_substracted) 
                        obs_2018.SetName("data_obs_Ch2018"+ext_substracted) 
                        obs_2018.Write("data_obs_Ch2018"+ext_substracted)
                        print("Found ", obj," with name ", obj_name, "  in ", file_path)
                    '''
                    if(obj_name == "2018_"+SearchRegion+"_predMass_rebin"):
                        if not foundNominal2018:     
                            nominal2018 = obj.Clone("Nominal2018")
                            foundNominal2018 = True

                        bkg_2018 = obj.Clone("background_Ch2018"+ext_substracted)
                        bkg_2018.SetTitle("background_Ch2018_title"+ext_substracted)
                        bkg_2018.SetName("background_Ch2018"+ext_substracted)
                        bkg_2018.Write()
                        obs_2018 = obj.Clone("data_obs_Ch2018"+ext_substracted)
                        obs_2018.SetTitle("data_obs_Ch2018_title"+ext_substracted) 
                        obs_2018.SetName("data_obs_Ch2018"+ext_substracted) 
                        obs_2018.Write("data_obs_Ch2018"+ext_substracted)
                        print("Found ", obj," with name ", obj_name, "  in ", file_path)
                    


            input_file.Close()
    
    output_file.cd()
    for p in range(len(objSig)):
        #if(len(objSigName[p]) == 18 or len(objSigName[p]) == 19 ):
        if("Sys" in objSigName[p]):
            print("Found {} to be the nominal signal mass distribution".format(objSigName[p]))
            scaled_2017 = objSig[p].Clone("signal_Ch2017"+ext_substracted)
            scaled_2018 = objSig[p].Clone("signal_Ch2018"+ext_substracted)
            scaled_2017.Scale(lumi2017/lumitot)
            scaled_2018.Scale(lumi2018/lumitot)
            scaled_2017.Write()
            scaled_2018.Write()
        if("toferrUp" in objSigName[p]):
            scaled_2017_toferr = objSig[p].Clone("signal_Ch2017"+ext_substracted+"_toferrUp")
            scaled_2018_toferr = objSig[p].Clone("signal_Ch2018"+ext_substracted+"_toferrUp")
            scaled_2017_toferr.Scale(lumi2017/lumitot)
            scaled_2018_toferr.Scale(lumi2018/lumitot)
            scaled_2017_toferr.Write()
            scaled_2018_toferr.Write()
        if("toferrDown" in objSigName[p]):
            scaled_2017_toferr_dn = objSig[p].Clone("signal_Ch2017"+ext_substracted+"_toferrDown")
            scaled_2018_toferr_dn = objSig[p].Clone("signal_Ch2018"+ext_substracted+"_toferrDown")
            scaled_2017_toferr_dn.Scale(lumi2017/lumitot)
            scaled_2018_toferr_dn.Scale(lumi2018/lumitot)
            scaled_2017_toferr_dn.Write()
            scaled_2018_toferr_dn.Write()

        if("puUp" in objSigName[p]):
            scaled_2017_pu = objSig[p].Clone("signal_Ch2017"+ext_substracted+"_puUp")
            scaled_2018_pu = objSig[p].Clone("signal_Ch2018"+ext_substracted+"_puUp")
            scaled_2017_pu.Scale(lumi2017/lumitot)
            scaled_2018_pu.Scale(lumi2018/lumitot)
            scaled_2017_pu.Write()
            scaled_2018_pu.Write()
        if("puDown" in objSigName[p]):
            scaled_2017_pu_dn = objSig[p].Clone("signal_Ch2017"+ext_substracted+"_puDown")
            scaled_2018_pu_dn = objSig[p].Clone("signal_Ch2018"+ext_substracted+"_puDown")
            scaled_2017_pu_dn.Scale(lumi2017/lumitot)
            scaled_2018_pu_dn.Scale(lumi2018/lumitot)
            scaled_2017_pu_dn.Write()
            scaled_2018_pu_dn.Write()
        if("pTUp" in objSigName[p]):
            scaled_2017_pt = objSig[p].Clone("signal_Ch2017"+ext_substracted+"_pTUp")
            scaled_2018_pt = objSig[p].Clone("signal_Ch2018"+ext_substracted+"_pTUp")
            scaled_2017_pt.Scale(lumi2017/lumitot)
            scaled_2018_pt.Scale(lumi2018/lumitot)
            scaled_2017_pt.Write()
            scaled_2018_pt.Write()
        if("pTDown" in objSigName[p]):
            scaled_2017_pt_dn = objSig[p].Clone("signal_Ch2017"+ext_substracted+"_pTDown")
            scaled_2018_pt_dn = objSig[p].Clone("signal_Ch2018"+ext_substracted+"_pTDown")
            scaled_2017_pt_dn.Scale(lumi2017/lumitot)
            scaled_2018_pt_dn.Scale(lumi2018/lumitot)
            scaled_2017_pt_dn.Write()
            scaled_2018_pt_dn.Write()
        if("triggerUp" in objSigName[p]):
            scaled_2017_tg = objSig[p].Clone("signal_Ch2017"+ext_substracted+"_triggerUp")
            scaled_2018_tg = objSig[p].Clone("signal_Ch2018"+ext_substracted+"_triggerUp")
            scaled_2017_tg.Scale(lumi2017/lumitot)
            scaled_2018_tg.Scale(lumi2018/lumitot)
            scaled_2017_tg.Write()
            scaled_2018_tg.Write()
        if("triggerDown" in objSigName[p]):
            scaled_2017_tg_dn = objSig[p].Clone("signal_Ch2017"+ext_substracted+"_triggerDown")
            scaled_2018_tg_dn = objSig[p].Clone("signal_Ch2018"+ext_substracted+"_triggerDown")
            scaled_2017_tg_dn.Scale(lumi2017/lumitot)
            scaled_2018_tg_dn.Scale(lumi2018/lumitot)
            scaled_2017_tg_dn.Write()
            scaled_2018_tg_dn.Write()
        if("fpixUp" in objSigName[p]):
            scaled_2017_k = objSig[p].Clone("signal_Ch2017"+ext_substracted+"_fpixUp")
            scaled_2018_k = objSig[p].Clone("signal_Ch2018"+ext_substracted+"_fpixUp")
            scaled_2017_k.Scale(lumi2017/lumitot)
            scaled_2018_k.Scale(lumi2018/lumitot)
            scaled_2017_k.Write()
            scaled_2018_k.Write()
        if("fpixDown" in objSigName[p]):
            scaled_2017_k_dn = objSig[p].Clone("signal_Ch2017"+ext_substracted+"_fpixDown")
            scaled_2018_k_dn = objSig[p].Clone("signal_Ch2018"+ext_substracted+"_fpixDown")
            scaled_2017_k_dn.Scale(lumi2017/lumitot)
            scaled_2018_k_dn.Scale(lumi2018/lumitot)
            scaled_2017_k_dn.Write()
            scaled_2018_k_dn.Write()

        if("muTriggerUp" in objSigName[p]):
            scaled_2017_k = objSig[p].Clone("signal_Ch2017"+ext_substracted+"_muTriggerUp")
            scaled_2018_k = objSig[p].Clone("signal_Ch2018"+ext_substracted+"_muTriggerUp")
            scaled_2017_k.Scale(lumi2017/lumitot)
            scaled_2018_k.Scale(lumi2018/lumitot)
            scaled_2017_k.Write()
            scaled_2018_k.Write()
        if("muTriggerDown" in objSigName[p]):
            scaled_2017_k_dn = objSig[p].Clone("signal_Ch2017"+ext_substracted+"_muTriggerDown")
            scaled_2018_k_dn = objSig[p].Clone("signal_Ch2018"+ext_substracted+"_muTriggerDown")
            scaled_2017_k_dn.Scale(lumi2017/lumitot)
            scaled_2018_k_dn.Scale(lumi2018/lumitot)
            scaled_2017_k_dn.Write()
            scaled_2018_k_dn.Write()

        if("muRecoUp" in objSigName[p]):
            scaled_2017_k = objSig[p].Clone("signal_Ch2017"+ext_substracted+"_muRecoUp")
            scaled_2018_k = objSig[p].Clone("signal_Ch2018"+ext_substracted+"_muRecoUp")
            scaled_2017_k.Scale(lumi2017/lumitot)
            scaled_2018_k.Scale(lumi2018/lumitot)
            scaled_2017_k.Write()
            scaled_2018_k.Write()
        if("muRecoDown" in objSigName[p]):
            scaled_2017_k_dn = objSig[p].Clone("signal_Ch2017"+ext_substracted+"_muRecoDown")
            scaled_2018_k_dn = objSig[p].Clone("signal_Ch2018"+ext_substracted+"_muRecoDown")
            scaled_2017_k_dn.Scale(lumi2017/lumitot)
            scaled_2018_k_dn.Scale(lumi2018/lumitot)
            scaled_2017_k_dn.Write()
            scaled_2018_k_dn.Write()
        if("muIdUp" in objSigName[p]):
            scaled_2017_k = objSig[p].Clone("signal_Ch2017"+ext_substracted+"_muIdUp")
            scaled_2018_k = objSig[p].Clone("signal_Ch2018"+ext_substracted+"_muIdUp")
            scaled_2017_k.Scale(lumi2017/lumitot)
            scaled_2018_k.Scale(lumi2018/lumitot)
            scaled_2017_k.Write()
            scaled_2018_k.Write()
        if("muIdDown" in objSigName[p]):
            scaled_2017_k_dn = objSig[p].Clone("signal_Ch2017"+ext_substracted+"_muIdDown")
            scaled_2018_k_dn = objSig[p].Clone("signal_Ch2018"+ext_substracted+"_muIdDown")
            scaled_2017_k_dn.Scale(lumi2017/lumitot)
            scaled_2018_k_dn.Scale(lumi2018/lumitot)
            scaled_2017_k_dn.Write()
            scaled_2018_k_dn.Write()


    '''
    output_file.cd() 
    print(nominal2018)
    print(nominal2017)
    bin_syst_2018 = vary_histogram_bins(nominal2018, 10,2018)
    bin_syst_2017 = vary_histogram_bins(nominal2017, 60,2017)
    for i in range(len(bin_syst_2018)):
        bin_syst_2018[i].Write()
        bin_syst_2017[i].Write()
    '''
    output_file.Close()


if __name__ == "__main__":


    ptCUT = sys.argv[1]
    SearchRegion = sys.argv[2]

    if len(sys.argv) != 3:
        print("usage : python CombFilesMassShape.py <pT cut> <Search Region>")

    print("Merging files for Mass Shape Analysis \nversion = {}\npT cut ={}\nSearch Region ={}".format(VERSION,ptCUT,SearchRegion))

    input_files = [
        "V"+VERSION+"/data"+VERSION+"_pt"+ptCUT,
        #"V"+VERSION+"/PredMass_"+USED_DATE[:-1]
        "V"+VERSION+"/"+USED_DATE+"pt"+ptCUT
    ]

    ext_substracted = ""

    input_signals = "V"+VERSION+"/SignalMass_V"  + VERSION + SearchRegion+"_pT"+ptCUT

    output_direc = "V"+VERSION+"/MassShapeHistos_pT"+ptCUT+"_"+SearchRegion+"_V"+VERSION+"_Ih4p35/"
    
    if not os.path.exists(output_direc):
        os.makedirs(output_direc)
 
    input_sig_path = find_root_files_in_directory(input_signals)
    print("input sig path : ",input_sig_path)
    
    end = []
    for item in input_sig_path:
        parts = item.split('/')
        last_part = parts[-1].replace("_Sys.root",'')
        end.append(last_part)


    namesOut = [output_direc + "Histos_massShape_" + end[i] + ".root" for i in range(len(input_sig_path))]

    print("Output  names for histos mass shapes PER mass point  :")
    print(namesOut)
    input_sigs = [ROOT.TFile.Open(infile) for infile in input_sig_path]
    for i in range(len(input_sigs)):
        objs = [key.ReadObj() for key in input_sigs[i].GetListOfKeys()]
        objs_name = [key.GetName() for key in input_sigs[i].GetListOfKeys()]
        add_all_histograms_from_directories(input_files, objs,objs_name ,namesOut[i],SearchRegion,ptCUT,ext_substracted)
    
