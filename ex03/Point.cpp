/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:06:51 by arabefam          #+#    #+#             */
/*   Updated: 2025/03/06 21:01:19 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cmath>

//------------------------------------------------------------------------------
// Constructor & Destructor
//------------------------------------------------------------------------------
Point::Point( void ): x(Fixed(0)), y(Fixed(0)) {}

Point::Point( float const a, float const b ): x(Fixed(a)), y(Fixed(b)) {}

Point::Point( Point const& src ) {
	if (this != &src)
		*this = src;
}

Point::~Point( void ) {}

//------------------------------------------------------------------------------
// Operator overload
//------------------------------------------------------------------------------
Point&	Point::operator=( Point const& rhs ) {
	const_cast<Fixed&>(this->x) = rhs.x;
	const_cast<Fixed&>(this->y) = rhs.y;
	return (*this);
}

//------------------------------------------------------------------------------
// Operator overload
//------------------------------------------------------------------------------
Fixed	Point::getX( void ) const {
	return (this->x);
}

Fixed	Point::getY( void ) const {
	return (this->y);
}

//------------------------------------------------------------------------------
// BSP methods
//------------------------------------------------------------------------------
Fixed	Point::calculateArea( Point const a, Point const b, Point const c ) {
	float	area;
	Fixed	fixedArea;

	area = a.x.toFloat() * (b.y.toFloat() - c.y.toFloat());
	area += b.x.toFloat() * (c.y.toFloat() - a.y.toFloat());
	area += c.x.toFloat() * (a.y.toFloat() - b.y.toFloat());
	if (area < 0)
		area *= -1;
	fixedArea = Fixed(area / 2.0f);
	return (fixedArea);
}

//------------------------------------------------------------------------------
// End of file
//------------------------------------------------------------------------------
