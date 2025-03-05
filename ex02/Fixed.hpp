/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 06:59:01 by arabefam          #+#    #+#             */
/*   Updated: 2025/03/05 20:39:35 by arabefam         ###   ########.fr       */
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
	private:
		int					_fixed;
		static int const	_fractBits;
};

std::ostream&	operator<<( std::ostream& o, Fixed const& rhs);

#endif
