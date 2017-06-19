# Makefile for the Paper

SRC=$(shell ls *.tex styles/*.sty *.bib sections/*.tex figures/eps/*.eps figures/fig/*.fig)

default: pdf

pdf: hotos2007.pdf

web: hotos2007.pdf
	cp hotos2007.pdf /u/v/g/vg/public/html/downloads/hotos2007.pdf

hotos2007.dvi: $(SRC)
	cd figures; make pdf; cd -
	latex hotos2007
	bibtex hotos2007
	latex hotos2007
	latex hotos2007
	rm -f *.log *.aux *.blg *.cb *.out *.bbl

hotos2007.pdf: hotos2007.dvi	
	dvipdf -dPDFSETTINGS=/prepress -dCompatibilityLevel=1.3 -dEmbedAllFonts=true -dSubsetFonts=true -dMonoImageResolution=600 -dMaxSubsetPct=100 hotos2007.dvi hotos2007.pdf
	rm -f *.log *.aux *.blg *.cb *.out *.bbl
	
# hotos2007.pdf: $(SRC)
# 	cd figures; make pdf; cd -
# 	pdflatex hotos2007
# 	bibtex hotos2007
# 	pdflatex hotos2007
# 	pdflatex hotos2007
# 	rm -f *.log *.aux *.blg *.cb *.out *.bbl

clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out \
		sections/*.bak
