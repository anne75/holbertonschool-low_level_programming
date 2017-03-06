#include "binary_trees.h"

/**
 * binary_tree_postorder - traverse a tree using pre-order
 * @tree: root of binary tree
 * @func: function to apply to each node
 * pre order traversal is visiting the node left subtree
 * then its right subtree then the node
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree)
	{
		binary_tree_preorder(tree->left);
		binary_tree_preorder(tree->right);
		func(tree->n);
	}
}
