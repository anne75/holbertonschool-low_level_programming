#include "holberton.h"

/**
 * printc - print int c a times
 * @a: number of times to print c must be > 0
 * @c: character to print
 * Return: void
 */
void printc(int a, int c)
{
	while (a > 0)
	{
		_putchar(c);
		a--;
	}
}

/**
 * print_triangle - print a triangle, ascii art
 * @size: size of triangle
 * Return: void
 */
void print_triangle(int size)
{
	int i;

	i = 1;
	while (i <= size)
	{
		printc(size - i, ' ');
		printc(i, '#');
		_putchar('\n');
		i++;
	}
}
