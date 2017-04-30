#include "huffman.h"


binary_tree_node_t *huffman_tree(char *data, size_t *freq, size_t size)
{
	binary_tree_node_t *root;
	heap_t *heap;
	int result;

	heap = huffman_priority_queue(data, freq, size);
	if (!heap)
		return (NULL);

	while (heap->size > 1)
	{
		result = huffman_extract_and_insert(heap);
		if (result == 0)
			puts("there is a problem with extract_inset");
	}
	root = (binary_tree_node_t *)heap_extract(heap);
	heap_delete(heap, free_data);
	return (root);
}
