#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
public:
	Fixed();
	Fixed(int const value);
	Fixed(float const value);
	Fixed(const Fixed &src);
	~Fixed();
	Fixed &operator=(Fixed const &rhs);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

private:
	int fixedValue;
	static const int bitsValue = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif