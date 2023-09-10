#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main (void)
{
    size_t n = 10;
    char *buf = NULL;
    printf("$");
    getline(&buf, &n, stdin);

    printf("%sBuffer size ya akhi houa:%ld\n", buf, n);
    free (buf);
}
