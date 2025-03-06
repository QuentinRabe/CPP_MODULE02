/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:08:30 by arabefam          #+#    #+#             */
/*   Updated: 2025/03/06 21:20:36 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

//------------------------------------------------------------------------------
// BSP methods
//------------------------------------------------------------------------------
static bool	hasAlignedPoints( Fixed& firstTriangle, Fixed& secondTriangle,Fixed& thirdTriangle,Fixed& fourthTriangle ) {
	return (firstTriangle == 0 || secondTriangle == 0 || thirdTriangle == 0 || fourthTriangle == 0);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point) {
	Fixed	mainTriangleArea(Point::calculateArea(a, b, c));
	Fixed	abpTriangleArea(Point::calculateArea(a, b, point));
	Fixed	acpTriangleArea(Point::calculateArea(a, c, point));
	Fixed	bcpTriangleArea(Point::calculateArea(b, c, point));
	Fixed	secondTriangleArea (abpTriangleArea + acpTriangleArea + bcpTriangleArea);

	if ((secondTriangleArea > mainTriangleArea) || hasAlignedPoints(mainTriangleArea, abpTriangleArea, acpTriangleArea, bcpTriangleArea))
		return (false);
	return (true);
}

//------------------------------------------------------------------------------
// End of file
//------------------------------------------------------------------------------
