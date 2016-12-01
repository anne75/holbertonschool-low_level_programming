#include "lists.h"
#include <stdio.h>

/**
 * reverse_listint - reverse a linked list
 * @head: pointer to pointer to first element
 * loop only once, use 2 variables at most
 * Return: pointer to reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *tmp, *previous;

/*there is no list*/
	if (*head == NULL)
		return (*head);

/*loop through the list until last element */
	previous = NULL;
	tmp = (*head)->next;
	while (tmp != NULL)
	{
		(*head)->next = previous;
		previous = (*head);
		(*head) = tmp;
		tmp = tmp->next;
	}
/*do the last element*/
	(*head)->next = previous;

	return (*head);
}
