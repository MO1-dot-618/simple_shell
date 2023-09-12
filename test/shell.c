#include "list.h"

/**
  * main - command line interpreter
  * Return: 0 (success)
  */

int main(void)
{
	char *command, *new_com;
	char **args;
	pid_t pid;

	while (1)
	{
		command = get_l();
		args = tokensh(command, DELIMITERS);
		new_com = find_exe(args[0]);
/* continue the first process after the child process is executed*/
		pid = fork();
		if (pid == 0)
		{
			if(execve(new_com, args, environ) == -1)
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
		else
			wait(NULL);
	}
	return (0);
}
