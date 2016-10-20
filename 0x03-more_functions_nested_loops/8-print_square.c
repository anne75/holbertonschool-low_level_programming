#include "holberton.h"

/**
 * print_square - print square of size size with #
 * @size: size of square
 * Return: void
 */
void print_square(int size)
{
	int i, a;

	if (size > 0)
	{
		i = 0;
		while (i < size)
		{
			a = size;
			while (a > 0)
			{
				_putchar('#');
				a--;
			}
			_putchar('\n');
			i++;
		}
	}
	else
	{
		_putchar('\n');
	}
}
