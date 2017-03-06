#include "binary_trees.h"
/**
 * child_count - returns 1 for 0/2 children, 0 for 1 child
 * @tree: ptr to binary tree node
 * Return: 0 or 1
 */
int child_count(const binary_tree_t *tree)
{
	if (!tree)
		return (1);
	if ((tree->left && tree->right) || !(tree->left || tree->right))
		return (1);
	return (0);
}
/**
 * binary_tree_preorder - traverse a tree using pre-order
 * @tree: root of binary tree
 * @func: function to apply to each node
 * pre order traversal is visiting the node, then its left subtree
 * then its right subtree
 */
int binary_tree_check(const binary_tree_t *tree,
			  int (*func)(const binary_tree_t *node))
{
	if (tree)
		printf("Value of tree: %d\n Value of func: %d\n", tree->n, func(tree));
	if (tree && func(tree))
	{
		if(!(tree->left || tree->right))
		   return (1);
		return (binary_tree_check(tree->left, func) &&
			binary_tree_check(tree->right, func));
	}
	printf("return 0 in binary_tree_check triggered\n");
	return (0);
}
int binary_tree_is_full(const binary_tree_t *tree)
{
	return (binary_tree_check(tree, child_count));
}
