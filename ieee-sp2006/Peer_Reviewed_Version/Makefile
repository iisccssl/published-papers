# Makefile for the Paper

SRC=$(shell ls *.tex styles/*.sty *.bib sections/*.tex figures/eps/*.eps figures/pdf/*.pdf figures/fig/*.fig)

default: pdf ps

pdf: ieee_sp06.pdf

ps: ieee_sp06.ps

ieee_sp06.ps: $(SRC)
	cd figures; make eps; cd -
	latex ieee_sp06
	bibtex ieee_sp06
	latex ieee_sp06
	latex ieee_sp06
	dvips -o ieee_sp06.ps ieee_sp06.dvi
	rm *.log *.aux *.blg
	cp ieee_sp06.ps /u/v/g/vg/public/html/download/oak06/

ieee_sp06.pdf: $(SRC)
	cd figures; make pdf; cd -
	pdflatex ieee_sp06
	bibtex ieee_sp06
	pdflatex ieee_sp06
	pdflatex ieee_sp06
	rm *.log *.aux *.blg
	cp ieee_sp06.pdf /u/v/g/vg/public/html/download/oak06/
	
clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
	rm -f /u/v/g/vg/public/html/download/oak06/*
	cd figures; make clean; cd -
