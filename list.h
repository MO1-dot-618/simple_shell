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

extern char **environ;
#endif
