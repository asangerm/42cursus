/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:28:30 by asangerm          #+#    #+#             */
/*   Updated: 2024/10/15 20:38:23 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"
# include "Character.hpp"

class MateriaSource : virtual public IMateriaSource
{
	private:
		AMateria*	tab[4];

	public:
	// Constructors
		MateriaSource();
		MateriaSource(const MateriaSource& src);
	
	// Operator overloads
		MateriaSource& operator = (const MateriaSource& src);

	// Destructors
		~MateriaSource();
	
	// Member functions
		void learnMateria(AMateria* src) ;
		AMateria* createMateria(const std::string& type);

	// Getters
		
};


#endif