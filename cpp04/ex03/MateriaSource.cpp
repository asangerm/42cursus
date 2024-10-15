/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:56:46 by asangerm          #+#    #+#             */
/*   Updated: 2024/10/15 20:21:39 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Constructor
	MateriaSource::MateriaSource()
	{
		for (int i = 0; i < 4; i++)
			tab[i] = nullptr;
	}

	MateriaSource::MateriaSource(const MateriaSource& copy) : IMateriaSource()
	{
		*this = copy;
	}

// Operator overload
	MateriaSource &MateriaSource::operator = (const MateriaSource &copy)
	{
		for (int i = 0; i < 4; i++)
		{
			if (tab[i])
				delete tab[i];
			if (!copy.tab[i])
				tab[i] = nullptr;
			else
				tab[i] = copy.tab[i]->clone();
		}
		return (*this);
	}

// Destructors
	MateriaSource::~MateriaSource()
	{
		for (int i = 0; i < 4; i++)
		{
			if (tab[i])
				delete tab[i];
		}
	}

// Member functions
	void	MateriaSource::learnMateria(AMateria *materia)
	{
		for (int i = 0; i < 4; i++)
		{
			if (!tab[i])
			{
				tab[i] = materia;
				return ;
			}
		}
	}

	AMateria*	MateriaSource::createMateria(const std::string &type)
	{
		for (int i = 0; i < 4; i++)
		{
			if (tab[i]->getType() == type)
				return (tab[i]->clone());
		}
		return (nullptr);
	}