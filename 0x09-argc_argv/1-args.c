#include <stdio.h>
#include "holberton.h"


/**
 * main - prints number of arguments given to program
 * @argc: number of arguments
 * @argv: list of arguments
 * Return: always 0
 */
int main(int argc, __attribute__ ((unused)) char *argv[])
{
	printf("%i\n", argc - 1);
	return (0);
}
