#!/bin/bash

for i in `ls | grep "\.bak"`
do
	rm *.bak
done

cvs commit
