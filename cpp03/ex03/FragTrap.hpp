/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:35:06 by asangerm          #+#    #+#             */
/*   Updated: 2024/10/02 21:11:10 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	private:
		
	public:
		// Constructors
		FragTrap();
		FragTrap(const FragTrap& copy);
		FragTrap(std::string name);

		// Destructors
		virtual ~FragTrap();

		// Operator overloads
		FragTrap& operator = (const FragTrap& src);

		// Member functions
		void highFiveGuys(void);
};

#endif