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

/**
 * is_help - check if first and last character of string match, iterates
 * @s: string
 * @l: last index in s
 * @i: position in string of charcters to match
 * Return: 0 if characters match, 1 otherwise
 */
int is_help(char *s, int l, int i)
{
	if (i >= ((l + 1)/ 2))
		return (1);
	if (*(s + i) != *(s + l - i))
		return (0);
	return (is_help(s, l, i + 1));
}

/**
 * is_palindrome - is s a palindrome
 * @s: string
 * Return: 1 if s is a palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int l;

	l = _strlen_recursion(s);
	return is_help(s, l - 1, 0);
}
