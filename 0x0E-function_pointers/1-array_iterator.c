#include <stdlib.h>

/**
 * array_iterator - execute a function on parameters passed in array
 * @array: array of parameters
 * @size: size of array
 * @action: function to perform
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (action == NULL)
		exit(98);

	i = 0;
	while (i < size)
	{
		action(array[i]);
		i++;
	}
}


