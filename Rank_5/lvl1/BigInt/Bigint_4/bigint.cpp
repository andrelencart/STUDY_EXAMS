#include "bigint.hpp"

bigint::bigint(): _digits("0") {};

bigint::bigint(unsigned long long n) {
	if (n == 0){
		_digits = '0';
		return ;	
	}
	_digits = "";
	while (n > 0){
		_digits = char('0' + n % 10) + _digits;
		n /= 10;
	}

}

bigint::bigint(const bigint& other): _digits(other._digits) {};

bigint& bigint::operator=(const bigint& other) {
	if (this != &other)
		_digits = other._digits;
	return *this;
}

bigint::~bigint() {};

size_t bigint::toSizeT() const {
	size_t result = 0;
	for (size_t i = 0; i < _digits.size(); i++)
		result = result * 10 + (_digits[i] - '0');
	return result;
};

bigint bigint::operator+(const bigint& other) const {
	bigint result;
	result._digits = "";
	int carry = 0;
	int i = _digits.size() - 1;
	int j = other._digits.size() - 1;
	while (i >= 0 || j >= 0 || carry){
		int sum = carry;
		if (i >= 0)
			sum += _digits[i--] - '0';
		if (j >= 0)
			sum += other._digits[j--] - '0';
		carry = sum / 10;
		result._digits = char('0' + sum % 10) + result._digits;
	}
	if (result._digits.empty())
		result._digits = "0";
	return result;
}

bigint& bigint::operator+=(const bigint& other) {
	*this = *this + other;
	return *this;
}

bigint& bigint::operator++() {
	*this += bigint(1);
	return *this;
}

bigint bigint::operator++(int) {
	bigint tmp = *this;
	++(*this);
	return tmp;
}

bigint bigint::operator<<(const bigint& other) const {
	if (_digits == "0")
		return *this;
	size_t n = other.toSizeT();
	bigint result(*this);
	result._digits.append(n, '0');
	return result;
}

bigint bigint::operator>>(const bigint& other) const {
	size_t n = other.toSizeT();
	if (n >= _digits.size())
		return bigint(0);
	bigint result;
	result._digits = _digits.substr(0, _digits.size() - n);
	if (result._digits.empty())
		result._digits = "0";
	return result;
}

bigint& bigint::operator<<=(const bigint& other) {
	*this = *this << other;
	return *this;
}

bigint& bigint::operator>>=(const bigint& other) {
	*this = *this >> other;
	return *this;
}

bool bigint::operator<(const bigint& other) const {
	if (_digits.size() != other._digits.size())
		return _digits.size() < other._digits.size();
	return _digits < other._digits;
}

bool bigint::operator>(const bigint& other) const {
	return other < *this;
}

bool bigint::operator<=(const bigint& other) const {
	return !(other < *this);
}

bool bigint::operator>=(const bigint& other) const {
	return !(*this < other);
}

bool bigint::operator==(const bigint& other) const {
	return _digits == other._digits;
}

bool bigint::operator!=(const bigint& other) const {
	return !(*this == other);
}

std::ostream& operator<<(std::ostream &os, const bigint &b) {
	os << b._digits;
	return os;
}


