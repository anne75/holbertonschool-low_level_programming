#include <stdio.h>
#include "holberton.h"


/**
 * main - entry point, sums numbers in fibonacci sequence
 *
 * Return: 0
 */
int main(void)
{
	int i, tmp, count;

	i = 0;
	count = 0;
	while ((tmp = fibo(i)) < 4000000)
	{
		if ((tmp % 2) == 0)
			count += tmp;
		i++;
	}
	printf("%d\n", count);
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
	if (i == 0)
	{
		return (1);
	}
	if (i == 1)
	{
		return (2);
	}
	return (fibo(i - 1) + fibo(i - 2));
}
