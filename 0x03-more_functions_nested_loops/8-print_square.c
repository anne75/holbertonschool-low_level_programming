#include "holberton.h"

/**
 * print_square - print square of size size with #
 * @size: size of square
 * Return: void
 */
void print_square(int size)
{
	int i;

	if (size > 0)
	{
		i = 0;
		while (i < size)
		{
			printsq(size);
			i++;
		}
	}
	else
	{
		_putchar('\n');
	}
}

/**
 * printsq - print one line of # of size i
 * @i: length of line, should be > 0
 * Return: void
 */
void printsq(int i)
{
	while (i > 0)
	{
		_putchar('#');
		i--;
	}
	_putchar('\n');
}
