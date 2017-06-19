#!/bin/bash

for i in `ls *.dot | perl -p -e 's/\.dot//g'`
do
	dot -Teps $i.dot > $i.eps
	epstopdf $i.eps > $i.pdf
	rm $i.eps
done
