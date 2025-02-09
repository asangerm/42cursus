/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:30:09 by asangerm          #+#    #+#             */
/*   Updated: 2025/02/10 00:21:19 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <stdexcept>
#include <algorithm>

class BitcoinExchange
{
	private:
	// Data
		std::map<std::string, float> map;
	
	// Private methods
		void parseData(std::ifstream &data);
		void parseInput(std::ifstream &input);
		void showRate(std::string const &date, std::string const &val);

	public:
	// Constructors
		BitcoinExchange();
		BitcoinExchange(std::ifstream &file);
		BitcoinExchange(const BitcoinExchange& copy);
	
	// Destructors
		~BitcoinExchange();

	// Operator overloads
		BitcoinExchange  &operator = (BitcoinExchange const &copy);

	// Public methods
		void showMap();
};