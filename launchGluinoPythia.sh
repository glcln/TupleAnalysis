#!/bin/bash

CONFIG=/safe/ui3_1/cms/gcoulon/CMSSW_15_0_13_patch1/src/TupleAnalysis/cfg/configFile.txt

# Build the selector
cd python
python3 CreateSelector.py
cd ../macros

# Collect line numbers of all commented lines containing " Gluino_Run3_MET_pythia"
# Format of grep -n output: <line_number>:<line_content>
mapfile -t Gluino_LINES < <(grep -n '^#.* Gluino_Run3_MET_pythia' "$CONFIG" | cut -d: -f1)

N_LINES=${#Gluino_LINES[@]}
echo "Found $N_LINES  Gluino_Run3_MET_pythia samples"

# Loop over each  Gluino_Run3_MET_pythia line
for ((i=0; i<N_LINES; i++)); do
    LINE=${Gluino_LINES[$i]}

    echo "========================================"
    echo "Running  Gluino_Run3_MET_pythia sample $((i+1)) / $N_LINES"
    echo "Activating config line number: $LINE"
    echo "========================================"

    # 1) Comment out all non-header active lines
    #    This guarantees that only one dataset is active at a time
    sed -i '/^#pT cut/! s/^[^#]/#&/' "$CONFIG"

    # 2) Uncomment the selected  Gluino_Run3_MET_pythia line
    sed -i "${LINE}s/^#//" "$CONFIG"

    # Optional debug: show the active configuration line
    echo "Active configuration:"
    grep -v '^#' "$CONFIG"

    # 3) Run the ROOT macro
    time root -l -q -b macro.cc

    # 4) Clean ROOT auto-generated selector files
    rm -f ../macros/HSCPSelector_C*
done