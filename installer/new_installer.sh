#!/bin/bash

git clone -b unstablev2 https://github.com/SerjeiMikailov/shellb.git

cd shellb

sh client_compiler.sh

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

cd src 

cp App.h $HOME/shellbsrc
cp misc.c $HOME/shellbsrc
cp generator.h $HOME/shellbsrc

cd ..

cd installer 

cp new_installer.sh $HOME/shellbsrc

sudo mv uninstall.sh /usr/local/bin
sudo chmod +x /usr/local/bin/uninstall.sh

sudo mv new_installer.sh /usr/local/bin
sudo chmod +x /usr/local/bin/updateshellb.sh

hash -r

echo "Installation complete!"

echo "Now type shellb in your terminal"
