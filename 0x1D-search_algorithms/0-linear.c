#include "search_algos.h"

/**
 * linear_search - implement linear search
 * @array: an array, unsorted
 * @size: size of array
 * @value: value to search
 * Return: first index with value or -1
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (!array || size <= 0)
		return (-1);

	i = 0;
	while (i < size)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
		++i;
	}
	return (-1);
}
