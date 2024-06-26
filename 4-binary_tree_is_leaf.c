#include "binary_trees.h"

/**
 * binary_tree_is_leaf -  a function to check if a node is a leaf
 * @node: pointer to the node to check
 *
 * Return: Leaf ? 1 : 0
*/
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
	{
		return (0);
	}
	if (node->left == NULL && node->right == NULL)
	{
		return (1);
	}
	else
		return (0);
}
