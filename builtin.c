#include "list.h"

int get_built (char *cmd)
{
    int i;
    char *buil[2] = {
        "exit", "env"
    };
    for (i = 0; i < 2; i++)
    if (_strcmp(cmd, buil[i]) == 0)
        return (1);
    return (0);
}

void hand_built(char **cmd, char **argv, int *status, int index)
{
    if (_strcmp(cmd[0], "exit") == 0)
	    myexit(cmd, argv, status, index);
    else if (_strcmp(cmd[0], "env") == 0)
	    my_p_env(cmd, status);
}

void myexit(char **cmd, char **argv, int *status, int index)
{
    char *idx;
    int last_cmd_value = (*status);

    if (cmd[1])
    {
        if (is_pos_string(cmd[1]))
            last_cmd_value = _atoi(cmd[1]);
        else
        {
            idx = int_to_a(index);
            write(STDERR_FILENO, argv[0], _strlen(argv[0]));
            write(STDERR_FILENO, ": ", 2);
            write(STDERR_FILENO, idx, _strlen(idx));
            write(STDERR_FILENO, ": exit: Illegal number: ", 24);
            write(STDERR_FILENO, cmd[1], _strlen(cmd[1]));
            write(STDERR_FILENO, "\n", 1);
            free(idx);
            fra(cmd);
            (*status) = 2;
            return;
	}
    }
    fra(cmd);
    exit(last_cmd_value);
}
void my_p_env(char **cmd, int *status)
{
    int i;
    for (i = 0; environ[i]; i++)
    {
        write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
        write(STDOUT_FILENO, "\n", 1);
    }
    fra(cmd);
    (*status) = 0;
}
