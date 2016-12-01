#include "lists.h"


/**
 * listint_len - size of linked list
 * @h: a linked list
 * Return: number of nodes in the list
 */
size_t listint_len(const listint_t *h)
{
	size_t l;

	l = 0;
	if (h == NULL)
		return (l);

	while (h != NULL)
	{
		++l;
		h = h->next;
	}
	return (l);
}
