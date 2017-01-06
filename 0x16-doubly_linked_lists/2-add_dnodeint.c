#include "lists.h"

/**
 * add_dnodeint - add a node at the beginning of a dll
 * @head: pointer to dll
 * @n: value to add
 * Return: pointer to new node or NULL
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;


	if (!head)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	new->next = *head;

	if (*head)
		(*head)->prev = new;
	*head = new;
	return (new);
}
