/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:39:43 by asangerm          #+#    #+#             */
/*   Updated: 2024/09/24 18:10:13 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors
	ClapTrap::ClapTrap() : name("Default"), health(10), energy(10), damage(0)
	{
		std::cout
		<< "ClapTrap default constructor called"	<< std::endl;
	}

	ClapTrap::ClapTrap(std::string name) : name(name), health(10), energy(10), damage(0)
	{
		std::cout
		<< "ClapTrap name constructor called for "	<< name
		<< std::endl;
	}

	ClapTrap::ClapTrap(const ClapTrap& copy)
	{
		std::cout
		<< "ClapTrap copy constructor called for "	<< copy.name
		<< std::endl;
		*this = copy;
	}

// Destructors
	ClapTrap::~ClapTrap()
	{
		std::cout
		<< "ClapTrap destructor called"	<< std::endl;
	}
// Operator overload
	ClapTrap& ClapTrap::operator = (const ClapTrap &src)
	{
		std::cout
		<< "ClapTrap operator overload = called"	<< std::endl;
		this->name = src.name;
		this->health = src.health;
		this->energy = src.energy;
		this->damage = src.damage;
		return *this;
	}

// Member functions
	void	ClapTrap::attack(const std::string& target)
	{
		if (this->energy > 0 && this->damage > 0)
		{
			std::cout
			<< "ClapTrap "			<< this->name
			<< " attacks "			<< target
			<< ", causing "			<< this->damage
			<< " points of damage!" << std::endl;
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

	void	ClapTrap::takeDamage(unsigned int amount)
	{
		if (this->health > amount)
		{
			this->health -= amount;
			std::cout
			<< "ClapTrap "							<< this->name
			<< " lost "								<< amount
			<< " hit points, his life is now about "<< this->health
			<< std::endl;
		}
		else if (this->health > 0)
		{
			this->health = 0;
			std::cout
			<< "ClapTrap "					<< this->name
			<< " lost " 					<< amount - this->health
			<< " hit points and died... RIP"<< std::endl;
		}
		else
			std::cout
			<< "ClapTrap "		<< this->name
			<< " already dead"	<< std::endl;
	}

	void	ClapTrap::beRepaired(unsigned int amount)
	{
		if (this->energy > 0 && this->health > 0 && this->health < 10)
		{
			this->health += amount;
			if (this ->health > 10)
				this->health = 10;
			this->energy--;
			std::cout
			<< "ClapTrap "					<< this->name
			<< " restore "					<< amount
			<< " hit points and now have "	<< this->health
			<< " hit points."				<< std::endl;
		}
		else if (this->energy == 0)
			std::cout
			<< "ClapTrap " 							<< this->name
			<< " can't restore him, out of energy"	<< std::endl;
		else if (this->health == 0)
			std::cout
			<< "ClapTrap "						<< this->name
			<< " can't restore him, he is dead" << std::endl;
		else
			std::cout
			<< "ClapTrap "		<< this->name
			<< " is already full life"	<< std::endl;
	}	

