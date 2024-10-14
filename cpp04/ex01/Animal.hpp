/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 23:28:52 by asangerm          #+#    #+#             */
/*   Updated: 2024/10/03 00:37:41 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string	type;
	public:
	// Constructors
		Animal();
		Animal(std::string type);
		Animal(const Animal& copy);

	// Destructors
		virtual ~Animal();

	// Overload operators
		Animal&	operator = (const Animal& copy);
	
	// Member functions
		virtual void	makeSound() const;
	
	// Getters
		std::string	getType() const;
};

#endif