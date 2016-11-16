#include <stdlib.h>

/**
 * print_name - passes a name to a printing function
 * @name: a string
 * @f: a pointer to a printing function
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	if (f == NULL)
		exit(98);
	f(name);
}

