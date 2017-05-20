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
		'a', 'b', 'c', 'd', 'e', 'f'
	};
	size_t freq[] = {
		60, 40, 30, 20, 10, 1
	};
	size_t size = sizeof(data) / sizeof(data[0]);

	if (!huffman_codes(data, freq, size))
	{
		fprintf(stderr, "Failed to get Huffman codes\n");
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
