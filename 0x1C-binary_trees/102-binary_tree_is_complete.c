#include "binary_trees.h"

/* a complete tree of size h is a full tree at size h -1
 * idea is to verify that
 * I don't think left and right recursion could work bc of
 *       _____ #____
 *  ___#         __#__
 * #             #    #
 *left and right are complete but not the whole tree
 *
 * algo is
 * - traverse tree by level
 * - keep count of nodes and when we stop having a continuum of children
 * - problem: when do we know we start a new level ?
 */


/**
 * binary_tree_height - measure the height of a binary tree
 * @tree: root of binary tree
 * Return: maximal number of edges between the root and a leaf node
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree && (tree->left || tree->right))
		return (1 + MAX(binary_tree_height(tree->left),
				binary_tree_height(tree->right)));

	return (0);
}

/**
 * binary_tree_is_complete - check if binary tree is complete
 * @tree: root of binary tree
 * a tree is comple when all its levels save the last are full
 * and on the last level all leaves nodes are as left as possible
 * Return: 1 id True, 0 if False
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t h, count, i;
	binary_tree_t *tmp; /*workaround for const*/

	if (!tree)
		return (0);
	h = binary_tree_height(tree);
	if (h == 0)
		return (1);

}
