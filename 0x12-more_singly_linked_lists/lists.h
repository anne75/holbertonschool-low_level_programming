#ifndef _LISTS_H_
#define _LISTS_H_

/*header file for 0x12*/
/*get the definition of size_t*/
#include <stddef.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

/**
 * struct list_ads - singly linked list
 * @p: an address
 * @next: points to the next node
 * Description: this singly linked list holds addresses
 * of encountered pointers
 */
typedef struct list_ads
{
	void *p;
	struct list_ads *next;
} list_ad;


/*in case we need it*/
int _putchar(char *);

/*question 0*/
size_t print_listint(const listint_t *h);

/*question 1*/
size_t listint_len(const listint_t *h);

/*question 2*/
listint_t *add_nodeint(listint_t **head, const int n);

/*question 3*/
listint_t *add_nodeint_end(listint_t **head, const int n);

/*question 4*/
void free_listint(listint_t *head);

/*question 5*/
void free_listint2(listint_t **head);

/*question 6*/
int pop_listint(listint_t **head);

/*question 7*/
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index);

/*question 8*/
int sum_listint(listint_t *head);

/*question 9*/
/**
 * insert_nodeint_at_index - insert a node at index in linked list
 * @head: pointer to pointer to first element
 * @index: index at which to insert node
 * @n: value to insert
 * if index is not reachable, do not insert
 * Return: the address of the new node if success, NULL otherwise
 */
listint_t *insert_nodeint_at_index(listint_t **head,
				   unsigned int index, int n);

/*question 10*/
int delete_nodeint_at_index(listint_t **head, unsigned int index);

/*question 100*/
listint_t *reverse_listint(listint_t **head);

/*question 101*/
size_t print_listint_safe(const listint_t *head);
int is_in(list_ad *add, void *p);
list_ad *add_add(list_ad **head, void *p);
void free_add(list_ad *head);

/*question 102*/
size_t free_listint_safe(listint_t **h);

/*question 103*/
listint_t *find_listint_loop(listint_t *head);

#endif
