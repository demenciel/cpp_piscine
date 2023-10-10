#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed()
{
	this->fixedValue = 0;
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed::Fixed(const int value)
{
	this->fixedValue = value << bitsValue;
}

Fixed::Fixed(const float value)
{
	this->fixedValue = std::round(value * (1 << bitsValue));
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed()
{
	/* std::cout << "Destructor called" << std::endl; */
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &Fixed::operator=(Fixed const &rhs)
{
	setRawBits(rhs.getRawBits());
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

/*
** --------------------------------- MEMBER FUNCTIONS ---------------------------------
*/

int Fixed::getRawBits(void) const
{
	return this->fixedValue;
};

void Fixed::setRawBits(int const raw)
{
	this->fixedValue = raw;
};

float Fixed::toFloat(void) const
{
	return (float)this->fixedValue / (1 << bitsValue);
}

int Fixed::toInt(void) const
{
	return this->fixedValue >> bitsValue;
}

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
    if (fixed1.getRawBits() < fixed2.getRawBits())
        return fixed1;
    else
        return fixed2;
}

Fixed const &Fixed::min(Fixed const &fixed1, Fixed const &fixed2)
{
    if (fixed1.getRawBits() < fixed2.getRawBits())
        return fixed1;
    else
        return fixed2;
}

Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
    if (fixed1.getRawBits() > fixed2.getRawBits())
        return fixed1;
    else
        return fixed2;
}
Fixed const &Fixed::max(Fixed const &fixed1, Fixed const &fixed2)
{
    if (fixed1.getRawBits() > fixed2.getRawBits())
        return fixed1;
    else
        return fixed2;
}



/*
** --------------------------------- OVERLOAD COMPARAISON ---------------------------------
*/
bool Fixed::operator>(Fixed const &rhs) const
{
	return this->getRawBits() > rhs.getRawBits();
}
bool Fixed::operator<(Fixed const &rhs) const
{
	return this->getRawBits() < rhs.getRawBits();
}
bool Fixed::operator>=(Fixed const &rhs) const
{
	return this->getRawBits() >= rhs.getRawBits();
}
bool Fixed::operator<=(Fixed const &rhs) const
{
	return this->getRawBits() <= rhs.getRawBits();
}
bool Fixed::operator==(Fixed const &rhs) const
{
	return this->getRawBits() == rhs.getRawBits();
}
bool Fixed::operator!=(Fixed const &rhs) const
{
	return this->getRawBits() != rhs.getRawBits();
}

/*
** --------------------------------- OVERLOAD ARITHMETICS ---------------------------------
*/
Fixed Fixed::operator+(Fixed const &rhs) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() + rhs.getRawBits());
	return result;
}

Fixed Fixed::operator-(Fixed const &rhs) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() - rhs.getRawBits());
	return result;
}

Fixed Fixed::operator*(Fixed const &rhs) const
{
	Fixed result;
	result.setRawBits((this->getRawBits() * rhs.getRawBits()) >> 8); // Assuming 8 fractional bits
	return result;
}

Fixed Fixed::operator/(Fixed const &rhs) const
{
	if (rhs.getRawBits() == 0)
	{
		std::cout << "Can't divide by zero" << std::endl;
		return *this;
	}
	Fixed result;
	result.setRawBits((this->getRawBits() << 8) / rhs.getRawBits()); // Assuming 8 fractional bits
	return result;
}

/*
** --------------------------------- OVERLOAD ++/-- ---------------------------------
*/
Fixed &Fixed::operator++()
{
	this->fixedValue += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++(*this);
	return temp;
}

Fixed &Fixed::operator--()
{
	this->fixedValue -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--(*this);
	return temp;
}
