/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:46:50 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/09 17:50:39 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point ap((point.getX() - a.getX()).toFloat(), (point.getY() - a.getY()).toFloat());
	Point ab((b.getX() - a.getX()).toFloat(), (b.getY() - a.getY()).toFloat());
	bool isABAPPositive = ab.getX() * ap.getY() - ab.getY() * ap.getX() > 0; // third term?

	Point bp((point.getX() - b.getX()).toFloat(), (point.getY() - b.getY()).toFloat());
	Point bc((c.getX() - b.getX()).toFloat(), (c.getY() - b.getY()).toFloat());
	bool isBCBPPositive = bc.getX() * bp.getY() - bc.getY() * bp.getX() > 0;

	if (isBCBPPositive != isABAPPositive)
		return false;

	Point cp((point.getX() - c.getX()).toFloat(), (point.getY() - c.getY()).toFloat());
	Point ca((a.getX() - c.getX()).toFloat(), (a.getY() - c.getY()).toFloat());
	bool isCACPPositive = ca.getX() * cp.getY() - ca.getY() * cp.getX() > 0;

	return isABAPPositive == isCACPPositive;
}
