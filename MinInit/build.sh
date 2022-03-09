#!/bin/bash
## 
## PROJECT:   MinCLR
## FILE:      .editorconfig
## PURPOSE:   Build script for MinInit
## 
## LICENSE:   The MIT License
## 
## DEVELOPER: Mouri_Naruto (Mouri_Naruto AT Outlook.com)
## 

SOURCE_ROOT=$(dirname $(realpath -s ${BASH_SOURCE[0]}))
OUTPUT_ROOT=$SOURCE_ROOT/Output/Binaries
mkdir -p $OUTPUT_ROOT
musl-gcc -std=c99 -static -O2 -s -o $OUTPUT_ROOT/mininit $SOURCE_ROOT/MinInit.c
