#include "lists.h"

/**
 * free_dlistint - free a dll of int
 * @head: a pointer to a dll
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
