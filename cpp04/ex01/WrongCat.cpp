/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 00:26:17 by asangerm          #+#    #+#             */
/*   Updated: 2024/10/14 00:27:23 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Constructors
	WrongCat::WrongCat() : WrongAnimal("WrongCat")
	{
		std::cout
		<< "WrongCat default constructor called!"	<< std::endl;
	}

	WrongCat::WrongCat(const WrongCat& copy)
	{
		*this = copy;
		std::cout
		<< "WrongCat copy constructor called"	<< std::endl;
	}

// Destructors
	WrongCat::~WrongCat()
	{
		std::cout
		<< "WrongCat destructor called"	<< std::endl;
	}

// Overload operators
	WrongCat&	WrongCat::operator = (const WrongCat& copy)
	{
		this->type = copy.type;
		std::cout
		<< "WrongCat operator = called"	<< std::endl;
		return *this;
	}

// Member functions
	