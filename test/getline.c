#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
char **token(char *str)
{
	char **token;
	int i = 0;
	
	token = (char**)malloc(20 * sizeof(char*));
	/* get the first token */
	token[0] = strtok(str, " ");

	/* walk through other tokens */
	while( token != NULL )
	{
		i++;
		token[i] = strtok(NULL, " ");
	}
	return (token);
}

int main()
{
	char *str;
	size_t size = 20;
	char **command;

	printf("#shell_alx$ ");
	/*We print this at every command line*/
	str = malloc(size);
	getline (&str, &size, stdin);
	/*We get a string containing the command*/

	command = token(str);
	if (strcmp(command[0], "pid") == 0)
			execve("./pid", command, NULL);
	else
			printf("Command does not exist\n");

	free(str);
	/*insert code to free command[i] for all i*/
	free(command);
	return (0);
}
