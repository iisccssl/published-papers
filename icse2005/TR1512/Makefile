# Makefile for the Paper

SRC=$(shell ls *.bib *.tex figures/*.eps)

default: tr1512.pdf

#ps:	submit_ccs2004.ps
ps:	tr1512.ps

#pdf: submit_ccs2004.pdf
pdf: tr1512.pdf

#submit_ccs2004.ps: $(SRC)
tr1512.ps: $(SRC)
	latex main
	bibtex main
	latex main
	latex main
	dvips -o tr1512.ps main.dvi
#	dvips -o submit_ccs2004.ps main.dvi
#	rm *.log *.aux *.blg

#submit_ccs2004.pdf: $(SRC)
tr1512.pdf: $(SRC)
	latex main
	bibtex main
	latex main
	latex main
	dvipdf main.dvi tr1512.pdf
#	dvipdf main.dvi submit_ccs2004.pdf
	rm *.log *.aux *.blg

clean:
	rm -f figures/*.bak *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf
