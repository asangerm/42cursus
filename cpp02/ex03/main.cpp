/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:46:11 by asangerm          #+#    #+#             */
/*   Updated: 2024/09/24 02:47:40 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(const Point p1, const Point p2, const Point p3, const Point point);

int main(void)
{
	Point p1;
	Point p2(10, 0);
	Point p3(0, 10);
	Point point(1, 1);

	std::cout << "point(x=" << point.getX() << ";y=" << point.getY() << ") is in\n" <<
	"p1(x=" << p1.getX() << ";y=" << p1.getY() << ")\n" <<
	"p2(x=" << p2.getX() << ";y=" << p2.getY() << ")\n" <<
	"p3(x=" << p3.getX() << ";y=" << p3.getY() << ")\n" << std::endl;
	if (bsp(p1, p2, p3, point) == true)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;
	std::cout << std::endl;
	Point p4(-1.5, -1.5);
	Point p5(2.5, 2.5);
	Point p6(-1, -2);
	Point point2(8.5, -9);

	std::cout << "point2(x=" << point2.getX() << ";y=" << point2.getY() << ") is in\n" <<
	"p4(x=" << p4.getX() << ";y=" << p4.getY() << ")\n" <<
	"p5(x=" << p5.getX() << ";y=" << p5.getY() << ")\n" <<
	"p6(x=" << p6.getX() << ";y=" << p6.getY() << ")\n" << std::endl;
	if (bsp(p4, p5, p6, point2) == true)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;
	return (0);
}
