#ifndef _LISTS_H_
#define _LISTS_H_

#include <stdlib.h>
#include <stdio.h>


/**
 * struct dlistint_s - doubly linked list
 * @n: integer
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 * for Holberton project
 */
typedef struct dlistint_s
{
	int n;
	struct dlistint_s *prev;
	struct dlistint_s *next;
} dlistint_t;


/*question 0*/
size_t print_dlistint(const dlistint_t *h);

/*question 1*/
size_t dlistint_len(const dlistint_t *h);

/*question 2*/
dlistint_t *add_dnodeint(dlistint_t **head, const int n);

/*question 3*/
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);

/*question 4*/
void free_dlistint(dlistint_t *head);

/*question 5*/
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index);

/*question 6*/
int sum_dlistint(dlistint_t *head);

/*question 7*/
dlistint_t *insert_dnodeint_at_idx(dlistint_t **head, unsigned int idx, int n);

/*question 8*/
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);

#endif
