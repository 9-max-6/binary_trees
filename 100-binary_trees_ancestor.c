#include "binary_trees.h"
#include <stddef.h>
#include <stdio.h>

/**
 * binary_tree_d -  a function that measures the depth of a
 * node in a binary tree
 * @tree: pointer of the tree to measure the depth
 *
 * Return: returns 0 if tree is null else depth
*/
static int binary_tree_d(const binary_tree_t *tree)
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
 * binary_trees_ancestor - a function that finds the lowest common
 * ancestor of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 * Return: a pointer to the lowest common ancestor node
 * of two given nodes. else NULL
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	binary_tree_t *ancestor, *first_t, *second_d;
	int dep_dif, iter;

	if (!first || !second)
		return (NULL);
	ancestor = NULL;
	first_t = (binary_tree_t *)first;
	second_d = (binary_tree_t *)second;
	dep_dif = binary_tree_d(first_t) - binary_tree_d(second_d);

	if (dep_dif > 0)
	{
		for (iter = 0; iter < dep_dif; iter++)
		{
			first_t = first_t->parent;
		}
	}

	if (dep_dif < 0)
	{
		dep_dif *= -1;
		for (iter = 0; iter < dep_dif; iter++)
		{
			second_d = second_d->parent;
		}
	}
	while(first_t && second_d)
	{
		if (first_t == second_d)
		{
			ancestor = first_t;
			break;
		}

		first_t = first_t->parent;
		second_d = second_d->parent;
	}
	return (ancestor);
}
