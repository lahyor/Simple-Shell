#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys.stat.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#define BUFFER_SIZE 1024

int hello_betty(void);
char *_getinput();
int exec_command(char **args)
char **tokenize(char *line)
int interp(int args, char *argv[])
int _strcmp(const char *str1, const char *str2);
int _strlen(char *str);
int _strncpy(char *dest, char *src, int size);
void *_memcpy(void *dest, void *src, size_t n);
void *_realloc(void *ptr, size_t size);

#endif
