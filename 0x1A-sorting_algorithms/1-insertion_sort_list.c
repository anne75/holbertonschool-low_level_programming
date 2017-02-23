#include "sort.h"


/**
 * swap - swap 2 elements in a doubly linked list
 * @list: linked list
 * @to_swap: element to swap
 * @compare: element to swap, place before to_swap
 */
void swap(listint_t **list, listint_t *to_swap, listint_t *compare)
{
	listint_t *tmp2;

	/*swap nodes*/
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
 * insertion_sort_list - sort a linked list with insertion sort
 * @list: a linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *to_swap, *compare;

	if (!list || !*list || (*list)->next == NULL)
		return;

	tmp = *list;
	while (tmp)
	{
		to_swap = tmp; /*mark the candidate to insert on the left*/
		compare = tmp->prev; /*start of the reverse loop*/
		tmp = tmp->next; /*move tmp, in case of swap, otherwise we lose it*/
		while (compare && (compare->n > to_swap->n))
		{
			swap(list, to_swap, compare);
			compare = to_swap->prev;
			print_list(*list);
		}
	}
}
