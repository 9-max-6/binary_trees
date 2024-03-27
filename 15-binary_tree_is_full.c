#include "binary_trees.h"

/**
 * binary_tree_is_full - a function that checks if binary tree is full
 * @tree: the pointer to the root of the tree
 *
 * Return: full ? 1 : 0
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);

	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	return (0);
}
