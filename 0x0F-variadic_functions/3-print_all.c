#include "variadic_functions.h"


/**
 * print_ci - prints va if it is a char or an int
 * @v: va_list
 * @s: format for printf
 * Return: void
 */
void print_ci(va_list v, char *s)
{
	printf(s, va_arg(v, int));
}

/**
 * print_d - prints va if it is a float
 * @v: va_list
 * @s: format for printf
 * Return: void
 */
void print_d(va_list v, char *s)
{
	printf(s, va_arg(v, double));
}

/**
 * print_s - prints va if it is a char *
 * @v: va_list
 * @s: format for printf
 * Return: void
 */
void print_s(va_list v, char *s)
{
	char *arg;

	arg = va_arg(v, char *);
	if (!arg)
		arg = "(nil)";
	printf(s, arg);
}

/**
 * print_all - prints a variable number of arguments
 * @format: a string giving format to expect
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	int i, j;
	char *end;
	va_list alist;

	fs array[] = {{print_ci, "%c", 'c'},
		      {print_d, "%f", 'f'},
		      {print_ci, "%i", 'i'},
		      {print_s, "%s", 's'},
	};

	va_start(alist, format);
	j = 0;
	end = "";
	while (format && *(format + j))
	{
		i = 0;
		while (i < 4)
		{
			if (*(format + j) == array[i].def)
			{
				printf("%s", end);
				array[i].mat(alist, array[i].s);
				end = ", ";
			}
			++i;
		}
		++j;
	}
	va_end(alist);
	puts("");
}
