#!/bin/sh

cvs ci -m "" p184-ganapathy.tex *.bib *.sty *.sh *.cls figures/*.fig Makefile
./mkbkp.sh p184-ganapathy.tex
