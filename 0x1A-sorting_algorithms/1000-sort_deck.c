#include "deck.h"


/**
 * get_value - transform a card into a number
 * @card: a card_t playing card
 * Return: an int value
 */
int get_value(const card_t *card)
{
	int value;
	char c;

	value = 1;
	if (card->kind == SPADE)
		value *= 0;
	else if (card->kind == HEART)
		value *= 100;
	else if (card->kind == CLUB)
		value *= 200;
	else if (card->kind == DIAMOND)
		value *= 300;
	else
		exit(98);

	c = *(card->value);
	if (c == '1')
		if (*((card->value) + 1) == '\0')
			value += 1;
		else
			value += 10;
	else if (c >= '2' && c <= '9')
		value += (c - '0');
	else if (c == 'J')
		value += 11;
	else if (c == 'Q')
		value += 12;
	else if (c == 'K')
		value += 13;

	return (value);
}

/**
 * _less - a comparator of cards
 * @c1: a card
 * @c2: another card
 * Return: 1 if c1 is <= c2 0 otherwise
 */
int _less(const card_t *c1, const card_t *c2)
{
	if (get_value(c1) <= get_value(c2))
		return (1);
	else
		return (0);
}


/**
 * swap - swap 2 elements in a doubly linked list
 * @list: linked list
 * @to_swap: element to swap
 * @compare: element to swap, place before to_swap
 */
void swap(deck_node_t **list, deck_node_t *to_swap, deck_node_t *compare)
{
	deck_node_t *tmp2;

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
 * sort_deck - sort a deck of cards
 * @list: a deck of card as a doubly linked list
 * Choice: quick sort, keeping the data structure
 */
void sort_deck(deck_node_t **list)
{
	int swapped;
	deck_node_t *cursor;

	if (!list || !*list || (*list)->next == NULL)
		return;
	swapped = 1;
	cursor = *list;
	while (swapped)
	{
		swapped = 0;
		while (cursor->next)
		{
			if (!_less(cursor->card, cursor->next->card))
			{
				swap(list, cursor->next, cursor);
				++swapped;
			}
			else
			{
			cursor = cursor->next;
			}
		}
		while (cursor->prev)
		{
			if (_less(cursor->card, (cursor->prev)->card))
			{
				swap(list, cursor, cursor->prev);
				++swapped;
			}
			else
			{
			cursor = cursor->prev;
			}
		}
	}
}
