#include "binary_trees.h"
/**
 * heapify_downward - basically performs a binary search downward
 * and swaps when parent < child
 * @tree: ptr to root
 */
void heapify_downward(heap_t *tree)
{
	int temp;

	if (!tree || !(tree->right || tree->left))
		return;
	else if (!(tree->right))
	{
		if (tree->left->n > tree->n)
		{
			temp = tree->n;
			tree->n = tree->left->n;
			tree->left->n = temp;
			heapify_downward(tree->left);
			return;
		}
	}
	else
	{
		if (tree->left->n > tree->right->n && tree->n < tree->left->n)
		{
			temp = tree->n;
			tree->n = tree->left->n;
			tree->left->n = temp;
			heapify_downward(tree->left);
			return;
		}
		if (tree->left->n < tree->right->n && tree->n < tree->right->n)
		{
			temp = tree->n;
			tree->n = tree->right->n;
			tree->right->n = temp;
			heapify_downward(tree->right);
			return;
		}
	}
}
/**
 * heap_extract - takes out "last" node and updates root
 * basically, removes root of a max binary heap
 * @root: ptr to root
 * Return: value of root
 */
int heap_extract(heap_t **root)
{
	queue_t *queue;
	binary_tree_t *temp;
	int value;

	if (!(*root))
		return (0);
	queue = NULL;
	enqueue(&queue, *root);
	while (queue)
	{
		temp = dequeue(&queue);
		enqueue(&queue, temp->left);
		enqueue(&queue, temp->right);
	}
	if (temp->parent)
	{
		if (temp->parent->left == temp)
			temp->parent->left = NULL;
		else
			temp->parent->right = NULL;
	}
	temp->parent = NULL;
	temp->right = (*root)->right;
	if (temp->right)
		temp->right->parent = temp;
	temp->left = (*root)->left;
	if (temp->left)
		temp->left->parent = temp;
	value = (*root)->n;
	if (*root == temp)
	{
		free(*root); *root = NULL;
	}
	else
	{
		free(*root);
		*root = temp;
		heapify_downward(temp);
	}
	return (value);
}
