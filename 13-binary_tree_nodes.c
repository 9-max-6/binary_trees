#include "binary_trees.h"

/**
 * binary_tree_nodes - a function to count the nodes in a binary tree
 * @tree: pointer to the tree.
 * Return: returns the number of leaves in the tree.
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree || (!tree->left && !tree->right))
		return (0);

	return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));

}
