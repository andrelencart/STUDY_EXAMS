#pragma once

#include <iostream>

class vect2 {
	private:
		int mx;
		int my;

	public:
		vect2();
		vect2(int x, int y);
		vect2(const vect2& other);
		~vect2();

		vect2 operator+(const vect2& other) const;
		vect2 operator-(const vect2& other)const;
		vect2 operator-()const;
		vect2 operator*(const vect2& other) const;
		vect2 operator*(const int scalar) const;

		vect2& operator++();
		vect2 operator++(int);
		vect2& operator--();
		vect2 operator--(int);

		vect2& operator=(const vect2& other);
		vect2& operator+=(const vect2& other);
		vect2& operator-=(const vect2& other);
		vect2& operator*=(const vect2& other);
		vect2& operator*=(const int scalar);

		bool operator==(const vect2& other) const;
		bool operator!=(const vect2& other) const;

		int &operator[](int i);
		const int &operator[](int i) const;
};
std::ostream& operator<<(std::ostream &os, const vect2& v);
vect2 operator*(const int scalar, const vect2& v);