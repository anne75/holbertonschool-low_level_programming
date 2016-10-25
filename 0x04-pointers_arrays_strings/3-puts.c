#include "holberton.h"

/**
 * _puts - lay man version of puts()
 * @str: string to print on stdout
 * Return: void
 */
void _puts(char *str)
{
	char s;

	while ((s = *(str++)) != '\0')
		_putchar(s);
	_putchar('\n');
}
