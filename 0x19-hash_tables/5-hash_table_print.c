#include "hash_tables.h"

/**
 * hash_table_print - print a hash table
 * @ht: a hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node;
	unsigned long int i;
	char *flag = "";

	if (!ht)
		return;

	putchar('{');
	for (i = 0; i < ht->size; ++i)
	{
		node = (ht->array[i]);
		if (node != NULL)
		{
			while (node)
			{
				printf("%s'%s': '%s'",
				      flag, node->key, node->value);
				flag = ", ";
				node = node->next;
			}
		}
	}
	puts("}");
}
