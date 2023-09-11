#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main (void)
{
    pid_t pid = getpid();
    char *argv[] = {"/bin/ls", "-l", NULL};
    fork();

    if (pid == 0)
    {
        execve(argv[0], argv, NULL);
    }
    else
    {
        wait(NULL);
        printf("I am alive! %d", pid);
    }
}
