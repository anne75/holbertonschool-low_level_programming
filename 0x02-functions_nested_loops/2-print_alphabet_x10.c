#include "holberton.h"

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

/**
 * print_alphabet_x10 - prints alphabet 10 times
 * lowercase, use previous function
 * Return: void
 */
void print_alphabet_x10(void)
{
	int i;

	i = 0;
	while (i < 10)
	{
		print_alphabet();
		i++;
	}
}
