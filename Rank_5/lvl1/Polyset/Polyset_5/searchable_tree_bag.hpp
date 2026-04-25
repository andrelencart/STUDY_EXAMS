#pragma once

#include "searchable_bag.hpp"
#include "tree_bag.hpp"
#include <cstddef>

class searchable_tree_bag: public tree_bag, public searchable_bag {
	private:
		bool search(node *node, int num) const;
	
	public:
		searchable_tree_bag();
		searchable_tree_bag(const searchable_tree_bag& other);
		searchable_tree_bag& operator=(const searchable_tree_bag& other);
		bool has(int) const;
		~searchable_tree_bag();
};