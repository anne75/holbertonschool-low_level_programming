#include "variadic_functions.h"

/**
 * print_strings - prints a variable number of strings
 * @separator: string to use to separate strings
 * @n: number of strings
 * Return: void
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list alist;
	char *a;

	i = 0;

	va_start(alist, n);
	while (i < n)
	{
		a = va_arg(alist, char *);
		printf("%s", (!a ? "(nil)" : a));
		++i;
		if (separator && i < n)
			printf("%s", separator);
	}
	puts("");
	va_end(alist);
}
