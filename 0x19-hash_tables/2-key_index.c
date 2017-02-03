#include "hash_tables.h"

/**
 * key_index - returns the index at which the key should be
 * @key: a string
 * @size: size of hash table
 *
 * Return: index of a given key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash;

	hash = hash_djb2(key);
	if (size != 0)
		return (hash % size);
	return (0);
}
