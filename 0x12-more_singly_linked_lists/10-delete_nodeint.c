#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - delete a node at index in a linked list
 * @head: pointer to pointer to linked list
 * @index: index at which to delete node
 * Return: 1 on success, -1 on failure
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i;
	listint_t *tmp, *tmp2;

	if (*head == NULL)
		return (-1);

	tmp = *head;
	if (index == 0)
	{
		*head = (*head)->next;
		free(tmp);
		return (1);
	}

	i = 0;
	while (tmp != NULL && i < (index - 1))
	{
		++i;
		tmp = tmp->next;
	}
/*either can't reach previous node or node at index == NULL*/
	if (i != (index - 1) || tmp->next == NULL)
		return (-1);
	tmp2 = tmp->next;
	tmp->next = (tmp->next)->next;
	free(tmp2);
	return (1);
}
