#include "holberton.h"

/**
 * _strcpy - lay man version of strcpy() from strings library
 * @dest: buffer where to copy the string in src
 * @src: string to be copied to dest
 * Return: a pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;

	while ((dest[i] = src[i]) != '\0')
		i++;

	return (dest);
}
