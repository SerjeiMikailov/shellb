#include "App.h"

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
                system("./externals/wsl_shutdown.sh");
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
    printf("\033[1;96m-  Beta V1.07  -\033[0m\n");
    printf("\033[1;36m----------------\033[0m\n");
}
