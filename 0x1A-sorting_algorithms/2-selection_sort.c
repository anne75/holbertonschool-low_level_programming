#include "sort.h"

/**
 * selection_sort - sort an array with selection sort
 * @array: array of int
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int swap_in;

	if (!array || size < 2)
		return;

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
