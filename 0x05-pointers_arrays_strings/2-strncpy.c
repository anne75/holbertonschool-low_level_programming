#include "holberton.h"


/**
 * _strncpy - copy at mots n char from src to the beginning of dest
 * @dest: destination string
 * @src: string to copy
 * @n: number of chars to copy
 *
 * Return: pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;

	while (i < n && *(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	while (i < n) /*happens only if I am pasting a src shorter than n string*/
		*(dest + i++) = '\0';

	return (dest);
}
