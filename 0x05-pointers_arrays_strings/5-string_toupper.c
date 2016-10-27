#include "holberton.h"


/**
 * string_toupper - changes lowercases lettes to uppercases
 * @s: string to modify
 * Return: pointer to s
 */
char *string_toupper(char *s)
{
	int i;

	i = 0;

	while (*(s + i) != '\0')
	{
		if (*(s + i) >= 'a' && *(s + i) <= 'z')
			*(s + i) = *(s + i) - 'a' + 'A';
		i++;
	}
	return (s);
}
