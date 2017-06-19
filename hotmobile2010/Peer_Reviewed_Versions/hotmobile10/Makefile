# Makefile for the Paper

#SRC=$(shell ls *.tex  *.bib sections/*.tex figures/eps/*.eps figures/fig/*.fig)
SRC=$(shell ls *.tex  *.bib sections/*.tex)

default: pdf 

#web: webversion.pdf

pdf: hotmobile10.pdf

ps: hotmobile10.ps

dvi: main.dvi

#hotmobile10.pdf: main.dvi
#	dvipdf main.dvi main.pdf
#	mv main.pdf hotmobile10.pdf

hotmobile10.pdf: $(SRC)
	pdflatex main
	bibtex main
	pdflatex main
	pdflatex main
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak
	mv main.pdf hotmobile10.pdf

hotmobile10.ps:	main.dvi
	dvips -o hotmobile10.ps main.dvi

main.dvi: $(SRC)
	latex main
	bibtex main
	latex main
	latex main
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
	rm -f *~ 
	cd sections/; rm -f *~
#	cd figures; make clean; cd -
