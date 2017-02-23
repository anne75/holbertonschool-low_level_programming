#include <stdio.h>
#include "sort.h"

/**
 * print_list_rev - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list_rev(const listint_t *list)
{
	int i;

	if (!list)
		return;
	i = 0;
	while (list->next)
		list = list->next;
	while (list)
	{
		if (i > 0)
			printf(", ");
		printf("%d", list->n);
		++i;
		list = list->prev;
	}
	printf("\n");
}
