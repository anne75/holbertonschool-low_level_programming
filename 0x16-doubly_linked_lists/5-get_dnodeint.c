#include "lists.h"

/**
 * get_dnodeint_at_index - return the node at index
 * @head: pointer to a dll
 * @index: index of the node
 * Return: pointer to node
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i;

/*	printf("%s, %i\n", (index < 0) ? "true" : "false", index + 1);*/
	i = 0;
	while (i < index && head != NULL)
	{
		head = head->next;
		++i;
	}
	if (i == index)
		return (head);
	return (NULL);
}
