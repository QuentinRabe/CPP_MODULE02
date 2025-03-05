/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 07:09:21 by arabefam          #+#    #+#             */
/*   Updated: 2025/03/05 20:45:07 by arabefam         ###   ########.fr       */
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
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const& src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed( int const value ) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixed = value * (1 << _fractBits);
}

Fixed::Fixed( float const value ) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixed = std::roundf(value * (1 << _fractBits));
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
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
	std::cout << "Copy assignment operator called" << std::endl;
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

//------------------------------------------------------------------------------
// End of file
//------------------------------------------------------------------------------
