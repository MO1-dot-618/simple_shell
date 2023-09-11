#include "list.h"

int main (int argc, char **argv)
{
    char *line = NULL;
    char **cmd = NULL;
    int i, status = 0;
   (void) argc;
    (void) argv;

    while (1)
    {
        line = get_l();
        if (line == NULL)
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            return (status);
        }
        cmd = tokensh(line);
        if (!cmd)
            continue;
        for (i = 0; cmd[i]; i++)
            printf("%s\n", cmd[i]);
    }

}
