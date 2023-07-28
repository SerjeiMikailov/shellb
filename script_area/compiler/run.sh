#!/bin/zsh

# #!/bin/bash

cd "$(dirname "$0")/../../"

g++ -std=c++11 -Wall -Wextra -I./script -o script_area/bin/shellscript script_area/shellb_script.cpp script/script.cpp
