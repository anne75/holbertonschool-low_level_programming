#include <stdio.h>
#include <stdlib.h>
#include "../sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
/*	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};*/
/*	int array[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5};*/
/*	int array[] = {1, 3, 2, 1, 3, 3, 3, 3, 2, 2, 2, 2, 1, 1, 1, 2, 1, 2, 2};*/
/*	int array[] = {-35};*/
	int array[] = {-3, -3, -7};

	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	shell_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
