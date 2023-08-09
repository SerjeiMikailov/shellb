#include "App.h"
#include <stdio.h>

void clear(void)
{
    #ifdef _WIN32
        system("cls");  
    #else
        system("clear");
    #endif
}

void shutdown_pc(void)
{
  #ifdef __linux__
    FILE* fp = popen("uname -a", "r");
        if (fp == NULL) {
            printf("Error determining system information.\n");
            return;
        }
        char buffer[128];
        if (fgets(buffer, sizeof(buffer), fp) != NULL) {
            if (strstr(buffer, "Microsoft") != NULL) {
                system("shutdown -s -f -t 0");
            } else {
                system("shutdown -h now");
            }
        }
        pclose(fp);
  #elif _WIN32
    system("./externals/shutdown.bat");
  #else
    puts("Not supported");
  #endif
}

void compile_script(void)
{
  // system("(cd $HOME/shellbsrc && sh run.sh)");
  system("(cd $HOME/projects/shellb/script_area/compiler/ && sh test.sh)");
  puts("Compiled with success");
}

void run_script(void)
{
  system("(cd $HOME/projects/shellb/script_area/bin/ && ./shellscript)");
  // system("(cd $HOME/shellbsrc && ./shellscript)"); 
}

char* working_dir(void) {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        return strdup(cwd);
    } else {
        perror("getcwd() error");
        return NULL; 
    }
}

void shellb(void) {
    printf("\033[1;36m----------------\033[0m\n");
    printf("\033[1;96m-    ShellB    -\033[0m\n");
    printf("\033[1;96m-  Main V1.12  -\033[0m\n");
    printf("\033[1;36m----------------\033[0m\n");
}
