#pragma once

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

void remove_directory(const char *path);
char* get_user();
void clear();
char* working_dir();
void shellb();
