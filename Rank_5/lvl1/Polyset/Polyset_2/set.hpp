#pragma once

#include "searchable_bag.hpp"
#include <cstddef>

class set: public searchable_bag {
	private:
		searchable_bag *_bag;

	public:
		set();
		set(searchable_bag &backend);
		set(const set& other);
		set& operator=(const set& other);
		virtual ~set();

		searchable_bag& get_bag() const;
		virtual bool has(int) const;
		virtual void insert(int value);
		virtual void insert(int* array, int value);
		virtual void print() const;
		virtual void clear();
};