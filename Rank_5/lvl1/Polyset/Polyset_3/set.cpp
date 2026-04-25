#include "set.hpp"

set::set(): _bag(0) {};

set::set(searchable_bag& backend): _bag(&backend) {};

set::set(const set& other): _bag(other._bag) {};

set& set::operator=(const set& other) {
	if (this != &other)
		this->_bag = other._bag;
	return *this;
}

set::~set() {};

searchable_bag& set::get_bag() const {
	return *this->_bag;
}

bool set::has(int num) const {
	if (this->_bag == 0)
		return false;
	return this->_bag->has(num);
}

void set::insert(int num) {
	if (this->_bag == 0)
		return ;
	if (!this->_bag->has(num))
		this->_bag->insert(num);
}

void set::insert(int *array, int num) {
	if (this->_bag == 0 || num <= 0 || array == 0)
		return ;
	for (int i = 0; i < num; i++)
		this->insert(array[i]);
}

void set::print() const {
	if (this->_bag == 0)
		return ;
	this->_bag->print();
}

void set::clear() {
	if (this->_bag == 0)
		return ;
	this->_bag->clear();
}