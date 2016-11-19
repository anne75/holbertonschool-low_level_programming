#include "variadic_functions.h"


/**
 * print_ci - prints va if it is a char or an int
 * @v: va_list
 * @s: format for printf
 * @end: separator for printf
 * Return: void
 */
void print_ci(va_list v, char *s, char *end)
{
	printf(s, end, va_arg(v, int));
}

/**
 * print_d - prints va if it is a float
 * @v: va_list
 * @s: format for printf
 * @end: separator for printf
 * Return: void
 */
void print_d(va_list v, char *s, char *end)
{
	printf(s, end, va_arg(v, double));
}

/**
 * print_s - prints va if it is a char *
 * @v: va_list
 * @s: format for printf
 * @end: separator for printf
 * Return: void
 */
void print_s(va_list v, char *s, char *end)
{
	char *arg;

	arg = va_arg(v, char *);
	if (!arg)
		arg = "(nil)";
	printf(s, end, arg);
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

	fs array[] = {{print_ci, "%s%c", 'c'},
		      {print_d, "%s%f", 'f'},
		      {print_ci, "%s%i", 'i'},
		      {print_s, "%s%s", 's'},
		      {NULL, "", '\0'}
	};

	if (format && *format)
	{
		j = 0;
		va_start(alist, format);
		end = "";
		while (*(format + j))
		{
			i = 0;
			while (i < 5)
			{
				if (*(format + j) == array[i].def)
				{
					array[i].mat(alist, array[i].s, end);
				}
				++i;
			}
			end = ", ";
			++j;
		}
		va_end(alist);
	}
	puts("");
}
