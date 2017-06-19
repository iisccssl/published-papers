# Makefile for the Paper

SRC=$(shell ls *.tex styles/*.sty *.bib sections/*.tex figures/eps/*.eps figures/fig/*.fig)

default: pdf ps icse

all: pdf ps icse

pdf: icse2007.pdf

ps: icse2007.ps

icse: ganapathy-mining.pdf

icse2007.dvi: $(SRC)
	cd figures; make; cd -
	latex icse2007
	bibtex icse2007
	latex icse2007
	latex icse2007
	rm -f *.log *.aux *.blg *.cb *.out *.bbl
	
icse2007.ps: icse2007.dvi
	dvips -Pcmz -Pamz icse2007.dvi

ganapathy-mining.pdf: icse2007.dvi
	dvipdf -dPDFSETTINGS=/prepress -dCompatibilityLevel=1.3 -dEmbedAllFonts=true -dSubsetFonts=true -dMonoImageResolution=600 -dMaxSubsetPct=100 icse2007.dvi ganapathy-mining.pdf
	rm -f *.log *.aux *.blg *.cb *.out *.bbl

icse2007.pdf: $(SRC)
	cd figures; make; cd -
	pdflatex icse2007
	bibtex icse2007
	pdflatex icse2007
	pdflatex icse2007
	rm -f *.log *.aux *.blg *.cb *.out *.bbl

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
	cd figures; make clean; cd -
