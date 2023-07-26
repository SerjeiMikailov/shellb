#include "App.h"

/*
<<<<<<< HEAD

=======
>>>>>>> unstable
----------------------------------
|                                |
|             ShellB             |
|                                |
<<<<<<< HEAD
|          Version 1.06          |
|                                |
----------------------------------

This version is so bad, please see the unstable (much better)

*/

int main()
=======
|          Version 1.07          |
|                                |
----------------------------------

Unstable build version
This version may cointain bugs and can be deprecated more quickly than the stable version

*/

int main(void)
>>>>>>> unstable
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
