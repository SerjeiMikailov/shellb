#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>
#include <sys/resource.h>

#define MAX_COMMAND_LENGHT 100
#define MAX_ARGS 20
#define MAX_PATH 50000

// commands
void execute_command(char **args);

// reader functions
void read_command(char *command);
void parse_command(char *command, char **args);

// system level executions
void executeSystemCommand(const char* command);

// get system info
void getProcessorCores(void);
void getProcessorInfo(void);
void print_memory_usage(void);
void print_os(void); 
void print_processor_arch(void);
char* get_user(void);

// misc
void shutdown_pc(void);
void remove_directory(const char *path);
void clear(void);
char* working_dir(void);
void shellb(void);
