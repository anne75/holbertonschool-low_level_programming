#ifndef _LISTS_H_
#define _LISTS_H_

#include <stdlib.h>

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;


/*question 0*/
size_t print_list(const list_t *h);

/*question 1*/
size_t list_len(const list_t *h);

/*question 2*/
list_t *add_node(list_t **head, const char *str);

/*question 3*/
list_t *add_node_end(list_t **head, const char *str);

/*question 4*/
void free_list(list_t *head);





#endif
