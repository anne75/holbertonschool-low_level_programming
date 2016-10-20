#include "holberton.h"

/**
 * _isdigit - simple version of isdigit()
 * @c: parameter to check
 * checks if c is a digit
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
