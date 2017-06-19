# Makefile for the Paper

#SRC=$(shell ls *.tex  *.bib sections/*.tex figures/eps/*.eps figures/fig/*.fig)
SRC=$(shell ls *.tex  *.bib sections/*.tex)

default: pdf 

#web: webversion.pdf

pdf: ubicomp09.pdf

ps: ubicomp09.ps

dvi: main.dvi

#ubicomp09.pdf: main.dvi
#	dvipdf main.dvi main.pdf
#	mv main.pdf ubicomp09.pdf

ubicomp09.pdf: $(SRC)
	pdflatex main
	bibtex main
	pdflatex main
	pdflatex main
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak
	mv main.pdf ubicomp09.pdf

ubicomp09.ps:	main.dvi
	dvips -o ubicomp09.ps main.dvi

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
