#include "holberton.h"
#include <stdio.h>

/**
 * print_diagsums - print the sums of the 2 diagonal of a square matrix
 * @a: pointer to int, start of array
 * @size: size of array
 * Return: void
 */
void print_diagsums(int *a, int size)
{

	int i, sum1, sum2;

	i = 0;
	sum1 = 0;
	sum2 = 0;
	while (i < size)
	{
		sum1 += *(a + i * (size + 1));
		sum2 += *(a + (i + 1) * (size - 1));
		i++;
	}

	printf("%d, %d\n", sum1, sum2);
}
