/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:04:05 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/07 23:54:12 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class AForm;

class Intern
{
	private:
	// Data

	// Setters

	public:
	// Constructors
		Intern();
		Intern(const Intern& copy);
	
	// Destructors
		~Intern();
	
	// Operator overloads
		Intern& operator = (const Intern& copy);
	
	// Member functions
		AForm *makeForm(std::string name, std::string target);

	// Getters
	
	//Exceptions
		class FormNotFoundException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

// Ostream overload

#endif