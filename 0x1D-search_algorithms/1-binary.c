#include "search_algos.h"


/**
 * print_array - print part of an array
 * @array: array
 * @lo: minimum index to print
 * @hi: maximum index to print
 */
void print_array(int *array, size_t lo, size_t hi)
{
	size_t i;

	printf("Searching in array:");
	for (i = lo; i < hi; ++i)
	{
		printf(" %d,", array[i]);
	}
	printf(" %d\n", array[i]);
}


/**
 * binary_search - implement binary search algorithm
 * @array: an array of int, sorted in ascending order
 * @size: size of array
 * @value: value to search
 * Return: index of where value appears in array or -1
 */
int binary_search(int *array, size_t size, int value)
{
	size_t lo, hi, middle;

	if (!array || size <= 0)
		return (-1);

	lo = 0;
	hi = size - 1;
	while (lo <= hi)
	{
		print_array(array, lo, hi);
		middle = lo + (hi - lo) / 2;
		if (array[middle] < value)
			lo = middle + 1;
		else if (array[middle] > value)
			hi = middle;
		else
			return (middle);
	}
	return (-1);
}
