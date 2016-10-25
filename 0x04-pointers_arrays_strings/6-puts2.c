#include "holberton.h"

/**
 * puts2 - prints only every other char in a string
 * @str: pointer to a char, a string
 * Return: void
 */
void puts2(char *str)
{
	int i;
	char s;

	i = 0;

	while ((s = *(str + i)) != '\0')
	{
		_putchar(s);
		i += 2;
	}
	_putchar('\n');
}
