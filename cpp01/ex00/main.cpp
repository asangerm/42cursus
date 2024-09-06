/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 02:55:58 by asangerm          #+#    #+#             */
/*   Updated: 2024/09/06 03:28:46 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

int	main( void )
{
	Zombie*	zombie = newZombie( "Arthur" );
	zombie->announce();
	randomChump( "Tom" );
	delete zombie;
}
