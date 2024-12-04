/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:15:12 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/03 17:45:55 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{
	private:
	// Data
		const std::string name;
		int	grade;
	
	// Setters
		void setGrade(int grade);

	public:
	// Constructors
		Bureaucrat();
		Bureaucrat(int grade);
		Bureaucrat(const std::string name);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat(const std::string name, int grade);
	
	// Destructors
		~Bureaucrat();
	
	// Operator overloads
		Bureaucrat& operator = (const Bureaucrat& copy);
	
	// Member functions
		void upGrade(void);
		void downGrade(void);
	// Getters
		const std::string getName(void) const;
		int getGrade(void) const;
};

// Ostream overload
	std::ostream& operator << (std::ostream &to, Bureaucrat *thing);

#endif
