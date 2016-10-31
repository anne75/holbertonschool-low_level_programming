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
