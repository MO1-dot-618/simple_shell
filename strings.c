#include "list.h"
#include <stdlib.h>
#include <stddef.h>
/**
  * _strdup - returns pointer to a duplicate string
  * @str: string to be duplicated
  * Return: NULL if NULL, otherwise location of duplicated string
  **/

char *_strdup(char *str)
{
	char *dup;
	int i, j;

	if (str == NULL)
	{
		return (NULL);
	}

	for (i = 0; str[i] != '\0'; i++)
		;
	dup = (char *)malloc(sizeof(char) * (i + 1));
	if (dup == NULL)
	{
		return (NULL);
	}

	for (j = 0; j <= i; j++)
	{
		dup[j] = str[j];
	}

	return (dup);
}

/**
 * _strcmp - compares two strings
 * @s1: first string.
 * @s2: second string.
 * Return: 0 if s1 and s2 are equals,
 * another number if not.
 */
int _strcmp(char *s1, char *s2)
{
	int l1 = 0, l2 = 0, i;

	while (l1 >= 0)
	{
		if (s1[l1] == '\0')
			break;
		l1++;
	}
	while (l2 >= 0)
	{
		if (s2[l2] == '\0')
			break;
		l2++;
	}
	for (i = 0; i < l1 || i < l2; i++)
	{
		if (s1[i] - s2[i] != 0)
			return (s1[i] - s2[i]);
	}
	return (0);
}
/**
 * _strlen - returns the length of a string.
 * @s: input string.
 * Return: length of a string.
 */
int _strlen(char *s)
{
	int count = 0;

	while (*(s + count) != '\0')
		count++;
	return (count);
}

/**
 * _strcat - concatenates two strings,
 * @dest: destination.
 * @src: source.
 * Return: the pointer to dest.
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	/* Find the end of str1 */
	for (i = 0; dest[i] != '\0'; i++)
	{
		continue;
	}

	for (j = 0; src[j] != '\0'; i++, j++)
	{
		/* Append str2 to the end of str1 */
		dest[i] = src[j];
	}
	dest[i] = '\0';
	/* Add null terminator to complete the concatenated string */
	return (dest);
}
/**
 * _strcpy - copies the string pointed to by src,
 * including the terminating null byte, to the
 * buffer pointed to by dest.
 * @dest: destination.
 * @src: source.
 * Return: the pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
	int count = 0;

	while (count >= 0)
	{
		*(dest + count) = *(src + count);
		if (*(src + count) == '\0')
			break;
		count++;
	}
	return (dest);
}
