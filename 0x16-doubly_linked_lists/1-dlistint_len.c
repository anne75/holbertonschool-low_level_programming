#include "lists.h"

/**
 * dlistint_len - return length of dll
 * @h: pointer to dll
 * Return: size of dll
 */
size_t dlistint_len(const dlistint_t *h)
{
	int count;

	for (count = 0; h; h = h->next)
		++count;

	return (count);
}
