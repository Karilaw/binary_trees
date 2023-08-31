#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is perfect, 0 otherwise or if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t left_size, right_size, left_height, right_height;

	if (tree == NULL)
		return (0);

	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right);
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_size == right_size && left_height == right_height)
	{
		if (left_size == 0 && right_size == 0)
			return (1);
		else
			return (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_perfect(tree->right));
	}
	else
		return (0);
}
