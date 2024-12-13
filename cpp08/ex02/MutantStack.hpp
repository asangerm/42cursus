/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:29:02 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/13 18:46:20 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

template	<typename T>
class	MutantStack : public std::stack<T>
{
	public:
	// Data
		typedef typename std::stack<T>::container_type::iterator 		iterator;
		typedef typename std::stack<T>::container_type::const_iterator	const_iterator;

	// Constructors
		MutantStack<T>();
		MutantStack<T>(const MutantStack<T> &src);

	// Destructors
		~MutantStack<T>();
	
	// Operator overloads
		MutantStack<T>& operator = (const MutantStack<T> &src);

	// Member functions
		iterator	begin();
		iterator	end();
		const_iterator	cbegin();
		const_iterator	cend();
};

# include "MutantStack.tpp"
