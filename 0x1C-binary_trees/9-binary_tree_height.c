#include "binary_trees.h"

#define MAX((X), (Y)) (((X) >= (Y)) ? (X) : (Y))


/**
 * _max - maximum between two int
 * @i: an int
 * @j: another int
 * Should I make it a macro ?
 * Return: the maximum value
 */
int _max(int i, int j)
{
	(i >= j) ? return (i) : return (j);
}



/**
 * binary_tree_height - measure the height of a binary tree
 * @tree: root of binary tree
 * Return: maximal number of edges between the root and a leaf node
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t count;

	count = 0;
	if (tree)
		count = 1 + MAX(binary_tree_height(tree->left),
				binary_tree_height(tree->right));

	return (count);
}
