#include "holberton.h"

/**
 * reverse_array - reverse elements of array
 * @a: array to reverse
 * @n: nb of elements in array
 * Return: void
 */
void reverse_array(int *a, int n)
{
	int i, tmp;

	i = 0;
	while (i < n / 2)
	{
		tmp = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = tmp;
		i++;
	}
}
