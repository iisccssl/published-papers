TEX      := latex
BIBTEX   := bibtex
PDFTEX   := pdflatex
DVIPS    := dvips
EPSTOPDF := epstopdf
RM       := rm -f
OPTIONS  = -t letter -Pcmz -D 900 
PDFTEXOPTIONS = -shell-escape #--interaction batchmode

MAINSRC = sacmat2009.tex
DVIFILE = $(basename $(MAINSRC)).dvi
TARGET  = $(basename $(MAINSRC)).pdf
PSFILE  = $(basename $(MAINSRC)).ps
BIBSRC  = $(shell ls *.bib)
BIBFILE = ref.bbl
TEXSRC	= $(shell ls *.tex)

SUBDIRS=figs

all: $(TARGET) $(PSFILE)


sacmat2009.ps: $(DVIFILE) $(TEXSRC) refs
	$(DVIPS) $(OPTIONS) -o $@ $(basename $@)

sacmat2009.pdf: $(TEXSRC) refs
	for i in 1 2; do\
 		$(PDFTEX) $(PDFTEXOPTIONS) $(basename $@);\
	done

figures :
	for i in $(SUBDIRS) ; do\
		$(MAKE) -C $$i;\
	done

sacmat2009.dvi: $(shell ls *.tex) refs
	   $(PDFTEX) -output-format dvi $(basename $@)

refs: $(MAINSRC) $(BIBSRC) #figures
	$(PDFTEX) $(basename $<);
	$(BIBTEX) $(basename $<);


clean: 
	$(RM) $(TARGET) $(PSFILE) $(DVIFILE) $(BIBFILE) *.aux *.log *blg *~ semantic.cache xxx* *.bbl *.out *.bak

cleansub: 
	for i in $(SUBDIRS); do\
		$(MAKE) -C $$i clean;\
	done
