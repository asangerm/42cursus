/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:26:06 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/07 23:27:09 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP 

# include <string>
# include <iostream>
# include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:
	// Data
		std::string target;

	public:
	// Constructors
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &copy);
	
	// Destructors
		~PresidentialPardonForm();

	// Operator overloads
		PresidentialPardonForm &operator = (PresidentialPardonForm const &copy);

	// Member functions
		void executeAction() const;
		AForm *clone(std::string target) const;
};

#endif