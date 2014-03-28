FOLDER='v2_output'

echo "~** This script will the version with interference term, building a PDF **~"
echo "[Warning:] you MUST have a datacard called hwwof_0j_inter.txt in the folder"

	mkdir $FOLDER
	mkdir rootfiles

echo "[Info:] prepare rootfiles test.root and test2.root"
	
	root.exe -b -q "import.c(7)"
	root.exe -b -q "import.c(8)"
	
	ls -lrt rootfiles
	
echo "[Info:] building the workspace" 

	text2workspace.py -m 125.6 hwwof_0j_inter.txt -P HiggsAnalysis.CombinedLimit.SpinZeroStructure:spinZeroHiggs --PO=muFloating -o $FOLDER/floatMu_inter.root -v 7

echo "[Info:] workspace floatMu_inter.root created"
echo "[Info:] running combine"

	combine -M MultiDimFit $FOLDER/floatMu_inter.root --algo=grid --points 100 -m 125.6 -n 1D_exp -t -1 --expectSignal=1 --saveToys -v 3 
	mv higgsCombine1D_exp.MultiDimFit.mH125.6.123456.root $FOLDER/.
	ls -lrt $FOLDER
	
echo "[Info:] Finished"
