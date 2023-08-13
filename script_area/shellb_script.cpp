/*

So you ask me, what is this? And how can you see, is just a template file 
to use the ShellB script. Yes, ShellB have a custom language that you can make scripts
with all functions you can imagine.

Just enjoy this magnific creation...

*/

// #include "script.hpp" 
#include "../script/script.hpp"

int main() {
    std::string source_code = "ls";
    Interpreter interpreter(source_code);
    interpreter.execute();
    return 0;
}
