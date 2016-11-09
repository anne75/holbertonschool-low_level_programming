#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
/**
 * _strlen - I cannot use strlen()
 * @s: string
 * Return: return size of string
 */
unsigned long _strlen(char *s)
{
	unsigned long i;

	i = 0;
	while (*(s + i) != '\0')
		++i;
	return (i);
}


/**
 * str_concat - concatenate 2 strings
 * @s1: front string
 * @s2: back string
 * Return: pointer to newly created string - NULL if impossible
 */
char *str_concat(char *s1, char *s2)
{
	unsigned long l1, l2;
	unsigned int i;
	char *s;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	l1 = _strlen(s1);
	l2 = _strlen(s2);
	if (l1 + l2 >= SIZE_MAX)
		return (NULL);
	s = malloc((l1 + l2 + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);

	i = 0;
	while (i < l1)
		*(s + i++) = *s1++;

	while (i < (l1 + l2))
		*(s + i++) = *s2++;
	*(s + i) = '\0';
	return (s);
}
