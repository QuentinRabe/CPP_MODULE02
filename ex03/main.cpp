/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 07:21:20 by arabefam          #+#    #+#             */
/*   Updated: 2025/03/06 09:48:12by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int	main( void ) {
	Point	a(1, 2);
	Point	b(4, 5);
	Point	c(6, 1);
	Point	array[5] = {
		Point(7, 4),
		Point(3, 3),
		Point(5, 2),
		Point(4, 3),
		Point(5, 3),
	};

	for(int i = 0; i < 5; i++) {
		if (bsp(a, b, c, array[i]))
			std::cout << "P(" << array[i].getX() << "," << array[i].getY() << ") is in the triangle ABC" << std::endl;
		else
			std::cout << "P(" << array[i].getX() << "," << array[i].getY() << ") is not in the triangle ABC" << std::endl;
	}

	return 0;
}
