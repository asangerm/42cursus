/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:04:21 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/08 00:13:43 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// Constructors
	Intern::Intern(void)
	{
	}

	Intern::Intern(Intern const &copy)
	{
		*this = copy;
	}

	Intern::~Intern()
	{
	}

	Intern& Intern::operator = (Intern const & copy)
	{
		(void) copy;
		return *this;
	}

	static AForm	*makePresident(const std::string target)
	{
		return (new PresidentialPardonForm(target));
	}

	static AForm	*makeRobot(const std::string target)
	{
		return (new RobotomyRequestForm(target));
	}

	static AForm	*makeShrubbery(const std::string target)
	{
		return (new ShrubberyCreationForm(target));
	}

	AForm *Intern::makeForm(std::string name, std::string target)
	{
		AForm *(*_forms[])(const std::string target) = {&makePresident, &makeRobot, &makeShrubbery};
		std::string forms[] = {"Presidential Pardon Form", "Robotomy Request Form", "Shrubbery Creation Form"};

		for (int i = 0; i < 3; i++)
		{
			if (name == forms[i])
			{
				std::cout
				<< "Intern creates "
				<< name
				<< std::endl;
				return (_forms[i](target));
			}
		}
		throw Intern::FormNotFoundException();
		return (NULL);
	}

	const char *Intern::FormNotFoundException::what() const throw()
	{
		return ("Form type not found");
	}