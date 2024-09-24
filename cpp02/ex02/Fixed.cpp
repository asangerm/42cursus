/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:31:41 by asangerm          #+#    #+#             */
/*   Updated: 2024/09/24 02:06:08 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : num(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& to_copy)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}

Fixed::Fixed(const int n)
{
	//std::cout << "Int constructor called" << std::endl;
	this->num = n << this->bits;
}

Fixed::Fixed(const float f)
{
	//std::cout << "Float constructor called" << std::endl;
	this->num = roundf(f * (1 << this->bits));
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator = (const Fixed& to_copy)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	this->num =  to_copy.getRawBits();
	return *this;
}

std::ostream& operator << (std::ostream &file, Fixed const &fixed)
{
	file << fixed.toFloat();
	return (file);
}

bool	Fixed::operator > (Fixed fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator < (Fixed fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator >= (Fixed fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator <= (Fixed fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator == (Fixed fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator != (Fixed fixed) const
{
	return (this->toFloat() != fixed.toFloat());
}

float	Fixed::operator + (Fixed fixed) const
{
	return (this->toFloat() + fixed.toFloat());
}

float	Fixed::operator - (Fixed fixed) const
{
	return (this->toFloat() - fixed.toFloat());
}

float	Fixed::operator * (Fixed fixed) const
{
	return (this->toFloat() * fixed.toFloat());
}

float	Fixed::operator / (Fixed fixed) const
{
	return (this->toFloat() / fixed.toFloat());
}

Fixed	Fixed::operator ++ ()
{
	this->num++;
	return (*this);
}

Fixed	Fixed::operator -- ()
{
	this->num--;
	return (*this);
}

Fixed	Fixed::operator ++ (int)
{
	Fixed tmp = *this;
	++this->num;
	return (tmp);
}

Fixed	Fixed::operator -- (int)
{
	Fixed tmp = *this;
	--this->num;
	return (tmp);
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

Fixed&	Fixed::min(Fixed &n1, Fixed &n2)
{
	if (n1.toFloat() <= n2.toFloat())
		return (n1);
	else
		return (n2);
}

const Fixed&	Fixed::min(const Fixed &n1, const Fixed &n2)
{
	if (n1.toFloat() <= n2.toFloat())
		return (n1);
	else
		return (n2);
}

Fixed&	Fixed::max(Fixed &n1, Fixed &n2)
{
	if (n1.toFloat() >= n2.toFloat())
		return (n1);
	else
		return (n2);
}

const Fixed&	Fixed::max(const Fixed &n1, const Fixed &n2)
{
	if (n1.toFloat() >= n2.toFloat())
		return (n1);
	else
		return (n2);
}
