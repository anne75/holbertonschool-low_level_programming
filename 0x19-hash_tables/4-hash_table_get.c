#include "hash_tables.h"

/**
 * hash_table_get - retrieve a value from a key in a hash table
 * @ht: hash table
 * @key: key, a string
 * Return: value, a string or NULL on failure
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int hash;
	hash_node_t *node;

	if (!ht || !key)
		return (NULL);

	hash = key_index((const unsigned char *)key, ht->size);

	node = (ht->array)[hash];
	if (!node)
		return (NULL);

	while (node && strcmp((char *)key, node->key))
	{
		node = node->next;
	}

	if (!node)
		return (NULL);
	return (node->value);
}
