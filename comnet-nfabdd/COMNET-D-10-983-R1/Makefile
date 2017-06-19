# Makefile for the Paper

SRC=$(shell ls *.tex *.bib *.eps)

default: web

web: COMNET-D-10-983.pdf
	cp COMNET-D-10-983.pdf /res/users/vinodg/public_html/downloads/pending/COMNET-D-10-983.pdf

pdf: COMNET-D-10-983.pdf

COMNET-D-10-983.pdf: $(SRC)
	latex main
	bibtex main
	latex main
	latex main
	dvips main.dvi
	ps2pdf main.ps
	mv main.pdf COMNET-D-10-983.pdf
	rm -f main.spl *.cb *.bak *.bbl *.blg *.log *.aux *.out *.dvi

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi COMNET-D-10-983.pdf *.out 
