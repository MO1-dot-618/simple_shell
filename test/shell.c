#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define DELIMITERS " \n\t"
#define ARGS 10
#define ARGS_SIZE 10

int exc(char *str, char **c);
char **token(char *str, char *d);

extern char **environ;

int exc(char *str, char **c)
{
	char *line, *command;
	char **paths;
	int i = 0;

	line = getenv("PATH");
	if (line != NULL)
	{
		paths = token(line, ":");
		while (paths[0] != NULL)
		{
			printf("%s\n", paths[i]);
			i++;
		}
		i = 0;
		line = NULL;
		while (paths != NULL)
		{
			printf("some path: %s\n", paths[i]);
			command = strcat(paths[i], "/");
			command = strcat(command, str);
			if (execve(command, c, NULL) != -1)
			{
				printf("right path: %s\n", paths[i]);
				i = 0;
				while (paths[0] != NULL)
				{
					free(paths[i]);
					i++;
				}
				free(paths);
				return (1);
			}
			i++;
		}
	}
	return (0);
}

char **token(char *str, char *d)
{
	char **token;
	int i = 1, j;
	
	token = (char**)malloc(ARGS * sizeof(char*));
	for (j = 0; j < ARGS; j++)
		token[j] = malloc(ARGS_SIZE);
	/* we get the first token */
	token[0] = strtok(str, d);

	/* then the other tokens */
	while( i < ARGS)
	{
		token[i] = strtok(NULL, d);
		if (token[i] == NULL)
			break;
		i++;
	}
	return (token);
}

int main()
{
	char *str;
	size_t size = ARGS * ARGS_SIZE;
	char **command;
	int j, ex;
	
	printf("#shell_alx$ ");
	/*We print this at every command line*/
	str = malloc(size);
	getline (&str, &size, stdin);
	/*We get a string containing the command*/

	command = token(str, DELIMITERS);
	/*We divide the string into separate arguments/tokens */
	if (execve(command[0], command, NULL) != -1)
		return (0);
	if (exc(command[0], command) == 0)
		printf("Command not found\n");
	free(str);
	
	/*insert code to free command[i] for all i*/
	for (j = 0; j < ARGS_SIZE; j++)
		free(command[j]);
	free(command);
	return (0);
}
