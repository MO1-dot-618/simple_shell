#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

#define DELIMITERS " \n\t"
#define ARGS 10
#define ARGS_SIZE 50

char* find_exe(char *str);
char **token(char *str, char *d);

extern char **environ;

char* find_exe(char *str)
{
	char *line, *command, *file_path = NULL;
	char **paths;
	int i = 0;
	struct stat buffer;

	file_path = malloc (ARGS_SIZE);
	/*check if file exists and is executable*/
	if (stat(str, &buffer) == 0 && buffer.st_mode & S_IXUSR)
	{
		printf("Executable exists! (PATH not checked)\n");
		strcpy(file_path, str);
	}
	else
	{
		line = getenv("PATH");
		if (line == NULL)
			return (NULL);
		paths = token(line, ":");
		command = malloc (ARGS_SIZE);
		while (paths != NULL && paths[i] != NULL)
		{
			/*copy string before using strcat to avoid unexepcted modification of other pointers of paths*/
			strcpy(command, paths[i]);
			command = strcat(command, "/");
			command = strcat(command, str);
			if (stat(command, &buffer) == 0 && buffer.st_mode & S_IXUSR)
			{
				printf("File exists in PATH!\n");
				strcpy(file_path, command);
				break;
			}
			i++;
		}
		/*i = 0;
		while (paths[i] != NULL)
		{
			printf("path to be free: %s\n", paths[i]);
			free(paths[i]);
			i++;
		}
		free(paths);
		free(command);*/
	}
	return (file_path);
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
	char *str, *new_com;
	size_t size = ARGS * ARGS_SIZE;
	char **command;
	int j;
	
	printf("#shell_alx$ ");
	/*We print this at every command line*/
	str = malloc(size);
	getline (&str, &size, stdin);
	/*We get a string containing the command*/

	command = token(str, DELIMITERS);
	new_com = find_exe(command[0]);

	if (execve(new_com, command, environ) == -1)
	{
		printf("Command not found\n");
		free(str);
		free(new_com);
		for (j = 0; j < ARGS_SIZE; j++)
			free(command[j]);
		free(command);
	}
	return (0);
}
