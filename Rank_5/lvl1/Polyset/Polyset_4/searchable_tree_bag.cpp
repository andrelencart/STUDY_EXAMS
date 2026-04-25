#include "searchable_tree_bag.hpp"

#include <cstddef>

searchable_tree_bag::searchable_tree_bag() {};

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& other): tree_bag(other) {};

searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag& other) {
	if (this != &other)
		tree_bag::operator=(other);
	return *this;
}

searchable_tree_bag::~searchable_tree_bag() {};

bool searchable_tree_bag::search(node *node, const int num) const {
	if (node == NULL)
		return false;
	if (node->value == num)
		return true;
	else if (num < node->value)
		return search(node->l, num);
	else
		return search(node->r, num);
}

bool searchable_tree_bag::has(int value) const {
	return search(tree, value);
}