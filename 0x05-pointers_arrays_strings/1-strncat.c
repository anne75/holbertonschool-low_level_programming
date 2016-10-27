#include "holberton.h"


/**
 * _strncat - adds at most n char from src to dest
 * @dest: string to be appended to
 * @src: string to append in part or no to dest
 * @n: number of char to append, at most
 *
 * Return: pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int l, i;

	l = 0;
	while (*(dest + l) != '\0')
		l++;

	i = 0;
	while (i < n && *(src + i) != '\0')
	{
		*(dest + l++) = *(src + i++);
	}

	if (i == n && *(dest + l) != '\0')
		*(dest + l++) = '\0';

	return (dest);
}
