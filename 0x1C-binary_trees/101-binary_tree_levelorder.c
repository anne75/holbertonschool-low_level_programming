/**
 * binary_tree_levelorder - will traverse a binary tree in level order
 * once I get it together after a good night's sleep
 * @tree: ptr to node of binary tree
 * @func: pointer to Alex's function
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t **queue;
	binary_tree_t *temp;

	if (!tree)
		return;
	queue = create_queue();
	enqueue(queue, head, tree);
	temp = tree;
	while(temp)
	{
		func(temp->n);
		if (temp->left)
			enqueue(queue, tail, temp->left);
		if (temp->right)
			enqueue(queue, tail, temp->right);
		temp = dequeue(queue, head, temp);
	}
}
