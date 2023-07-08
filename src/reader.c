#include "App.h"

void read_command(char *command)
{
    char *user = get_user();
    char *folder = working_dir();

    printf("\033[1;32m%s\033[0m:", user);
    printf("\033[1;34m%s\033[0m -> ", folder);
    fgets(command, MAX_COMMAND_LENGHT, stdin);
    command[strcspn(command, "\n")] = '\0';
}

void parse_command(char *command, char **args)
{
    int i = 0;
    args[i] = strtok(command, " ");

    while (args[i] != NULL && i < MAX_ARGS - 1)
    {
        i++;
        args[i] = strtok(NULL, " ");
    }
}
