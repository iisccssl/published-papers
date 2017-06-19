The source file is submit.tex. To produce the ps file
	latex submit; 
	latex submit; 
	bibtex submit; 
	latex submit;
	dvips -o submit.ps submit.dvi

To produce the pdf file
	dvipdf submit.dvi
The output is produced by default in submit.pdf

I have changed the figures so that they are now included using the
epsfig package. I had some problems in getting pdfimage to work on
my machine.

The style files are stored in the directory ENTCS_STYLE_FILES. They
are also there in the same directory as submit.tex.

It is also possible to produce pdf files having active links in them,
but I was unable to get the active links using the dvipdf command.
