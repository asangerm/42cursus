/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:07:56 by asangerm          #+#    #+#             */
/*   Updated: 2024/10/02 21:21:01 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Constructors
	DiamondTrap::DiamondTrap(): ClapTrap("default_clap_trap")
	{
		this->name = "default";
		this->health = FragTrap::health;
		this->energy = ScavTrap::energy;
		this->damage = FragTrap::damage;
		std::cout
		<< "DiamondTrap Default Constructor called"	<< std::endl;
	}

	DiamondTrap::DiamondTrap(const DiamondTrap& copy): ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
	{
		*this = copy;
		std::cout
		<< "DiamondTrap Copy Constructor called"	<< std::endl;
	}

	DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_trap")
	{
		this->name = name;
		this->health = FragTrap::health;
		this->energy = ScavTrap::energy;
		this->damage = FragTrap::damage;
		std::cout
		<< "DiamondTrap Constructor for "	<< this->name
		<< " called"						<< std::endl;
	}

// Destructors
	DiamondTrap::~DiamondTrap()
	{
		std::cout
		<< "DiamondTrap Deconstructor for "	<< this->name
		<< " called"						<< std::endl;
	}

// Operator overloads
	DiamondTrap &DiamondTrap::operator=(const DiamondTrap& src)
	{
		this->name = src.name + "_clap_trap";
		this->health = src.health;
		this->energy = src.energy;
		this->damage = src.damage;
		std::cout
		<< "DiamondTrap operator overload = called"	<< std::endl;
		return *this;
	}

// Member functions
	void	DiamondTrap::attack(const std::string& target)
	{
		ScavTrap::attack(target);
	}

	void	DiamondTrap::whoAmI(void)
	{
		std::cout
		<< "I am a DiamondTrap "				<< this->name
		<< ", i am a subobject of ClapTrap "	<< ClapTrap::name
		<< std::endl;
	}