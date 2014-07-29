echo "Removing the previous rootfile"

rm rootfiles/test.root
#rm plots/*


echo "Running templates"

# center of mass energy
for e in 8; do
	echo "Center of mass = $e"
	for i in 0 1 2 3 4 5 6 7 22 23 24 25 26 27 28 29 30 31 32 33; do
		root.exe -b -l -q chain.C+\($i\,$e\)
	done

	for i in 0 1 2 3 4 5 6 7 22 23 24 25 26 27 28 29 30 31 32 33; do
		root.exe -b -l -q plot.C\($i\,$e\)
	done
	for i in 0 1 2 3 4 5 6 7 22 23 24 25 26 27 28 29 30 31 32 33; do
		root.exe -b -l -q compareplot.C\($i\,$e\)
		root.exe -b -l -q compareplot_alt.C\($i\,$e\)
	done
done
