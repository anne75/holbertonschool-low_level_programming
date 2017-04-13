#include "search_algos.h"


/**
 * print_array - print part of an array
 * @array: array of int
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
 * advanced_binary - implement binary search algorithm
 * @array: an array of int, sorted in ascending order
 * @size: size of array
 * @value: value to search
 * Return: index of where value appears in array or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t lo, hi, middle, i;

	if (!array || size <= 0)
		return (-1);

	lo = 0;
	hi = size - 1;
	i = 0;
	while (lo <= hi && i++ < 5)
	{
		print_array(array, lo, hi);
		middle = lo + (hi - lo) / 2;
		if (array[middle] < value)
			lo = middle + 1;
		else
			hi = middle;
	}
	if (array[lo] == value)
		return (middle);
	return (-1);
}
