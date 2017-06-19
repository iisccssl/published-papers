# Makefile for the Paper

SRC=$(shell ls *.sty *.bib *.tex figures/eps/*.eps figures/pdf/*.pdf figures/fig/*.fig)

default: pdf ps

pdf: selinux06.pdf

ps: selinux06.ps

selinux06.ps: $(SRC)
	latex selinux06
	bibtex selinux06
	latex selinux06
	latex selinux06
	dvips -o selinux06.ps selinux06.dvi
	rm *.log *.aux *.blg

selinux06.pdf: $(SRC)
	make ps
	ps2pdf selinux06.ps
	cp selinux06.pdf /u/v/g/vg/public/html/download/selinux06/
	
clean:
	rm -f *.cb *.bak *.bbl *.blg *.log *.aux *.ps *.dvi *.pdf *.out
#	cd figures; make clean; cd -
