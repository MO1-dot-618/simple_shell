#include "list.h"

/**
  * get_l - getline
  * Return: the command input
  */
char *get_l(void)
{
	size_t n = 0;
	char *line = NULL;
	ssize_t s;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	s = getline(&line, &n, stdin);
	if (s == -1)
	{
		free(line), line = NULL;
		return (NULL);
	}
	return (line);
}
