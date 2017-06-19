#!/bin/bash

make pdf 
scp ndss09.pdf /res/users/vinodg/public_html/downloads/sd-ndss09.pdf
cp ndss09.pdf ~/public_html/downloads/ndss09.pdf
chmod 755 ~/public_html/downloads/ndss09.pdf
