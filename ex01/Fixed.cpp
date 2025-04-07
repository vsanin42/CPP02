/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:15:59 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/07 16:47:31 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <ostream>

Fixed::Fixed() : value(0) { std::cout << "Default constructor called" << "\n"; }
Fixed::~Fixed() { std::cout << "Destructor called" << "\n"; }

Fixed::Fixed(const Fixed& ref)
{
	std::cout << "Copy constructor called" << "\n";
	*this = ref;
}

Fixed& Fixed::operator=(const Fixed& ref)
{
	std::cout << "Copy assignment operator called" << "\n";
	if (this != &ref)
		value = ref.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const { return value; }
void Fixed::setRawBits(int const raw) { value = raw; }

Fixed::Fixed(const int inum)
{
	std::cout << "Int constructor called" << "\n";
	value = inum << fraction_bits;
}

Fixed::Fixed(const float fnum)
{
	std::cout << "Float constructor called" << "\n";
	value = roundf(fnum * (1 << fraction_bits));
}

int Fixed::toInt(void) const
{
	return value >> fraction_bits;
}

float Fixed::toFloat(void) const
{
	return (float)value / (float)(1 << fraction_bits);
}

std::ostream& operator<<(std::ostream& stream, const Fixed& num)
{
	stream << num.toFloat();
	return stream;
}
