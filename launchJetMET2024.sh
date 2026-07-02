#!/bin/bash

CONFIG=/safe/ui3_1/cms/gcoulon/CMSSW_15_0_13_patch1/src/TupleAnalysis/cfg/configFile.txt

# Build the selector
cd python
python3 CreateSelector.py
cd ../macros

# Collect line numbers of all commented lines containing "JetMET2024"
# Format of grep -n output: <line_number>:<line_content>
mapfile -t JetMET_LINES < <(grep -n '^#.*JetMET2024' "$CONFIG" | cut -d: -f1)

N_LINES=${#JetMET_LINES[@]}
echo "Found $N_LINES JetMET2024 samples"

# Loop over each JetMET2024 line
for ((i=0; i<N_LINES; i++)); do
    LINE=${JetMET_LINES[$i]}

    echo "========================================"
    echo "Running JetMET2024 sample $((i+1)) / $N_LINES"
    echo "Activating config line number: $LINE"
    echo "========================================"

    # 1) Comment out all non-header active lines
    #    This guarantees that only one dataset is active at a time
    sed -i '/^#pT cut/! s/^[^#]/#&/' "$CONFIG"

    # 2) Uncomment the selected JetMET2024 line
    sed -i "${LINE}s/^#//" "$CONFIG"

    # Optional debug: show the active configuration line
    echo "Active configuration:"
    grep -v '^#' "$CONFIG"

    # 3) Run the ROOT macro
    time root -l -q -b macro.cc

    # 4) Clean ROOT auto-generated selector files
    rm -f ../macros/HSCPSelector_C*
done