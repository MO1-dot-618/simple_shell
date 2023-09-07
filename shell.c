#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define DELIMITERS " \n\t\r"
#define ARGS 10
#define ARGS_SIZE 10

char **token(char *str)
{
	char **token;
	int i = 1, j;
	
	token = (char**)malloc(ARGS * sizeof(char*));
	for (j = 0; j < ARGS; j++)
		token[j] = malloc(ARGS_SIZE);
	/* we get the first token */
	token[0] = strtok(str, DELIMITERS);

	/* then the other tokens */
	while( i < ARGS)
	{
		token[i] = strtok(NULL, DELIMITERS);
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
	int j;
	extern char **environ;

	printf("#shell_alx$ ");
	/*We print this at every command line*/
	str = malloc(size);
	getline (&str, &size, stdin);
	/*We get a string containing the command*/

	command = token(str);
	/*We divide the string into separate arguments/tokens */
	if (strcmp(command[0], "pid") == 0)
			execve("/bin/ls", command, environ);
	else
			printf("Command does not exist\n");

	free(str);
	/*insert code to free command[i] for all i*/
	for (j = 0; j < ARGS_SIZE; j++)
		free(command[j]);
	free(command);
	return (0);
}
