# Makefile for the Paper

SRC=$(shell ls *.tex styles/*.sty *.bib sections/*.tex figures/eps/*.eps figures/pdf/*.pdf figures/fig/*.fig)

default: pdf ps

pdf: UW-CS-TR1544.pdf

ps: UW-CS-TR1544.ps

UW-CS-TR1544.ps: $(SRC)
	cd figures; make eps; cd -
	latex UW-CS-TR1544
	bibtex UW-CS-TR1544
	latex UW-CS-TR1544
	latex UW-CS-TR1544
	dvips -o UW-CS-TR1544.ps UW-CS-TR1544.dvi
	rm *.log *.aux *.blg

UW-CS-TR1544.pdf: $(SRC)
	cd figures; make pdf; cd -
	pdflatex UW-CS-TR1544
	bibtex UW-CS-TR1544
	pdflatex UW-CS-TR1544
	pdflatex UW-CS-TR1544
	rm *.log *.aux *.blg
	
clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
	cd figures; make clean; cd -
