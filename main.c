#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>

#define MAX_COMMAND_LENGHT 100
#define MAX_ARGS 20
#define MAX_PATH 50000

void remove_directory(const char *path) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        printf("Error opening directory\n");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        char entry_path[MAX_PATH];
        snprintf(entry_path, sizeof(entry_path), "%s/%s", path, entry->d_name);

        struct stat st;
        if (lstat(entry_path, &st) == -1) {
            printf("Error getting file/directory information\n");
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            remove_directory(entry_path);
        } else {
            if (remove(entry_path) != 0) {
                printf("Error removing file: %s\n", entry_path);
            }
        }
    }

    closedir(dir);

    if (rmdir(path) != 0) {
        printf("Error removing directory: %s\n", path);
    }
}

void read_command(char *command)
{
    printf("> ");
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
    if (strcmp(args[0], "cd") == 0)
    {
        if (args[1] == NULL)
        {
            printf("Type the directory to access with 'cd'\n");
            return;
        }
        if (chdir(args[1]) != 0)
        {
            printf("Error to access the directory\n");
        }
    }
    else if (strcmp(args[0], "ls") == 0)
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
            printf("Erro ao abrir diretório\n");
            return;
        }

        while ((entry = readdir(dir)) != NULL)
        {
            printf("%s\n", entry->d_name);
        }

        closedir(dir);
    }
    else if (strcmp(args[0], "re") == 0)
    {
        if (args[1] == NULL || args[2] == NULL)
        {
            printf("Type the directory to rename with 're'\n");
            return;
        }
        if (rename(args[1], args[2]) != 0)
        {
            printf("Error to rename\n");
        }
    }
    else if (strcmp(args[0], "rm") == 0)
    {
        if (args[1] == NULL) {
            printf("Type the name of the file/directory to remove with 'rm'\n");
            return;
        }

        struct stat st;
        if (lstat(args[1], &st) == -1) {
            printf("Error getting file/directory information\n");
            return;
        }

        if (S_ISDIR(st.st_mode)) {
            remove_directory(args[1]);
        } else {
            if (remove(args[1]) != 0) {
                printf("Error removing file: %s\n", args[1]);
            }
        }
    }
    else if (strcmp(args[0], "cf") == 0)
    {
        if (args[1] == NULL)
        {
            printf("Type the name of directory to create 'cf'\n");
            return;
        }
        if (mkdir(args[1], 0777) != 0)
        {
            printf("Error to create the dir\n");
        }
    }
    else
    {
        printf("Unknow: %s\n", args[0]);
    }
}

int main()
{
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