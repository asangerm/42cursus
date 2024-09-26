/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:01:12 by asangerm          #+#    #+#             */
/*   Updated: 2024/09/26 18:13:50 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	a;
	ClapTrap	b("Arthur");
	ClapTrap	c(b);

	a.attack("someone");
	b.takeDamage(5);
	b.beRepaired(3);
	b.takeDamage(7);
	b.beRepaired(12);
	b.beRepaired(10);
	b.takeDamage(10);
	b.takeDamage(10);
	b.beRepaired(10);

	ScavTrap	d;
	ScavTrap	e("Arthur");
	ScavTrap	f(e);

	d.attack("someone");
	e.takeDamage(5);
	e.beRepaired(3);
	e.takeDamage(7);
	e.beRepaired(12);
	e.beRepaired(10);
	e.takeDamage(10);
	e.takeDamage(10);
	e.beRepaired(10);
	f.guardGate();
	return 0;
}