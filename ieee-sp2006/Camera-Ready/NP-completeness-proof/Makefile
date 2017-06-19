# Makefile for the Paper

SRC=$(shell ls *.tex)

default: pdf 

pdf: k-CNF.pdf

# Use this to produce PDFs for IEEE (no bookmarks, all fonts embedded/subset)
k-CNF.pdf: $(SRC)
	latex k-CNF
	latex k-CNF
	dvipdf -dPDFSETTINGS=/prepress -dCompatibilityLevel=1.3 -dEmbedAllFonts=true -dSubsetFonts=true -dMonoImageResolution=600 k-CNF.dvi

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
