#include "App.h"

/*
----------------------------------
|                                |
|             ShellB             |
|                                |
|          Version 1.07          |
|                                |
----------------------------------

Unstable build version
This version may cointain bugs and can be deprecated more quickly than the stable version

*/

int main()
{
    clear();
    shellb();

    char command[MAX_COMMAND_LENGHT];
    char *args[MAX_ARGS];

    while (1)
    {
        read_command(command);
        parse_command(command, args);
        execute_command(args);
    }

    return 0;
}
