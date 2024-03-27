#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_depth -  a function that measures the depth of a
 * node in a binary tree
 * @tree: pointer of the tree to measure the depth
 *
 * Return: returns 0 if tree is null else depth
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;

	if (!tree)
		return (0);
	depth = 0;

	while (tree)
	{
		depth += 1;
		tree = tree->parent;
	}
	return (depth - 1);
}
