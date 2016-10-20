#include "holberton.h"

/**
 * more_numbers - print 10 times 0-14
 *
 * Return: void
 */
void more_numbers(void)
{
	int a, i;

	a = 0;
	while (a < 10)
	{
		i = 0;
		while (i <= 14)
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
		a++;
	}
}
