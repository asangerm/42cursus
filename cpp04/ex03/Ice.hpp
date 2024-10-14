/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:18:52 by asangerm          #+#    #+#             */
/*   Updated: 2024/10/14 18:21:01 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : virtual public AMateria
{
	private:

	public:
	// Constructors
		Ice();
		Ice(const Ice& copy);
	
	// Destructors
		~Ice();
	
	// Operator overloads
		Ice& operator=(const Ice& copy);

	// Member functions
		Ice* clone() const;
		void use(ICharacter &target);
};

#endif