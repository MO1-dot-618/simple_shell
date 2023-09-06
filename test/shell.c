#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
char **token(char *str)
{
	char **token;
	int i = 0, j;
	const int args = 10, size_arg = 10;
	
	token = (char**)malloc(args * sizeof(char*));
	for (j = 0; j < args; j++)
		token[j] = malloc(size_arg);
	/* get the first token */
	token[0] = strtok(str, " ");
	printf("token : %s\n",token[i]);

	/* walk through other tokens */
	while( token != NULL && i < 19)
	{
		i++;
		token[i] = strtok(NULL, " ");
		printf("token : %s\n",token[i]);
	}
	return (token);
}

int main()
{
	char *str;
	size_t size = 100;
	char **command;
	int j;
	const int arg_size = 10;

	printf("#shell_alx$ ");
	/*We print this at every command line*/
	str = malloc(size);
	getline (&str, &size, stdin);
	/*We get a string containing the command*/

	command = token(str);
	if (strcmp(command[0], "pid\0") == 0)
			execve("./pid", command, NULL);
	else
			printf("Command does not exist\n");

	free(str);
	/*insert code to free command[i] for all i*/
	for (j = 0; j < arg_size; j++)
		free(command[j]);
	free(command);
	return (0);
}
