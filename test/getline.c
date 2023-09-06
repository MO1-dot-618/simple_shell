#include <stdlib.h>
#include <stdio.h>
int main()
{
	char *str;
	size_t size = 20;

	printf("\"$ \"");
	str = malloc(size);
	if (getline (&str, &size, stdin) == -1)
		printf("ERROR!");
	else
		printf("%s", str);
	free(str);
	return (0);
}
