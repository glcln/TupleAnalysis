{
    gSystem->Load("../libTools.so");

    ifstream ifile;
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

    TChain* chain;
    if(dataset == "Gluino2000_miniAOD_Mu50") {
        chain = new TChain("HSCPMiniAODAnalyzer/Events");
        chain->AddFile("/opt/sbg/cms/safe1/cms/gcoulon/CMSSW_15_0_13_patch1/src/output_SameminiAOD.root");
    }
    else if (dataset == "Gluino2000_AOD_Mu50") {
        chain = new TChain("HSCPFullAODAnalyzer/Events");
        chain->AddFile("/opt/sbg/cms/safe1/cms/gcoulon/CMSSW_15_0_13_patch1/src/output_SameAOD.root");
    }

    if (dataset == "DataMET_2024_test_miniAOD") {
       chain = new TChain("HSCPMiniAODAnalyzer/Events");
       std::string pathData = "/opt/sbg/cms/ui3_data1/gcoulon/HSCP_prod/V12p20/";
       std::string fileNames[] = { (pathData+"V12p20.txt").c_str()};
       
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
    else if(dataset == "Gluino2000_Run2_MET") {
        chain = new TChain("HSCPMiniAODAnalyzer/Events");
        chain->AddFile("/opt/sbg/cms/ui3_data1/gcoulon/HSCP_prod/V13p0/Gluino2000_Run2_vcorr.root");
    }
    
    else if (dataset == "Gluino2000_AOD_FULL_Mu50") {
        chain = new TChain("HSCPFullAODAnalyzer/Events");
        chain->AddFile("/opt/sbg/cms/ui3_data1/gcoulon/HSCP_prod/V13p0/Gluino2000_Run2_vcorr_AOD.root");
    }
    else if (dataset == "Gluino2000_miniAOD_FULL_Mu50") {
        chain = new TChain("HSCPMiniAODAnalyzer/Events");
        chain->AddFile("/opt/sbg/cms/ui3_data1/gcoulon/HSCP_prod/V13p0/Gluino2000_Run2_vcorr.root");
    }

    else if(dataset == "GluinoRun2_miniAOD_FULL") {
       chain = new TChain("HSCPMiniAODAnalyzer/Events");
       std::string pathData = "/opt/sbg/cms/ui3_data1/gcoulon/HSCP_prod/V13p0/";
       std::string fileNames[] = { (pathData+"V13p0.txt").c_str()};
       
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


    else if(dataset == "TTbar2024_partial") {
       chain = new TChain("HSCPMiniAODAnalyzer/Events");
       std::string pathData = "/opt/sbg/cms/ui3_data1/gcoulon/HSCP_prod/BKG/";
       std::string fileNames[] = { (pathData+"V15p1.txt").c_str()};
       
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
    

    else if (dataset == "Data2018_miniAOD") {
        chain = new TChain("HSCPMiniAODAnalyzer/Events");
        chain->AddFile("/opt/sbg/cms/safe1/cms/gcoulon/CMSSW_15_0_13_patch1/src/Mu_Run2.root");
    }
    else if (dataset == "Data2022_miniAOD") {
        chain = new TChain("HSCPMiniAODAnalyzer/Events");
        chain->AddFile("/opt/sbg/cms/safe1/cms/gcoulon/CMSSW_15_0_13_patch1/src/Mu_Run3.root");
    }

    else {
        std::cout << "Dataset not recognized. Exiting." << std::endl;
        return;
    }


    std::string binning = std::to_string(ptcut) + "," + std::to_string(etabins) + "," + std::to_string(ihbins) + ","
                        + std::to_string(pbins) + "," + std::to_string(massbins) + "," + std::to_string(masscut) + ","
                        + std::to_string(fpixbins) + "," + dataset + "," + version;

    std::cout << "Running over dataset : " << dataset << std::endl;
    std::cout << "        code version : " << version << std::endl; 
    std::cout << "Defining regions A,B,C,D with pT cut = " << ptcut << std::endl;

    chain->Process("HSCPSelector.C+",binning.c_str());

    delete chain;
}
