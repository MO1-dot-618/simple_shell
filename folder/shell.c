#include "list.h"

/**
  * main - command line interpreter
  * Return: 0 (success)
  */

int main(void)
{
	char *command, *new_com;
	char **args;

	while (1)
	{
		command = get_l();
		args = tokensh(command, DELIMITERS);
		new_com = find_exe(args[0]);

		if (execve(new_com, args, environ) == -1)
		{
			printf("Command not found\n");
			free(command);
			free(new_com);
			while (*args)
			{
				free(*args);
				args++;
			}
			free(args);
		}
	}
	return (0);
}
