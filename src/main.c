#include "App.h"
#include <stdio.h>

/*
----------------------------------
|                                |
|             ShellB             |
|                                |
|          Version 1.13          |
|                                |
----------------------------------

Stable build version
Stable v4

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
