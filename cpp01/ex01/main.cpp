/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 03:49:37 by asangerm          #+#    #+#             */
/*   Updated: 2024/09/06 04:06:17 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name );

int	main( void )
{
	int	N;

	N = 10;
	Zombie	*horde = zombieHorde(N, "Arthur");
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete [] horde;
}