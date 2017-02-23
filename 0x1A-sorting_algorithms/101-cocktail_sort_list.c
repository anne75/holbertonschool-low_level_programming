#include "sort.h"


/**
 * swap - swap 2 elements in a doubly linked list
 * @list: linked list
 * @to_swap: element to swap
 * @compare: element to swap, placed before to_swap
 */
void swap(listint_t **list, listint_t *to_swap, listint_t *compare)
{
	listint_t *tmp2;

	if (compare->next == to_swap)
	{
		if (to_swap->next)
			(to_swap->next)->prev = compare;
		tmp2 = to_swap->next;
		to_swap->next = compare;
		compare->next = tmp2;
		tmp2 = to_swap->prev;
		to_swap->prev = compare->prev;
		compare->prev = to_swap;
	}
	else
	{
		if (to_swap->next)
			(to_swap->next->prev) = compare;
		(to_swap->prev)->next = compare;
		(compare->next)->prev = to_swap;
		tmp2 = to_swap->next;
		to_swap->next = compare->next;
		compare->next = tmp2;
		tmp2 = to_swap->prev;
		to_swap->prev = compare->prev;
		compare->prev = tmp2;
	}
	if (to_swap->prev)
		(to_swap->prev)->next = to_swap;
	else
		*list = to_swap;
}

/**
 * cocktail_sort_list - sort with cocktail sort algorithm
 * @list: doubly linked list of int
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *cursor;

	if (!list || !*list)
		return;
	swapped = 1;
	cursor = *list;
	while (swapped)
	{
		swapped = 0;
		while (cursor->next)
		{
			if (cursor->n > (cursor->next)->n)
			{
				swap(list, cursor->next, cursor);
				print_list(*list);
				++swapped;
			}
			else
			{
			cursor = cursor->next;
			}
		}
		while (cursor->prev)
		{
			if (cursor->n < (cursor->prev)->n)
			{
				swap(list, cursor, cursor->prev);
				print_list(*list);
				++swapped;
			}
			else
			{
			cursor = cursor->prev;
			}
		}
	}
}
