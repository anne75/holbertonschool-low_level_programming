#include "holberton.h"


/**
 * _memset - simple version of memset()
 * @s: buffer to modify
 * @b: value to modify buffer with
 * @n: number of bytes pointed to by s to modify with char b
 *
 * Return: pointer to buffer, s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	i = 0;

	while (i < n)
		*(s + i++) = b;

	return (s);
}
