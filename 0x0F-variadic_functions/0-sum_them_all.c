#include "variadic_functions.h"

/**
 * sum_them_all - sum all variable arguments
 * @n: number of arguments
 *
 * Return:sum
 */
int sum_them_all(const unsigned int n, ...)
{
	unsigned int i;
	int sum;
	va_list alist;

	if (!n)
		return (0);

	i = 0;
	sum = 0;
	va_start(alist, n);
	while (i < n)
	{
		sum += va_arg(alist, int);
		++i;
	}
	va_end(alist);

	return (sum);
}
