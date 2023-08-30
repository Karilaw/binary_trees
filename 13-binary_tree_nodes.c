#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes
 * @tree: pointer to the root node of the tree
 *
 * Return: number of nodes with at least 1 child
 * or 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (0);
	return (binary_tree_nodes(tree->left) + 1 + binary_tree_nodes(tree->right));
}
