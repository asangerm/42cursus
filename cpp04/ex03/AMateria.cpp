/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:37:48 by asangerm          #+#    #+#             */
/*   Updated: 2024/10/15 19:43:16 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
// Constructors
	AMateria::AMateria()
	{
		
	}

	AMateria::AMateria(std::string const & type) : type(type)
	{

	}

	AMateria::AMateria(const AMateria& copy)
	{
		*this = copy;
	}
	
// Destructors
	AMateria::~AMateria()
	{

	}
	
// Operator overloads
	AMateria& AMateria::operator = (const AMateria& copy)
	{
		this->type = copy.type;
		return *this;
	}

// Member functions
	void AMateria::use(ICharacter& target)
	{

	}

// Getters
	std::string const& AMateria::getType() const
	{
		return (this->type);
	}