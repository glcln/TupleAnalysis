{
    gSystem->Load("../libTools.so");
    ROOT::EnableImplicitMT(4);

    ifstream ifile;
    // /opt/sbg/cms/safe1/cms/gcoulon
    ifile.open("/opt/sbg/cms/safe1/cms/gcoulon/CMSSW_15_0_13_patch1/src/TupleAnalysis/cfg/configFile.txt");
    if(!ifile) std::cout << "Error when opening config file " <<  std::endl;
    std::string line;
    std::string dataset;
    std::string version;
    int etabins, ihbins, pbins, massbins, fpixbins;
    double ptcut;
    int masscut;
    std::cout << std::endl;
    std::cout << "   Reading config file: " << std::endl;
    std::cout << endl;
    std::cout << "pT cut - eta bins - ih bins - p bins - mass bins - massCut - FPIXbins -  type - version" << std::endl;
    while(std::getline(ifile,line))
    {
        if(strncmp(line.c_str(),"#",1)==0) continue;
        std::cout << line << std::endl;
        std::stringstream ss(line);
        ss >> ptcut >> etabins >> ihbins >> pbins >> massbins >> masscut >> fpixbins >> dataset >> version;
    }
    ifile.close();
    std::cout << std::endl;

    std::vector<std::string> QCDnames = {
        "QCD2024_mu_pt15to20",
        "QCD2024_mu_pt20to30",
        "QCD2024_mu_pt30to50",
        "QCD2024_mu_pt50to80",
        "QCD2024_mu_pt80to120",
        "QCD2024_mu_pt120to170",
        "QCD2024_mu_pt170to300",
        "QCD2024_mu_pt300to470",
        "QCD2024_mu_pt470to600",
        "QCD2024_mu_pt600to800",
        "QCD2024_mu_pt800to1000",
        "QCD2024_mu_pt1000"
    };

    std::vector<std::string> Wjetsnames = {
        "Wjets2024_1J_pt40to100",
        "Wjets2024_1J_pt100to200",
        "Wjets2024_1J_pt200to400",
        "Wjets2024_1J_pt400to600",
        "Wjets2024_1J_pt600",
        "Wjets2024_2J_pt40to100",
        "Wjets2024_2J_pt100to200",
        "Wjets2024_2J_pt200to400",
        "Wjets2024_2J_pt400to600",
        "Wjets2024_2J_pt600",
    };

    std::vector<std::string> JetMETnames = {
        "JetMET2024C",
        "JetMET2024D",
        "JetMET2024E",
        "JetMET2024F",
        "JetMET2024G",
        "JetMET2024H",
        "JetMET2024I"
    };

    std::vector<std::string> Munames = {
        "Mu2024C",
        "Mu2024D",
        "Mu2024E",
        "Mu2024F",
        "Mu2024G",
        "Mu2024H",
        "Mu2024I"
    };

    std::vector<std::string> MuonEGnames = {
        "MuonEG2024C",
        "MuonEG2024D",
        "MuonEG2024E",
        "MuonEG2024F",
        "MuonEG2024G",
        "MuonEG2024H",
        "MuonEG2024I",
    };

    std::vector<TString> GluinonamesPythia = {
        "Gluino_Run3_MET_pythia_1000",
        "Gluino_Run3_MET_pythia_1200",
        "Gluino_Run3_MET_pythia_1400",
        "Gluino_Run3_MET_pythia_1600",
        "Gluino_Run3_MET_pythia_1800",
        "Gluino_Run3_MET_pythia_2000",
        "Gluino_Run3_MET_pythia_2200",
        "Gluino_Run3_MET_pythia_2400",
        "Gluino_Run3_MET_pythia_2600"
    };

    std::vector<TString> GluinonamesMadgraph = {
        "Gluino_Run3_MET_madgraph_1100",
        "Gluino_Run3_MET_madgraph_1200",
        "Gluino_Run3_MET_madgraph_1300",
        "Gluino_Run3_MET_madgraph_1400",
        "Gluino_Run3_MET_madgraph_1600",
        "Gluino_Run3_MET_madgraph_1800",
        "Gluino_Run3_MET_madgraph_2000",
        "Gluino_Run3_MET_madgraph_2200",
        "Gluino_Run3_MET_madgraph_2400",
        "Gluino_Run3_MET_madgraph_2600"
    };

    std::vector<TString> GluinoInputnamesPythia = {
        Form("Par-M-1000_Code%s_merged.root", version.c_str()),
        Form("Par-M-1200_Code%s_merged.root", version.c_str()),
        Form("Par-M-1400_Code%s_merged.root", version.c_str()),
        Form("Par-M-1600_Code%s_merged.root", version.c_str()),
        Form("Par-M-1800_Code%s_merged.root", version.c_str()),
        Form("Par-M-2000_Code%s_merged.root", version.c_str()),
        Form("Par-M-2200_Code%s_merged.root", version.c_str()),
        Form("Par-M-2400_Code%s_merged.root", version.c_str()),
        Form("Par-M-2600_Code%s_merged.root", version.c_str())
    };

    std::vector<TString> GluinoInputnamesMadgraph = {
        Form("Par-M-1100_Code%s_merged.root", version.c_str()),
        Form("Par-M-1200_Code%s_merged.root", version.c_str()),
        Form("Par-M-1300_Code%s_merged.root", version.c_str()),
        Form("Par-M-1400_Code%s_merged.root", version.c_str()),
        Form("Par-M-1600_Code%s_merged.root", version.c_str()),
        Form("Par-M-1800_Code%s_merged.root", version.c_str()),
        Form("Par-M-2000_Code%s_merged.root", version.c_str()),
        Form("Par-M-2200_Code%s_merged.root", version.c_str()),
        Form("Par-M-2400_Code%s_merged.root", version.c_str()),
        Form("Par-M-2600_Code%s_merged.root", version.c_str())
    };



    TChain* chain;
    if(dataset == "Gluino2000_miniAOD_Mu50") {
        chain = new TChain("HSCPMiniAODAnalyzer/Events");
        chain->AddFile("/safe/ui3_1/cms/gcoulon/CMSSW_15_0_13_patch1/src/output_SameminiAOD.root");
    }
    else if (dataset == "Gluino2000_AOD_Mu50") {
        chain = new TChain("HSCPFullAODAnalyzer/Events");
        chain->AddFile("/safe/ui3_1/cms/gcoulon/CMSSW_15_0_13_patch1/src/output_SameAOD.root");
    }

    if (dataset == "DataMET_2024_test_miniAOD") {
       chain = new TChain("HSCPMiniAODAnalyzer/Events");
       std::string pathData = "/opt/sbg/cms/ui3_data1/gcoulon/HSCP_prod/V12p20/";
       std::string fileNames[] = { (pathData + "V12p20.txt").c_str()};
       
       for (const std::string& fileName : fileNames) {
            std::ifstream file(fileName);
            if (!file.is_open()) {
                std::cerr << "Failed to open file: " << fileName << std::endl;
                continue;
            }
            std::string line;
            while (std::getline(file, line)) {
                if (!line.empty() && line.back() == '\n') {
                   line.pop_back();
                }
                chain->AddFile(line.c_str());
            }
            file.close();
        }
    }
    

    else if(dataset == "Gluino2000_Run2_METtrgEff_AOD") {
        chain = new TChain("HSCPFullAODAnalyzer/Events");
        chain->AddFile("/opt/sbg/cms/ui3_data1/gcoulon/HSCP_prod/V13p0/Gluino2000_Run2_vcorr_AOD.root");
    }
    else if(dataset == "Gluino2000_Run2_METtrgEff") {
        chain = new TChain("HSCPMiniAODAnalyzer/Events");
        chain->AddFile("/opt/sbg/cms/ui3_data1/gcoulon/HSCP_prod/V13p0/Gluino2000_Run2_vcorr.root");
    }

    else if(dataset == "Gluino2000_Run2_MET_AOD") {
        chain = new TChain("HSCPFullAODAnalyzer/Events");
        chain->AddFile("/opt/sbg/cms/ui3_data1/gcoulon/HSCP_prod/V13p0/Gluino2000_Run2_vcorr_AOD.root");
    }
    
    
    else if (dataset == "Gluino2000_AOD_FULL_Mu50") {
        chain = new TChain("HSCPFullAODAnalyzer/Events");
        chain->AddFile("/opt/sbg/cms/ui3_data1/gcoulon/HSCP_prod/V13p0/Gluino2000_Run2_vcorr_AOD.root");
    }
    else if (dataset == "Gluino2000_miniAOD_FULL_Mu50") {
        chain = new TChain("HSCPMiniAODAnalyzer/Events");
        chain->AddFile("/opt/sbg/cms/ui3_data1/gcoulon/HSCP_prod/V13p0/Gluino2000_Run2_vcorr.root");
    }


    else if (dataset.find("Gluino_Run3") != std::string::npos) {
        if (version=="V19p0") {
            for (size_t i = 0; i < GluinonamesPythia.size(); ++i) {
                if (dataset == GluinonamesPythia[i]) {
                    chain = new TChain("HSCPMiniAODAnalyzer/Events");
                    chain->AddFile(Form("/opt/sbg/cms/ui3_data1/gcoulon/HSCP_prod/SIGNAL/Gluino_Run3_pythia/%s", GluinoInputnamesPythia[i].Data()));
                }
            }
        }
        else if (version=="V19p1") {
            for (size_t i = 0; i < GluinonamesMadgraph.size(); ++i) {
                if (dataset == GluinonamesMadgraph[i]) {
                    chain = new TChain("HSCPMiniAODAnalyzer/Events");
                    chain->AddFile(Form("/opt/sbg/cms/ui3_data1/gcoulon/HSCP_prod/SIGNAL/Gluino_Run3_madgraph/%s", GluinoInputnamesMadgraph[i].Data()));
                }
            }
        }
    }
    


    else if (dataset.find("JetMET2024") != std::string::npos) {
        for (size_t i = 0; i < JetMETnames.size(); ++i) {
            if (dataset == JetMETnames[i]) {

                chain = new TChain("HSCPMiniAODAnalyzer/Events");

                std::string pathData = "/opt/sbg/cms/ui3_data1/gcoulon/HSCP_prod/JetMET2024/";
                std::string fileName = pathData + "V12p24" + std::to_string(i) + ".txt";

                std::ifstream file(fileName);
                if (!file.is_open()) {
                    std::cerr << "Failed to open file: " << fileName << std::endl;
                    break;
                }

                std::string line;
                while (std::getline(file, line)) {
                    if (!line.empty()) chain->AddFile(line.c_str());
                }

                file.close();
                break;
            }
        }
    }

    else if (dataset.find("Mu2024") != std::string::npos) {
        for (size_t i = 0; i < Munames.size(); ++i) {
            if (dataset == Munames[i]) {

                chain = new TChain("HSCPMiniAODAnalyzer/Events");

                std::string pathData = "/opt/sbg/cms/ui3_data1/gcoulon/HSCP_prod/Mu2024/";
                std::string fileName = pathData + "V18p0" + std::to_string(i) + ".txt";

                std::ifstream file(fileName);
                if (!file.is_open()) {
                    std::cerr << "Failed to open file: " << fileName << std::endl;
                    break;
                }

                std::string line;
                while (std::getline(file, line)) {
                    if (!line.empty()) chain->AddFile(line.c_str());
                }

                file.close();
                break;
            }
        }
    }

    else if (dataset.find("MuonEG2024") != std::string::npos) {
        for (size_t i = 0; i < MuonEGnames.size(); ++i) {
            if (dataset == MuonEGnames[i]) {

                chain = new TChain("HSCPMiniAODAnalyzer/Events");

                std::string pathData = "/opt/sbg/cms/ui3_data1/gcoulon/HSCP_prod/MuonEG2024/";
                std::string fileName = pathData + "V17p3" + std::to_string(i) + ".txt";

                std::ifstream file(fileName);
                if (!file.is_open()) {
                    std::cerr << "Failed to open file: " << fileName << std::endl;
                    break;
                }

                std::string line;
                while (std::getline(file, line)) {
                    if (!line.empty()) chain->AddFile(line.c_str());
                }

                file.close();
                break;
            }
        }
    }

    else if (dataset == "TestMuonEG") {
        chain = new TChain("HSCPMiniAODAnalyzer/Events");
            std::string pathData = "/opt/sbg/cms/ui3_data1/gcoulon/HSCP_prod/MuonEG2024/";
            std::string fileName = pathData + "testMuonEG.txt";

            std::ifstream file(fileName);
            if (!file.is_open())  std::cerr << "Failed to open file: " << fileName << std::endl;

            std::string line;
            while (std::getline(file, line)) {
                if (!line.empty()) chain->AddFile(line.c_str());
            }

            file.close();
    }

    else if (dataset == "TestMuon2024") {
        chain = new TChain("HSCPMiniAODAnalyzer/Events");
            std::string pathData = "/opt/sbg/cms/ui3_data1/gcoulon/HSCP_prod/Mu2024/";
            std::string fileName = pathData + "testMu2024.txt";

            std::ifstream file(fileName);
            if (!file.is_open())  std::cerr << "Failed to open file: " << fileName << std::endl;

            std::string line;
            while (std::getline(file, line)) {
                if (!line.empty()) chain->AddFile(line.c_str());
            }

            file.close();
    }

    else if (dataset == "TestMET2024") {
        chain = new TChain("HSCPMiniAODAnalyzer/Events");
            std::string pathData = "/opt/sbg/cms/ui3_data1/gcoulon/HSCP_prod/JetMET2024/";
            std::string fileName = pathData + "testJetMET.txt";

            std::ifstream file(fileName);
            if (!file.is_open())  std::cerr << "Failed to open file: " << fileName << std::endl;

            std::string line;
            while (std::getline(file, line)) {
                if (!line.empty()) chain->AddFile(line.c_str());
            }

            file.close();
    }
    else if (dataset == "TestTTbar2024") {
        chain = new TChain("HSCPMiniAODAnalyzer/Events");
            std::string pathData = "/opt/sbg/cms/ui3_data1/gcoulon/HSCP_prod/BKG/TTbar2024/";
            std::string fileName = pathData + "testTTbar.txt";

            std::ifstream file(fileName);
            if (!file.is_open())  std::cerr << "Failed to open file: " << fileName << std::endl;

            std::string line;
            while (std::getline(file, line)) {
                if (!line.empty()) chain->AddFile(line.c_str());
            }

            file.close();
    }
    else if (dataset == "TestWjets") {
        chain = new TChain("HSCPMiniAODAnalyzer/Events");
            std::string pathData = "/opt/sbg/cms/ui3_data1/gcoulon/HSCP_prod/BKG/Wjets2024/";
            std::string fileName = pathData + "testWjets.txt";

            std::ifstream file(fileName);
            if (!file.is_open())  std::cerr << "Failed to open file: " << fileName << std::endl;

            std::string line;
            while (std::getline(file, line)) {
                if (!line.empty()) chain->AddFile(line.c_str());
            }

            file.close();
    }



    else if(dataset == "Gluino2000_Run2_MET") {
        chain = new TChain("HSCPMiniAODAnalyzer/Events");
        chain->AddFile("/opt/sbg/cms/ui3_data1/gcoulon/HSCP_prod/GluinoRun2corr/Gluino2000_Run2_vcorr.root");
    }

    else if(dataset == "GluinoRun2_miniAOD_FULL") {
       chain = new TChain("HSCPMiniAODAnalyzer/Events");
       std::string pathData = "/opt/sbg/cms/ui3_data1/gcoulon/HSCP_prod/GluinoRun2corr/";
       std::string fileNames[] = { (pathData + "V13p0.txt").c_str()};
       
       for (const std::string& fileName : fileNames) {
            std::ifstream file(fileName);
            if (!file.is_open()) {
                std::cerr << "Failed to open file: " << fileName << std::endl;
                continue;
            }
            std::string line;
            while (std::getline(file, line)) {
                if (!line.empty() && line.back() == '\n') {
                   line.pop_back();
                }
                chain->AddFile(line.c_str());
            }
            file.close();
        }
    }


    else if(dataset == "TTbar2024") {
       chain = new TChain("HSCPMiniAODAnalyzer/Events");
       std::string pathData = "/opt/sbg/cms/ui3_data1/gcoulon/HSCP_prod/BKG/TTbar2024/";
       std::string fileNames[] = { (pathData + "V15p5.txt").c_str()};
       
       for (const std::string& fileName : fileNames) {
            std::ifstream file(fileName);
            if (!file.is_open()) {
                std::cerr << "Failed to open file: " << fileName << std::endl;
                continue;
            }
            std::string line;
            while (std::getline(file, line)) {
                if (!line.empty() && line.back() == '\n') {
                   line.pop_back();
                }
                chain->AddFile(line.c_str());
            }
            file.close();
        }
    }

    // else if in the dataset names there is "QCD2024"
    else if (dataset.find("QCD2024") != std::string::npos) {
        for (size_t i = 0; i < QCDnames.size(); ++i) {
            if (dataset == QCDnames[i]) {

                chain = new TChain("HSCPMiniAODAnalyzer/Events");

                std::string pathData = "/opt/sbg/cms/ui3_data1/gcoulon/HSCP_prod/BKG/QCD2024/";
                std::string fileName = pathData + "V16p0" + std::to_string(i + 1) + ".txt";

                std::ifstream file(fileName);
                if (!file.is_open()) {
                    std::cerr << "Failed to open file: " << fileName << std::endl;
                    break;
                }

                std::string line;
                while (std::getline(file, line)) {
                    if (!line.empty()) chain->AddFile(line.c_str());
                }

                file.close();
                break;
            }
        }
    }

    else if (dataset.find("Wjets2024") != std::string::npos) {
        for (size_t i = 0; i < Wjetsnames.size(); ++i) {
            if (dataset == Wjetsnames[i]) {

                chain = new TChain("HSCPMiniAODAnalyzer/Events");

                std::string pathData = "/opt/sbg/cms/ui3_data1/gcoulon/HSCP_prod/BKG/Wjets2024/";
                std::string fileName = pathData + "V14p60" + std::to_string(i + 1) + ".txt";

                std::ifstream file(fileName);
                if (!file.is_open()) {
                    std::cerr << "Failed to open file: " << fileName << std::endl;
                    break;
                }

                std::string line;
                while (std::getline(file, line)) {
                    if (!line.empty()) chain->AddFile(line.c_str());
                }

                file.close();
                break;
            }
        }
    }


    else {
        std::cout << "Dataset not recognized. Exiting." << std::endl;
        return;
    }


    if (!chain) {
        std::cerr << "ERROR: chain is null before processing!" << std::endl;
        return;
    }


    std::string binning = std::to_string(ptcut) + "," + std::to_string(etabins) + "," + std::to_string(ihbins) + ","
                        + std::to_string(pbins) + "," + std::to_string(massbins) + "," + std::to_string(masscut) + ","
                        + std::to_string(fpixbins) + "," + dataset + "," + version;

    std::cout << "Running over dataset : " << dataset << std::endl;
    std::cout << "        code version : " << version << std::endl; 
    std::cout << "Defining regions A,B,C,D with pT cut = " << ptcut << std::endl;

    std::cout << "Implicit MT enabled: " << ROOT::IsImplicitMTEnabled() << std::endl;

    chain->SetCacheSize(200 * 1024 * 1024); // 200 MB
    chain->AddBranchToCache("*", true);
    
    chain->Process("HSCPSelector.C+",binning.c_str());

    delete chain;
}
