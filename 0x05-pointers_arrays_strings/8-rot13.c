#include "holberton.h"


/**
 * rot13 - replace some letters with numbers in a string
 * @s: a string
 * changes a to $, e to 3, o to 0, t to 7, l to 1
 * Return: pointer to s
 */
char *rot13(char *s)
{

	int i, j, n;

	char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	n = 52;
	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (j < n)
		{
			if (letters[j] == s[i])
			{
				s[i] = letters[(j + 13) % 26 + (j / 26) * 26];
				j = n;
			}
			j++;
		}
		i++;
	}
	return (s);
}
