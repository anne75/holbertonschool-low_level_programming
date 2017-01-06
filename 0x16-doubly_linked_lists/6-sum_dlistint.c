#include "lists.h"

/**
 * sum_dlistint - sum all values in a dll
 * @head: pointer to dll
 * Return: sum
 */
int sum_dlistint(dlistint_t *head)
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
