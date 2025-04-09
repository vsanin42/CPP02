/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:47:12 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/09 17:26:46 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
		// todo?
	public:
		Point();
		Point(const float new_x, const float new_y);
		Point(const Point& ref);
		~Point();
		Point& operator=(const Point& ref);
		
		const Fixed& getX(void) const;
		const Fixed& getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
