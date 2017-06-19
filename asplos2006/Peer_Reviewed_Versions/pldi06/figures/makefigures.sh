#!/bin/bash

echo "Cleaning up all .eps and .pdf files"
echo ""
for i in `ls |grep "\.bak"`
do
	rm $i
done


# Cleanup all the eps and pdf files, and produce them afresh.
for i in `ls *.fig | gawk -F. '{printf $1"\n"}'`
do
	figfile="$i.fig"
	epsfile="$i.eps"
	pdffile="$i.pdf"
	
	rm $epsfile
	rm $pdffile
	
	echo "Producing $epsfile."
	fig2dev -Leps $figfile > $epsfile

	echo "Producing $pdffile."
	fig2dev -Lpdf $figfile > $pdffile

	echo ""
done

chmod 644 *.pdf
echo "Done."
