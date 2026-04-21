#pragma once

# include "tree_bag.hpp"
# include "searchable_bag.hpp"

class searchable_tree_bag: public tree_bag, public searchable_bag {
	private:
		bool search(node *node, const int value) const;

	public:
		searchable_tree_bag();
		searchable_tree_bag(const searchable_tree_bag& other);
		searchable_tree_bag& operator=(const searchable_tree_bag& other);
		bool has(int) const;
		~searchable_tree_bag();

};