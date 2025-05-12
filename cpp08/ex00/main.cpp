/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:25:09 by asangerm          #+#    #+#             */
/*   Updated: 2025/01/29 00:26:28 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	std::vector<int>	v;
	for (int i = 0; i < 10; i++)
		v.push_back(i + 1);
	std::cout << "vector: [";
	for (size_t i = 0; i < v.size(); ++i)
        std::cout << " " << v[i] << ";";
	std::cout << "]" << std::endl;

	std::cout << "Value to find: 5" << std::endl;
	try
	{
		easyfind(v, 5);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	};
	std::cout << std::endl;
	
	std::cout << "Value to find: 12" << std::endl;
	try
	{
		easyfind(v, 12);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	};
	std::cout << std::endl;

	
	std::list<int>	l;
	for (int i = 0; i < 10; i++)
		l.push_back(i + 1);
	std::cout << "list: [";
	for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        std::cout << " " << *it << ";";
    }
	std::cout << "]" << std::endl;

	std::cout << "Value to find: 5" << std::endl;
	try
	{
		easyfind(l, 5);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	};
	std::cout << std::endl;
	
	std::cout << "Value to find: 12" << std::endl;
	try
	{
		easyfind(l, 12);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	};
	std::cout << std::endl;
	
	return (0);
}