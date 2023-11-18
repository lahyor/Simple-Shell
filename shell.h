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

extern char **environ;

int hello_betty(void);
void prompt(void);
char *_getinput();
int execute(char *argv[]);
char *get_path(void);
char *find_in_path(char *command);
void free_error(char *argv[], char *arg);
void free_tokens(char **pnt);
void free_path(char **environs);
char *get_insert(void);
void free_last_insert(void);
char **tokenize(char *str, const char *delim);
char **tokenize_insert(char *insert);
void _puterrors(char *err);
void _puts(char *str);
char *_getenv(const char *name);
int check_for_builtin(char **args);
int _strlen(const char *);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strstr(char *haystack, char *needle);
char *_strchr(char *s, char c);
char *_strcpy(char *, char *);
char *_strcat(char *, const char *);
char *_strdup(const char *);
int _putchars(char);
unsigned int _strspn(char *s, char *accept);
int _atoi(const char *str);
char *_memset(char *, char, unsigned int);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *, unsigned int, unsigned int);
void *_calloc(unsigned int nmemb, unsigned int size);
void handle_sigint(int sign);
void handle_sigquit(int sign);
void handle_sigtstp(int sign);

#endif
