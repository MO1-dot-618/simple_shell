#include "list.h"

int main (int argc, char **argv)
{
	char *line = NULL;
	char **cmd = NULL;
	int status = 0;
	int index = 0;
	int exit_status = 0;
	(void)argc;

	while (1)
	{
		line = get_l();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		index++;
		cmd = tokensh(line);

		if (!cmd)
			continue;
		if (_strcmp(cmd[0], "exit") == 0)
		{
			if (cmd[1])
				exit_status = _atoi(cmd[1]);
			return (exit_status);
		}

		status = exec(cmd, argv, index);
		if (status == 2)
			myexit(2);
	}
	return (status);
}
