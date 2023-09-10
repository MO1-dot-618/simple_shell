#include <stdio.h>
#include <unistd.h>

int main (void)
{
    pid_t pid;
   //printf("Before fork I was alone\n");
    int id = fork();
    if (pid == -1)
    {
        perror("Unsuccessful fucko\n");
        return (1);
    }
    if (id == 0){
        sleep(30);
        printf("ana tifl (pid: %u, ppid: %u)\n", getpid(), getppid());
    } else {
        printf("ana bak\n (pid: %u)\n", getpid());
	sleep(10);
    }
    return (0);
}
