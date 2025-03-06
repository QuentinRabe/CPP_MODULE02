/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:06:50 by arabefam          #+#    #+#             */
/*   Updated: 2025/03/06 19:11:26 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point {
	public:
	Point( void );
	Point( float const a, float const b );
	Point( Point const& src );
	Point&	operator=( Point const& rhs );
	~Point( void );
	Fixed	getX( void ) const;
	Fixed	getY( void ) const;
	static Fixed	calculateArea( Point const a, Point const b, Point const c);
	private:
	Fixed const	x;
	Fixed const	y;
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);
#endif
