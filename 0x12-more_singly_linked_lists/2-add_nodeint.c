#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint - add a node at the beginning of a linked list
 * @head: pointer to the head of the list
 * @n: value to add
 * Return: address of the new element on success NULL otherwise
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
/*new and head are pointing to the same element, now to be 2nd in the list*/
	new->next = *head;
/*make the pointer to the first element point to the same thing as new now*/
	*head = new;

	return (new);
}
