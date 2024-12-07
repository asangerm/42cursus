/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:19:12 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/07 18:25:29 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Constructors
	AForm::AForm() : name("Default"), sign(false), signGrade(150), execGrade(150)
	{
		std::cout
		<< "AForm default constructor called with name: "
		<< this->getName()
		<< ", sign grade: "
		<< this->getSignGrade()
		<< ", exec grade: "
		<< this->getExecGrade()
		<< " and sign bool: "
		<< this->getSign()
		<< std::endl;
	}

	AForm::AForm(const AForm& copy) : name(copy.getName() + "_copy"), signGrade(copy.getSignGrade()), execGrade(copy.getExecGrade())
	{
		*this = copy;
		std::cout
		<< "AForm copy constructor called with name: "
		<< this->getName()
		<< ", sign grade: "
		<< this->getSignGrade()
		<< ", exec grade: "
		<< this->getExecGrade()
		<< " and sign bool: "
		<< this->getSign()
		<< std::endl;
	}

	AForm::AForm(const std::string name) : name(name), sign(false), signGrade(150), execGrade(150)
	{
		std::cout
		<< "AForm constructor called with name: "
		<< this->getName()
		<< ", sign grade: "
		<< this->getSignGrade()
		<< ", exec grade: "
		<< this->getExecGrade()
		<< " and sign bool: "
		<< this->getSign()
		<< std::endl;
	}

	AForm::AForm(const int signGrade, const int execGrade) : name("Default"), sign(false), signGrade(signGrade), execGrade(execGrade)
	{
		std::cout
		<< "AForm constructor called with name: "
		<< this->getName()
		<< ", sign grade: "
		<< signGrade
		<< ", exec grade: "
		<< execGrade
		<< " and sign bool: "
		<< this->getSign()
		<< std::endl;
	
		if (this->getSignGrade() > 150 || this->getExecGrade() > 150)
			throw(AForm::GradeTooLowException());
		else if( this->getSignGrade() < 1 || this->getExecGrade() < 1)
			throw(AForm::GradeTooHighException());
	}

	AForm::AForm(const std::string name, const int signGrade, const int execGrade) : name(name), sign(false), signGrade(signGrade), execGrade(execGrade)
	{
		std::cout
		<< "AForm constructor called with name: "
		<< this->getName()
		<< ", sign grade: "
		<< signGrade
		<< ", exec grade: "
		<< execGrade
		<< " and sign bool: "
		<< this->getSign()
		<< std::endl;

		if (this->getSignGrade() > 150 || this->getExecGrade() > 150)
			throw(AForm::GradeTooLowException());
		else if( this->getSignGrade() < 1 || this->getExecGrade() < 1)
			throw(AForm::GradeTooHighException());
	}

	
// Destructors
	AForm::~AForm()
	{
		std::cout
		<< "AForm destructor called for name: "
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
	AForm& AForm::operator = (const AForm& copy)
	{
		this->sign = copy.getSign();
		std::cout
		<< "Overload Operator = called"
		<< std::endl;
		return *this;
	}

	
// Member functions
	void AForm::beSigned(Bureaucrat &signer)
	{
		if (signer.getGrade() > this->getSignGrade())
			throw(AForm::GradeTooLowException());
		else if (this->getSign() == false)
		{
			this->sign = true;
			std::cout
			<< this->getName()
			<< " AForm was signed by "
			<< signer.getName()
			<< std::endl;
		}
		else
			throw(AForm::FormAlreadySignedException());
	}

	void AForm::execute(Bureaucrat const &exec) const
	{
		if (this->getSign() == false)
		{
			throw(AForm::FormNotSignedException());
			return;
		}
		else if (exec.getGrade() > this->getExecGrade())
		{
			throw(AForm::GradeTooLowException());
			return;
		}
		executeAction();
	}

// Getters
	bool AForm::getSign(void)const
	{
		return(this->sign);
	}

	int AForm::getSignGrade(void)const
	{
		return(this->signGrade);
	}

	int AForm::getExecGrade(void)const
	{
		return(this->execGrade);
	}

	const std::string AForm::getName(void)const
	{
		return(this->name);
	}

//Exceptions
	const char *AForm::GradeTooLowException::what(void) const throw()
	{
		return ("Grade too low");
	};

	const char *AForm::GradeTooHighException::what(void) const throw()
	{
		return ("Grade too high");
	};

	const char *AForm::FormNotSignedException::what() const throw()
	{
		return ("Form is not signed");
	}

	const char *AForm::FormAlreadySignedException::what() const throw()
	{
		return ("Form is already signed");
	}

// Ostream overload
	std::ostream& operator << (std::ostream &to, AForm *thing)
	{
		to
		<< "AForm "
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
