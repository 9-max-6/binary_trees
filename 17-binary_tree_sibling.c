#include "binary_trees.h"

/**
 * binary_tree_sibling - a function that finds the sibling of a node.
 * @node: pointer to the node to find the sibling.
 *
 * Return: returns a pointer to the sibiling of the given node. or NULL
*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	else
		return (node->parent->left);
}
