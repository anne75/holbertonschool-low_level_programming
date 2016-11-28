#include "lists.h"

/**
 * list_len - number of elements in a list
 * @h: a linked list
 * Return: number of elements in list
 */
size_t list_len(const list_t *h)
{
	size_t n;

	n = 0;

	while (h != NULL)
	{
		++n;
		if (h->next == NULL)
			return (n);
		h = h->next;
	}
	return (n);
}
