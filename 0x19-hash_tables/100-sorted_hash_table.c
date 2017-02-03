#include "hash_tables.h"


/**
 * shash_table_create - create a sorted hash table
 * @size: size of hash table
 * Return: pointer to hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	unsigned long int i;
	shash_table_t *ht;
	shash_node_t **array;

	if (size == 0)
		return (NULL);
	ht = malloc(sizeof(shash_table_t));
	if (!ht)
		return (NULL);
	array = malloc((sizeof(*array) * size));
	if (!array)
	{
		free(ht);
		return (NULL);
	}
	for (i = 0; i < size; ++i)
		array[i] = NULL;
	ht->size = size;
	ht->array = array;
	ht->shead = NULL;
	ht->stail = NULL;
	return (ht);
}

/**
 * shash_table_set - insert an element in a sorted hash table
 * @ht: pointer to hash table
 * @key: key value
 * @value: value
 * Return: 1 on success, 0 on error
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int hash;
	shash_node_t *new, *tmp;

	if (!ht | !key)
		return (0);
	hash = key_index((const unsigned char *)key, ht->size);
/*update node*/
	new = (ht->array)[hash];
	while (new && _strcmp(new->key, (char *)key))
		new = new->next;
	if (new)
		new->value = (char *)value;
	new = ht->shead;
	while (new && _strcmp(new->key, (char *)key))
		new = new->snext;
	if (new)
	{
		new->value = (char *)value;
		return (1);
	}
/*create new node*/
	new = malloc(sizeof(shash_node_t));
	if (!new)
		return (0);
	new->key = (char *)key, new->value = (char *)value;
	new->next = NULL, new->sprev = NULL, new->snext = NULL;
	if ((ht->array)[hash] == NULL)
	{
		(ht->array)[hash] = new;
	}
	else
	{
		new->next = ((ht->array)[hash]);
		(ht->array)[hash] = new;
	}
	if (ht->shead == NULL)
	{
		ht->shead = new;
		ht->stail = new;
	}
	else
	{
		if (hash < key_index((const unsigned char *)(ht->shead)->key,
				     ht->size))
		{
			new->snext = ht->shead, (ht->shead)->sprev = new;
			ht->shead = new;
		}
		else if (hash >
			 key_index((const unsigned char *)(ht->stail)->key,
				   ht->size))
		{
			(ht->stail)->snext = new, new->sprev = ht->stail;
			ht->stail = new;
		}
		else
		{
			tmp = ht->shead;
			while (hash > key_index((const unsigned char *)tmp->key,
						ht->size))
				tmp = tmp->snext;
			new->sprev = tmp, new->snext = tmp->next;
			(tmp->snext)->sprev = new, tmp->snext = new;
		}
	}
	return (1);
}



char *shash_table_get(const shash_table_t *ht, const char *key)
{}
void shash_table_print(const shash_table_t *ht)
{}
void shash_table_print_rev(const shash_table_t *ht){}


