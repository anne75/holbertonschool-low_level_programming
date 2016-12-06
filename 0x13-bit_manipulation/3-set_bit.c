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

/*
 *check index is inside my number in binary
 *to set the value to one at index, I would need to find
 *a mask that does not touch anything but the bit at index, and
 *make this one 1. the only possibility to set a bit to 1
 *when it was already 1 is to use or | then if I do 0 | bit, it
 *will leave the value as is.
 *So I need a mask with a 1 at index and 0 anywhere else
 *to do that I take the value of 1 = 0000000001, and switch it to the
 *left by index that way I push the 1 to the left, so it stands at index
 *and it is padded with 0 to the right
 */
