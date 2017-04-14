#include "search_algos.h"
#include <math.h>


/**
 * get_node - return the node at some index in a linked list
 * @list: singly linked list
 * @idx: index, MUST be valid (no idea what to return otherwise)
 * Return: node at index
 */
listint_t *get_node(listint_t *list, size_t idx)
{
	if (!list)
		return (NULL);

	while (list->index < idx)
	{
		list = list->next;
		if (!list)
			return (NULL);
	}
	return (list);
}

/**
 * jump_list - implements the jump search algorithm in a singly linked list
 * @list: ordered singly linked list of int
 * @size: size of linked list
 * @value: value to search
 * Return: node at which value is found or -1
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step, lo, hi, i;
	listint_t *end, *start;

	if (!list || size <= 0)
		return (NULL);

	step = sqrt(size);
	lo = 0;
	hi = step;
	i = step;
	start = list;
	end = get_node(list, step);
	while (end->n < value && hi < size)
	{
/*
 * note that hi condition above requires to go down linear search
 * and prevent to return here if list[size] < value
 */
		printf("Value checked at index [%lu] = [%d]\n", i, end->n);
		lo = hi;
		hi += step;
		i = MIN(hi, size - 1);
		start = end;
		end = get_node(end, i);
	}
	printf("Value checked at index [%lu] = [%d]\n", i, end->n);
	printf("Value found between indexes [%lu] and [%lu]\n", lo, i);

	/*linear search between lo and hi*/
	hi = i;
	for (i = lo; i <= hi; ++i, start = start->next)
	{
		printf("Value checked at index[%lu] = [%d]\n", i, start->n);
		if (start->n == value)
			return (start);
	}
	return (NULL);
}
