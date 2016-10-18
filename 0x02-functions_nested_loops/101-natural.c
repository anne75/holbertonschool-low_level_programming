#include <stdio.h>
#include "holberton.h"

/**
 * main - entry point
 * computes and prints the sum of all the multiples of 3 or 5 < 1024
 * Return: 0
 */
int main(void)
{
	int total, i;

	i = 0;
	total = 0;
	while (i < 10)
	{
		if ((i % 3) == 0 || (i % 5) == 0)
			total += i;
		i++;
	}
	printf("%d\n", total);
	return (0);
}
