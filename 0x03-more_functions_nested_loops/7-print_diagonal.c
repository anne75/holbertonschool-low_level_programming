#include "holberton.h"

/**
 * print_diagonal - print diagonal
 * @n: number of times to print \ on a new line
 *
 * Return: void
 */
void print_diagonal(int n)
{
	int i, a;

	if (n > 0)
	{
		i = 1;
		while (i <= n)
		{
			a = i;
			while (a > 1)
			{
				_putchar(' ');
				a--;
			}
			_putchar('\\');
			_putchar('\n');
			i++;
		}
	}
	else
	{
		_putchar('\n');
	}
}
