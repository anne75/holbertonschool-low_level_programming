#include "holberton.h"

/**
 * print_diagonal - print diagonal
 * @n: number of times to print \ on a new line
 *
 * Return: void
 */
void print_diagonal(int n)
{
	int i;

	if (n > 0)
	{
		i = 1;
		while (i <= n)
			printdiag(i++);
	}
	else
	{
		_putchar('\n');
	}
}

/**
 * printdiag - helper function prints 1 line
 * @i: position to print \, i should be > 0
 * Return: void
 */
void printdiag(int i)
{

	while (i > 1)
	{
		_putchar(' ');
		i--;
	}
	_putchar('\\');
	_putchar('\n');
}
