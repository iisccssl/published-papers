#!/bin/bash

# Obtain timestamp and create new file name.
date=`date +%d%b%y_%H%M`
newfilename="$1.$date"

cp $1 backup/$newfilename
