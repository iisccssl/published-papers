LATEX	=latex
BIBTEX	=bibtex
DVIPS	=dvips
PS2PDF  =ps2pdf
article =wisec
FILES	=$(wildcard *.tex) $(wildcard *.bib)

$(article).pdf: $(FILES)
	    $(LATEX) $(article) 
	    $(BIBTEX) $(article)
	    $(LATEX) $(article) 
	    $(LATEX) $(article) 
	    $(DVIPS) -P www -t letter -o $(article).ps $(article).dvi
		$(PS2PDF)  -dPDFSETTINGS=/prepress -dEmbedAllFonts=true -dSubsetFonts=true -dEPSCrop=true $(article).ps $(article).pdf
	    #rm -f $(article).dvi

clean::
	rm -f $(article).dvi $(article).bbl $(article).log $(article).aux $(article).ps $(article).pdf $(article).blg *.*~ *.backup *.bak

commit:
	cvs commit
update:
	cvs up
