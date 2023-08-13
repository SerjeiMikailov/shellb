#!/bin/zsh

# #!/bin/bash

clang -c misc.c -o test.o

clang++ -c -o shellb_script.o shellb_script.cpp
clang++ -c -o script.o script/script.cpp

clang++ -std=c++11 -o shellscript shellb_script.o script.o test.o
