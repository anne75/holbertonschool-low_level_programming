#include "holberton.h"
#include <stdio.h>

/**
 * _strchr - simple version of strchr()
 * @s: string in which we want to locate given byte
 * @c: char or byte to locate, \0 works
 *
 * Return: pointer to first occurence of c or NULL otherwise
 */
char *_strchr(char *s, char c)
{
	int i;

	i = 0;

	while (*(s + i) != '\0')
	{
		if (*(s + i) == c)
			return (s + i);
		i++;
	}
	if (c == '\0')
		return (s + i);
	return (NULL);
}


/**
 * _strstr - finds the first occurrence of the substring needle in the string
 * haystack
 * @haystack: string to explore
 * @needle: string to look for
 * Return: pointer to the beginning of the located substring, or NULL if the
 * substring is not found.
 */

char *_strstr(char *haystack, char *needle)
{
	int i;
	char *start;

	start = _strchr(haystack, *needle);
	if (start == NULL || *needle == '\0')
		return (NULL);

	i = 0;
	while (*(start + i) == *(needle + i)
	       && *(start + i) != '\0' && *(needle + i) != '\0')
	{

		i++;

	}

	if (*(needle + i) == '\0')
		return (start);

	return (0);
}
