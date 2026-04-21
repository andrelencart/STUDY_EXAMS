#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() {};

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& other): tree_bag(other) {};

searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag& other) {
	if (this != &other)
		tree_bag::operator=(other);
	return *this;
}

searchable_tree_bag::~searchable_tree_bag() {};

bool searchable_tree_bag::search(node *node, const int value) const{
	if (node == NULL)
		return false;
	if (node->value == value)
		return true;
	else if (value < node->value)
		return search(node->l, value);
	else
		return search(node->r, value);
}

bool searchable_tree_bag::has(int value) const {
	return search(tree, value);
}