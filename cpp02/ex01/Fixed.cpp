/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:31:41 by asangerm          #+#    #+#             */
/*   Updated: 2024/09/24 00:46:19 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : num(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& to_copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->num = n << this->bits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->num = roundf(f * (1 << this->bits));
}

Fixed& Fixed::operator = (const Fixed& to_copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->num =  to_copy.getRawBits();
	return *this;
}

std::ostream& operator << (std::ostream &file, Fixed const &fixed)
{
	file << fixed.toFloat();
	return (file);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return this->num;
}

void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->num = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->num / (float)(1 << this->bits));
}

int		Fixed::toInt(void) const
{
	return (this->num >> this->bits);
}
