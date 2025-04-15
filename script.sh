#!/bin/bash

CONFIG_FILE="cfg/configFile.txt"
#For Tau' 1e and 2e
#NUM_ITERATIONS=18

#For Stau
NUM_ITERATIONS=9 

#For MC ZMUMU
#NUM_ITERATIONS=5

#For both
#NUM_ITERATIONS=27

for ((i=0; i<$NUM_ITERATIONS; i++)); do
    # Run the compile and launch scripts
    ./compile.sh
    ./launch.sh
    # Modify config file
    CURRENT_LINE=$(grep -n "^[^#]" $CONFIG_FILE | cut -d : -f 1 | head -n 1)
    if [ ! -z "$CURRENT_LINE" ]; then
        sed -i "${CURRENT_LINE}s/^/#/" $CONFIG_FILE
        NEXT_LINE=$((CURRENT_LINE + 1))
        sed -i "${NEXT_LINE}s/^#//" $CONFIG_FILE
        echo "Next line to be processed:"
        sed -n "${NEXT_LINE}p" $CONFIG_FILE
    fi
done
