#include "holberton.h"

/**
 * more_numbers - print 10 times 0-14
 *
 * Return: void
 */
void more_numbers(void)
{
	int i;

	i = 0;
	while (i < 10)
	{
		print_line(14);
		i++;
	}
}

/**
 * printline - print 0 to c
 * @c: end of print
 * Return: void
 */
void printline(int c)
{
	int i;

	i = 0;

	while (i <= c)
	{
		if (i < 10)
		{
			_putchar('0' + i);
		}
		else
		{
			_putchar('0' + i / 10);
			_putchar('0' + i % 10);
		}
		i++;
	}
	_putchar('\n');
}
