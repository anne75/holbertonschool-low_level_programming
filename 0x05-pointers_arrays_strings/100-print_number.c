#include "holberton.h"
#include <stdio.h>

/**
 * print_number - prints an integer using only putchar
 * @n: number to print
 * Return: void
 */
void print_number(int n)
{
	if (n < 0)
		_putchar('-');
	else
		n = -n;

	if ((n / 10) < 0)
	{
		print_number(-(n / 10));
	}
	_putchar('0' - n % 10);
}
