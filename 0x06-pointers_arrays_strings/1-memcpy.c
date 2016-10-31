#include "holberton.h"

/**
 * _memcpy - simple version of memcopy()
 * @dest: memory area to print to
 * @src: memoy area to print from
 * @n: number of bytes to copy from src to dest
 *
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	return (dest);
}
