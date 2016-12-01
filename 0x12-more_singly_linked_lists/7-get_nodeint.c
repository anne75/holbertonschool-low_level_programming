#include "lists.h"
#include <stdio.h>

/**
 * get_nodeint_at_index - return the node at index
 * @head: pointer to first element
 * @index: position that needs to be returned
 * Return: pointer to node at index
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;

	i = 0;
	while (head != NULL && i < index)
	{
		head = head->next;
		++i;
	}

	if (i == index)
		return (head);

	return (NULL);
}
