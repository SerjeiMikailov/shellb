pkill shellb

cd $HOME

sudo rm -rf shellbsrc

cd /usr/local/bin/

sudo rm -rf shellb

cd $HOME

mkdir shellbsrc

cd shellbsrc

git clone https://github.com/SerjeiMikailov/shellb.git

cd shellb 

sh client_compiler.sh

cd build

sudo cp shellb /usr/local/bin
sudo chmod +x /usr/local/bin/shellb

hash -r
echo "Now type shellb in your terminal"
