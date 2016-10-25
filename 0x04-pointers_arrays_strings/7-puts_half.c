#include "holberton.h"

/**
 * _strlen - lay man version of strlen()
 *@s: pointer to char, string
 * get the length of the string in input
 * Return: length of s
 */
int _strlen(char *s)
{
	int l;

	l = 0;
	while (*(s++) != '\0')
		l++;

	return (l);
}


/**
 * puts_half - prints second half of string
 * @str: pointer to char, string
 * Return: void
 */
void puts_half(char *str)
{
	int l, start;
	char s;

	l = _strlen(str);

	if (l % 2 == 0)
		start = l / 2;
	else
		start = (l + 1) / 2;

	while ((s = *(str + start)) != '\0')
	{
		_putchar(s);
		start++;
	}
	_putchar('\n');
}
