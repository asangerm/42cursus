/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:18:59 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/07 23:15:45 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
	// Data
		bool		sign;
		const int	signGrade;
		const int	execGrade;
		const std::string	name;

	public:
	// Constructors
		AForm();
		AForm(const AForm& copy);
		AForm(const std::string name);
		AForm(int signGrade, int execGrade);
		AForm(const std::string name, int signGrade, int execGrade);
	
	// Destructors
		~AForm();
	
	// Operator overloads
		AForm& operator = (const AForm& copy);
	
	// Member functions
		void beSigned(Bureaucrat &signer);
		void execute(Bureaucrat const &exec) const;
		virtual void executeAction() const = 0;
		virtual AForm *clone(std::string target) const = 0;

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
		class FormNotSignedException : public std::exception
		{
		public :
			virtual const char *what() const throw();
		};
		class FormAlreadySignedException : public std::exception
		{
		public :
			virtual const char *what() const throw();
		};
};

// Ostream overload
	std::ostream& operator << (std::ostream &to, AForm *thing);

#endif