#include "binary_trees.h"

/**
 * simple_insert - inserts a node into a bst so that it remains a bst
 * @tree: double ptr to root of tree
 * @value: int value at node
 * Return: ptr to the new node in the tree
 */
avl_t *simple_insert(avl_t **tree, int value)
{

	binary_tree_t *temp, *parent, *new;

	if (!tree)
		return (NULL);
	if (!(*tree))
	{
		*tree = binary_tree_node(*tree, value);
		return (*tree);
	}
	temp = (*tree);
	while (temp)
	{
		parent = temp;
		if (value > temp->n)
			temp = temp->right;
		else if (value < temp->n)
			temp = temp->left;
		else
			return (NULL);
	}
	new = binary_tree_node(parent, value);
	if (parent->n < value)
		parent->right = new;
	if (parent->n > value)
		parent->left = new;
	return (new);
}

/**
 * re_balance - re balances the tree to keep its AVL property
 * @tree: pointer to the root of the subtree to consider
 * Return: pointer to the new root
 */
avl_t *re_balance(avl_t *tree)
{
	int balance;

	if (!tree)
		return NULL;
	balance = binary_tree_balance((const binary_tree_t *)tree);
	printf("DEBUG balance %d and node value %d\n", balance, tree->n);
	if (balance > 1) /*left leaning tree*/
	{
		if (binary_tree_balance((const avl_t*)tree->left) <= -1)
			tree->left = binary_tree_rotate_left(tree->left);
		tree = binary_tree_rotate_right(tree);
	}
	else if (balance < -1) /*right leaning tree*/
	{
		if (binary_tree_balance((const avl_t*)tree->right) >= 1)
			tree->right = binary_tree_rotate_right(tree->right);
		tree = binary_tree_rotate_left(tree);
	}
/*	printf("return value of re_balance %d\n", tree->n);*/
	return (tree);
}

/**
 * avl_insert - insert a new value in an AVL node
 * @tree: pointer to the root of the tree
 * @value: value to insert
 * Return: pointer to the created node or NULL
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new, *tmp;
	int count;

	new = simple_insert(tree, value);
	if (!new)
		return (NULL);

	tmp = new;
	count = 0;
	while (new->parent && count < 8)
	{
		new = re_balance(new);
/*		printf("return from balance is node %d with parent %d\n", new->n, new->parent->n);*/
		new = new->parent;
		++count;
	}
/* at this point new is pointing to the root */
	*tree = re_balance(new);

	return(tmp);
}
