#include "lists.h"

/**
 * add_dnodeint_end - add node at the end of a dll
 * @head: pointer to a linked list
 * @n: value to insert
 * Return: address of node or NULL
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *tmp;

	if (!head)
		return (NULL);
	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head)
	{
		for (tmp = *head; tmp->next;)
			tmp = tmp->next;
		new->prev = tmp;
		tmp->next = new;
	}
	else
	{
		new->prev = NULL;
		*head = new;
	}
	return (new);
}
