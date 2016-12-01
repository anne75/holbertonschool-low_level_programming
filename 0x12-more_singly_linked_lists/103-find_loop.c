#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/*http://codingfreak.blogspot.com/2012/09/detecting-loop-in-singly-linked-
 *list_22.html
 *http://codingfreak.blogspot.com/2012/12/detecting-first-node-in-a-loop.html
 */

/**
 * find_listint_loop - find a loop in a linked list
 * @head: beginning of linked list
 * Return: address of the node where loop starts or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *hare, *turtle;

	if (head == NULL)
		return (NULL);

	turtle = head;
	hare = head;
/*assume in a non looping list, it always ends pointing to NULL*/
	while (turtle || hare)
	{
		hare = hare->next;
		if (hare)
			hare = hare->next;
		turtle = turtle->next;
		if (turtle == hare)
			break;
	}
	if (!turtle || !hare)
		return (NULL);

	turtle = head;
	while (turtle != hare)
	{
		hare = hare->next;
		turtle = turtle->next;
	}
	return (turtle);
}
