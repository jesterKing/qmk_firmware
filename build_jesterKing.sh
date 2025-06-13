#!/bin/sh

cd /qmk

python3 -m pip install -r requirements.txt
qmk compile -kb splitkb/kyria/rev3 -km jesterKing
#cp *.uf2 /qmk/local/.
