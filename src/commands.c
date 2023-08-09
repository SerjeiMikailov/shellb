#include "App.h"
#include "./create_file/generator.h"
#include <stdio.h>

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
            puts("Error to open the directory");
            return;
        }

        int max_name_length = 0;
        while ((entry = readdir(dir)) != NULL)
        {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
            {
                int name_length = strlen(entry->d_name);
                if (name_length > max_name_length)
                {
                    max_name_length = name_length;
                }
            }
        }

        rewinddir(dir);

        while ((entry = readdir(dir)) != NULL)
        {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
            {
                printf("%-*s\n", max_name_length + 2, entry->d_name);
            }
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
        if (args[1] == NULL)
        {
            puts("Type the name of the file/directory to remove with 'rm'");
            return;
        }

        struct stat st;
        if (lstat(args[1], &st) == -1)
        {
            puts("Error getting file/directory information");
            return;
        }

        if (S_ISDIR(st.st_mode))
        {
            remove_directory(args[1]);
        }
        else
        {
            if (remove(args[1]) != 0)
            {
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
            puts("Error to create the dir");
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
    /*
    /////////////
    else (args[0][0] == '!' && args[0][1] != '\0') { // system level command
        executeSystemCommand(args[0]);
    }
    ////////////
    */
    else if (strcmp(args[0], "ram") == 0) // ram usage
    {
        print_memory_usage();
    }
    else if (strcmp(args[0], "exit") == 0) // exit command
    {
        puts("Exiting...");
        exit(0);
    }
    else if (strcmp(args[0], "nf") == 0) // ShellB "neofetch"
    {
    clear();

    char asciiArt[] =
          "---------------------\n"
          "|  ######   ######  |\n"
          "| #      #  #     # |\n"
          "|  #     #  #     # |\n"
          "|  #####    ######  |\n"
          "|       #   #     # |\n"
          "| #     #   #     # |\n"
          "| #####     ######  |\n"
          "---------------------\n";

    printf("\033[1;36m");
    printf("%s", asciiArt);
    printf("\033[0m");
       
    printf("\033[1;94m");
//    printf("\t\t\t");
    getProcessorInfo();
//    printf("\t\t\t");
    getProcessorCores();
//    printf("\t\t\t");
    print_processor_arch();
//    printf("\t\t\t"); 
    print_os();
    print_memory_usage();
    printf("\033[0m");
    puts(" ");
//    puts(" ");

    } else if (strcmp(args[0], "shutdown") == 0) // shutdown 
    {
      shutdown_pc();
    } else if (strcmp(args[0], "mkf") == 0)  // make file
    {
      if (args[1] == NULL) {
            puts("Usage: createfile <filename> <content>");
            return;
        }
        createFile(args[1]);
    } else if(strcmp(args[0], "te") == 0) // test command
    {
        te();
    } else if(strcmp(args[0], "sbcomp") == 0) // shell script compile command
    {
        compile_script();
    } else if(strcmp(args[0], "sbrun") == 0)  // shell script run command
    {
        run_script();
    } else if(strcmp(args[0], "help") == 0)
    {
        puts("https://www.youtube.com/watch?v=GaptpvBASxo&ab_channel=ANCAPSU");  
    } else if(strcmp(args[0], "update") == 0)
    {
       const char *homePath = getenv("HOME");
       const char *relativeFolderPath = "/shellbsrc";
       const char *fileName = "update.sh";

       size_t fullPathLength = strlen(homePath) + strlen(relativeFolderPath) + 1;
       char *fullPath = (char *)malloc(fullPathLength);

       snprintf(fullPath, fullPathLength, "%s%s", homePath, relativeFolderPath);
       char command[256];
       snprintf(command, sizeof(command), "xdg-open %s && cd %s && ./%s", fullPath, fullPath, fileName);
       
       int result = system(command);
       if (result == -1) {
        fprintf(stderr, "Failed to execute command\n");
    }
       free(fullPath);
    }
    else
    { 
        char command[MAX_COMMAND_LENGHT] = {0};  // now running native by default
        strcpy(command, args[0]);                       

        for (int i = 1; args[i] != NULL; i++)
        {
            strcat(command, " ");
            strcat(command, args[i]);
        }

        int result = system(command);

        if (result == -1)
        {
            printf("Error executing command: %s\n", command);
        }
    }
}
