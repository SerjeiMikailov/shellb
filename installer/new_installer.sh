
git clone https://github.com/SerjeiMikailov/shellb.git

cd shellb
cd $OLDPWD

mkdir $HOME/shellbsrc

mv shellb $HOME/shellbsrc

cd $HOME
cd shellbsrc
cd shellb 

sh client_compiler.sh

cd build

sudo mv shellb /usr/local/bin
sudo chmod +x /usr/local/bin/shellb

cd ..
cd installer

sudo cp client_updater.sh /usr/local/bin
sudo chmod +x /usr/local/bin/client_updater.sh

sudo cp uninstall.sh /usr/local/bin
sudo chmod +x /usr/local/bin/uninstall.sh

hash -r
echo "Now type shellb in your terminal"
