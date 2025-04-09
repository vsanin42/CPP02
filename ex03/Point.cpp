/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:46:59 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/09 17:51:18 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cmath>
#include <iostream>

Point::Point() : x(0), y(0) {}

Point::Point(const float new_x, const float new_y) : x(new_x), y(new_y) {}

Point::Point(const Point& ref) : x(ref.x), y(ref.y) {}

Point::~Point() {}

Point& Point::operator=(const Point& ref)
{
	(void)ref;
	std::cout << "'=' operator invoked on const members. Result unchanged." << std::endl;
	return *this;
}

const Fixed& Point::getX(void) const { return x; }
const Fixed& Point::getY(void) const { return y; }
