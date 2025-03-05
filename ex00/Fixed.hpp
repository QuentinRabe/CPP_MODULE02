/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 06:59:01 by arabefam          #+#    #+#             */
/*   Updated: 2025/03/05 07:12:56 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_HPP
# define FIXED_HPP

class Fixed {
	public:
		Fixed( void );
		Fixed( Fixed const& src );
		Fixed&	operator=( Fixed const& rhs );
		~Fixed( void );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
	private:
		int					_fixed;
		static int const	_fractBits;
};

#endif
