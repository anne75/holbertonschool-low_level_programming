#include "holberton.h"

/**
 * jack_bauer - prints every minutes in a whole day
 *
 * Return: void
 */
void jack_bauer(void)
{
	int a, b;

	a = 0;
	while (a < 24)
	{
		b = 0;
		while (b < 60)
		{
			_putchar('0' + a / 10);
			_putchar('0' + a % 10);
			_putchar(':');
			_putchar('0' + b / 10);
			_putchar('0' + b % 10);
			_putchar('\n');
			b++;
		}
		a++;
	}
}
