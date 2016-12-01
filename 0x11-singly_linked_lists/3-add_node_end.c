#include "lists.h"
#include <string.h>
#include <stdio.h>

/**
 * _strlen - get length of a string
 * @s: a string
 * Return: length of string
 */
int _strlen(const char *s)
{
	int i;

	for (i = 0; *(s + i); ++i)
		;
	return (i);
}


/**
 * add_node_end - add a node to the endo of the list
 * @head: pointer to the list
 * @str: value to add
 * Return: address of new element or NULL if failed
 */
list_t *add_node_end(list_t **head, const char *str)
{

	list_t *new, *tmp;

	new = malloc(sizeof(list_t));
	if (new == NULL || str == NULL)
		return (NULL);
	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}
	new->len = _strlen(str);
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	tmp = *head;
	while (tmp != NULL)
	{
		if (tmp->next == NULL)
		{
			tmp->next = new;
			return (new);
		}
		tmp = tmp->next;
	}
	return (new);
}
