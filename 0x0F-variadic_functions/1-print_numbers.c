#include "variadic_functions.h"

/**
 * print_numbers - print all numbers given as variables arguments
 * @separator: separator between numbers
 * @n: number of variable args
 * Return: void
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list alist;

	i = 0;

	va_start(alist, n);
	while (i < n)
	{
		printf("%d", va_arg(alist, int));
		i++;
		if (separator && i < n)
			printf("%s", separator);
	}
	puts("");
	va_end(alist);
}
