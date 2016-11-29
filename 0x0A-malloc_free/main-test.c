#include <stdio.h>
#include "holberton.h"


/**
 * main - check the 3 codes for the grid creation.
 *
 * Return: Always 0.
 */
int main(void)
{
	int row;
	int **g;

	row = 0;
	while (row < 50000)
	{
		printf("grid[%i][%i]\n", row, row);
		g = alloc_grid(row, row );
		if (g != NULL)
			g[0][0] = 1;
		row++;
	}
	puts("\n");
	return (0);
}
