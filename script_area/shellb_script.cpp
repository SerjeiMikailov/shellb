/*

So you ask me, what is this? And how can you see, is just a template file 
to use the ShellB script. Yes, ShellB have a custom language that you can make scripts
with all functions you can imagine.

I'm so stupid to make something good, just enjoy this magnific creation...

*/

#include "../script/script.hpp"

int main() {
    std::string source_code = "HI HI HI";
    Interpreter interpreter(source_code);
    interpreter.execute();
    return 0;
}
