/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:13:17 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/11 15:32:58 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template	<typename T>
void	swap(T &a, T &b)
{
	T	tmp;
	tmp = a;
	a = b;
	b = tmp;
}

template	<typename T>
T const	&min(T const &a, T const &b)
{
	return (a < b ? a : b);
}

template	<typename T>
T const	&max(T const &a, T const &b)
{
	return (a > b ? a : b);
}