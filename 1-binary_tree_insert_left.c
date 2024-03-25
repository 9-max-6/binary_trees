#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_left - a function that inserts a node as the
 * left-child of another node
 * 
 * @parent: pointer to the node to insert the left-child in
 * @value:  is the value to store in the new node
 * 
 * Return: Success ? return pointer to the created node : NULL
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    new_node = malloc(sizeof(binary_tree_t));
    if (!new_node)
        return (NULL);
    new_node->n = value;
    if (parent->left == NULL)
    {
        parent->left = new_node;
        new_node->right = NULL;
        new_node->left = NULL;
        return (new_node);
    }

    if (parent->left)
    {
        parent->left->parent = new_node;
        new_node->left = parent->left;
        parent->left = new_node;
        new_node->right = NULL;
    }
    new_node->parent = parent;
    return (new_node);

}