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
#define PROMPT "$ "
#define BUFFER_SIZE 1024
#define MAX_TOKENS 1024

int hello_betty(void);
char *_getinput();
int execute(char *argv[]);
void free_error(char *argv[], char *arg);
void free_tokens(char **pnt);
void free_path(void);
char *get_insert(void);
void free_last_insert(void);
char **tokenize(char *str, const char *delim);
char **tokenize_insert(char *insert)
int _strcmp(const char *str1, const char *str2);
int _strlen(char *str);
int _strncpy(char *dest, char *src, int size);
void *_memcpy(void *dest, void *src, size_t n);
void *_realloc(void *ptr, size_t size);

#endif
