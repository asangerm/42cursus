/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:36:08 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/11 23:47:12 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template	<typename T>
class	Array
{	
	private:
	// Data
		T*		elt;
		uint	len;

	public:
	// Constructors
		Array();
		Array(uint len);
		Array(const Array &src);
	
	// Destructors
		~Array();

	// Overload operators
		Array&		operator = (const Array &src);
		T&			operator [] (uint i);
		const T&	operator [] (uint i) const;

	// Exceptions
		class	OutOfBoundsException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#include "Array.tpp"