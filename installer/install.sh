#!/bin/bash

git clone https://github.com/SerjeiMikailov/shellb.git

cd shellb

make install

make

echo "Compiled with success"

cd build 

cp shellb /usr/local/bin/

chmod +x /usr/local/bin/shellb

hash -r

echo "Installation complete!"

echo "Now type shellb in your terminal"
