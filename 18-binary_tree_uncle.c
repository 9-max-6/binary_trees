#include "binary_trees.h"

/**
 * binary_tree_uncle - a function to find the uncle of a node
 * @node: the node
 *
 * Return: returns the pointer to the uncle or Null
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node)
	{
		if (node->parent)
		{
			if (node->parent->parent)
			{
				if (node->parent->parent->left == node->parent)
					return (node->parent->parent->right);
				else
					return (node->parent->parent->left);
			}
		}
	}
	return (NULL);
}
