/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:10:39 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/08 00:20:54 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main(void)
{	
	Bureaucrat *a = new Bureaucrat("King", 1);
	Intern *c = new Intern();
	AForm *b = c->makeForm("Robotomy Request Form", "Robot");

	a->signForm(*b);
	b->execute(*a);

	delete a;
	delete b;
	delete c;

	return 0;
}