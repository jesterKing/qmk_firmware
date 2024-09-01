#!/bin/sh

cd /qmk/qmk_firmware

git fetch
git reset --hard origin/jesterking_liatris
git submodule update --init --recursive

qmk compile -kb splitkb/kyria/rev3 -km jesterKing
cp *.uf2 /qmk/local/.
