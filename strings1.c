#include "list.h"

/**
  * _strstr - function that loactes character
  * in a string.
  * @haystack: string to checked
  * @needle: substring to be found
  * Return: location of first encounter, otherwise NULL.
  **/

char *_strstr(char *haystack, char *needle)
{
	char *a;
	char *b;

	while (*haystack != '\0')
	{
		a = haystack;
		b = needle;

		while (*haystack != '\0' && *b != '\0' && *haystack == *b)
		{
			haystack++;
			b++;
		}
		if (!*b)
			return (a);
		haystack = a + 1;
	}
	return (0);
}
/**
 * _atoi - converts a string to an integer.
 * @s: input string.
 * Return: integer.
 */

int _atoi(char *s)
{
	unsigned int count = 0, size = 0, oi = 0, pn = 1, m = 1, i;

	while (*(s + count) != '\0')
	{
		if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;

		if (*(s + count) == '-')
			pn *= -1;

		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		count++;
	}

	for (i = count - size; i < count; i++)
	{
		oi = oi + ((*(s + i) - 48) * m);
		m /= 10;
	}
	return (oi * pn);
}
