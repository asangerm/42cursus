/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 00:25:33 by asangerm          #+#    #+#             */
/*   Updated: 2024/10/14 00:26:09 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Constructors
	WrongAnimal::WrongAnimal() : type("default")
	{
		std::cout
		<< "WrongAnimal default constructor called!"	<< std::endl;
	}

	WrongAnimal::WrongAnimal(std::string type) : type(type)
	{
		std::cout
		<< "WrongAnimal type constructor called with type : "	<< type
		<< std::endl;
	}

	WrongAnimal::WrongAnimal(const WrongAnimal& copy)
	{
		*this = copy;
		std::cout
		<< "WrongAnimal copy constructor called"	<< std::endl;
	}

// Destructors
	WrongAnimal::~WrongAnimal()
	{
		std::cout
		<< "WrongAnimal destructor called"	<< std::endl;
	}

// Overload operators
	WrongAnimal&	WrongAnimal::operator = (const WrongAnimal& copy)
	{
		this->type = copy.type;
		std::cout
		<< "WrongAnimal operator = called"	<< std::endl;
		return *this;
	}

// Member functions
	void	WrongAnimal::makeSound() const
	{
		std::cout
		<< "Nothing happens..."	<< std::endl;
	}

// Getters
	std::string	WrongAnimal::getType() const
	{
		return (this->type);
	}