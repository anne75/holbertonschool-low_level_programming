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
 * _strpbrk - simple version of strpbrk()
 * @s: string to be analyzed
 * @accept: characters to look for in s
 * walk through s until reaching a point where a char in s is in accept.
 * return a pointer to this byte
 * Return: a pointer to the byte in s that matches one of the bytes in accept
 */
char *_strpbrk(char *s, char *accept)
{
	unsigned int i;

	i = 0;
	while (*(s + i) != '\0')
	{
		if (_strchr(accept, *(s + i)) != 0)
			return (s + i);
		i++;
	}
	return (0);
}
