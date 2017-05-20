#include "heap.h"

/**
 * set_parent - set parents node right after node2 parent
 * becomes node1's
 * @node1: node who got new parents
 * @node2: node who gives it parent
 */
void set_parent(binary_tree_node_t *node1, binary_tree_node_t *node2)
{
	if (node1->parent)
	{
		if (node1->parent->left == node2)
			node1->parent->left = node1;
		else
			node1->parent->right = node1;
	}
}

/**
 * set_child_parent - set left child node right after node2 left/right child
 * becomes node1's
 * @node1: node who got new left/right child
 */
void set_child_parent(binary_tree_node_t *node1)
{
	if (node1->left)
		(node1->left)->parent = node1;
	if (node1->right)
		(node1->right)->parent = node1;
}

/**
 * swap_node_pointers - swap parents left and right node
 * @child: child node to swap with parent
 * @parent: parent to swap with child
 * Each node keeps its data, other pointers are swapped between
 * parent and child
 */
void swap_node_pointers(binary_tree_node_t *child, binary_tree_node_t *parent)
{
	binary_tree_node_t *tmp;

	child->parent = parent->parent,	parent->parent = child;
	if (child->parent)
	{
		if (child->parent->left == parent)
			child->parent->left = child;
		else
			child->parent->right = child;
	}
	if (parent->left == child)
	{
		tmp = child->left;
		child->left = parent;
		parent->left = tmp;
		if (tmp)
			tmp->parent = parent;
		tmp = child->right;
		child->right = parent->right;
		if (child->right)
			child->right->parent = child;
		parent->right = tmp;
		if (tmp)
			tmp->parent = parent;
	}
	else
	{
		tmp = child->right;
		child->right = parent;
		parent->right = tmp;
		if (tmp)
			tmp->parent = parent;
		tmp = child->left;
		child->left = parent->left;
		if (child->left)
			child->left->parent = child;
		parent->left = tmp;
		if (tmp)
			tmp->parent = parent;
	}
}

/**
 * swap_nodes - swap 2 nodes, values included
 * @node1: node to swap
 * @node2: node to swap
 */
void swap_nodes(binary_tree_node_t *node1, binary_tree_node_t *node2)
{
	binary_tree_node_t *tmp_node, *tmp_node2;

	if (!node1 || !node2)
		return;

	if (node1->parent && node1->parent == node2)
	{
		swap_node_pointers(node1, node2);
	}
	else if (node2->parent && node2->parent == node1)
	{
		swap_node_pointers(node2, node1);
	}
	else
	{
		tmp_node = node1->parent;
		node1->parent = node2->parent;
		set_parent(node1, node2);
		node2->parent = tmp_node;
		set_parent(node2, node1);
		tmp_node = node1->left;
		tmp_node2 = node1->right;
		node1->left = node2->left;
		node1->right = node2->right;
		set_child_parent(node1);
		node2->left = tmp_node;
		node2->right = tmp_node2;
		set_child_parent(node2);
	}
}
