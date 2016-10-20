#include "holberton.h"

/**
 * _isupper - lay man version of isupper()
 * @c: character to check for upper caseness
 * checks wether input is upper case or not
 * Return: 1 if c is uppercase 0 otherwise
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
