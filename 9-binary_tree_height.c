#include "binary_trees.h"
#include <stddef.h>

/**
 * recur_height - a static function to help find the height of a tree
 * @tree: pointer to the tree
 *
 * Return: returns 1 + height of the tree.
*/
static size_t recur_height(const binary_tree_t *tree)
{
	size_t height, l_height, r_height;

	if (!tree)
		return (0);

	l_height = recur_height(tree->left);
	r_height = recur_height(tree->right);

	height = l_height > r_height ? l_height : r_height;

	return (1 + height);

}
/**
 * binary_tree_height - a function that measures the height of a binary tree
 * @tree: pointer to the tree that is to be measured.
 *
 * Return: returns 0 if tree is NULL, or just the height of the tree.
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (recur_height(tree) - 1);
}
