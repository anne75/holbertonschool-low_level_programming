#include "sort.h"



/**
 * merge_up - merge 2 bitonic arrays in ascending order
 * @array: array of int
 * @size: size of array
 * @p_a: array for printing
 * @p_s: size for printing
 */
void merge_up(int *array, size_t size, int *p_a, size_t p_s)
{
	size_t i, j, k, n;
	int tmp;

	for (n = size / 2; n >= 1; n /= 2)
	{
		for (i = 0; i < size; i += 2 * n)
		{
			for(j = i, k = 0; k < n; ++j, ++k)
			{
				if (array[j] > array[j + n])
				{
					tmp = array[j];
					array[j] = array[j + n];
					array[j + n] = tmp;
					print_array(p_a, p_s);
				}
			}
		}
	}
}

/**
 * merge_down - merge 2 bitonic arrays in descending order
 * @array: array of int
 * @size: size of array
 * @p_a: array for printing
 * @p_s: size for printing
 */
void merge_down(int *array, size_t size, int *p_a, size_t p_s)
{
	size_t i, j, k, n;
	int tmp;

	for (n = size / 2; n >= 1; n /= 2)
	{
		for (i = 0; i < size; i += 2 * n)
		{
			for(j = i, k = 0; k < n; ++j, ++k)
			{
				if (array[j] < array[j + n])
				{
					tmp = array[j];
					array[j] = array[j + n];
					array[j + n] = tmp;
					print_array(p_a, p_s);
				}
			}
		}
	}
}



/**
 * bitonic_sort - sort an array using bitonic sort
 * @array: array of int
 * @size: size of array
 * Use a bottom up approach, assume the array is of size 2^k for k >= 0
 */
void bitonic_sort(int *array, size_t size)
{
	size_t i, n;

	if (!array || size < 2)
		return;

	for (n = 2; n <= size; n *= 2)
	{
		for (i = 0; i < size; i += 2 * n)
		{
			merge_up(array + i, n, array, size);
			if ((i + n) < size)
				merge_down(array + i + n, n, array, size);
		}
	}
}
