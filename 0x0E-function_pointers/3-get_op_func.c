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

	op_t ops[] = {{'+', op_add},
		      {'-', op_sub},
		      {'*', op_mul},
		      {'/', op_div},
		      {'%', op_mod} };

	if (s == NULL)
		return (NULL);

	i = 0;
	while (i < 5)
	{
		if (*s == ops[i].op && *(s + 1) == '\0')
		{
			return (ops[i].f);
		}
		++i;
	}

	return (NULL);
}
