/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:46:50 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/11 10:39:14 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point ap((point.getX() - a.getX()).toFloat(), (point.getY() - a.getY()).toFloat());
	Point ab((b.getX() - a.getX()).toFloat(), (b.getY() - a.getY()).toFloat());
	Fixed crossABAP = ab.getX() * ap.getY() - ab.getY() * ap.getX();
	bool isABAPPositive = crossABAP > 0;

	Point bp((point.getX() - b.getX()).toFloat(), (point.getY() - b.getY()).toFloat());
	Point bc((c.getX() - b.getX()).toFloat(), (c.getY() - b.getY()).toFloat());
	Fixed crossBCBP = bc.getX() * bp.getY() - bc.getY() * bp.getX();
	bool isBCBPPositive = crossBCBP > 0;

	if (isBCBPPositive != isABAPPositive)
		return false;

	Point cp((point.getX() - c.getX()).toFloat(), (point.getY() - c.getY()).toFloat());
	Point ca((a.getX() - c.getX()).toFloat(), (a.getY() - c.getY()).toFloat());
	Fixed crossCACP = ca.getX() * cp.getY() - ca.getY() * cp.getX();
	bool isCACPPositive = crossCACP > 0;

	if (crossABAP == 0 || crossBCBP == 0 || crossCACP == 0)
		return false;
	return isABAPPositive == isCACPPositive;
}
