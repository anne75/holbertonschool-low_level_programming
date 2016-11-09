#include <stdlib.h>

/**
 * _strlen - I cannot use strlen()
 * @s: string
 * Return: return size of string 0 included
 */
int _strlen(char *s)
{
	int i;

	i = 0;

	while (*(s + i++) != '\0')
		;
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

	if (s1 == NULL || s2 == NULL)
		return (NULL);

	l1 = _strlen(s1);
	l2 = _strlen(s2);
	--l1;

	s = malloc((l1 + l2) * sizeof(char));
	if (s == NULL)
		return (NULL);

	i = 0;
	while (i < l1)
		*(s + i++) = *s1++;

	while (i < (l1 + l2))
		*(s + i++) = *s2++;

	return (s);
}
