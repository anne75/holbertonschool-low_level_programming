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


/* other solution using recursion
 * at each step I consider the node I am at and the next node
 * I call recursion on the rest of the linked list, which
 * is a linked list that starts at next.
 * I can then reset the value of the next->next node which had been set to
 * NULL in the recursive call and set to NULL head->next.
 */
listint_t *reverse_recursive(listint_t **head)
{
	listint_t *next, *rest;

	if (!head)
		return (NULL);
	if (*head == NULL)
		return (*head);
/*base case*/
	if ((*head)->next == NULL)
		return (*head);
/*create next node*/
	next = (*head)->next;
/*call function on linked list starting at next*/
	rest = reverse_recursive(&next);
/*set true value of next->next, was set to NULL in recursive call*/
	next->next = (*head);
/*set head->next*/
	(*head)->next = NULL;

	return (rest);
}
