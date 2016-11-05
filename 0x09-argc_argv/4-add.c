#include <stdio.h>
#include "holberton.h"


/**
 * _atoi - convert a string to a positive number
 * @s: string
 * assume the string consists only of integers or starts with something else
 * Return: positive integer or -1
 */
int _atoi(char *s)
{
	int number;

	number = 0;
	if (*s < '0' || *s > '9')
		return (-1);
	while (*s >= '0' && *s <= '9')
	{
		number = number * 10 + (*s - '0');
		s++;
	}
	if (*s == '\0')
		return (number);
	return (-1);
}

/**
 * main - adds command passed arguments if they are positive intgers
 * @argc: number of arguments
 * @argv: list of arguments, passed as strings
 * Return: 0 if no or all arguments are positive int, 1 otherwise
 */
int main(int argc, char *argv[])
{
	int i, n, sum;

	sum = 0;
	i = 1;
	while (i < argc)
	{
		n = _atoi(argv[i]);
		if (n < 0)
		{
			puts("Error");
			return (1);
		}
		sum += n;
		i++;
	}
	printf("%i\n", sum);
	return (0);
}
