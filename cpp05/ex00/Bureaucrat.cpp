/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:15:21 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/06 17:10:08 by asangerm         ###   ########.fr       */
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

	Bureaucrat::Bureaucrat(int grade) : name ("Default")
	{
		std::cout
		<< "Bureaucrat constructor called with name: "
		<< this->getName()
		<< " and grade: "
		<< grade
		<< std::endl;

		try
		{
			this->setGrade(grade);
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr
			<< "Constructing "
			<< this->getName()
			<< " failed: "
			<< e.what()
			<< std::endl
			<< "Grade set to 150"
			<< std::endl;
			this->setGrade(150);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr
			<< "Constructing "
			<< this->getName()
			<< " failed: "
			<< e.what()
			<< std::endl
			<< "Grade set to 150"
			<< std::endl;
			this->setGrade(150);
		}
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

	Bureaucrat::Bureaucrat(const Bureaucrat& copy) : name(copy.name)
	{
		*this = copy;
		std::cout
		<< "Bureaucrat copy constructor called with name: "
		<< this->getName()
		<< " and grade: "
		<< this->getGrade()
		<< std::endl;
	}

	Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
	{
		std::cout
		<< "Bureaucrat constructor called with name: "
		<< this->getName()
		<< " and grade: "
		<< grade
		<< std::endl;

		try
		{
			this->setGrade(grade);
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr
			<< "Constructing "
			<< this->getName()
			<< " failed: "
			<< e.what()
			<< std::endl
			<< "Grade set to 150"
			<< std::endl;
			this->setGrade(150);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr
			<< "Constructing "
			<< this->getName()
			<< " failed: "
			<< e.what()
			<< std::endl
			<< "Grade set to 150"
			<< std::endl;
			this->setGrade(150);
		}
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
		std::cout
		<< "Overload Operator = called"
		<< std::endl;
		return *this;
	}

	
// Member functions
	void Bureaucrat::upGrade(void)
	{
		try
		{
			std::cout
			<< "Trying to upgrade "
			<< this->getName()
			<< std::endl;
			this->setGrade(this->grade - 1);
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr
			<< "Upgrading "
			<< this->getName()
			<< " failed: "
			<< e.what()
			<< std::endl;
		}
	}

	void Bureaucrat::downGrade(void)
	{
		try
		{
			std::cout
			<< "Trying to downgrade "
			<< this->getName()
			<< std::endl;
			this->setGrade(this->grade + 1);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr
			<< "Downgrading "
			<< this->getName()
			<< " failed: "
			<< e.what()
			<< std::endl;
		}
	}


// Getters
	const std::string Bureaucrat::getName(void) const
	{
		return (this->name);
	}

	int Bureaucrat::getGrade(void) const
	{
		return (this->grade);
	}


// Setters
	void Bureaucrat::setGrade(int grade)
	{
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else
			this->grade = grade;
	}

// Exceptions
	const char *Bureaucrat::GradeTooLowException::what(void) const throw()
	{
		return ("Grade too low");
	};

	const char *Bureaucrat::GradeTooHighException::what(void) const throw()
	{
		return ("Grade too high");
	};

// Ostream overload
	std::ostream& operator << (std::ostream &to, Bureaucrat *thing)
	{
		to
		<< thing->getName()
		<< ", bureaucrat grade "
		<< thing->getGrade()
		<< std::endl;
		return (to);
	}
