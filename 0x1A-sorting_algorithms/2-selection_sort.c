#include "sort.h"

/**
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int swap_in;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			swap_in = array[min];
			array[min] = array[i];
			array[i] = swap_in;
			print_array(array, size);
		}
	}
}
