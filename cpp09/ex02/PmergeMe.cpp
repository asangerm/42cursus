/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:13:51 by asangerm          #+#    #+#             */
/*   Updated: 2025/02/13 18:11:23 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Constructors
	PmergeMe::PmergeMe()
	{
	}

	PmergeMe::PmergeMe(const PmergeMe& copy)
	{
		*this = copy;
	}

	PmergeMe::PmergeMe(char** argv)
	{
		size_t i = 1;
		while (argv[i])
		{
			this->tab.push_back(std::atoi(argv[i]));
			i++;
		}
	}
	
// Operator overload
	PmergeMe& PmergeMe::operator = (const PmergeMe& copy)
	{
		this->tab = copy.tab;
		return *this;
	}

// Destructors
	PmergeMe::~PmergeMe()
	{
	}

// Public methods
	bool PmergeMe::isDoppelGanger()
	{
		std::set<int> seen;
		for (size_t i = 0; i < this->tab.size(); ++i)
		{
			if (seen.find(this->tab[i]) != seen.end())
				return true;
			seen.insert(this->tab[i]);
		}
    	return false;
	}

	long    PmergeMe::calculateJacobsthal( int i, std::vector<unsigned long long> &jacob)
	{
		if (i == 0)
			return 0;
		else if (i == 1)
			return 1;
		return ( jacob[i - 1] + (2 * jacob[i - 2]) );
	}

	void PmergeMe::sortMe()
	{
		this->start = std::clock();
		bool isit = false;
		int index = 0;
		if (this->tab.size() % 2 != 0)
		{
			isit = true;
			index = *(this->tab.end() - 1);
			this->tab.pop_back();
		}

		std::vector<std::pair<int, int> > pairedVector;
		for (typename std::vector<int>::iterator it = this->tab.begin(); it != this->tab.end(); ++it)
		{
			int maxi = *it;
			int mini = *(++it);
			if (maxi < mini)
				std::swap(maxi, mini);
			pairedVector.push_back(std::make_pair(maxi, mini));
		}

		std::vector<int> bigNumbers;
		std::vector<int> smallNumbers;

		for (std::vector<std::pair<int, int> >::iterator it = pairedVector.begin(); it != pairedVector.end(); ++it)
		{
			int big = it->first;
			int small = it->second;
			
			bigNumbers.push_back(big);
			smallNumbers.push_back(small);
		}

		std::sort(bigNumbers.begin(), bigNumbers.end());

		std::vector< unsigned long long > jacob;
		int n = smallNumbers.size();
		
		for (int i = 0; i < n; ++i)
		{	
			unsigned long long jacobsthal = calculateJacobsthal(i, jacob);
			jacob.push_back(jacobsthal);
		}

		for (size_t i = 0; i < jacob.size(); ++i)
		{
			std::vector<int>::iterator insertPos = std::lower_bound(bigNumbers.begin(), bigNumbers.end(), smallNumbers[i]);
			bigNumbers.insert(insertPos, smallNumbers[i]);
		}

		if (isit)
		{
			std::vector<int>::iterator pos = std::lower_bound(bigNumbers.begin(), bigNumbers.end(), index);
			bigNumbers.insert(pos, index);
		}

		this->tab = bigNumbers;
		this->end = std::clock();
	}

	void PmergeMe::printTab()
	{
		for (std::vector<int>::iterator it = this->tab.begin(); it != this->tab.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	void PmergeMe::printTime()
	{
		std::cout << static_cast<double>(this->end - this->start) / CLOCKS_PER_SEC;
	}

// Functions
	void error(std::string str)
	{
		std::cout << "Error: " << str << std::endl;
	}

	bool isAllDigit(char **argv)
	{
		size_t i = 1;
		while (argv[i])
		{
			int j = 0;
			while (argv[i][j])
			{
				if (!std::isdigit(argv[i][j]))
					return false;
				j++;
			}
			i++;
		}
		return true;
	}