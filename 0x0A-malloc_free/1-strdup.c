#include <stdlib.h>
#include <stdio.h>

/**
 * _strlen - I cannot use strlen()
 * @s: string
 * Return: return size of string \0 included
 */
int _strlen(char *s)
{
	int i;

	i = 0;

	while (*(s + i++) != '\0')
		;
	return (i);
}


/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: string to copy to new space in memory
 * returns a pointer to a newly allocated space in memory, which contains
 * a copy of the string given as a parameter.
 * Return: a pointer to the duplicated string. NULL if insufficient memory
 */
char *_strdup(char *str)
{
	int l, i;
	char *s;

	l = _strlen(str);

	s = malloc((l + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);

	i = 0;
	while (i < l)
		*(s + i++) = *str++;
	return (s);
}