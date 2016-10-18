#include "holberton.h"
#include <stdio.h>

/**
 * print_to_98 - print all integers from input n to 98
 * @n: starting point for printing integers to 98
 *
 * Return: void
 */
void print_to_98(int n)
{
	if (n > 98)
		while (n > 98)
			printf("%d, ", n--);
	else if (n < 98)
		while (n < 98)
			printf("%d, ", n++);
	printf("98\n");
}
