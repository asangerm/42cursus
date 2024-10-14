/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:26:41 by asangerm          #+#    #+#             */
/*   Updated: 2024/10/14 14:41:49 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	private:
		std::string	ideas[100];
	public:
	// Constructors
		Brain();
		Brain(const Brain& copy);

	// Destructors
		~Brain();

	// Overload operators
		Brain&	operator = (const Brain& copy);
	
	// Member functions
	
	// Getters
		std::string	getIdea(int	index) const;
	
	// Setters
		void	setIdea(int index, std::string idea);
};


#endif