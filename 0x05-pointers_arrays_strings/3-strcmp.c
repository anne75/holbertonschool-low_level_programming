#include "holberton.h"

/**
 * _strcmp - compare 2 strings see strcmp()
 * @s1: string to compare
 * @s2: string used as reference
 * Return: It returns the difference in value of the first characters where
 * s1 and s2 disagree
*/
int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (*(s1 + i) == *(s2 + i) && *(s1 + i) != '\0' && *(s2 + i) != '\0')
		i++;
	return (*(s1 + i) - *(s2 + i));
}
