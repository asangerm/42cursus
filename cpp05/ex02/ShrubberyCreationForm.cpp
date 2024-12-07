/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:25:14 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/07 19:10:07 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "ShrubberyCreationForm.hpp"

// Constructors
	ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery creation form", 145, 137)
	{
		this->target = "default";
	}

	ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :  AForm("Shrubbery creation form", 145, 137)
	{
		this->target = target;
	}

	ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm("Shrubbery creation form", 145, 137)
	{
		*this = copy;
	}

// Destructors
	ShrubberyCreationForm::~ShrubberyCreationForm()
	{

	}

// Operator overload
	ShrubberyCreationForm &ShrubberyCreationForm::operator = (ShrubberyCreationForm const &copy)
	{
		this->target = copy.target;
		return *this;
	}

// Member functions
	void ShrubberyCreationForm::executeAction() const
	{
		std::fstream file;
		std::string filename = this->target + "_shrubbery";
		file.open(filename.c_str(), std::fstream::out);

		if (!file.is_open())
		{
			std::cerr
			<< "Error: Impossible to open file "
			<< this->target + "_shrubbery"
			<< std::endl;
			return;
		}

		file << "   ^   " << std::endl;
		file << "  ^^^  " << std::endl;
		file << " ^^^^^ " << std::endl;
		file << "^^^^^^^" << std::endl;
		file << "   |   " << std::endl;
		file << "   |   " << std::endl;
		file.close();
	}