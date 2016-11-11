#include <stdlib.h>
#include <stdio.h>

/**
 * _strlen - size of string
 * @s: string to evaluate
 * Return: nb of elements in s
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}


/**
 * string_nconcat - concatenate 2 strings
 * @s1: first string
 * @s2: string to add to first
 * @n: number of bytes in s2 to add to s1
 * Return: pointer to new char
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *s;
	unsigned int l1, l2, i, min;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	l1 = _strlen(s1);
	l2 = _strlen(s2);

	min = (l2 > n) ? n : l2;
	s = malloc(sizeof(*s) * (l1 + min + 1));
	if (s == NULL)
		return (NULL);

	i = 0;
	while (i < l1)
	{
		*(s + i) = *(s1 + i);
		i++;
	}
	while (i < (l1 + min))
		*(s + i++) = *s2++;

	*(s + i) = '\0';
	return (s);
}
