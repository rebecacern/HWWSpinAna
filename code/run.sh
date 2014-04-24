echo "Removing the previous rootfile"

rm rootfiles/test.root

echo "Running templates"

# center of mass energy
for e in 8; do
	echo "Center of mass = $e"
	for i in 0 1 2 3 4; do
		root.exe -b -l -q chain.C+\($i\,$e\)
	done

	for i in 0 1 2 3 4; do
		root.exe -b -l -q plot.C\($i\,$e\)
	done
done
