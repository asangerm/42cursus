/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 23:28:40 by asangerm          #+#    #+#             */
/*   Updated: 2024/10/03 00:31:24 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructors
	Animal::Animal() : type("default")
	{
		std::cout
		<< "Animal default constructor called!"	<< std::endl;
	}

	Animal::Animal(std::string type) : type(type)
	{
		std::cout
		<< "Animal type constructor called with type : "	<< type
		<< std::endl;
	}

	Animal::Animal(const Animal& copy)
	{
		*this = copy;
		std::cout
		<< "Animal copy constructor called"	<< std::endl;
	}

// Destructors
	Animal::~Animal()
	{
		std::cout
		<< "Animal destructor called"	<< std::endl;
	}

// Overload operators
	Animal&	Animal::operator = (const Animal& copy)
	{
		this->type = copy.type;
		std::cout
		<< "Animal operator = called"	<< std::endl;
		return *this;
	}

// Member functions
	void	Animal::makeSound() const
	{
		std::cout
		<< "Nothing happens..."	<< std::endl;
	}

// Getters
	std::string	Animal::getType() const
	{
		return (this->type);
	}