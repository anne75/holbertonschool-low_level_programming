#include "holberton.h"

/**
 * times_table - prints the times table from 0 to 9
 *
 * Return: void
 */
void times_table(void)
{
	int a, b, n;

	a = 0;
	while (a <= 9)
	{
		b = 0;
		while (b <= 9)
		{
			if (b > 0)
				_putchar(' ');
			n = a * b;
			if (n < 10)
			{
				if (b > 0)
					_putchar(' ');
				_putchar('0' + n);
			}
			else
			{
				_putchar('0' + n / 10);
				_putchar('0' + n % 10);
			}
			if ((a <  9 && b == 9) || (a == 9 && b == 9))
				_putchar('\n');
			else
				_putchar(',');
			b++;
		}
		a++;
	}
}
