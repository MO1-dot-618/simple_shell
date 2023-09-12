#include "list.h"

/**
  * get_l - function that will display the prompt and take commands
  * no input
  * Return: a pointer to the command written
  * or NULL if there is an error
  */
char *get_l(void)
{
	size_t n = 0;
	char *line = NULL;

	write(STDOUT_FILENO, "$ ", 2);
	if (getline(&line, &n, stdin) == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

/**
  * tokensh - converts a string into an array of tokens
  * @line: string to convert
  * @delim: delimeter
  * Return: a pointer to the array of tokens
  */
char **tokensh(char *line, char *delim)
{
	char *cmd = NULL, *token = NULL;
	int argc = 0, i = 0;
	char **argv = NULL;

	if (!line)
		return (NULL);

	cmd = strdup(line);
	token = strtok(cmd, delim);

	if (token == NULL)
	{
		free(line), line = NULL;
		free(cmd), cmd = NULL;
		return (NULL);
	}
	while (token)
	{
		/* we get the number of tokens before allocating */
		token = strtok(NULL, delim);
		argc++;
	}

	argv = malloc(sizeof(char *) * (argc + 1));
	if (!argv)
	{
		free(line), line = NULL;
		return (NULL);
	}
	token = strtok(line, delim);

	while (token)
	{
		argv[i] = strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	argv[i] = NULL;
	free(line), line = NULL;
	return (argv);
}

/**
  * find_exe - searches for an executable in the given path
  *		or looks for it in the PATH env variable
  * @str: command input
  * Return: the full path to the command if it exists
  *		Otherwise - NULL
  */
char *find_exe(char *str)
{
	char *line, *command, *file_path = NULL;
	char **paths;
	int i = 0;
	struct stat buffer;

	file_path = malloc(ARGS_SIZE);
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
		printf("PATH tokened\n");
		command = malloc(ARGS_SIZE);
		
		while (paths != NULL && paths[i] != NULL)
		{
			printf("searching path : %s\n",paths[i]);
			/*copy string before using strcat to avoid unexepcted behavior*/
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
