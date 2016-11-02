#include "holberton.h"
#include <stdio.h>

/**
 * _sqrt_help - find if m is sqrt(n), use binary search to find m otherwise
 * @a: lower bound for binary search
 * @b: upper bound for binary search
 * @n: number to get sqrt from, checks on n done elsewhere.
 * Return: sqrt(n) if it exists, -1 otherwise
 */
int _sqrt_help(int a, int b, int n)
{
	int middle;

	if ((b - a) < 0)
		return (-1);

	middle = a + (b -a) / 2;
	if (middle * middle == n)
		return (middle);
	if (middle * middle < n)
		return (_sqrt_help(middle + 1, b, n));
	return (_sqrt_help(a, middle - 1, n));
}

/**
 * _sqrt_recursion - find the square root of a number using recursion
 * @n: number to get square root from
 * Return: sqrt(n) if it is an int, -1 otherwise
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (_sqrt_help(0, n, n));

}
