# include "holberton.h"


/**
 * print_alphabet - prints alphabet
 * print lowercase use only_p...
 *Return: void
 */
void print_alphabet(void)
{
	char c;

	c = 'a';
	while (c <= 'z')
	{
		_putchar(c++);
	}
	_putchar('\n');
}
