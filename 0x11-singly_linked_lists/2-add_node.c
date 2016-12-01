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
 * add_node - add a node at the beginning of a list
 * @head: pointer to the first element of a list
 * @str: value of the node to insert
 * Return: address of new element or NULL if failed
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;

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
	if (head != NULL)
		new->next = *head;
	*head = new;
	return (new);
}
