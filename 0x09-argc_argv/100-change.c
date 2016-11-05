#include <stdio.h>

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
	return (number);
}

/**
 * main - greedy algorithm, minimal number of coins for change
 * @argc: number of arguments
 * @argv: list of arguments, given as strings
 * Return: 1 if not 2 args are given, 0 otherwise
 */
int main(int argc, char *argv[])
{
	int i;
	long int n, count;
	int coins[] = {25, 10, 5, 2, 1};

	if (argc != 2)
	{
		puts("Error");
		return (1);
	}
	n = _atoi(argv[1]);
	if (n < 0)
		return (1);
	count = 0;
	i = 0;
	while (n > 0)
	{
		if (n >= coins[i])
		{
			n = n - coins[i];
			count += 1;
			i--;
		}
		i++;
	}
	printf("%li\n", count);
	return (0);
}
