#include "../sort.h"

/**
 * partition - matching teacher's output Hoare
 *
 * @array: array of int
 * @lo: lowest index to compare
 * @hi: highest index to compare
 * @size: size of array (for printing)
 * The pivot is assigned to be the last element in the partition
 * Return: point of convergence between lo and hi
 */
size_t partition(int *array, size_t lo, size_t hi, size_t size)
{
	size_t i, j;
	int tmp, pivot;

	pivot = array[hi];
	i = lo - 1;
	j = hi + 1;
	while (1)
	{
		do {
			--j;
		} while (array[j] > pivot);
		do {
			++i;
		} while (array[i] < pivot);
		if (i < j)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
		else
		{
			return (i);
		}
	}
}


/**
 * partition_2 - partition ?
 * @array: array of int
 * @lo: lowest index to compare
 * @hi: highest index to compare
 * @size: size of array (for printing)
 * The pivot is assigned to be the last element in the partition
 * Return: point of convergence between lo and hi
 */
size_t partition_2(int *array, size_t lo, size_t hi, size_t size)
{
	size_t i, j;
	int tmp;

	i = lo - 1;
	j = hi;

	while (1)
	{
/* all values to the left of pivot must be < pivot */
		while (array[++i] < array[hi])
		{
			if (i >= hi)
				break;
		}
/* all values to the right must be > pivot */
		while (array[--j] > array[hi])
		{
			if (j <= lo)
				break;
		}
		if (i >= j)
			break;
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, size);
	}
	if (i != hi) /*put pivot in its right place*/
	{
		tmp = array[hi];
		array[hi] = array[i];
		array[i] = tmp;
		print_array(array, size);
	}
	return (i); /*return index of pivot*/
}

/**
 * qs_recursion - quick sort core
 * @array: array of in
 * @lo: lower index
 * @hi: higher index
 * @size: size of array
 */
void qs_recursion(int *array, size_t lo, size_t hi, size_t size)
{
	size_t p;

	if (hi <= lo)
		return;
	p = partition(array, lo, hi, size);
	if (p > 0) /* not necessary, not ready to take it away */
		qs_recursion(array, lo, p - 1, size);
	qs_recursion(array, p, hi, size);
}
/* use p + 1 instead of p on last line for partition 2*/


/**
 * quick_sort - sort an array with quick sort
 * @array: array of int
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{

	if (size < 2)
		return;
	qs_recursion(array, 0, size - 1, size);
}
