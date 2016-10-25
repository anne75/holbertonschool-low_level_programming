#include "holberton.h"
#include <stdio.h>

/**
 * print_array - print n elements of an array
 * @a: pointer to an int, pointer to first element of array
 * @n: number of elements to print
 * Return: void
 */
void print_array(int *a, int n)
{
	int i;

	if (n == 0)
	{
		printf("\n");
	}
	else
	{
		i = 0;

		while (i < (n - 1))
		{
			printf("%d, ", *(a + i));
			i++;
		}
		printf("%d\n", *(a + i));
	}
}
