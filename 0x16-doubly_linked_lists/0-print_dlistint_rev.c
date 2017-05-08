#include "lists.h"
#include "lists.h"
/**
 * print_dlistint_rev - print all the elements in a dll, starting from the end
 * @h: pointer to dll
 * Return: size of dll
 */
size_t print_dlistint_rev(const dlistint_t *h)
{
	size_t count;

	count = 0;
	while (h != NULL && h->next != NULL)
		h = h->next;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		++count;
		h = h->prev;
	}
	return (count);
}
