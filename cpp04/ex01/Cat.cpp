/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 00:12:31 by asangerm          #+#    #+#             */
/*   Updated: 2024/10/14 15:45:46 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructors
	Cat::Cat() : Animal("Cat"), brain(new Brain())
	{
		std::cout
		<< "Cat default constructor called!"	<< std::endl;
	}

	Cat::Cat(const Cat& copy)
	{
		*this = copy;
		std::cout
		<< "Cat copy constructor called"	<< std::endl;
	}

// Destructors
	Cat::~Cat()
	{
		delete this->brain;
		std::cout
		<< "Cat destructor called"	<< std::endl;
	}

// Overload operators
	Cat&	Cat::operator = (const Cat& copy)
	{
		if (this != &copy)
		{
			this->type = copy.type;
			if (this->brain != NULL)
				delete this->brain;
			this->brain = new Brain(*copy.brain);
		}
		std::cout
		<< "Cat operator = called"	<< std::endl;
		return *this;
	}

// Member functions
	void	Cat::makeSound() const
	{
		std::cout
		<< "Miaouuuuuuuuuuuuuuuuuu"	<< std::endl;
	}

	Brain*	Cat::getBrain() const
	{
		return this->brain;
	}