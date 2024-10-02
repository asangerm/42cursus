/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:11:23 by asangerm          #+#    #+#             */
/*   Updated: 2024/09/26 18:00:33 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructors
	ScavTrap::ScavTrap() : ClapTrap()
	{
		this->energy = 50;
		this->health = 100;
		this->damage = 20;
		this->guard = false;
		std::cout
		<< "ScavTrap default constructor called"	<< std::endl;
	}

	ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
	{
		this->health = 100;
		this->energy = 50;
		this->damage = 20;
		this->guard = false;
		std::cout
		<< "ScavTrap name constructor called for "	<< name
		<< std::endl;
	}

	ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
	{
		this->guard = copy.guard;
		std::cout
		<< "ScavTrap copy constructor called for "	<< copy.name
		<< std::endl;
	}

// Destructors
	ScavTrap::~ScavTrap()
	{
		std::cout
		<< "ScavTrap destructor called"	<< std::endl;
	}

// Operator overload
	ScavTrap& ScavTrap::operator = (const ScavTrap &src)
	{
		this->name   = src.name;
		this->health = src.health;
		this->energy = src.energy;
		this->damage = src.damage;
		this->guard  = src.guard;
		std::cout
		<< "ScavTrap operator overload = called"	<< std::endl;
		return *this;
	}

// Member functions
	void	ScavTrap::attack(const std::string &target)
	{
		if (this->energy > 0 && this->damage > 0)
		{
			std::cout
			<< "ScavTrap "			<< this->name
			<< " attacks "			<< target
			<< ", causing "			<< this->damage
			<< " points of damage!"	<< std::endl;
			this->energy--;
		}
		else if (this->damage == 0)
			std::cout
			<< "ClapTrap "							<< this->name
			<< " not able to make any damage to "	<< target
			<< std::endl;
		else
			std::cout
			<< "ClapTrap "				<< this->name
			<< " not able to attack "	<< target
			<< ", it is out of energy"	<< std::endl;
	}

	void	ScavTrap::guardGate(void)
	{
		if (this->guard == false)
		{
			this->guard = true;
			std::cout
			<< "ScavTrap "				<< this->name
			<< " is guarding the gate."	<< std::endl;
		}
		else
			std::cout
			<< "ScavTrap "						<< this->name
			<< " already guarding the gate."	<< std::endl;
	}