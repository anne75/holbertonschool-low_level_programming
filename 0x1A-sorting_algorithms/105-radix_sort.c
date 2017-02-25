#include "sort.h"


/**
 * _max - returns the maximum value in an array
 * @array: array
 * @size: size of array
 * Return: maximum value
 */
int _max(int *array, size_t size)
{
	int max_v;
	size_t i;

	if (!array || size == 0)
		return (0);

	max_v = array[0];
	for (i = 1; i < size; ++i)
	{
		if (array[i] > max_v)
			max_v = array[i];
	}
	return (max_v);
}


/**
 * get_nb_digits - return the number of digits in a number
 * @n: an int (positive)
 * Return: number of digits
 */
int get_nb_digits(int n)
{
	int i;

	i = 1;
	while ((n / 10) > 0)
	{
		++i;
		n /= 10;
	}
	return (i);
}


/**
 * radix_sort - implement LSD sort for an array of integers
 * @array: array of ints
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int max_number, nb_digit, divisor, i, j, k;
	size_t jprime;
	int *count, *tmp;

	if (!array || size < 2)
		return;
	max_number = _max(array, size);
	count = malloc(sizeof(int) * 11);
	if (!count)
		return;
	tmp = malloc(sizeof(int) * size);
	if (!tmp)
	{
		free(count);
		return;
	}
	nb_digit = get_nb_digits(max_number);
	divisor = 1;
	for (i = 1; i <= nb_digit; ++i)
	{
		for (j = 0; j < 11; ++j)
			count[j] = 0;
		for (jprime = 0; jprime < size; ++jprime)
			count[(array[jprime] / divisor) % 10 + 1] += 1;
		for (j = 1; j < 11; ++j)
			count[j] += count[j - 1];
		for (jprime = 0; jprime < size; ++jprime)
		{
			k = (array[jprime] / divisor) % 10;
			tmp[count[k]] = array[jprime];
			count[k] += 1;
		}
		for (jprime = 0; jprime < size; ++jprime)
			array[jprime] = tmp[jprime];
		print_array(array, size);
		divisor *= 10;
	}
	free(count);
	free(tmp);
}
