/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:16:48 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/12 18:26:26 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>

// Exceptions
	class	NotFoundException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("Element not found");
			}
	};

// Functions
	template	<typename T>
	typename T::iterator	easyfind(T &container, int elt)
	{
		typename T::iterator	find = std::find(container.begin(), container.end(), elt);

		if (find == container.end())
			throw (NotFoundException());
		return (find);
	}