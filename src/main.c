#include "App.h"
#include <stdio.h>

/*
----------------------------------
|                                |
|             ShellB             |
|                                |
|          Version 1.12          |
|                                |
----------------------------------

Unstable build version
Unstable v3

*/

int main(void)
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
