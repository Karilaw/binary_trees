#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor
 * or NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	const binary_tree_t *second)
{
	binary_tree_t *f, *s;

	if (first == NULL || second == NULL)
		return (NULL);

	f = (binary_tree_t *)first;
	s = (binary_tree_t *)second;

	while (f != NULL)
	{
		while (s != NULL)
		{
			if (f == s)
				return (f);
			s = s->parent;
		}
		f = f->parent;
		s = (binary_tree_t *)second;
	}

	return (NULL);
}
