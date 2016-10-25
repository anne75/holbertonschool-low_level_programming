#include "holberton.h"
#include <stdio.h>

/**
 * _atoi - lay man version of atoi()
 * @s: string to conver to integer if possible
 * Return: int, value of 1st number in string
 */
int _atoi(char *s)
{
	int countp, countn, i, number;

	countp = 0;
	countn = 0;
	number = 0;

	i = 0;
	while ((s[i] < '0' || s[i] > '9') && s[i] != '\0')
	{
		if (s[i] == '+')
			countp++;
		if (s[i] == '-')
			countn++;
		i++;
	}

	while (s[i] >= '0' && s[i] <= '9' && s[i] != '\0')
	{
		number = 10 * number + (s[i] - '0');
		i++;
	}

	if (countp < countn && number != 0)
		number = -number;

	return (number);
}
