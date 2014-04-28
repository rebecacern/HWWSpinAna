FOLDER='output_0m'
DC='fa3/0m'
MX=125.6
NAME='hww_test'
NTOYS=100

echo "~** This script will run version 1, no interference term **~"
	mkdir -p $FOLDER
	mkdir -p $DC/${MX}

	combineCards.py -S $DC/*_new.txt > $NAME

	
echo "[Info:] building the workspace, hypothesis testing fqq floating" 

	#text2workspace.py -m 125.6 $NAME -P HiggsAnalysis.CombinedLimit.HiggsJPC:twoHypothesisHiggs --PO=muFloating -o $FOLDER/fixedMu.root 
	text2workspace.py -m 125.6 $NAME -P HiggsAnalysis.CombinedLimit.HiggsJPC:twoHypothesisHiggs --PO='fqqFloating' -o $FOLDER/fixedMu.root 

    
echo "[Info:] workspace fixedMu.root created"
echo "[Info:] running combine"
	
	combine -m ${MX} -M HybridNew $FOLDER/fixedMu.root --seed -1 --testStat=TEV --generateExt=1 --generateNuis=1 --fitNuis=0 --singlePoint 1 --saveHybridResult -T $NTOYS -i 1 --clsAcc 0 --fullBToys --setPhysicsModelParameters fqq=0 --freezeNuisance fqq 
	mv  higgsCombineTest.HybridNew.*.root $FOLDER/.
	ls -lrt $FOLDER
	
echo "[Info:] Finished"
