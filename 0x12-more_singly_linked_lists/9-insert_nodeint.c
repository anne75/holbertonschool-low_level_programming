#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - insert a node at index in linked list
 * @head: pointer to pointer to first element
 * @index: index at which to insert node
 * @n: value to insert
 * if index is not reachable, do not insert
 * Return: the address of the new node if success, NULL otherwise
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int index, int n)
{
	unsigned int i;
	listint_t *new, *tmp;

	if (!head)
		return (NULL);
/*insert at head, head can be NULL*/
	if (index == 0)
	{
		new = malloc(sizeof(listint_t));
		if (new == NULL)
			return (NULL);
		new->n = n;
		new->next = *head;
		*head = new;
		return (new);
	}
/*otherwise, I stop just before the index to set the next value of the
 * previous node
 */
	i = 0;
	tmp = *head;
	while (tmp != NULL && i < (index - 1))
	{
		++i;
		tmp = tmp->next;
	}
/*the list is too short, or head is NULL (case NULL head i = 1), or tmp NULL*/
	if (head == NULL || i != index - 1 || tmp == NULL)
		return (NULL);
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
/*set the next value of the new node to the one of the previous node*/
	new->next = tmp->next;
/*set the new next value of the previous node*/
	tmp->next = new;
	return (new);
}
