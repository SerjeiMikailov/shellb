#include "App.h"

/*

----------------------------------
|                                |
|             ShellB             |
|                                |
|          Version 1.06          |
|                                |
----------------------------------

This version is so bad, please see the unstable (much better)

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
