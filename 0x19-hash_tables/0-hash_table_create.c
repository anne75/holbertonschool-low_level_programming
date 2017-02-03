#include "hash_tables.h"

/**
 * hash_table_create - create a hash table with chaining
 * @size: size of hash table
 *
 * Return: pointer to hash_table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *h;
	hash_node_t **array;
	unsigned long int i;

	if (size == 0)
		return (NULL);

	array = malloc(sizeof(*array) * size);
	if (!array)
		return (NULL);
	for (i = 0; i < size; ++i)
		array[i] = NULL;

	h = malloc(sizeof(hash_table_t));
	if (!h)
	{
		free(array);
		return (NULL);
	}

	h->size = size;
	h->array = array;

	return (h);
}
