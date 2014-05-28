echo "Removing the previous rootfile"

rm rootfiles/test.root
rm plots/*

echo "Running templates"

# center of mass energy
for e in 8; do
	echo "Center of mass = $e"
	for i in 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21; do
		root.exe -b -l -q chain.C+\($i\,$e\)
	done

	for i in 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21; do
		root.exe -b -l -q plot.C\($i\,$e\)
		root.exe -b -l -q plot1d.C\($i\,$e\)
	done
	#root.exe compareplot.C
done
