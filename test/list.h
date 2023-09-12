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
extern char **environ;

int exec(char **cmd, char **argv);
char **tokensh(char *line);
char *get_l (void);

#endif
