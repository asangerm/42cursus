/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:02:58 by asangerm          #+#    #+#             */
/*   Updated: 2024/10/02 21:12:41 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string name;
	public:
	// Constructors
		DiamondTrap();
		DiamondTrap(const DiamondTrap& copy);
		DiamondTrap(std::string name);

	// Destructors
		virtual ~DiamondTrap();

	// Operator overload
		DiamondTrap& operator = (const DiamondTrap& src);

	// Member functions
		void attack(const std::string &target);
		void whoAmI(void);
};

#endif