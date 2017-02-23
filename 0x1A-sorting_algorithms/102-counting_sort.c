#include "sort.h"


/**
 * _max - returns the maximum value in an array
 * @array: array
 * @size: size of array
 * Return: maximum value
 */
int _max(int *array, size_t size)
{
	int max_v;
	size_t i;

	if (!array || size == 0)
		return (0);

	max_v = array[0];
	for (i = 1; i < size; ++i)
	{
		if (array[i] > max_v)
			max_v = array[i];
	}
	return (max_v);
}

/**
 * counting_sort - sort an array using key index sorting algorithm
 * @array: array of positive int
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	int *counts, *aux, size_counts, i;
	size_t j;

	size_counts = _max(array, size) + 1;
	counts = malloc(sizeof(int) * size_counts);
	if (!counts)
		return;
	aux = malloc(sizeof(int) * size);
	if (!aux)
	{
		free(counts);
		return;
	}

	for (i = 0; i < size_counts; ++i)
		counts[i] = 0;

	for (j = 0; j < size; ++j)
		counts[array[j]] += 1; /*Sedgewick adds 1 to counts index*/

	for (i = 1; i < size_counts; ++i)
		counts[i] += counts[i - 1];
	/* i <-> array[i] and counts[i] - 1 is the last index to place i in*/
	/* sorted array, with Sedgewicks method, it would be neat */
	print_array(counts, size_counts);

	for (j = 0; j < size; ++j)
	{
		aux[counts[array[j]] - 1] = array[j];
		counts[array[j]] -= 1;
	}
	/*decrement counts[i] to go to next index (+ 1) */
	/*where a duplicate key can go*/
	free(counts);
	for (j = 0; j < size; ++j)
		array[j] = aux[j];
	free(aux);
}
