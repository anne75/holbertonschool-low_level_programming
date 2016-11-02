#include "holberton.h"


/**
 * _strlen_recursion - gets length of string using recursion
 * @s: string
 * Return: int lentgh of string
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}
	return (1 + _strlen_recursion(s + 1));
}
