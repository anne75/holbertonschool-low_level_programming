#include "3-calc.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * get_op_func - return pointer to right operation
 * @s: should be + or - or * or / or %
 * Return: pointer to correct function
 */
int (*get_op_func(char *s))(int, int)
{
	int i;
	char ops[5] = {'+', '-', '*', '/', '%'};

	int (*p[5])(int, int) = {op_add, op_sub, op_mul, op_div, op_mod};

	i = 0;
	while (i < 5)
	{
		printf("DEBUG GET: s %s, ops %c\n", s, ops[i]);
		if (*s == ops[i])
		{
			puts("DEBUG GET: i have a match");
			return (p[i]);
		}
		++i;
	}

	return (NULL);
}
