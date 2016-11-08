#include <stdlib.h>

/**
 * alloc_grid - return a pointer to a newly created 2 dim integer grid
 * @width: width of grid or columns
 * @height: height of grid or columns
 * Return: pointer to grid on success, or NULL
 */
int **alloc_grid(int width, int height)
{
	int **a, i, j;

	if (width <= 0 || height <= 0)
		return (NULL);

	a = malloc(height * sizeof(*a));
	if (a == NULL)
		return (NULL);

	i = 0;
	while (i < height)
	{
		a[i] = malloc(width * sizeof(int));
		if (a[i] == NULL)
			return (NULL);
		i++;
	}

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
			a[i][j++] = 0;
		i++;
	}

	return (a);
}
