#include <stdlib.h>


/**
 * free_grid - frees a 2D grid created in 3-...
 * @grid: 2D matrix
 * @height: number of rows
 * Return: void
 */
void free_grid(int **grid, int height)
{
	int i;

	i = 0;
	while (i < height)
		free(grid[i++]);
	free(grid);
}
