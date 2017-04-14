#include "search_algos.h"

/**
 * interpolation_search - implement interpolation search algorithm
 * @array: ordered array of int
 * @size: size of array
 * @value: value to search
 * Return: index where value is or -1
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t lo, hi, probe;

	if (!array || size <= 0)
		return (-1);

	lo = 0;
	hi = size - 1;
	while (lo <= hi)
	{
		probe = lo + (((double)(hi - lo) / (array[hi] - array[lo])) *
			      (value - array[lo]));
		if (probe > size - 1)
		{
			printf("Value checked array[%lu] is out of range\n",
			       probe);
			return (-1);
		}
		printf("Value checked array[%lu] = [%d]\n",
		       probe, array[probe]);
		if (array[probe] < value)
			lo = probe + 1;
		else if (array[probe] > value)
			hi = probe;
		else
			return (probe);
	}
	return (-1);
}
