import array
import ROOT


max_fit = 4000
max_CR_fit = 980
lowFitV = 70


rebinning = array.array('d', [0.0, 10.0, 20.0, 30.0, 40.0, 50.0, 60.0,70.0, 80.0,90.0,100.0,110.0, 120.0,130.0,140.0,155.0,170.0,190.0,210.0,225.0,240.0,260.0,290.0,320.0,350.0,400.0,460.0,6000.0])

sizeRebinning=len(rebinning)-1
max_rebin = max(rebinning)
