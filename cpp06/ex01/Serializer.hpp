/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:31:43 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/09 16:56:44 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <cstdint>

typedef struct	s_Data
{
	int			integer;
	std::string	str;
}				Data;

class	Serializer
{
	private:
	// Constructors
		Serializer();
		Serializer(Serializer const &src);
	
	// Operator overload
		Serializer &operator = (Serializer const &src);

	public:
	// Destructors
		~Serializer();

	// Member functions
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};