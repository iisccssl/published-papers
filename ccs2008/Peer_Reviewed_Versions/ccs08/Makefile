# Makefile for the Paper

#SRC=$(shell ls *.tex  *.bib sections/*.tex figures/eps/*.eps figures/fig/*.fig)
SRC=$(shell ls *.tex *.bib sections/*.tex)

default: pdf

tr: tmi-techreport.pdf
#web: webversion.pdf

pdf: ccs08.pdf

ps: ccs08.ps

ccs08.ps: ccs08.pdf
	pdftops ccs08.pdf 

#ccs08.pdf: ccs08.dvi
#	dvipdf ccs08.dvi 

tmi-techreport.pdf: $(SRC)
	cd figures; make pdf; cd -
	pdflatex techreport
	bibtex techreport
	pdflatex techreport
	pdflatex techreport
	mv techreport.pdf tmi-techreport.pdf
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak

ccs08.pdf: $(SRC)
	cd figures; make pdf; cd -
	pdflatex main
	bibtex main
	pdflatex main
	pdflatex main
	mv main.pdf ccs08.pdf
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.out sections/*.bak

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
	rm -f *~ 
	cd sections/; rm -f *~
#	cd figures; make clean; cd -
