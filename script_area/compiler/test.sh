
clang -c ../../src/misc.c -o ../bin/test.o

clang++ -c -o ../bin/shellb_script.o ../shellb_script.cpp
clang++ -c -o ../bin/script.o ../../script/script.cpp

cd ..

cd bin

clang++ -std=c++11 -o shellscript shellb_script.o script.o test.o
