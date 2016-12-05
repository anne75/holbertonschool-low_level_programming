#include "holberton.h"


/**
 * binary_to_uint - convert a binary number to an unsigned int
 * @b: a string that should consists of 0 and 1
 * Return: the number
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int n;

	if (!b)
		return (0);

	n = 0;
	while (*b != '\0')
	{
		if (*b != '0' && *b != '1')
			return (0);
		n = 2 * n + *b - '0';
		++b;
	}
	return (n);
}
