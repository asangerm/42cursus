/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:14:19 by asangerm          #+#    #+#             */
/*   Updated: 2024/09/06 17:50:31 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): name(name), weapon(weapon)
{
	
}

HumanA::~HumanA()
{

}

void	HumanA::attack(void)
{
	std::cout << this->name
	<< " attacks with their "
	<< this->weapon.getType()
	<< std::endl;
}
