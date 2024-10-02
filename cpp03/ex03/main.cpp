/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:01:12 by asangerm          #+#    #+#             */
/*   Updated: 2024/10/02 21:37:07 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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

	FragTrap	g;
	FragTrap	h("Arthur");
	FragTrap	i(h);

	g.attack("someone");
	h.takeDamage(5);
	h.beRepaired(3);
	h.takeDamage(7);
	h.beRepaired(12);
	h.beRepaired(10);
	h.takeDamage(10);
	h.takeDamage(10);
	h.beRepaired(10);
	i.highFiveGuys();

	DiamondTrap	j;
	DiamondTrap	k("Arthur");
	DiamondTrap	l(k);

	j.attack("someone");
	k.takeDamage(5);
	k.beRepaired(3);
	k.takeDamage(7);
	k.beRepaired(12);
	k.beRepaired(10);
	k.takeDamage(10);
	k.takeDamage(10);
	k.beRepaired(10);
	l.whoAmI();
	return 0;
}