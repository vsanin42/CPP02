/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:15:59 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/05 16:07:22 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

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
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << "\n"; 
	return (value);
}
void Fixed::setRawBits(int const raw) { value = raw; }
