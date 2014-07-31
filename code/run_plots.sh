echo "Removing the previous rootfile"

rm rootfiles_var/*

echo "Running variables"

# center of mass energy
for e in 7 8; do
	echo "Center of mass = $e"
	for i in 1 2 3 4 5 6 7; do
		for j in 0 1; do
			for k in 0 1; do
				root.exe -b -l -q twohistos.C+\($i\,$e\,$j\,$k\)
			done
		done
	done
done

hadd test00/new_mll_0j.root rootfiles_var/test_mll_0j.root gui/histo_mll_0j.root 
hadd test00/new_mll_1j.root rootfiles_var/test_mll_1j.root gui/histo_mll_1j.root
hadd test00/new_mt_0j.root rootfiles_var/test_mt_0j.root gui/histo_mt_0j.root
hadd test00/new_mt_1j.root rootfiles_var/test_mt_1j.root gui/histo_mt_1j.root
