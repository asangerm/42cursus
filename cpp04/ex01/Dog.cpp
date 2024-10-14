/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 00:02:47 by asangerm          #+#    #+#             */
/*   Updated: 2024/10/14 15:48:36 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructors
	Dog::Dog() : Animal("Dog"), brain(new Brain())
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
		delete this->brain;
		std::cout
		<< "Dog destructor called"	<< std::endl;
	}

// Overload operators
	Dog&	Dog::operator = (const Dog& copy)
	{
		if (this != &copy)
		{
			this->type = copy.type;
			if (this->brain != NULL)
				delete this->brain;
			this->brain = new Brain(*copy.brain);
		}
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

	Brain*	Dog::getBrain() const
	{
		return this->brain;
	}