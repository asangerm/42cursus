/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:01:55 by asangerm          #+#    #+#             */
/*   Updated: 2024/09/06 21:48:30 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	replace(char **argv, std::string str)
{
	std::ofstream	file;
	std::string		fileName;
	int				start;
	int				to_replace_size;

	to_replace_size = std::string(argv[2]).size();
	fileName = std::string(argv[1]) + ".replace";
	file.open(fileName);
	if (file.fail())
		return (1);
	for (int i = 0; i < str.size(); i++)
	{
		start = str.find(argv[2], i);
		if (start == i)
		{
			file << argv[3];
			i += to_replace_size - 1;
		}
		else
			file << str[i];
	}
	file.close();
	return (0);
}

int	main(int argc, char** argv)
{
	std::ifstream	file;
	char			c;
	std::string		str;

	if (argc != 4)
	{
		std::cout << "commande: ./<exec> <fichier> <s1> <s2>"
		<< std::endl;
		return (1);
	}
	file.open(argv[1]);
	if (file.fail())
	{
		std::cout << argv[1]
		<< ": impossible d'ouvrir le fichier"
		<< std::endl;
		return (1);
	}
	while (!file.eof() && file >> std::noskipws >> c)
		str += c;
	file.close();
	return (replace(argv, str));
}
