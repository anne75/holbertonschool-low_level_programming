#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * find_listint_loop - find a loop in a linked list
 * @head: beginning of linked list
 * Return: address of the node where loop starts or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	list_ad *address, *check;

	if (head == NULL)
		return (NULL);

	address = NULL;

/*assume in a non looping list, it always ends pointing to NULL*/
	while (head != NULL)
	{
		if (is_in(address,(void *) head))
		{
			free_add(address);
			return (head);
		}
		check = add_add(&address, (void *) head);
		if (check == NULL)
		{
			free_add(address);
			exit(98);
		}
		head = head->next;
	}
	free_add(address);
	return (NULL);
}
