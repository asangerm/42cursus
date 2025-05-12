/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:26:24 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/30 17:10:48 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	rep;
	std::string	str;

	while (str != "EXIT")
	{
		std::cout << "\x1B[34mEntrez une commande > \033[0m";
		std::getline(std::cin, str);
		if (str == "ADD")
			rep.add();
		else if (str == "SEARCH")
			rep.search();
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
	}
	return (0);
}