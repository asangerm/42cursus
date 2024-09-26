/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:01:12 by asangerm          #+#    #+#             */
/*   Updated: 2024/09/26 06:30:42 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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
	return 0;
}