
if [ "$1" == "--gcc" ]; then

pkill shellb

cd $HOME/shellbsrc/shellb

sh gcc.sh

cd build

sudo mv shellb /usr/local/bin
sudo chmod +x /usr/local/bin/shellb

hash -r
fi

if [ "$1" == "--clang" ]; then

pkill shellb

cd $HOME/shellbsrc/shellb

sh clang.sh

cd build

sudo mv shellb /usr/local/bin
sudo chmod +x /usr/local/bin/shellb

hash -r
fi