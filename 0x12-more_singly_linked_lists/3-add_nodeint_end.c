#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint_end - add node at the end of the linked list
 * @head: pointer to the head of the list
 * @n: value to add
 * Return: address of the new element on success, 0 otherwise
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new, *tmp;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

/*list is empty, new is first element*/
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
/*otherwise*/
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = new;
	return (new);
}
