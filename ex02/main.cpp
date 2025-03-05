/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 07:21:20 by arabefam          #+#    #+#             */
/*   Updated: 2025/03/05 20:55:22 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int	main( void ) {
	Fixed	a(42);
	Fixed	b;
	Fixed	c = a / b;

	std::cout << "Value of a " << a << std::endl;
	std::cout << "Value of b " << b << std::endl;
	std::cout << "Value of c " << c << std::endl;
	return 0;
}
