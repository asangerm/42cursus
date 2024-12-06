/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:18:59 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/07 00:37:13 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
	// Data
		bool		sign;
		const int	signGrade;
		const int	execGrade;
		const std::string	name;

	public:
	// Constructors
		Form();
		Form(const Form& copy);
		Form(const std::string name);
		Form(int signGrade, int execGrade);
		Form(const std::string name, int signGrade, int execGrade);
	
	// Destructors
		~Form();
	
	// Operator overloads
		Form& operator = (const Form& copy);
	
	// Member functions
		void beSigned(Bureaucrat &signer);

	// Getters
		bool getSign(void)const;
		int getSignGrade(void)const;
		int getExecGrade(void)const;
		const std::string getName(void)const;
	
	//Exceptions
		class GradeTooLowException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};
};

// Ostream overload
	std::ostream& operator << (std::ostream &to, Form *thing);

#endif