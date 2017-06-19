# Makefile for the Paper

SRC=$(shell ls *.tex)

default: pdf

pdf: raid2010.pdf

raid2010.pdf: $(SRC)
	pdflatex raid2010
	pdflatex raid2010
	pdflatex raid2010
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out *.bak

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux raid2010.pdf *.out *.bak
#	cd figures; make clean; cd -
