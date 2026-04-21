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

bool set::has(int value) const {
	if (this->_bag == 0)
		return false;
	return this->_bag->has(value);
}

void set::insert(int value) {
	if (this->_bag == 0)
		return ;
	if (!this->_bag->has(value))
		this->_bag->insert(value);
}

void set::insert(int *array, int value) {
	if (this->_bag == 0 || value <= 0 || array == 0)
		return ;
	
	for (int i = 0; i < value; i++)
		this->insert(array[i]);  // Why not this->_bag->insert(array[i])
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