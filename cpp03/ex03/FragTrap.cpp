/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:35:30 by asangerm          #+#    #+#             */
/*   Updated: 2024/10/02 22:04:52 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructors
	FragTrap::FragTrap(): ClapTrap()
	{
		this->health = 100;
		this->energy = 100;
		this->damage = 30;
		std::cout
		<< "FragTrap Default Constructor called"	<< std::endl;
	}

	FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
	{
		std::cout
		<< "FragTrap Copy Constructor called"	<< std::endl;
	}

	FragTrap::FragTrap(std::string name): ClapTrap(name)
	{
		this->health = 100;
		this->energy = 100;
		this->damage = 30;
		std::cout
		<< "FragTrap Constructor for "	<< this->name
		<< " called" 					<< std::endl;
	}

// Destructors
	FragTrap::~FragTrap()
	{
		std::cout
		<< "FragTrap Destructor for "	<< this->name
		<< " called"					<< std::endl;
	}

// Operator overloads
	FragTrap&	FragTrap::operator = (const FragTrap &src)
	{
		this->name = src.name;
		this->health = src.health;
		this->energy = src.energy;
		this->damage = src.damage;
		std::cout
		<< "FragTrap operator overload = called"	<< std::endl;
		return *this;
	}

// Member functions
	void	FragTrap::highFiveGuys(void)
	{
		std::cout
		<< "FragTrap "			<< this->name
		<< "wants a high five"	<< std::endl;
	}
