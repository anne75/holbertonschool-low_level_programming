#include "heap.h"

/**
 * heapify_down - dive the root to its normal place
 * @heap: heap struct
 * if a node has one child it is a left child as a heap is complete
 * beware with cmp, node->data can be a binary_tree_node, so the function
 * will have to go deeper
 */
void heapify_down(heap_t *heap)
{
	binary_tree_node_t *node;

	if (!heap || !heap->root || !(heap->root)->left)
		return;

	node = heap->root;
	printf("enter heapify down for %p\n", (void *)node);
	while (node->left)
	{
		if (node->right &&
		    heap->data_cmp(node->right->data,
				   node->left->data) < 0 &&
		    heap->data_cmp(node->data,
				   node->left->data) > 0)
		{
			printf("heap down swap right\n");
			swap_node_pointers(node->right, node);
			if ((node - (heap->root)) == 0)
/*compare pointer values with subtractions*/
				heap->root = node->parent;
		}
		else if (heap->data_cmp(node->left->data,
					node->data) < 0)
		{
			printf("heap down swap_left\n");
			printf("Node(%p): data(%d) left(%p) right(%p) parent(%p)\n",
			       (void *)node, *((int *)node->data),
			       (void *)node->left,
			       (void *)node->right, (void *)node->parent);
			printf("Node->left(%p): data(%d) left(%p) right(%p) parent(%p)\n",
			       (void *)node->left, *((int *)node->left->data),
			       (void *)node->left->left,
			       (void *)node->left->right, (void *)node->left->parent);
			swap_node_pointers(node->left, node);
			if (((heap->root) - node) == 0)
				heap->root = node->parent;
		}
		else
		{
			node = node->left;
		}
	}
}

/**
 * heap_extract - extract the first element of a heap
 * @heap: heap struct
 * Return: data element of the extracted heap node
 */
void *heap_extract(heap_t *heap)
{
	queue_t *queue;
	binary_tree_node_t *node, *tmp;
	void *data;

	if (!heap)
		return (NULL);
	if (!(heap->root))
		return (NULL);

	queue = NULL;
	enqueue(&queue, heap->root);
	while (queue)
	{
		node = dequeue(&queue);
		enqueue(&queue, node->left);
		enqueue(&queue, node->right);
	}
	data = (heap->root)->data;
	if (node == heap->root)
	{
		free(node);
		heap->root = NULL;
		heap->size = 0;
		return (data);
	}
	if ((node->parent)->left == node)
		(node->parent)->left = NULL;
	else
		(node->parent)->right = NULL;
/*prepare swapping with the root, as we remove the root*/
	node->parent = NULL;
	tmp = heap->root;
	swap_nodes(tmp, node);
	heap->root = node;
	free(tmp);
	heap->size -= 1;
	printf("extracted root, heapify down %p\n", (void *)node);
	heapify_down(heap);
	return (data);
}
