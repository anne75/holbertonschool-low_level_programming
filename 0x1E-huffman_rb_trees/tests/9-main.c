#include <stdlib.h>
#include <stdio.h>
#include "../heap/heap.h"
#include "../huffman.h"

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	char data[] = {
		'H', 'o', 'l', 'b', 'e', 'r', 't', 'o', 'n'
	};
	size_t freq[] = {
		4, 32, 5, 12, 68, 6, 11, 12, 1
		/*1, 1, 1, 1, 1, 1, 1, 1, 1*/
	};
	size_t size = sizeof(data) / sizeof(data[0]);

	if (!huffman_codes(data, freq, size))
	{
		fprintf(stderr, "Failed to get Huffman codes\n");
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
