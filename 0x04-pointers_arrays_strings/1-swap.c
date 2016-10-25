#include "holberton.h"

/**
 * swap_int - swap two integers
 *@a: pointer to an int to swap
 *@b: pointer to an int to swpa
 *Return: void
 */
void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
