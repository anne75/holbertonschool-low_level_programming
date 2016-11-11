#include <stdlib.h>

/**
 * array_range - creates an array of integers
 * @min: min value for initialization
 * @max: max values for initialization
 *create an array, assgin all values in order from min to max
 * Return: pointer to array if success, or NULL
 */
int *array_range(int min, int max)
{
	int i, size;
	int *a;

	if (min >  max)
		return (NULL);

	size = max - min + 1;
	a = malloc(sizeof( *a) * size);
	if (a == NULL)
		return (NULL);

	i = 0;
	while (i < size)
	{
		a[i] = min + i;
		++i;
	}
	return (a);
}
