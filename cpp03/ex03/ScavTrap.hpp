/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:11:42 by asangerm          #+#    #+#             */
/*   Updated: 2024/10/02 21:11:16 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	private:
		bool	guard;
	public:
		// Constructors
		ScavTrap(void);
		ScavTrap(const ScavTrap& copy);
		ScavTrap(std::string name);

		// Operator orverloads
		ScavTrap& operator = (const ScavTrap& copy);

		// Destructors
		virtual	~ScavTrap(void);

		// Member functions
		void	attack(const std::string& target);
		void	guardGate(void);
};

#endif