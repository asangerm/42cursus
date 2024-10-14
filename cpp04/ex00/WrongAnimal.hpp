/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 00:20:19 by asangerm          #+#    #+#             */
/*   Updated: 2024/10/14 00:21:24 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;
	public:
	// Constructors
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal& copy);

	// Destructors
		virtual ~WrongAnimal();

	// Overload operators
		WrongAnimal&	operator = (const WrongAnimal& copy);
	
	// Member functions
		virtual void	makeSound() const;
	
	// Getters
		std::string	getType() const;
};

#endif