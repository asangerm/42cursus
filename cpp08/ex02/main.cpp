/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:36:58 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/13 18:46:08 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	int i = 0;

	std::cout << "Stack:" << std::endl;
	MutantStack<int> mutant;

	mutant.push(1);
	mutant.push(2);
	mutant.push(3);
	mutant.push(4);
	mutant.push(5);
	mutant.push(6);

	MutantStack<int>::iterator it = mutant.begin();
	MutantStack<int>::iterator ite = mutant.end();
	
	while (it != ite)
	{
		std::cout << i++ << ": " << *it << std::endl;
		++it;
	}

	return (0);
}