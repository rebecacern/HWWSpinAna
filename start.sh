echo "[Info:] downloading summer 2013 datacards to datacards/"

	svn co svn+ssh://svn.cern.ch/reps/cmshcg/trunk/summer2013/jcp/ datacards

echo "[Info:] copying proper PDF class to your CMSSW installation"

	scp basic/HZZ4L_RooSpinZeroPdf.cc ../HiggsAnalysis/CombinedLimit/src/.
	scp basic/HZZ4L_RooSpinZeroPdf.h ../HiggsAnalysis/CombinedLimit/interface/.
	scp basic/SpinZeroStructure.py ../HiggsAnalysis/CombinedLimit/python/.

pushd ../

echo ""
echo "[Info:] compiling HiggsAnalysis/CombinedLimit"
echo ""
 
	scramv1 b clean
	scramv1 b -j 8

popd

echo "[Info:] done"

pwd
