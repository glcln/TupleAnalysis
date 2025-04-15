#!/bin/bash

version=$(python -c 'from USE_DATE import VERSION; print("V"+VERSION)') 

argB=$1
argC=$2

day=$(date +%d)
month=$(date +%B | tr '[:upper:]' '[:lower:]')
combined="$day$month"

dt=$(python -c "from USE_DATE import USED_DATE; print(USED_DATE)")
echo "Successfully imported the USE DATE as ${dt}"


ot="pt100"

base="/opt/sbg/cms/ui4_data1/rhaeberl/CMSSW_10_6_30/src/HSCPTreeAnalyzer/macros/Data_good/VATLAS_final_v3"

output_dir="${version}/${dt}${ot}"

mu2017_file="${base}/Mu2017_massCut_0_pT100_Vtof_final_atlas_ih0_beta0_allTests_corrected_oldError.root"
mu2018_file="${base}/Mu2018_massCut_0_pT100_Vtof_final_atlas_ih0_beta0_allTests.root"

echo "Running on singleMu 2017 and then 2018 sample, saving outputs to $output_dir"

python NoSigDataCR.py "$mu2017_file" "$output_dir"
python NoSigDataCR.py "$mu2018_file" "$output_dir" 
