/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 01:23:58 by asangerm          #+#    #+#             */
/*   Updated: 2024/09/24 02:26:19 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float	area(const Point p1, const Point p2, const Point p3)
{
	float	area;

	area = ((p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat())) +
			(p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat())) +
			(p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat()))) / 2;
	if (area >= 0)
		return (area);
	else
		return (area * -1);
}

bool bsp(const Point p1, const Point p2, const Point p3, const Point point)
{
	float a1, a2, a3, a4;
	bool b = false;

	a1 = area(p1, p2, p3);
	a2 = area(point, p1, p2);
	a3 = area(point, p2, p3);
	a4 = area(point, p1, p3);
	if ( a2 == 0 || a3 == 0 || a4 == 0)
		b = false;
	else if ( a2 + a3 + a4 == a1 )
		b = true;
	return (b);
}