#include "list.h"

/**
  * getsirat - checks if executable exists
  * @command: executable
  * Return: command with full path
  */
char *getsirat(char *command)
{
	char *path_environ, *f_cmd, *list;
	struct stat s;

    /*Case 1: command already exists*/
	if (stat(command, &s) == 0 && s.st_mode & S_IXUSR)
		return (_strdup(command));

    /*Case 2: User uses the command unset to delete the path*/
	path_environ = getenviron("PATH");
	if (!path_environ)
	{
		return (NULL);
	}

    /*Case 3: Path must be handled*/
	list = strtok(path_environ, ":");

	while (list)
	{
		f_cmd = malloc(_strlen(list) + _strlen(command) + 2);
		if (f_cmd)
		{
			_strcpy(f_cmd, list);
			_strcat(f_cmd, "/");
			_strcat(f_cmd, command);
			if (stat(f_cmd, &s) == 0 && (s.st_mode & S_IXUSR))
			{
				free(path_environ), path_environ = NULL;
				return (f_cmd);
			}
			free(f_cmd), f_cmd = NULL;
			list = strtok(NULL, ":");
		}
	}
	free(path_environ), path_environ = NULL;
	return (NULL);
}

/**
  * getenviron - gets the environment variable
  * @var: variable
  * Return: the value of var
  */
char *getenviron(char *var)
{
	char *temp, *key, *value, *value_cpy;
	int i;

	for (i = 0; environ[i]; i++)
	{
		temp = _strdup(environ[i]);
		key = strtok(temp, "=");
		if (_strcmp(key, var) == 0)
		{
			value = strtok(NULL, "\n");
			value_cpy = _strdup(value);
			free(temp), temp = NULL;
			return (value_cpy);
		}
		free(temp), temp = NULL;
	}
	return (NULL);
}
