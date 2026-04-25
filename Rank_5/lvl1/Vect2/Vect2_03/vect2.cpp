#include "vect2.hpp"

vect2::vect2(): mx(0), my(0) {};

vect2::vect2(int x, int y): mx(x), my(y) {};

vect2::vect2(const vect2& other): mx(other.mx), my(other.my) {};

vect2::~vect2() {};

vect2 vect2::operator+(const vect2& other) const {
	vect2 temp;
	temp.mx = this->mx + other.mx;
	temp.my = this->my + other.my;

	return temp;
}

vect2 vect2::operator-(const vect2& other) const {
	vect2 temp;
	temp.mx = this->mx - other.mx;
	temp.my = this->my - other.my;

	return temp;
}

vect2 vect2::operator-() const {
	vect2 temp;
	temp.mx = -this->mx;
	temp.my = -this->my;

	return temp;
}

vect2 vect2::operator*(const vect2& other) const {
	vect2 temp;
	temp.mx = this->mx * other.mx;
	temp.my = this->my * other.my;

	return temp;
}

vect2 vect2::operator*(const int scalar) const {
	vect2 temp;
	temp.mx = this->mx * scalar;
	temp.my = this->my * scalar;

	return temp;
}

vect2& vect2::operator++() {
	this->mx++;
	this->my++;

	return *this;
}

vect2 vect2::operator++(int) {
	vect2 temp = *this;
	++this->mx;
	++this->my;

	return temp;
}

vect2& vect2::operator--() {
	this->mx--;
	this->my--;

	return *this;
}

vect2 vect2::operator--(int) {
	vect2 temp = *this;
	--this->mx;
	--this->my;

	return temp;
}

vect2& vect2::operator=(const vect2& other) {
	if (this != &other){
		this->mx = other.mx;
		this->my = other.my;
	}
	return *this;
}

vect2& vect2::operator+=(const vect2& other) {
		this->mx += other.mx;
		this->my += other.my;
	return *this;
}

vect2& vect2::operator-=(const vect2& other) {
		this->mx -= other.mx;
		this->my -= other.my;
	return *this;
}

vect2& vect2::operator*=(const vect2& other) {
		this->mx *= other.mx;
		this->my *= other.my;
	return *this;
}

vect2& vect2::operator*=(const int scalar) {
		this->mx *= scalar;
		this->my *= scalar;
	return *this;
}

bool vect2::operator==(const vect2& other) const {
	if (this->mx == other.mx && this->my == other.my)
		return true;
	return false;
}

bool vect2::operator!=(const vect2& other) const {
	if (this->mx != other.mx || this->my != other.my)
		return true;
	return false;
}

int &vect2::operator[](int i){
	if (i == 0)
		return this->mx;
	return this->my;
}

const int &vect2::operator[](int i) const{
	if (i == 0)
		return this->mx;
	return this->my;
}

vect2 operator*(const int scalar, const vect2& v) {
	return (v * scalar);
}

std::ostream& operator<<(std::ostream &os, const vect2& v) {
	os << "{" << v[0] << ", " << v[1] << "}";
	return os;
}
