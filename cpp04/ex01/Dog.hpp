/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 00:01:07 by asangerm          #+#    #+#             */
/*   Updated: 2024/10/14 15:34:30 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : virtual public Animal
{
	private:
		Brain*	brain;
	public:
	// Constructors
		Dog();
		Dog(const Dog& copy);

	// Destructors
		~Dog();

	// Overload operators
		Dog&	operator = (const Dog& copy);
	
	// Member functions
		void	makeSound() const;
		Brain*	getBrain() const;
};

#endif