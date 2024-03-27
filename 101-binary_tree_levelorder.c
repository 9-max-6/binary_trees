#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_d -  a function that measures the depth of a
 * node in a binary tree
 * @tree: pointer of the tree to measure the depth
 *
 * Return: returns 0 if tree is null else depth
*/
static size_t binary_tree_d(const binary_tree_t *tree)
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
 * binary_tree_h - a function that measures the height of a binary tree
 * @tree: pointer to the tree that is to be measured.
 *
 * Return: returns 0 if tree is NULL, or just the height of the tree.
*/
size_t binary_tree_h(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (recur_height(tree) - 1);
}
/**
 * binary_tree_inorder -  a function that goes through a
 * binary tree using inorder traversal
 * @func: is a pointer to a function to call for each node
 * @tree: is a pointer to the root node of the tree to traverse
*/
static void binary_tree_i(const binary_tree_t *tree, void (*func)(int),
size_t depth)
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_i(tree->left, func, depth);
	if (binary_tree_d(tree) == depth)
		func(tree->n);
	binary_tree_i(tree->right, func, depth);
}

/**
 * binary_tree_levelorder -  a function that goes through a binary tree
 * using level-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func:  a pointer to a function to call for each node
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, iter;
	const binary_tree_t *temp;

	if (!tree)
		return;
	height = binary_tree_h(tree);
	temp = tree;
	for (iter = 0; iter < height; iter++)
	{
		binary_tree_i((const binary_tree_t *)temp, func, iter);
	}
}
