#include "holberton.h"

/**
 * _isupper - simple version of isupper()
 * @c: parameter to check
 * checks wether input is upper case or not
 * Return: 1 if c is uppercase, 0 otherwise
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
