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

/*
 *check if the index is included in the number
 *in that case, I want to switch index bits to the right of n so that
 *the rightmost digit is the bit at the index.
 *I then apply a mask 00000....1 so that all is put to 0 except the last bit
 *which is left intact
 */
