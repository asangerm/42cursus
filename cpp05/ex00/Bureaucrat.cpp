/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:15:21 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/03 18:15:24 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructors
	Bureaucrat::Bureaucrat() : name("Default"), grade(150)
	{
		std::cout
		<< "Bureaucrat default constructor called with name: "
		<< this->getName()
		<< " and grade: "
		<< this->getGrade()
		<< std::endl;
	}

	Bureaucrat::Bureaucrat(int grade) : name ("Default"), grade(grade)
	{
		std::cout
		<< "Bureaucrat constructor called with name: "
		<< this->getName()
		<< " and grade: "
		<< this->getGrade()
		<< std::endl;
	}

	Bureaucrat::Bureaucrat(const std::string name) : name(name), grade(150)
	{
		std::cout
		<< "Bureaucrat constructor called with name: "
		<< this->getName()
		<< " and grade: "
		<< this->getGrade()
		<< std::endl;
	}

	Bureaucrat::Bureaucrat(const Bureaucrat& copy)
	{
		*this = copy;
		std::cout
		<< "Bureaucrat copy constructor called with name: "
		<< this->getName()
		<< " and grade: "
		<< this->getGrade()
		<< std::endl;
	}

	Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
	{
		std::cout
		<< "Bureaucrat constructor called with name: "
		<< this->getName()
		<< " and grade: "
		<< this->getGrade()
		<< std::endl;
	}

	
// Destructors
	Bureaucrat::~Bureaucrat()
	{
		std::cout
		<< "Bureaucrat destructor called with name: "
		<< this->getName()
		<< " and grade: "
		<< this->getGrade()
		<< std::endl;
	}

	
// Operator overloads
	Bureaucrat& Bureaucrat::operator = (const Bureaucrat& copy)
	{
		this->grade = copy.getGrade();
		this->name = copy.getName;
		std::cout
		<< "Overload Operator = called"
		<< std::endl;
		return *this;
	}

	
// Member functions
	void Bureaucrat::upGrade(void)
	{

	}

	void Bureaucrat::downGrade(void)
	{

	}


// Getters
	const std::string Bureaucrat::getName(void) const
	{

	}

	int Bureaucrat::getGrade(void) const
	{

	}


// Setters
	void Bureaucrat::setGrade(int grade)
	{

	}


// Ostream overload
	std::ostream& operator << (std::ostream &to, Bureaucrat *thing)
	{
		
	}
