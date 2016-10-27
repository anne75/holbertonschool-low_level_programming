#include "holberton.h"


/**
 * leet - replace somme letters with numbers in a string
 * @s: a string
 * changes a to $, e to 3, o to 0, t to 7, l to 1
 * Return: pointer to s
 */
char *leet(char *s)
{

	int i, j, n;

	int code[] = {'4', '3', '0', '7', '1', '4', '3', '0', '7', '1'};
	char letters[] = {'a', 'e', 'o', 't', 'l', 'A', 'E', 'O', 'T', 'L'};

	n = 10;
	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (j < n)
		{
			if (letters[j] == s[i])
				s[i] = code[j];
			j++;
		}
		i++;
	}
	return (s);
}
