#include "lists.h"

/**
 * sum_listint - sum all values in a linked list of integers
 * @head: pointer to first element
 * Return: sum of all values
 */
int sum_listint(listint_t *head)
{
	int sum;

	sum = 0;
	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
