/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:12:23 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/09 00:31:40 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>
#include <climits>
#include <limits>
#include <iomanip>

class Convert
{
	private:
	// Constructors
		Convert();
		Convert(const Convert &src);
	
	// Destructors
		~Convert();
	
	// Operator overload
		Convert& operator = (const Convert &src);

	public:
	// Main function
		static void	convert(const std::string &input);
	
	// Testers
		static bool	isChar(const std::string &input);
		static bool	isInt(const std::string &input);
		static bool	isFloat(const std::string &input);
		static bool	isDouble(const std::string &input);
		static bool	isSpecial(const std::string &input);
	
	// Converters
		static void	convertChar(const std::string &input);
		static void	convertInt(const std::string &input);
		static void	convertFloat(const std::string &input);
		static void	convertDouble(const std::string &input);
		static void	convertSpecial(const std::string &input);
};
