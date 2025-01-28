/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:36:39 by asangerm          #+#    #+#             */
/*   Updated: 2025/01/29 00:11:44 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Array.hpp"

// Constructors
	template <typename T>
	Array<T>::Array() : elt(new T[0]), len(0)
	{

	}

	template <typename T>
	Array<T>::Array(unsigned int len) : elt(new T[len]), len(len)
	{

	}

	template <typename T>
	Array<T>::Array(const Array &src) : elt(new T[src.len]), len(src.len)
	{
		for (unsigned int i = 0; i < src.len; i++)
			elt[i] = src.elt[i];
	}

// Destructors
	template <typename T>
	Array<T>::~Array()
	{
		delete [] elt;
	}

// Overload operators
	template <typename T>
	Array<T>&	Array<T>::operator = (const Array &src)
	{
		delete [] elt;
		len = src.len;
		elt = new T[src.len];
		for (unsigned int i = 0; i < len; i++)
			elt[i] = src.elt[i];
		return (*this);
	}

	template <typename T>
	T&	Array<T>::operator [] (unsigned int i)
	{
		if (i >= len)
			throw OutOfBoundsException();
		else
			return (elt[i]);
	}

	template <typename T>
	const T&	Array<T>::operator [] (unsigned int i) const
	{
		if (i >= len || i < 0)
			throw OutOfBoundsException();
		else
			return (elt[i]);
	}

// Exceptions
	template <typename T>
	const char*	Array<T>::OutOfBoundsException::what() const throw()
	{
		return ("Index is out of bounds");
	}