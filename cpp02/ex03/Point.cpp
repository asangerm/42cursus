/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 01:22:06 by asangerm          #+#    #+#             */
/*   Updated: 2024/09/24 02:17:11 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Constructors
Point::Point(): x(0), y(0)
{
}

Point::Point(const float x, const float y): x(x), y(y)
{
}

Point::Point(const Point &to_copy): x(to_copy.getX()), y(to_copy.getY())
{
}

// Deconstructors
Point::~Point()
{
}

// Overloaded Operators
Point&	Point::operator = (const Point &to_copy)
{
	this->x = to_copy.getX();
	this->y = to_copy.getY();
	return *this;
}

const Fixed&	Point::getX(void)const
{
	return (this->x);
}

const Fixed&	Point::getY(void)const
{
	return (this->y);
}

std::ostream	&operator<<(std::ostream &file, Point const point)
{
	file << "x: " << point.getX() << " and y: " << point.getY() << std::endl;
	return (file);
}