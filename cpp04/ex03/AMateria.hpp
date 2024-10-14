/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:47:36 by asangerm          #+#    #+#             */
/*   Updated: 2024/10/14 18:13:43 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string	type;
	public:
	// Constructors
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria& copy);
	
	// Destructors
		virtual ~AMateria();
	
	// Operator overloads
		AMateria& operator = (const AMateria& copy);

	// Member functions
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

	// Getters
		std::string const & getType() const; //Returns the materia type
};


#endif