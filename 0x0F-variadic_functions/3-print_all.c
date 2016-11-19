#include "variadic_functions.h"

#define PRINT(t) ("%"#t)

/**
 * print_ci - prints va if it is a char or an int
 * @v: va_list
 * @s: format for printf
 * @end: separator for printf
 * Return: void
 */
void print_ci(va_list v, char *s, char *end)
{
	printf(s, va_arg(v, int), end);
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
	printf(s, va_arg(v, double), end);
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
	printf(s, arg, end);
}

/**
 * chose - function to chose which printing function to use
 * @format: type of element to print
 * @vp: va_list
 * @array: a struct array to chose the function and its arguments
 * @end: separator after print
 * Return: void
 */
void chose(char format, va_list vp, fs array[], char *end)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (format == array[i].def)
		{
			array[i].mat(vp, array[i].s, end);
		}
		++i;
	}
}

/**
 * print_all - prints a variable number of arguments
 * @format: a string giving format to expect
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	int j;
	va_list alist;

	fs array[] = {{'c', print_ci, "%c%s"},
		      {'f', print_d, "%f%s"},
		      {'i', print_ci, "%i%s"},
		      {'s', print_s, "%s%s"},
		      {'\0', NULL, ""}
	};

	j = 0;
	va_start(alist, format);
	while (*(format + j) && *(format + j + 1))
	{
		chose(*(format + j), alist, array, ", ");
		++j;
	}
	chose(*(format + j), alist, array, "\n");
	va_end(alist);
}
