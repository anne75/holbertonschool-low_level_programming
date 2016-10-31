#include "holberton.h"

/**
 * print_line - prints an array of size 8
 * @line: array of char of size 8
 * Return: void
 */
void print_line(char line[8])
{
	int i;

	i = 0;
	while (i < 8)
		_putchar(line[i++]);
	_putchar('\n');
}

/**
 * print_chessboard - prints an 8*8 matrix
 * @a: pointer to an array of size 8
 * Return: void
 */
void print_chessboard(char (*a)[8])
{

	int i;

	i = 0;
	while (i < 8)
		print_line(a[i++]);
}
