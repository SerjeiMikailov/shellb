#!/bin/bash

git clone https://github.com/SerjeiMikailov/shellb.git

cd shellb

make install

make

echo "Compilation: success"

cd build 

sudo cp shellb /usr/local/bin/

sudo chmod +x /usr/local/bin/shellb

hash -r

echo "Path: Success"

cd $HOME

mkdir shellbsrc

cd $OLDPWD

cd ..

cd script

cp script.cpp  $HOME/shellbsrc

cp script.hpp  $HOME/shellbsrc

cd .. 

cd script_area

cp shellb_script.cpp $HOME/shellbsrc

cd compiler

cp run.sh $HOME/shellbsrc

cd ../..

cd installer 

mv updateshellb.sh ~/bin/

chmod +x ~/bin/updateshellb.sh

hash -r

echo "Installation complete!"

echo "Now type shellb in your terminal"
