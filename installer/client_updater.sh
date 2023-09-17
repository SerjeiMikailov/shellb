pkill shellb

cd $HOME

rm -rf shellbsrc

cd /usr/local/bin/

sudo rm -rf shellb

cd $HOME

mkdir updatesb

cd updatesb

git clone -b unstablev2 https://github.com/SerjeiMikailov/shellb.git

cd shellb

cd installer 

cp new_installer.sh $HOME/updatesb

cd $HOME
cd updatesb

sh new_installer.sh

cd $HOME

rm -rf updatesb
