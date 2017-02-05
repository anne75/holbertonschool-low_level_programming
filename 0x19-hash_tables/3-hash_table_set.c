#include "hash_tables.h"

/**
 * hash_table_help - create a node
 * @ht: hash table
 * @key: key
 * @value: value
 * @hash: index
 * Return: 1 on sucess 0 on error
 */
int hash_table_help(hash_table_t *ht, const char *key,
		    const char *value, unsigned long int hash)
{
	hash_node_t *new;
	char *s;

	new = malloc(sizeof(hash_node_t));
	if (!new)
	{
		/*free_ht(ht);*/
		return (0);
	}
	s = strdup(key);
	if (!s)
	{
		free(new);
		return (0);
	}
	new->key = s;
	s = NULL;
	if (value)
	{
		s = strdup(value);
		if (!s)
		{
			free(new->key), free(new);
			return (0);
		}
	}
	new->value = s;
	new->next = NULL;
	if ((ht->array)[hash] == NULL)
	{
		(ht->array)[hash] = new;
	}
	else
	{
		new->next = ((ht->array)[hash]);
		(ht->array)[hash] = new;
	}
	return (1);
}

/**
 * hash_table_set - add an element to a hash table
 * @ht: pointer to hash table
 * @key: key value
 * @value: value to add to the has table
 *
 * Return: 1 on success 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int hash;
	hash_node_t *new;
	char *s;

	if (!ht || !key)
		return (0);
	hash = key_index((const unsigned char *)key, ht->size);
/*update node*/
	new = (ht->array)[hash];
	while (new && strcmp(new->key, (char *)key))
	{
		new = new->next;
	}
	if (new)
	{
		s = strdup(value);
		if (!s)
			return (0);
		if (new->value)
			free(new->value);
		new->value = s;
		return (1);
	}
/*create new node*/
	return (hash_table_help(ht, key, value, hash));
}
