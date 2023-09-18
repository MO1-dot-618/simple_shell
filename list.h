#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

#define DELIMITERS " \n\t"
#define ARGS 10
#define ARGS_SIZE 50

char *getenviron(char *var);
char *getsirat(char *command);
int exec(char **cmd, char **argv, int index);
char **tokensh(char *line);
char *get_l(void);
void c_perror(char *usrnm, int index, char *cmd);
void fra(char ** arr);
void myexit(int status);

char *_strcpy(char *dest, char *src);
char *int_to_a(int num);
char *_strstr(char *haystack, char *needle);
void rev_string(char *str, int len);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);
char *_strdup(char *str);

extern char **environ;
#endif
