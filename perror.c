#include "list.h"

char *int_to_a(int num) {
    char buffer[50];
    int i = 0;
    if (num == 0)
        buffer[i++] = '0';
    else
        while (num > 0)
        {
            buffer[i] = (num % 10) + '0';
            num /= 10;
            i++;
        }
    buffer[i] = '\0';
    rev_string(buffer, i);

    return (_strdup(buffer));

}

void rev_string(char *str, int len)
{
    int beg = 0;
    int end = len - 1;
    char store;

    while (beg < end)
    {
        store = str[beg];
        str[beg] = str[end];
        str[end] = store;
        beg++;
        end--;
    }
}
void c_perror(char *usrnm, int index, char *cmd)
{
    char *_indx;
     
    _indx = int_to_a(index);

    write(STDERR_FILENO, usrnm, _strlen(usrnm));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, _indx, _strlen(_indx));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, cmd, _strlen(cmd));
    write(STDERR_FILENO, ": not found\n", 12);

    free(_indx);
}

