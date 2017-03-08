#include "binary_trees.h"


/**
 * binary_tree_h - measure the height of a binary tree by nodecount
 * @tree: root of binary tree
 * Return: maximal number of nodes between the root and a leaf node
 */
int binary_tree_h(const binary_tree_t *tree)
{
	int count;

	count = 0;
	if (tree)
		count = 1 + MAX(binary_tree_h(tree->left),
				binary_tree_h(tree->right));
	return (count);
}
/**
 * binary_tree_balance - returns the difference of the maximal node depth on
 * left and maximal node depth on right
 * @tree: ptr to root of tree
 * Return: balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_h(tree->left) -
		binary_tree_h(tree->right));

}
