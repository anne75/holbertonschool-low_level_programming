#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - return first element of linked list
 * @head: pointer to pointer to first element
 * Return: value of head node
 */
int pop_listint(listint_t **head)
{
	int n;

	if (*head == NULL)
		return (0);
/*value of node pointed by *head*/
	n = (*head)->n;
	free(*head);
/*assign to *head the pointer to the seond node*/
	*head = (*head)->next;

	return (n);
}
