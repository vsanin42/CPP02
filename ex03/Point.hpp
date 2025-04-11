/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:47:12 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/11 11:00:51 by vsanin           ###   ########.fr       */
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
