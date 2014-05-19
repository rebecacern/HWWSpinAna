FOLDER='v1_0m_norm'

echo "~** This script will run version 1, no interference term **~"
	mkdir $FOLDER
echo "[Info:] combine datacards of hww 0j"
 	rm hwwof_0j.txt
	../HiggsAnalysis/CombinedLimit/scripts/combineCards.py 0m_norm/hwwof_*new.txt > hwwof_0j.txt
	
echo "[Info:] building the workspace" 

	text2workspace.py -m 125.6 hwwof_0j.txt -P HiggsAnalysis.CombinedLimit.HiggsJPC:twoHypothesisHiggs --PO=muFloating -o $FOLDER/fixedMu.root 

echo "[Info:] workspace fixedMu.root created"
echo "[Info:] running combine"

	combine -M MultiDimFit $FOLDER/fixedMu.root --algo=grid --points 100 -m 125.6 -n 1D_exp -t -1 --expectSignal=1 --saveToys -v 3 
	mv higgsCombine1D_exp.MultiDimFit.mH125.6.123456.root $FOLDER/.
	ls -lrt $FOLDER
	
echo "[Info:] Finished"
