#include "binary_trees.h"

/**
 * l_pow - a function to raise a number to a power
 * @a: the base
 * @b: the exponent
 * Return: returns the number raised to said power
*/
static int l_pow(int a, int b)
{
	int c, i;

	if (a == 0)
		return (0);
	if (b == 0)
		return (1);
	if (b == 1)
		return (a);
	c = 1;

	for (i = 0; i < b; i++)
		c *= a;
	return (c);
}

/**
 * recur_height - a static function to help find the height of a tree
 * @tree: pointer to the tree
 *
 * Return: returns height of the tree.
 */
static int recur_height(const binary_tree_t *tree)
{
	int l_height, r_height;

	if (!tree)
		return (0);

	l_height = recur_height(tree->left);
	r_height = recur_height(tree->right);

	return (1 + (l_height > r_height ? l_height : r_height));
}

/**
 * binary_tree_s - a function that measures the size of a binary tree
 * @tree: pointer to the tree that is to be measured.
 *
 * Return: returns 0 if tree is NULL, or the size of the tree.
 */
static size_t binary_tree_s(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_s(tree->left) + binary_tree_s(tree->right));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if the tree is perfect, 0 otherwise or if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	int height = recur_height(tree);
	int size = binary_tree_s(tree);

	return (size == (l_pow(2, height) - 1));
}
