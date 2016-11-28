#include "lists.h"
#include <stdio.h>

/**
 * print_list - print all the elements of a list
 * @h: a list
 * Return: number of nodes
 */
size_t print_list(const list_t *h)
{
	size_t n;

	n = 0;
	while (h != NULL)
	{
		printf("[%i] %s\n", h->len, h->str);
		++n;
		if (h->next == NULL)
			return (n);
		h = h->next;
	}
	return (n);
}
