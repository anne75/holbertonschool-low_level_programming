#include "sort.h"



/**
 * sink - sink an element in a heap
 * @array: array of int
 * @size: size of heap
 * @index: index of element to sink
 * @n: size of array for printing
 */
void sink(int *array, size_t size, size_t index, size_t n)
{
	size_t j, tmp;

	j = (index + 1) * 2 - 1; /*trick as index starts at 0 and not at one*/
	while (j < size)
	{
		/* go to index children at 2 * index and 2 * index + 1*/
		if (array[j] < array[j + 1] && (j + 1) < size)
			++j;
		if (array[index] < array[j])
		{
			tmp = array[index];
			array[index] = array[j];
			array[j] = tmp;
			print_array(array, n);
		}
		index = j;
		j = (index + 1) * 2 - 1;
	}
}




/**
 * heap_sort - sort an array with heap sort
 * @array: array of int
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;
	int tmp;

	if (!array || size < 2)
		return;
	/*make a heap, skip leaf nodes*/
	i = size / 2 - 1; /*index start at 0*/
	while (i > 0)
	{
		sink(array, size, i, size);
		--i;
	}
	sink(array, size, 0, size); /*to go around using unsigned int*/

	i = size - 1;
	while (i > 0)
	{
		/*swap heap root, max and last node*/
		tmp = array[i];
		array[i] = array[0];
		array[0] = tmp;
		print_array(array, size);
		sink(array, i, 0, size);
		--i;
	}
}
