#include "lists.h"
#include <stdio.h>

/**
 * print_listint - prints a linked list of integers
 * @h: a linked list
 * Return: size of linked list
 */
size_t print_listint(const listint_t *h)
{
	size_t l;

	l = 0;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		++l;
		h = h->next;
	}
	return (l);
}
