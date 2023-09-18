pkill shellb

cd $HOME/shellbsrc/shellb

sh client_compiler.sh

cd build

sudo mv shellb /usr/local/bin
sudo chmod +x /usr/local/bin/shellb

hash -r
