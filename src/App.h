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

// misc
void print_memory_usage();
void remove_directory(const char *path);
char* get_user();
void clear();
char* working_dir();
void shellb();
