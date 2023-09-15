#include "list.h"

int main (int argc, char **argv)
{
	char *line = NULL;
	char **cmd = NULL;
	int status = 0;
	int index = 0;
	(void) argc;

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
		status = exec(cmd, argv, index);
	}
}
