#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - free a linked list of integers, sets first element to NULL
 * @head: pointer to pointer to first element of list
 *
 */
void free_listint2(listint_t **head)
{
	listint_t *tmp1, *tmp2;

	if (!head || *head == NULL)
		return;

	tmp1 = *head;
	while (tmp1 != NULL)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
		free(tmp2);
	}
	*head = NULL;
}
