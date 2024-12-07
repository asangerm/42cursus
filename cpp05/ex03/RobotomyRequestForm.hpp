/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:25:34 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/07 23:16:32 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP 

# include <string>
# include <iostream>
# include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
	// Data
		std::string target;

	public:
	// Constructors
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &copy);
	
	// Destructors
		~RobotomyRequestForm();

	// Operator overloads
		RobotomyRequestForm &operator = (RobotomyRequestForm const &copy);

	// Member functions
		void executeAction() const;
		AForm *clone(std::string target) const;
};

#endif