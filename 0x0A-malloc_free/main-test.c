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
		printf("row:%i  ", row);
		g = alloc_grid(row, row );
		if (g == NULL)
			puts(" NULL\n");
		/*else
			printf(" %i\n", g[0][0]);*/
		row++;
	}
	puts("\n");
	return (0);
}
