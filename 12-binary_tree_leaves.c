#include "binary_trees.h"

/**
 * binary_tree_leaves - a function to counts the leaves in  binary tree
 * @tree: pointer to the tree.
 * Return: returns the number of leaves in the tree.
*/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
