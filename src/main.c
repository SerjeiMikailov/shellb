#include "App.h"

void read_command(char *command)
{
    char* user = get_user();
    char* folder = working_dir();

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

void execute_command(char **args)
{
    if (strcmp(args[0], "cd") == 0) // cd
    {
        if (args[1] == NULL)
        {
            puts("Type the directory to access with 'cd'");
            return;
        }
        if (chdir(args[1]) != 0)
        {
            puts("Error to access the directory");
        }
    }
    else if (strcmp(args[0], "ls") == 0) // ls
    {   
        DIR *dir;
        struct dirent *entry;

        if (args[1] == NULL)
        {
            dir = opendir(".");
        }
        else
        {
            dir = opendir(args[1]);
        }

        if (dir == NULL)
        {
            puts("Erro ao abrir diretório");
            return;
        }

        while ((entry = readdir(dir)) != NULL)
        {
            printf("%s\n", entry->d_name);
        }

        closedir(dir);
    }
    else if (strcmp(args[0], "re") == 0) // rename
    {
        if (args[1] == NULL || args[2] == NULL)
        {
            puts("Type the directory to rename with 're'");
            return;
        }
        if (rename(args[1], args[2]) != 0)
        {
            puts("Error to rename");
        }
    }
    else if (strcmp(args[0], "rm") == 0) // remove 
    {
        if (args[1] == NULL) {
            puts("Type the name of the file/directory to remove with 'rm'");
            return;
        }

        struct stat st;
        if (lstat(args[1], &st) == -1) {
            puts("Error getting file/directory information");
            return;
        }

        if (S_ISDIR(st.st_mode)) {
            remove_directory(args[1]);
        } else {
            if (remove(args[1]) != 0) {
                printf("Error removing file: %s", args[1]);
            }
        }
    }
    else if (strcmp(args[0], "cf") == 0) // create folder
    {
        if (args[1] == NULL)
        {
            puts("Type the name of directory to create 'cf'");
            return;
        }
        if (mkdir(args[1], 0777) != 0)
        {
            printf("Error to create the dir\n");
        }
    }
    else if (strcmp(args[0], "shellb") == 0) // shellb
    {
       shellb();
    }
    else if (strcmp(args[0], "loc") == 0) // location
    {
        working_dir();
    }
    else if (strcmp(args[0], "clear") == 0) // clear
    {
        clear();
        shellb();
    }
    else if (strcmp(args[0], "fc") == 0) // full clear
    {
        clear();
    }
    else
    {
        printf("Unknow: %s\n", args[0]);
    }
}

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
