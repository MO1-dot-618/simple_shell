#include "list.h"

int exec(char **cmd, char **argv, int index)
{
    pid_t pid;
    int status;
    char *f_cmd;

    f_cmd = getsirat(cmd[0]);
    if (f_cmd == NULL)
    {
        c_perror(argv[0], index, cmd[0]);
        free(cmd), cmd = NULL;
        return(127);
    }

    pid = fork();
    if (pid == 0)
    {
        if (execve(f_cmd, cmd, environ) == -1)
        {
            free(f_cmd), f_cmd = NULL;
	  /*  while (*cmd)
	    {
		    free(*cmd); cmd = NULL;
		    cmd++;
	    }
            free(cmd), cmd = NULL;*/
        }
    }   else
    {
        waitpid(pid, &status, 0);
        free(f_cmd), f_cmd = NULL;
	/*while (*cmd)
	{
		free(*cmd); cmd = NULL;
		cmd++;
	}
        free(cmd), cmd = NULL;*/
    }
    return (WEXITSTATUS(status));
}
