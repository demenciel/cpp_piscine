/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:35:03 by acouture          #+#    #+#             */
/*   Updated: 2023/10/10 13:44:55 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
public:
	Fixed();
	Fixed(Fixed const &src);
	~Fixed();
	Fixed &operator=(Fixed const &rhs);
	int getRawBits( void ) const;
	void setRawBits( int const raw );

private:
	int fixedValue;
	static const int bitsValue = 8;
};

#endif