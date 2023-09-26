
git clone -b unstablev2 https://github.com/SerjeiMikailov/shellb.git

cd shellb
cd $OLDPWD

mkdir $HOME/shellbsrc

mv shellb $HOME/shellbsrc

cd $HOME
cd shellbsrc
cd shellb 

read -p "Select your compiler: (clang / gcc): " confirm
if [ "$confirm" == "clang" ]; then
    sh clang.sh
elif [ "$confirm" == "gcc" ]; then
    sh gcc.sh
fi

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
