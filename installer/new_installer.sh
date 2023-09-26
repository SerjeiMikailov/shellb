
git clone -b unstablev2 https://github.com/SerjeiMikailov/shellb.git

cd shellb || exit 1

if [ ! -d "$HOME/shellbsrc" ]; then
    mkdir "$HOME/shellbsrc"
fi

mv shellb "$HOME/shellbsrc"

cd "$HOME/shellbsrc/shellb" || exit 1

read -p "Select your compiler: (clang / gcc): " confirm

if [ "$confirm" = "clang" ]; then
    sh clang.sh
elif [ "$confirm" = "gcc" ]; then
    sh gcc.sh
fi

cd "$HOME/shellbsrc/shellb/build" || exit 1

sudo mv shellb /usr/local/bin
sudo chmod +x /usr/local/bin/shellb

cd "$HOME/shellbsrc/shellb/installer" || exit 1

sudo cp client_updater.sh /usr/local/bin
sudo chmod +x /usr/local/bin/client_updater.sh

sudo cp uninstall.sh /usr/local/bin
sudo chmod +x /usr/local/bin/uninstall.sh

hash -r
echo "Now type shellb in your terminal"
