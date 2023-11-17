#ifndef SHELL_H
#define SHELL_H
#define _GNU_SRC

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <limits.h>
#include <fcntl.h>
#include <stdarg.h>
#include <ctype.h>

#define PATH_MAX_LENGTH 4096
#define PATH_SEPERATE ":"
#define PROMPT "simple_shell$ "

int hello_betty(void);
int execute(char *argv[]);
void prompt(void);


char *get_path(void);

char *find_in_path(char *command);

void free_error(char *argv[], char *arg);
void free_token(char **pnt);
void free_path(void);
