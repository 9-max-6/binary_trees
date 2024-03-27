#include "binary_trees.h"
#include <stdbool.h>

/**
 * binary_tree_s - a function to determine the size of a binary tree.
 * @tree: pointer to the tree
 * Return: returns the height of the tree or 0
*/
static int binary_tree_s(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_s(tree->left) + binary_tree_s(tree->right));

}

/**
 * is_complete - a function to recur in determining completeness of a tree
 * @root: root node of the tree
 * @total_nodes: the size of the tree
 * @index: the current index in the recursive instance
 *
 * Return: returns true is the tree is complete and false otherwise
*/
static bool is_complete(const binary_tree_t *root,
int index, int total_nodes) {
    if (root == NULL)
        return true;

    if (index >= total_nodes)
        return false;

    return is_complete(root->left, 2 * index + 1, total_nodes) &&
           is_complete(root->right, 2 * index + 2, total_nodes);
}
/**
 * binary_tree_is_complete - a function that checks if a binary tree
 * is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: returns 0 if it is not complete.
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
    int index, total_nodes;
    if (!tree)
        return (0);
    index = 0;
    total_nodes = binary_tree_s(tree);
    if (is_complete(tree, index, total_nodes))
        return (1);
    else
        return (0);
}