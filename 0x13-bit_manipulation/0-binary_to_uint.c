#include "holberton.h"
#include <stdio.h>

/**
 * binary_to_uint - convert a binary number to an unsigned int
 * @b: a string that should consist of 0 and 1
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
		n =  (n << 1) + *b - '0';
		++b;
	}
	return (n);
}

/*
 *it works the same way as atoi or print_numbers
 *loop through the string, each loop moves one position to the right
 *so one power of 2 less, to reconstruct the number,
 * multiply what we have by 2 and add what we have at this position
 */
