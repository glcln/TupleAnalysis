#!/bin/bash

./make_pred.sh
python new_toyObs.py
./make_signal.sh 
python CombFilesMassShape.py 100 SR1
