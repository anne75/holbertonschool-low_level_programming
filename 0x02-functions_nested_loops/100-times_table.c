#include "holberton.h"

/**
 * print_times_table - prints the times table from 0 to n
 * @n: gives the dimension of the times table, must be between 0 and 15
 *
 * Return: void
 */
void print_times_table(int n)
{
	int a;

	if (n >= 0 && n <= 15)
	{
		a = 0;
		while (a <= n)
		{
			make_line(a, n);
			a++;
		}
	}
}

/**
 * make_line - helper function to print each row
 * @a: line we are making
 * @n: length of line
 * Return: void
 */
void make_line(int a, int n)
{
	int b, p;

	b = 0;
	while (b <= n)
	{
		if (b > 0)
			_putchar(' ');
		p = a * b;
		if (p < 10)
		{
			if (b > 0)
			{
				_putchar(' ');
				_putchar(' ');
			}
			_putchar('0' + p);
		}
		else
		{
			if (p < 100 && b > 0)
			{
				_putchar(' ');
			}
			else
			{
				_putchar('0' + p / 100);
				p = p - (p / 100) * 100;
			}
			_putchar('0' + p / 10);
			_putchar('0' + p % 10);
		}
		if ((a <  n && b == n) || (a == n && b == n))
			_putchar('\n');
		else
			_putchar(',');
		b++;
	}
}
