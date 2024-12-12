/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:15:03 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/12 19:25:55 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <limits>
#include <set>

class	Span
{
	private:
	// Data
		std::set<int>	tab;
		uint			len;

	public:
	// Constructors
		Span(void);
		Span(uint N);
		Span(const Span &src);
	
	// Destructors
		~Span();
	
	// Operator overloads
		Span& operator = (const Span &src);
		
	// Member functions
		void	addNumber(int number);
		int		shortestSpan();
		int		longestSpan();
		template <typename T>
		void	addNumber(T begin, T end)
		{
			while (begin != end)
			{
				addNumber(*begin);
				begin++;
			}
		}

	// Exceptions
		class MaxCapacityException : public std::exception
		{
			public:
				virtual const char*	what() const throw() { return ("tab is full"); }
		};

		class InvalidSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw() { return ("Invalid Span"); }
		};
};