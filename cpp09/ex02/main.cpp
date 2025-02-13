/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:21:55 by asangerm          #+#    #+#             */
/*   Updated: 2025/02/13 18:54:50 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	if (argc <= 1)
		return error("less than one argument"), 0;
	if (!isAllDigit(argv))
		return error("some arguments are not digits"), 0;
	PmergeMe test(argv);
	if (test.isDoppelGanger())
		return error("A number appears twice"), 0;
	std::cout << "Before: ";
	test.printTab();
	test.sortMe();
	std::cout << "After: ";
	test.printTab();
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector<int> : ";
	test.printTime();
	std::cout << " us" << std::endl;
	test.sortMeD();
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque<int> : ";
	test.printTime();
	std::cout << " us" << std::endl;
}