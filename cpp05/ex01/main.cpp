/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:10:39 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/07 00:45:04 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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

	Form h;
	Form i("job");
	Form j(100, 50);
	Form k("supervisor", 20, 10);
	Form l(i);
	//Form m(2000, 50);

	//b.signForm(j);
	d.signForm(j);

	std::cout << &h;
	std::cout << &i;
	std::cout << &j;
	std::cout << &k;
	std::cout << &l;
	//std::cout << &m;
	
	return 0;
}