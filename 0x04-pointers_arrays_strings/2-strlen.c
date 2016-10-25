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
