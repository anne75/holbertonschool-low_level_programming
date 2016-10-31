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
 * check_first - check if string in is at the begining of string s
 * @s: string to check
 * @in: string to look for
 * Return: 1 if true, 0 if false
 */
int check_first(char *s, char *in)
{
	int i;

	i = 0;
	if (*in == '\0')
		return (0);
	while (*(s + i) == *(in + i) && *(s + i) != '\0' && *(in + i) != '\0')
		++i;

	if (*(in + i) == '\0')
		return (1);

	return (0);
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
	char *start;

	while ((start = _strchr(haystack, *needle)) != NULL)
	{
		if (check_first(start, needle) == 1)
			return (start);
		haystack = start + 1;
	}
	return (NULL);
}
