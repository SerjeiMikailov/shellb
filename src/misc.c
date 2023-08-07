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
  const char *homeDir = getenv("HOME");
  char compileCommand[256];
  
  snprintf(compileCommand, sizeof(compileCommand), "(cd %s/shellbsrc && ./run.sh)", homeDir);
  int result = system(compileCommand);

  if(result == 0) {
    puts("Compiled with success");
  } else {
    puts("Error during compilation");
  }

  // system("(cd $HOME/shellbsrc && ./run.sh)");
  //puts("Compiled with success");
}

void run_script(void)
{
  system("(cd $HOME/shellbsrc && ./shellscript)"); 
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
    printf("\033[1;96m-  Beta V1.11  -\033[0m\n");
    printf("\033[1;36m----------------\033[0m\n");
}
