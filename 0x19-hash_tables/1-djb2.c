#include "hash_tables.h"

/**
 * hash_djb2 - implement db2 algorithm
 * @str: a string
 * use http://www.cse.yorku.ca/%7Eoz/hash.html
 * Return: a number
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long hash;
	int c;

	hash = 5381;
	while ((c = *str++))
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return (hash);
}
