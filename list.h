#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

#define DELIMITERS " \n\t"
#define ARGS 10
#define ARGS_SIZE 50

char *find_exe(char *str);
char **tokensh(char *line, char *delim);
char *get_l(void);

char *_strncpy(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);

extern char **environ;
#endif
