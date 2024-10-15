/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:43:38 by asangerm          #+#    #+#             */
/*   Updated: 2024/10/15 19:55:59 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// CCure::onstructors
	Cure::Cure() : AMateria("cure")
	{

	}
	
	Cure::Cure(const Cure& copy)
	{
		*this = copy;
	}
	
	
// Destructors
	Cure::~Cure()
	{

	}
	
	
// Operator overloads
	Cure& Cure::operator = (const Cure& copy)
	{
		if (this != &copy)
			this->type = copy.type;
		return (*this);
	}
	

// Member functions
	Cure* Cure::clone() const
	{
		return (new Cure());
	}
	
	void Cure::use(ICharacter &target)
	{
		std::cout
		<< " heals "
		<< target.getName()
		<< std::endl;
	}
	