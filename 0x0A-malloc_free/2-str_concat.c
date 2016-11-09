#include <stdlib.h>
#include <stdio.h>
/**
 * _strlen - I cannot use strlen()
 * @s: string
 * Return: return size of string
 */
int _strlen(char *s)
{
	int i;

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
	int l1, l2, i;
	char *s;

	l1 = l2 = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 != NULL)
		l1 = _strlen(s1);
	if (s2 != NULL)
		l2 = _strlen(s2);
	printf("length %s %i, %s %i\n", s1, l1, s2, l2);
	s = malloc((l1 + l2 + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);

	i = 0;
	if (s1 != NULL)
		while (i < l1)
			*(s + i++) = *s1++;

	if (s2 != NULL)
		while (i < (l1 + l2))
			*(s + i++) = *s2++;
	*(s + i) = '\0';
	return (s);
}
