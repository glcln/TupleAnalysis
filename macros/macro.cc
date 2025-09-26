{
    gSystem->Load("../libTools.so");

    TProof::Open("workers=1");   //change number of worker.

    ifstream ifile;
    ifile.open("/opt/sbg/cms/safe1/cms/gcoulon/CMSSW_14_0_20/src/TupleAnalysis/cfg/configFile.txt");
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
    chain = new TChain("HSCParticleAnalyzer/Events");

    if(dataset == "Gluino2000"){
        std::string pathData = "/opt/sbg/cms/ui3_data1/gcoulon/HSCP_prod/V10p0/";
        std::string fileNamesGluino2000[] = { (pathData+"V10p0.txt").c_str()};

        for (const std::string& fileName : fileNamesGluino2000) {
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


    std::string binning = std::to_string(tofcut) + "," + std::to_string(ptcut) + "," + std::to_string(etabins) + "," + std::to_string(ihbins) + "," + std::to_string(pbins) + "," + std::to_string(massbins) + "," + std::to_string(masscut)  + "," +std::to_string(tofbins) + ","+std::to_string(fpixbins) + "," + dataset + "," + version;

    std::cout << "Running over dataset : " << dataset << std::endl;
    std::cout << "        code version : " << version << std::endl; 
    std::cout << "Defining regions A,B,C,D with pT cut = " << ptcut << std::endl;
    std::cout << "                          or tof cut = " << tofcut << std::endl;


    chain->SetProof();
    chain->Process("HSCPSelector.C+",binning.c_str());

    delete chain;
}
