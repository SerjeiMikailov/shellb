
git clone -b unstablev2 https://github.com/SerjeiMikailov/shellb.git

cd shellb
cd $OLDPWD

mkdir $HOME/shellbsrc

mv shellb $HOME/shellbsrc

cd $HOME
cd shellbsrc
cd shellb 

sh client_compiler.sh

cd build

sudo cp shellb /usr/local/bin
sudo chmod +x /usr/local/bin/shellb

cd ..
cd installer

sudo cp client_updater /usr/local/bin
sudo chmod +x /usr/local/bin/client_updater

sudo cp uninstall.sh /usr/local/bin
sudo chmod +x /usr/local/bin/uninstall.sh

hash -r
echo "Now type shellb in your terminal"