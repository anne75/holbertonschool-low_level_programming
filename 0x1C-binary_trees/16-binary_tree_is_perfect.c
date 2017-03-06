#include "binary_trees.h"
#define MAX(X, Y) ((X) >= (Y) ? (X) : (Y))
/**
 * binary_tree_size - measure the size of a binary tree
 * @tree: root of the tree
 * Return: number of nodes in the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t count;

	count = 0;
	if (tree)
		count = 1 + binary_tree_size(tree->left)
			+ binary_tree_size(tree->right);

	return (count);
}
/**
 * binary_tree_is_leaf - check if a node is a leaf
 * @node: a binary tree node
 * Return: 1 for True, 0 for False
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);
	if (node->left || node->right)
		return (0);
	return (1);
}
/**
 * binary_tree_leaves - counts leaves in a binary-tree
 * @tree: pointer to root of binary tree
 * Return: leaf count
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count;

	count = 0;
	if (binary_tree_is_leaf(tree))
	{
		count = 1;
	}
	else if (tree)
	{
		count = binary_tree_leaves(tree->right)
			+ binary_tree_leaves(tree->left);
	}
	return (count);
}
/**
 * binary_tree_is_perfect - "perfect" basically means full and symmetric
 * and the nodecount of each level of the tree will be a power of 2
 * we compare our total nodes to the nodecount of a perfect tree of that height
 * @tree: ptr to binary tree node
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if ((2 * binary_tree_leaves(tree)) - 1 == binary_tree_size(tree))
		    return (1);
	return (0);
}
