#!/bin/bash

make pdf 
cp ccs08.pdf ~/public_html/downloads/ccs08-tmi.pdf
cd ~/public_html/downloads/
chmod 755 ccs08-tmi.pdf
