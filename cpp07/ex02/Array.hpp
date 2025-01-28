/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:36:08 by asangerm          #+#    #+#             */
/*   Updated: 2025/01/29 00:10:00 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>

template	<typename T>
class	Array
{	
	private:
	// Data
		T*		elt;
		unsigned int	len;

	public:
	// Constructors
		Array();
		Array(unsigned int len);
		Array(const Array &src);
	
	// Destructors
		~Array();

	// Overload operators
		Array&		operator = (const Array &src);
		T&			operator [] (unsigned int i);
		const T&	operator [] (unsigned int i) const;

	// Exceptions
		class	OutOfBoundsException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#include "Array.tpp"