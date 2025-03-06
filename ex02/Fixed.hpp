/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 06:59:01 by arabefam          #+#    #+#             */
/*   Updated: 2025/03/06 09:59:18 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	public:
		Fixed( void );
		Fixed( Fixed const& src );
		Fixed( int const value );
		Fixed( float const value );
		Fixed&	operator=( Fixed const& rhs );
		~Fixed( void );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		bool	operator<( Fixed const& rhs );
		bool	operator>( Fixed const& rhs );
		bool	operator<=( Fixed const& rhs );
		bool	operator>=( Fixed const& rhs );
		bool	operator==( Fixed const& rhs );
		bool	operator!=( Fixed const& rhs );
		Fixed	operator+( Fixed const& rhs );
		Fixed	operator-( Fixed const& rhs );
		Fixed	operator*( Fixed const& rhs );
		Fixed	operator/( Fixed const& rhs );
		Fixed&	operator++( void );
		Fixed	operator++( int );
		Fixed&	operator--( void );
		Fixed	operator--( int );
		static Fixed&	min( Fixed& a, Fixed& b );
		static Fixed&	min( Fixed const& a, Fixed const& b );
		static Fixed&	max( Fixed& a, Fixed& b );
		static Fixed&	max( Fixed const& a, Fixed const& b );
	private:
		int					_fixed;
		static int const	_fractBits;
};

std::ostream&	operator<<( std::ostream& o, Fixed const& rhs);

#endif
