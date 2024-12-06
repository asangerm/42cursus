/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:19:12 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/07 00:44:02 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructors
	Form::Form() : name("Default"), sign(false), signGrade(150), execGrade(150)
	{
		std::cout
		<< "Form default constructor called with name: "
		<< this->getName()
		<< ", sign grade: "
		<< this->getSignGrade()
		<< ", exec grade: "
		<< this->getExecGrade()
		<< " and sign bool: "
		<< this->getSign()
		<< std::endl;
	}

	Form::Form(const Form& copy) : name(copy.getName() + "_copy"), signGrade(copy.getSignGrade()), execGrade(copy.getExecGrade())
	{
		*this = copy;
		std::cout
		<< "Form copy constructor called with name: "
		<< this->getName()
		<< ", sign grade: "
		<< this->getSignGrade()
		<< ", exec grade: "
		<< this->getExecGrade()
		<< " and sign bool: "
		<< this->getSign()
		<< std::endl;
	}

	Form::Form(const std::string name) : name(name), sign(false), signGrade(150), execGrade(150)
	{
		std::cout
		<< "Form constructor called with name: "
		<< this->getName()
		<< ", sign grade: "
		<< this->getSignGrade()
		<< ", exec grade: "
		<< this->getExecGrade()
		<< " and sign bool: "
		<< this->getSign()
		<< std::endl;
	}

	Form::Form(const int signGrade, const int execGrade) : name("Default"), sign(false), signGrade(signGrade), execGrade(execGrade)
	{
		std::cout
		<< "Form constructor called with name: "
		<< this->getName()
		<< ", sign grade: "
		<< signGrade
		<< ", exec grade: "
		<< execGrade
		<< " and sign bool: "
		<< this->getSign()
		<< std::endl;
	
		if (this->getSignGrade() > 150 || this->getExecGrade() > 150)
			throw(Form::GradeTooLowException());
		else if( this->getSignGrade() < 1 || this->getExecGrade() < 1)
			throw(Form::GradeTooHighException());
	}

	Form::Form(const std::string name, const int signGrade, const int execGrade) : name(name), sign(false), signGrade(signGrade), execGrade(execGrade)
	{
		std::cout
		<< "Form constructor called with name: "
		<< this->getName()
		<< ", sign grade: "
		<< signGrade
		<< ", exec grade: "
		<< execGrade
		<< " and sign bool: "
		<< this->getSign()
		<< std::endl;

		if (this->getSignGrade() > 150 || this->getExecGrade() > 150)
			throw(Form::GradeTooLowException());
		else if( this->getSignGrade() < 1 || this->getExecGrade() < 1)
			throw(Form::GradeTooHighException());
	}

	
// Destructors
	Form::~Form()
	{
		std::cout
		<< "Form destructor called for name: "
		<< this->getName()
		<< ", sign grade: "
		<< this->getSignGrade()
		<< ", exec grade: "
		<< this->getExecGrade()
		<< " and sign bool: "
		<< this->getSign()
		<< std::endl;
	}

	
// Operator overloads
	Form& Form::operator = (const Form& copy)
	{
		this->sign = copy.getSign();
		std::cout
		<< "Overload Operator = called"
		<< std::endl;
		return *this;
	}

	
// Member functions
	void Form::beSigned(Bureaucrat &signer)
	{
		if (signer.getGrade() > this->getSignGrade())
			throw(Bureaucrat::GradeTooLowException());
		else if (this->getSign() == false)
		{
			this->sign = true;
			std::cout
			<< this->getName()
			<< " Form was signed by "
			<< signer.getName()
			<< std::endl;
		}
		else
			std::cout
			<< this->getName()
			<< " Form is already signed"
			<< std::endl;
	}


// Getters
	bool Form::getSign(void)const
	{
		return(this->sign);
	}

	int Form::getSignGrade(void)const
	{
		return(this->signGrade);
	}

	int Form::getExecGrade(void)const
	{
		return(this->execGrade);
	}

	const std::string Form::getName(void)const
	{
		return(this->name);
	}

//Exceptions
	const char *Form::GradeTooLowException::what(void) const throw()
	{
		return ("Grade too low");
	};

	const char *Form::GradeTooHighException::what(void) const throw()
	{
		return ("Grade too high");
	};

// Ostream overload
	std::ostream& operator << (std::ostream &to, Form *thing)
	{
		to
		<< "Form "
		<< thing->getName()
		<< ":\n signGrade: "
		<< thing->getSignGrade()
		<< "\n execGrade: "
		<< thing->getExecGrade()
		<< "\n is signed: "
		<< thing->getSign()
		<< std::endl;
		return (to);
	}
