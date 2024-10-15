/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:38:46 by asangerm          #+#    #+#             */
/*   Updated: 2024/10/15 20:44:44 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Constructors
	Character::Character() : name("Default")
	{
		for (int i = 0; i < 4; i++)
			this->inventory[i] = nullptr;
		std::cout
		<< "Character default constructor called"
		<< std::endl;
	}

	Character::Character(const std::string& name) : name(name)
	{
		for (int i = 0; i < 4; i++)
			this->inventory[i] = nullptr;
		std::cout
		<< "Character constructor called with this name : "
		<< this->name
		<< std::endl;
	}

	Character::Character(const Character& copy)
	{
		*this = copy;
		std::cout
		<< "Character copy constructor called with this name : "
		<< this->name
		<< std::endl;
	}

	
// Operator overloads
	Character& Character::operator = (const Character& copy)
	{
		this->name = copy.name;
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i])
				delete inventory[i];
			if (copy.inventory[i] == nullptr)
				this->inventory[i] = nullptr;
			else
				this->inventory[i] = copy.inventory[i]->clone();
		}
		std::cout
		<< "Character operator = called"
		<< std::endl;
		return *this;
	}

// Destructors
	Character::~Character()
	{
		for (int i = 0; i < 4; i++)
			if (this->inventory[i])
				delete this->inventory[i];
		std::cout
		<< "Character destructor called for : "
		<< this->name
		<< std::endl;
	}

	
// Member functions
	void Character::equip(AMateria* m)
	{
		for (int i = 0; i < 4; i++)
		{
			if (!this->inventory[i])
			{
				this->inventory[i] = m;
				std::cout
				<< "Character "
				<< this->name
				<< " equiped "
				<< m->getType()
				<< std::endl;
				return ;
			}
		}
		std::cout
		<< "Character "
		<< this->name
		<< " can't equip "
		<< m->getType()
		<< " because he is already full stuff"
		<< std::endl;
	}

	void Character::unequip(int idx)
	{
		if (idx < 0 || idx >= 4)
		{
			std::cout
			<< "Character "
			<< this->name
			<< " can't unequip because index is wrong"
			<< std::endl;
			return ;
		}
		if (this->inventory[idx])
		{
			this->inventory[idx] = nullptr;
			std::cout
			<< "Character "
			<< this->name
			<< " unequip for index "
			<< idx
			<< std::endl;
			return;
		}
		std::cout
		<< "Character "
		<< this->name
		<< " can't unequip because no Materia exist for index "
		<< idx
		<< std::endl;
	}

	void Character::use(int idx, ICharacter& target)
	{
		if (idx < 0 || idx >= 4)
		{
			std::cout
			<< "Character "
			<< this->name
			<< " can't use Materia because index is incorrect"
			<< std::endl;
			return ;
		}
		if (this->inventory[idx])
		{
			this->inventory[idx]->use(target);
			return ;
		}
		std::cout
		<< "Character "
		<< this->name
		<< " do not find Materia for index : "
		<< idx
		<< std::endl;
	}

	
// Getters
	std::string const& Character::getName() const
	{
		return this->name;
	}
