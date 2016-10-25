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
 * rev_string - return the string in reverse order
 * @s: pointer to char, string to reverse
 * Return: void
 */
void rev_string(char *s)
{
	int l, i;
	char tmp;

	l = _strlen(s);
	i = 0;
	while (i < (l / 2))
	{
		tmp = *(s + i);
		*(s + i) = *(s + l - 1 - i);
		*(s + l - 1 - i) = tmp;
		i++;
	}
}
