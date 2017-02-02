#ifndef _HASH_TABLES_
#define _HASH_TABLES_

#include <stdio.h>
#include <stdlib.h>

/**
 * struct hash_node_s - node for hah table
 * @key : The key, string
 * The key is unique in the HashTable
 * @value : The value corresponding to a key
 * @next : A pointer to the next node of the list
 */
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - struct for hash table
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 */
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

/*question 0*/
hash_table_t *hash_table_create(unsigned long int size);

/*question 1*/
unsigned long int hash_djb2(const unsigned char *str);

/*question 2*/
unsigned long int key_index(const unsigned char *key, unsigned long int size);

/*question 3*/
int _strcmp(char *s1, char *s2);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);

/*question 4*/
char *hash_table_get(const hash_table_t *ht, const char *key);

/*question 5*/
void hash_table_print(const hash_table_t *ht);


#endif
