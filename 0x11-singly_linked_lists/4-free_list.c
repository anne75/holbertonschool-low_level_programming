#include "lists.h"
#include <stdio.h>

/**
 * free_list - free a linked list
 * @head: linked list
 *
 */
void free_list(list_t *head)
{
	list_t *tmp;

	if (head == NULL)
		return;

	tmp = head;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp->str);
		free(tmp);
	}

}
