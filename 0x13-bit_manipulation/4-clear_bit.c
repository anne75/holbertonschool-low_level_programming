#include "holberton.h"

/**
 * clear_bit - set the value of bit to 0 at index
 * @n: a number
 * @index: index
 * Return: 1 on success, -1 on error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{

	if (index > (sizeof(unsigned long int) * 8))
		return (-1);

	*n = *n & ~(1 << index);

	return (1);
}

