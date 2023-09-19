#include "list.h"

/**
  * fra - it frees tha slaves (memory)
  * @arr: array of strings to be freed
  */
void fra(char **arr)
{
	int i;

	if (!arr)
		return;

	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr);
	arr = NULL;
}

