/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:36:09 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/09 16:38:51 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// Constructors
	Serializer::Serializer()
	{

	}

	Serializer::Serializer(Serializer const &src)
	{
		*this = src;
	}

// Operator overload
	Serializer &Serializer::operator = (Serializer const &src)
	{
		(void) src;
		return (*this);
	}

// Destructors
	Serializer::~Serializer() {}
	
// Member functions
	uintptr_t Serializer::serialize(Data* ptr)
	{
		return reinterpret_cast<uintptr_t>(ptr);
	}

	Data* Serializer::deserialize(uintptr_t raw)
	{
		return reinterpret_cast<Data*>(raw);
	}
