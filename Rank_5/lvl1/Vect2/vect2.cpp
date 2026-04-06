#include "vect2.hpp"

vect2::vect2() : m_x(0), m_y(0) {};

vect2::vect2(int x, int y) : m_x(x), m_y(y) {};

vect2::vect2(const vect2 &other) : m_x(other.m_x), m_y(other.m_y) {};

vect2::~vect2() {};

vect2 vect2::operator+(const vect2 &other) const{
	int x = this.m_x + other.m_x;
	int y = this.m_y + other.m_y;

	return (vect2(x, y));
}

vect2 vect2::operator-(const vect2 &other) const{
	int x = this.m_x - other.m_x;
	int y = this.m_y - other.m_y;

	return (vect2(x, y));
}

vect2 vect2::operator*(const vect2 &other) const{
	int x = this.m_x * other.m_x;
	int y = this.m_y * other.m_y;

	return (vect2(x, y));
}

vect2 vect2::operator-(){
	return (vect2(-this.m_x, -this.m_y));
}
vect2 vect2::operator*(const int num) const {
	int x = this.m_x * num;
	int y = this.m_y * num;

	return (vect2(x, y));
}


