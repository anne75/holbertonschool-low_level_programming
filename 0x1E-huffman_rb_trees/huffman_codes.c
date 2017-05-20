#include "huffman.h"

/**
 * print_binary - print a char in binary format
 * @data: the data that was encoded
 * @c: a char, the code
 */
void print_binary(char data, char c)
{
	char array[9] = {'\0'};
	int i, j, tmp;

	i = 0;
	if (c == 0)
	{
		printf("%c: 0\n", data);
	}
	else
	{
		while (c > 0)
		{
			array[i++] = ((c & 1) == 0) ? '0' : '1';
			c = (c >> 1);
		}
		/*reverse the array*/
		--i;
		for (j = 0; j < i / 2; ++j)
		{
			tmp = array[j];
			array[j] = array[i - j];
			array[i - j] = tmp;
		}
		printf("%c: %s\n", data, array);
	}
}


/**
 * make_codes - build codes from a Huffman tree
 * @tree: a Huffman binary tree
 * @building_char: char used to create the code
 * Return: 1 on success 0 on failure
 */
int make_codes(binary_tree_node_t *tree, char building_char)
{
	char code, data;

	if (tree->left)
	{
		code = building_char << 1;
		make_codes(tree->left, code);
	}
	if (tree->right)
	{
		code = (building_char << 1) | 1;
		make_codes(tree->right, code);
	}
	if (!(tree->right || tree->right))
	{
		/*get leaf node symbol data*/
		if (tree->data)
			data = ((symbol_t *)tree->data)->data;
		else
			return (0);
		print_binary(data, building_char);
	}
	return (1);
}


/**
 * huffman_codes - build a huffman tree and print the codes
 * @data: data to compress
 * @freq: frequency of each data point
 * @size: size of data and frequency arrays
 * Return: 1 on success otherwise 0
 */
int huffman_codes(char *data, size_t *freq, size_t size)
{
	binary_tree_node_t *tree;
	char c;
	int ret;

	c = '\0';
	if (!data || !freq || size <= 0)
		return (0);
	tree = huffman_tree(data, freq, size);
	if (!tree)
		return (0);
	ret = make_codes(tree, c);
/*free binary tree*/
	free_data(tree);
	return (ret);
}
