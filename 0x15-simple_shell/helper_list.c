#include "shell.h"

/*this files contains helper functions for linked lists*/

/**
 * free_list - free a linked list
 * @head: linked list
 *
 */
void free_list(path_t *head)
{
	path_t *tmp;

	if (head == NULL)
		return;

	tmp = head;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * add_node_end - add a node at the end of a list
 * @head: pointer to the first element of a list
 * @str: value of the node to insert
 * Return: address of new element or NULL if failed
 */
path_t *add_node_end(path_t **head, const char *str)
{
	path_t *new;
	path_t **tmp;

	if(!head || !str)
		return (NULL);

	new = malloc(sizeof(path_t));
	if (new == NULL)
		return (NULL);

	new->path = _strdup(str);
	if (new->path == NULL)
	{
		free(new);
		return (NULL);
	}
	new->next = NULL;
/*try to apply Linus Torvald's good taste, no if*/
	tmp = head;
	while (*tmp != NULL)
		tmp = &((*tmp)->next);
	*tmp = new;
	return (new);
}
