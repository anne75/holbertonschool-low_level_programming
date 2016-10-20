#include "holberton.h"

/**
 * print_most_numbers - print 0 1 3 5 6 7 8 9
 *
 * Return: void
 */
void print_most_numbers(void)
{
	int c;

	c = '0';
	while (c <= '9')
	{
		if (c != '2' && c != '4')
			_putchar(c);
		c++;
	}
	_putchar('\n');
}
