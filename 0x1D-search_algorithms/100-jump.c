#include "search_algos.h"
#include <math.h>

/**
 * jump_search - implements the jump search algorithm
 * @array: ordered array of int
 * @size: size of array
 * @value: value to search
 * Return: index at which value is found or -1
 */
int jump_search(int *array, size_t size, int value)
{
	size_t step, lo, hi, i;

	if (!array || size <= 0)
		return (-1);

	step = sqrt(size);
	lo = 0;
	hi = 0;
	while (hi < size && array[hi] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", hi, array[hi]);
		lo = hi;
		hi += step;
	}
	printf("Value found between indexes [%lu] and [%lu]\n", lo, hi);
	hi = MIN(hi, size - 1);
	/*linear search between lo and hi*/
	for (i = lo; i <= hi; ++i)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}
	return (-1);
}


/**
 * jump_search2 - implements the jump search algorithm
 * @array: ordered array of int
 * @size: size of array
 * @value: value to search
 * Previous version where a check in while avoid linear search of not necessary
 * Return: index at which value is found or -1
 */
int jump_search2(int *array, size_t size, int value)
{
	size_t step, lo, hi, i;

	if (!array || size <= 0)
		return (-1);

	step = sqrt(size);
	lo = 0;
	hi = 0;
	i = 0;
	while (array[i] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		lo = hi;
		hi += step;
		i = MIN(hi, size - 1);
		if (lo >= size)
			return (-1);
	}
	printf("Value found between indexes [%lu] and [%lu]\n", lo, i);
	/*linear search between lo and hi*/
	hi = i;
	for (i = lo; i <= hi; ++i)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}
	return (-1);
}
