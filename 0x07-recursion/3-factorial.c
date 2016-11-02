#include "holberton.h"

/**
 * factorial - return factorial of number using recursion
 * @n: number
 * Return: n! if n >= 0 , -1 otherwise
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0)
		return (1);
	return (n * factorial(n - 1));
}
