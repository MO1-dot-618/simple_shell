#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main (void)
{
    pid_t pid;
    char *argv[] = {"/bin/ls", NULL};

    pid = fork();
    /*  pid = getpid();*/
    if (pid == 0)
    {
        execve(argv[0], argv, NULL);
    }
    else
    {
        wait(NULL);
        printf("\n after execve \n");
    }
    return (0);
}
