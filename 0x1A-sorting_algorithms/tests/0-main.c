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
/*	int array[] = {19, 18, 17, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};*/
/*	int array[] = {2, 1};*/
/*	int array[] = {-2, -2, -2, -2, -2, -2, -2, 1, -2, -2, -2, -2, -2, -2, -2};*/
	int array[] = {9, 17, 58, 21, -46, -50, -68, -69, 54, -44, -7, 2, 39, -34, -52, 20, -3, 70, 28, -9};

	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	bubble_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
