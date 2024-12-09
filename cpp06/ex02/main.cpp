/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:17:42 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/09 17:28:17 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	int	i = rand() % 3;

	switch (i)
	{
		case (0): return new A();
		case (1): return new B();
		default: return new C();
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "NOT A" << std::endl;
	}
	
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "NOT B" << std::endl;
	}
	
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "NOT C" << std::endl;
	}
}

int	main(void)
{
	std::srand(static_cast<unsigned int>(time(0)));

	Base *random = generate();

	std::cout << "identify pointer" << std::endl;
	identify(random);
	std::cout << std::endl;
	std::cout << "identify reference" << std::endl;
	identify(*random);
	return (0);
}