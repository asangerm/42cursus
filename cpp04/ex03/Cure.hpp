/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:21:28 by asangerm          #+#    #+#             */
/*   Updated: 2024/10/14 18:21:50 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : virtual public AMateria
{
	private:

	public:
	// Constructors
		Cure();
		Cure(const Cure& copy);
	
	// Destructors
		~Cure();
	
	// Operator overloads
		Cure& operator=(const Cure& copy);

	// Member functions
		Cure* clone() const;
		void use(ICharacter &target);
};

#endif