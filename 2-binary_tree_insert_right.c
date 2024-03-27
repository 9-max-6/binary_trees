#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_right - a function that inserts a node as the
 * right-child of another node
 *
 * @parent: pointer to the node to insert the left-child in
 * @value:  is the value to store in the new node
 *
 * Return: Success ? return pointer to the created node : NULL
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (!parent)
		return (NULL);
	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	if (parent->right)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}
	parent->right = new_node;

	return (new_node);
}
