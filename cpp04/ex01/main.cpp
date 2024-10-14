/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 23:26:29 by asangerm          #+#    #+#             */
/*   Updated: 2024/10/14 17:09:50 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal	*animals[4];

	animals[0] = new Cat();
	animals[1] = new Dog();
	animals[2] = new Cat();
	animals[3] = new Dog();

	for (int i = 0; i < 4; i++)
		delete animals[i];

	Dog	*d = new Dog();

	d->getBrain()->setIdea(0, "Eat");
	d->getBrain()->setIdea(1, "Sleep");
	std::cout << d->getBrain()->getIdea(0) << std::endl;

	delete d;
	return 0;
}
