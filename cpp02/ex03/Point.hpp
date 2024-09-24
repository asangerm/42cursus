/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 01:22:28 by asangerm          #+#    #+#             */
/*   Updated: 2024/09/24 02:15:42 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed	x;
		Fixed	y;
	public:
		// Constructors
		Point(void);
		Point(const Point&);
		Point(const float x, const float y);

		// Destructors
		~Point();

		// Operator overloads
		Point&	operator = (const Point&);

		// Member functions
		const Fixed&	getX(void) const;
		const Fixed&	getY(void) const;
};

std::ostream&	operator << (std::ostream &file, const Point point);

#endif