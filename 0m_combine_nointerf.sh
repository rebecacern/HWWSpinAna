FOLDER='v1_0m'

echo "~** This script will run version 1, no interference term **~"
	mkdir $FOLDER

echo "[Info:] building the workspace" 

	text2workspace.py -m 125.6 datacard.txt -P HiggsAnalysis.CombinedLimit.HiggsJPC:twoHypothesisHiggs --PO=muFloating -o $FOLDER/fixedMu.root 

echo "[Info:] workspace fixedMu.root created"
echo "[Info:] running combine"

	combine -M MultiDimFit v1_output/fixedMu.root --algo=grid --points 100 -m 125.6 -n 1D_exp -t -1 --expectSignal=1 --saveToys -v 3 
	mv higgsCombine1D_exp.MultiDimFit.mH125.6.123456.root $FOLDER/.
	ls -lrt $FOLDER
	
echo "[Info:] Finished"
