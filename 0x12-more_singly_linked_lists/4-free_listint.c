#include "lists.h"
#include <stdlib.h>

/**
 * free_listint - free a linked list of integers
 * @head: pointer to list
 *
 */
void free_listint(listint_t *head)
{
	listint_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
