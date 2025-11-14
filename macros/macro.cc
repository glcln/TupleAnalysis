{
    gSystem->Load("../libTools.so");

    TProof::Open("workers=1");   //change number of worker.

    ifstream ifile;
    ifile.open("/opt/sbg/cms/safe1/cms/gcoulon/CMSSW_14_0_21/src/TupleAnalysis/cfg/configFile.txt");
    if(!ifile) std::cout << "Error when opening config file " <<  std::endl;
    std::string line;
    std::string dataset;
    std::string version;
    int etabins, ihbins, pbins, massbins, tofbins, fpixbins;
    double ptcut;
    double tofcut;
    int masscut;
    std::cout << std::endl;
    std::cout << "   Reading config file: " << std::endl;
    std::cout << endl;
    std::cout << "TOF cut - pT cut - eta bins - ih bins - p bins - mass bins - massCut - TOFbins - FPIXbins -  type - version" << std::endl;
    while(std::getline(ifile,line))
    {
        if(strncmp(line.c_str(),"#",1)==0) continue;
        std::cout << line << std::endl;
        std::stringstream ss(line);
        ss >> tofcut >> ptcut >> etabins >> ihbins >> pbins >> massbins >> masscut >> tofbins >> fpixbins >> dataset >> version;
    }
    ifile.close();
    std::cout << std::endl;

    TChain* chain;
    // TO BE CHANGED IF NEEDED
    if(dataset == "Gluino2000_miniAOD_Mu50") {
        chain = new TChain("HSCPMiniAODAnalyzer/Events");
        chain->AddFile("/opt/sbg/cms/safe1/cms/gcoulon/CMSSW_14_0_21/src/output_SameminiAOD.root");
    }
    else if (dataset == "Gluino2000_AOD_Mu50") {
        chain = new TChain("HSCPFullAODAnalyzer/Events");
        chain->AddFile("/opt/sbg/cms/safe1/cms/gcoulon/CMSSW_14_0_21/src/output_SameAOD.root");
    }

    else if(dataset == "Gluino2000_miniAOD_FULL_Mu50") {
        chain = new TChain("HSCPMiniAODAnalyzer/Events");
        chain->AddFile("/opt/sbg/cms/ui3_data1/gcoulon/HSCP_prod/V11p11/Gluino2000_miniAOD.root");
    }
    else if (dataset == "Gluino2000_AOD_FULL_Mu50") {
        chain = new TChain("HSCPFullAODAnalyzer/Events");
        chain->AddFile("/opt/sbg/cms/ui3_data1/gcoulon/HSCP_prod/V11p11/Gluino2000_AOD.root");
    }

    else if(dataset == "Gluino2000_miniAOD_FULL_MET") {
        chain = new TChain("HSCPMiniAODAnalyzer/Events");
        chain->AddFile("/opt/sbg/cms/ui3_data1/gcoulon/HSCP_prod/V11p12/Gluino2000_miniAOD.root");
    }
    else if (dataset == "Gluino2000_AOD_FULL_MET") {
        chain = new TChain("HSCPFullAODAnalyzer/Events");
        chain->AddFile("/opt/sbg/cms/ui3_data1/gcoulon/HSCP_prod/V11p12/Gluino2000_AOD.root");
    }

    else if (dataset == "Data2018_miniAOD") {
        chain = new TChain("HSCPMiniAODAnalyzer/Events");
        chain->AddFile("/opt/sbg/cms/safe1/cms/gcoulon/CMSSW_14_0_21/src/Mu_Run2.root");
    }
    else if (dataset == "Data2022_miniAOD") {
        chain = new TChain("HSCPMiniAODAnalyzer/Events");
        chain->AddFile("/opt/sbg/cms/safe1/cms/gcoulon/CMSSW_14_0_21/src/Mu_Run3.root");
    }

    else {
        std::cout << "Dataset not recognized. Exiting." << std::endl;
        return;
    }


    std::string binning = std::to_string(tofcut) + "," + std::to_string(ptcut) + "," + std::to_string(etabins) + "," + std::to_string(ihbins) + "," + std::to_string(pbins) + "," + std::to_string(massbins) + "," + std::to_string(masscut)  + "," +std::to_string(tofbins) + ","+std::to_string(fpixbins) + "," + dataset + "," + version;

    std::cout << "Running over dataset : " << dataset << std::endl;
    std::cout << "        code version : " << version << std::endl; 
    std::cout << "Defining regions A,B,C,D with pT cut = " << ptcut << std::endl;
    std::cout << "                          or tof cut = " << tofcut << std::endl;


    chain->SetProof();
    chain->Process("HSCPSelector.C+",binning.c_str());

    delete chain;
}
