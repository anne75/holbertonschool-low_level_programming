#include "holberton.h"

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
	return (0);
}


/**
 * _strspn - simple version of strspn()
 * @s: string to be analyze
 * @accept: characters to look for s
 * walk through s until reaching a point where a char in s is not in accept.
 * return the length of the walk
 * Return: number of bytes in the initial segment of s ...
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i;

	i = 0;
	while (*(s + i) != '\0')
	{
		if (_strchr(accept, *(s + i)) != 0)
			i++;
		else
			return (i);
	}
	return (i);
}
