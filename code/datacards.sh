echo 'Organizing datacards'
mkdir ../fa3/
mkdir ../fa3/0m/
mkdir ../fa3/0mix/

scp /data/smurf/ceballos/inputLimits/ana_spin/xww125p6_x125ww4l-0mt-v19/*.root ../fa3/0m/
scp /data/smurf/ceballos/inputLimits/ana_spin/xww125p6_x125ww4l-0mf05ph0-v19/*.root ../fa3/0mix/

root.exe -b -l -q datacardmaker.C\(true\)
root.exe -b -l -q datacardmaker.C\(false\)
