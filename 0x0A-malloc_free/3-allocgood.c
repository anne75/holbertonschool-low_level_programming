#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

/**
 * _memset - simple version of memset()
 * @s: buffer to modify
 * @b: value to modify buffer with
 * @n: number of int to modify with char b
 *
 * Return: pointer to buffer, s
 */
int *_memset(int *s, int b, int n)
{
	int i;

	if (s == NULL)
		return (NULL);

	i = 0;
	while (i < n)
		*(s + i++) = b;


	return (s);
}

/**
 * alloc_grid - return a pointer to a newly created 2 dim integer grid
 * @width: width of grid or columns
 * @height: height of grid or columns
 * Return: pointer to grid on success, or NULL
 */
int **alloc_grid(int width, int height)
{
	int **a, i;

	if (width <= 0 || height <= 0)
		return (NULL);
	a = malloc(height * sizeof(*a));
	if (a == NULL)
		return (NULL);

	i = 0;
	while (i < height)
	{
		a[i] = malloc(width * sizeof(**a));
		if (a[i] == NULL)
		{
			while (i >= 0)
				free(a[i--]);
			free(a);
			return (NULL);
		}
		a[i] = _memset(a[i], 0, width);
		i++;
	}
	return (a);
}

/*This is not passing the free check unfortunately*/
/* *a = malloc(sizeof(int) * width * height);
 *   if (*a == NULL)
 *  {
 *  free(a);
 *  return (NULL);
 *  }
 *  i = 0;
 *  while (i <= height)
 *  {
 *  a[i] = (*a + width * i);
 *  i++;
 *  }
*/
