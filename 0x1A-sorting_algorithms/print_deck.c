#include "deck.h"

/**
 * _suit - match a suit with a number
 * @kind: kind_t
 * Return: C, S, H or D
 */
char _suit(kind_t kind)
{
	switch (kind)
	{
	case SPADE:
		return ('S');
	case HEART:
		return ('H');
	case CLUB:
		return ('C');
	case DIAMOND:
		return ('D');
	}
	return ('w');
}



/**
 * print_deck - print a deck of cards
 * @deck: deck of card as a doubly linked list of card_t type
 */
void print_deck(deck_node_t *deck)
{
	int i;

	i = 1;

	while (deck)
	{
		printf("{%s, %c}", deck->card->value, _suit(deck->card->kind));
		if (i % 13)
			printf(", ");
		else
			puts("");
		deck = deck->next;
		++i;
	}
}
