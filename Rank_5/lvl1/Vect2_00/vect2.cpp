#include "vect2.hpp"

vect2::vect2() : m_x(0), m_y(0) {};

vect2::vect2(int x, int y) : m_x(x), m_y(y) {};

vect2::vect2(const vect2 &other) : m_x(other.m_x), m_y(other.m_y) {};

vect2::~vect2() {};

vect2 vect2::operator+(const vect2 &other) const{
	int x = this->m_x + other.m_x;
	int y = this->m_y + other.m_y;

	return (vect2(x, y));
}

vect2 vect2::operator-(const vect2 &other) const{
	int x = this->m_x - other.m_x;
	int y = this->m_y - other.m_y;

	return (vect2(x, y));
}

vect2 vect2::operator*(const vect2 &other) const{
	int x = this->m_x * other.m_x;
	int y = this->m_y * other.m_y;

	return (vect2(x, y));
}

vect2 vect2::operator-() const{
	return (vect2(-this->m_x, -this->m_y));
}
vect2 vect2::operator*(const int num) const {
	int x = this->m_x * num;
	int y = this->m_y * num;

	return (vect2(x, y));
}

vect2 &vect2::operator++() {
	this->m_x++;
	this->m_y++;
	return *this;
}

vect2 vect2::operator++(int) {
	vect2 old(*this);
	++(*this);
	return old;
}

vect2 &vect2::operator--() {
	this->m_x--;
	this->m_y--;
	return *this;
}

vect2 vect2::operator--(int) {
	vect2 old(*this);
	--(*this);
	return old;
}

vect2 &vect2::operator=(const vect2 &other){
	if(this == &other)
		return *this;
	this->m_x = other.m_x;
	this->m_y = other.m_y;
	return *this;
}

vect2 &vect2::operator+=(const vect2 &other){
	if(this == &other)
		return *this;
	this->m_x += other.m_x;
	this->m_y += other.m_y;
	return *this;
}

vect2 &vect2::operator-=(const vect2 &other){
	if(this == &other)
		return *this;
	this->m_x -= other.m_x;
	this->m_y -= other.m_y;
	return *this;
}

vect2 &vect2::operator*=(const vect2 &other){
	if(this == &other)
		return *this;
	this->m_x *= other.m_x;
	this->m_y *= other.m_y;
	return *this;
}

vect2 &vect2::operator*=(const int num){
	this->m_x *= num;
	this->m_y *= num;
	return *this;
}

bool vect2::operator==(const vect2 &other) const{
	if (m_x == other.m_x && m_y == other.m_y)
		return true;
	return false;
}

bool vect2::operator!=(const vect2 &other) const{
	if (m_x != other.m_x || m_y != other.m_y)
		return true;
	return false;
}

int &vect2::operator[](int i){
	if (i == 0)
		return this->m_x;
	return this->m_y;
}

const int &vect2::operator[](int i) const{
	if (i == 0)
		return this->m_x;
	return this->m_y;
}

vect2 operator*(const int scalar, const vect2 &v){
	return (v * scalar);
}

std::ostream &operator<<(std::ostream &os, const vect2 &v){
	os << "{" << v[0] << ", " << v[1] << "}";
	return os;
}