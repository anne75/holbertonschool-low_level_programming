#include "holberton.h"


/**
 * print_binary - print binary representation of number
 * @n: number, unsigned
 * Do not use array, malloc, % and /
 *
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

/* due to constraints, use recursion
 * there are 2 base cases: if we want print_binary(0), we have
 * to return 0, however in any other case we do not want to start
 * with a 0 so we stop at the leftmost digit that is = 1, ie
 * the most significant digit, we know it exists since the number
 * is > 0
 */
