#include "sort.h"


/**
 * shell_sort - sort an array with shell sort
 * @array: array of int
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, step;
	int tmp;

	if (!array || size < 2)
		return;

	step = 1;
	while (step < size / 3)
		step = 3 * step + 1;

	while (step >= 1)
	{
		for (i = step; i < size; ++i)
		{
			for (j = i; j >= step &&
				     (array[j] < array[j - step]); j -= step)
			{
				tmp = array[j];
				array[j] = array[j - step];
				array[j - step] = tmp;
			}
		}
		print_array(array, size);
		step /= 3;
	}
}
