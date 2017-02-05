#include "hash_tables.h"

/**
 * hash_table_delete - free a hash table
 * @ht: hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *node, *tmp;

	for (i = 0; i < ht->size; ++i)
	{
		node = (ht->array)[i];
		while (node)
		{
			tmp = node;
			node = node->next;
			free(tmp->key);
			tmp->key = NULL;
			free(tmp->value);
			tmp->value = NULL;
			free(tmp);
			tmp = NULL;
		}
	}
	free(ht->array);
	ht->array = NULL;
	free(ht);
	ht = NULL;
}
