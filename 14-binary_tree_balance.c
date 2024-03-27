#include "binary_trees.h"
#include <stddef.h>


/**
 * recur_height - a static function to help find the height of a tree
 * @tree: pointer to the tree
 *
 * Return: returns 1 + height of the tree.
*/
static int recur_height(const binary_tree_t *tree)
{
	int height, l_height, r_height;


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
static int binary_tree_h(const binary_tree_t *tree)
{
	if (!tree->left || !tree->right)
		return (1);
	return (recur_height(tree) - 1);
}

/**
 * binary_tree_balance - a function to measure the balance factor of
 * a  binary tree
 * @tree: pointer to the tree.
 * Return: returns the balance factor or 0 if tree is NULL
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	int l_height, r_height;

	if (!tree)
		return (0);

	l_height = tree->left ? binary_tree_h(tree->left) : 0;
	r_height = tree->right ? binary_tree_h(tree->right) : 0;

	return (l_height - r_height);
}
