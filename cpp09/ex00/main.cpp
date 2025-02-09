/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:29:47 by asangerm          #+#    #+#             */
/*   Updated: 2025/02/10 00:28:55 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int test(int ch)
{
	return !std::isspace(ch);
}

void checkInput(std::ifstream &file, int argc, char *fileName)
{
	if (argc != 2)
		throw std::runtime_error("Error: Usage: ./btc [file.txt].");
	file.open(fileName, std::ifstream::in);
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");
	std::ifstream testEmptyLine;
	std::string line;
	testEmptyLine.open(fileName, std::ifstream::in);
	while (getline(testEmptyLine, line))
	{
		line.erase(line.begin(), std::find_if(line.begin(), line.end(), test));
		if (line.empty())
		{
			testEmptyLine.close();
			throw std::runtime_error("Error: Empty line in input file.");
		}
	}
	testEmptyLine.close();
}

int	main(int argc, char **argv)
{
	std::ifstream inputFile;
	try
	{
		checkInput(inputFile, argc, argv[1]);
		BitcoinExchange btc = BitcoinExchange(inputFile);
		btc.showMap();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	inputFile.close();
}