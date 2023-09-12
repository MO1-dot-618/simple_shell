#include "list.h"

int exec(char **cmd, char **argv)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0)
    {
        if (execve(cmd[0], cmd, environ) == -1)
        {
            perror(argv[0]);
            free(cmd);
	    exit(0);
        }
    }
    else
    {
        waitpid(pid, &status, 0);
        free(cmd);
    }
    return (WEXITSTATUS(status));
}
