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

char* working_dir() {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        return strdup(cwd);
    } else {
        perror("getcwd() error");
        return NULL; 
    }
}

void print_memory_usage() {
    struct rusage usage;
    if (getrusage(RUSAGE_SELF, &usage) == 0) {
        long ram_usage = usage.ru_maxrss;
        printf("Memory usage: %ld KB\n", ram_usage);
    } else {
        puts("Failed to retrieve memory usage");
    }
}

void shellb() {
    printf("\033[1;36m----------------\033[0m\n");
    printf("\033[1;96m-    ShellB    -\033[0m\n");
    printf("\033[1;96m-  Beta V1.07  -\033[0m\n");
    printf("\033[1;36m----------------\033[0m\n");
}
