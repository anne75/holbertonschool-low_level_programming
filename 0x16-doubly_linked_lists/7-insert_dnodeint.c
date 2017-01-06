#include "lists.h"

/**
 * insert_dnodeint_at_idx - insert a node at index in dll
 * @head: pointer to dll
 * @idx: index at which to insert node
 * @n: value to insert
 * Return: address of new node or NULL
 */
dlistint_t *insert_dnodeint_at_idx(dlistint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	dlistint_t *new, *tmp; /*keep my sanity*/

	if (!head || (idx > 0 && *head == NULL))
		return (NULL);

	i = 0;
	tmp = *head;
	while (i < (idx - 1) && tmp != NULL)
	{
		tmp = tmp->next;
		++i;
	}

	if (i < (idx - 1))
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->prev = tmp;
	if (tmp->next)
	{
		new->next = tmp->next;
		(tmp->next)->prev = new;
	}
	else
	{
		new->next = NULL;
	}
	tmp->next = new;

	return (new);
}
