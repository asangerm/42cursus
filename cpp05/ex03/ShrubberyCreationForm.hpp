/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:25:03 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/07 23:16:39 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP 

# include <string>
# include <iostream>
# include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	private:
	// Data
		std::string target;

	public:
	// Constructors
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &copy);
	
	// Destructors
		~ShrubberyCreationForm();

	// Operator overloads
		ShrubberyCreationForm &operator = (ShrubberyCreationForm const &copy);

	// Member functions
		void executeAction() const;
		AForm *clone(std::string target) const;
};

#endif