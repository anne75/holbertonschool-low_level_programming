#include "search_algos.h"
#include <math.h>


/**
 * get_node - return the node at some index in a linked list
 * @list: singly linked list
 * @idx: index, MUST be valid (no idea what to return otherwise)
 * Return: node at index
 */
skiplist_t *get_node(skiplist_t *list, size_t idx)
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
 * linear_skip - implements the jump search algorithm in a singly linked list
 * @list: ordered singly skip list of int
 * @value: value to search
 * Return: node at which value is found or -1
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *end, *start;

	if (!list)
		return (NULL);
	start = list;
	end = list->express;
	while (end && end->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       end->index, end->n);
		start = end;
		end = end->express;
	}
	if (end)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       end->index, end->n);
	}
	else
	{
		/*reach last node*/
		end = start;
		while (end->next)
			end = end->next;
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
	       start->index, end->index);
	/*linear search between lo and hi*/
	while (start != end)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       start->index, start->n);
		if (start->n == value)
			return (start);
		start = start->next;
	}
	printf("Value checked at index [%lu] = [%d]\n", start->index, start->n);
	if (start->n == value)
		return (start);
	return (NULL);
}
