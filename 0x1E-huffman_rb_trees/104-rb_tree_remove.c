#include "rb_trees.h"

/**
 * set_parent - set the parent of the node to remove right
 * @node: node to remove
 * @swap: node to swap it with
 */
void set_parent(bst_t *node, bst_t *swap)
{
	if (!node)
		return;
	if (node->parent)
	{
		if ((node->parent)->left == node)
			(node->parent)->left = swap;
		else
			(node->parent)->right = swap;
	}
}

/**
 * rb_tree_rotate_left - left-rotates a rb tree
 * @tree: ptr to root of tree
 * Return: ptr to new root of tree
 */
rb_tree_t *rb_tree_rotate_left(rb_tree_t *tree)
{
	rb_tree_t *temp;

	if (!tree)
		return (NULL);
	temp = tree->right;
	if (!temp)
		return (tree);
	tree->right = (temp)->left;
	if (temp->left)
		temp->left->parent = tree;
	temp->parent = tree->parent;
	if (tree->parent)
	{
		if (tree == tree->parent->left)
			tree->parent->left = temp;
		else
			tree->parent->right = temp;
	}
	temp->left = tree;
	tree->parent = temp;
	return (temp);
}


/**
 * rb_tree_rotate_right - rotate a node to the right
 * @node: pointer to a node in a rb tree
 * Return: pointer to the new parent
 */
rb_tree_t *rb_tree_rotate_right(rb_tree_t *node)
{
	rb_tree_t *tmp;

	if (!node)
		return (NULL);

	tmp = node->left;

	if (!tmp)
		return (node);

	node->left = tmp->right;
	if (node->left)
		(node->left)->parent = node;

	tmp->right = node;
	tmp->parent = node->parent;
	if (tmp->parent)
	{
		if ((tmp->parent)->left == node)
			(tmp->parent)->left = tmp;
		else
			(tmp->parent)->right = tmp;
	}
	node->parent = tmp;

	return (tmp);
}


/**
 * delete_min - delete the minimum node in a rb search tree
 * @tree: pointer to root
 * Return: the minimum node
 */
bst_t *delete_min(bst_t *tree)
{

	if (!tree)
		return (NULL);
	while (tree->left)
		tree = tree->left;
	if (tree->right)
		(tree->right)->parent = tree->parent;
	if (tree->parent)
	{
		if ((tree->parent)->left == tree)
			(tree->parent)->left = tree->right;
		else
			(tree->parent)->right = tree->right;
	}
	return (tree);
}

/**
 * re_bst - make the tree a valid red black tree after deletion
 * @root: root of the tree
 * @removed: removed node
 * Return: the root of the tree
 */
rb_tree_t *re_bst(rb_tree_t *root, rb_tree_t *removed)
{
	rb_tree_t *child, *parent, *sibling;

	if (!root || !removed)
		return (removed);
	if (removed->color == RED)
	{
		set_parent(removed, NULL), free(removed);
		return (root);
	}
	/*removed->color == BLACK*/
	child = (removed->left == NULL) ? removed->right : removed->left;
	if (child && child->color == RED)
	{
		removed->n = child->n, set_parent(child, NULL);
		free(child);
		return (root);
	}
	to_free = removed, removed->color = DOUBLE_BLACK;
	/*removed has 2 NULL children, NULL children are black*/
	while (removed->parent && removed->color == DOUBLE_BLACK)
	{
		parent = removed->parent;
		if (parent->left == removed)
		{
			sibling = parent->right;
			if (sibling && sibling->color == BLACK)
			{
				if (!sibling->right &&
				    sibling->left && sibling->left->color == RED)
					parent->right = rotate_right(sibling);
				if (sibling->right && sibling->right->color == RED)
				{
					if (!parent->parent)
						root = rotate_left(parent);
					else
					{
						set_parent(parent, rotate_left(parent));
					}
					removed->color = BLACK;
				}
				else
				{
					sibling->color = RED;
					parent->color = DOUBLE_BLACK;
					removed = parent;
				}
			}
			else if (sibling && sibling->color == RED)
			{
				if (!parent->parent)
					root = rotate_left(parent);
				else
				{
					set_parent(parent, rotate_left(parent));
				}
				removed->color = BLACK;
			}
		}
		else
		{
			sibing = parent->left;
			if (sibling && sibling->color == BLACK)
			{
				if (!sibling->left &&
				    sibling->right && sibling->right->color == RED)
					parent->right = rotate_left(sibling);
				if (sibling->left && sibling->left->color = RED)
				{
					if (!parent->parent)
						root = rotate_right(parent);
					else
					{
						set_parent(parent, rotate_right(parent));
					}
					removed->color = BLACK;
				}
				else
				{
					sibling->color = RED;
					parent->color = DOUBLE_BLACK;
					removed = parent;
				}
			}
		}
		
		




/**
 * rb_tree_remove - remove a node from a rb bst
 * @root: root of the tree
 * @value: value to remove
 * Return: root of the tree
 */
rb_tree_t *rb_tree_remove(rb_tree_t *root, int n)
{
	rb_tree_t *tmp, *removed;

	if (!root)
		return (NULL);
	tmp = root;
	while (tmp)
	{
		if (tmp->n < value)
			tmp = tmp->right;
		else if (tmp->n > value)
			tmp = tmp->left;
		else
			break;
	}
	if (!tmp)
		return (NULL);
	if ((tmp->right) && (tmp->left))
	{
		removed = delete_min(tmp->right);
		tmp->n = removed->n;
		root = re_bst(root, removed);
	}
	else
	{
		root = re_bst(root, tmp);
	}
	return (root);
}
