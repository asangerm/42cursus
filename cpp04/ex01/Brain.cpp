/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:32:42 by asangerm          #+#    #+#             */
/*   Updated: 2024/10/14 15:54:42 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Constructors
	Brain::Brain()
	{
		std::cout
		<< "Brain default constructor called!"	<< std::endl;
	}

	Brain::Brain(const Brain& copy)
	{
		*this = copy;
		std::cout
		<< "Brain copy constructor called"	<< std::endl;
	}

// Destructors
	Brain::~Brain()
	{
		std::cout
		<< "Brain destructor called"	<< std::endl;
	}

// Overload operators
	Brain&	Brain::operator = (const Brain& copy)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = copy.ideas[i];
		std::cout
		<< "Brain operator = called"	<< std::endl;
		return *this;
	}

// Getters
	std::string	Brain::getIdea(int	index) const
	{
		if (index >= 0 && index < 100)
			return (this->ideas[index]);
		else
			return NULL;
	}
	
// Setters
	void	Brain::setIdea(int index, std::string idea)
	{
		if (index >= 0 && index < 100)
			this->ideas[index] = idea;
	}

// Member functions
	