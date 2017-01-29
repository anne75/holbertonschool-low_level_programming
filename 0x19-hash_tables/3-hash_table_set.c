#include "hash_tables.h"

/**
 * _strcmp - compare 2 strings
 * @s1: a string
 * @s2: a string
 * Return: difference in character at first mismatch
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	if (!s1 || !s2)
		return (1);
	i = 0;
	while (*(s1 +i ) && *(s2 + i) && *(s1 + i) == *(s2 + i))
		++i;

	return (*(s1 + i) - *(s2 + i));
}


/**
 * has_table_set - add an element to a hash table
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

	if (!ht)
		return (0);

	hash = key_index((const unsigned char *)key, ht->size);

/*update node*/
	new = (ht->array)[hash];
	while (new && _strcmp(new->key, (char *)key))
	{
		new = new->next;
	}
	if (new)
	{
		new->value = (char *)value;
		return (1);
	}

/*create new node*/
	new = malloc(sizeof(hash_node_t));
	if (!new)
		return (0);
	new->key = (char *)key;
	new->value = (char *)value;
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
