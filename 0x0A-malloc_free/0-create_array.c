#include "holberton.h"
#include <stdlib.h>

/**
 * create_array - creates an array of char, initializes with c
 * @size: size of array to create
 * @c: char to initialize array with
 * Return: pointer to created array
 */
char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *p;

	if (size <= 0)
		return (NULL);
	p = malloc(sizeof(char) * size);
	if (p == NULL)
		return (NULL);

	i = 0;
	while (i < size)
		p[i++] = c;

	return (p);
}
