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
 * insert_sorted_node - insert a node in sorted hash order
 * @ht: pointer to hash table
 * @new: node
 * Return: 1 on success, 0 on failure
 */
int insert_sorted_node(shash_table_t *ht, shash_node_t *new)
{
	shash_node_t *tmp;

	if (!ht || !new)
		return (0);

	if (ht->shead == NULL)
	{
		ht->shead = new;
		ht->stail = new;
	}
	else
	{
		if (strcmp(new->key, (ht->shead)->key) <= 0)
		{
			new->snext = ht->shead, (ht->shead)->sprev = new;
			ht->shead = new;
		}
		else if (strcmp(new->key, (ht->stail)->key) > 0)
		{
			(ht->stail)->snext = new, new->sprev = ht->stail;
			ht->stail = new;
		}
		else
		{
/* should be able to put last 2 cases together, better ?*/
			tmp = ht->shead;
			while (tmp->snext && strcmp(new->key, (tmp->snext)->key) > 0)
				tmp = tmp->snext;
			new->sprev = tmp, new->snext = tmp->snext;
			(tmp->snext)->sprev = new, tmp->snext = new;
		}
	}
	return (1);
}

/**
 * create_node - create a node
 * @ht: hash table
 * @key: a key
 * @value: value
 * @hash: index
 * Return: 0 on failure, 1 on success
 */
int create_node(shash_table_t *ht, const char *key,
		    const char *value, unsigned long int hash)
{
	shash_node_t *new;
	char *s;

	if (!ht || !key)
		return (0);

	new = malloc(sizeof(shash_node_t));
	if (!new)
		return (0);
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
			free(new->key);
			free(new);
			return (0);
		}
	}
	new->value = s;
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
	return (insert_sorted_node(ht, new));
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
	shash_node_t *new;
	char *s;

	if (!ht | !key)
		return (0);
	hash = key_index((const unsigned char *)key, ht->size);
	s = NULL;
/*update node*/
	new = (ht->array)[hash];
	while (new && strcmp(new->key, (char *)key))
		new = new->next;
	if (new)
	{
		if (value)
		{
			s = strdup(value);
			if (!s)
				return (0);
		}
		if (new->value)
			free(new->value);
		new->value = s;
		return (1);
	}
/*create new node*/
	return (create_node(ht, key, value, hash));
}

/**
 * shash_table_get - retrieve value from key
 * @ht: hash table
 * @key: key
 * Return: value, a string
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int hash;
	shash_node_t *node;

	if (!ht)
		return (NULL);
	hash = key_index((const unsigned char *)key, ht->size);

	if ((ht->array)[hash] == NULL)
	{
		return (NULL);
	}
	node = (ht->array)[hash];
	while (node && strcmp(node->key, (char *)key))
		node = node->next;

	if (!node)
		return (NULL);
	return (node->value);

}

/**
 * shash_table_print - print a sorted hash table in increasing order
 * @ht: hash table, sorted
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;
	char *flag = "";

	if (!ht)
		return;
	node = ht->shead;

	putchar('{');
	while (node)
	{
		printf("%s'%s': '%s'", flag, node->key, node->value);
		flag = ", ";
		node = node->snext;
	}
	puts("}");

}

/**
 * shash_table_print_rev - print a sorted hash table in decreasing order
 * @ht: sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;
	char *flag = "";

	if (!ht)
		return;
	node = ht->stail;

	putchar('{');
	while (node)
	{
		printf("%s'%s': '%s'", flag, node->key, node->value);
		flag = ", ";
		node = node->sprev;
	}
	puts("}");
}



/**
 * hash_table_printt - print a hash table
 * @ht: a hash table
 */
void hash_table_printt(const shash_table_t *ht)
{
	shash_node_t *node;
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
			puts("new node");
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

/**
 * shash_table_delete - delete a sorted hash table
 * @ht: a hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *node, *tmp;

	if (!ht)
		return;
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
		}
	}
	free(ht->array);
	ht->array = NULL;
	free(ht);
	ht = NULL;
}
