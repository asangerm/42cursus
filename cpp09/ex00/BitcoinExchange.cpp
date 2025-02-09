/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 00:09:58 by asangerm          #+#    #+#             */
/*   Updated: 2025/02/10 00:26:05 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Constructors
	BitcoinExchange::BitcoinExchange() {}

	BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) : map(copy.map) {}

	BitcoinExchange::BitcoinExchange(std::ifstream &file)
	{
		(void) file;
		std::ifstream data;
		data.open("data.csv", std::ifstream::in);
		if (!data.is_open())
			throw std::runtime_error("Error: Can't open data file");
		this->parseData(data);
		this->parseInput(file);
	}

// Destructors
	BitcoinExchange::~BitcoinExchange() {}


// Operator overloads
	BitcoinExchange  &BitcoinExchange::operator = (BitcoinExchange const &copy)
	{
		(void) copy;
		return (*this);
	}

// Utils
	bool	isAllDigit(std::string const &str)
	{
		for (size_t i = 0; i < str.size(); i++)
		{
			if (std::isdigit(str[i]) == 0)
				return (false);
		}
		return (true);
	}

	bool isValidDate(std::string const & date)
	{
		if (date.length() != 10) return false;
		if (date[4] != '-' || date[7] != '-') return false;
		std::string year = date.substr(0, 4);
		std::string month = date.substr(5, 2);
		std::string day = date.substr(8, 2);
		if (!isAllDigit(year) || !isAllDigit(month) || !isAllDigit(day))
			return false;
		int iMonth = std::atoi(month.c_str());
		int iDay = std::atoi(day.c_str());
		if (iMonth < 1 || iMonth > 12) return false;
		else if (iDay < 1 ||iDay > 31) return false;
		return true;
	}

	bool isValidFloat(std::string const & value)
	{
		char* endptr = 0;
		std::strtod(value.c_str(), &endptr);
		return endptr != value.c_str() && *endptr == '\0'; 
	}

	bool checkInputFloat(std::string const & value)
	{
		float f = std::strtof(value.c_str(), 0);
		if (f < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			return false;
		}
		if (f >= static_cast<float>(__INT_MAX__) || f > 1000)
		{
			std::cerr << "Error: too large number." << std::endl;
			return false;
		}
		return true;
	}

	std::string trim(const std::string& str)
	{
		size_t first = str.find_first_not_of(" \t");
		if (first == std::string::npos)
			return "";
		size_t last = str.find_last_not_of(" \t");
		return str.substr(first, last - first + 1);
	}

// Private Methods
	void	BitcoinExchange::parseData(std::ifstream &data) {
		std::string line;
		std::getline(data, line);

		while (std::getline(data, line))
		{
			size_t commaPos = line.find(',');
			if (commaPos == std::string::npos)
				throw std::runtime_error("Error: line does not contain a comma.");
			std::string date = line.substr(0, commaPos);
			std::string value = line.substr(commaPos + 1);
			if (!isValidDate(date))
				throw std::runtime_error("Error: Invalid date format in data.");
			if (!isValidFloat(value))
				throw std::runtime_error("Error: Invalid exchange rate in data.");
			this->map[date] = static_cast<float>(std::atof(value.c_str()));
		}
	}

	void BitcoinExchange::parseInput(std::ifstream &input)
	{
		std::string line, date, value;
		std::getline(input, line);
		while (std::getline(input, line))
		{
			size_t pipePos = line.find('|');
			if (pipePos == std::string::npos)
			{
				std::cerr << "Error: invalid line format." << std::endl;
				continue;
			}
			date = trim(line.substr(0, pipePos));
			value = trim(line.substr(pipePos + 1));
			if (!isValidDate(date))
			{
				std::cerr << "Error: bad input => " << date << std::endl;
				continue;
			}
			if (!checkInputFloat(value))
				continue;
			this->showRate(date, value);
		}
	}

	void BitcoinExchange::showRate(std::string const &date, std::string const &val)
	{
		std::map<std::string, float>::iterator it = this->map.upper_bound(date);
		if (it == this->map.begin())
		{
			std::cerr << "Error: No previous date available." << std::endl;
			return ;
		}
		float fVal = std::strtof(val.c_str(), 0);
		it--;
		std::cout << date << " => " << fVal
			<< " = " << it->second * fVal << std::endl;
	}

// Public Methods
	void BitcoinExchange::showMap()
	{
		std::cout << "Stored data:" << std::endl;
		for (std::map<std::string, float>::const_iterator it = map.begin(); it != map.end(); ++it)
			std::cout << it->first << " => " << it->second << std::endl;
	}