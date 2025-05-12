/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:24:24 by asangerm          #+#    #+#             */
/*   Updated: 2025/02/12 14:13:16 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Functions
	void error()
	{
		std::cout << "Error" << std::endl;
	}

// Constructors
	RPN::RPN()
	{
	}

	RPN::RPN(const RPN& copy)
	{
		*this = copy;
	}

	RPN::RPN(const std::string str)
	{
		this->str = str;
	}

// Operator overload
	RPN& RPN::operator = (const RPN& copy)
	{
		this->str = copy.str;
		return *this;
	}

// Destructors
	RPN::~RPN()
	{
	}


// Private methods

	bool RPN::validChar(char c)
	{
		std::string chars = " 1234567890+-/*";
		for (size_t j = 0; j < chars.length(); j++)
			if (c == chars[j])
				return true;
		return false;
	}

	bool RPN::validChars()
	{
		for (size_t i = 0; i < this->str.length(); i++)
		{
			if (!validChar(this->str[i]))
				return false;
		}
		return true;
	}

// Public methods
	void RPN::Calculate()
	{
		int res = 0;
		int a = 0;
		int b = 0;
		std::stack<int> numbers;
		if (this->str.empty() || !validChars())
			return error();
		for (size_t i = 0; i < this->str.length(); i ++)
		{
			if (std::isdigit(this->str[i]))
				numbers.push(this->str[i] - '0');
			else if (str[i] != ' ')
			{
				if (numbers.size() < 2)
					return error();
				a = numbers.top(); numbers.pop();
				b = numbers.top(); numbers.pop();
				if (this->str[i] == '+')
					res = a + b;
				if (this->str[i] == '-')
					res = b - a;
				if (this->str[i] == '*')
					res = a * b;
				if (this->str[i] == '/')
				{
					if (a == 0)
						return error();
					res = b / a;
				}
				numbers.push(res);
			}
		}
		if (numbers.size() != 1)
			return error();
		res = numbers.top();
		std::cout << res << std::endl;
	}