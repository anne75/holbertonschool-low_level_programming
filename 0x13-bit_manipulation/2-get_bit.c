#include "holberton.h"
#include <stdio.h>

/**
 * get_bit - return the value of a bit at a given index
 * @n: a number
 * @index: index of bit
 * Return: the bit, or -1 if error
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int b;

	if (index > sizeof(unsigned long int) * 8)
	return (-1);

	b = (n >> index) & 1;

	return (b);
}
