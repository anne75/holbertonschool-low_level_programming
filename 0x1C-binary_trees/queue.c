/* this is a helper file to insert in 101...
 * we build a queue of binary_tree_t * values
 * the queue is a singly linked list
 * each call to enqueue inserts a tree node (malloc)
 * each call to dequeue returns a tree node (free)
 */

/**
 * struct queue_s - struct for a tree linked list
 * @node: a binary_tree_t *
 * @next: pointer to the next value
 */
typedef struct queue_s
{
	binary_tree_t *node;
	struct tree_queue_s *next;
} queue_t;


/**
 * enqueue - insert a node at the end
 * @head: head of queue
 * @node: node to insert
 * Return: pointer to newly created list element or NULL on failure
 */
queue_t *enqueue(queue_t **head, binary_tree_t *node)
{
	queue_t *new, *tmp;

	if (!node)
		return (NULL); /*do not insert a null value*/

	if (!head)
		return (NULL); /*edge case we should not meet here*/

	new = malloc(sizeof(queue_t));
	if (!new)
		return (NULL);

	new->node = node;
	new->next = NULL;
	if (!*head)
	{
		*head = new;
	}
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (new);
}

/**
 * dequeue - return a node from the beginning
 * @head: head of queue
 * Return: a pointer to a binary tree node
 */
binary_tree_t *dequeue(queue_t **head)
{
	queue_t *tmp;
	binary_tree_t *node;

	if (!head || !*head)
		return (NULL);

	tmp = *head;
	*head = tmp->next;
	node = tmp->node;
	free(tmp);

	return (node);
}
