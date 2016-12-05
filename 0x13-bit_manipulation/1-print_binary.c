#include "holberton.h"


/**
 * print_binary - print binary representation of number
 * @n: number, unsigned
 * Do not use array, malloc, % and /
 * Problem : if n == 0, print 0 otherwise do not print
 * front 0, so use helper
 * Return: void
 */
void print_binary(unsigned long int n)
{
	char c;
/*base case n == 0*/
	if (n == 0)
	{
		_putchar('0');
		return;
	}
/*base case n at beginning > 0 I have reached most significant bit*/
	if ((n ^ 1) == 0)
	{
		_putchar('1');
		return;
	}
/*recursion*/
	print_binary(n >> 1);
	c = ((n & 1) == 0) ? '0' : '1';
	_putchar(c);

}
