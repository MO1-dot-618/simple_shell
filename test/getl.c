#include "list.h"

char *get_l (void)
{
    size_t n = 0;
    char *line = NULL;
    ssize_t s;
    write(STDOUT_FILENO, "$ ", 2);
    s = getline(&line, &n, stdin);
    if (s == -1)
    {
        free(line);
        return (NULL);
    }

    return (line);
}
