HWWSpinAna
==========

---------------------------------------------
I. ** Setting up the area 
---------------------------------------------


1) Start from a CMSSW release (CMSSW_6_1_1)


setenv SCRAM_ARCH slc5_amd64_gcc472

cmsrel CMSSW_6_1_1

cd CMSSW_6_1_1/src/

cmsenv

git clone

git clone https://github.com/chmartin/HiggsAnalysis-CombinedLimit.git HiggsAnalysis/CombinedLimit

git clone https://github.com/drkovalskyi/Smurf

git clone https://github.com/rebecacern/HWWSpinAna

cd HWWSpinAna/


2) start.sh will download the datacards used in the combination in the summer of 2013 from svn and the proper PDF script. 
Then it will recompile and bring you back to the folder.

sh start.sh


---------------------------------------------
II. ** Test the framework, without interference using the old cards 
---------------------------------------------


1) v1_combine.sh will combine the datacards at 7 and 8TeV into one (no
interference), build the workspace and run combine

sh v1_combine.sh


2) For doing the plot:

root -q -b plotScan1D.C

You can see it like this:

display v1_output/1D_exp.png

---------------------------------------------
III. ** Test the framework, with interference, building the PDF using the old cards 
---------------------------------------------

Now for doing the PDF version, the datacard needs to be adapted.
We need a modified datacard, hwwof_0j_inter_model.txt is a good
example.

After channel 1 (7TeV)

shapes ggH ch1 test.root w:ggH_ w:$PROCESS_$SYSTEMATIC

After channel 2 (8TeV)

shapes ggH ch2 test2.root w:ggH_ w:$PROCESS_$SYSTEMATIC

+ all shape1 instead of "shape" for signals (major modification, script may be needed)

However, to test it quickly:

scp hwwof_0j_inter_model.txt hwwof_0j_inter.txt

works


1) pdf_combine.sh will prepare the rootfiles with the PDF for 7 and 8TeV,
prepare the workspace and run combine.

sh pdf_combine.sh

2) for the plot the same script works (adapting the folder to look, should be fixed soon)

root -q -b plotScan1D.C

Have a look:

display v2_output/1D_exp.png


---------------------------------------------
IV. ** Check the new samples 
---------------------------------------------

In this bundle there's also a folder called "code", it is for testing the tuples (in the MIT cluster)
