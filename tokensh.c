#include "list.h"

char **tokensh(char *line)
{
    char *cmd= NULL, *token = NULL;
    char *delim = " \t\n";
    int argc = 0, i = 0;
    char **argv = NULL;

    if (!line)
        return (NULL);

    cmd = _strdup(line);
    token = strtok(cmd, delim);

    if (token == NULL)
    {
        free(line), line = NULL;
        free(cmd), cmd = NULL;
        return (NULL);
    }
    while(token)
    {
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

    while(token)
    {
        argv[i] = _strdup(token);
        token = strtok(NULL, delim);
        i++;
    }
    argv[i] = NULL;
    free(line), line = NULL;
    return (argv);
}

