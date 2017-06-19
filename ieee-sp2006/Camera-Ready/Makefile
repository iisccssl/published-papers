# Makefile for the Paper

SRC=$(shell ls *.tex styles/*.sty *.bib sections/*.tex figures/eps/*.eps figures/pdf/*.pdf figures/fig/*.fig)

default: pdf 

all: pdf ps pdfbm

pdf: ganapathy-retrofitting.pdf

ps: ganapathy-retrofitting.ps

pdfbm: ieee-sp2006.pdf

# Make Postscript. Not for IEEE.
ganapathy-retrofitting.ps: $(SRC)
	latex ganapathy-retrofitting
	bibtex ganapathy-retrofitting
	latex ganapathy-retrofitting
	latex ganapathy-retrofitting
	dvips -o ganapathy-retrofitting.ps ganapathy-retrofitting.dvi
	rm -f *.log *.aux *.blg *.cb *.out *.bbl *.dvi
	
# Use this to produce PDFs for IEEE (no bookmarks, all fonts embedded/subset)
ganapathy-retrofitting.pdf: $(SRC)
	latex ganapathy-retrofitting
	bibtex ganapathy-retrofitting
	latex ganapathy-retrofitting
	latex ganapathy-retrofitting
	dvipdf -dPDFSETTINGS=/prepress -dCompatibilityLevel=1.3 -dEmbedAllFonts=true -dSubsetFonts=true -dMonoImageResolution=600 ganapathy-retrofitting.dvi
	rm -f *.log *.aux *.blg *.cb *.out *.bbl *.dvi

# Use this to produce PDFs with bookmarks.
ieee-sp2006.pdf: $(SRC)
	pdflatex ieee-sp2006
	bibtex ieee-sp2006
	pdflatex ieee-sp2006
	pdflatex ieee-sp2006
	rm -f *.log *.aux *.blg *.cb *.out *.bbl
	
clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out sections/*.bak
