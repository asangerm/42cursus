/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:11:33 by asangerm          #+#    #+#             */
/*   Updated: 2025/02/13 18:53:39 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <set>
#include <algorithm>
#include <ctime>

class PmergeMe
{
	private:
	// Data
		std::vector<int> tab;
		std::deque<int> tabD;
		std::clock_t start;
    	std::clock_t end;

	public:
	// Constructors
		PmergeMe();
		PmergeMe(const PmergeMe& copy);
		PmergeMe(char** argv);
	
	// Operator overload
		PmergeMe& operator = (const PmergeMe& copy);
	
	// Destructors
		~PmergeMe();
	
	// Public methods
		bool isDoppelGanger();
		long calculateJacobsthal(int i, std::vector<unsigned long long> &jacob);
		long calculateJacobsthalD( int i, std::deque<unsigned long long> &jacob);
		void sortMe();
		void sortMeD();
		void printTab();
		void printTime();
};

// Functions
	void error(std::string str);
	bool isAllDigit(char **argv);
