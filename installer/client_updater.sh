pkill shellb

cd $HOME

rm -rf shellbsrc

cd /usr/local/bin/

sudo rm -rf shellb

cd $HOME

git clone -b unstablev2 https://github.com/SerjeiMikailov/shellb.git

cd shellb

cd installer 

sh new_installer.sh

cd ../.. 

rm -rf shellb