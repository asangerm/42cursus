/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 00:12:49 by asangerm          #+#    #+#             */
/*   Updated: 2024/10/03 00:34:14 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : virtual public Animal
{
	private:

	public:
	// Constructors
		Cat();
		Cat(const Cat& copy);

	// Destructors
		~Cat();

	// Overload operators
		Cat&	operator = (const Cat& copy);
	
	// Member functions
		void	makeSound() const;
};

#endif