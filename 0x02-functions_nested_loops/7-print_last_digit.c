#include "holberton.h"

/**
 * print_last_digit - prints and return last digit of number
 * @n: integer of which we return the last digit
 *
 * Return: last digit of number
 */
int print_last_digit(int n)
{
	int l;

	l = n % 10;
	if (n < 0)
		l = -l;

	_putchar('0' + l);
	return (l);
}
