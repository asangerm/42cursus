/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:16:33 by asangerm          #+#    #+#             */
/*   Updated: 2024/10/15 20:37:37 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class AMateria;
class ICharacter;

class Character : virtual public ICharacter
{
	private:
		std::string	name;
		AMateria*	inventory[4];
	public:
	// Constructors
		Character();
		Character(const std::string& name);
		Character(const Character& copy);
	
	// Operator overloads
		Character& operator = (const Character& copy);
	// Destructors
		~Character();
	
	// Member functions
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
	
	// Getters
		std::string const & getName() const;
};


#endif