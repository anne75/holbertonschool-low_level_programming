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
 * binary_s - implement binary search algorithm
 * @array: an array of int, sorted in ascending order
 * @lo: min index to consider
 * @hi: max index to consider
 * @value: value to search
 * Return: index of where value appears in array or -1
 */
int binary_s(int *array, size_t lo, size_t hi, int value)
{
	size_t middle;

	if (!array || lo > hi)
		return (-1);

	while (lo <= hi)
	{
		print_array(array, lo, hi);
		middle = (lo + hi) / 2;
		if (array[middle] < value)
			lo = middle + 1;
		else if (array[middle] > value)
			hi = middle;
		else
			return (middle);
	}
	return (-1);
}

/**
 * exponential_search - implement exponential search
 * @array: ordered array of int
 * @size: size of array
 * @value: value to search
 * Return: index at which value is found or -1
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t test, lo, hi;

	if (!array || size <= 0)
		return (-1);

	test = 1;
	while (test < size && array[test] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", test, array[test]);
		test *= 2;
	}
	lo = test / 2;
	hi = MIN(test, size - 1);
	printf("Value found between indexes [%lu] and [%lu]\n", lo, hi);
	return (binary_s(array, lo, hi, value));
}
