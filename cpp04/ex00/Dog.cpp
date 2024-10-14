/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 00:02:47 by asangerm          #+#    #+#             */
/*   Updated: 2024/10/03 00:31:49 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructors
	Dog::Dog() : Animal("Dog")
	{
		std::cout
		<< "Dog default constructor called!"	<< std::endl;
	}

	Dog::Dog(const Dog& copy)
	{
		*this = copy;
		std::cout
		<< "Dog copy constructor called"	<< std::endl;
	}

// Destructors
	Dog::~Dog()
	{
		std::cout
		<< "Dog destructor called"	<< std::endl;
	}

// Overload operators
	Dog&	Dog::operator = (const Dog& copy)
	{
		this->type = copy.type;
		std::cout
		<< "Dog operator = called"	<< std::endl;
		return *this;
	}

// Member functions
	void	Dog::makeSound() const
	{
		std::cout
		<< "Waaaaaaaaaaaaaaf"	<< std::endl;
	}