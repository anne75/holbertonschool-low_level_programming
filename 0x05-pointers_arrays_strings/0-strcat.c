#include "holberton.h"


/**
 *_strcat - lay man version of strcat()
 * @dest: string which will be appended a new one, dest has to be big enough to
 * host src
 * @src: string to append to dest
 * Return: pointer to the resulting dest
 */
char *_strcat(char *dest, char *src)
{
	int l, i;

	l = 0;
	while (*(dest + l) != '\0')
		l++;

	i = 0;
	while ((*(dest + l++) = *(src + i++)) != '\0')
		;
	return (dest);
}
