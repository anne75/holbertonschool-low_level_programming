#include <stdio.h>
#include "holberton.h"

/*prototypes are in holberton.h*/

/**
 * main - entry point
 *
 * Return: 0
 */
int main(void)
{
	int i;

	i = 0;
	while (i < 49)
	{
		printf("%lu, ", fibo(i));
		i++;
	}
	printf("%lu\n", fibo(i));
	return (0);
}

/**
 * fibo - return ith fibonacci number
 * @i: int, return ith number in series
 *
 * Return: int, value of Fibonacci series
 */
long int fibo(int i)
{
	long int d;

	if (i == 0)
	{
		return (1);
	}
	if (i == 1)
	{
		return (2);
	}
	d = fibo(i - 1) + fibo(i - 2);
	return (d);
}
