#include "holberton.h"
#include <stdio.h>

/**
 * _strlen - gives size of string
 * @a: pointer to string
 * Return: length of string  as int
 */
int _strlen(char *a)
{
	int i;

	i = 0;
	while (*(a + i) != '\0')
		i++;
	return (i);
}

/**
 * infinite_add - add two numbers given as strings
 * @n1: this sring is a number
 * @n2: this string is a number
 * @r: buffer to put result
 * @size_r: size of buffer
 * Return:pointer to buffer with result
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int l1, l2, retenue, sum;

	l1 = _strlen(n1);
	l2 = _strlen(n2);
	*(r + size_r - 1) = '\0';
	size_r--;
	if (l1 > size_r || l2 > size_r || size_r == 0)
		return (0);
	if (l1 == size_r && l2 == size_r && (*n1 - '0' + *n2 - '0') > 9)
		return (0);
	retenue = 0;
	while (size_r > 0)
	{
		if (l1 < 0 && l2 < 0)
		{
			*(r + size_r - 1) = retenue + '0';
			return (r + size_r - 1);
		}
		else if (l1 < 0)
		{
			sum =  *(n2 + l2 - 1) - '0' + retenue;
		}
		else if (l2 <= 0)
		{
			sum  = *(n1 + l1 - 1) - '0' + retenue;
		}
		else
		{
			sum = *(n1 + l1 - 1) - '0' + *(n2 + l2 - 1) - '0' + retenue;

		}
		retenue = sum / 10;
		*(r + size_r - 1) = sum % 10 + '0';
		l1--;
		l2--;
		size_r--;
	}
	if (size_r == 0 && l1 <= 0 && l2 <= 0 && retenue == 0)
		return (r);
	return (0);
}
