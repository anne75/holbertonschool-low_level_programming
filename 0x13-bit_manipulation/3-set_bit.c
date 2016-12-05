#include "holberton.h"

/**
 * set_bit - set value of a bit to 1 at given index
 * @n: pointer to number
 * @index: index
 * Return: 1 if worked, -1 if error
 */
int set_bit(unsigned long int *n, unsigned int index)
{

	if (index > (sizeof(unsigned long int) * 8))
		return (-1);

	*n = *n | (1 << index);

	return (1);
}
