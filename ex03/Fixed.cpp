/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:15:59 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/09 14:42:27 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <ostream>

Fixed::Fixed() : value(0) {}
Fixed::~Fixed() {}

Fixed::Fixed(const Fixed& ref)
{
	*this = ref;
}

Fixed& Fixed::operator=(const Fixed& ref)
{
	if (this != &ref)
		value = ref.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const { return value; }
void Fixed::setRawBits(int const raw) { value = raw; }

/* -------------------------------------------------------------------------- */
/*                                    ex01                                    */
/* -------------------------------------------------------------------------- */

Fixed::Fixed(const int inum) { value = inum << fraction_bits; }

Fixed::Fixed(const float fnum) { value = roundf(fnum * (1 << fraction_bits)); }

int Fixed::toInt(void) const { return value >> fraction_bits; }

float Fixed::toFloat(void) const { return (float)value / (float)(1 << fraction_bits); }

std::ostream& operator<<(std::ostream& stream, const Fixed& num)
{
	stream << num.toFloat();
	return stream;
}

/* -------------------------------------------------------------------------- */
/*                                    ex02                                    */
/* -------------------------------------------------------------------------- */

bool Fixed::operator<(const Fixed& ref) const { return this->value < ref.value; }

bool Fixed::operator>(const Fixed& ref) const { return !((*this) < ref) && !((*this) == ref); }

bool Fixed::operator==(const Fixed& ref) const { return this->value == ref.value; }

bool Fixed::operator!=(const Fixed& ref) const { return !(*this == ref); }

bool Fixed::operator<=(const Fixed& ref) const { return (*this) < ref || (*this) == ref; }

bool Fixed::operator>=(const Fixed& ref) const { return !((*this) < ref); }

Fixed Fixed::operator+(const Fixed& ref) const
{
	int sum = this->value + ref.value;
	Fixed res;
	res.setRawBits(sum);
	return res;
}

Fixed Fixed::operator-(const Fixed& ref) const
{
	int difference = this->value - ref.value;
	Fixed res;
	res.setRawBits(difference);
	return res;
}

Fixed Fixed::operator*(const Fixed& ref) const
{
	int64_t this_val = static_cast<int64_t>(this->value);
	int64_t ref_val = static_cast<int64_t>(ref.value);
	int product = ((this_val * ref_val) + (1LL << (fraction_bits - 1))) >> fraction_bits;
	
	Fixed res;
	res.setRawBits(product);
	return res;
}

Fixed Fixed::operator/(const Fixed& ref) const
{
	if (ref.value == 0)
		throw std::domain_error("Division by zero.");
	int64_t this_val = static_cast<int64_t>(this->value);
	int64_t ref_val = static_cast<int64_t>(ref.value);
	int quotient = ((this_val << fraction_bits) + (ref_val / 2)) / ref_val;

	Fixed res;
	res.setRawBits(quotient);
	return res;
}

Fixed Fixed::operator++(int)
{
	Fixed old = *this;
	operator++();
	return old;
}

Fixed Fixed::operator--(int)
{
	Fixed old = *this;
	operator--();
	return old;
}

Fixed& Fixed::operator++()
{
	this->value += 1;
	return *this;
}

Fixed& Fixed::operator--()
{
	this->value -= 1;
	return *this;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) { return a <= b ? a : b; }

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) { return a <= b ? a : b; }

Fixed& Fixed::max(Fixed& a, Fixed& b) { return a >= b ? a : b; }

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) { return a >= b ? a : b; }

