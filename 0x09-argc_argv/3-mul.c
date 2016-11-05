#include <stdio.h>
#include "holberton.h"
#include <stdlib.h>

/**
 * main - multiply 2 numbers, prints result
 * @argc: number of arguments
 * @argv: list of arguments
 * Return: 1 if number of arguments is not 3, 0 otherwise
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		puts("Error");
		return (1);
	}
	printf("%i\n", atoi(argv[1]) * atoi(argv[2]));
	return (0);
}
