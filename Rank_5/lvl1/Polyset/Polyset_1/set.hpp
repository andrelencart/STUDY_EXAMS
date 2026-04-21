#pragma once

#include "searchable_bag.hpp"

class set: public searchable_bag {
	private:
		searchable_bag *_bag;

	public:
		set();
		set(const set& other);
		set(searchable_bag &backend);
		set& operator=(const set& other);
		virtual ~set();

		searchable_bag& get_bag() const;
		virtual bool has(int) const;
		virtual void insert(int num);
		virtual void insert(int *array, int num);
		virtual void print() const;
		virtual void clear();
};