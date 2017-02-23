#include "sort.h"

/**
 * print_indexes - print part of array
 * @array: array of int
 * @lo: lowset index to print
 * @hi: upper index to print, excluded
 */
void print_indexes(int *array, size_t lo, size_t hi)
{
	size_t i;

	i = lo;
	while (array && i < (hi - 1))
		printf("%d, ", array[i++]);
	printf("%d\n", array[i]);
}


/**
 * _merge - merge 2 arrays
 * @array: array of int
 * @aux: auxiliary array
 * @lo: lower index value to consider
 * @mid: middle index value
 * @hi: upper index value to consider
 */
void _merge(int *array, int *aux, size_t lo, size_t mid, size_t hi)
{
	size_t i, j, k;

	puts("Merging...");
	printf("[left]: ");
	print_indexes(array, lo, mid);
	printf("[right]: ");
	print_indexes(array, mid, hi);
	for (i = lo; i < hi; ++i)
		aux[i] = array[i];
	i = lo;
	j = mid;
	for (k = lo; k < hi; ++k)
	{
/*		printf("i %lu, j %lu aux[j] %i, k %lu\n", i, j, aux[j], k);*/
		if (i >= mid)
			array[k] = aux[j++];
		else if (j >= hi)
			array[k] = aux[i++];
		else if (aux[i] <= aux[j])
			array[k] = aux[i++];
		else
			array[k] = aux[j++];
	}
	printf("[Done]: ");
	print_indexes(array, lo, hi);
}




/**
 * _sort - recursion for merge sort
 * @array: array of int
 * @aux: auxiliary array of int
 * @lo: lower value
 * @hi: upper value
 */
void _sort(int *array, int *aux, size_t lo, size_t hi)
{
	size_t mid;

/*	printf("sort lo %lu hi %lu\n", lo, hi);*/
	if (!array || !aux || hi <= (lo + 1))
		return;

	mid = lo + (hi - lo) / 2;
/*	printf("sort lo %lu mid %lu hi %lu\n", lo, mid, hi);*/
	_sort(array, aux, lo, mid);
	_sort(array, aux, mid, hi);
	_merge(array, aux, lo, mid, hi);
}



/**
 * merge_sort - sort an array using top-down merge sort
 * @array: an array of int
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *aux;

	if (!array || size < 2)
		return;

	aux = malloc(sizeof(int) * size);
	if (!aux)
		return;

	_sort(array, aux, 0, size);
	free(aux);
}
