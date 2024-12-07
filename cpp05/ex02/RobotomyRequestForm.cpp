/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:25:46 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/07 19:02:26 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include "RobotomyRequestForm.hpp"

// Constructors
	RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy request form", 72, 45)
	{
		std::srand((unsigned)std::time(0));
		this->target = "default";
	}

	RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy request form", 72, 45)
	{
		std::srand((unsigned)std::time(0));
		this->target = target;
	}

	RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm("Robotomy request form", 72, 45)
	{
		std::srand((unsigned)std::time(0));
		*this = copy;
	}

// Destructors
	RobotomyRequestForm::~RobotomyRequestForm()
	{
		
	}

// Operator overloads
	RobotomyRequestForm &RobotomyRequestForm::operator = (RobotomyRequestForm const &copy)
	{
		this->target = copy.target;
		return (*this);
	}

// Member functions
	void RobotomyRequestForm::executeAction() const
	{
		int random;
		
		random = std::rand() % 2;
	
		std::cout
		<< "Drilling Noises"
		<< std::endl;

		if (random == 0)
		{
			std::cout
			<< this->target
			<< " has been robotomized"
			<< std::endl;
		}
		else
		{
			std::cout
			<< "Robotomy on "
			<< this->target
			<< " has failed"
			<< std::endl;
		}
	}
