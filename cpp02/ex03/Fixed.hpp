/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:24:29 by asangerm          #+#    #+#             */
/*   Updated: 2024/09/24 01:04:29 by asangerm         ###   ########.fr       */
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
		Fixed operator ++ ();
		Fixed operator -- ();
		Fixed operator ++ (int);
		Fixed operator -- (int);
		bool operator > (Fixed)const;
		bool operator < (Fixed)const;
		bool operator >= (Fixed)const;
		bool operator <= (Fixed)const;
		bool operator == (Fixed)const;
		bool operator != (Fixed)const;
		float operator + (Fixed)const;
		float operator - (Fixed)const;
		float operator * (Fixed)const;
		float operator / (Fixed)const;

		// Destructors
		~Fixed();

		// Member functions
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat( void ) const;
		int					toInt( void ) const;
		static Fixed&		min(Fixed &n1, Fixed &n2);
		static const Fixed&	min(Fixed const &n1, Fixed const &n2);
		static Fixed&		max(Fixed &n1, Fixed &n2);
		static const Fixed&	max(Fixed const &n1, const Fixed &n2);
};

std::ostream&	operator << (std::ostream &file, Fixed const &fixed);

#endif