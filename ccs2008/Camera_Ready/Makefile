# Makefile for the Paper

#SRC=$(shell ls *.tex  *.bib sections/*.tex figures/eps/*.eps figures/fig/*.fig)
SRC=$(shell ls *.tex *.bib sections/*.tex)

default: pdf

pdf: ccs2008.pdf ccs106-birgisson.pdf

ps: ccs2008.ps

# Make rules for latex
#
ccs106-birgisson.pdf:	ccs2008.pdf
	cp ccs2008.pdf ccs106-birgisson.pdf

#ccs2008.pdf: ccs2008.dvi
#	dvipdf -dPDFSETTINGS=/prepress -dCompatibilityLevel=1.3 -dEmbedAllFonts=true -dSubsetFonts=true -dMonoImageResolution=600 main.dvi
#	mv main.pdf ccs2008.pdf
#	rm -f *.log *.aux *.blg *.cb *.out *.bbl *.dvi

ccs2008.ps: ccs2008.dvi
	dvips -o ccs2008.ps main.dvi
	rm -f *.log *.aux *.blg *.cb *.out *.bbl *.dvi

ccs2008.dvi: $(SRC)
	latex main
	bibtex main
	latex main
	latex main

# Make rules for pdflatex.
#
ccs2008.pdf: $(SRC)
	cd figures; make pdf; cd -
	pdflatex main
	bibtex main
	pdflatex main
	pdflatex main
	mv main.pdf ccs2008.pdf
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak
#
#ccs2008.ps: ccs2008.pdf
#	pdftops ccs2008.pdf 

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
	rm -f *~ 
	cd sections/; rm -f *~
