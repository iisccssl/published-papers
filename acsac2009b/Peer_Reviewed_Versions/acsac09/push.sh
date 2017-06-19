#!/bin/bash

# Mercurial commit.
echo "Mercurial commit"
hg commit;
hg push /res/users/vinodg/hg-repo/securedrivers/paper;

# CVS commit.
echo "CVS commit"
cvs commit;
