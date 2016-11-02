#include "holberton.h"


/**
 * _pow_recursion - returns x raised to power of y
 * @x: base number
 * @y: power
 * Return: x**y if y > 0, -1 otherwise
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	return (x * _pow_recursion(x, y - 1));
}
