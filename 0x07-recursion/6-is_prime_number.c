#include "holberton.h"

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
		return (a);

	middle = (b + a + 1) / 2;
	if (middle * middle == n)
		return (middle);
	if (middle * middle < n)
		return (_sqrt_help(middle + 1, b, n));
	return (_sqrt_help(a, middle - 1, n));
}

/**
 * no_divisor - checks if m is a divisor of n, iterates if not
 * @n: number to check if it is divisible, n >= 2
 * @limit: number that may be a divisor of n
 * Return: 1 if m is prime, 0 otherwise
 */
int no_divisor(int n, int limit)
{
	if (limit < 2)
		return (1);
	if ((n % limit) == 0)
		return (0);
	return (no_divisor(n, limit - 1));
}

/**
 * is_prime_number - checks if number is prime using recursion
 * @n: number
 * Return: 1 if n is prime 0 otherwise
 */
int is_prime_number(int n)
{
	int limit;

	if (n < 2)
		return (0);
	limit = _sqrt_help(0, n, n);
	return (no_divisor(n, limit));
}
