#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - replace operators
 * @ac: number of arguments
 * @av: string of arguments
 * Return: 0
 */
int main(int ac, char **av)
{
	int a, b;
	int (*op)(int, int);

	if (ac != 4)
	{
		puts("Error");
		exit(98);
	}

	op = get_op_func(av[2]);
	if (op == NULL)
	{
		puts("Error");
		exit(99);
	}

	a = atoi(av[1]);
	b = atoi(av[3]);
	if (b == 0 && (*(av[2]) == '/' || *(av[2]) == '%'))
	{
		puts("Error");
		exit(100);
	}
	printf("%d\n", op(a, b));
	return (0);
}
