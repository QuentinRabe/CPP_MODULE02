/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 07:09:21 by arabefam          #+#    #+#             */
/*   Updated: 2025/03/06 10:00:15 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

int const	Fixed::_fractBits = 8;

//------------------------------------------------------------------------------
// Constructors & Destructors
//------------------------------------------------------------------------------
Fixed::Fixed( void ): _fixed(0) {
}

Fixed::Fixed( Fixed const& src ) {
	*this = src;
}

Fixed::Fixed( int const value ) {
	this->_fixed = value * (1 << _fractBits);
}

Fixed::Fixed( float const value ) {
	this->_fixed = roundf(value * (1 << _fractBits));
}

Fixed::~Fixed( void ) {
}

//------------------------------------------------------------------------------
// Getters & Setters
//------------------------------------------------------------------------------
int	Fixed::getRawBits( void ) const {
	return  (this->_fixed);
}

void	Fixed::setRawBits( int const raw ) {
	this->_fixed = raw;
}

//------------------------------------------------------------------------------
// Conversion methods
//------------------------------------------------------------------------------
float	Fixed::toFloat( void ) const {
	return ((float) this->_fixed / (float) (1 << _fractBits));
}

int	Fixed::toInt( void ) const {
	return (this->_fixed >> _fractBits);
}

//------------------------------------------------------------------------------
// Methods overload
//------------------------------------------------------------------------------
std::ostream&	operator<<( std::ostream& o, Fixed const& rhs) {
	o << rhs.toFloat();
	return (o);
}

Fixed& Fixed::operator=( Fixed const &rhs ) {
	if (this != &rhs)
		this->_fixed = rhs.getRawBits();
	return (*this);
}

bool	Fixed::operator<( Fixed const& rhs) {
	return (this->getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator>( Fixed const& rhs) {
	return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator<=( Fixed const& rhs) {
	return (this->getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator>=( Fixed const& rhs) {
	return (this->getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator==( Fixed const& rhs) {
	return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=( Fixed const& rhs) {
	return (this->getRawBits() != rhs.getRawBits());
}

Fixed	Fixed::operator+( Fixed const& rhs ) {
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-( Fixed const& rhs ) {
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*( Fixed const& rhs ) {
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/( Fixed const& rhs ) {
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed&	Fixed::operator++( void ) {
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator++( int ) {
	Fixed	current = *this;
	this->setRawBits(this->getRawBits() + 1);
	return (current);
}

Fixed&	Fixed::operator--( void ) {
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator--( int ) {
	Fixed	current = *this;
	this->setRawBits(this->getRawBits() - 1);
	return (current);
}

//------------------------------------------------------------------------------
// Min & Max static methods
//------------------------------------------------------------------------------
Fixed&	Fixed::min( Fixed& a, Fixed& b ) {
	return (a < b ? a : b);
}

Fixed&	Fixed::min( Fixed const& a, Fixed const& b ) {
	return (const_cast<Fixed&>(a) < const_cast<Fixed&>(b) ? const_cast<Fixed&>(a) : const_cast<Fixed&>(b));
}

Fixed&	Fixed::max( Fixed& a, Fixed& b ) {
	return (a > b ? a : b);
}

Fixed&	Fixed::max( Fixed const& a, Fixed const& b ) {
	return (const_cast<Fixed&>(a) > const_cast<Fixed&>(b) ? const_cast<Fixed&>(a) : const_cast<Fixed&>(b));
}
//------------------------------------------------------------------------------
// End of file
//------------------------------------------------------------------------------
