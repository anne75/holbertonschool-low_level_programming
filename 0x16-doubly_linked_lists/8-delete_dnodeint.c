#include "lists.h"

/**
 * delete_dnodeint_at_index - delate node at index
 * @head: pointer to dll
 * @index: index at which to delete node
 * Return: 1 on success, -1 otherwise
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int i;
	dlistint_t **tmp, *tmp2;

	if (!head || !*head)
		return (-1);

	i = 0;
	tmp = head;
	while (i < index && (*tmp)->next != NULL)
	{
		++i;
		tmp = &((*tmp)->next);
	}
	if (i < index)
		return (-1);

	if ((*tmp)->next)
		((*tmp)->next)->prev = (*tmp)->prev;
	tmp2 = *tmp;
	*tmp = (*tmp)->next;
	free(tmp2);
	return (1);
}
