/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:25:42 by asangerm          #+#    #+#             */
/*   Updated: 2024/10/15 20:39:13 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <iostream>
# include "AMateria.hpp"

class IMateriaSource
{
	public:
	// Destructors
		virtual ~IMateriaSource(){}
	
	// Member functions
		virtual void learnMateria(AMateria *src) = 0;
		virtual AMateria* createMateria(const std::string &type) = 0;

	// Getters
		
};


#endif