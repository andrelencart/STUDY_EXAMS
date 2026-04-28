#ifndef BIGINT_HPP
# define BIGINT_HPP

# include <string>
# include <iostream>

class bigint {
private:
	std::string	_digits;
	size_t		toSizeT() const;

public:
	bigint();
	bigint(unsigned long long n);
	bigint(const bigint& other);
	~bigint();
	bigint&	operator=(const bigint& other);

	bigint	operator+(const bigint& rhs) const;
	bigint&	operator+=(const bigint& rhs);
	bigint&	operator++();
	bigint	operator++(int);

	bigint	operator<<(const bigint& shift) const;
	bigint&	operator<<=(const bigint& shift);
	bigint	operator>>(const bigint& shift) const;
	bigint&	operator>>=(const bigint& shift);

	bool	operator<(const bigint& rhs) const;
	bool	operator<=(const bigint& rhs) const;
	bool	operator>(const bigint& rhs) const;
	bool	operator>=(const bigint& rhs) const;
	bool	operator==(const bigint& rhs) const;
	bool	operator!=(const bigint& rhs) const;

	friend std::ostream&	operator<<(std::ostream& os, const bigint& b);
};

#endif
