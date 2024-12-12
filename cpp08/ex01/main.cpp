/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:34:44 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/12 20:10:57 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <vector>

int	main(void)
{
	Span span = Span(1000);
	std::vector<int> tab;
	for (int i = 0; i < 1000; ++i)
        tab.push_back(rand() % 1001);

	try
	{
		span.addNumber(tab.begin(), tab.end());
		std::cout << "Span le plus court : " << span.shortestSpan() << std::endl;
		std::cout << "Span le plus long : " << span.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Erreur : " << e.what() << std::endl;
	}
	return (0);
}