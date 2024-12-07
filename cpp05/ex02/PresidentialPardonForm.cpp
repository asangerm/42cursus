/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:26:18 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/07 19:13:09 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Constructors
	PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential pardon form", 25, 5)
	{
		this->target = "default";
	}

	PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential pardon form", 25, 5)
	{
		this->target = target;
	}

	PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : AForm("Presidential pardon form", 25, 5)
	{
		*this = copy;
	}

// Destructors
	PresidentialPardonForm::~PresidentialPardonForm()
	{

	}

// Operator overloads
	PresidentialPardonForm &PresidentialPardonForm::operator = (PresidentialPardonForm const &copy)
	{
		this->target = copy.target;
		return *this;
	}

// Member functions
	void PresidentialPardonForm::executeAction() const
	{
		std::cout
		<< this->target
		<< " has been pardoned by Zaphod Beeblebrox."
		<< std::endl;
	}