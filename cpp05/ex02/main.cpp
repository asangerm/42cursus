/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:10:39 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/07 19:24:58 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat a;
	Bureaucrat b(150);
	Bureaucrat c("Daniel");
	Bureaucrat d("Nigel", 1);
	Bureaucrat e(d);
	Bureaucrat g(200);

	b.downGrade();
	b.upGrade();
	d.upGrade();
	d.downGrade();

	std::cout << &a;
	std::cout << &b;
	std::cout << &c;
	std::cout << &d;
	std::cout << &e;
	std::cout << &g;

	ShrubberyCreationForm	home("home");
    RobotomyRequestForm		robot("Le robot");
    PresidentialPardonForm	pardon("Macron");

	d.signForm(home);
	d.signForm(robot);
	d.signForm(pardon);
	d.executeForm(home);
	d.executeForm(robot);
	d.executeForm(pardon);
	
	return 0;
}