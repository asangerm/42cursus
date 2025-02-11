/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:19:48 by asangerm          #+#    #+#             */
/*   Updated: 2025/02/11 22:20:30 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>

class RPN
{
	private:
	// Data
		std::string str;

	// Private methods
		bool validChars();
		bool validChar(char c);
	public:
	// Constructors
		RPN();
		RPN(const RPN& copy);
		RPN(const std::string str);
	
	// Operator overload
		RPN& operator = (const RPN& copy);

	// Destructors
		~RPN();
	
	// Public Methods
		void Calculate();
};

// Functions
	void error();