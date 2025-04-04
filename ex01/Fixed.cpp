/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:15:59 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/04 19:11:25 by vsanin           ###   ########.fr       */
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
	value = ref.getRawBits();
}

Fixed &Fixed::operator=(const Fixed& ref)
{
	std::cout << "Copy assignment operator called" << "\n";
	if (this != &ref)
		value = ref.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	return value;
}
void Fixed::setRawBits(int const raw) { value = raw; }

Fixed::Fixed(const int inum)
{
	std::cout << "Int constructor called" << "\n";
	value = inum << fraction_bits; // - 1
}

Fixed::Fixed(const float fnum)
{
	std::cout << "Float constructor called" << "\n";
	value = roundf(fnum * (1 << fraction_bits)); // - 1
}

int Fixed::toInt(void) const
{
	//std::cout << "value before toInt: " << value << "\n";
	return value >> fraction_bits;
}

float Fixed::toFloat(void) const
{
	//std::cout << "value before toFloat: " << value << "\n";
	return value >> fraction_bits;
}

std::ostream& operator<<(std::ostream& stream, const Fixed& num)
{
	stream << num.toFloat();
	return stream;
}
