echo "Removing the previous rootfiles"
rm trees/*


echo "Running templates"

# center of mass energy
for e in 7; do
	echo "Center of mass = $e"
	for j in 0 1; do
		echo "Jet bin = $j"
		for i in  1 2 3 4 5 6 7 8 9 22 23 24 25 26 27 28 29 30 32 33 34 35 36 37; do
			root.exe -b -l -q trees.C+\($i\,$e\,$j\)
		done
	done

	
done
