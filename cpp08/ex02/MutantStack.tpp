/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:30:02 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/13 18:36:52 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

// Constructors
	template<typename T>
	MutantStack<T>::MutantStack()
	{

	}

	template<typename T>
	MutantStack<T>::MutantStack(const MutantStack<T> &src)
	{
		*this = src;
	}

// Destructors
	template<typename T>
	MutantStack<T>::~MutantStack()
	{

	}

// Operator overloads
	template<typename T>
	MutantStack<T>& MutantStack<T>::operator = (const MutantStack<T> &src)
	{
		this->c = src.c;
		return (*this);
	}

// Member functions
	template<typename T>
	typename std::stack<T>::container_type::iterator	MutantStack<T>::begin()
	{
		return (this->c.begin());
	}

	template<typename T>
	typename std::stack<T>::container_type::iterator	MutantStack<T>::end()
	{
		return (this->c.end());
	}

	template<typename T>
	typename std::stack<T>::container_type::const_iterator	MutantStack<T>::cbegin()
	{
		return (this->c.cbegin());
	}

	template<typename T>
	typename std::stack<T>::container_type::const_iterator	MutantStack<T>::cend()
	{
		return (this->c.cend());
	}