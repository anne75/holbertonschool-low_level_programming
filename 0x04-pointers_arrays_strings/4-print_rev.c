#include "holberton.h"

/**
 * _strlen - lay man version of strlen()
 *@s: pointer to char, string
 * get the length of the string in input
 * Return: length of s
 */
int _strlen(char *s)
{
	int l;

	l = 0;
	while (*(s++) != '\0')
		l++;

	return (l);
}


/**
 * print_rev - print a string in reverse order
 *@s: pointer to a char, a string
 * Return: void
 */
void print_rev(char *s)
{
	int l;

	l = _strlen(s) - 1;
	while (l >= 0)
		_putchar(*(s + l--));
	_putchar('\n');
}
