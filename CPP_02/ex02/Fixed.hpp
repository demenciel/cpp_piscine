#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

// Ajoutez à votre classe des fonctions membres publiques afin de surcharger les opéra-
// teurs suivants :
// • Les 6 opérateur de comparaison : >, <, >=, <=, == et !=.
// • Les 4 opérateurs de arithmétiques : +, -, *, et /.
// • Les 4 opérateurs d’incrémentation et de décrémentation (pré-incrémentation et
// post-incrémentation, pré-décrémentation et post-décrémentation) qui diminueront
// la valeur du nombre à virgule fixe d’unité ε tel que 1 + ε > 1.
// Ajoutez à votre classe ces quatre fonctions membres publiques surchargées :
// • Une fonction membre statique min prenant en paramètres deux références sur des
// nombres à virgule fixe et qui retourne le plus petit d’entre eux.
// • Une fonction membre statique min prenant en paramètres deux références sur des
// nombres à virgule fixe constants et qui retourne le plus petit d’entre eux.
// • Une fonction membre statique max prenant en paramètres deux références sur des
// nombres à virgule fixe et qui retourne le plus grand d’entre eux.
// • Une fonction membre statique max prenant en paramètres deux références sur des
// nombres à virgule fixe constants et qui retourne le plus grand d’entre eux.

class Fixed
{
public:
	// coplien
	Fixed();
	Fixed(const Fixed &src);
	~Fixed();
	Fixed &operator=(Fixed const &rhs);
	// surcharging comparaison operators
	bool operator>(Fixed const &rhs) const;
	bool operator<(Fixed const &rhs) const;
	bool operator>=(Fixed const &rhs) const;
	bool operator<=(Fixed const &rhs) const;
	bool operator==(Fixed const &rhs) const;
	bool operator!=(Fixed const &rhs) const;
	// surcharging arithmetics operators
	Fixed operator+(Fixed const &rhs) const;
	Fixed operator-(Fixed const &rhs) const;
	Fixed operator*(Fixed const &rhs) const;
	Fixed operator/(Fixed const &rhs) const;
	// surcharging arithmetics operators
	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);
	// constructors int/float
	Fixed(int const value);
	Fixed(float const value);
	// member functions
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	static Fixed &min(Fixed &fixed1, Fixed &fixed2);
	static const Fixed &min(Fixed const &fixed1, Fixed const &fixed2);
	static Fixed &max(Fixed &fixed1, Fixed &fixed2);
	static const Fixed &max(Fixed const &fixed1, const Fixed &fixed2);

private:
	int fixedValue;
	static const int bitsValue = 8;
};

// converts the fixed value of Fixed into a floating number and prints in the out stream
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif