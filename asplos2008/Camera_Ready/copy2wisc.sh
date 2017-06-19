#!/bin/bash

TGT=vg@prospero.cs.wisc.edu:private/research/Writings/ASPLOS2008
SRC=`find . | grep -e *.tex -e *.cls -e *.bib`
rsync -t $SRC $TGT/.
SRC=`find sections/ | grep -e .tex`
rsync -t $SRC $TGT/sections/
