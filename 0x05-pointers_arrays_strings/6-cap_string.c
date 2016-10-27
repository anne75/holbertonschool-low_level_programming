#include "holberton.h"
#include <stdio.h>

/**
 * sep - check if a char is a word separator
 * @c: char to check
 * Return: 1 if true, 0 otherwise
 */
int sep(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' ||
	    c == ',' || c == ';' || c == '.' || c == '!' ||
	    c == '?' || c == '"' || c == '(' || c == ')' ||
	    c == '{' || c == '}')
		return (1);
	return (0);
}

/**
 * _islower - check if char is lower case letter
 * @c: character to check
 * Return: 1 if true 0 if false
 */
int _islower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}


/**
 * cap_string - capitalizes all words in a string
 * @s: string to capitalize
 * Return: pointer to s
 */
char *cap_string(char *s)
{
	int i;

	i = 0;

	if (_islower(*s) == 1)
	{
		*s = *s -'a' + 'A';
		i++;
	}

	while (*(s + i) != '\0')
	{
		if (sep(*(s + i)) == 1 && *(s + i + 1) != '\0' &&
			_islower(*(s + i + 1)) == 1)
		{
			*(s + i + 1) = *(s + i + 1) - 'a' + 'A';
			i++;
		}
		i++;
	}
	return (s);
}
