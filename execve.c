#include "list.h"

int exec(char **cmd, char **argv, int index)
{
    pid_t pid;
    int status;
    int exit_status;
    char *f_cmd;

    f_cmd = getsirat(cmd[0]);
    if (f_cmd == NULL)
    {
        c_perror(argv[0], index, cmd[0]);
        fra(cmd);
        return(127);
    }

    pid = fork();
    if (pid == 0)
    {
        if (execve(f_cmd, cmd, environ) == -1)
	{
		free(f_cmd), f_cmd = NULL;
		fra(cmd);
		myexit(2);
        }
    }   else
    {
        waitpid(pid, &status, 0);
        free(f_cmd), f_cmd = NULL;
	fra(cmd);
    }
    if (WIFEXITED(status))
    {
	    exit_status = WEXITSTATUS(status);
	    if (exit_status != 0)
		    return (2);
    }

    return (0);
}

void myexit(int status)
{
	exit(status);
}
