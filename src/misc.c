#include "App.h"

void clear()
{
    #ifdef _WIN32
        system("cls");  
    #else
        system("clear");
    #endif
}

char* get_user() {
    return getenv("USER");
}

void working_dir()
{
    char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) != NULL)
        {
            printf("Current working dir: %s\n", cwd);
        }
        else
        {
            perror("getcwd() error");
        }
}

void shellb() {
    puts("----------------");
    puts("-    ShellB    -");
    puts("-  Beta V1.06  -");
    puts("----------------");
}
