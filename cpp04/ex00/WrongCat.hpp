/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 00:22:50 by asangerm          #+#    #+#             */
/*   Updated: 2024/10/14 00:23:47 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : virtual public WrongAnimal
{
	private:

	public:
	// Constructors
		WrongCat();
		WrongCat(const WrongCat& copy);

	// Destructors
		~WrongCat();

	// Overload operators
		WrongCat&	operator = (const WrongCat& copy);
	
	// Member functions
		
};

#endif