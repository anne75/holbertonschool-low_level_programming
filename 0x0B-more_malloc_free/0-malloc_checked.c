#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>


/**
 * malloc_checked - allocate memory with malloc
 * @b: size of space in memory to allocate
 * Return: void, if any pb with malloc exit(98)
 */
void *malloc_checked(unsigned int b)
{
	void *p;

	p = malloc(b);
	if (p == NULL)
		exit(98);

	return (p);
}
