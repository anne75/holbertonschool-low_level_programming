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

/*similar to question 3
 * to set a value at 0 I need a mask that sets value = 0 for
 * any previous value of the bit. I need to use & 0, in any case
 * bit & 0 = 0.
 * I want to leave other bits untouched, bit & 1 = bit
 * So I want 111101111, it is the exact inverse of the mask at
 * question 3
 */
