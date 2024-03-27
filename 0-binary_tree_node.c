#include "binary_trees.h"
#include <stdlib.h>
/**
 * *binary_tree_node - a function to create a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: the actual value of the node.
 *
 * Return: Success ? pointer to the new node : Null
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
	{
		return (NULL);
	}
	new_node->parent = parent;
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
