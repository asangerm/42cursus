/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:24:29 by asangerm          #+#    #+#             */
/*   Updated: 2024/09/24 00:41:31 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					num;
		static int const	bits = 8;		
	public:
		// Constructors
		Fixed();
		Fixed(const Fixed&);
		Fixed(const int n);
		Fixed(const float f);

		// Operator overloads
		Fixed& operator = (const Fixed&);


		// Destructors
		~Fixed();

		// Member functions
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream&	operator << (std::ostream &file, Fixed const &fixed);

#endif