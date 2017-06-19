# Makefile for the Paper

SRC=$(shell ls *.bib *.tex Figures/*.eps)

all:	p351-ganapathy.ps

p351-ganapathy.ps: $(SRC)
	echo "BBL File is Included in the LaTeX file."
	latex p351-ganapathy 
	#bibtex p351-ganapathy
	#latex p351-ganapathy
	latex p351-ganapathy
	dvips -P cmz -t letter -o p351-ganapathy.ps p351-ganapathy.dvi
	dvipdf p351-ganapathy.dvi p351-ganapathy.pdf

clean:
	rm -f *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf
