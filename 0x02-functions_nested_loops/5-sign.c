#include "holberton.h"

/**
 * print_sign - print sign of number and return 1 0 or -1
 * @n: integer we want to know the sign of
 * check if input is positive or 0 or negative
 * Return: -1 if c < 0, 0 if c == 0,  1 if c > 0
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	if (n == 0)
	{
		_putchar('0');
		return (0);
	}
	_putchar('-');
	return (-1);
}
