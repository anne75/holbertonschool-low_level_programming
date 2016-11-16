#include <stdlib.h>

/**
 * int_index - searches for an integer using cmp function
 * @array: array to search
 * @size: size of array
 * @cmp: matching function
 * Return: index of first matching element, if no match -1
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (cmp == NULL)
		return (-1);

	i = 0;
	while (i < size)
	{
		if (cmp(array[i]) != 0)
			return (i);
		i++;
	}
	return (-1);
}
