/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:50:02 by asangerm          #+#    #+#             */
/*   Updated: 2024/10/15 19:55:53 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// Constructors
	Ice::Ice() : AMateria("ice")
	{

	}
	
	Ice::Ice(const Ice& copy)
	{
		*this = copy;
	}
	
	
// Destructors
	Ice::~Ice()
	{

	}
	
	
// Operator overloads
	Ice& Ice::operator = (const Ice& copy)
	{
		if (this != &copy)
			this->type = copy.type;
		return (*this);
	}
	

// Member functions
	Ice* Ice::clone() const
	{
		return (new Ice());
	}
	
	void Ice::use(ICharacter &target)
	{
		std::cout
		<< " use ice on "
		<< target.getName()
		<< std::endl;
	}
	