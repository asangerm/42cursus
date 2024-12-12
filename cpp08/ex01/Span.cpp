/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:27:04 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/12 20:10:39 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Constructors
	Span::Span()
	{

	}

	Span::Span(uint N) : len(N)
	{

	}

	Span::Span(const Span &src)
	{
		*this = src;
	}

// Destructors
	Span::~Span()
	{

	}

// Operator overloads
	Span& Span::operator = (const Span &src)
	{
		*this = src;
		return (*this);
	}

// Member functions
	void	Span::addNumber(int number)
	{
		if (tab.size() >= len)
			throw MaxCapacityException();
		tab.insert(number);
	}

	int		Span::shortestSpan()
	{
		if (tab.size() < 2)
			throw InvalidSpanException();

		int	mini = std::numeric_limits<int>::max();
		std::set<int>::iterator	last = tab.begin();

		for (std::set<int>::iterator val = ++tab.begin(); val != tab.end(); val++)
		{
			mini = std::min(mini, *val - *last);
			last = val;
		}
		return (mini);
	}

	int		Span::longestSpan()
	{
		if (tab.size() < 2)
			throw InvalidSpanException();
		
		return (*tab.rbegin() - *tab.begin());
	}