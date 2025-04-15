import ROOT
import os

def scale_histograms_in_file(file_path, scale_factor):
    root_file = ROOT.TFile(file_path, "UPDATE")
    keys = root_file.GetListOfKeys()
    key_names = [key.GetName() for key in keys]
    for key_name in key_names:
        obj = root_file.Get(key_name)
        if isinstance(obj, ROOT.TH1):
            obj.Scale(scale_factor)
            obj.Write("", ROOT.TObject.kOverwrite)

    root_file.Close()

def process_all_files_in_directory(directory, scale_factor):
    for filename in os.listdir(directory):
        if filename.endswith(".root"):
            print("Opened {}".format(filename))
            file_path = os.path.join(directory, filename)
            scale_histograms_in_file(file_path, scale_factor)
            print("Done with the rescaling")
 
if __name__ == "__main__":
    directory = "./V80p11/MassShapeHistos_pT100_SR1_V80p11_PrevisionRun3"
    scale_factor = 3
    process_all_files_in_directory(directory, scale_factor)

