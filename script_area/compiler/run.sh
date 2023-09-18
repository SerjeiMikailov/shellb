
clang -c $HOME/shellbsrc/shellb/src/misc.c -o $HOME/shellbsrc/shellb/script_area/bin/test.o

clang++ -c -o $HOME/shellbsrc/shellb/script_area/shellb_script.cpp -o $HOME/shellbsrc/shellb/script_area/bin/shellb_script.o
clang++ -c -o $HOME/shellbsrc/shellb/script/script.cpp -o $HOME/shellbsrc/shellb/script_area/bin/script.o

cd $HOME/shellbsrc/shellb/script_area/bin

clang++ -std=c++11 -o shellscript shellb_script.o script.o test.o
