/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:14:14 by asangerm          #+#    #+#             */
/*   Updated: 2024/09/06 15:38:45 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	sentence = "HI THIS IS BRAIN";
	std::string	*ptr;
	std::string	&ref = sentence;

	ptr = &sentence;
	std::cout << &sentence << std::endl;
	std::cout << ptr << std::endl;
	std::cout << &ref << std::endl;
	std::cout << sentence << std::endl;
	std::cout << *ptr << std::endl;
	std::cout << ref << std::endl;
}