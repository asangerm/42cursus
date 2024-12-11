/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:04:19 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/11 16:13:01 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template	<typename T>
void	iter(T *array, size_t len, void (*f)(T const &))
{
	for (size_t i = 0; i < len; i++)
		f(array[i]);
}

template	<typename T>
void	printer(T const &val)
{
	std::cout << val << " / ";
}